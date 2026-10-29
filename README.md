# FreeBASIC-NG

FreeBASIC-NG is an independently maintained fork of
[FreeBASIC](https://github.com/freebasic/fbc): a free, open-source,
multi-platform BASIC compiler with MS-QuickBASIC-compatible syntax.  The
compiler executable remains `fbc` for source compatibility.

The project is based on the upstream 1.20.0 development line.  Its exact
upstream base and the fork's compatibility policy are documented in
[UPSTREAM_BASE.md](UPSTREAM_BASE.md).

## Project identity

| Surface | Name |
| --- | --- |
| Project | FreeBASIC-NG |
| Compiler executable | `fbc` |
| GitHub repository | `metaneutrons/freebasic-ng` |
| Debian and Homebrew package | `freebasic-ng` |
| AUR source and binary packages | `freebasic-ng`, `freebasic-ng-bin` |

Release tags use `v<version>` and release assets use the
`freebasic-ng-<version>-<platform>` prefix.

## Install

Use [freebasic.metaneutrons.cc](https://freebasic.metaneutrons.cc/) for the
operating-system and architecture picker, release downloads and package-manager
setup.  The Debian instructions include the required `deb.metaneutrons.cc`
repository configuration before installation; the site also links the
Homebrew tap and the AUR source and binary packages.  GitHub release archives
remain available from the
[release page](https://github.com/metaneutrons/freebasic-ng/releases).

Install or upgrade the compiler, runtime and graphics libraries as one package
or versioned archive.  Do not copy a new `fbc` over libraries from another
FreeBASIC-NG or upstream FreeBASIC version.

## Build

Requirements:

- CMake 3.20 or newer
- a C compiler (GCC or Clang; MinGW-w64 on Windows)
- Python 3 and CA certificates when CMake materializes a bootstrap seed
- ncurses on Linux and macOS

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/src/compiler/fbc --version
```

Builds use a target-specific, provenance-verified compiler seed by default.
This keeps source builds independent of an arbitrary `fbc` found on `PATH`.
The verified binary is cached below the build directory after its first use.
Developers who specifically want a local compiler may opt in with
`-DFB_USE_SYSTEM_FBC=ON`. See [the bootstrap chain](docs/bootstrap.md)
for the pinned release provenance and offline reproduction procedure.

To stage an installation:

```bash
cmake --install build --prefix "$PWD/stage"
```

## Platform status

CI and stable releases cover Linux x86_64/aarch64, macOS x86_64/aarch64 and
Windows x86_64/aarch64 as Tier 1 native hosts.

Tier 1 archives contain the matching runtime and graphics-library variants.
On macOS, graphics programs use the native Cocoa/CoreGraphics backend and do
not require XQuartz.  Windowed, borderless, always-on-top and fullscreen modes
are supported; the documented limitations and manual qualification procedure
are in the [platform notes](docs/platform-support.md#macos-output-conventions).
The macOS archives and object files produced by their compiler target macOS
11.0 or newer.

AmigaOS/m68k and MorphOS/PowerPC have developer-preview target SDKs with
documented emulator runtime evidence.  They are not Tier 1 native host releases
or package-manager targets.  AROS qualification remains deferred to M6.

## Compatibility

FreeBASIC-NG aims for source compatibility with its upstream base. It does not
claim ABI compatibility with FreeBASIC distributions. Package managers must
treat it as an alternative compiler distribution, not as a drop-in provider for
an arbitrary `freebasic` dependency.

## Contributing and security

Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a pull request and
[SECURITY.md](SECURITY.md) for vulnerability reporting. The release and
repository roadmap is versioned in [docs/plans/m0.md](docs/plans/m0.md); the
current tidy-up decisions are in [docs/plans/m5.md](docs/plans/m5.md).

## License and attribution

FreeBASIC-NG preserves the original copyright notices and component licences.
The compiler is GPL-2.0-or-later; `libfb` and `libfbgfx` are
LGPL-2.1-or-later with the existing static-linking exception. See
[LICENSE.md](LICENSE.md) and the notices alongside the respective sources.
