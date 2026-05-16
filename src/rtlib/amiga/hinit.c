/* libfb init/end for AmigaOS - DOSBase opened by startup.s */
#include "../fb.h"

void fb_hInit(void) { }
void fb_hEnd(int errlevel) { (void)errlevel; }

#if defined(HOST_AMIGAOS)
#include <proto/intuition.h>
extern struct IntuitionBase *IntuitionBase;
#endif

FBCALL void fb_Beep(void) {
#if defined(HOST_AMIGAOS)
    extern struct Library *DOSBase;
    /* Try DisplayBeep, fall back to BEL character */
    if (IntuitionBase) {
        DisplayBeep(NULL);
    } else {
        long out;
        register struct Library *a6 __asm("a6") = (struct Library *)DOSBase;
        register long res __asm("d0");
        __asm volatile ("jsr -60(%%a6)" : "=r"(res) : "r"(a6) : "a0","a1","d1","memory");
        out = res;
        if (out) {
            register struct Library *a6w __asm("a6") = (struct Library *)DOSBase;
            register long d1 __asm("d1") = out;
            register const void *d2 __asm("d2") = "\a";
            register long d3 __asm("d3") = 1;
            __asm volatile ("jsr -48(%%a6)" : : "r"(a6w), "r"(d1), "r"(d2), "r"(d3) : "d0","a0","a1","memory");
        }
    }
#endif
}
