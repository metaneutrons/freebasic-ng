/* File operations for AmigaOS */
#include "../fb.h"
#include <string.h>

#if defined(HOST_AMIGAOS)
#include <proto/dos.h>
extern struct DosLibrary *DOSBase;
#endif

int fb_hFileFlushEx(FILE *f) {
    if (f) fflush(f);
    return 0;
}

int fb_hFileLock(FILE *f, fb_off_t ofs, fb_off_t len) {
    /* AmigaOS doesn't have POSIX file locking - no-op */
    (void)f; (void)ofs; (void)len;
    return 0;
}

int fb_hFileUnlock(FILE *f, fb_off_t ofs, fb_off_t len) {
    (void)f; (void)ofs; (void)len;
    return 0;
}

int fb_hFileSetEofEx(FILE *f) {
#if defined(HOST_AMIGAOS)
    BPTR fh = (BPTR)fileno(f);
    if (fh) SetFileSize(fh, 0, OFFSET_CURRENT);
#else
    ftruncate(fileno(f), ftell(f));
#endif
    return 0;
}

int fb_hFileResetEx(int streamno) {
    return 0;
}

int fb_FileCopy(const char *source, const char *dest) {
    FILE *in = fopen(source, "rb");
    if (!in) return -1;
    FILE *out = fopen(dest, "wb");
    if (!out) { fclose(in); return -1; }
    char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), in)) > 0)
        fwrite(buf, 1, n, out);
    fclose(out);
    fclose(in);
    return 0;
}
