#!/usr/bin/env bash
# Exercise the measured-archive formula generator before creating a release tag.
set -euo pipefail

version=$(sed -nE 's/^FBVERSION[[:space:]]*:=[[:space:]]*([0-9]+\.[0-9]+\.[0-9]+)$/\1/p' version.mk)
[[ "$version" =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]]

work=$(mktemp -d "${TMPDIR:-/tmp}/freebasic-ng-formula-style.XXXXXX")
created_tap=''
cleanup() {
  if [[ -n "$created_tap" ]]; then
    brew untap "$created_tap" >/dev/null 2>&1 || true
  fi
  rm -rf -- "$work"
}
trap cleanup EXIT
mkdir -p "$work/candidate" "$work/source"

for target in darwin-aarch64 darwin-x86_64; do
  root="freebasic-ng-${version}-${target}"
  mkdir -p "$work/source/$root/bin" \
    "$work/source/$root/include/freebasic" \
    "$work/source/$root/lib/freebasic/$target"
  : > "$work/source/$root/bin/fbc"
  : > "$work/source/$root/include/freebasic/fb.bi"
  : > "$work/source/$root/lib/freebasic/$target/libfb.a"
  tar -C "$work/source" -cJf "$work/candidate/$root.tar.xz" "$root"
done

formula="$work/Formula/freebasic-ng.rb"
bash scripts/release/generate-homebrew-formula.sh \
  --version "$version" \
  --base-url "https://github.com/metaneutrons/freebasic-ng/releases/download/v$version" \
  --candidate-dir "$work/candidate" \
  --output "$formula"
ruby -c "$formula"
brew style "$formula"

# A disposable tap lets brew audit apply the same strict formula checks as the
# release qualification job without publishing or installing the package.
tap='freebasic-ng/formula-style-qualification'
if brew tap | grep -Fxq "$tap"; then
  printf 'refusing to replace existing Homebrew tap %s\n' "$tap" >&2
  exit 1
fi
brew tap-new --no-git "$tap"
created_tap="$tap"
command cp -f "$formula" "$(brew --repository "$tap")/Formula/freebasic-ng.rb"
brew audit --strict "$tap/freebasic-ng"
