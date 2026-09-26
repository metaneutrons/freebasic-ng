"""Positive and counter-probes for public release-note composition."""

from pathlib import Path
import subprocess
import sys
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[2]
SCRIPT = ROOT / "scripts/release/compose-release-notes.py"
BEGIN = "<!-- freebasic-ng:public-release-notes:start -->"
END = "<!-- freebasic-ng:public-release-notes:end -->"
TEMPLATE = "\n---\n\nTemplate for the next cycle:"


class ComposeReleaseNotesTest(unittest.TestCase):
    def compose(self, body: str, source: str) -> tuple[subprocess.CompletedProcess[str], str | None]:
        with tempfile.TemporaryDirectory() as directory:
            work = Path(directory)
            (work / "body.md").write_text(body, encoding="utf-8")
            (work / "notes.md").write_text(source, encoding="utf-8")
            output = work / "result.md"
            result = subprocess.run(
                [sys.executable, str(SCRIPT), "--body", str(work / "body.md"),
                 "--notes", str(work / "notes.md"), "--output", str(output)],
                capture_output=True, text=True, check=False,
            )
            return result, output.read_text(encoding="utf-8") if output.exists() else None

    def test_appends_public_notes_without_template(self) -> None:
        source = f"# Release notes for the next version\n\nIntro.\n\n{BEGIN}\n\n## Graphics\n\nIncluded.\n\n{END}\n{TEMPLATE}\n```markdown\n_Do not publish._\n```\n"
        result, output = self.compose("## Changelog\n\n- Fixed.\n", source)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(output, "## Changelog\n\n- Fixed.\n\n---\n\n## Graphics\n\nIncluded.\n")
        self.assertNotIn("Do not publish", output)

    def test_existing_notes_are_not_duplicated(self) -> None:
        source = f"# Release notes for the next version\n\n{BEGIN}\n\n## Graphics\n\nIncluded.\n\n{END}\n{TEMPLATE}\n"
        body = "## Changelog\n\n## Graphics\n\nIncluded.\n"
        result, output = self.compose(body, source)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(output, body)

    def test_empty_template_keeps_changelog(self) -> None:
        source = f"# Release notes for the next version\n\n{BEGIN}\n\n_No notes for the next release yet._\n\n{END}\n{TEMPLATE}\n"
        result, output = self.compose("## Changelog\n", source)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(output, "## Changelog\n")

    def test_missing_end_marker_fails_without_output(self) -> None:
        source = f"# Release notes for the next version\n\n{BEGIN}\n\n## Graphics\n\nIncluded.\n{TEMPLATE}\n"
        result, output = self.compose("## Changelog\n", source)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("marker pair", result.stderr)
        self.assertIsNone(output)

    def test_partial_existing_notes_fail_without_output(self) -> None:
        source = f"# Release notes for the next version\n\n{BEGIN}\n\n## Graphics\n\nIncluded.\n\n## Cocoa\n\nReady.\n\n{END}\n{TEMPLATE}\n"
        result, output = self.compose("## Changelog\n\n## Graphics\n\nOld text.\n", source)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("already contains some", result.stderr)
        self.assertIsNone(output)

    def test_repository_notes_follow_the_contract(self) -> None:
        source = (ROOT / "docs/release-notes/next.md").read_text(encoding="utf-8")
        result, output = self.compose("## Changelog\n", source)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("## Graphics libraries", output)
        self.assertNotIn("Template for the next cycle", output)


if __name__ == "__main__":
    unittest.main()
