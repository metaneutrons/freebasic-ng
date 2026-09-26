#!/usr/bin/env python3
"""Run a clean-room compiler smoke test against a staged CMake installation."""

from __future__ import annotations

import argparse
import re
import subprocess
import tempfile
from pathlib import Path


def run(command: list[str], *, cwd: Path | None = None) -> str:
    result = subprocess.run(command, cwd=cwd, text=True,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    if result.returncode:
        rendered = " ".join(command)
        raise RuntimeError(
            f"command failed with exit status {result.returncode}: {rendered}\n"
            f"{result.stdout}"
        )
    return result.stdout


def verify_macos_deployment(path: Path) -> None:
    output = run(["xcrun", "vtool", "-show-build", str(path)])
    match = re.search(r"(?m)^\s*minos\s+(\d+)\.(\d+)(?:\.\d+)?\s*$", output)
    if match is None or (int(match.group(1)), int(match.group(2))) != (11, 0):
        raise RuntimeError(f"{path} must target macOS 11.0, got:\n{output}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--prefix", type=Path, required=True)
    parser.add_argument("--expected-host", required=True)
    parser.add_argument(
        "--require-gfxlib",
        action="store_true",
        help="require and link-test every graphics library variant supported by the host",
    )
    args = parser.parse_args()

    version_match = re.search(
        r"^FBVERSION\s*:=\s*(\d+\.\d+\.\d+)\s*$",
        (Path(__file__).resolve().parents[1] / "version.mk").read_text(encoding="utf-8"),
        re.MULTILINE,
    )
    if version_match is None:
        raise RuntimeError("version.mk has no semantic FBVERSION")
    expected_version = version_match.group(1)

    # The compiler is invoked again from an isolated temporary directory below.
    # Resolve the staged path before changing cwd, otherwise a relative --prefix
    # would point into that temporary directory.
    executable = (args.prefix / "bin" / "fbc").resolve()
    if not executable.exists():
        executable = executable.with_suffix(".exe")
    if not executable.is_file():
        raise FileNotFoundError(f"staged compiler not found below {args.prefix / 'bin'}")

    version = run([str(executable), "--version"])
    if f"Version {expected_version}" not in version:
        raise RuntimeError(
            f"expected compiler version {expected_version!r} in:\n{version}"
        )
    expected = f"built for {args.expected_host}"
    if expected not in version:
        raise RuntimeError(f"expected '{expected}' in compiler version output:\n{version}")

    libdir = args.prefix / "lib" / "freebasic" / args.expected_host
    expected_archives = {"libfb.a", "libfbmt.a", "fbrt0.o"}
    pic_supported = args.expected_host.startswith("linux-") and not args.expected_host.endswith("-x86")
    if pic_supported:
        expected_archives.update({"libfbpic.a", "libfbmtpic.a", "fbrt0pic.o"})
    if args.require_gfxlib:
        expected_archives.update({"libfbgfx.a", "libfbgfxmt.a"})
        if pic_supported:
            expected_archives.update({"libfbgfxpic.a", "libfbgfxmtpic.a"})
    missing_archives = sorted(
        archive for archive in expected_archives if not (libdir / archive).is_file()
    )
    if missing_archives:
        raise FileNotFoundError(
            f"staged libraries missing below {libdir}: {', '.join(missing_archives)}"
        )

    if args.expected_host.startswith("darwin-"):
        verify_macos_deployment(executable)
        verify_macos_deployment(libdir / "fbrt0.o")

    if args.require_gfxlib:
        platform_member = (
            "gfx_cocoa" if args.expected_host.startswith("darwin-")
            else "gfx_x11" if args.expected_host.startswith("linux-")
            else "gfx_win32"
        )
        gfx_archives = sorted(name for name in expected_archives if name.startswith("libfbgfx"))
        for name in gfx_archives:
            members = run(["ar", "t", str(libdir / name)]).splitlines()
            if len(members) < 10 or not any("gfx_screen." in member for member in members):
                raise RuntimeError(f"{name} has no complete graphics object inventory")
            if not any(platform_member in member for member in members):
                raise RuntimeError(f"{name} omits the {platform_member} platform driver")

    with tempfile.TemporaryDirectory(prefix="freebasic-ng-smoke-") as temporary:
        workdir = Path(temporary)
        source = workdir / "smoke.bas"
        output_base = workdir / "smoke"
        source.write_text(
            'Print "FreeBASIC-NG smoke: "; __FB_VERSION__\n', encoding="utf-8"
        )
        gfx_source = workdir / "gfx-smoke.bas"
        gfx_source.write_text(
            '#include once "fbgfx.bi"\n'
            'Dim screen_width As Integer, screen_height As Integer, screen_depth As Integer\n'
            'ScreenInfo screen_width, screen_height, screen_depth\n'
            'Print "FreeBASIC-NG smoke: "; __FB_VERSION__\n',
            encoding="utf-8",
        )
        run([str(executable), "-v", str(source), "-x", str(output_base)], cwd=workdir)
        output = output_base if output_base.exists() else output_base.with_suffix(".exe")
        if not output.is_file():
            raise FileNotFoundError(f"compiler did not produce {output_base} or {output_base}.exe")
        if args.expected_host.startswith("darwin-"):
            verify_macos_deployment(output)
        result = run([str(output)], cwd=workdir).strip()
        expected_output = f"FreeBASIC-NG smoke: {expected_version}"
        if result != expected_output:
            raise RuntimeError(f"unexpected smoke-program output: {result!r}")

        # Each command selects a distinct default library suffix.  The gfx
        # probe calls SCREENINFO to pull the archive, but never opens a window;
        # this keeps archive/link validation independent of the platform driver.
        variant_flags = [[], ["-mt"]]
        if pic_supported:
            variant_flags.extend([["-pic"], ["-mt", "-pic"]])
        if args.require_gfxlib:
            variant_flags.extend([flags + ["-fbgfx"] for flags in variant_flags])

        for index, flags in enumerate(variant_flags):
            variant_base = workdir / f"variant-{index}"
            variant_source = gfx_source if "-fbgfx" in flags else source
            command = [
                str(executable),
                *flags,
                str(variant_source),
                "-x",
                str(variant_base),
            ]
            # Frameworks are not static libraries. Inspect the compiler
            # driver's command for the Darwin gfx variant so accidentally
            # passing -lCocoa can never look like a valid link contract.
            if (
                args.expected_host.startswith("darwin-")
                and "-fbgfx" in flags
                and "-mt" not in flags
            ):
                command.insert(1, "-v")
                link_output = run(command, cwd=workdir)
                for framework in ("Cocoa", "CoreGraphics"):
                    expected_framework_arg = f"-framework {framework}"
                    if expected_framework_arg not in link_output:
                        raise RuntimeError(
                            f"Darwin gfx link omitted {expected_framework_arg}:\n"
                            f"{link_output}"
                        )
            else:
                run(command, cwd=workdir)
            variant_output = (
                variant_base
                if variant_base.exists()
                else variant_base.with_suffix(".exe")
            )
            if not variant_output.is_file():
                raise FileNotFoundError(
                    f"compiler did not produce {variant_base} or {variant_base}.exe"
                )
            result = run([str(variant_output)], cwd=workdir).strip()
            if result != expected_output:
                raise RuntimeError(
                    f"unexpected variant output for {' '.join(flags) or 'default'}: "
                    f"{result!r}"
                )

    print(f"verified staged compiler for {args.expected_host}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
