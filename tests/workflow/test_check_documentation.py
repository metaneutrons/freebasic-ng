from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path
from xml.etree.ElementTree import ParseError


SCRIPT = Path(__file__).parents[2] / "scripts" / "ci" / "check_documentation.py"
SPEC = importlib.util.spec_from_file_location("check_documentation", SCRIPT)
assert SPEC and SPEC.loader
MODULE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MODULE)


class CheckDocumentationTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name)
        self.assets = self.root / ".github" / "assets"
        self.assets.mkdir(parents=True)

    def tearDown(self) -> None:
        self.temporary.cleanup()

    def test_valid_local_image_and_svg_pass(self) -> None:
        (self.root / "README.md").write_text(
            '<img src=".github/assets/header.svg" alt="Header">', encoding="utf-8"
        )
        (self.assets / "header.svg").write_text(
            '<svg xmlns="http://www.w3.org/2000/svg"/>', encoding="utf-8"
        )
        self.assertEqual(MODULE.validate(self.root), (1, 1))

    def test_missing_local_image_fails(self) -> None:
        (self.root / "README.md").write_text(
            '<img src=".github/assets/missing.svg" alt="Missing">', encoding="utf-8"
        )
        with self.assertRaises(FileNotFoundError):
            MODULE.validate(self.root)

    def test_malformed_svg_fails(self) -> None:
        (self.root / "README.md").write_text("No image", encoding="utf-8")
        (self.assets / "broken.svg").write_text("<svg>", encoding="utf-8")
        with self.assertRaises(ParseError):
            MODULE.validate(self.root)


if __name__ == "__main__":
    unittest.main()
