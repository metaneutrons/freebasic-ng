#!/usr/bin/env python3
"""Prepare and run the private MorphOS QEMU release fixture."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import time
from typing import Any


ROOT = Path(__file__).resolve().parent
DEFAULT_MANIFEST = ROOT / "fixture-manifest.json"
GUEST_RUNNER = ROOT / "guest" / "run-fixture"
SHA256_RE = re.compile(r"[0-9a-f]{64}")


class HarnessError(RuntimeError):
    """A deterministic fixture contract failure."""


def load_manifest(path: Path) -> dict[str, Any]:
    try:
        manifest = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise HarnessError(f"cannot read fixture manifest {path}: {error}") from error
    if manifest.get("schema") != 1:
        raise HarnessError("fixture manifest schema must be 1")
    try:
        iso = manifest["morphos"]["iso"]
        boot = manifest["morphos"]["boot"]
        qemu = manifest["qemu"]
        markers = qemu["markers"]
        required = (
            iso["filename"], iso["url"], iso["size"], iso["md5"], iso["sha256"],
            boot["member"], boot["filename"], boot["size"], boot["sha256"],
            qemu["machine"], qemu["payload_volume"], markers["begin"],
            markers["pass"], markers["exit_prefix"],
        )
    except (KeyError, TypeError) as error:
        raise HarnessError(f"fixture manifest is incomplete: {error}") from error
    if any(value in (None, "") for value in required):
        raise HarnessError("fixture manifest contains an empty required value")
    for name, value in (("ISO SHA-256", iso["sha256"]), ("boot SHA-256", boot["sha256"])):
        if not isinstance(value, str) or not SHA256_RE.fullmatch(value):
            raise HarnessError(f"{name} is not a lowercase SHA-256 digest")
    if not isinstance(iso["md5"], str) or not re.fullmatch(r"[0-9a-f]{32}", iso["md5"]):
        raise HarnessError("ISO MD5 is not a lowercase MD5 digest")
    return manifest


def digest(path: Path, algorithm: str) -> str:
    result = hashlib.new(algorithm)
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            result.update(chunk)
    return result.hexdigest()


def verify_file(path: Path, spec: dict[str, Any], label: str) -> None:
    if not path.is_file() or path.is_symlink():
        raise HarnessError(f"{label} is not a regular file: {path}")
    expected_size = int(spec["size"])
    actual_size = path.stat().st_size
    if actual_size != expected_size:
        raise HarnessError(f"{label} size mismatch: expected {expected_size}, got {actual_size}")
    for algorithm in ("md5", "sha256"):
        expected = spec.get(algorithm)
        if expected is None:
            continue
        actual = digest(path, algorithm)
        if actual != expected:
            raise HarnessError(
                f"{label} {algorithm.upper()} mismatch: expected {expected}, got {actual}"
            )


def require_command(name: str) -> str:
    command = shutil.which(name)
    if command is None:
        raise HarnessError(f"required command is not installed: {name}")
    return command


def archive_member_count(listing: bytes, member: str) -> int:
    """Count an ASCII member without decoding unrelated archive filenames."""
    return listing.splitlines().count(member.encode("ascii"))


def download_iso(manifest: dict[str, Any], cache_dir: Path) -> Path:
    iso_spec = manifest["morphos"]["iso"]
    destination = cache_dir / iso_spec["filename"]
    cache_dir.mkdir(parents=True, exist_ok=True)
    if destination.exists():
        verify_file(destination, iso_spec, "MorphOS ISO")
        return destination

    partial = destination.with_name(destination.name + ".part")
    curl = require_command("curl")
    command = [
        curl,
        "--fail",
        "--location",
        "--continue-at",
        "-",
        "--retry",
        "3",
        "--retry-delay",
        "2",
        "--output",
        str(partial),
        iso_spec["url"],
    ]
    try:
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as error:
        raise HarnessError(f"MorphOS ISO download failed with exit code {error.returncode}") from error
    verify_file(partial, iso_spec, "downloaded MorphOS ISO")
    os.replace(partial, destination)
    return destination


def extract_boot(manifest: dict[str, Any], iso: Path, cache_dir: Path) -> Path:
    boot_spec = manifest["morphos"]["boot"]
    destination = cache_dir / boot_spec["filename"]
    if destination.exists():
        verify_file(destination, boot_spec, "MorphOS boot image")
        return destination

    bsdtar = require_command("bsdtar")
    try:
        listing = subprocess.run(
            [bsdtar, "-tf", str(iso)], check=True, capture_output=True
        ).stdout
    except subprocess.CalledProcessError as error:
        raise HarnessError("cannot list the MorphOS ISO") from error
    if archive_member_count(listing, boot_spec["member"]) != 1:
        raise HarnessError(
            f"MorphOS ISO must contain exactly one {boot_spec['member']}"
        )

    partial = destination.with_name(destination.name + ".part")
    with partial.open("wb") as output:
        try:
            subprocess.run(
                [bsdtar, "-xOf", str(iso), boot_spec["member"]],
                check=True,
                stdout=output,
            )
        except subprocess.CalledProcessError as error:
            raise HarnessError(f"cannot extract {member} from the MorphOS ISO") from error
    verify_file(partial, boot_spec, "extracted MorphOS boot image")
    os.replace(partial, destination)
    return destination


def prepare(manifest: dict[str, Any], cache_dir: Path) -> tuple[Path, Path]:
    iso = download_iso(manifest, cache_dir)
    boot = extract_boot(manifest, iso, cache_dir)
    return iso, boot


def verify_fixture_image(path: Path, expected_sha256: str) -> None:
    if not SHA256_RE.fullmatch(expected_sha256):
        raise HarnessError("fixture SHA-256 must be 64 lowercase hexadecimal characters")
    if not path.is_file() or path.is_symlink():
        raise HarnessError(f"MorphOS fixture is not a regular file: {path}")
    actual = digest(path, "sha256")
    if actual != expected_sha256:
        raise HarnessError(
            f"MorphOS fixture SHA-256 mismatch: expected {expected_sha256}, got {actual}"
        )


def verify_morphos_executable(path: Path) -> None:
    if not path.is_file() or path.is_symlink():
        raise HarnessError(f"MorphOS test executable is not a regular file: {path}")
    header = path.read_bytes()[:20]
    if len(header) < 20 or header[:4] != b"\x7fELF":
        raise HarnessError("MorphOS test executable is not ELF")
    if header[4] != 1 or header[5] != 2:
        raise HarnessError("MorphOS test executable must be 32-bit big-endian ELF")
    machine = int.from_bytes(header[18:20], "big")
    if machine != 20:
        raise HarnessError(f"MorphOS test executable must target PowerPC, got e_machine={machine}")


def create_iso(source_dir: Path, destination: Path, volume: str) -> None:
    xorriso = shutil.which("xorriso")
    if xorriso is not None:
        command = [
            xorriso, "-as", "mkisofs", "-quiet", "-V", volume,
            "-o", str(destination), str(source_dir),
        ]
    else:
        hdiutil = shutil.which("hdiutil")
        if hdiutil is None:
            raise HarnessError("creating the test ISO requires xorriso or hdiutil")
        command = [
            hdiutil, "makehybrid", "-quiet", "-iso", "-joliet",
            "-default-volume-name", volume, "-o", str(destination), str(source_dir),
        ]
    try:
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as error:
        raise HarnessError(f"test ISO creation failed with exit code {error.returncode}") from error


def parse_serial_log(text: str, markers: dict[str, str]) -> None:
    lines = [line.strip().replace("\x00", "") for line in text.replace("\r", "\n").splitlines()]
    begin = markers["begin"]
    passed = markers["pass"]
    exit_prefix = markers["exit_prefix"]
    for marker in (begin, passed):
        count = lines.count(marker)
        if count != 1:
            raise HarnessError(f"serial marker {marker!r} occurred {count} times, expected once")
    exits = [line for line in lines if line.startswith(exit_prefix)]
    if len(exits) != 1:
        raise HarnessError(f"serial exit marker occurred {len(exits)} times, expected once")
    match = re.fullmatch(re.escape(exit_prefix) + r"([0-9]+)", exits[0])
    if match is None:
        raise HarnessError(f"malformed serial exit marker: {exits[0]!r}")
    exit_code = int(match.group(1))
    if exit_code != 0:
        raise HarnessError(f"MorphOS fixture reported exit code {exit_code}")
    positions = [lines.index(begin), lines.index(passed), lines.index(exits[0])]
    if positions != sorted(positions) or len(set(positions)) != len(positions):
        raise HarnessError("serial markers are out of order")


def serial_has_exit(text: str, exit_prefix: str) -> bool:
    return any(line.strip().startswith(exit_prefix) for line in text.replace("\r", "\n").splitlines())


def build_qemu_command(
    qemu: str,
    machine: str,
    boot: Path,
    overlay: Path,
    payload_iso: Path,
    serial_log: Path,
) -> list[str]:
    return [
        qemu,
        "-machine", machine,
        "-rtc", "base=utc",
        "-device", "ati-vga,guest_hwcursor=true,romfile=",
        "-kernel", str(boot),
        "-display", "none",
        "-monitor", "none",
        "-serial", f"file:{serial_log}",
        "-net", "none",
        "-drive", f"file={overlay},format=qcow2,media=disk",
        "-drive", f"file={payload_iso},format=raw,media=cdrom,readonly=on",
        "-no-reboot",
    ]


def stop_process(process: subprocess.Popen[bytes]) -> None:
    if process.poll() is not None:
        return
    process.send_signal(signal.SIGTERM)
    try:
        process.wait(timeout=5)
    except subprocess.TimeoutExpired:
        process.kill()
        process.wait(timeout=5)


def run_fixture(args: argparse.Namespace, manifest: dict[str, Any], boot: Path) -> Path:
    fixture = Path(args.fixture_image).expanduser().resolve()
    executable = Path(args.executable).expanduser().resolve()
    verify_fixture_image(fixture, args.fixture_sha256)
    verify_morphos_executable(executable)

    qemu = require_command("qemu-system-ppc")
    qemu_img = require_command("qemu-img")
    machine = manifest["qemu"]["machine"]
    machine_list = subprocess.run(
        [qemu, "-machine", "help"], check=True, text=True, capture_output=True
    ).stdout
    if not any(line.split(maxsplit=1)[0] == machine for line in machine_list.splitlines() if line):
        raise HarnessError(f"QEMU does not provide required machine {machine}")

    work_root = Path(args.work_dir).expanduser().resolve()
    work_root.mkdir(parents=True, exist_ok=True)
    run_dir = Path(tempfile.mkdtemp(prefix="run-", dir=work_root))
    payload = run_dir / "payload"
    payload.mkdir()
    shutil.copyfile(executable, payload / "smoke")
    shutil.copyfile(GUEST_RUNNER, payload / "run-fixture")
    payload_iso = run_dir / "payload.iso"
    create_iso(payload, payload_iso, manifest["qemu"]["payload_volume"])

    overlay = run_dir / "overlay.qcow2"
    subprocess.run(
        [qemu_img, "create", "-f", "qcow2", "-F", "qcow2", "-b", str(fixture), str(overlay)],
        check=True,
    )
    serial_log = run_dir / "serial.log"
    qemu_log = run_dir / "qemu.log"
    command = build_qemu_command(qemu, machine, boot, overlay, payload_iso, serial_log)
    deadline = time.monotonic() + args.timeout
    with qemu_log.open("wb") as diagnostics:
        process = subprocess.Popen(command, stdout=diagnostics, stderr=subprocess.STDOUT)
        try:
            while True:
                text = serial_log.read_text(encoding="utf-8", errors="replace") if serial_log.exists() else ""
                if serial_has_exit(text, manifest["qemu"]["markers"]["exit_prefix"]):
                    parse_serial_log(text, manifest["qemu"]["markers"])
                    break
                if process.poll() is not None:
                    raise HarnessError(
                        f"QEMU exited with code {process.returncode} before the fixture result; see {qemu_log}"
                    )
                if time.monotonic() >= deadline:
                    raise HarnessError(f"MorphOS fixture timed out after {args.timeout} seconds")
                time.sleep(0.25)
        finally:
            stop_process(process)

    command_rm = (overlay, payload_iso)
    for generated in command_rm:
        generated.unlink(missing_ok=True)
    shutil.rmtree(payload)
    return serial_log


def parser() -> argparse.ArgumentParser:
    result = argparse.ArgumentParser(description=__doc__)
    result.add_argument("--manifest", type=Path, default=DEFAULT_MANIFEST)
    commands = result.add_subparsers(dest="command", required=True)

    prepare_parser = commands.add_parser("prepare", help="download and verify MorphOS boot inputs")
    prepare_parser.add_argument("--cache-dir", type=Path)

    run_parser = commands.add_parser("run", help="run one executable in the private MorphOS fixture")
    run_parser.add_argument("--cache-dir", type=Path)
    run_parser.add_argument(
        "--fixture-image", default=os.environ.get("MORPHOS_FIXTURE_IMAGE"), required=False
    )
    run_parser.add_argument(
        "--fixture-sha256", default=os.environ.get("MORPHOS_FIXTURE_SHA256"), required=False
    )
    run_parser.add_argument("--executable", required=True)
    run_parser.add_argument("--work-dir", default="build/morphos-qemu")
    run_parser.add_argument("--timeout", type=int, default=180)
    return result


def cache_dir_from(args: argparse.Namespace) -> Path:
    if args.cache_dir is not None:
        return args.cache_dir.expanduser().resolve()
    configured = os.environ.get("MORPHOS_CACHE_DIR")
    if configured:
        return Path(configured).expanduser().resolve()
    return Path.home() / ".cache" / "freebasic-ng" / "morphos"


def main() -> int:
    args = parser().parse_args()
    try:
        manifest = load_manifest(args.manifest)
        cache_dir = cache_dir_from(args)
        iso, boot = prepare(manifest, cache_dir)
        if args.command == "prepare":
            print(f"verified MorphOS ISO: {iso}")
            print(f"verified MorphOS boot image: {boot}")
            return 0
        if not args.fixture_image:
            raise HarnessError("set MORPHOS_FIXTURE_IMAGE or pass --fixture-image")
        if not args.fixture_sha256:
            raise HarnessError("set MORPHOS_FIXTURE_SHA256 or pass --fixture-sha256")
        if args.timeout <= 0:
            raise HarnessError("timeout must be positive")
        serial_log = run_fixture(args, manifest, boot)
        print(f"MorphOS QEMU fixture passed; serial log: {serial_log}")
        return 0
    except (HarnessError, OSError, subprocess.CalledProcessError) as error:
        print(f"MorphOS QEMU fixture error: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
