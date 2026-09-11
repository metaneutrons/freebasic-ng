#!/usr/bin/env python3
"""Run a clean-room compiler smoke test against a staged CMake installation."""

from __future__ import annotations

import argparse
import subprocess
import tempfile
from pathlib import Path


def run(command: list[str], *, cwd: Path | None = None) -> str:
    result = subprocess.run(command, cwd=cwd, check=True, text=True,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    return result.stdout


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--prefix", type=Path, required=True)
    parser.add_argument("--expected-host", required=True)
    args = parser.parse_args()

    executable = args.prefix / "bin" / "fbc"
    if not executable.exists():
        executable = executable.with_suffix(".exe")
    if not executable.is_file():
        raise FileNotFoundError(f"staged compiler not found below {args.prefix / 'bin'}")

    version = run([str(executable), "--version"])
    expected = f"built for {args.expected_host}"
    if expected not in version:
        raise RuntimeError(f"expected '{expected}' in compiler version output:\n{version}")

    with tempfile.TemporaryDirectory(prefix="freebasic-ng-smoke-") as temporary:
        workdir = Path(temporary)
        source = workdir / "smoke.bas"
        output_base = workdir / "smoke"
        source.write_text('Print "FreeBASIC-NG smoke"\n', encoding="utf-8")
        run([str(executable), str(source), "-x", str(output_base)], cwd=workdir)
        output = output_base if output_base.exists() else output_base.with_suffix(".exe")
        if not output.is_file():
            raise FileNotFoundError(f"compiler did not produce {output_base} or {output_base}.exe")
        result = run([str(output)], cwd=workdir).strip()
        if result != "FreeBASIC-NG smoke":
            raise RuntimeError(f"unexpected smoke-program output: {result!r}")

    print(f"verified staged compiler for {args.expected_host}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
