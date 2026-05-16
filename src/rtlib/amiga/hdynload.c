/* Dynamic library loading for AmigaOS via OpenLibrary/CloseLibrary */
#include "../fb.h"

#if defined(HOST_AMIGAOS)
#include <proto/exec.h>
extern struct ExecBase *SysBase;

void *fb_DylibLoad(const char *filename) {
    return (void *)OpenLibrary((CONST_STRPTR)filename, 0);
}

void *fb_DylibSymbol(void *lib, const char *symbol) {
    /* AmigaOS libraries don't have symbol lookup by name.
       Return NULL - users should use library offset calls instead. */
    (void)lib; (void)symbol;
    return NULL;
}

void *fb_DylibSymbolByOrd(void *lib, int ordinal) {
    /* Return the function at the given LVO offset */
    if (!lib || ordinal <= 0) return NULL;
    /* Library base - (ordinal * 6) gives the jump vector */
    return (void *)((char *)lib - (ordinal * 6));
}

void fb_DylibFree(void *lib) {
    if (lib) CloseLibrary((struct Library *)lib);
}

#else
/* AROS/MorphOS have dlopen */
#include <dlfcn.h>

void *fb_DylibLoad(const char *filename) { return dlopen(filename, RTLD_LAZY); }
void *fb_DylibSymbol(void *lib, const char *symbol) { return dlsym(lib, symbol); }
void *fb_DylibSymbolByOrd(void *lib, int ordinal) { (void)lib; (void)ordinal; return NULL; }
void fb_DylibFree(void *lib) { if (lib) dlclose(lib); }
#endif
