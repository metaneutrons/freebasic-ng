#!/usr/bin/env bash
# Package the FreeBASIC target SDK and qualify the archive with the cross-link smoke test.
set -euo pipefail
umask 022

project_dir="$(cd "$(dirname "$0")/../.." && pwd)"
archive="${1:?Usage: build-morphos-sdk.sh PATH.tar.xz}"
: "${FBC:?Set FBC to the absolute path of the matching host compiler}"
: "${MORPHOS_GCC_ROOT:?Set MORPHOS_GCC_ROOT to the pinned MorphOS cross-toolchain prefix}"
tar_cmd="${MORPHOS_TAR:-tar}"
sdk_name="$(basename "$archive" .tar.xz)"
source_date_epoch="$(git -C "$project_dir" show -s --format=%ct HEAD)"

work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
stage="$work/stage/$sdk_name"
unpacked="$work/unpacked/$sdk_name"
runtime=lib/freebasic/morphos-powerpc/libfb.a

cmake -S "$project_dir" -B "$work/build" -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE="$project_dir/cmake/toolchains/morphos-ppc.cmake" \
  -DMORPHOS_GCC_ROOT="$MORPHOS_GCC_ROOT" -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_LIBDIR=lib -DFB_BUILD_COMPILER=OFF -DFB_BUILD_GFXLIB=OFF \
  -DFB_DISABLE_X11=ON -DFB_DISABLE_GPM=ON -DFB_DISABLE_FFI=ON -DFB_DISABLE_OPENGL=ON
cmake --build "$work/build"
cmake --install "$work/build" --prefix "$stage"
install -m 0644 "$project_dir/docs/morphos-sdk.md" "$stage/README.md"
install -m 0644 "$project_dir/LICENSE.md" "$stage/LICENSE.md"
install -m 0644 "$project_dir/src/rtlib/license.txt" "$stage/runtime-license.txt"
install -m 0644 "$project_dir/doc/lgpl.txt" "$stage/lgpl.txt"
install -m 0644 "$project_dir/test/morphos/smoke.bas" "$stage/smoke.bas"
install -m 0644 "$project_dir/cmake/toolchains/morphos-ppc.lock.json" "$stage/toolchain-lock.json"

"$tar_cmd" --sort=name --mtime="@$source_date_epoch" --owner=0 --group=0 \
  --numeric-owner --format=gnu -cJf "$work/sdk.tar.xz" -C "$work/stage" "$sdk_name"

mkdir "$work/unpacked"
"$tar_cmd" -xJf "$work/sdk.tar.xz" -C "$work/unpacked"
test -s "$unpacked/$runtime"
test -s "$unpacked/include/freebasic/file.bi"
test ! -e "$unpacked/bin"

{
  printf '#include once "file.bi"\n'
  cat "$unpacked/smoke.bas"
} > "$work/smoke.bas"

FB_MORPHOS_RUNTIME="$unpacked/$runtime" \
FB_MORPHOS_INCLUDE="$unpacked/include/freebasic" \
FB_MORPHOS_BUILD_DIR="$work/linked" \
MORPHOS_CC="$MORPHOS_GCC_ROOT/bin/ppc-morphos-gcc" \
MORPHOS_OBJDUMP="$MORPHOS_GCC_ROOT/bin/ppc-morphos-objdump" \
MORPHOS_READELF="$MORPHOS_GCC_ROOT/bin/ppc-morphos-readelf" \
  "$project_dir/test/morphos/build_and_link.sh" "$work/smoke.bas"

mkdir -p "$(dirname "$archive")"
install -m 0644 "$work/sdk.tar.xz" "$archive"
