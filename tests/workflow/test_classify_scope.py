from __future__ import annotations

import importlib.util
import unittest
from pathlib import Path


SCRIPT = Path(__file__).parents[2] / "scripts" / "ci" / "classify_scope.py"
SPEC = importlib.util.spec_from_file_location("classify_scope", SCRIPT)
assert SPEC and SPEC.loader
MODULE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MODULE)


class ClassifyScopeTests(unittest.TestCase):
    def test_documentation_paths_skip_code_ci(self) -> None:
        paths = [
            "README.md",
            "docs/platform-support.md",
            "docs/images/diagram.png",
            ".github/assets/badges/release.svg",
            ".github/ISSUE_TEMPLATE/bug.yml",
        ]
        self.assertFalse(MODULE.requires_code_ci(paths))

    def test_code_and_policy_paths_require_code_ci(self) -> None:
        for path in (
            "src/compiler/fbc.bas",
            "package-lock.json",
            ".github/workflows/ci.yml",
            "notes.markdown",
        ):
            with self.subTest(path=path):
                self.assertTrue(MODULE.requires_code_ci([path]))

    def test_mixed_change_requires_code_ci(self) -> None:
        self.assertTrue(MODULE.requires_code_ci(["README.md", "CMakeLists.txt"]))


if __name__ == "__main__":
    unittest.main()
