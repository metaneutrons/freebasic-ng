#!/usr/bin/env python3
"""Compile and run the native Cocoa framebuffer/presentation smoke test."""

import argparse
import os
from pathlib import Path
import platform
import subprocess
import sys
import tempfile


ROOT = Path(__file__).resolve().parents[1]


def run(
    command: list[str], *, cwd: Path, env: dict[str, str] | None = None
) -> None:
    result = subprocess.run(
        command, cwd=cwd, env=env, capture_output=True, text=True, timeout=60
    )
    if result.returncode:
        if result.stdout:
            print(result.stdout, file=sys.stderr)
        if result.stderr:
            print(result.stderr, file=sys.stderr)
        raise SystemExit(f"Cocoa smoke failed ({result.returncode}): {command[0]}")
    if result.stdout:
        print(result.stdout, end="")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--prefix", type=Path, required=True)
    args = parser.parse_args()
    if platform.system() != "Darwin":
        parser.error("Cocoa smoke must run on macOS")

    prefix = args.prefix.resolve()
    fbc = prefix / "bin" / "fbc"
    if not fbc.is_file():
        parser.error(f"staged compiler not found: {fbc}")
    host = subprocess.check_output([str(fbc), "-print", "host"], text=True).strip()
    arch = {"darwin-aarch64": "arm64", "darwin-x86_64": "x86_64"}.get(host)
    if arch is None:
        parser.error(f"expected a Darwin compiler, got {host}")

    with tempfile.TemporaryDirectory(prefix="freebasic-ng-cocoa-") as temp:
        build = Path(temp)
        probe = build / "cocoa-baseline-probe.o"
        executable = build / "cocoa-baseline-smoke"
        run([
            "clang", "-arch", arch, "-fobjc-arc", "-c",
            str(ROOT / "tests/gfx/cocoa-baseline-probe.m"), "-o", str(probe),
        ], cwd=build)
        run([
            str(fbc), str(ROOT / "tests/gfx/cocoa-baseline-smoke.bas"),
            str(probe), "-x", str(executable),
        ], cwd=build)
        env = os.environ.copy()
        env.pop("DISPLAY", None)
        env["FBGFX"] = "Cocoa"
        run([str(executable)], cwd=build, env=env)


if __name__ == "__main__":
    main()
