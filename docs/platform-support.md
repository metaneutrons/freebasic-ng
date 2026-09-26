# Developer-preview platform contract

M1 releases native `fbc` host archives for the following Tier 1 platforms:

| Release ID | Native host | Minimal seed transport | CI runner |
| --- | --- | --- | --- |
| `linux-x86_64` | Linux x86_64 | attested Debian amd64 release asset | `ubuntu-24.04` |
| `linux-aarch64` | Linux ARM64 | attested Debian arm64 release asset | `ubuntu-24.04-arm` |
| `darwin-x86_64` | macOS Intel | attested macOS Intel host archive | `macos-15-intel` |
| `darwin-aarch64` | macOS Apple silicon | attested macOS Apple-silicon host archive | `macos-15` |
| `win64` | Windows x86_64 | attested Windows x64 host archive | `windows-2025` with MSYS2 `MINGW64` |
| `win32-aarch64` | Windows ARM64 | attested Windows ARM64 host archive | `windows-11-arm` with MSYS2 `CLANGARM64` |

Each host obtains exactly one compiler binary from the pinned,
[provenance-verified seed manifest](../bootstrap/seed-provenance.json). CMake
verifies both the release transport and extracted seed digests before using it
to regenerate the compiler from this checkout. The full procedure, including
offline cache reuse and seed rotation, is documented in
[the bootstrap chain](bootstrap.md). `FB_USE_SYSTEM_FBC=ON` remains the only
intentional opt-in to an arbitrary locally installed compiler.

Every Tier 1 CI job builds the complete CMake tree, installs it into an empty
prefix, confirms the host identity, compiles a small FreeBASIC program with the
installed compiler, and executes that program on the same host. This is the
assurance level for a Developer Preview host archive. The archive uses the
normal `bin`, `include/freebasic` and `lib/freebasic/<host>` layout and requires
the platform C toolchain at use time; it does not bundle a C toolchain.

## macOS output conventions

Native macOS graphics uses an AppKit window and a CoreGraphics framebuffer
presentation path. `SCREENRES` dimensions and mouse coordinates are logical
window points: the origin is the upper-left corner, and increasing Y moves
down. AppKit handles Retina backing pixels; FreeBASIC does not double its
framebuffer dimensions when `backingScaleFactor` is 2. In fullscreen mode the
logical framebuffer is scaled to the main display's point-sized frame. This is
borderless desktop fullscreen, not an exclusive display-mode switch or a
separate macOS Space. `GFX_NO_FRAME` creates a borderless key-capable window;
`GFX_ALWAYS_ON_TOP` uses the floating window level.

Keyboard `SC_*` values represent physical key positions; event `ascii` and
`INKEY$` use the layout-dependent text converted to FreeBASIC's CP437 code
page. Characters outside CP437 are not emitted as text. The backend does not
provide an IME composition interface. Mouse movement, button, wheel, focus
and close requests are posted to `ScreenEvent`. `ScreenEvent` also pumps the
AppKit queue on the main thread, so an event-only loop does not need drawing
calls to receive input. `GETMOUSE` reports logical coordinates and the current
button/wheel state. Positive `SETMOUSE` clipping, OpenGL and shaped windows
return an illegal-function-call error rather than claiming unsupported
behaviour worked.

AppKit creation, polling, presentation and teardown run on the process main
thread. A `-mt` worker can draw into the shared framebuffer, but its
`SCREENRES`/`SCREEN 0` mode change is rejected before the current screen is
destroyed. Worker requests to change title, window position or mouse cursor
are queued for the main thread; they become visible when its run loop is
pumped. A worker must not wait for a queued window change while holding up
the main thread. Graphics output drawn by a worker appears at the next
main-thread presentation/poll operation.

The hosted macOS smoke test injects synthetic AppKit input and verifies
window/event translation for both standard and `-mt` graphics builds. Manual
qualification still needs a real keyboard, mouse, Retina/non-Retina display,
and both macOS architectures to check focus transitions, IME limitations,
cursor behaviour and display scaling.

Mach-O differs from ELF in two ways that are visible in what `fbc` produces on
macOS, so they are part of the platform contract rather than a property of one
release.

`fbc -dylib` writes `lib<name>.dylib`, links it with `-dynamiclib` and records
an install name, the Mach-O counterpart of an ELF `SONAME`. `.so` is the
loadable-bundle extension on this platform and is not used for shared
libraries. `DyLibLoad("<name>")` resolves the `.dylib` name.

The `DATA` descriptor uses the natural field layout on Darwin, not the packed
one the other targets share, because `ld64` requires a pointer relocation to sit
at a pointer-aligned offset and rejects the packed form fatally on arm64. The
descriptor is part of the object-file interface between compiled code and the
runtime, so macOS object files carrying `DATA` statements are interchangeable
only between builds that agree on this layout.

## AmigaOS/m68k target-SDK preview

M3 is deliberately limited to classic AmigaOS/m68k. It is not a Tier 1 native
host. `-gen gcc -r` remains a syntax and generated-C check only; it does not
establish a target ABI, a linkable executable, or runtime behaviour.

| Target | Current evidence | Published support status |
| --- | --- | --- |
| AmigaOS 3 / m68k | The CMake runtime builds with `amiga-gcc`; a program generated by a freshly built `fbc` links against that runtime and prints its smoke marker under pinned Vamos with a 68020 CPU. Vamos remains output-only because the SDK's `libamiga` exit path yields its status 255 limitation. `test/amiga/run-fs-uae.sh` independently builds the same program, copies a user-supplied boot HDF, injects an early AmigaDOS test hook, and runs it under FS-UAE 3.2.35. The harness requires the smoke marker and a normal AmigaDOS `If Warn` result, and refuses success if the source HDF hash changes. | Developer-preview target SDK. M3 executable, runtime-marker and independent process-exit evidence are complete; this is still not a Tier 1 native host or a public-CI runtime test. |

The immutable compiler image, SDK root and emulator packages are recorded in
[`cmake/toolchains/amiga-m68k.lock.json`](../cmake/toolchains/amiga-m68k.lock.json).
CI validates that lock file before loading its values into the runtime-smoke
job, so the published pin and the executed inputs cannot silently diverge.
The independent FS-UAE harness is intentionally local: Kickstart ROMs and
bootable AmigaOS HDFs are lawful user-supplied inputs, never repository assets
or public-CI dependencies. Preserve `FS_UAE_WORK_DIR` when running it to retain
the copied HDF, FS-UAE log, test markers and detected emulator version as
evidence.

AROS remains deferred to the later
[M6 target-qualification epic](https://github.com/metaneutrons/freebasic-ng/issues/102).
MorphOS M6 has a pinned SDK, a CMake runtime archive and a FreeBASIC
link check in CI, recorded in
[`cmake/toolchains/morphos-ppc.lock.json`](../cmake/toolchains/morphos-ppc.lock.json).
That establishes neither execution nor process termination on MorphOS, so the
target remains unqualified and is not published as supported.
Package publication to APT, Homebrew and the AUR is M2 work.
