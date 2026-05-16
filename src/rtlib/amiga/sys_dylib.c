/* System: getcwd, shell, exec for AmigaOS */
#include "../fb.h"
#include <string.h>

#if defined(HOST_AMIGAOS)
#include <proto/dos.h>
extern struct DosLibrary *DOSBase;
#endif

char *fb_hGetCurrentDir(char *dst, ssize_t maxlen) {
    if (!dst || maxlen <= 0) return dst;
#if defined(HOST_AMIGAOS)
    if (!GetCurrentDirName(dst, maxlen))
        dst[0] = '\0';
#else
    if (!getcwd(dst, maxlen))
        dst[0] = '\0';
#endif
    return dst;
}

int fb_hShell(const char *program) {
#if defined(HOST_AMIGAOS)
    return SystemTags(program, TAG_DONE);
#else
    return system(program);
#endif
}

int fb_ExecEx(FBSTRING *program, FBSTRING *args, int wait_flag) {
    char cmd[512];
    if (!program || !program->data) return -1;
    strncpy(cmd, program->data, sizeof(cmd) - 1);
    if (args && args->data && args->len > 0) {
        strncat(cmd, " ", sizeof(cmd) - strlen(cmd) - 1);
        strncat(cmd, args->data, sizeof(cmd) - strlen(cmd) - 1);
    }
#if defined(HOST_AMIGAOS)
    return SystemTags(cmd, TAG_DONE);
#else
    return system(cmd);
#endif
}
