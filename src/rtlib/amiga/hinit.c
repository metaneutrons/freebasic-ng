/* libfb init/end for AmigaOS - DOSBase opened by startup.s */
#include "../fb.h"

void fb_hInit(void) { }
void fb_hEnd(int errlevel) { (void)errlevel; }

#if defined(HOST_AMIGAOS)
#include <proto/intuition.h>
extern struct IntuitionBase *IntuitionBase;
#endif

void fb_Beep(void) {
#if defined(HOST_AMIGAOS)
    /* DisplayBeep flashes the screen - standard Amiga beep */
    if (IntuitionBase) DisplayBeep(NULL);
#endif
}
