#!/usr/bin/env python3
"""Check the exact graphics/runtime inventory inside a Tier-1 release archive."""

from __future__ import annotations

import argparse
from pathlib import Path
import tarfile
import zipfile


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--archive", type=Path, required=True)
    parser.add_argument("--root", required=True)
    parser.add_argument("--expected-host", required=True)
    args = parser.parse_args()

    archive = args.archive
    if archive.suffix == ".zip":
        with zipfile.ZipFile(archive) as source:
            corrupt = source.testzip()
            if corrupt:
                raise RuntimeError(f"corrupt ZIP member: {corrupt}")
            names = [member.filename for member in source.infolist() if not member.is_dir()]
    elif archive.name.endswith(".tar.xz"):
        with tarfile.open(archive, "r:xz") as source:
            names = [member.name for member in source if member.isfile()]
    else:
        parser.error("expected a .tar.xz or .zip release archive")

    root = args.root.rstrip("/")
    if len(names) != len(set(names)):
        raise RuntimeError("archive has duplicate file names")
    if not names or any(not name.startswith(root + "/") for name in names):
        raise RuntimeError(f"archive contains a file outside {root}/")

    libdir = f"{root}/lib/freebasic/{args.expected_host}/"
    required = {f"{root}/bin/fbc", f"{libdir}libfb.a", f"{libdir}libfbmt.a",
                f"{libdir}libfbgfx.a", f"{libdir}libfbgfxmt.a",
                f"{libdir}fbrt0.o"}
    if args.expected_host.startswith("win"):
        required.remove(f"{root}/bin/fbc")
        required.add(f"{root}/bin/fbc.exe")
    if args.expected_host.startswith("linux-"):
        required.update({f"{libdir}libfbpic.a", f"{libdir}libfbmtpic.a",
                         f"{libdir}libfbgfxpic.a", f"{libdir}libfbgfxmtpic.a",
                         f"{libdir}fbrt0pic.o"})
    missing = sorted(required - set(names))
    if missing:
        raise RuntimeError("release archive is missing: " + ", ".join(missing))
    if not any(name.startswith(f"{root}/include/freebasic/") for name in names):
        raise RuntimeError("release archive has no FreeBASIC headers")

    print(f"verified {archive.name}: {len(required)} required binaries/libraries")


if __name__ == "__main__":
    main()
