# M1 and M2 release process

## Maintained distribution contract

FreeBASIC-NG publishes the six Tier 1 archives, signed source archive, native
Debian packages for `amd64` and `arm64`, a Homebrew formula, and the
`freebasic-ng` / `freebasic-ng-bin` AUR metadata. The central APT archive
ingests the attested Debian assets after GitHub Release promotion. RPM is not a
maintained distribution channel.

The historical local Debian and release assemblers were retired in M5. The
versioned GitHub Actions release workflow is the sole maintained release path;
its qualification and retention boundaries are recorded in
[the M5 plan](plans/m5.md).

The upstream release procedure, `todo.txt` and `changelog.txt` remain
available as historical records in [the history index](history/README.md).
They do not define this release process or the FreeBASIC-NG roadmap.

Release Please observes conventional commits on main, opens a version PR and,
when that PR is merged, creates a draft GitHub release and an immutable
v&lt;version&gt; tag. It authenticates through the existing
organisation-wide `metaneutrons-release-please` GitHub App; no personal token
is acceptable. Although that App has a shared parent key and broad
installation, this workflow requests and verifies an installation token scoped
to `metaneutrons/freebasic-ng` only.

The tag dispatches the release workflow. For each Tier 1 host it verifies the
pinned minimal compiler seed, regenerates the compiler from the current source
checkout, stages a normal installation and compiles and runs an independent
FreeBASIC program from that installation. It then repeats that smoke test
after extracting the archive. The seed chain and its rotation procedure are
documented in [bootstrap.md](bootstrap.md).

Graphics is part of the release gate, not an optional post-release package.
Every host build and the Debian/AUR source builds enable `FB_BUILD_GFXLIB`.
Before packaging, the workflow checks the staged `libfbgfx` archive variants,
their object inventories and the platform driver, then compiles and runs
non-GUI `-fbgfx` probes with standard/`-mt` and supported PIC combinations.
The same checks run on extracted archives and after archive replacement.
The archive itself is inspected for its exact runtime/graphics inventory.
Both macOS host lanes additionally open native Cocoa windows from the staged
compiler and extracted archive; a successful link alone is not window-runtime
evidence. Debian, Homebrew and both AUR packages also compile and run a
headless graphics-link probe after installation. A real keyboard, mouse and
display check remains a manual release-qualification step; a hosted runner
cannot establish user-interaction quality merely by linking a library.

The workflow publishes a GitHub prerelease only after all six archives are
present. Each archive has:

- an SPDX JSON SBOM;
- a Sigstore keyless signature bundle;
- a GitHub build-provenance attestation;
- a signed SHA256SUMS inventory covering the archives, SBOMs and bundles.

Every archive lane also downloads the matching archive from the preceding
stable release, installs it into a stable active prefix, replaces that prefix
with the candidate archive, proves files removed by the candidate did not
survive, and runs the candidate compiler from that prefix. The supported
archive update is therefore a full versioned-directory replacement; it is not
an in-place NSIS or shell-installer upgrade.

It downloads the assets from the draft release and verifies the checksum
inventory before the draft is made visible. M2 adds native Debian packages for
`amd64` and `arm64`, a signed source archive, and measured Homebrew plus AUR
source/binary metadata to that same candidate. Before visibility, clean
Bookworm, Homebrew on both macOS architectures, and Arch Linux x86_64/aarch64
qualification lanes install the generated packages and compile a program with
`fbc`. Qualification receives no channel credentials.

## Release notes the changelog cannot carry

The generated changelog records what changed. It does not record what a change
means for an installation that already exists: an interface that stops being
interchangeable, an output file that changes its name, a platform that becomes
buildable. [`release-notes/next.md`](release-notes/next.md) collects those
consequences as they arise. A change with such a consequence adds its note in
the same pull request that introduces it.

Before the draft release is made visible, the release workflow appends the
marked public sections to its existing Release Please body. A malformed marker
pair stops staging. After the stable release, reset the file to the template it
carries at its end in a follow-up change. The file is a working document
between releases, not a published one, so an empty public block is the normal
state right after a release.

Merging the Release Please version PR is the explicit stable-release decision.
For a stable `v<version>` tag, the workflow first proves every channel's
credentials and destination scope without writing, then publishes the verified
candidate, publishes Homebrew and AUR metadata, promotes the GitHub release,
and finally dispatches the APT archive. A deliberately planned prerelease tag
such as `v<version>-m2.1` performs the complete build and package qualification
but remains a GitHub prerelease and cannot write to package channels.

## Required GitHub configuration

Use the existing `metaneutrons-release-please` App (client ID
`Iv23liGQAEDw6hfrazTD`). Store that ID as the `release` environment variable
`RELEASE_PLEASE_CLIENT_ID` and its existing private key as the `release`
environment secret `RELEASE_PLEASE_APP_PRIVATE_KEY`. The workflow must retain
its explicit `owner: metaneutrons`, `repositories: freebasic-ng` token request
and reject any token inventory other than this repository.

The release workflow itself uses GitHub Actions OIDC for Cosign; it does not
need a stored signing key. The repository must permit Actions to create
attestations and to write releases.
