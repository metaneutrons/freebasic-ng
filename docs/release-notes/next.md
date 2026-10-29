# Release notes for the next version

Release Please generates the changelog from conventional commits. That record
is accurate but it does not say what a change means for someone who already has
the previous release installed. The release workflow copies the marked public
sections into the draft before it becomes visible. After a stable release,
reset this file to the template at the end.

<!-- freebasic-ng:public-release-notes:start -->

## Graphics libraries are included in the Tier 1 packages

The previous host archives and package builds omitted `libfbgfx`. This release
includes the standard and multithreaded graphics archives on all six Tier 1
hosts, plus PIC graphics archives on supported Linux hosts. The Debian,
Homebrew and AUR packages include the same graphics support. Linux packages
declare the X11 link dependencies needed for programs using `-fbgfx`; an
existing installation should be upgraded as a complete package or versioned
archive directory, not by copying only `fbc` over the old version.

## macOS: native Cocoa graphics

Graphics programs on macOS use a native Cocoa driver and no longer need
XQuartz. `fbc` links them against the Cocoa and CoreGraphics frameworks itself.
Windowed, borderless (`GFX_NO_FRAME`), always-on-top (`GFX_ALWAYS_ON_TOP`) and
fullscreen screens work, as do keyboard, mouse, wheel, focus and close events.
Fullscreen fills the main display without switching its display mode. On a
Retina display, screen sizes and mouse coordinates are logical points, so a
640x480 screen appears at the same size as on other displays.

OpenGL screens, shaped windows and mouse confinement through `SETMOUSE` are not
available. They fail with an illegal-function-call error instead of appearing to
succeed. Text input covers the characters of code page 437, and there is no
input-method (IME) composition. In `-mt` programs only the main thread may open,
change or close a graphics screen. An `.xpm` icon passed to `fbc` has no effect
with this driver. The details are in the
[platform notes](https://github.com/metaneutrons/freebasic-ng/blob/main/docs/platform-support.md#macos-output-conventions).

On Intel Macs the driver passes the automated build, link and window tests but
has not yet been checked by hand on physical hardware; that check is tracked in
[issue #182](https://github.com/metaneutrons/freebasic-ng/issues/182).

## macOS archives target macOS 11.0

The compiler, runtime startup object and native Cocoa graphics driver in the
macOS archives, as well as object files compiled by `fbc`, now declare
macOS 11.0 as their minimum deployment target.
Earlier builds could inherit the newer macOS version of the build runner, even
though `fbc` linked user programs for macOS 11.0. On macOS 11, the Cocoa driver
reports a 60 Hz fallback refresh rate because the display refresh-rate API it
uses on newer systems was introduced in macOS 12. This declares a build and API
compatibility target; the release is not being interactively tested on
macOS 11.

## macOS: `DATA` object files are not interchangeable across this release

`DATA` statements are compiled into a descriptor whose layout was packed on
every target. On Mach-O that puts the descriptor's pointer at offset 2, and
`ld64` refuses a pointer relocation at an unaligned offset, fatally on arm64.
Darwin therefore uses the natural layout now, on the compiler and the runtime
side alike, and the pointer sits at offset 8.

The layout on Linux and Windows is unchanged. On macOS the descriptor is part
of the object-file interface between compiled code and the runtime, so an
object file or static library that carries a `DATA` statement and was produced
by an earlier `fbc` cannot be linked against this runtime, and the reverse
holds as well. Recompile such objects; there is no mixed configuration that
works. Programs compiled entirely with this release are unaffected, as is every
program without a `DATA` statement.

## macOS: shared libraries are named `.dylib`

`fbc -dylib foo.bas` produced `libfoo.so` on macOS and now produces
`libfoo.dylib`. Mach-O reserves `.so` for loadable bundles, which are built and
loaded differently, and `fb_DylibLoad()` looks for the `.dylib` name first.
Build scripts, installation rules and packaging manifests that name the `.so`
file have to follow. Code that loads the library through `DyLibLoad("foo")`
needs no change.

The library is linked with `-dynamiclib` and carries an install name, the
Mach-O equivalent of an ELF `SONAME`. Earlier releases passed the GNU spellings
`-shared` and `-h<soname>`, which the macOS toolchain rejects, so `-dylib` did
not link at all there.

## `-e` compiles where the C toolchain is clang

The C backend emits the jump to an error handler as a computed goto. Clang
rejects one in a function that takes no label address, which every procedure
holding an error check was without `-ex`. Programs built with `-e` therefore
failed to compile wherever clang translates the generated C: on macOS, and on
the `win32-aarch64` host, whose CLANGARM64 toolchain ships clang under the `gcc`
name. `-e` was not buildable on that host before this release.

## `ON ERROR GOTO` handlers run in their own procedure

A handler installed with `ON ERROR GOTO` is often reached from an error raised
in another procedure, typically a module-level handler for an error inside a
`SUB` or `FUNCTION`. Earlier releases jumped to such a handler without leaving
the failing procedure. The handler then read its own variables through the
wrong stack frame and saw wrong values, and optimized builds could crash or
hang. The handler now runs in the procedure that installed it, and its
variables hold the values they had when the error occurred.

`RESUME` and `RESUME NEXT` continue in the procedure where the error occurred,
so they need a handler in that procedure, typically one installed with
`ON LOCAL ERROR GOTO`. From a handler in another procedure they end the program
with runtime error 5 (illegal resume), because the failing procedure has
already been left.

<!-- freebasic-ng:public-release-notes:end -->

---

Template for the next cycle:

```markdown
# Release notes for the next version

Release Please generates the changelog from conventional commits. That record
is accurate but it does not say what a change means for someone who already has
the previous release installed. The release workflow copies the marked public
sections into the draft before it becomes visible. After a stable release,
reset this file to the template at the end.

<!-- freebasic-ng:public-release-notes:start -->

_No notes for the next release yet._

<!-- freebasic-ng:public-release-notes:end -->
```
