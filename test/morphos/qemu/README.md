# MorphOS QEMU runtime fixture

This harness executes a cross-built MorphOS/PowerPC program in a private,
locally provisioned MorphOS 3.20 QEMU image. The repository contains the
runner and its input contract. It does not contain MorphOS system files,
registration data, an installed disk image or a modified boot image.

## Trust boundary

`fixture-manifest.json` pins the official MorphOS 3.20 ISO published at
`morphos-team.net` by its published MD5 value and by a repository-recorded
SHA-256 value. `harness.py prepare` reuses a valid cached ISO or downloads it
through HTTPS into a `.part` file, verifies both digests, and only then makes
it active. It extracts the unmodified Pegasos II `boot.img` and verifies that
separately.

The installed QCOW2 image remains private. Every run requires its SHA-256 on
the command line or through `MORPHOS_FIXTURE_SHA256`; a different image is
rejected. QEMU writes only to a temporary copy-on-write overlay.

The fixture deliberately has no network device. A tiny `-noixemul` runner uses
MorphOS `debug.lib` to place deterministic markers in QEMU's serial log and
launches the smoke executable with a 64 KiB stack. This avoids the
interrupt-driven `SER:` DOS handler, which stalls after its first byte under
the emulated Pegasos II UART in the existing MorphOS 3.19 qualification image.
Do not use a boot image that removes or changes MorphOS registration behaviour.

## Prepare the host inputs

The default cache is `~/.cache/freebasic-ng/morphos`. An existing shared cache
can be selected explicitly:

```sh
export MORPHOS_CACHE_DIR=/Volumes/Dev/MorphOS
python3 test/morphos/qemu/harness.py prepare
```

The command must report both the verified ISO and the extracted boot image.
Deleting a rejected `.part` file is an explicit operator decision; the harness
does not replace an unverified download silently.

## Provision the private base image

Install MorphOS 3.20 normally into a dedicated QCOW2 image. Never use the
daily-use image as a writable test disk. Copy
`guest/freebasic-ng-fixture-startup` to
`SYS:S/freebasic-ng-fixture-startup` inside MorphOS and add exactly this line
to `SYS:S/user-startup`:

```text
Execute SYS:S/freebasic-ng-fixture-startup
```

The hook does nothing unless a CD named `FBNGTEST:` contains `run-fixture`.
Shut MorphOS down cleanly, calculate the image's SHA-256, and make the image
read-only. The image and its hash are operator-controlled inputs and must not
be committed.

## Run a cross-built program

First build the program with the pinned MorphOS toolchain as described in the
parent directory. Then run it through the fixture:

```sh
export MORPHOS_CACHE_DIR=/Volumes/Dev/MorphOS
export MORPHOS_FIXTURE_IMAGE=/Volumes/Dev/MorphOS/freebasic-ng-fixture-3.20.qcow2
export MORPHOS_FIXTURE_SHA256='<sha256-of-that-exact-image>'
python3 test/morphos/qemu/harness.py run \
  --executable build/morphos-smoke/smoke \
  --work-dir build/morphos-qemu
```

The harness verifies a 32-bit big-endian PowerPC ELF input, creates the test
ISO and overlay, builds the fixture runner with `ppc-morphos-gcc` (or
`MORPHOS_CC`), starts QEMU without networking, and accepts only one ordered
marker sequence ending in `FBNG:EXIT=0`. Serial and QEMU logs remain below the
run directory. Generated payload and overlay files are removed after success.

## Contract tests

The portable tests exercise the valid path and isolated counter-probes for a
corrupt input, wrong ELF byte order, missing or duplicate markers and a
non-zero guest result:

```sh
python3 -m unittest discover -s test/morphos/qemu -p 'test_*.py'
```

These tests can run in public CI. The real MorphOS execution requires the
private image and belongs on an explicitly configured private runner or in a
documented local release qualification.

The first completed MorphOS 3.20 emulator run, its exact inputs and its
counter-probe are recorded in [QUALIFICATION.md](QUALIFICATION.md).
