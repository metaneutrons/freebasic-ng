#include "../fb.h"
#include <string.h>

#if defined(HOST_AMIGAOS)
#include <proto/dos.h>
extern struct DosLibrary *DOSBase;
#endif

char *fb_hGetExePath(char *dst, ssize_t maxlen) {
    if (maxlen <= 0) return dst;
#if defined(HOST_AMIGAOS)
    /* Use GetProgramDir() + NameFromLock() */
    BPTR lock = GetProgramDir();
    if (lock) {
        NameFromLock(lock, dst, maxlen);
    } else {
        strncpy(dst, "PROGDIR:", maxlen - 1);
        dst[maxlen - 1] = '\0';
    }
#else
    /* AROS/MorphOS have getcwd or similar */
    strncpy(dst, "PROGDIR:", maxlen - 1);
    dst[maxlen - 1] = '\0';
#endif
    return dst;
}
