#include "../fb.h"

#ifdef HOST_AMIGAOS
#include <proto/exec.h>
extern struct ExecBase *SysBase;
#endif

FBCALL size_t fb_GetMemAvail(int mode) {
#ifdef HOST_AMIGAOS
    /* mode: 0=any, 1=largest block, 2=total free */
    ULONG flags = MEMF_ANY;
    if (mode == 1) return (size_t)AvailMem(flags | MEMF_LARGEST);
    return (size_t)AvailMem(flags);
#else
    return 0;
#endif
}
