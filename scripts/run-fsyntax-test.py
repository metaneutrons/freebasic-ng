#!/usr/bin/env python3
"""Run test/cmake/fsyntax.sh against the compiler installed from this build."""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
from pathlib import Path


def locate(tool: Path) -> Path:
    """Accept a path or a bare name looked up on PATH.

    The Windows test registration passes plain names, because MSYS Python
    reads a C:/... argument as a relative POSIX path.
    """

    if tool.is_file():
        return tool.resolve()
    located = shutil.which(str(tool))
    if located is None:
        return tool
    return Path(located)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--cmake", type=Path, required=True)
    parser.add_argument("--build-dir", type=Path, required=True)
    parser.add_argument("--install-prefix", type=Path, required=True)
    parser.add_argument("--script", type=Path, required=True)
    parser.add_argument(
        "--fbc-flag",
        action="append",
        default=[],
        help="extra option passed to fbc; repeat for several options",
    )
    args = parser.parse_args()

    cmake = locate(args.cmake)
    build_dir = args.build_dir.resolve()
    install_prefix = args.install_prefix.resolve()
    script = args.script.resolve()
    fbc = install_prefix / "bin" / "fbc"

    if not cmake.is_file():
        parser.error(f"CMake executable does not exist: {cmake}")
    if not build_dir.is_dir():
        parser.error(f"CMake build directory does not exist: {build_dir}")
    if not script.is_file():
        parser.error(f"test script does not exist: {script}")
    sh = shutil.which("sh")
    if sh is None:
        parser.error("sh is required to run the -fsyntax checks")

    shutil.rmtree(install_prefix, ignore_errors=True)
    subprocess.run(
        [str(cmake), "--install", str(build_dir), "--prefix", str(install_prefix)],
        check=True,
    )
    if not fbc.is_file() and fbc.with_suffix(".exe").is_file():
        fbc = fbc.with_suffix(".exe")
    if not fbc.is_file():
        raise RuntimeError(f"installed compiler does not exist: {fbc}")

    # The script splits FBC at spaces, and sh reads C:\... as an escape.
    command = " ".join([fbc.as_posix(), *args.fbc_flag])
    subprocess.run(
        [sh, script.as_posix()],
        check=True,
        env={**os.environ, "FBC": command},
    )


if __name__ == "__main__":
    main()
