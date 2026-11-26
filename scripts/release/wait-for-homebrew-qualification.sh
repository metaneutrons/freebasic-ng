#!/usr/bin/env bash
set -euo pipefail

tap_repo="${1:?Expected the Homebrew tap repository}"
pull_request="${2:?Expected the Homebrew tap pull request}"
expected_head="${3:?Expected the formula commit}"
required_check="Formula qualification"

printf 'Waiting for %s on %s at %s\n' "$required_check" "$pull_request" "$expected_head"
while :; do
  snapshot=$(gh pr view "$pull_request" --repo "$tap_repo" --json headRefOid,state,statusCheckRollup)
  if ! jq -e --arg head "$expected_head" '.state == "OPEN" and .headRefOid == $head' <<< "$snapshot" >/dev/null; then
    echo '::error::The Homebrew formula pull request is no longer open at the expected commit.' >&2
    exit 1
  fi

  # The tap registers its aggregate check after the prerequisite jobs finish.
  # An empty result and a running aggregate both mean qualification is pending.
  conclusion=$(jq -r --arg name "$required_check" '
    [.statusCheckRollup[] | select(.name == $name)]
    | if length > 1 then error("Multiple Homebrew formula qualification checks")
      elif length == 0 or .[0].status != "COMPLETED" then "pending"
      else .[0].conclusion
      end
  ' <<< "$snapshot")

  case "$conclusion" in
    pending) sleep 20 ;;
    SUCCESS)
      printf '%s passed for %s\n' "$required_check" "$expected_head"
      exit 0
      ;;
    *)
      printf '::error::Homebrew formula qualification concluded with %s.\n' "$conclusion" >&2
      exit 1
      ;;
  esac
done
