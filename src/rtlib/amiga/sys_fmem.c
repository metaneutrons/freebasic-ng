#include "../fb.h"

#ifdef HOST_AMIGAOS
#include <proto/exec.h>
extern struct ExecBase *SysBase;
#endif

FBCALL size_t fb_GetMemAvail(int mode) {
#ifdef HOST_AMIGAOS
    return (size_t)AvailMem(0); /* MEMF_ANY */
#else
    return 0;
#endif
}
