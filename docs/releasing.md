# M1 release process

Release Please observes conventional commits on main, opens a version PR and,
when that PR is merged, creates a draft GitHub release and an immutable
freebasic-ng-v&lt;version&gt; tag. It authenticates as the dedicated
FreeBASIC-NG GitHub App; no personal token and no credential from another
repository is acceptable.

The tag dispatches the release workflow. For each Tier 1 host it builds from
the checked-in, provenance-verified bootstrap C sources, stages a normal
installation and compiles and runs an independent FreeBASIC program from the
staged installation. It then repeats that smoke test after extracting the
archive.

The workflow publishes a GitHub prerelease only after all six archives are
present. Each archive has:

- an SPDX JSON SBOM;
- a Sigstore keyless signature bundle;
- a GitHub build-provenance attestation;
- a signed SHA256SUMS inventory covering the archives, SBOMs and bundles.

It downloads the assets from the draft release and verifies the checksum
inventory before the draft is made visible. The M1 workflow deliberately has
no APT, Homebrew or AUR credentials or publication steps. Those distribution
channels are M2 work.

## Required GitHub configuration

Create a dedicated GitHub App installed only for
metaneutrons/freebasic-ng, with Contents: read and write and Pull requests:
read and write. Store its client ID as the release environment variable
RELEASE_PLEASE_CLIENT_ID and its generated private key as the release
environment secret RELEASE_PLEASE_APP_PRIVATE_KEY.

The release workflow itself uses GitHub Actions OIDC for Cosign; it does not
need a stored signing key. The repository must permit Actions to create
attestations and to write releases.
