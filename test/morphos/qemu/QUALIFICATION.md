# MorphOS 3.20 qualification record

FreeBASIC-NG's MorphOS/PowerPC runtime completed its first emulator
qualification on 29 October 2026. This record identifies the exact source,
toolchain, guest and results. It does not make the private MorphOS image
redistributable.

## Qualified inputs

- FreeBASIC-NG commit: `5d1585bf52c5886db52dab868677fbcbef53368d`
- FreeBASIC-NG compiler: 1.24.4, built for Darwin AArch64
- MorphOS cross-compiler: GCC 15.2.0 from `morphos-cross`
- QEMU: 11.1.3, `pegasos2` machine
- Host: macOS 26.5.1 on AArch64
- MorphOS ISO SHA-256: `3761e191124cfd204a490915f8d285d55969e95b66c5c3cd1cf854bc71dab911`
- MorphOS boot-image SHA-256: `7c38f0eb7587924fe997ecea0dad7f9af8d2202526b3cbd18516a03eb23736b1`
- Private, read-only MorphOS 3.20 fixture SHA-256: `86340f37987935ccceaefed5296d20a8cde27c65d7764b49aafb0e26fb4bb7ae`
- Generated smoke executable SHA-256: `eef236838878e0a6adc3e38ec080f5107b094c2dd8ff0e71bc7c420c23a5cdda`

The private fixture was provisioned from the existing test image and updated
from MorphOS 3.19 with the official 3.20 IWizard update path. IWizard reported
`MorphOS 3.20 successfully installed`. The repository startup hook remained in
the updated image. The final image was checked with `qemu-img check` and made
read-only before its digest was recorded.

## Build and positive run

The native compiler and MorphOS runtime were rebuilt from the qualified commit.
`test/morphos/build_and_link.sh` then generated C from
`test/morphos/smoke.bas`, linked it with the freshly built MorphOS runtime and
verified the resulting `elf32-morphos` executable. The runtime harness used the
hash-pinned base image only through a disposable QCOW2 overlay and disabled
guest networking.

The guest produced exactly one ordered success sequence:

```text
FBNG:BEGIN
FBNG:PROGRAM=PASS
FBNG:EXIT=0
```

## Counter-probe

An independently compiled MorphOS executable returning status 20 was run
through the same base image, boot image and harness. It produced no pass marker,
and the host rejected the run with:

```text
MorphOS fixture reported exit code 20
```

This distinguishes successful execution from merely booting MorphOS or seeing
the start marker. Public CI validates the portable harness contract, builds the
same MorphOS runtime and links the smoke executable. Running the proprietary
guest image remains a documented private-runner release qualification.
