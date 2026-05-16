/* Path conversion and console cleanup for AmigaOS */
#include "../fb.h"
#include <string.h>

/* AmigaOS path conversion:
 * AmigaOS uses Volume:path/file (colon after volume, slash as separator)
 * No conversion needed when running on AmigaOS - paths are native.
 * This function is called by the rtlib to normalize paths. */
char *fb_hConvertPath(const char *path) {
    /* On AmigaOS, paths are already in native format.
       Just return a copy. */
    if (!path) return NULL;
    size_t len = strlen(path);
    char *result = (char *)malloc(len + 1);
    if (result) memcpy(result, path, len + 1);
    return result;
}

void fb_hExitConsole(void) {
    /* Reset console to default state */
#if defined(HOST_AMIGAOS)
    extern struct Library *DOSBase;
    /* Reset ANSI attributes */
    long out;
    register struct Library *a6 __asm("a6") = DOSBase;
    register long res __asm("d0");
    __asm volatile ("jsr -60(%%a6)" : "=r"(res) : "r"(a6) : "a0","a1","d1","memory");
    out = res;
    if (out) {
        const char *reset = "\033[0m";
        register struct Library *a6w __asm("a6") = DOSBase;
        register long d1 __asm("d1") = out;
        register const void *d2 __asm("d2") = reset;
        register long d3 __asm("d3") = 4;
        __asm volatile ("jsr -48(%%a6)" : : "r"(a6w), "r"(d1), "r"(d2), "r"(d3) : "d0","a0","a1","memory");
    }
#endif
}
