# FreeBASIC-NG SDK for MorphOS PowerPC

This developer-preview SDK contains the FreeBASIC static runtime, BASIC
headers, a smoke program and the build's toolchain lock. Use the `fbc` from
a matching FreeBASIC-NG host release and install the `ppc-morphos-gcc`
cross-toolchain separately. The SDK targets the native libnix ABI. The
matching source archive is available alongside the SDK in
[GitHub Releases](https://github.com/metaneutrons/freebasic-ng/releases).

Extract the SDK and set `sdk` to its absolute path. With both compilers on
your PATH, build the included example from a temporary directory.

```sh
work=$(mktemp -d)
cp "$sdk/smoke.bas" "$work/"
cd "$work"
fbc -gen gcc -r -m smoke -target morphos -arch powerpc \
  -i "$sdk/include/freebasic" smoke.bas
ppc-morphos-gcc -noixemul -mcpu=powerpc smoke.c \
  "$sdk/lib/freebasic/morphos-powerpc/libfb.a" -lgcc -lc -lm -o smoke
```

Copy the resulting `smoke` executable to a MorphOS system to run it.
