/* Timer/Sleep/Date for AmigaOS */
#include "../fb.h"

#if defined(HOST_AMIGAOS)
#include <proto/dos.h>
extern struct DosLibrary *DOSBase;
#else
#include <sys/time.h>
#include <unistd.h>
#endif

double fb_Timer(void) {
#if defined(HOST_AMIGAOS)
    struct DateStamp ds;
    DateStamp(&ds);
    return (double)ds.ds_Days * 86400.0 + (double)ds.ds_Minute * 60.0 + (double)ds.ds_Tick / 50.0;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
#endif
}

void fb_Sleep(int msecs) {
#if defined(HOST_AMIGAOS)
    /* Delay() uses system tick rate: 50Hz (PAL) or 60Hz (NTSC).
       We assume 50Hz (20ms/tick). For NTSC the sleep will be ~17% shorter. */
    long ticks = msecs / 20;
    if (ticks < 1) ticks = 1;
    Delay(ticks);
#else
    usleep(msecs * 1000);
#endif
}

void fb_Delay(int msecs) { fb_Sleep(msecs); }

int fb_hSetDate(int year, int month, int day) {
    /* Setting system date requires supervisor privileges - not supported */
    return -1;
}

int fb_hSetTime(int hour, int minute, int second) {
    return -1;
}
