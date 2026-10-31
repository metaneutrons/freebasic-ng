#!/usr/bin/env python3
"""Validate local README images and repository-owned SVG assets."""

from __future__ import annotations

import argparse
import re
import xml.etree.ElementTree as ET
from pathlib import Path
from urllib.parse import urlparse


IMAGE_SOURCE = re.compile(r"<img\b[^>]*\bsrc=[\"']([^\"']+)[\"']", re.IGNORECASE)


def validate(root: Path) -> tuple[int, int]:
    root = root.resolve()
    readme = root / "README.md"
    text = readme.read_text(encoding="utf-8")

    local_images = 0
    for source in IMAGE_SOURCE.findall(text):
        parsed = urlparse(source)
        if parsed.scheme or source.startswith("//"):
            continue
        target = (root / parsed.path).resolve()
        if root not in target.parents:
            raise ValueError(f"README image escapes repository root: {source}")
        if not target.is_file():
            raise FileNotFoundError(f"README image does not exist: {source}")
        local_images += 1

    svg_files = sorted((root / ".github" / "assets").rglob("*.svg"))
    for svg_file in svg_files:
        ET.parse(svg_file)

    return local_images, len(svg_files)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path.cwd())
    args = parser.parse_args()
    local_images, svg_files = validate(args.root)
    print(f"validated {local_images} local README images and {svg_files} SVG assets")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
