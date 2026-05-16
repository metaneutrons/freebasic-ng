/* DIR$() implementation for AmigaOS via Examine/ExNext */
#include "../fb.h"
#include <string.h>

#if defined(HOST_AMIGAOS)
#include <proto/dos.h>
#include <dos/dosextens.h>
extern struct DosLibrary *DOSBase;

static BPTR dir_lock;
static struct FileInfoBlock *dir_fib;

static void dir_cleanup(void) {
    if (dir_lock) { UnLock(dir_lock); dir_lock = 0; }
    if (dir_fib) { FreeDosObject(DOS_FIB, dir_fib); dir_fib = NULL; }
}

FBSTRING *fb_Dir(FBSTRING *filespec, int attrib, int *out_attrib) {
    static char result[256];

    if (filespec && filespec->data && filespec->len > 0) {
        /* First call - start new search */
        if (dir_lock) { UnLock(dir_lock); dir_lock = 0; }
        if (!dir_fib) dir_fib = (struct FileInfoBlock *)AllocDosObject(DOS_FIB, NULL);
        if (!dir_fib) goto empty;

        dir_lock = Lock(filespec->data, SHARED_LOCK);
        if (!dir_lock) goto empty;

        if (!Examine(dir_lock, dir_fib)) {
            UnLock(dir_lock); dir_lock = 0;
            goto empty;
        }
        /* If it's a file (not dir), return its name */
        if (dir_fib->fib_DirEntryType < 0) {
            strncpy(result, dir_fib->fib_FileName, sizeof(result) - 1);
            UnLock(dir_lock); dir_lock = 0;
            goto done;
        }
        /* It's a directory - get first entry */
        if (!ExNext(dir_lock, dir_fib)) {
            UnLock(dir_lock); dir_lock = 0;
            goto empty;
        }
        strncpy(result, dir_fib->fib_FileName, sizeof(result) - 1);
    } else {
        /* Subsequent call - get next entry */
        if (!dir_lock || !dir_fib) goto empty;
        if (!ExNext(dir_lock, dir_fib)) {
            UnLock(dir_lock); dir_lock = 0;
            goto empty;
        }
        strncpy(result, dir_fib->fib_FileName, sizeof(result) - 1);
    }

done:
    result[255] = 0;
    if (out_attrib) *out_attrib = 0;
    return fb_StrAllocTempDescZEx(result, strlen(result));

empty:
    if (out_attrib) *out_attrib = 0;
    return fb_StrAllocTempDescZEx("", 0);
}

#else
/* AROS/MorphOS - use POSIX opendir/readdir */
#include <dirent.h>
static DIR *dir_handle;

FBSTRING *fb_Dir(FBSTRING *filespec, int attrib, int *out_attrib) {
    static char result[256];
    struct dirent *entry;

    if (filespec && filespec->data && filespec->len > 0) {
        if (dir_handle) { closedir(dir_handle); dir_handle = NULL; }
        dir_handle = opendir(filespec->data);
        if (!dir_handle) goto empty;
    }
    if (!dir_handle) goto empty;

    entry = readdir(dir_handle);
    if (!entry) { closedir(dir_handle); dir_handle = NULL; goto empty; }

    strncpy(result, entry->d_name, sizeof(result) - 1);
    result[255] = 0;
    if (out_attrib) *out_attrib = 0;
    return fb_StrAllocTempDescZEx(result, strlen(result));

empty:
    if (out_attrib) *out_attrib = 0;
    return fb_StrAllocTempDescZEx("", 0);
}
#endif
