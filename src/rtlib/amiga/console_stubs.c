/* AmigaOS console implementation via ANSI escape sequences + dos.library */
#include "../fb.h"
#include <string.h>

#if defined(HOST_AMIGAOS)
extern struct Library *DOSBase;

static long dos_Input(void) {
    register struct Library *a6 __asm("a6") = DOSBase;
    register long res __asm("d0");
    __asm volatile ("jsr -54(%%a6)" : "=r"(res) : "r"(a6) : "a0","a1","d1","memory");
    return res;
}

static long dos_Output(void) {
    register struct Library *a6 __asm("a6") = DOSBase;
    register long res __asm("d0");
    __asm volatile ("jsr -60(%%a6)" : "=r"(res) : "r"(a6) : "a0","a1","d1","memory");
    return res;
}

static long dos_Read(long fh, void *buf, long len) {
    register struct Library *a6 __asm("a6") = DOSBase;
    register long d1 __asm("d1") = fh;
    register void *d2 __asm("d2") = buf;
    register long d3 __asm("d3") = len;
    register long res __asm("d0");
    __asm volatile ("jsr -42(%%a6)" : "=r"(res) : "r"(a6), "r"(d1), "r"(d2), "r"(d3) : "a0","a1","memory");
    return res;
}

static void dos_Write(long fh, const void *buf, long len) {
    register struct Library *a6 __asm("a6") = DOSBase;
    register long d1 __asm("d1") = fh;
    register const void *d2 __asm("d2") = buf;
    register long d3 __asm("d3") = len;
    __asm volatile ("jsr -48(%%a6)" : : "r"(a6), "r"(d1), "r"(d2), "r"(d3) : "d0","a0","a1","memory");
}

static long dos_WaitForChar(long fh, long timeout) {
    register struct Library *a6 __asm("a6") = DOSBase;
    register long d1 __asm("d1") = fh;
    register long d2 __asm("d2") = timeout;
    register long res __asm("d0");
    __asm volatile ("jsr -204(%%a6)" : "=r"(res) : "r"(a6), "r"(d1), "r"(d2) : "a0","a1","memory");
    return res;
}

static void dos_Delay(long ticks) {
    register struct Library *a6 __asm("a6") = DOSBase;
    register long d1 __asm("d1") = ticks;
    __asm volatile ("jsr -198(%%a6)" : : "r"(a6), "r"(d1) : "d0","a0","a1","memory");
}

static void con_write(const char *s) {
    dos_Write(dos_Output(), s, strlen(s));
}

static void con_write_ansi(const char *seq) {
    con_write(seq);
}

/* Simple itoa for ANSI sequences */
static void int_to_str(int val, char *buf) {
    char tmp[8]; int i = 0;
    if (val <= 0) { buf[0] = '0'; buf[1] = 0; return; }
    while (val > 0) { tmp[i++] = '0' + (val % 10); val /= 10; }
    int j = 0; while (i > 0) buf[j++] = tmp[--i];
    buf[j] = 0;
}

#else
/* AROS/MorphOS - use stdio */
#include <stdio.h>
#include <unistd.h>
#define con_write(s) fputs(s, stdout)
#define dos_Input() 0
#define dos_Output() 0
#define dos_Read(fh, buf, len) read(STDIN_FILENO, buf, len)
#define dos_WaitForChar(fh, t) 1
#define dos_Delay(t) usleep((t) * 20000)
static void int_to_str(int val, char *buf) { sprintf(buf, "%d", val); }
#endif

/* --- Console state --- */
static int con_x = 1, con_y = 1;
static int con_fg = 7, con_bg = 0;
static int con_w = 80, con_h = 25;

/* --- Size --- */
FBCALL void fb_ConsoleGetSize(int *cols, int *rows) {
    if (cols) *cols = con_w;
    if (rows) *rows = con_h;
}

/* --- Position --- */
FBCALL void fb_ConsoleGetXY(int *col, int *row) {
    if (col) *col = con_x;
    if (row) *row = con_y;
}

int fb_ConsoleGetX(void) { return con_x; }
int fb_ConsoleGetY(void) { return con_y; }

int fb_ConsoleLocate(int row, int col, int cursor) {
    char buf[20] = "\033[";
    char num[8];
    if (row > 0) { int_to_str(row, num); strcat(buf, num); con_y = row; }
    strcat(buf, ";");
    if (col > 0) { int_to_str(col, num); strcat(buf, num); con_x = col; }
    strcat(buf, "H");
    con_write(buf);
    return 0;
}

/* --- Color (ANSI) --- */
unsigned int fb_ConsoleColor(unsigned int fc, unsigned int bc, int flags) {
    unsigned int old = con_fg | (con_bg << 4);
    /* Map FB colors (0-15) to ANSI (30-37 + bright) */
    static const int ansi_fg[] = {30,34,32,36,31,35,33,37,90,94,92,96,91,95,93,97};
    static const int ansi_bg[] = {40,44,42,46,41,45,43,47,100,104,102,106,101,105,103,107};
    if (fc <= 15) { con_fg = fc; char buf[12]; sprintf(buf, "\033[%dm", ansi_fg[fc]); con_write(buf); }
    if (bc <= 15) { con_bg = bc; char buf[12]; sprintf(buf, "\033[%dm", ansi_bg[bc]); con_write(buf); }
    return old;
}

unsigned int fb_ConsoleGetColorAtt(void) { return con_fg | (con_bg << 4); }

/* --- Clear --- */
void fb_ConsoleClear(int mode) {
    con_write("\033[2J\033[H");
    con_x = 1; con_y = 1;
}

/* --- Scroll --- */
void fb_ConsoleScroll(int nrows) {
    if (nrows > 0) { while (nrows--) con_write("\033[S"); }
    else { while (nrows++) con_write("\033[T"); }
}

/* --- Width --- */
int fb_ConsoleWidth(int cols, int rows) {
    if (cols > 0) con_w = cols;
    if (rows > 0) con_h = rows;
    return 0;
}

/* --- View --- */
FBCALL int fb_ConsoleView(int toprow, int botrow) { return 0; }
int fb_ConsoleViewEx(int toprow, int botrow, int set_cursor) { return 0; }
void fb_ConsoleGetView(int *toprow, int *botrow) { if (toprow) *toprow = 1; if (botrow) *botrow = con_h; }
int fb_ConsoleGetMaxRow(void) { return con_h; }
void fb_ConsoleViewUpdate(void) { }
int fb_ConsoleGetTopRow(void) { return 1; }
int fb_ConsoleGetBotRow(void) { return con_h; }
void fb_ConsoleSetTopBotRows(int top, int bot) { }

/* --- Keyboard Input --- */
int fb_ConsoleGetkey(void) {
    long in = dos_Input();
    if (!in) return 0;
    char c;
    long r = dos_Read(in, &c, 1);
    return (r == 1) ? (unsigned char)c : 0;
}

FBSTRING *fb_ConsoleInkey(void) {
    static FBSTRING result;
    static char keybuf[2];
    long in = dos_Input();
    if (!in || !dos_WaitForChar(in, 0)) {
        result.data = NULL; result.len = 0; result.size = 0;
        return &result;
    }
    char c;
    if (dos_Read(in, &c, 1) == 1) {
        keybuf[0] = c; keybuf[1] = 0;
        result.data = keybuf; result.len = 1; result.size = 0;
    } else {
        result.data = NULL; result.len = 0; result.size = 0;
    }
    return &result;
}

int fb_ConsoleKeyHit(void) {
    long in = dos_Input();
    return (in && dos_WaitForChar(in, 0)) ? FB_TRUE : FB_FALSE;
}

/* --- ReadStr (for INPUT/LINE INPUT from console) --- */
char *fb_ConsoleReadStr(char *buffer, ssize_t len) {
    if (!buffer || len <= 0) return buffer;
    long in = dos_Input();
    if (!in) { buffer[0] = '\0'; return buffer; }
    ssize_t i = 0;
    while (i < len - 1) {
        char c;
        long r = dos_Read(in, &c, 1);
        if (r <= 0 || c == '\n') break;
        if (c == '\r') continue;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return buffer;
}

/* --- Sleep --- */
void fb_ConsoleSleep(int msecs) {
    if (msecs < 0) {
        /* Sleep until keypress */
        long in = dos_Input();
        if (in) { char c; dos_Read(in, &c, 1); }
    } else if (msecs == 0) {
        /* Just yield */
        dos_Delay(1);
    } else {
        long ticks = msecs / 20;
        if (ticks < 1) ticks = 1;
        dos_Delay(ticks);
    }
}

/* --- Misc --- */
FBCALL unsigned int fb_ConsoleReadXY(int col, int row, int colorflag) { return 32; }
int fb_ConsoleIsRedirected(int is_input) {
#if defined(HOST_AMIGAOS)
    extern struct Library *DOSBase;
    long fh = is_input ? dos_Input() : dos_Output();
    if (!fh) return 1;
    /* dos.library IsInteractive() offset -216 */
    register struct Library *a6 __asm("a6") = DOSBase;
    register long d1 __asm("d1") = fh;
    register long res __asm("d0");
    __asm volatile ("jsr -216(%%a6)" : "=r"(res) : "r"(a6), "r"(d1) : "a0","a1","memory");
    return res ? 0 : 1; /* interactive = not redirected */
#else
    return 0;
#endif
}
int fb_ConsolePageCopy(int src, int dst) { return 0; }
int fb_ConsolePageSet(int active, int visible) { return 0; }
