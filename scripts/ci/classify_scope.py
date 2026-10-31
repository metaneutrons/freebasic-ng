#!/usr/bin/env python3
"""Classify a change set as documentation-only or code-affecting."""

from __future__ import annotations

import argparse
import sys
from collections.abc import Iterable


DOCUMENTATION_PREFIXES = (
    ".github/assets/",
    ".github/ISSUE_TEMPLATE/",
    "docs/",
)


def is_documentation_path(path: str) -> bool:
    return path.endswith(".md") or path.startswith(DOCUMENTATION_PREFIXES)


def requires_code_ci(paths: Iterable[str]) -> bool:
    return any(path and not is_documentation_path(path) for path in paths)


def base_for_event(event_name: str, pull_request_base: str, push_before: str) -> str | None:
    if event_name == "pull_request":
        candidate = pull_request_base
    elif event_name == "push":
        candidate = push_before
    else:
        return None
    if not candidate or set(candidate) == {"0"}:
        return None
    return candidate


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--null",
        action="store_true",
        help="read NUL-delimited paths from standard input",
    )
    parser.add_argument("--event-name")
    parser.add_argument("--pull-request-base", default="")
    parser.add_argument("--push-before", default="")
    args = parser.parse_args()

    if args.event_name:
        print(
            base_for_event(
                args.event_name, args.pull_request_base, args.push_before
            )
            or ""
        )
        return 0

    separator = "\0" if args.null else "\n"
    paths = sys.stdin.read().split(separator)
    print("true" if requires_code_ci(paths) else "false")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
