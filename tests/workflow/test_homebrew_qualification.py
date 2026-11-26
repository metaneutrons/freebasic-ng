import json
import os
from pathlib import Path
import subprocess
import tempfile
import unittest


SCRIPT = Path(__file__).resolve().parents[2] / "scripts/release/wait-for-homebrew-qualification.sh"
HEAD = "a" * 40

MOCK_GH = """#!/usr/bin/env python3
import json
from pathlib import Path
import sys

assert sys.argv[1:] == [
    "pr", "view", "112", "--repo", "owner/tap", "--json",
    "headRefOid,state,statusCheckRollup",
]
counter = Path("requests")
index = int(counter.read_text()) if counter.exists() else 0
counter.write_text(str(index + 1))
response = json.loads(Path("responses.json").read_text())[index]
if "error" in response:
    print(response["error"], file=sys.stderr)
    sys.exit(1)
print(json.dumps(response))
"""


def snapshot(*checks, head=HEAD):
    return {"headRefOid": head, "state": "OPEN", "statusCheckRollup": checks}


def qualification(status, conclusion=None):
    return {"name": "Formula qualification", "status": status, "conclusion": conclusion}


class HomebrewQualificationTests(unittest.TestCase):
    def run_wait(self, responses):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for name, script in {
                "gh": MOCK_GH,
                "sleep": "#!/usr/bin/env bash\n[[ $1 == 20 ]]\n",
            }.items():
                command = root / name
                command.write_text(script)
                command.chmod(0o755)
            (root / "responses.json").write_text(json.dumps(responses))
            result = subprocess.run(
                ["bash", str(SCRIPT), "owner/tap", "112", HEAD],
                cwd=root,
                env=os.environ | {"PATH": f"{root}{os.pathsep}{os.environ['PATH']}"},
                capture_output=True,
                text=True,
                timeout=10,
                check=False,
            )
            return result, int((root / "requests").read_text())

    def test_waits_past_the_old_cutoff_until_the_aggregate_passes(self):
        discovery = {"name": "Discover changed formulas", "status": "COMPLETED", "conclusion": "SUCCESS"}
        responses = [snapshot(), snapshot(discovery)]
        responses += [snapshot(qualification("IN_PROGRESS"))] * 19
        responses.append(snapshot(qualification("COMPLETED", "SUCCESS")))

        result, requests = self.run_wait(responses)

        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("Formula qualification passed", result.stdout)
        self.assertEqual(requests, len(responses))

    def test_rejects_unsuccessful_terminal_results(self):
        for conclusion in ("FAILURE", "CANCELLED", "SKIPPED", "TIMED_OUT"):
            with self.subTest(conclusion=conclusion):
                result, requests = self.run_wait([snapshot(qualification("COMPLETED", conclusion))])

                self.assertEqual(result.returncode, 1, result.stderr)
                self.assertIn(conclusion, result.stderr)
                self.assertEqual(requests, 1)

    def test_fails_on_api_error_instead_of_polling(self):
        result, requests = self.run_wait([{"error": "HTTP 403: rate limit exceeded"}])

        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("HTTP 403", result.stderr)
        self.assertEqual(requests, 1)

    def test_rejects_success_for_a_changed_pull_request_head(self):
        result, requests = self.run_wait([snapshot(qualification("COMPLETED", "SUCCESS"), head="b" * 40)])

        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("expected commit", result.stderr)
        self.assertEqual(requests, 1)
