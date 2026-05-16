/* Internationalization via locale.library */
#include "../fb.h"
#include <string.h>

#if defined(HOST_AMIGAOS)
#include <proto/exec.h>
#include <proto/locale.h>
extern struct ExecBase *SysBase;
static struct Library *LocaleBase;
static struct Locale *locale;

static void ensure_locale(void) {
    if (!LocaleBase) {
        LocaleBase = OpenLibrary("locale.library", 38);
        if (LocaleBase) locale = OpenLocale(NULL);
    }
}
#endif

int fb_DrvIntlGet(int item) {
#if defined(HOST_AMIGAOS)
    ensure_locale();
    if (!locale) return 0;
    switch (item) {
        case 0: return locale->loc_DecimalPoint ? locale->loc_DecimalPoint[0] : '.';
        case 1: return locale->loc_DateFormat ? '/' : '/';
        case 2: return locale->loc_TimeFormat ? ':' : ':';
    }
#endif
    return 0;
}

int fb_DrvIntlGetDateFormat(char *buf, size_t buflen) {
    strncpy(buf, "dd/mm/yyyy", buflen);
    return 0;
}

int fb_DrvIntlGetTimeFormat(char *buf, size_t buflen) {
    strncpy(buf, "hh:mm:ss", buflen);
    return 0;
}

int fb_DrvIntlGetMonthName(int month, int abbreviated, char *buf, size_t buflen) {
    static const char *months[] = {"","January","February","March","April","May","June",
        "July","August","September","October","November","December"};
    static const char *abbr[] = {"","Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"};
    if (month < 1 || month > 12) { buf[0] = 0; return -1; }
    strncpy(buf, abbreviated ? abbr[month] : months[month], buflen);
    return 0;
}

int fb_DrvIntlGetWeekdayName(int weekday, int abbreviated, char *buf, size_t buflen) {
    static const char *days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    static const char *abbr[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    if (weekday < 0 || weekday > 6) { buf[0] = 0; return -1; }
    strncpy(buf, abbreviated ? abbr[weekday] : days[weekday], buflen);
    return 0;
}
