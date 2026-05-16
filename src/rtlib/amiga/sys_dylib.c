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
    BPTR lock = CurrentDir(0);
    CurrentDir(lock);
    if (!lock || !NameFromLock(lock, dst, maxlen))
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
    if (!program || !program->data) return -1;
    size_t len = program->len + 1;
    if (args && args->data) len += args->len + 1;
    char *cmd = (char *)malloc(len + 1);
    if (!cmd) return -1;
    strcpy(cmd, program->data);
    if (args && args->data && args->len > 0) {
        strcat(cmd, " ");
        strcat(cmd, args->data);
    }
    int ret;
#if defined(HOST_AMIGAOS)
    ret = SystemTags(cmd, TAG_DONE);
#else
    ret = system(cmd);
#endif
    free(cmd);
    return ret;
}
