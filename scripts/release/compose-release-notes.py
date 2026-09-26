#!/usr/bin/env python3
"""Append the public notes for this version to a draft GitHub release body."""

from __future__ import annotations

import argparse
from pathlib import Path


BEGIN = "<!-- freebasic-ng:public-release-notes:start -->"
END = "<!-- freebasic-ng:public-release-notes:end -->"
TEMPLATE = "\n---\n\nTemplate for the next cycle:"
EMPTY = "_No notes for the next release yet._"


def extract_public_notes(source: str) -> str:
    active, separator, _ = source.partition(TEMPLATE)
    if not separator:
        raise ValueError("missing next-cycle template separator")
    if active.count(BEGIN) != 1 or active.count(END) != 1:
        raise ValueError("expected exactly one public release-notes marker pair")

    introduction, _, remainder = active.partition(BEGIN)
    notes, _, trailing = remainder.partition(END)
    if not introduction.startswith("# Release notes for the next version"):
        raise ValueError("unexpected release-notes introduction")
    if trailing.strip():
        raise ValueError("content follows the public release-notes block")

    notes = notes.strip()
    if notes == EMPTY:
        return ""
    if not notes.startswith("## "):
        raise ValueError("public release notes must start with a section heading")
    return notes


def compose_body(body: str, notes: str) -> str:
    body = body.rstrip()
    if not notes:
        return body + "\n" if body else ""
    if notes in body:
        return body + "\n"

    headings = (line for line in notes.splitlines() if line.startswith("## "))
    if any(heading in body for heading in headings):
        raise ValueError("draft body already contains some public release notes")
    return f"{body}\n\n---\n\n{notes}\n" if body else notes + "\n"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--body", type=Path, required=True)
    parser.add_argument("--notes", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    try:
        notes = extract_public_notes(args.notes.read_text(encoding="utf-8"))
        result = compose_body(args.body.read_text(encoding="utf-8"), notes)
    except ValueError as error:
        parser.error(str(error))
    args.output.write_text(result, encoding="utf-8")


if __name__ == "__main__":
    main()
