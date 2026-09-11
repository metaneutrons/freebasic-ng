typedef   signed char       int8;
typedef unsigned char      uint8;
typedef   signed short      int16;
typedef unsigned short     uint16;
typedef   signed int        int32;
typedef unsigned int       uint32;
typedef   signed long long  int64;
typedef unsigned long long uint64;
typedef struct { char *data; int64 len; int64 size; } FBSTRING;
typedef int8 boolean;
struct $13FBGNUARCHINFO {
	char* GNUID;
	int64 CPUTYPE;
};
#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]
__FB_STATIC_ASSERT( sizeof( struct $13FBGNUARCHINFO ) == 16 );
struct $7TLISTTB;
struct $7TLISTTB {
	struct $7TLISTTB* NEXT;
	void* NODETB;
	int64 NODES;
};
__FB_STATIC_ASSERT( sizeof( struct $7TLISTTB ) == 24 );
struct $9TLISTNODE;
struct $9TLISTNODE {
	struct $9TLISTNODE* PREV;
	struct $9TLISTNODE* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9TLISTNODE ) == 16 );
typedef int64 $10LIST_FLAGS;
struct $5TLIST {
	struct $7TLISTTB* TBHEAD;
	struct $7TLISTTB* TBTAIL;
	int64 NODES;
	int64 NODELEN;
	struct $9TLISTNODE* FHEAD;
	void* HEAD;
	void* TAIL;
	$10LIST_FLAGS FLAGS;
};
__FB_STATIC_ASSERT( sizeof( struct $5TLIST ) == 64 );
struct $8HASHITEM;
struct $8HASHITEM {
	char* NAME;
	void* DATA;
	struct $8HASHITEM* PREV;
	struct $8HASHITEM* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $8HASHITEM ) == 32 );
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
struct $10FBC_EXTOPT {
	FBSTRING GAS;
	FBSTRING LD;
	FBSTRING GCC;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBC_EXTOPT ) == 72 );
struct $9FBCIOFILE {
	FBSTRING SRCFILE;
	FBSTRING* OBJFILE;
	int64 IS_CUSTOM_OBJFILE;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBCIOFILE ) == 40 );
struct $8HASHLIST {
	struct $8HASHITEM* HEAD;
	struct $8HASHITEM* TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $8HASHLIST ) == 16 );
struct $5THASH {
	struct $8HASHLIST* LIST;
	int64 NODES;
	int64 DELSTR;
};
__FB_STATIC_ASSERT( sizeof( struct $5THASH ) == 24 );
struct $7TSTRSET {
	struct $5TLIST LIST;
	struct $5THASH HASH;
};
__FB_STATIC_ASSERT( sizeof( struct $7TSTRSET ) == 88 );
typedef int64 $7FB_LANG;
struct $10FBC_OBJINF {
	$7FB_LANG LANG;
	int64 MT;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBC_OBJINF ) == 16 );
struct $6FBCCTX {
	int64 OPTID;
	struct $9FBCIOFILE* LASTMODULE;
	FBSTRING OBJFILE;
	int64 BACKEND;
	int64 CPUTYPE;
	int64 CPUTYPE_IS_NATIVE;
	int64 ASMSYNTAX;
	int64 EMITASMONLY;
	int64 KEEPASM;
	int64 EMITFINALASMONLY;
	int64 KEEPFINALASM;
	int64 KEEPOBJ;
	int64 VERBOSE;
	int64 SHOWVERSION;
	int64 SHOWHELP;
	int64 PRINT;
	struct $5TLIST MODULES;
	struct $5TLIST RCS;
	struct $9FBCIOFILE XPM;
	struct $7TSTRSET TEMPS;
	struct $5TLIST OBJLIST;
	struct $5TLIST LIBFILES;
	struct $7TSTRSET LIBS;
	struct $7TSTRSET LIBPATHS;
	struct $7TSTRSET EXCLUDEDLIBS;
	struct $7TSTRSET FINALLIBS;
	struct $7TSTRSET FINALLIBPATHS;
	char OUTNAME[261];
	char MAINNAME[261];
	char ENTRY[129];
	int64 MAINSET;
	char MAPFILE[261];
	char SUBSYSTEM[129];
	struct $10FBC_EXTOPT EXTOPT;
	char TARGET[129];
	char TARGETPREFIX[129];
	char SYSROOT[261];
	char XBE_TITLE[129];
	int64 NODEFLIBS;
	int64 NOFBRT0;
	int64 STATICLINK;
	int64 STRIPSYMBOLS;
	char PREFIX[261];
	char BINPATH[261];
	char INCPATH[261];
	char LIBPATH[261];
	char BUILDPREFIX[261];
	struct $10FBC_OBJINF OBJINF;
};
__FB_STATIC_ASSERT( sizeof( struct $6FBCCTX ) == 4104 );
typedef int64 $11FBCTOOLFLAG;
struct $11FBCTOOLINFO {
	char NAME[16];
	char ENV_VARIABLE[16];
	$11FBCTOOLFLAG FLAGS;
	char PATH[261];
};
__FB_STATIC_ASSERT( sizeof( struct $11FBCTOOLINFO ) == 304 );
struct $16__FB_ARRAYDIMTB$ {
	int64 ELEMENTS;
	int64 LBOUND;
	int64 UBOUND;
};
__FB_STATIC_ASSERT( sizeof( struct $16__FB_ARRAYDIMTB$ ) == 24 );
struct $8FBARRAY1IcE {
	char* DATA;
	char* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1IcE ) == 72 );
typedef int64 $7FBCTOOL;
struct $11FBGNUOSINFO {
	char* GNUID;
	int64 OS;
};
__FB_STATIC_ASSERT( sizeof( struct $11FBGNUOSINFO ) == 16 );
struct $12FBOSARCHINFO {
	char* TARGETID;
	int64 OS;
	int64 CPUTYPE;
};
__FB_STATIC_ASSERT( sizeof( struct $12FBOSARCHINFO ) == 24 );
struct $7FBARRAYI8FBSTRINGE {
	FBSTRING* DATA;
	FBSTRING* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYI8FBSTRINGE ) == 240 );
struct $7FBARRAYIKvE {
	void* DATA;
	void* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYIKvE ) == 240 );
struct $7FBARRAYIvE {
	void* DATA;
	void* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYIvE ) == 240 );
struct $18FBC_CMDLINE_OPTION {
	boolean TAKES_ARGUMENT;
	boolean ALLOWED_IN_SOURCE;
	boolean PARSER_RESTART;
	int64 FBC_RESTART;
};
__FB_STATIC_ASSERT( sizeof( struct $18FBC_CMDLINE_OPTION ) == 16 );
void fb_ArrayStrErase( struct $7FBARRAYIvE* );
int64 fb_ArrayLBound( struct $7FBARRAYIKvE*, int64 );
int64 fb_ArrayUBound( struct $7FBARRAYIKvE*, int64 );
void* fb_ErrorThrowAt( int32, char*, void*, void* );
int32 fb_FileOpen( FBSTRING*, uint32, uint32, uint32, int32, int32 );
int32 fb_FileOpenPipe( FBSTRING*, uint32, uint32, uint32, int32, int32, char* );
int32 fb_FileClose( int32 );
int32 fb_FilePutLarge( int32, int64, void*, uint64 );
int32 fb_FileLineInput( int32, void*, int64, int32 );
int32 fb_FileInput( int32 );
int32 fb_InputString( void*, int64, int32 );
int32 rename( char*, char* );
int32 fb_FileFree( void );
int32 fb_FileEof( int32 );
int32 fb_FileKill( FBSTRING* );
void fb_PrintVoid( int32, int32 );
void fb_PrintString( int32, FBSTRING*, int32 );
FBSTRING* fb_StrInit( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
void fb_StrDelete( FBSTRING* );
FBSTRING* fb_StrConcat( FBSTRING*, void*, int64, void*, int64 );
FBSTRING* fb_StrConcatByref( void*, int64, void*, int64, int32 );
int32 fb_StrCompare( void*, int64, void*, int64 );
FBSTRING* fb_StrConcatAssign( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAllocTempResult( FBSTRING* );
FBSTRING* fb_StrAllocTempDescZ( char* );
FBSTRING* fb_StrAllocTempDescZEx( char*, int64 );
FBSTRING* fb_LongintToStr( int64 );
int64 fb_StrLen( void*, int64 );
int64 fb_StrInstr( int64, FBSTRING*, FBSTRING* );
FBSTRING* fb_TRIM( FBSTRING* );
int32 fb_VALINT( FBSTRING* );
FBSTRING* fb_LEFT( FBSTRING*, int64 );
FBSTRING* fb_RIGHT( FBSTRING*, int64 );
FBSTRING* fb_StrLcase2( FBSTRING*, int32 );
FBSTRING* fb_StrUcase2( FBSTRING*, int32 );
void fb_Init( int32, char**, int32 );
void fb_InitSignals( void );
void fb_End( int32 );
FBSTRING* fb_ExePath( void );
int32 fb_Shell( FBSTRING* );
int32 fb_Exec( FBSTRING*, FBSTRING* );
FBSTRING* fb_GetEnviron( FBSTRING* );
void LISTINIT( struct $5TLIST*, int64, int64, $10LIST_FLAGS );
void* LISTNEWNODE( struct $5TLIST* );
void* LISTGETHEAD( struct $5TLIST* );
void* LISTGETNEXT( void* );
void STRLISTAPPEND( struct $5TLIST*, FBSTRING* );
void STRLISTINIT( struct $5TLIST*, int64 );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
void STRSETADD( struct $7TSTRSET*, FBSTRING*, int64 );
void STRSETDEL( struct $7TSTRSET*, FBSTRING* );
void STRSETCOPY( struct $7TSTRSET*, struct $7TSTRSET* );
void STRSETINIT( struct $7TSTRSET*, int64 );
void ERRPREINIT( void );
int64 ERRGETCOUNT( void );
typedef int64 $12FB_ERRMSGOPT;
void ERRREPORTEX( int64, char*, int64, $12FB_ERRMSGOPT, char* );
void ERRREPORTWARN( int64, char*, $12FB_ERRMSGOPT, char* );
void ERRREPORTWARNEX( int64, char*, int64, $12FB_ERRMSGOPT, char* );
void FBINIT( int64, char*, int64 );
void FBEND( void );
void FBCOMPILE( char*, char*, FBSTRING*, int64 );
int64 FBSHOULDRESTART( void );
typedef int64 $16FB_RESTART_FLAGS;
void FBRESTARTBEGINREQUEST( $16FB_RESTART_FLAGS );
void FBRESTARTENDREQUEST( $16FB_RESTART_FLAGS );
int64 FBRESTARTGETCOUNT( void );
void FBGLOBALINIT( void );
void FBADDINCLUDEPATH( FBSTRING* );
void FBADDPREDEFINE( FBSTRING* );
void FBADDPREINCLUDE( FBSTRING* );
void FBSETOPTION( int64, int64 );
int64 FBGETOPTION( int64 );
void FBSETLIBS( struct $7TSTRSET*, struct $7TSTRSET* );
void FBGETLIBS( struct $7TSTRSET*, struct $7TSTRSET* );
FBSTRING* FBGETTARGETID( void );
FBSTRING* FBGETHOSTID( void );
int64 FBIDENTIFYOS( FBSTRING* );
int64 FBDEFAULTCPUTYPEFROMCPUFAMILYID( int64, FBSTRING* );
char* FBGETGCCARCH( void );
char* FBGETFBCARCH( void );
int64 FBGETBITS( void );
int64 FBGETHOSTBITS( void );
int64 FBGETCPUFAMILY( void );
int64 FBIDENTIFYFBCARCH( FBSTRING* );
int64 FBTARGETSUPPORTSELF( void );
int64 FBISCROSSCOMP( void );
typedef int64 $10FB_BACKEND;
FBSTRING* FBGETBACKENDNAME( $10FB_BACKEND );
$7FB_LANG FBGETLANGID( char* );
int64 HFILEEXISTS( char* );
FBSTRING* HSTRIPEXT( FBSTRING* );
FBSTRING* HSTRIPPATH( char* );
FBSTRING* HSTRIPFILENAME( char* );
FBSTRING* HGETFILEEXT( char* );
void HREPLACESLASH( char*, int64 );
FBSTRING* PATHSTRIPDIV( FBSTRING* );
FBSTRING* STRUNQUOTE( FBSTRING* );
FBSTRING* HREPLACE( char*, char*, char* );
void HSPLITSTR( FBSTRING*, FBSTRING*, struct $7FBARRAYI8FBSTRINGE* );
void OBJINFOREADOBJ( FBSTRING* );
void OBJINFOREADLIBFILE( FBSTRING* );
void OBJINFOREADLIB( FBSTRING*, struct $5TLIST* );
int64 OBJINFOREADNEXT( FBSTRING* );
char* OBJINFOGETFILENAME( void );
void OBJINFOREADEND( void );
int64 fb_FileLen( char* );
static void _ZN10FBC_EXTOPTC1Ev( struct $10FBC_EXTOPT* );
static void _ZN10FBC_EXTOPTaSERKS_( struct $10FBC_EXTOPT*, struct $10FBC_EXTOPT* );
static void _ZN10FBC_EXTOPTD1Ev( struct $10FBC_EXTOPT* );
static void _ZN9FBCIOFILEC1Ev( struct $9FBCIOFILE* );
static void _ZN9FBCIOFILEaSERKS_( struct $9FBCIOFILE*, struct $9FBCIOFILE* );
static void _ZN9FBCIOFILED1Ev( struct $9FBCIOFILE* );
static void _ZN6FBCCTXC1Ev( struct $6FBCCTX* );
static void _ZN6FBCCTXaSERKS_( struct $6FBCCTX*, struct $6FBCCTX* );
static void _ZN6FBCCTXD1Ev( struct $6FBCCTX* );
static void FBCFINDBIN( int64, FBSTRING* );
static void HPRINTVERSION( int64 );
static void FBCINIT( void );
static void HSETOUTNAME( void );
static void FBCEND( int64 );
static void FBCADDTEMP( FBSTRING* );
static void FBCREMOVETEMP( FBSTRING* );
static FBSTRING* FBCADDOBJ( FBSTRING* );
static FBSTRING* HGET1STOUTPUTLINEFROMCOMMAND( FBSTRING* );
static FBSTRING* FBCQUERYCC( FBSTRING* );
static FBSTRING* FBCBUILDPATHTOLIBFILE( char* );
static FBSTRING* FBCFINDSYSROOT( void );
static FBSTRING* FBCFINDLIBFILE( char* );
static void FBCADDDEFLIBPATH( FBSTRING* );
static void FBCADDLIBPATHFOR( char* );
static int64 FBCRUNBIN( char*, int64, FBSTRING* );
static int64 HPUTLDARGSINTOFILE( FBSTRING* );
static int64 CLEARDEFLIST( FBSTRING* );
static int64 HGENERATEEMPTYDEFFILE( FBSTRING* );
static int64 MAKEIMPLIB( FBSTRING*, FBSTRING* );
static FBSTRING* HFINDLIB( char* );
static int64 FBCLINKERISGOLD( void );
static int64 FBCISUSINGGOLDLINKER( void );
static int64 HLINKFILES( void );
static void HREADOBJINFO( void );
static void HCOLLECTOBJINFO( void );
static void HFATALINVALIDOPTION( FBSTRING*, int64 );
static void HCHECKWAITINGOBJFILE( void );
static void HSETIOFILE( struct $9FBCIOFILE*, FBSTRING*, int64 );
static void HADDBAS( FBSTRING* );
static void HPARSEGNUTRIPLET( FBSTRING*, int64, int64*, int64* );
static void HPARSETARGETARG( FBSTRING*, int64*, int64*, int64* );
static void HANDLEOPT( int64, FBSTRING*, int64 );
static int64 PARSEOPTION( char* );
static void PARSEARGSFROMFILE( FBSTRING*, int64 );
static void HANDLEARG( FBSTRING*, int64, int64 );
void FBCPARSEARGSFROMSTRING( char*, int64, int64 );
static int64 HTARGETNEEDSPIC( void );
static void HPARSEARGS( int64, char** );
static void HCHECKARGS( void );
static void FBCDETERMINEPREFIX( void );
static void FBCSETUPCOMPILERPATHS( void );
static void FBCPRINTTARGETINFO( void );
static void FBCDETERMINEMAINNAME( void );
static FBSTRING* HGETASMNAME( struct $9FBCIOFILE*, int64 );
static void HCOMPILEBAS( struct $9FBCIOFILE*, int64, int64, int64 );
static void HCOMPILEMODULES( void );
static int64 HPARSEXPM( FBSTRING*, FBSTRING* );
static int64 HCOMPILEXPM( void );
static int64 HCOMPILESTAGE2MODULE( struct $9FBCIOFILE* );
static void HCOMPILESTAGE2MODULES( void );
static int64 HASSEMBLEMODULE( struct $9FBCIOFILE* );
static void HASSEMBLEMODULES( void );
static int64 HASSEMBLERC( struct $9FBCIOFILE* );
static void HASSEMBLERCS( void );
static void HASSEMBLEXPM( void );
static int64 HCOMPILEFBCTINF( void );
static int64 HARCHIVEFILES( void );
static void HSETDEFAULTLIBPATHS( void );
static void FBCADDDEFLIB( char* );
static FBSTRING* HGETFBLIBNAMESUFFIX( void );
static void HADDDEFAULTLIBS( void );
static void HEXCLUDELIBSFROMLINK( void );
static void HPRINTOPTIONS( int64 );
static void _GLOBAL__I( void ) __attribute__(( constructor ));
static void _GLOBAL__D( void ) __attribute__(( destructor ));
static struct $11FBCTOOLINFO FBCTOOLTB$[16] = { { "", "", 0ll }, { "as", "AS", 3ll }, { "ar", "AR", 3ll }, { "ld", "LD", 3ll }, { "gcc", "GCC", 3ll }, { "llc", "LLC", 3ll }, { "clang", "CLANG", 3ll }, { "dlltool", "DLLTOOL", 3ll }, { "GoRC", "GORC", 3ll }, { "windres", "WINDRES", 3ll }, { "cxbe", "CXBE", 3ll }, { "dxe3gen", "DXEGEN", 3ll }, { "emcc", "EMAS", 3ll }, { "emar", "EMAR", 3ll }, { "emcc", "EMLD", 3ll }, { "emcc", "EMCC", 3ll } };
static struct $6FBCCTX FBC$;
static struct $11FBGNUOSINFO GNUOSMAP$[17] = { { (char*)"android", 3ll }, { (char*)"linux", 2ll }, { (char*)"mingw", 0ll }, { (char*)"djgpp", 4ll }, { (char*)"msdosdjgpp", 4ll }, { (char*)"cygwin", 1ll }, { (char*)"darwin", 10ll }, { (char*)"freebsd", 6ll }, { (char*)"dragonfly", 7ll }, { (char*)"solaris", 8ll }, { (char*)"netbsd", 11ll }, { (char*)"openbsd", 9ll }, { (char*)"xbox", 5ll }, { (char*)"amigaos4", 16ll }, { (char*)"amigaos", 13ll }, { (char*)"aros", 14ll }, { (char*)"morphos", 15ll } };
static struct $13FBGNUARCHINFO GNUARCHMAP$[21] = { { (char*)"i386", 0ll }, { (char*)"i486", 1ll }, { (char*)"i586", 2ll }, { (char*)"i686", 3ll }, { (char*)"x86", 3ll }, { (char*)"x86_64", 13ll }, { (char*)"amd64", 13ll }, { (char*)"armv5te", 14ll }, { (char*)"armv6", 15ll }, { (char*)"armv6+fp", 16ll }, { (char*)"armv7a", 17ll }, { (char*)"armv7a+fp", 18ll }, { (char*)"arm", 17ll }, { (char*)"aarch64", 19ll }, { (char*)"ppc", 20ll }, { (char*)"powerpc", 20ll }, { (char*)"ppc64  ", 21ll }, { (char*)"powerpc64", 21ll }, { (char*)"ppc64le  ", 22ll }, { (char*)"powerpc64le", 22ll }, { (char*)"m68k", 24ll } };
static struct $12FBOSARCHINFO FBOSARCHMAP$[17] = { { (char*)"win32", 0ll, 3ll }, { (char*)"win64", 0ll, 13ll }, { (char*)"dragonfly", 7ll, 13ll }, { (char*)"solaris", 8ll, 13ll }, { (char*)"dos", 4ll, 3ll }, { (char*)"xbox", 5ll, 3ll }, { (char*)"cygwin", 1ll, 19ll }, { (char*)"darwin", 10ll, 19ll }, { (char*)"freebsd", 6ll, 19ll }, { (char*)"linux", 2ll, 19ll }, { (char*)"android", 3ll, 17ll }, { (char*)"netbsd", 11ll, 19ll }, { (char*)"openbsd", 9ll, 19ll }, { (char*)"amiga", 13ll, 24ll }, { (char*)"aros", 14ll, 19ll }, { (char*)"morphos", 15ll, 20ll }, { (char*)"amigaos4", 16ll, 20ll } };
static struct $18FBC_CMDLINE_OPTION CMDLINEOPTIONTB$[74] = { { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)0, -1ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, -1ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, -1ll }, { (boolean)0, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)0, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)0, -1ll }, { (boolean)0, (boolean)1, (boolean)0, -1ll }, { (boolean)1, (boolean)1, (boolean)0, -1ll }, { (boolean)1, (boolean)0, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)0, (boolean)1, (boolean)1, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)0, -1ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll }, { (boolean)0, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)0, 0ll }, { (boolean)1, (boolean)1, (boolean)1, -1ll } };

int64 FBCPUTYPEFROMGNUARCHINFO( FBSTRING* ARCH$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$561:;
	{
		int64 I$2;
		I$2 = 0ll;
		label$566:;
		{
			int32 vr$2 = fb_StrCompare( (void*)ARCH$1, -1ll, *(void**)((int64)(struct $13FBGNUARCHINFO*)GNUARCHMAP$ + (I$2 << (4ll & 63ll))), 0ll );
			if( (int64)vr$2 != 0ll) goto label$568;
			{
				fb$result$1 = *(int64*)(((int64)(struct $13FBGNUARCHINFO*)GNUARCHMAP$ + (I$2 << (4ll & 63ll))) + 8ll);
				goto label$562;
			}
			label$568:;
			label$567:;
		}
		label$564:;
		I$2 = I$2 + 1ll;
		label$563:;
		if( I$2 <= 20ll) goto label$566;
		label$565:;
	}
	fb$result$1 = -1ll;
	goto label$562;
	label$562:;
	return fb$result$1;
}

void FBCPARSEARGSFROMSTRING( char* ARGS_IN$1, int64 IS_SOURCE$1, int64 IS_FILE$1 )
{
	label$1046:;
	FBSTRING ARGS$1;
	fb_StrInit( (void*)&ARGS$1, -1ll, (void*)ARGS_IN$1, 0ll, 0 );
	FBSTRING ARG$1;
	__builtin_memset( &ARG$1, 0, 24ll );
	label$1048:;
	{
		int64 LENGTH$2;
		int64 vr$3 = fb_StrLen( (void*)&ARGS$1, -1ll );
		LENGTH$2 = vr$3;
		if( LENGTH$2 != 0ll) goto label$1052;
		{
			goto label$1049;
		}
		label$1052:;
		label$1051:;
		int64 I$2;
		I$2 = 0ll;
		int64 QUOTECH$2;
		QUOTECH$2 = 0ll;
		label$1053:;
		if( I$2 >= LENGTH$2) goto label$1054;
		{
			int64 CH$3;
			CH$3 = (int64)*(uint8*)((uint8*)*(char**)&ARGS$1 + I$2);
			{
				uint64 TMP$532$4;
				TMP$532$4 = (uint64)CH$3;
				goto label$1056;
				label$1057:;
				{
					if( QUOTECH$2 != 0ll) goto label$1059;
					{
						goto label$1054;
					}
					label$1059:;
					label$1058:;
				}
				goto label$1055;
				label$1060:;
				{
					if( QUOTECH$2 != CH$3) goto label$1062;
					{
						QUOTECH$2 = 0ll;
					}
					goto label$1061;
					label$1062:;
					if( QUOTECH$2 != 0ll) goto label$1063;
					{
						QUOTECH$2 = CH$3;
					}
					label$1063:;
					label$1061:;
				}
				goto label$1055;
				label$1056:;
				static const void* tmp$534[8ll] = {
					&&label$1057,
					&&label$1055,
					&&label$1060,
					&&label$1055,
					&&label$1055,
					&&label$1055,
					&&label$1055,
					&&label$1060,
				};
				if( (TMP$532$4 - 32ull) > 7ull ) goto label$1055;
				goto *tmp$534[TMP$532$4 - 32ull];
				label$1055:;
			}
			I$2 = I$2 + 1ll;
		}
		goto label$1053;
		label$1054:;
		if( I$2 != 0ll) goto label$1065;
		{
			I$2 = 1ll;
		}
		goto label$1064;
		label$1065:;
		{
			FBSTRING* vr$8 = fb_LEFT( (FBSTRING*)&ARGS$1, I$2 );
			fb_StrAssign( (void*)&ARG$1, -1ll, (void*)vr$8, -1ll, 0 );
			FBSTRING* vr$11 = fb_TRIM( (FBSTRING*)&ARG$1 );
			fb_StrAssign( (void*)&ARG$1, -1ll, (void*)vr$11, -1ll, 0 );
			FBSTRING* vr$14 = STRUNQUOTE( &ARG$1 );
			fb_StrAssign( (void*)&ARG$1, -1ll, (void*)vr$14, -1ll, 0 );
			HANDLEARG( &ARG$1, IS_SOURCE$1, IS_FILE$1 );
		}
		label$1064:;
		FBSTRING* vr$19 = fb_RIGHT( (FBSTRING*)&ARGS$1, LENGTH$2 - I$2 );
		fb_StrAssign( (void*)&ARGS$1, -1ll, (void*)vr$19, -1ll, 0 );
	}
	label$1050:;
	goto label$1048;
	label$1049:;
	fb_StrDelete( (FBSTRING*)&ARG$1 );
	fb_StrDelete( (FBSTRING*)&ARGS$1 );
	label$1047:;
}

int32 main( int32 __FB_ARGC__$0, char** __FB_ARGV__$0 )
{
	int32 fb$result$0;
	__builtin_memset( &fb$result$0, 0, 4ll );
	fb_Init( __FB_ARGC__$0, (char**)__FB_ARGV__$0, 0 );
	fb_InitSignals(  );
	label$0:;
	FBCINIT(  );
	if( (int64)__FB_ARGC__$0 != 1ll) goto label$1585;
	{
		HPRINTOPTIONS( 0ll );
		FBCEND( 1ll );
	}
	label$1585:;
	label$1584:;
	HPARSEARGS( (int64)__FB_ARGC__$0, (char**)__FB_ARGV__$0 );
	HCHECKARGS(  );
	if( *(int64*)((uint8*)&FBC$ + 120ll) == 0ll) goto label$1587;
	{
		HPRINTVERSION( *(int64*)((uint8*)&FBC$ + 112ll) );
		FBCEND( 0ll );
	}
	label$1587:;
	label$1586:;
	if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$1589;
	{
		*(int64*)((uint8*)&FBC$ + 120ll) = -1ll;
		HPRINTVERSION( 0ll );
	}
	label$1589:;
	label$1588:;
	if( *(int64*)((uint8*)&FBC$ + 128ll) == 0ll) goto label$1591;
	{
		HPRINTOPTIONS( *(int64*)((uint8*)&FBC$ + 112ll) );
		FBCEND( 1ll );
	}
	label$1591:;
	label$1590:;
	label$1592:;
	{
		FBSTRING TMP$883$1;
		FBCDETERMINEPREFIX(  );
		FBCSETUPCOMPILERPATHS(  );
		if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$1596;
		{
			FBCPRINTTARGETINFO(  );
		}
		label$1596:;
		label$1595:;
		__builtin_memset( &TMP$883$1, 0, 24ll );
		fb_StrAssign( (void*)&TMP$883$1, -1ll, (void*)((uint8*)&FBC$ + 3298ll), 261ll, 0 );
		FBADDINCLUDEPATH( &TMP$883$1 );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 3298ll), 261ll, (void*)&TMP$883$1, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&TMP$883$1 );
		int64 HAVE_INPUT_FILES$1;
		void* vr$11 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 144ll) );
		void* vr$14 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 400ll) );
		void* vr$18 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 528ll) );
		void* vr$22 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 464ll) );
		HAVE_INPUT_FILES$1 = (((int64)-(vr$11 != (void*)0ull) | (int64)-(vr$14 != (void*)0ull)) | (int64)-(vr$18 != (void*)0ull)) | (int64)-(vr$22 != (void*)0ull);
		if( *(int64*)((uint8*)&FBC$ + 136ll) < 0ll) goto label$1598;
		{
			{
				int64 TMP$884$3;
				TMP$884$3 = *(int64*)((uint8*)&FBC$ + 136ll);
				if( TMP$884$3 != 0ll) goto label$1600;
				label$1601:;
				{
					FBSTRING* vr$25 = FBGETHOSTID(  );
					fb_PrintString( 0, (FBSTRING*)vr$25, 1 );
				}
				goto label$1599;
				label$1600:;
				if( TMP$884$3 != 1ll) goto label$1602;
				label$1603:;
				{
					FBSTRING* vr$26 = FBGETTARGETID(  );
					fb_PrintString( 0, (FBSTRING*)vr$26, 1 );
				}
				goto label$1599;
				label$1602:;
				if( TMP$884$3 != 2ll) goto label$1604;
				label$1605:;
				{
					if( HAVE_INPUT_FILES$1 == 0ll) goto label$1607;
					{
						FBCDETERMINEMAINNAME(  );
					}
					label$1607:;
					label$1606:;
					HSETOUTNAME(  );
					FBSTRING* vr$28 = fb_StrAllocTempDescZ( (char*)((uint8*)&FBC$ + 968ll) );
					fb_PrintString( 0, (FBSTRING*)vr$28, 1 );
				}
				goto label$1599;
				label$1604:;
				if( TMP$884$3 != 3ll) goto label$1608;
				label$1609:;
				{
					FBSTRING* vr$30 = fb_StrAllocTempDescZ( (char*)((uint8*)&FBC$ + 3559ll) );
					fb_PrintString( 0, (FBSTRING*)vr$30, 1 );
				}
				goto label$1599;
				label$1608:;
				if( TMP$884$3 != 4ll) goto label$1610;
				label$1611:;
				{
					FBSTRING* vr$31 = fb_StrAllocTempDescZEx( (char*)"", 0ll );
					fb_PrintString( 0, (FBSTRING*)vr$31, 1 );
				}
				goto label$1599;
				label$1610:;
				if( TMP$884$3 != 5ll) goto label$1612;
				label$1613:;
				{
					FBSTRING* vr$32 = fb_StrAllocTempDescZEx( (char*)"", 0ll );
					fb_PrintString( 0, (FBSTRING*)vr$32, 1 );
				}
				label$1612:;
				label$1599:;
			}
			FBCEND( 0ll );
		}
		label$1598:;
		label$1597:;
		FBCDETERMINEMAINNAME(  );
		if( HAVE_INPUT_FILES$1 != 0ll) goto label$1615;
		{
			HPRINTOPTIONS( *(int64*)((uint8*)&FBC$ + 112ll) );
			FBCEND( 1ll );
		}
		label$1615:;
		label$1614:;
		HCOMPILEMODULES(  );
		int64 vr$33 = FBSHOULDRESTART(  );
		if( vr$33 != 0ll) goto label$1617;
		{
			goto label$1593;
		}
		label$1617:;
		label$1616:;
		FBRESTARTENDREQUEST( 8ll );
		ERRPREINIT(  );
		HCHECKARGS(  );
		if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$1619;
		{
			FBSTRING* vr$34 = fb_StrAllocTempDescZEx( (char*)"Restarting fbc ...", 18ll );
			fb_PrintString( 0, (FBSTRING*)vr$34, 1 );
		}
		label$1619:;
		label$1618:;
	}
	label$1594:;
	goto label$1592;
	label$1593:;
	int64 vr$35 = HCOMPILEXPM(  );
	if( vr$35 != 0ll) goto label$1621;
	{
		FBCEND( 1ll );
	}
	label$1621:;
	label$1620:;
	if( *(int64*)((uint8*)&FBC$ + 72ll) == 0ll) goto label$1623;
	{
		FBCEND( 0ll );
	}
	label$1623:;
	label$1622:;
	int64 vr$36 = FBGETOPTION( 2ll );
	int64 vr$38 = FBGETOPTION( 2ll );
	if( ((int64)-(vr$36 != 0ll) & (int64)-(vr$38 != 4ll)) == 0ll) goto label$1625;
	{
		HCOMPILESTAGE2MODULES(  );
	}
	label$1625:;
	label$1624:;
	if( *(int64*)((uint8*)&FBC$ + 88ll) == 0ll) goto label$1627;
	{
		FBCEND( 0ll );
	}
	label$1627:;
	label$1626:;
	HASSEMBLEMODULES(  );
	HASSEMBLERCS(  );
	HASSEMBLEXPM(  );
	int64 vr$41 = FBGETOPTION( 0ll );
	if( vr$41 != 3ll) goto label$1629;
	{
		FBCEND( 0ll );
	}
	label$1629:;
	label$1628:;
	HSETDEFAULTLIBPATHS(  );
	int64 vr$42 = FBGETOPTION( 40ll );
	int64 vr$43 = FBISCROSSCOMP(  );
	if( (vr$42 & ~vr$43) == 0ll) goto label$1631;
	{
		HCOLLECTOBJINFO(  );
	}
	label$1631:;
	label$1630:;
	int64 vr$46 = FBGETOPTION( 0ll );
	if( vr$46 != 1ll) goto label$1633;
	{
		int64 vr$47 = HARCHIVEFILES(  );
		if( vr$47 != 0ll) goto label$1635;
		{
			FBCEND( 1ll );
		}
		label$1635:;
		label$1634:;
		FBCEND( 0ll );
	}
	label$1633:;
	label$1632:;
	if( *(int64*)((uint8*)&FBC$ + 2744ll) != 0ll) goto label$1637;
	{
		HADDDEFAULTLIBS(  );
	}
	label$1637:;
	label$1636:;
	HEXCLUDELIBSFROMLINK(  );
	int64 vr$48 = HLINKFILES(  );
	if( vr$48 != 0ll) goto label$1639;
	{
		FBCEND( 1ll );
	}
	label$1639:;
	label$1638:;
	FBCEND( 0ll );
	label$1:;
	fb_End( 0 );
	return fb$result$0;
}

static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM* THIS$1, struct $11TSTRSETITEM* __FB_RHS__$1 )
{
	label$4:;
	fb_StrAssign( (void*)THIS$1, -1ll, (void*)__FB_RHS__$1, -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 24ll) = *(int64*)((uint8*)__FB_RHS__$1 + 24ll);
	*(struct $8HASHITEM**)((uint8*)THIS$1 + 32ll) = *(struct $8HASHITEM**)((uint8*)__FB_RHS__$1 + 32ll);
	label$5:;
}

static void _ZN10FBC_EXTOPTC1Ev( struct $10FBC_EXTOPT* THIS$1 )
{
	__builtin_memset( (FBSTRING*)THIS$1, 0, 24ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 24ll), 0, 24ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 48ll), 0, 24ll );
	label$10:;
	label$11:;
}

static void _ZN10FBC_EXTOPTaSERKS_( struct $10FBC_EXTOPT* THIS$1, struct $10FBC_EXTOPT* __FB_RHS__$1 )
{
	label$12:;
	fb_StrAssign( (void*)THIS$1, -1ll, (void*)__FB_RHS__$1, -1ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 24ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 24ll), -1ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 48ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 48ll), -1ll, 0 );
	label$13:;
}

static void _ZN10FBC_EXTOPTD1Ev( struct $10FBC_EXTOPT* THIS$1 )
{
	label$16:;
	label$17:;
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 48ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 24ll) );
	fb_StrDelete( (FBSTRING*)THIS$1 );
}

static void _ZN9FBCIOFILEC1Ev( struct $9FBCIOFILE* THIS$1 )
{
	__builtin_memset( (FBSTRING*)THIS$1, 0, 24ll );
	__builtin_memset( (FBSTRING**)((uint8*)THIS$1 + 24ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 32ll), 0, 8ll );
	label$18:;
	label$19:;
}

static void _ZN9FBCIOFILEaSERKS_( struct $9FBCIOFILE* THIS$1, struct $9FBCIOFILE* __FB_RHS__$1 )
{
	label$20:;
	fb_StrAssign( (void*)THIS$1, -1ll, (void*)__FB_RHS__$1, -1ll, 0 );
	*(FBSTRING**)((uint8*)THIS$1 + 24ll) = *(FBSTRING**)((uint8*)__FB_RHS__$1 + 24ll);
	*(int64*)((uint8*)THIS$1 + 32ll) = *(int64*)((uint8*)__FB_RHS__$1 + 32ll);
	label$21:;
}

static void _ZN9FBCIOFILED1Ev( struct $9FBCIOFILE* THIS$1 )
{
	label$24:;
	label$25:;
	fb_StrDelete( (FBSTRING*)THIS$1 );
}

static void _ZN6FBCCTXC1Ev( struct $6FBCCTX* THIS$1 )
{
	__builtin_memset( (int64*)THIS$1, 0, 8ll );
	__builtin_memset( (struct $9FBCIOFILE**)((uint8*)THIS$1 + 8ll), 0, 8ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 16ll), 0, 24ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 40ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 48ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 56ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 64ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 72ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 80ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 88ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 96ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 104ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 112ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 120ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 128ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 136ll), 0, 8ll );
	__builtin_memset( (struct $5TLIST*)((uint8*)THIS$1 + 144ll), 0, 64ll );
	__builtin_memset( (struct $5TLIST*)((uint8*)THIS$1 + 208ll), 0, 64ll );
	_ZN9FBCIOFILEC1Ev( (struct $9FBCIOFILE*)((uint8*)THIS$1 + 272ll) );
	__builtin_memset( (struct $7TSTRSET*)((uint8*)THIS$1 + 312ll), 0, 88ll );
	__builtin_memset( (struct $5TLIST*)((uint8*)THIS$1 + 400ll), 0, 64ll );
	__builtin_memset( (struct $5TLIST*)((uint8*)THIS$1 + 464ll), 0, 64ll );
	__builtin_memset( (struct $7TSTRSET*)((uint8*)THIS$1 + 528ll), 0, 88ll );
	__builtin_memset( (struct $7TSTRSET*)((uint8*)THIS$1 + 616ll), 0, 88ll );
	__builtin_memset( (struct $7TSTRSET*)((uint8*)THIS$1 + 704ll), 0, 88ll );
	__builtin_memset( (struct $7TSTRSET*)((uint8*)THIS$1 + 792ll), 0, 88ll );
	__builtin_memset( (struct $7TSTRSET*)((uint8*)THIS$1 + 880ll), 0, 88ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 968ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 1229ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 1490ll), 0, 129ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 1624ll), 0, 8ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 1632ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 1893ll), 0, 129ll );
	_ZN10FBC_EXTOPTC1Ev( (struct $10FBC_EXTOPT*)((uint8*)THIS$1 + 2024ll) );
	__builtin_memset( (char*)((uint8*)THIS$1 + 2096ll), 0, 129ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 2225ll), 0, 129ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 2354ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 2615ll), 0, 129ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 2744ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 2752ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 2760ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 2768ll), 0, 8ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 2776ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 3037ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 3298ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 3559ll), 0, 261ll );
	__builtin_memset( (char*)((uint8*)THIS$1 + 3820ll), 0, 261ll );
	__builtin_memset( (struct $10FBC_OBJINF*)((uint8*)THIS$1 + 4088ll), 0, 16ll );
	label$26:;
	label$27:;
}

static void _ZN6FBCCTXaSERKS_( struct $6FBCCTX* THIS$1, struct $6FBCCTX* __FB_RHS__$1 )
{
	label$28:;
	*(int64*)THIS$1 = *(int64*)__FB_RHS__$1;
	*(struct $9FBCIOFILE**)((uint8*)THIS$1 + 8ll) = *(struct $9FBCIOFILE**)((uint8*)__FB_RHS__$1 + 8ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 16ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 16ll), -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 40ll) = *(int64*)((uint8*)__FB_RHS__$1 + 40ll);
	*(int64*)((uint8*)THIS$1 + 48ll) = *(int64*)((uint8*)__FB_RHS__$1 + 48ll);
	*(int64*)((uint8*)THIS$1 + 56ll) = *(int64*)((uint8*)__FB_RHS__$1 + 56ll);
	*(int64*)((uint8*)THIS$1 + 64ll) = *(int64*)((uint8*)__FB_RHS__$1 + 64ll);
	*(int64*)((uint8*)THIS$1 + 72ll) = *(int64*)((uint8*)__FB_RHS__$1 + 72ll);
	*(int64*)((uint8*)THIS$1 + 80ll) = *(int64*)((uint8*)__FB_RHS__$1 + 80ll);
	*(int64*)((uint8*)THIS$1 + 88ll) = *(int64*)((uint8*)__FB_RHS__$1 + 88ll);
	*(int64*)((uint8*)THIS$1 + 96ll) = *(int64*)((uint8*)__FB_RHS__$1 + 96ll);
	*(int64*)((uint8*)THIS$1 + 104ll) = *(int64*)((uint8*)__FB_RHS__$1 + 104ll);
	*(int64*)((uint8*)THIS$1 + 112ll) = *(int64*)((uint8*)__FB_RHS__$1 + 112ll);
	*(int64*)((uint8*)THIS$1 + 120ll) = *(int64*)((uint8*)__FB_RHS__$1 + 120ll);
	*(int64*)((uint8*)THIS$1 + 128ll) = *(int64*)((uint8*)__FB_RHS__$1 + 128ll);
	*(int64*)((uint8*)THIS$1 + 136ll) = *(int64*)((uint8*)__FB_RHS__$1 + 136ll);
	__builtin_memcpy( (struct $5TLIST*)((uint8*)THIS$1 + 144ll), (struct $5TLIST*)((uint8*)__FB_RHS__$1 + 144ll), 64 );
	__builtin_memcpy( (struct $5TLIST*)((uint8*)THIS$1 + 208ll), (struct $5TLIST*)((uint8*)__FB_RHS__$1 + 208ll), 64 );
	_ZN9FBCIOFILEaSERKS_( (struct $9FBCIOFILE*)((uint8*)THIS$1 + 272ll), (struct $9FBCIOFILE*)((uint8*)__FB_RHS__$1 + 272ll) );
	__builtin_memcpy( (struct $7TSTRSET*)((uint8*)THIS$1 + 312ll), (struct $7TSTRSET*)((uint8*)__FB_RHS__$1 + 312ll), 88 );
	__builtin_memcpy( (struct $5TLIST*)((uint8*)THIS$1 + 400ll), (struct $5TLIST*)((uint8*)__FB_RHS__$1 + 400ll), 64 );
	__builtin_memcpy( (struct $5TLIST*)((uint8*)THIS$1 + 464ll), (struct $5TLIST*)((uint8*)__FB_RHS__$1 + 464ll), 64 );
	__builtin_memcpy( (struct $7TSTRSET*)((uint8*)THIS$1 + 528ll), (struct $7TSTRSET*)((uint8*)__FB_RHS__$1 + 528ll), 88 );
	__builtin_memcpy( (struct $7TSTRSET*)((uint8*)THIS$1 + 616ll), (struct $7TSTRSET*)((uint8*)__FB_RHS__$1 + 616ll), 88 );
	__builtin_memcpy( (struct $7TSTRSET*)((uint8*)THIS$1 + 704ll), (struct $7TSTRSET*)((uint8*)__FB_RHS__$1 + 704ll), 88 );
	__builtin_memcpy( (struct $7TSTRSET*)((uint8*)THIS$1 + 792ll), (struct $7TSTRSET*)((uint8*)__FB_RHS__$1 + 792ll), 88 );
	__builtin_memcpy( (struct $7TSTRSET*)((uint8*)THIS$1 + 880ll), (struct $7TSTRSET*)((uint8*)__FB_RHS__$1 + 880ll), 88 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 968ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 968ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 1229ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 1229ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 1490ll), 129ll, (void*)((uint8*)__FB_RHS__$1 + 1490ll), 129ll, 0 );
	*(int64*)((uint8*)THIS$1 + 1624ll) = *(int64*)((uint8*)__FB_RHS__$1 + 1624ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 1632ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 1632ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 1893ll), 129ll, (void*)((uint8*)__FB_RHS__$1 + 1893ll), 129ll, 0 );
	_ZN10FBC_EXTOPTaSERKS_( (struct $10FBC_EXTOPT*)((uint8*)THIS$1 + 2024ll), (struct $10FBC_EXTOPT*)((uint8*)__FB_RHS__$1 + 2024ll) );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 2096ll), 129ll, (void*)((uint8*)__FB_RHS__$1 + 2096ll), 129ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 2225ll), 129ll, (void*)((uint8*)__FB_RHS__$1 + 2225ll), 129ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 2354ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 2354ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 2615ll), 129ll, (void*)((uint8*)__FB_RHS__$1 + 2615ll), 129ll, 0 );
	*(int64*)((uint8*)THIS$1 + 2744ll) = *(int64*)((uint8*)__FB_RHS__$1 + 2744ll);
	*(int64*)((uint8*)THIS$1 + 2752ll) = *(int64*)((uint8*)__FB_RHS__$1 + 2752ll);
	*(int64*)((uint8*)THIS$1 + 2760ll) = *(int64*)((uint8*)__FB_RHS__$1 + 2760ll);
	*(int64*)((uint8*)THIS$1 + 2768ll) = *(int64*)((uint8*)__FB_RHS__$1 + 2768ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 2776ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 2776ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 3037ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 3037ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 3298ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 3298ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 3559ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 3559ll), 261ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 3820ll), 261ll, (void*)((uint8*)__FB_RHS__$1 + 3820ll), 261ll, 0 );
	__builtin_memcpy( (struct $10FBC_OBJINF*)((uint8*)THIS$1 + 4088ll), (struct $10FBC_OBJINF*)((uint8*)__FB_RHS__$1 + 4088ll), 16 );
	label$29:;
}

static void _ZN6FBCCTXD1Ev( struct $6FBCCTX* THIS$1 )
{
	label$32:;
	label$33:;
	_ZN10FBC_EXTOPTD1Ev( (struct $10FBC_EXTOPT*)((uint8*)THIS$1 + 2024ll) );
	_ZN9FBCIOFILED1Ev( (struct $9FBCIOFILE*)((uint8*)THIS$1 + 272ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 16ll) );
}

static void FBCINIT( void )
{
	label$34:;
	*(int64*)((uint8*)&FBC$ + 40ll) = -1ll;
	*(int64*)((uint8*)&FBC$ + 48ll) = -1ll;
	*(int64*)((uint8*)&FBC$ + 64ll) = -1ll;
	LISTINIT( (struct $5TLIST*)((uint8*)&FBC$ + 144ll), 64ll, 40ll, 4294967295ll );
	LISTINIT( (struct $5TLIST*)((uint8*)&FBC$ + 208ll), 16ll, 40ll, 4294967295ll );
	STRSETINIT( (struct $7TSTRSET*)((uint8*)&FBC$ + 312ll), 16ll );
	STRLISTINIT( (struct $5TLIST*)((uint8*)&FBC$ + 400ll), 64ll );
	STRLISTINIT( (struct $5TLIST*)((uint8*)&FBC$ + 464ll), 16ll );
	STRSETINIT( (struct $7TSTRSET*)((uint8*)&FBC$ + 528ll), 16ll );
	STRSETINIT( (struct $7TSTRSET*)((uint8*)&FBC$ + 616ll), 16ll );
	STRSETINIT( (struct $7TSTRSET*)((uint8*)&FBC$ + 704ll), 16ll );
	STRSETINIT( (struct $7TSTRSET*)((uint8*)&FBC$ + 792ll), 32ll );
	STRSETINIT( (struct $7TSTRSET*)((uint8*)&FBC$ + 880ll), 32ll );
	FBGLOBALINIT(  );
	int64 vr$10 = FBGETOPTION( 10ll );
	*($7FB_LANG*)((uint8*)&FBC$ + 4088ll) = vr$10;
	*(int64*)((uint8*)&FBC$ + 136ll) = -1ll;
	label$35:;
}

static void HSETOUTNAME( void )
{
	label$36:;
	int64 vr$1 = fb_StrLen( (void*)((uint8*)&FBC$ + 968ll), 261ll );
	if( vr$1 <= 0ll) goto label$39;
	{
		goto label$37;
	}
	label$39:;
	label$38:;
	int64 vr$2 = FBGETOPTION( 0ll );
	if( vr$2 != 1ll) goto label$41;
	{
		FBSTRING TMP$56$2;
		FBSTRING TMP$57$2;
		FBSTRING TMP$58$2;
		FBSTRING* vr$4 = HSTRIPPATH( (char*)((uint8*)&FBC$ + 1229ll) );
		FBSTRING* vr$6 = HSTRIPFILENAME( (char*)((uint8*)&FBC$ + 1229ll) );
		__builtin_memset( &TMP$56$2, 0, 24ll );
		FBSTRING* vr$9 = fb_StrConcat( &TMP$56$2, (void*)vr$6, -1ll, (void*)"lib", 4ll );
		__builtin_memset( &TMP$57$2, 0, 24ll );
		FBSTRING* vr$12 = fb_StrConcat( &TMP$57$2, (void*)vr$9, -1ll, (void*)vr$4, -1ll );
		__builtin_memset( &TMP$58$2, 0, 24ll );
		FBSTRING* vr$15 = fb_StrConcat( &TMP$58$2, (void*)vr$12, -1ll, (void*)".a", 3ll );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)vr$15, -1ll, 0 );
		goto label$37;
	}
	label$41:;
	label$40:;
	fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)((uint8*)&FBC$ + 1229ll), 261ll, 0 );
	{
		int64 TMP$59$2;
		int64 vr$19 = FBGETOPTION( 0ll );
		TMP$59$2 = vr$19;
		if( TMP$59$2 != 0ll) goto label$43;
		label$44:;
		{
			{
				int64 TMP$60$4;
				int64 vr$20 = FBGETOPTION( 3ll );
				TMP$60$4 = vr$20;
				if( TMP$60$4 == 4ll) goto label$47;
				label$48:;
				if( TMP$60$4 == 1ll) goto label$47;
				label$49:;
				if( TMP$60$4 == 0ll) goto label$47;
				label$50:;
				if( TMP$60$4 != 5ll) goto label$46;
				label$47:;
				{
					FBSTRING TMP$61$5;
					__builtin_memset( &TMP$61$5, 0, 24ll );
					FBSTRING* vr$24 = fb_StrConcat( &TMP$61$5, (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)".exe", 5ll );
					fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)vr$24, -1ll, 0 );
				}
				goto label$45;
				label$46:;
				if( TMP$60$4 != 12ll) goto label$51;
				label$52:;
				{
					FBSTRING TMP$63$5;
					__builtin_memset( &TMP$63$5, 0, 24ll );
					FBSTRING* vr$29 = fb_StrConcat( &TMP$63$5, (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)".html", 6ll );
					fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)vr$29, -1ll, 0 );
				}
				label$51:;
				label$45:;
			}
		}
		goto label$42;
		label$43:;
		if( TMP$59$2 != 2ll) goto label$53;
		label$54:;
		{
			{
				int64 TMP$64$4;
				int64 vr$31 = FBGETOPTION( 3ll );
				TMP$64$4 = vr$31;
				if( TMP$64$4 == 1ll) goto label$57;
				label$58:;
				if( TMP$64$4 != 0ll) goto label$56;
				label$57:;
				{
					FBSTRING TMP$66$5;
					__builtin_memset( &TMP$66$5, 0, 24ll );
					FBSTRING* vr$35 = fb_StrConcat( &TMP$66$5, (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)".dll", 5ll );
					fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)vr$35, -1ll, 0 );
				}
				goto label$55;
				label$56:;
				if( TMP$64$4 == 2ll) goto label$60;
				label$61:;
				if( TMP$64$4 == 10ll) goto label$60;
				label$62:;
				if( TMP$64$4 == 6ll) goto label$60;
				label$63:;
				if( TMP$64$4 == 9ll) goto label$60;
				label$64:;
				if( TMP$64$4 == 11ll) goto label$60;
				label$65:;
				if( TMP$64$4 == 7ll) goto label$60;
				label$66:;
				if( TMP$64$4 == 8ll) goto label$60;
				label$67:;
				if( TMP$64$4 != 3ll) goto label$59;
				label$60:;
				{
					FBSTRING TMP$68$5;
					FBSTRING TMP$69$5;
					FBSTRING TMP$70$5;
					FBSTRING* vr$38 = HSTRIPPATH( (char*)((uint8*)&FBC$ + 968ll) );
					FBSTRING* vr$40 = HSTRIPFILENAME( (char*)((uint8*)&FBC$ + 968ll) );
					__builtin_memset( &TMP$68$5, 0, 24ll );
					FBSTRING* vr$43 = fb_StrConcat( &TMP$68$5, (void*)vr$40, -1ll, (void*)"lib", 4ll );
					__builtin_memset( &TMP$69$5, 0, 24ll );
					FBSTRING* vr$46 = fb_StrConcat( &TMP$69$5, (void*)vr$43, -1ll, (void*)vr$38, -1ll );
					__builtin_memset( &TMP$70$5, 0, 24ll );
					FBSTRING* vr$49 = fb_StrConcat( &TMP$70$5, (void*)vr$46, -1ll, (void*)".so", 4ll );
					fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)vr$49, -1ll, 0 );
				}
				goto label$55;
				label$59:;
				if( TMP$64$4 != 4ll) goto label$68;
				label$69:;
				{
					FBSTRING TMP$72$5;
					__builtin_memset( &TMP$72$5, 0, 24ll );
					FBSTRING* vr$54 = fb_StrConcat( &TMP$72$5, (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)".dxe", 5ll );
					fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)vr$54, -1ll, 0 );
				}
				label$68:;
				label$55:;
			}
		}
		label$53:;
		label$42:;
	}
	label$37:;
}

static void FBCEND( int64 ERRNUM$1 )
{
	label$70:;
	struct $11TSTRSETITEM* FILE$1;
	void* vr$1 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 312ll) );
	FILE$1 = (struct $11TSTRSETITEM*)vr$1;
	label$72:;
	if( FILE$1 == (struct $11TSTRSETITEM*)0ull) goto label$73;
	{
		int32 vr$4 = fb_FileKill( (FBSTRING*)FILE$1 );
		if( (int64)vr$4 == 0ll) goto label$75;
		{
		}
		label$75:;
		label$74:;
		void* vr$6 = LISTGETNEXT( (void*)FILE$1 );
		FILE$1 = (struct $11TSTRSETITEM*)vr$6;
	}
	goto label$72;
	label$73:;
	fb_End( (int32)ERRNUM$1 );
	label$71:;
}

static void FBCADDTEMP( FBSTRING* FILE$1 )
{
	label$76:;
	STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 312ll), FILE$1, 0ll );
	label$77:;
}

static void FBCREMOVETEMP( FBSTRING* FILE$1 )
{
	label$78:;
	STRSETDEL( (struct $7TSTRSET*)((uint8*)&FBC$ + 312ll), (FBSTRING*)FILE$1 );
	label$79:;
}

static FBSTRING* FBCADDOBJ( FBSTRING* FILE$1 )
{
	FBSTRING* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$80:;
	FBSTRING* S$1;
	void* vr$2 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&FBC$ + 400ll) );
	S$1 = (FBSTRING*)vr$2;
	fb_StrAssign( (void*)S$1, -1ll, (void*)FILE$1, -1ll, 0 );
	fb$result$1 = S$1;
	label$81:;
	return fb$result$1;
}

static FBSTRING* HGET1STOUTPUTLINEFROMCOMMAND( FBSTRING* CMD$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$82:;
	int32 F$1;
	int32 vr$1 = fb_FileFree(  );
	F$1 = vr$1;
	int32 vr$2 = fb_FileOpenPipe( (FBSTRING*)CMD$1, 2u, 0u, 0u, F$1, 0, (char*)0ull );
	if( (int64)vr$2 == 0ll) goto label$85;
	{
		goto label$83;
	}
	label$85:;
	label$84:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	fb_FileInput( F$1 );
	fb_InputString( (void*)&LN$1, -1ll, 0 );
	int32 vr$6 = fb_FileClose( F$1 );
	if( (int64)vr$6 == 0ll) goto label$86;
	void* vr$8 = fb_ErrorThrowAt( 310, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$8;
	label$86:;
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&LN$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	goto label$83;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$83:;
	FBSTRING* vr$14 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$14;
}

static FBSTRING* FBCQUERYCC( FBSTRING* OPTIONS$1 )
{
	FBSTRING TMP$78$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$87:;
	FBSTRING PATH$1;
	__builtin_memset( &PATH$1, 0, 24ll );
	{
		int64 TMP$74$2;
		int64 vr$2 = FBGETOPTION( 2ll );
		TMP$74$2 = vr$2;
		if( TMP$74$2 != 2ll) goto label$90;
		label$91:;
		{
			FBCFINDBIN( 6ll, &PATH$1 );
		}
		goto label$89;
		label$90:;
		{
			FBCFINDBIN( 4ll, &PATH$1 );
		}
		label$92:;
		label$89:;
	}
	{
		int64 TMP$75$2;
		int64 vr$5 = FBGETCPUFAMILY(  );
		TMP$75$2 = vr$5;
		if( TMP$75$2 != 0ll) goto label$94;
		label$95:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m32", 6ll, 0 );
		}
		goto label$93;
		label$94:;
		if( TMP$75$2 != 1ll) goto label$96;
		label$97:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m64", 6ll, 0 );
		}
		goto label$93;
		label$96:;
		if( TMP$75$2 != 4ll) goto label$98;
		label$99:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m32", 6ll, 0 );
		}
		goto label$93;
		label$98:;
		if( TMP$75$2 == 5ll) goto label$101;
		label$102:;
		if( TMP$75$2 != 6ll) goto label$100;
		label$101:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m64", 6ll, 0 );
		}
		label$100:;
		label$93:;
	}
	__builtin_memset( &TMP$78$1, 0, 24ll );
	FBSTRING* vr$13 = fb_StrConcat( &TMP$78$1, (void*)&PATH$1, -1ll, (void*)OPTIONS$1, -1ll );
	fb_StrAssign( (void*)&PATH$1, -1ll, (void*)vr$13, -1ll, 0 );
	int64 FF$1;
	int32 vr$15 = fb_FileFree(  );
	FF$1 = (int64)vr$15;
	int32 vr$19 = fb_FileOpenPipe( (FBSTRING*)&PATH$1, 2u, 0u, 0u, (int32)FF$1, 0, (char*)0ull );
	if( (int64)vr$19 == 0ll) goto label$104;
	{
		fb_StrDelete( (FBSTRING*)&PATH$1 );
		goto label$88;
	}
	label$104:;
	label$103:;
	FBSTRING RET$1;
	__builtin_memset( &RET$1, 0, 24ll );
	fb_FileInput( (int32)FF$1 );
	fb_InputString( (void*)&RET$1, -1ll, 0 );
	int32 vr$26 = fb_FileClose( (int32)FF$1 );
	if( (int64)vr$26 == 0ll) goto label$105;
	void* vr$28 = fb_ErrorThrowAt( 349, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$28;
	label$105:;
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&RET$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RET$1 );
	fb_StrDelete( (FBSTRING*)&PATH$1 );
	goto label$88;
	fb_StrDelete( (FBSTRING*)&RET$1 );
	fb_StrDelete( (FBSTRING*)&PATH$1 );
	label$88:;
	FBSTRING* vr$36 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$36;
}

static FBSTRING* FBCBUILDPATHTOLIBFILE( char* FILE$1 )
{
	FBSTRING TMP$79$1;
	FBSTRING TMP$80$1;
	FBSTRING TMP$85$1;
	FBSTRING TMP$86$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$106:;
	FBSTRING FOUND$1;
	__builtin_memset( &FOUND$1, 0, 24ll );
	__builtin_memset( &TMP$79$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$79$1, (void*)((uint8*)&FBC$ + 3559ll), 261ll, (void*)"\x5C", 2ll );
	__builtin_memset( &TMP$80$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$80$1, (void*)vr$5, -1ll, (void*)FILE$1, 0ll );
	fb_StrAssign( (void*)&FOUND$1, -1ll, (void*)vr$8, -1ll, 0 );
	int64 vr$10 = HFILEEXISTS( (char*)*(char**)&FOUND$1 );
	if( vr$10 == 0ll) goto label$109;
	{
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&FOUND$1, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&FOUND$1 );
		goto label$107;
	}
	label$109:;
	label$108:;
	FBSTRING PATH$1;
	__builtin_memset( &PATH$1, 0, 24ll );
	{
		int64 TMP$81$2;
		int64 vr$15 = FBGETOPTION( 2ll );
		TMP$81$2 = vr$15;
		if( TMP$81$2 != 2ll) goto label$111;
		label$112:;
		{
			FBCFINDBIN( 6ll, &PATH$1 );
		}
		goto label$110;
		label$111:;
		{
			FBCFINDBIN( 4ll, &PATH$1 );
		}
		label$113:;
		label$110:;
	}
	{
		int64 TMP$82$2;
		int64 vr$18 = FBGETCPUFAMILY(  );
		TMP$82$2 = vr$18;
		if( TMP$82$2 != 0ll) goto label$115;
		label$116:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m32", 6ll, 0 );
		}
		goto label$114;
		label$115:;
		if( TMP$82$2 != 1ll) goto label$117;
		label$118:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m64", 6ll, 0 );
		}
		goto label$114;
		label$117:;
		if( TMP$82$2 != 4ll) goto label$119;
		label$120:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m32", 6ll, 0 );
		}
		goto label$114;
		label$119:;
		if( TMP$82$2 == 5ll) goto label$122;
		label$123:;
		if( TMP$82$2 != 6ll) goto label$121;
		label$122:;
		{
			fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" -m64", 6ll, 0 );
		}
		label$121:;
		label$114:;
	}
	int64 vr$24 = fb_StrLen( (void*)((uint8*)&FBC$ + 2354ll), 261ll );
	if( vr$24 == 0ll) goto label$125;
	{
		fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" --sysroot=", 12ll, 0 );
		fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)((uint8*)&FBC$ + 2354ll), 261ll, 0 );
	}
	label$125:;
	label$124:;
	__builtin_memset( &TMP$85$1, 0, 24ll );
	FBSTRING* vr$30 = fb_StrConcat( &TMP$85$1, (void*)" -print-file-name=", 19ll, (void*)FILE$1, 0ll );
	__builtin_memset( &TMP$86$1, 0, 24ll );
	FBSTRING* vr$34 = fb_StrConcat( &TMP$86$1, (void*)&PATH$1, -1ll, (void*)vr$30, -1ll );
	fb_StrAssign( (void*)&PATH$1, -1ll, (void*)vr$34, -1ll, 0 );
	FBSTRING* vr$37 = HGET1STOUTPUTLINEFROMCOMMAND( &PATH$1 );
	fb_StrAssign( (void*)&FOUND$1, -1ll, (void*)vr$37, -1ll, 0 );
	int64 vr$40 = fb_StrLen( (void*)&FOUND$1, -1ll );
	if( vr$40 != 0ll) goto label$127;
	{
		fb_StrDelete( (FBSTRING*)&PATH$1 );
		fb_StrDelete( (FBSTRING*)&FOUND$1 );
		goto label$107;
	}
	label$127:;
	label$126:;
	FBSTRING* vr$43 = HSTRIPPATH( (char*)*(char**)&FOUND$1 );
	int32 vr$45 = fb_StrCompare( (void*)&FOUND$1, -1ll, (void*)vr$43, -1ll );
	if( (int64)vr$45 != 0ll) goto label$129;
	{
		fb_StrDelete( (FBSTRING*)&PATH$1 );
		fb_StrDelete( (FBSTRING*)&FOUND$1 );
		goto label$107;
	}
	label$129:;
	label$128:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&FOUND$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&PATH$1 );
	fb_StrDelete( (FBSTRING*)&FOUND$1 );
	label$107:;
	FBSTRING* vr$54 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$54;
}

static FBSTRING* FBCFINDSYSROOT( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$130:;
	FBSTRING PATH$1;
	__builtin_memset( &PATH$1, 0, 24ll );
	{
		int64 TMP$87$2;
		int64 vr$2 = FBGETOPTION( 2ll );
		TMP$87$2 = vr$2;
		if( TMP$87$2 != 2ll) goto label$133;
		label$134:;
		{
			FBCFINDBIN( 6ll, &PATH$1 );
		}
		goto label$132;
		label$133:;
		{
			FBCFINDBIN( 4ll, &PATH$1 );
		}
		label$135:;
		label$132:;
	}
	fb_StrConcatAssign( (void*)&PATH$1, -1ll, (void*)" --print-sysroot", 17ll, 0 );
	FBSTRING* vr$7 = HGET1STOUTPUTLINEFROMCOMMAND( &PATH$1 );
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)vr$7, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&PATH$1 );
	goto label$131;
	fb_StrDelete( (FBSTRING*)&PATH$1 );
	label$131:;
	FBSTRING* vr$12 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$12;
}

static FBSTRING* FBCFINDLIBFILE( char* FILE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$136:;
	FBSTRING FOUND$1;
	__builtin_memset( &FOUND$1, 0, 24ll );
	FBSTRING* vr$2 = FBCBUILDPATHTOLIBFILE( FILE$1 );
	fb_StrAssign( (void*)&FOUND$1, -1ll, (void*)vr$2, -1ll, 0 );
	int64 vr$5 = fb_StrLen( (void*)&FOUND$1, -1ll );
	if( vr$5 <= 0ll) goto label$139;
	{
		int64 vr$6 = HFILEEXISTS( (char*)*(char**)&FOUND$1 );
		if( vr$6 != 0ll) goto label$141;
		{
			fb_StrAssign( (void*)&FOUND$1, -1ll, (void*)"", 1ll, 0 );
		}
		label$141:;
		label$140:;
	}
	label$139:;
	label$138:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&FOUND$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&FOUND$1 );
	label$137:;
	FBSTRING* vr$12 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$12;
}

static void FBCADDDEFLIBPATH( FBSTRING* PATH$1 )
{
	label$142:;
	STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 880ll), PATH$1, -1ll );
	label$143:;
}

static void FBCADDLIBPATHFOR( char* LIBNAME$1 )
{
	FBSTRING TMP$89$1;
	label$144:;
	FBSTRING PATH$1;
	__builtin_memset( &PATH$1, 0, 24ll );
	__builtin_memset( &TMP$89$1, 0, 24ll );
	FBSTRING* vr$2 = FBCBUILDPATHTOLIBFILE( LIBNAME$1 );
	fb_StrAssign( (void*)&TMP$89$1, -1ll, (void*)vr$2, -1ll, 0 );
	FBSTRING* vr$4 = HSTRIPFILENAME( (char*)*(char**)&TMP$89$1 );
	fb_StrAssign( (void*)&PATH$1, -1ll, (void*)vr$4, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&TMP$89$1 );
	FBSTRING* vr$8 = PATHSTRIPDIV( &PATH$1 );
	fb_StrAssign( (void*)&PATH$1, -1ll, (void*)vr$8, -1ll, 0 );
	int64 vr$11 = fb_StrLen( (void*)&PATH$1, -1ll );
	if( vr$11 <= 0ll) goto label$147;
	{
		FBCADDDEFLIBPATH( &PATH$1 );
	}
	label$147:;
	label$146:;
	fb_StrDelete( (FBSTRING*)&PATH$1 );
	label$145:;
}

static void FBCFINDBIN( int64 TOOL$1, FBSTRING* PATH$1 )
{
	label$148:;
	if( (*(int64*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) & 4ll) == 0ll) goto label$151;
	{
		fb_StrAssign( (void*)PATH$1, -1ll, (void*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 40ll), 261ll, 0 );
		goto label$149;
	}
	label$151:;
	label$150:;
	*($11FBCTOOLFLAG*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) = *(int64*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) & -9ll;
	if( (*(int64*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) & 2ll) == 0ll) goto label$153;
	{
		FBSTRING* vr$11 = fb_StrAllocTempDescZ( (char*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 16ll) );
		FBSTRING* vr$12 = fb_GetEnviron( (FBSTRING*)vr$11 );
		fb_StrAssign( (void*)PATH$1, -1ll, (void*)vr$12, -1ll, 0 );
	}
	label$153:;
	label$152:;
	int64 vr$13 = fb_StrLen( (void*)PATH$1, -1ll );
	if( vr$13 != 0ll) goto label$155;
	{
		FBSTRING TMP$90$2;
		FBSTRING TMP$91$2;
		__builtin_memset( &TMP$90$2, 0, 24ll );
		FBSTRING* vr$19 = fb_StrConcat( &TMP$90$2, (void*)((uint8*)&FBC$ + 3037ll), 261ll, (void*)((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)), 16ll );
		__builtin_memset( &TMP$91$2, 0, 24ll );
		FBSTRING* vr$22 = fb_StrConcat( &TMP$91$2, (void*)vr$19, -1ll, (void*)".exe", 5ll );
		fb_StrAssign( (void*)PATH$1, -1ll, (void*)vr$22, -1ll, 0 );
		int64 vr$24 = HFILEEXISTS( (char*)*(char**)PATH$1 );
		if( vr$24 != 0ll) goto label$157;
		{
			{
				int64 TMP$92$4;
				int64 vr$25 = FBGETOPTION( 2ll );
				TMP$92$4 = vr$25;
				if( TMP$92$4 == 1ll) goto label$160;
				label$161:;
				if( TMP$92$4 != 2ll) goto label$159;
				label$160:;
				{
					if( TOOL$1 != 1ll) goto label$163;
					{
						FBSTRING TMP$94$6;
						__builtin_memset( &TMP$94$6, 0, 24ll );
						fb_StrAssign( (void*)&TMP$94$6, -1ll, (void*)" -print-prog-name=as", 21ll, 0 );
						FBSTRING* vr$29 = FBCQUERYCC( &TMP$94$6 );
						fb_StrAssign( (void*)PATH$1, -1ll, (void*)vr$29, -1ll, 0 );
						fb_StrDelete( (FBSTRING*)&TMP$94$6 );
					}
					goto label$162;
					label$163:;
					if( TOOL$1 != 3ll) goto label$164;
					{
						FBSTRING TMP$96$6;
						__builtin_memset( &TMP$96$6, 0, 24ll );
						fb_StrAssign( (void*)&TMP$96$6, -1ll, (void*)" -print-prog-name=ld", 21ll, 0 );
						FBSTRING* vr$34 = FBCQUERYCC( &TMP$96$6 );
						fb_StrAssign( (void*)PATH$1, -1ll, (void*)vr$34, -1ll, 0 );
						fb_StrDelete( (FBSTRING*)&TMP$96$6 );
					}
					label$164:;
					label$162:;
				}
				goto label$158;
				label$159:;
				if( TMP$92$4 == 0ll) goto label$166;
				label$167:;
				if( TMP$92$4 != 4ll) goto label$165;
				label$166:;
				{
				}
				label$165:;
				label$158:;
			}
		}
		label$157:;
		label$156:;
		int64 vr$37 = HFILEEXISTS( (char*)*(char**)PATH$1 );
		if( vr$37 != 0ll) goto label$169;
		{
			int64 vr$38 = FBGETOPTION( 3ll );
			if( vr$38 == 12ll) goto label$171;
			{
				int64 vr$40 = fb_StrLen( (void*)((uint8*)&FBC$ + 3820ll), 261ll );
				if( vr$40 <= 0ll) goto label$173;
				{
					FBSTRING TMP$97$5;
					FBSTRING TMP$98$5;
					__builtin_memset( &TMP$97$5, 0, 24ll );
					FBSTRING* vr$46 = fb_StrConcat( &TMP$97$5, (void*)((uint8*)&FBC$ + 3820ll), 261ll, (void*)((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)), 16ll );
					__builtin_memset( &TMP$98$5, 0, 24ll );
					FBSTRING* vr$49 = fb_StrConcat( &TMP$98$5, (void*)vr$46, -1ll, (void*)".exe", 5ll );
					fb_StrAssign( (void*)PATH$1, -1ll, (void*)vr$49, -1ll, 0 );
				}
				goto label$172;
				label$173:;
				{
					FBSTRING TMP$99$5;
					FBSTRING TMP$100$5;
					__builtin_memset( &TMP$99$5, 0, 24ll );
					FBSTRING* vr$55 = fb_StrConcat( &TMP$99$5, (void*)((uint8*)&FBC$ + 2225ll), 129ll, (void*)((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)), 16ll );
					__builtin_memset( &TMP$100$5, 0, 24ll );
					FBSTRING* vr$58 = fb_StrConcat( &TMP$100$5, (void*)vr$55, -1ll, (void*)".exe", 5ll );
					fb_StrAssign( (void*)PATH$1, -1ll, (void*)vr$58, -1ll, 0 );
				}
				label$172:;
			}
			goto label$170;
			label$171:;
			{
				fb_StrAssign( (void*)PATH$1, -1ll, (void*)((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)), 16ll, 0 );
			}
			label$170:;
			*($11FBCTOOLFLAG*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) = *(int64*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) | 8ll;
		}
		label$169:;
		label$168:;
	}
	label$155:;
	label$154:;
	fb_StrAssign( (void*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 40ll), 261ll, (void*)PATH$1, -1ll, 0 );
	*($11FBCTOOLFLAG*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) = *(int64*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) | 4ll;
	label$149:;
}

static int64 FBCRUNBIN( char* ACTION$1, int64 TOOL$1, FBSTRING* LN$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$174:;
	int64 RESULT$1;
	FBSTRING PATH$1;
	__builtin_memset( &PATH$1, 0, 24ll );
	FBCFINDBIN( TOOL$1, &PATH$1 );
	if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$177;
	{
		FBSTRING TMP$102$2;
		FBSTRING TMP$104$2;
		FBSTRING TMP$105$2;
		__builtin_memset( &TMP$102$2, 0, 24ll );
		FBSTRING* vr$5 = fb_StrConcat( &TMP$102$2, (void*)ACTION$1, 0ll, (void*)": ", 3ll );
		fb_PrintString( 0, (FBSTRING*)vr$5, 2 );
		__builtin_memset( &TMP$104$2, 0, 24ll );
		FBSTRING* vr$9 = fb_StrConcat( &TMP$104$2, (void*)&PATH$1, -1ll, (void*)" ", 2ll );
		__builtin_memset( &TMP$105$2, 0, 24ll );
		FBSTRING* vr$12 = fb_StrConcat( &TMP$105$2, (void*)vr$9, -1ll, (void*)LN$1, -1ll );
		fb_PrintString( 0, (FBSTRING*)vr$12, 1 );
	}
	label$177:;
	label$176:;
	if( (*(int64*)(((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (TOOL$1 * 304ll)) + 32ll) & 8ll) != 0ll) goto label$179;
	{
		int32 vr$16 = fb_Exec( (FBSTRING*)&PATH$1, (FBSTRING*)LN$1 );
		RESULT$1 = (int64)vr$16;
	}
	goto label$178;
	label$179:;
	{
		FBSTRING TMP$106$2;
		FBSTRING TMP$107$2;
		__builtin_memset( &TMP$106$2, 0, 24ll );
		FBSTRING* vr$21 = fb_StrConcat( &TMP$106$2, (void*)&PATH$1, -1ll, (void*)" ", 2ll );
		__builtin_memset( &TMP$107$2, 0, 24ll );
		FBSTRING* vr$24 = fb_StrConcat( &TMP$107$2, (void*)vr$21, -1ll, (void*)LN$1, -1ll );
		int32 vr$25 = fb_Shell( (FBSTRING*)vr$24 );
		RESULT$1 = (int64)vr$25;
	}
	label$178:;
	if( RESULT$1 != 0ll) goto label$181;
	{
		fb$result$1 = -1ll;
	}
	goto label$180;
	label$181:;
	if( RESULT$1 >= 0ll) goto label$182;
	{
		ERRREPORTEX( 91ll, (char*)*(char**)&PATH$1, -1ll, 6ll, (char*)0ull );
	}
	goto label$180;
	label$182:;
	{
		if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$184;
		{
			FBSTRING TMP$110$3;
			FBSTRING TMP$111$3;
			FBSTRING TMP$112$3;
			FBSTRING TMP$113$3;
			FBSTRING* vr$27 = fb_LongintToStr( RESULT$1 );
			__builtin_memset( &TMP$110$3, 0, 24ll );
			FBSTRING* vr$31 = fb_StrConcat( &TMP$110$3, (void*)ACTION$1, 0ll, (void*)" failed: '", 11ll );
			__builtin_memset( &TMP$111$3, 0, 24ll );
			FBSTRING* vr$34 = fb_StrConcat( &TMP$111$3, (void*)vr$31, -1ll, (void*)&PATH$1, -1ll );
			__builtin_memset( &TMP$112$3, 0, 24ll );
			FBSTRING* vr$37 = fb_StrConcat( &TMP$112$3, (void*)vr$34, -1ll, (void*)"' terminated with exit code ", 29ll );
			__builtin_memset( &TMP$113$3, 0, 24ll );
			FBSTRING* vr$40 = fb_StrConcat( &TMP$113$3, (void*)vr$37, -1ll, (void*)vr$27, -1ll );
			fb_PrintString( 0, (FBSTRING*)vr$40, 1 );
		}
		label$184:;
		label$183:;
	}
	label$180:;
	fb_StrDelete( (FBSTRING*)&PATH$1 );
	label$175:;
	return fb$result$1;
}

static int64 HPUTLDARGSINTOFILE( FBSTRING* LDCLINE$1 )
{
	int64 TMP$117$1;
	FBSTRING TMP$123$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$185:;
	FBSTRING ARGSFILE$1;
	__builtin_memset( &ARGSFILE$1, 0, 24ll );
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	int64 F$1;
	FBSTRING* vr$4 = HSTRIPFILENAME( (char*)((uint8*)&FBC$ + 968ll) );
	fb_StrAssign( (void*)&ARGSFILE$1, -1ll, (void*)vr$4, -1ll, 0 );
	fb_StrConcatAssign( (void*)&ARGSFILE$1, -1ll, (void*)"ldopt.tmp", 10ll, 0 );
	int32 vr$7 = fb_FileFree(  );
	F$1 = (int64)vr$7;
	int32 vr$11 = fb_FileOpen( (FBSTRING*)&ARGSFILE$1, 3u, 0u, 0u, (int32)F$1, 0 );
	if( (int64)vr$11 == 0ll) goto label$188;
	{
		fb_StrDelete( (FBSTRING*)&LN$1 );
		fb_StrDelete( (FBSTRING*)&ARGSFILE$1 );
		goto label$186;
	}
	label$188:;
	label$187:;
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)LDCLINE$1, -1ll, 0 );
	FBSTRING* vr$16 = HREPLACE( (char*)*(char**)&LN$1, (char*)"\x5C", (char*)"\x5C\x5C" );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$16, -1ll, 0 );
	TMP$117$1 = F$1;
	fb_PrintString( (int32)TMP$117$1, (FBSTRING*)&LN$1, 1 );
	int32 vr$21 = fb_FileClose( (int32)F$1 );
	if( (int64)vr$21 == 0ll) goto label$189;
	void* vr$23 = fb_ErrorThrowAt( 636, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$23;
	label$189:;
	if( *(int64*)((uint8*)&FBC$ + 80ll) != 0ll) goto label$191;
	{
		FBCADDTEMP( &ARGSFILE$1 );
	}
	label$191:;
	label$190:;
	if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$193;
	{
		FBSTRING TMP$120$2;
		FBSTRING TMP$121$2;
		__builtin_memset( &TMP$120$2, 0, 24ll );
		FBSTRING* vr$28 = fb_StrConcat( &TMP$120$2, (void*)"ld options in '", 16ll, (void*)&ARGSFILE$1, -1ll );
		__builtin_memset( &TMP$121$2, 0, 24ll );
		FBSTRING* vr$31 = fb_StrConcat( &TMP$121$2, (void*)vr$28, -1ll, (void*)"': ", 4ll );
		fb_PrintString( 0, (FBSTRING*)vr$31, 2 );
		fb_PrintString( 0, (FBSTRING*)LDCLINE$1, 1 );
	}
	label$193:;
	label$192:;
	__builtin_memset( &TMP$123$1, 0, 24ll );
	FBSTRING* vr$35 = fb_StrConcat( &TMP$123$1, (void*)"@", 2ll, (void*)&ARGSFILE$1, -1ll );
	fb_StrAssign( (void*)LDCLINE$1, -1ll, (void*)vr$35, -1ll, 0 );
	fb$result$1 = -1ll;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	fb_StrDelete( (FBSTRING*)&ARGSFILE$1 );
	label$186:;
	return fb$result$1;
}

static int64 CLEARDEFLIST( FBSTRING* DEFFILE$1 )
{
	FBSTRING TMP$125$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$194:;
	int64 FI$1;
	int32 vr$1 = fb_FileFree(  );
	FI$1 = (int64)vr$1;
	int32 vr$4 = fb_FileOpen( (FBSTRING*)DEFFILE$1, 2u, 0u, 0u, (int32)FI$1, 0 );
	if( (int64)vr$4 == 0ll) goto label$197;
	{
		fb$result$1 = 0ll;
		goto label$195;
	}
	label$197:;
	label$196:;
	FBSTRING CLEANED$1;
	FBSTRING* vr$6 = HSTRIPEXT( DEFFILE$1 );
	__builtin_memset( &TMP$125$1, 0, 24ll );
	FBSTRING* vr$9 = fb_StrConcat( &TMP$125$1, (void*)vr$6, -1ll, (void*)".clean.def", 11ll );
	fb_StrInit( (void*)&CLEANED$1, -1ll, (void*)vr$9, -1ll, 0 );
	int64 FO$1;
	int32 vr$11 = fb_FileFree(  );
	FO$1 = (int64)vr$11;
	int32 vr$15 = fb_FileOpen( (FBSTRING*)&CLEANED$1, 3u, 0u, 0u, (int32)FO$1, 0 );
	if( (int64)vr$15 == 0ll) goto label$199;
	{
		int32 vr$18 = fb_FileClose( (int32)FI$1 );
		if( (int64)vr$18 == 0ll) goto label$200;
		void* vr$20 = fb_ErrorThrowAt( 661, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
		goto *vr$20;
		label$200:;
		fb$result$1 = 0ll;
		fb_StrDelete( (FBSTRING*)&CLEANED$1 );
		goto label$195;
	}
	label$199:;
	label$198:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	label$201:;
	int32 vr$24 = fb_FileEof( (int32)FI$1 );
	if( (int64)vr$24 != 0ll) goto label$202;
	{
		int64 TMP$127$2;
		fb_FileLineInput( (int32)FI$1, (void*)&LN$1, -1ll, 0 );
		FBSTRING* vr$29 = fb_RIGHT( (FBSTRING*)&LN$1, 4ll );
		int32 vr$30 = fb_StrCompare( (void*)vr$29, -1ll, (void*)"DATA", 5ll );
		if( (int64)vr$30 != 0ll) goto label$204;
		{
			int64 vr$33 = fb_StrLen( (void*)&LN$1, -1ll );
			FBSTRING* vr$36 = fb_LEFT( (FBSTRING*)&LN$1, vr$33 + -4ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$36, -1ll, 0 );
		}
		label$204:;
		label$203:;
		TMP$127$2 = FO$1;
		fb_PrintString( (int32)TMP$127$2, (FBSTRING*)&LN$1, 1 );
	}
	goto label$201;
	label$202:;
	int32 vr$41 = fb_FileClose( (int32)FO$1 );
	if( (int64)vr$41 == 0ll) goto label$205;
	void* vr$43 = fb_ErrorThrowAt( 676, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$43;
	label$205:;
	int32 vr$45 = fb_FileClose( (int32)FI$1 );
	if( (int64)vr$45 == 0ll) goto label$206;
	void* vr$47 = fb_ErrorThrowAt( 677, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$47;
	label$206:;
	fb_FileKill( (FBSTRING*)DEFFILE$1 );
	int32 vr$49 = rename( (char*)*(char**)&CLEANED$1, (char*)*(char**)DEFFILE$1 );
	fb$result$1 = (int64)-((int64)vr$49 == 0ll);
	fb_StrDelete( (FBSTRING*)&LN$1 );
	fb_StrDelete( (FBSTRING*)&CLEANED$1 );
	goto label$195;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	fb_StrDelete( (FBSTRING*)&CLEANED$1 );
	label$195:;
	return fb$result$1;
}

static int64 HGENERATEEMPTYDEFFILE( FBSTRING* DEFFILE$1 )
{
	int32 TMP$128$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$207:;
	int32 F$1;
	int32 vr$1 = fb_FileFree(  );
	F$1 = vr$1;
	int32 vr$2 = fb_FileOpen( (FBSTRING*)DEFFILE$1, 3u, 0u, 0u, F$1, 0 );
	if( (int64)vr$2 == 0ll) goto label$210;
	{
		goto label$208;
	}
	label$210:;
	label$209:;
	TMP$128$1 = F$1;
	FBSTRING* vr$4 = fb_StrAllocTempDescZEx( (char*)"EXPORTS", 7ll );
	fb_PrintString( TMP$128$1, (FBSTRING*)vr$4, 1 );
	int32 vr$5 = fb_FileClose( F$1 );
	if( (int64)vr$5 == 0ll) goto label$211;
	void* vr$7 = fb_ErrorThrowAt( 691, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$7;
	label$211:;
	fb$result$1 = -1ll;
	label$208:;
	return fb$result$1;
}

static int64 MAKEIMPLIB( FBSTRING* DLLNAME$1, FBSTRING* DEFFILE$1 )
{
	FBSTRING TMP$132$1;
	FBSTRING TMP$133$1;
	FBSTRING TMP$134$1;
	FBSTRING TMP$138$1;
	FBSTRING TMP$139$1;
	FBSTRING TMP$140$1;
	FBSTRING TMP$141$1;
	FBSTRING TMP$142$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$212:;
	int64 vr$1 = CLEARDEFLIST( DEFFILE$1 );
	if( vr$1 != 0ll) goto label$215;
	{
		goto label$213;
	}
	label$215:;
	label$214:;
	int64 vr$3 = fb_FileLen( (char*)*(char**)DEFFILE$1 );
	if( vr$3 != 0ll) goto label$217;
	{
		int64 vr$4 = HGENERATEEMPTYDEFFILE( DEFFILE$1 );
		if( vr$4 != 0ll) goto label$219;
		{
			goto label$213;
		}
		label$219:;
		label$218:;
	}
	label$217:;
	label$216:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	__builtin_memset( &TMP$132$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$132$1, (void*)"--def \x22", 8ll, (void*)DEFFILE$1, -1ll );
	__builtin_memset( &TMP$133$1, 0, 24ll );
	FBSTRING* vr$11 = fb_StrConcat( &TMP$133$1, (void*)vr$8, -1ll, (void*)"\x22", 2ll );
	__builtin_memset( &TMP$134$1, 0, 24ll );
	FBSTRING* vr$15 = fb_StrConcat( &TMP$134$1, (void*)&LN$1, -1ll, (void*)vr$11, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$15, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" --dllname \x22", 13ll, 0 );
	FBSTRING* vr$19 = HSTRIPPATH( (char*)((uint8*)&FBC$ + 968ll) );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$19, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	FBSTRING* vr$23 = HSTRIPFILENAME( (char*)((uint8*)&FBC$ + 968ll) );
	__builtin_memset( &TMP$138$1, 0, 24ll );
	FBSTRING* vr$26 = fb_StrConcat( &TMP$138$1, (void*)" --output-lib \x22", 16ll, (void*)vr$23, -1ll );
	__builtin_memset( &TMP$139$1, 0, 24ll );
	FBSTRING* vr$29 = fb_StrConcat( &TMP$139$1, (void*)vr$26, -1ll, (void*)"lib", 4ll );
	__builtin_memset( &TMP$140$1, 0, 24ll );
	FBSTRING* vr$32 = fb_StrConcat( &TMP$140$1, (void*)vr$29, -1ll, (void*)DLLNAME$1, -1ll );
	__builtin_memset( &TMP$141$1, 0, 24ll );
	FBSTRING* vr$35 = fb_StrConcat( &TMP$141$1, (void*)vr$32, -1ll, (void*)".dll.a\x22", 8ll );
	__builtin_memset( &TMP$142$1, 0, 24ll );
	FBSTRING* vr$39 = fb_StrConcat( &TMP$142$1, (void*)&LN$1, -1ll, (void*)vr$35, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$39, -1ll, 0 );
	int64 vr$42 = FBCRUNBIN( (char*)"creating import library", 7ll, &LN$1 );
	if( vr$42 != 0ll) goto label$221;
	{
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$213;
	}
	label$221:;
	label$220:;
	if( *(int64*)((uint8*)&FBC$ + 80ll) != 0ll) goto label$223;
	{
		FBCADDTEMP( DEFFILE$1 );
	}
	label$223:;
	label$222:;
	fb$result$1 = -1ll;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$213:;
	return fb$result$1;
}

static FBSTRING* HFINDLIB( char* FILE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$224:;
	FBSTRING FOUND$1;
	FBSTRING* vr$1 = FBCBUILDPATHTOLIBFILE( FILE$1 );
	fb_StrInit( (void*)&FOUND$1, -1ll, (void*)vr$1, -1ll, 0 );
	int64 vr$4 = fb_StrLen( (void*)&FOUND$1, -1ll );
	if( vr$4 <= 0ll) goto label$227;
	{
		fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)" \x22", 3ll, 0 );
		fb_StrConcatAssign( (void*)&fb$result$1, -1ll, (void*)&FOUND$1, -1ll, 0 );
		fb_StrConcatAssign( (void*)&fb$result$1, -1ll, (void*)"\x22", 2ll, 0 );
	}
	goto label$226;
	label$227:;
	{
		ERRREPORTEX( 23ll, (char*)FILE$1, -1ll, 1ll, (char*)0ull );
	}
	label$226:;
	fb_StrDelete( (FBSTRING*)&FOUND$1 );
	label$225:;
	FBSTRING* vr$11 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$11;
}

static int64 FBCLINKERISGOLD( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$228:;
	int64 vr$1 = FBGETOPTION( 3ll );
	if( vr$1 != 8ll) goto label$231;
	{
		fb$result$1 = 0ll;
		goto label$229;
	}
	goto label$230;
	label$231:;
	{
		FBSTRING LDCMD$2;
		__builtin_memset( &LDCMD$2, 0, 24ll );
		FBCFINDBIN( 3ll, &LDCMD$2 );
		fb_StrConcatAssign( (void*)&LDCMD$2, -1ll, (void*)" --version", 11ll, 0 );
		FBSTRING* vr$5 = fb_StrAllocTempDescZEx( (char*)"GNU gold", 8ll );
		FBSTRING* vr$7 = HGET1STOUTPUTLINEFROMCOMMAND( &LDCMD$2 );
		int64 vr$8 = fb_StrInstr( 1ll, (FBSTRING*)vr$7, (FBSTRING*)vr$5 );
		fb$result$1 = (int64)-(vr$8 > 0ll);
		fb_StrDelete( (FBSTRING*)&LDCMD$2 );
		goto label$229;
		fb_StrDelete( (FBSTRING*)&LDCMD$2 );
	}
	label$230:;
	label$229:;
	return fb$result$1;
}

static int64 FBCISUSINGGOLDLINKER( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$232:;
	int64 vr$1 = FBTARGETSUPPORTSELF(  );
	if( vr$1 == 0ll) goto label$235;
	{
		int64 vr$2 = FBCLINKERISGOLD(  );
		fb$result$1 = vr$2;
		goto label$233;
	}
	label$235:;
	label$234:;
	fb$result$1 = 0ll;
	goto label$233;
	label$233:;
	return fb$result$1;
}

static int64 HLINKFILES( void )
{
	int64 TMP$291$1;
	int64 TMP$292$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$236:;
	FBSTRING LDCLINE$1;
	__builtin_memset( &LDCLINE$1, 0, 24ll );
	FBSTRING DLLNAME$1;
	__builtin_memset( &DLLNAME$1, 0, 24ll );
	FBSTRING DEFFILE$1;
	__builtin_memset( &DEFFILE$1, 0, 24ll );
	int64 COFF_LINKER$1;
	int64 vr$4 = FBGETOPTION( 3ll );
	int64 vr$6 = FBGETCPUFAMILY(  );
	COFF_LINKER$1 = (int64)-(vr$4 == 0ll) & (int64)-(vr$6 == 3ll);
	fb$result$1 = 0ll;
	HSETOUTNAME(  );
	{
		int64 TMP$147$2;
		int64 vr$9 = FBGETOPTION( 3ll );
		TMP$147$2 = vr$9;
		if( TMP$147$2 != 0ll) goto label$239;
		label$240:;
		{
			{
				int64 TMP$148$4;
				int64 vr$10 = FBGETCPUFAMILY(  );
				TMP$148$4 = vr$10;
				if( TMP$148$4 != 0ll) goto label$242;
				label$243:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-m i386pe ", 11ll, 0 );
				}
				goto label$241;
				label$242:;
				if( TMP$148$4 != 1ll) goto label$244;
				label$245:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-m i386pep ", 12ll, 0 );
				}
				label$244:;
				label$241:;
			}
		}
		goto label$238;
		label$239:;
		if( TMP$147$2 != 2ll) goto label$246;
		label$247:;
		{
			{
				int64 TMP$151$4;
				int64 vr$13 = FBGETCPUFAMILY(  );
				TMP$151$4 = vr$13;
				if( TMP$151$4 != 0ll) goto label$249;
				label$250:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-m elf_i386 ", 13ll, 0 );
				}
				goto label$248;
				label$249:;
				if( TMP$151$4 != 1ll) goto label$251;
				label$252:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-m elf_x86_64 ", 15ll, 0 );
				}
				goto label$248;
				label$251:;
				if( TMP$151$4 != 2ll) goto label$253;
				label$254:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-m armelf_linux_eabi ", 22ll, 0 );
				}
				label$253:;
				label$248:;
			}
		}
		goto label$238;
		label$246:;
		if( TMP$147$2 != 3ll) goto label$255;
		label$256:;
		{
			int64 vr$18 = fb_StrLen( (void*)((uint8*)&FBC$ + 2354ll), 261ll );
			int64 vr$20 = FBGETOPTION( 2ll );
			if( ((int64)-(vr$18 == 0ll) & (int64)-(vr$20 == 1ll)) == 0ll) goto label$258;
			{
				FBSTRING* vr$23 = FBCFINDSYSROOT(  );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 2354ll), 261ll, (void*)vr$23, -1ll, 0 );
				FBSTRING* vr$26 = fb_StrAllocTempDescZ( (char*)((uint8*)&FBC$ + 2354ll) );
				FBSTRING* vr$27 = fb_LEFT( (FBSTRING*)vr$26, 5ll );
				int32 vr$28 = fb_StrCompare( (void*)vr$27, -1ll, (void*)"/tmp/", 6ll );
				if( (int64)vr$28 != 0ll) goto label$260;
				{
					ERRREPORTWARNEX( 51ll, (char*)0ull, 0ll, 1ll, (char*)0ull );
				}
				label$260:;
				label$259:;
			}
			label$258:;
			label$257:;
			FBSTRING ARGS$3;
			fb_StrInit( (void*)&ARGS$3, -1ll, (void*)"", 1ll, 0 );
			int64 vr$32 = fb_StrLen( (void*)((uint8*)&FBC$ + 2096ll), 129ll );
			if( vr$32 <= 0ll) goto label$262;
			{
				fb_StrAssign( (void*)&ARGS$3, -1ll, (void*)" -target ", 10ll, 0 );
				fb_StrConcatAssign( (void*)&ARGS$3, -1ll, (void*)((uint8*)&FBC$ + 2096ll), 129ll, 0 );
			}
			label$262:;
			label$261:;
			fb_StrConcatAssign( (void*)&ARGS$3, -1ll, (void*)" -print-libgcc-file-name", 25ll, 0 );
			FBSTRING PATH$3;
			FBSTRING* vr$38 = FBCQUERYCC( &ARGS$3 );
			fb_StrInit( (void*)&PATH$3, -1ll, (void*)vr$38, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)&PATH$3, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" ", 2ll, 0 );
			int64 vr$43 = FBGETOPTION( 4ll );
			if( vr$43 != 17ll) goto label$264;
			{
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"--fix-cortex-a8 ", 17ll, 0 );
			}
			label$264:;
			label$263:;
			fb_StrDelete( (FBSTRING*)&PATH$3 );
			fb_StrDelete( (FBSTRING*)&ARGS$3 );
		}
		goto label$238;
		label$255:;
		if( TMP$147$2 != 10ll) goto label$265;
		label$266:;
		{
			{
				int64 TMP$159$4;
				int64 vr$47 = FBGETCPUFAMILY(  );
				TMP$159$4 = vr$47;
				if( TMP$159$4 != 0ll) goto label$268;
				label$269:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-arch i386 ", 12ll, 0 );
				}
				goto label$267;
				label$268:;
				if( TMP$159$4 != 1ll) goto label$270;
				label$271:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-arch x86_64 ", 14ll, 0 );
				}
				goto label$267;
				label$270:;
				if( TMP$159$4 != 3ll) goto label$272;
				label$273:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-arch arm64 ", 13ll, 0 );
				}
				goto label$267;
				label$272:;
				if( TMP$159$4 != 2ll) goto label$274;
				label$275:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-arch armv6 ", 13ll, 0 );
				}
				label$274:;
				label$267:;
			}
		}
		goto label$238;
		label$265:;
		if( TMP$147$2 == 13ll) goto label$277;
		label$278:;
		if( TMP$147$2 == 14ll) goto label$277;
		label$279:;
		if( TMP$147$2 == 15ll) goto label$277;
		label$280:;
		if( TMP$147$2 != 16ll) goto label$276;
		label$277:;
		{
		}
		label$276:;
		label$238:;
	}
	fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"-o \x22", 5ll, 0 );
	fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
	fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"\x22", 2ll, 0 );
	int64 vr$56 = FBGETOPTION( 3ll );
	int64 vr$58 = FBGETOPTION( 0ll );
	if( ((int64)-(vr$56 == 4ll) & (int64)-(vr$58 == 2ll)) == 0ll) goto label$282;
	{
		FBSTRING TMP$168$2;
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -I \x22lib", 9ll, 0 );
		__builtin_memset( &TMP$168$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$168$2, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
		FBSTRING* vr$66 = HSTRIPEXT( &TMP$168$2 );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)&TMP$168$2, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$66, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"_il.a\x22", 7ll, 0 );
		fb_StrDelete( (FBSTRING*)&TMP$168$2 );
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -U", 4ll, 0 );
		{
			FBSTRING* OBJFILE$3;
			void* vr$74 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 400ll) );
			OBJFILE$3 = (FBSTRING*)vr$74;
			label$283:;
			if( OBJFILE$3 == (FBSTRING*)0ull) goto label$284;
			{
				FBSTRING TMP$171$4;
				FBSTRING TMP$172$4;
				FBSTRING TMP$173$4;
				__builtin_memset( &TMP$171$4, 0, 24ll );
				FBSTRING* vr$77 = fb_StrConcat( &TMP$171$4, (void*)" \x22", 3ll, (void*)OBJFILE$3, -1ll );
				__builtin_memset( &TMP$172$4, 0, 24ll );
				FBSTRING* vr$80 = fb_StrConcat( &TMP$172$4, (void*)vr$77, -1ll, (void*)"\x22", 2ll );
				__builtin_memset( &TMP$173$4, 0, 24ll );
				FBSTRING* vr$84 = fb_StrConcat( &TMP$173$4, (void*)&LDCLINE$1, -1ll, (void*)vr$80, -1ll );
				fb_StrAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$84, -1ll, 0 );
				void* vr$86 = LISTGETNEXT( (void*)OBJFILE$3 );
				OBJFILE$3 = (FBSTRING*)vr$86;
			}
			goto label$283;
			label$284:;
		}
		{
			FBSTRING* LIBFILE$3;
			void* vr$88 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 464ll) );
			LIBFILE$3 = (FBSTRING*)vr$88;
			if( LIBFILE$3 == (FBSTRING*)0ull) goto label$286;
			{
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -lc", 5ll, 0 );
			}
			label$286:;
			label$285:;
			label$287:;
			if( LIBFILE$3 == (FBSTRING*)0ull) goto label$288;
			{
				FBSTRING TMP$175$4;
				FBSTRING TMP$176$4;
				FBSTRING TMP$177$4;
				__builtin_memset( &TMP$175$4, 0, 24ll );
				FBSTRING* vr$92 = fb_StrConcat( &TMP$175$4, (void*)" \x22", 3ll, (void*)LIBFILE$3, -1ll );
				__builtin_memset( &TMP$176$4, 0, 24ll );
				FBSTRING* vr$95 = fb_StrConcat( &TMP$176$4, (void*)vr$92, -1ll, (void*)"\x22", 2ll );
				__builtin_memset( &TMP$177$4, 0, 24ll );
				FBSTRING* vr$99 = fb_StrConcat( &TMP$177$4, (void*)&LDCLINE$1, -1ll, (void*)vr$95, -1ll );
				fb_StrAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$99, -1ll, 0 );
				void* vr$101 = LISTGETNEXT( (void*)LIBFILE$3 );
				LIBFILE$3 = (FBSTRING*)vr$101;
			}
			goto label$287;
			label$288:;
		}
		int64 vr$103 = FBCRUNBIN( (char*)"making DXE", 11ll, &LDCLINE$1 );
		fb$result$1 = vr$103;
		fb_StrDelete( (FBSTRING*)&DEFFILE$1 );
		fb_StrDelete( (FBSTRING*)&DLLNAME$1 );
		fb_StrDelete( (FBSTRING*)&LDCLINE$1 );
		goto label$237;
	}
	label$282:;
	label$281:;
	{
		uint64 TMP$179$2;
		int64 vr$107 = FBGETOPTION( 3ll );
		TMP$179$2 = (uint64)vr$107;
		goto label$290;
		label$291:;
		{
			int64 vr$109 = fb_StrLen( (void*)((uint8*)&FBC$ + 1893ll), 129ll );
			if( vr$109 != 0ll) goto label$293;
			{
				fb_StrAssign( (void*)((uint8*)&FBC$ + 1893ll), 129ll, (void*)"console", 8ll, 0 );
			}
			goto label$292;
			label$293:;
			{
				int32 vr$112 = fb_StrCompare( (void*)((uint8*)&FBC$ + 1893ll), 129ll, (void*)"gui", 4ll );
				if( (int64)vr$112 != 0ll) goto label$295;
				{
					fb_StrAssign( (void*)((uint8*)&FBC$ + 1893ll), 129ll, (void*)"windows", 8ll, 0 );
				}
				label$295:;
				label$294:;
			}
			label$292:;
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -subsystem ", 13ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 1893ll), 129ll, 0 );
			int64 vr$118 = FBGETOPTION( 0ll );
			if( vr$118 != 2ll) goto label$297;
			{
				FBSTRING TMP$184$4;
				FBSTRING TMP$185$4;
				__builtin_memset( &TMP$185$4, 0, 24ll );
				__builtin_memset( &TMP$184$4, 0, 24ll );
				fb_StrAssign( (void*)&TMP$184$4, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
				FBSTRING* vr$124 = HSTRIPEXT( &TMP$184$4 );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)&TMP$184$4, -1ll, 0 );
				fb_StrAssign( (void*)&TMP$185$4, -1ll, (void*)vr$124, -1ll, 0 );
				FBSTRING* vr$128 = HSTRIPPATH( (char*)*(char**)&TMP$185$4 );
				fb_StrAssign( (void*)&DLLNAME$1, -1ll, (void*)vr$128, -1ll, 0 );
				fb_StrDelete( (FBSTRING*)&TMP$185$4 );
				fb_StrDelete( (FBSTRING*)&TMP$184$4 );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --dll --enable-stdcall-fixup", 30ll, 0 );
				int64 vr$133 = FBGETCPUFAMILY(  );
				if( vr$133 != 0ll) goto label$299;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -e _DllMainCRTStartup@12", 26ll, 0 );
				}
				goto label$298;
				label$299:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -e DllMainCRTStartup", 22ll, 0 );
				}
				label$298:;
			}
			label$297:;
			label$296:;
		}
		goto label$289;
		label$300:;
		{
			int64 vr$136 = FBGETOPTION( 0ll );
			if( vr$136 != 2ll) goto label$302;
			{
				FBSTRING TMP$189$4;
				FBSTRING TMP$190$4;
				__builtin_memset( &TMP$190$4, 0, 24ll );
				__builtin_memset( &TMP$189$4, 0, 24ll );
				fb_StrAssign( (void*)&TMP$189$4, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
				FBSTRING* vr$142 = HSTRIPEXT( &TMP$189$4 );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)&TMP$189$4, -1ll, 0 );
				fb_StrAssign( (void*)&TMP$190$4, -1ll, (void*)vr$142, -1ll, 0 );
				FBSTRING* vr$146 = HSTRIPPATH( (char*)*(char**)&TMP$190$4 );
				fb_StrAssign( (void*)&DLLNAME$1, -1ll, (void*)vr$146, -1ll, 0 );
				fb_StrDelete( (FBSTRING*)&TMP$190$4 );
				fb_StrDelete( (FBSTRING*)&TMP$189$4 );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -shared -h", 12ll, 0 );
				FBSTRING* vr$152 = HSTRIPPATH( (char*)((uint8*)&FBC$ + 968ll) );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$152, -1ll, 0 );
				FBSTRING* vr$155 = fb_LEFT( (FBSTRING*)&DLLNAME$1, 3ll );
				int32 vr$156 = fb_StrCompare( (void*)vr$155, -1ll, (void*)"lib", 4ll );
				if( (int64)vr$156 != 0ll) goto label$304;
				{
					int64 vr$159 = fb_StrLen( (void*)&DLLNAME$1, -1ll );
					FBSTRING* vr$162 = fb_RIGHT( (FBSTRING*)&DLLNAME$1, vr$159 + -3ll );
					fb_StrAssign( (void*)&DLLNAME$1, -1ll, (void*)vr$162, -1ll, 0 );
				}
				label$304:;
				label$303:;
			}
			goto label$301;
			label$302:;
			{
				{
					uint64 TMP$192$5;
					int64 vr$164 = FBGETOPTION( 3ll );
					TMP$192$5 = (uint64)vr$164;
					goto label$306;
					label$307:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /libexec/ld-elf.so.1", 38ll, 0 );
					}
					goto label$305;
					label$308:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /libexec/ld-elf.so.2", 38ll, 0 );
					}
					goto label$305;
					label$309:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --dynamic-linker /lib/64/ld.so.1", 34ll, 0 );
					}
					goto label$305;
					label$310:;
					{
						{
							int64 TMP$196$7;
							int64 vr$168 = FBGETCPUFAMILY(  );
							TMP$196$7 = vr$168;
							if( TMP$196$7 != 0ll) goto label$312;
							label$313:;
							{
								fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /lib/ld-linux.so.2", 36ll, 0 );
							}
							goto label$311;
							label$312:;
							if( TMP$196$7 != 1ll) goto label$314;
							label$315:;
							{
								fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /lib64/ld-linux-x86-64.so.2", 45ll, 0 );
							}
							goto label$311;
							label$314:;
							if( TMP$196$7 != 2ll) goto label$316;
							label$317:;
							{
								fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /lib/ld-linux-armhf.so.3", 42ll, 0 );
							}
							goto label$311;
							label$316:;
							if( TMP$196$7 != 3ll) goto label$318;
							label$319:;
							{
								fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /lib/ld-linux-aarch64.so.1", 44ll, 0 );
							}
							label$318:;
							label$311:;
						}
					}
					goto label$305;
					label$320:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /usr/libexec/ld.elf_so", 40ll, 0 );
					}
					goto label$305;
					label$321:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /usr/libexec/ld.so", 36ll, 0 );
					}
					goto label$305;
					label$322:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -dynamic-linker /system/bin/linker", 36ll, 0 );
					}
					goto label$305;
					label$306:;
					static const void* tmp$886[10ll] = {
						&&label$310,
						&&label$322,
						&&label$305,
						&&label$305,
						&&label$307,
						&&label$308,
						&&label$309,
						&&label$321,
						&&label$305,
						&&label$320,
					};
					if( (TMP$192$5 - 2ull) > 9ull ) goto label$305;
					goto *tmp$886[TMP$192$5 - 2ull];
					label$305:;
				}
			}
			label$301:;
			int64 vr$176 = FBGETOPTION( 0ll );
			int64 vr$178 = FBGETOPTION( 34ll );
			int64 vr$180 = FBGETOPTION( 3ll );
			if( (((int64)-(vr$176 == 2ll) | vr$178) & (int64)-(vr$180 != 8ll)) == 0ll) goto label$324;
			{
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --export-dynamic", 18ll, 0 );
			}
			label$324:;
			label$323:;
		}
		goto label$289;
		label$325:;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -nostdlib --file-alignment 0x20 --section-alignment 0x20 -shared", 66ll, 0 );
		}
		goto label$289;
		label$326:;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -O", 4ll, 0 );
			int64 vr$186 = FBGETOPTION( 8ll );
			FBSTRING* vr$187 = fb_LongintToStr( vr$186 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$187, -1ll, 0 );
			static char EMSCRIPTEN_OPTIONS$3[5][32] = { "CASE_INSENSITIVE_FS=1", "TOTAL_MEMORY=67108864", "ALLOW_MEMORY_GROWTH=1", "RETAIN_COMPILER_SETTINGS=1", "ASYNCIFY=1" };
			static struct $8FBARRAY1IcE tmp$212$3 = { (char*)EMSCRIPTEN_OPTIONS$3, (char*)EMSCRIPTEN_OPTIONS$3, 160ll, 32ll, 1ll, 49ll, { { 5ll, 0ll, 4ll } } };
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -Wno-warn-absolute-paths", 26ll, 0 );
			{
				int64 I$4;
				I$4 = 0ll;
				label$330:;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -s ", 5ll, 0 );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((int64)(char*)EMSCRIPTEN_OPTIONS$3 + (I$4 << (5ll & 63ll))), 32ll, 0 );
				}
				label$328:;
				I$4 = I$4 + 1ll;
				label$327:;
				if( I$4 <= 4ll) goto label$330;
				label$329:;
			}
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --shell-file", 14ll, 0 );
			FBSTRING* vr$196 = HFINDLIB( (char*)"fb_shell.html" );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$196, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --post-js", 11ll, 0 );
			FBSTRING* vr$199 = HFINDLIB( (char*)"fb_rtlib.js" );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$199, -1ll, 0 );
			int64 vr$202 = fb_StrLen( (void*)((uint8*)&FBC$ + 1893ll), 129ll );
			if( vr$202 != 0ll) goto label$332;
			{
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --post-js", 11ll, 0 );
				FBSTRING* vr$204 = HFINDLIB( (char*)"termlib_min.js" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$204, -1ll, 0 );
			}
			label$332:;
			label$331:;
		}
		goto label$289;
		label$290:;
		static const void* tmp$887[13ll] = {
			&&label$291,
			&&label$291,
			&&label$300,
			&&label$300,
			&&label$289,
			&&label$325,
			&&label$300,
			&&label$300,
			&&label$300,
			&&label$300,
			&&label$300,
			&&label$300,
			&&label$326,
		};
		if( TMP$179$2 > 12ull ) goto label$289;
		goto *tmp$887[TMP$179$2 - 0ull];
		label$289:;
	}
	int64 vr$206 = FBGETOPTION( 3ll );
	if( vr$206 != 4ll) goto label$334;
	{
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -T \x22", 6ll, 0 );
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 3559ll), 261ll, 0 );
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"\x5Ci386go32.x\x22", 13ll, 0 );
	}
	goto label$333;
	label$334:;
	{
		int64 vr$211 = FBGETOPTION( 40ll );
		int64 vr$212 = FBGETOPTION( 3ll );
		int64 vr$215 = FBGETOPTION( 3ll );
		int64 vr$218 = FBGETOPTION( 3ll );
		int64 vr$223 = FBCISUSINGGOLDLINKER(  );
		if( (((((vr$211 & (int64)-(vr$212 != 10ll)) & (int64)-(vr$215 != 8ll)) & (int64)-(vr$218 != 12ll)) & ~COFF_LINKER$1) & ~vr$223) == 0ll) goto label$336;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -T \x22", 6ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 3559ll), 261ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"\x5C" "fbextra.x\x22", 12ll, 0 );
		}
		label$336:;
		label$335:;
	}
	label$333:;
	{
		uint64 TMP$225$2;
		int64 vr$230 = FBGETOPTION( 3ll );
		TMP$225$2 = (uint64)vr$230;
		goto label$338;
		label$339:;
		{
			int64 STACKSIZE$3;
			int64 vr$231 = FBGETOPTION( 39ll );
			STACKSIZE$3 = vr$231;
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --stack ", 10ll, 0 );
			FBSTRING* vr$233 = fb_LongintToStr( STACKSIZE$3 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$233, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)",", 2ll, 0 );
			FBSTRING* vr$236 = fb_LongintToStr( STACKSIZE$3 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$236, -1ll, 0 );
			int64 vr$238 = FBGETOPTION( 0ll );
			if( vr$238 != 2ll) goto label$341;
			{
				FBSTRING TMP$228$4;
				__builtin_memset( &TMP$228$4, 0, 24ll );
				fb_StrAssign( (void*)&TMP$228$4, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
				FBSTRING* vr$243 = HSTRIPEXT( &TMP$228$4 );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)&TMP$228$4, -1ll, 0 );
				fb_StrAssign( (void*)&DEFFILE$1, -1ll, (void*)vr$243, -1ll, 0 );
				fb_StrConcatAssign( (void*)&DEFFILE$1, -1ll, (void*)".def", 5ll, 0 );
				fb_StrDelete( (FBSTRING*)&TMP$228$4 );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --output-def \x22", 16ll, 0 );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)&DEFFILE$1, -1ll, 0 );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"\x22", 2ll, 0 );
			}
			label$341:;
			label$340:;
		}
		goto label$337;
		label$342:;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -e _WinMainCRTStartup", 23ll, 0 );
		}
		goto label$337;
		label$338:;
		static const void* tmp$888[6ll] = {
			&&label$339,
			&&label$339,
			&&label$337,
			&&label$337,
			&&label$337,
			&&label$342,
		};
		if( TMP$225$2 > 5ull ) goto label$337;
		goto *tmp$888[TMP$225$2 - 0ull];
		label$337:;
	}
	if( *(int64*)((uint8*)&FBC$ + 2760ll) == 0ll) goto label$344;
	{
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -Bstatic", 10ll, 0 );
	}
	label$344:;
	label$343:;
	int64 vr$255 = FBGETOPTION( 38ll );
	if( vr$255 == 0ll) goto label$346;
	{
		int64 vr$256 = FBGETOPTION( 0ll );
		if( vr$256 != 0ll) goto label$348;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -pie", 6ll, 0 );
		}
		goto label$347;
		label$348:;
		{
		}
		label$347:;
	}
	label$346:;
	label$345:;
	int64 vr$259 = fb_StrLen( (void*)((uint8*)&FBC$ + 1632ll), 261ll );
	if( vr$259 <= 0ll) goto label$350;
	{
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -Map ", 7ll, 0 );
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 1632ll), 261ll, 0 );
	}
	label$350:;
	label$349:;
	int64 vr$263 = FBGETOPTION( 14ll );
	if( vr$263 != 0ll) goto label$352;
	{
		int64 vr$264 = FBGETOPTION( 24ll );
		if( vr$264 == 1ll) goto label$354;
		{
			int64 vr$265 = FBGETOPTION( 3ll );
			int64 vr$267 = FBGETOPTION( 3ll );
			if( ((int64)-(vr$265 != 10ll) & (int64)-(vr$267 != 12ll)) == 0ll) goto label$356;
			{
				if( *(int64*)((uint8*)&FBC$ + 2768ll) == 0ll) goto label$358;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -s", 4ll, 0 );
				}
				label$358:;
				label$357:;
			}
			label$356:;
			label$355:;
		}
		label$354:;
		label$353:;
	}
	label$352:;
	label$351:;
	{
		struct $11TSTRSETITEM* I$2;
		void* vr$272 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 880ll) );
		I$2 = (struct $11TSTRSETITEM*)vr$272;
		FBSTRING L$2;
		__builtin_memset( &L$2, 0, 24ll );
		int64 vr$274 = FBGETOPTION( 3ll );
		if( vr$274 == 12ll) goto label$360;
		{
			fb_StrAssign( (void*)&L$2, -1ll, (void*)" -L \x22", 6ll, 0 );
		}
		goto label$359;
		label$360:;
		{
			fb_StrAssign( (void*)&L$2, -1ll, (void*)" -L\x22", 5ll, 0 );
		}
		label$359:;
		label$361:;
		if( I$2 == (struct $11TSTRSETITEM*)0ull) goto label$362;
		{
			FBSTRING TMP$238$3;
			FBSTRING TMP$239$3;
			FBSTRING TMP$240$3;
			__builtin_memset( &TMP$238$3, 0, 24ll );
			FBSTRING* vr$282 = fb_StrConcat( &TMP$238$3, (void*)&L$2, -1ll, (void*)I$2, -1ll );
			__builtin_memset( &TMP$239$3, 0, 24ll );
			FBSTRING* vr$285 = fb_StrConcat( &TMP$239$3, (void*)vr$282, -1ll, (void*)"\x22", 2ll );
			__builtin_memset( &TMP$240$3, 0, 24ll );
			FBSTRING* vr$289 = fb_StrConcat( &TMP$240$3, (void*)&LDCLINE$1, -1ll, (void*)vr$285, -1ll );
			fb_StrAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$289, -1ll, 0 );
			void* vr$291 = LISTGETNEXT( (void*)I$2 );
			I$2 = (struct $11TSTRSETITEM*)vr$291;
		}
		goto label$361;
		label$362:;
		fb_StrDelete( (FBSTRING*)&L$2 );
	}
	int64 vr$294 = fb_StrLen( (void*)((uint8*)&FBC$ + 2354ll), 261ll );
	if( vr$294 == 0ll) goto label$364;
	{
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --sysroot=", 12ll, 0 );
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 2354ll), 261ll, 0 );
	}
	label$364:;
	label$363:;
	{
		uint64 TMP$241$2;
		int64 vr$298 = FBGETOPTION( 3ll );
		TMP$241$2 = (uint64)vr$298;
		goto label$366;
		label$367:;
		{
			int64 vr$299 = FBGETOPTION( 0ll );
			if( vr$299 != 2ll) goto label$369;
			{
				FBSTRING* vr$300 = HFINDLIB( (char*)"crt0.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$300, -1ll, 0 );
			}
			goto label$368;
			label$369:;
			{
				FBSTRING* vr$302 = HFINDLIB( (char*)"crt0.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$302, -1ll, 0 );
				int64 vr$304 = FBGETOPTION( 24ll );
				if( vr$304 != 1ll) goto label$371;
				{
					FBSTRING* vr$305 = HFINDLIB( (char*)"gcrt0.o" );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$305, -1ll, 0 );
				}
				label$371:;
				label$370:;
			}
			label$368:;
		}
		goto label$365;
		label$372:;
		{
			int64 vr$307 = FBGETOPTION( 0ll );
			if( vr$307 != 2ll) goto label$374;
			{
				FBSTRING* vr$308 = HFINDLIB( (char*)"dllcrt2.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$308, -1ll, 0 );
			}
			goto label$373;
			label$374:;
			{
				FBSTRING* vr$310 = HFINDLIB( (char*)"crt2.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$310, -1ll, 0 );
				int64 vr$312 = FBGETOPTION( 24ll );
				if( vr$312 != 1ll) goto label$376;
				{
					FBSTRING* vr$313 = HFINDLIB( (char*)"gcrt2.o" );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$313, -1ll, 0 );
				}
				label$376:;
				label$375:;
			}
			label$373:;
			FBSTRING* vr$315 = HFINDLIB( (char*)"crtbegin.o" );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$315, -1ll, 0 );
		}
		goto label$365;
		label$377:;
		{
			int64 vr$317 = FBGETOPTION( 24ll );
			if( vr$317 != 1ll) goto label$379;
			{
				FBSTRING* vr$318 = HFINDLIB( (char*)"gcrt0.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$318, -1ll, 0 );
			}
			goto label$378;
			label$379:;
			{
				FBSTRING* vr$320 = HFINDLIB( (char*)"crt0.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$320, -1ll, 0 );
			}
			label$378:;
		}
		goto label$365;
		label$380:;
		{
			int64 vr$322 = FBGETOPTION( 0ll );
			if( vr$322 != 0ll) goto label$382;
			{
				int64 vr$323 = FBGETOPTION( 24ll );
				if( vr$323 == 0ll) goto label$384;
				{
					{
						uint64 TMP$248$6;
						int64 vr$324 = FBGETOPTION( 3ll );
						TMP$248$6 = (uint64)vr$324;
						goto label$386;
						label$387:;
						{
							FBSTRING* vr$325 = HFINDLIB( (char*)"gcrt0.o" );
							fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$325, -1ll, 0 );
						}
						goto label$385;
						label$388:;
						{
							FBSTRING* vr$327 = HFINDLIB( (char*)"gcrt1.o" );
							fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$327, -1ll, 0 );
						}
						goto label$385;
						label$386:;
						static const void* tmp$889[3ll] = {
							&&label$387,
							&&label$388,
							&&label$387,
						};
						if( (TMP$248$6 - 9ull) > 2ull ) goto label$388;
						goto *tmp$889[TMP$248$6 - 9ull];
						label$385:;
					}
				}
				goto label$383;
				label$384:;
				{
					{
						uint64 TMP$250$6;
						int64 vr$329 = FBGETOPTION( 3ll );
						TMP$250$6 = (uint64)vr$329;
						goto label$390;
						label$391:;
						{
							FBSTRING* vr$330 = HFINDLIB( (char*)"crt0.o" );
							fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$330, -1ll, 0 );
						}
						goto label$389;
						label$392:;
						{
							FBSTRING* vr$332 = HFINDLIB( (char*)"crt1.o" );
							fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$332, -1ll, 0 );
						}
						goto label$389;
						label$390:;
						static const void* tmp$890[3ll] = {
							&&label$391,
							&&label$392,
							&&label$391,
						};
						if( (TMP$250$6 - 9ull) > 2ull ) goto label$392;
						goto *tmp$890[TMP$250$6 - 9ull];
						label$389:;
					}
				}
				label$383:;
			}
			label$382:;
			label$381:;
			int64 vr$334 = FBGETOPTION( 3ll );
			if( vr$334 == 10ll) goto label$394;
			{
				int64 vr$335 = FBGETOPTION( 3ll );
				if( vr$335 == 9ll) goto label$396;
				{
					FBSTRING* vr$336 = HFINDLIB( (char*)"crti.o" );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$336, -1ll, 0 );
				}
				label$396:;
				label$395:;
				int64 vr$338 = FBGETOPTION( 38ll );
				if( vr$338 == 0ll) goto label$398;
				{
					FBSTRING* vr$339 = HFINDLIB( (char*)"crtbeginS.o" );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$339, -1ll, 0 );
				}
				goto label$397;
				label$398:;
				{
					FBSTRING* vr$341 = HFINDLIB( (char*)"crtbegin.o" );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$341, -1ll, 0 );
				}
				label$397:;
			}
			label$394:;
			label$393:;
		}
		goto label$365;
		label$399:;
		{
		}
		goto label$365;
		label$400:;
		{
			int64 vr$343 = FBGETOPTION( 0ll );
			if( vr$343 != 0ll) goto label$402;
			{
				if( *(int64*)((uint8*)&FBC$ + 2760ll) == 0ll) goto label$404;
				{
					FBSTRING* vr$344 = HFINDLIB( (char*)"crtbegin_static.o" );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$344, -1ll, 0 );
				}
				goto label$403;
				label$404:;
				{
					FBSTRING* vr$346 = HFINDLIB( (char*)"crtbegin_dynamic.o" );
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$346, -1ll, 0 );
				}
				label$403:;
			}
			goto label$401;
			label$402:;
			{
				FBSTRING* vr$348 = HFINDLIB( (char*)"crtbegin_so.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$348, -1ll, 0 );
			}
			label$401:;
		}
		goto label$365;
		label$405:;
		{
			FBSTRING* vr$350 = HFINDLIB( (char*)"crt0.o" );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$350, -1ll, 0 );
		}
		goto label$365;
		label$366:;
		static const void* tmp$891[12ll] = {
			&&label$372,
			&&label$367,
			&&label$380,
			&&label$400,
			&&label$377,
			&&label$405,
			&&label$380,
			&&label$380,
			&&label$380,
			&&label$380,
			&&label$399,
			&&label$380,
		};
		if( TMP$241$2 > 11ull ) goto label$365;
		goto *tmp$891[TMP$241$2 - 0ull];
		label$365:;
	}
	if( *(int64*)((uint8*)&FBC$ + 2752ll) != 0ll) goto label$407;
	{
		int64 vr$352 = FBGETOPTION( 3ll );
		if( vr$352 == 12ll) goto label$409;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" \x22", 3ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 3559ll), 261ll, 0 );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"\x5C", 2ll, 0 );
			{
				int64 TMP$257$4;
				int64 vr$357 = FBGETOPTION( 24ll );
				TMP$257$4 = vr$357;
				if( TMP$257$4 != 2ll) goto label$411;
				label$412:;
				{
					int64 vr$358 = FBGETOPTION( 38ll );
					if( vr$358 == 0ll) goto label$414;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"fbrt1pic.o", 11ll, 0 );
					}
					goto label$413;
					label$414:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"fbrt1.o", 8ll, 0 );
					}
					label$413:;
				}
				goto label$410;
				label$411:;
				if( TMP$257$4 != 3ll) goto label$415;
				label$416:;
				{
					int64 vr$361 = FBGETOPTION( 38ll );
					if( vr$361 == 0ll) goto label$418;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"fbrt2pic.o", 11ll, 0 );
					}
					goto label$417;
					label$418:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"fbrt2.o", 8ll, 0 );
					}
					label$417:;
				}
				goto label$410;
				label$415:;
				{
					int64 vr$364 = FBGETOPTION( 38ll );
					if( vr$364 == 0ll) goto label$421;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"fbrt0pic.o", 11ll, 0 );
					}
					goto label$420;
					label$421:;
					{
						fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"fbrt0.o", 8ll, 0 );
					}
					label$420:;
				}
				label$419:;
				label$410:;
			}
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)"\x22", 2ll, 0 );
		}
		label$409:;
		label$408:;
	}
	label$407:;
	label$406:;
	{
		FBSTRING* OBJFILE$2;
		void* vr$369 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 400ll) );
		OBJFILE$2 = (FBSTRING*)vr$369;
		label$422:;
		if( OBJFILE$2 == (FBSTRING*)0ull) goto label$423;
		{
			FBSTRING TMP$264$3;
			FBSTRING TMP$265$3;
			FBSTRING TMP$266$3;
			__builtin_memset( &TMP$264$3, 0, 24ll );
			FBSTRING* vr$372 = fb_StrConcat( &TMP$264$3, (void*)" \x22", 3ll, (void*)OBJFILE$2, -1ll );
			__builtin_memset( &TMP$265$3, 0, 24ll );
			FBSTRING* vr$375 = fb_StrConcat( &TMP$265$3, (void*)vr$372, -1ll, (void*)"\x22", 2ll );
			__builtin_memset( &TMP$266$3, 0, 24ll );
			FBSTRING* vr$379 = fb_StrConcat( &TMP$266$3, (void*)&LDCLINE$1, -1ll, (void*)vr$375, -1ll );
			fb_StrAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$379, -1ll, 0 );
			void* vr$381 = LISTGETNEXT( (void*)OBJFILE$2 );
			OBJFILE$2 = (FBSTRING*)vr$381;
		}
		goto label$422;
		label$423:;
	}
	int64 vr$382 = FBGETOPTION( 3ll );
	if( vr$382 == 10ll) goto label$425;
	{
		int64 vr$383 = FBGETOPTION( 3ll );
		if( ((int64)-(vr$383 != 12ll) & ~COFF_LINKER$1) == 0ll) goto label$427;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" \x22-(\x22", 6ll, 0 );
		}
		label$427:;
		label$426:;
	}
	label$425:;
	label$424:;
	{
		FBSTRING* LIBFILE$2;
		void* vr$389 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 464ll) );
		LIBFILE$2 = (FBSTRING*)vr$389;
		label$428:;
		if( LIBFILE$2 == (FBSTRING*)0ull) goto label$429;
		{
			FBSTRING TMP$268$3;
			FBSTRING TMP$269$3;
			FBSTRING TMP$270$3;
			__builtin_memset( &TMP$268$3, 0, 24ll );
			FBSTRING* vr$392 = fb_StrConcat( &TMP$268$3, (void*)" \x22", 3ll, (void*)LIBFILE$2, -1ll );
			__builtin_memset( &TMP$269$3, 0, 24ll );
			FBSTRING* vr$395 = fb_StrConcat( &TMP$269$3, (void*)vr$392, -1ll, (void*)"\x22", 2ll );
			__builtin_memset( &TMP$270$3, 0, 24ll );
			FBSTRING* vr$399 = fb_StrConcat( &TMP$270$3, (void*)&LDCLINE$1, -1ll, (void*)vr$395, -1ll );
			fb_StrAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$399, -1ll, 0 );
			void* vr$401 = LISTGETNEXT( (void*)LIBFILE$2 );
			LIBFILE$2 = (FBSTRING*)vr$401;
		}
		goto label$428;
		label$429:;
	}
	{
		struct $11TSTRSETITEM* I$2;
		void* vr$403 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 792ll) );
		I$2 = (struct $11TSTRSETITEM*)vr$403;
		int64 CHECKDLLNAME$2;
		int64 vr$404 = FBGETOPTION( 0ll );
		CHECKDLLNAME$2 = (int64)-(vr$404 == 2ll);
		label$430:;
		if( I$2 == (struct $11TSTRSETITEM*)0ull) goto label$431;
		{
			int64 TMP$271$3;
			if( CHECKDLLNAME$2 == 0ll) goto label$432;
			int32 vr$409 = fb_StrCompare( (void*)I$2, -1ll, (void*)&DLLNAME$1, -1ll );
			TMP$271$3 = (int64)-((int64)vr$409 != 0ll);
			goto label$1646;
			label$432:;
			TMP$271$3 = -1ll;
			label$1646:;
			if( TMP$271$3 == 0ll) goto label$434;
			{
				FBSTRING TMP$273$4;
				FBSTRING TMP$274$4;
				__builtin_memset( &TMP$273$4, 0, 24ll );
				FBSTRING* vr$416 = fb_StrConcat( &TMP$273$4, (void*)" -l", 4ll, (void*)I$2, -1ll );
				__builtin_memset( &TMP$274$4, 0, 24ll );
				FBSTRING* vr$420 = fb_StrConcat( &TMP$274$4, (void*)&LDCLINE$1, -1ll, (void*)vr$416, -1ll );
				fb_StrAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$420, -1ll, 0 );
			}
			label$434:;
			label$433:;
			void* vr$422 = LISTGETNEXT( (void*)I$2 );
			I$2 = (struct $11TSTRSETITEM*)vr$422;
		}
		goto label$430;
		label$431:;
	}
	int64 vr$423 = FBGETOPTION( 3ll );
	if( vr$423 == 10ll) goto label$436;
	{
		int64 vr$424 = FBGETOPTION( 3ll );
		if( vr$424 == 12ll) goto label$438;
		{
			if( ~COFF_LINKER$1 == 0ll) goto label$440;
			{
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" \x22-)\x22", 6ll, 0 );
			}
			label$440:;
			label$439:;
		}
		goto label$437;
		label$438:;
		{
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -lfb", 6ll, 0 );
		}
		label$437:;
	}
	label$436:;
	label$435:;
	{
		uint64 TMP$277$2;
		int64 vr$428 = FBGETOPTION( 3ll );
		TMP$277$2 = (uint64)vr$428;
		goto label$442;
		label$443:;
		{
			int64 vr$429 = FBGETOPTION( 38ll );
			if( vr$429 == 0ll) goto label$445;
			{
				FBSTRING* vr$430 = HFINDLIB( (char*)"crtendS.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$430, -1ll, 0 );
			}
			goto label$444;
			label$445:;
			{
				FBSTRING* vr$432 = HFINDLIB( (char*)"crtend.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$432, -1ll, 0 );
			}
			label$444:;
			int64 vr$434 = FBGETOPTION( 3ll );
			if( vr$434 == 9ll) goto label$447;
			{
				FBSTRING* vr$435 = HFINDLIB( (char*)"crtn.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$435, -1ll, 0 );
			}
			label$447:;
			label$446:;
		}
		goto label$441;
		label$448:;
		{
			int64 vr$437 = FBGETOPTION( 0ll );
			if( vr$437 != 0ll) goto label$450;
			{
				FBSTRING* vr$438 = HFINDLIB( (char*)"crtend_android.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$438, -1ll, 0 );
			}
			goto label$449;
			label$450:;
			{
				FBSTRING* vr$440 = HFINDLIB( (char*)"crtend_so.o" );
				fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$440, -1ll, 0 );
			}
			label$449:;
		}
		goto label$441;
		label$451:;
		{
			FBSTRING* vr$442 = HFINDLIB( (char*)"crtend.o" );
			fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)vr$442, -1ll, 0 );
		}
		goto label$441;
		label$442:;
		static const void* tmp$892[12ll] = {
			&&label$451,
			&&label$441,
			&&label$443,
			&&label$448,
			&&label$441,
			&&label$441,
			&&label$443,
			&&label$443,
			&&label$443,
			&&label$443,
			&&label$441,
			&&label$443,
		};
		if( TMP$277$2 > 11ull ) goto label$441;
		goto *tmp$892[TMP$277$2 - 0ull];
		label$441:;
	}
	int64 vr$444 = FBGETOPTION( 3ll );
	if( vr$444 != 10ll) goto label$453;
	{
		fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" -mmacosx-version-min=11.0", 27ll, 0 );
	}
	label$453:;
	label$452:;
	{
		uint64 TMP$284$2;
		int64 vr$446 = FBGETOPTION( 3ll );
		TMP$284$2 = (uint64)vr$446;
		goto label$455;
		label$456:;
		{
			int64 TMP$285$3;
			int32 OUTTYPE$3;
			int64 vr$447 = FBGETOPTION( 0ll );
			OUTTYPE$3 = (int32)vr$447;
			if( (int64)OUTTYPE$3 == 0ll) goto label$457;
			TMP$285$3 = (int64)-((int64)OUTTYPE$3 == 2ll);
			goto label$1647;
			label$457:;
			TMP$285$3 = -1ll;
			label$1647:;
			if( TMP$285$3 == 0ll) goto label$459;
			{
				int64 TMP$286$4;
				int64 TMP$287$4;
				int64 TMP$288$4;
				int32 CPUFAMILY$4;
				int64 vr$452 = FBGETCPUFAMILY(  );
				CPUFAMILY$4 = (int32)vr$452;
				if( (int64)CPUFAMILY$4 == 1ll) goto label$460;
				TMP$286$4 = (int64)-((int64)CPUFAMILY$4 == 3ll);
				goto label$1648;
				label$460:;
				TMP$286$4 = -1ll;
				label$1648:;
				if( TMP$286$4 != 0ll) goto label$461;
				TMP$287$4 = (int64)-((int64)CPUFAMILY$4 == 5ll);
				goto label$1649;
				label$461:;
				TMP$287$4 = -1ll;
				label$1649:;
				if( TMP$287$4 != 0ll) goto label$462;
				TMP$288$4 = (int64)-((int64)CPUFAMILY$4 == 6ll);
				goto label$1650;
				label$462:;
				TMP$288$4 = -1ll;
				label$1650:;
				if( TMP$288$4 == 0ll) goto label$464;
				{
					fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" --eh-frame-hdr", 16ll, 0 );
				}
				label$464:;
				label$463:;
			}
			label$459:;
			label$458:;
		}
		goto label$454;
		label$455:;
		static const void* tmp$893[10ll] = {
			&&label$456,
			&&label$454,
			&&label$454,
			&&label$454,
			&&label$456,
			&&label$456,
			&&label$456,
			&&label$456,
			&&label$454,
			&&label$456,
		};
		if( (TMP$284$2 - 2ull) > 9ull ) goto label$454;
		goto *tmp$893[TMP$284$2 - 2ull];
		label$454:;
	}
	fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)" ", 2ll, 0 );
	fb_StrConcatAssign( (void*)&LDCLINE$1, -1ll, (void*)((uint8*)&FBC$ + 2048ll), -1ll, 0 );
	int32 FORCEFILE$1;
	__builtin_memset( &FORCEFILE$1, 0, 4ll );
	uint32 TARGETPREFIXLEN$1;
	__builtin_memset( &TARGETPREFIXLEN$1, 0, 4ll );
	int64 vr$468 = fb_StrLen( (void*)((uint8*)&FBC$ + 2225ll), 129ll );
	TARGETPREFIXLEN$1 = (uint32)vr$468;
	int64 TOOLNAMELEN$1;
	int64 vr$472 = fb_StrLen( (void*)((uint8*)&FBC$ + 3820ll), 261ll );
	if( (int64)TARGETPREFIXLEN$1 <= vr$472) goto label$465;
	TMP$291$1 = (int64)TARGETPREFIXLEN$1;
	goto label$1651;
	label$465:;
	int64 vr$475 = fb_StrLen( (void*)((uint8*)&FBC$ + 3820ll), 261ll );
	TMP$291$1 = vr$475;
	label$1651:;
	TOOLNAMELEN$1 = TMP$291$1 + 7ll;
	if( (int64)FORCEFILE$1 != 0ll) goto label$466;
	int64 vr$478 = FBGETOPTION( 3ll );
	int64 vr$481 = fb_StrLen( (void*)&LDCLINE$1, -1ll );
	TMP$292$1 = (int64)-(((int64)-(vr$478 == 4ll) | (int64)-(vr$481 > (2047ll - TOOLNAMELEN$1))) != 0ll);
	goto label$1652;
	label$466:;
	TMP$292$1 = -1ll;
	label$1652:;
	if( TMP$292$1 == 0ll) goto label$468;
	{
		int64 vr$487 = HPUTLDARGSINTOFILE( &LDCLINE$1 );
		if( vr$487 != 0ll) goto label$470;
		{
			fb_StrDelete( (FBSTRING*)&DEFFILE$1 );
			fb_StrDelete( (FBSTRING*)&DLLNAME$1 );
			fb_StrDelete( (FBSTRING*)&LDCLINE$1 );
			goto label$237;
		}
		label$470:;
		label$469:;
	}
	label$468:;
	label$467:;
	$7FBCTOOL LD$1;
	LD$1 = 3ll;
	int64 vr$491 = FBGETOPTION( 3ll );
	if( vr$491 != 12ll) goto label$472;
	{
		LD$1 = 14ll;
	}
	goto label$471;
	label$472:;
	int64 vr$492 = FBGETOPTION( 3ll );
	if( vr$492 != 10ll) goto label$473;
	{
		LD$1 = 4ll;
	}
	label$473:;
	label$471:;
	int64 vr$494 = FBCRUNBIN( (char*)"linking", LD$1, &LDCLINE$1 );
	if( vr$494 != 0ll) goto label$475;
	{
		fb_StrDelete( (FBSTRING*)&DEFFILE$1 );
		fb_StrDelete( (FBSTRING*)&DLLNAME$1 );
		fb_StrDelete( (FBSTRING*)&LDCLINE$1 );
		goto label$237;
	}
	label$475:;
	label$474:;
	{
		uint64 TMP$294$2;
		int64 vr$498 = FBGETOPTION( 3ll );
		TMP$294$2 = (uint64)vr$498;
		goto label$477;
		label$478:;
		{
			int64 F$3;
			int32 vr$499 = fb_FileFree(  );
			F$3 = (int64)vr$499;
			FBSTRING* vr$503 = fb_StrAllocTempDescZ( (char*)((uint8*)&FBC$ + 968ll) );
			int32 vr$504 = fb_FileOpen( (FBSTRING*)vr$503, 0u, 3u, 0u, (int32)F$3, 0 );
			if( (int64)vr$504 == 0ll) goto label$480;
			{
				fb_StrDelete( (FBSTRING*)&DEFFILE$1 );
				fb_StrDelete( (FBSTRING*)&DLLNAME$1 );
				fb_StrDelete( (FBSTRING*)&LDCLINE$1 );
				goto label$237;
			}
			label$480:;
			label$479:;
			int32 VALUE$3;
			int64 vr$509 = FBGETOPTION( 39ll );
			VALUE$3 = (int32)vr$509;
			int32 vr$513 = fb_FilePutLarge( (int32)F$3, 533ll, (void*)&VALUE$3, 4ull );
			if( (int64)vr$513 == 0ll) goto label$481;
			void* vr$515 = fb_ErrorThrowAt( 1448, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
			goto *vr$515;
			label$481:;
			int32 vr$517 = fb_FileClose( (int32)F$3 );
			if( (int64)vr$517 == 0ll) goto label$482;
			void* vr$519 = fb_ErrorThrowAt( 1450, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
			goto *vr$519;
			label$482:;
		}
		goto label$476;
		label$483:;
		{
			int64 vr$520 = FBGETOPTION( 0ll );
			if( vr$520 != 2ll) goto label$485;
			{
				int64 vr$523 = MAKEIMPLIB( &DLLNAME$1, &DEFFILE$1 );
				if( vr$523 != 0ll) goto label$487;
				{
					fb_StrDelete( (FBSTRING*)&DEFFILE$1 );
					fb_StrDelete( (FBSTRING*)&DLLNAME$1 );
					fb_StrDelete( (FBSTRING*)&LDCLINE$1 );
					goto label$237;
				}
				label$487:;
				label$486:;
			}
			label$485:;
			label$484:;
		}
		goto label$476;
		label$488:;
		{
			FBSTRING TMP$306$3;
			FBSTRING TMP$311$3;
			FBSTRING TMP$312$3;
			FBSTRING CXBEPATH$3;
			__builtin_memset( &CXBEPATH$3, 0, 24ll );
			FBSTRING CXBECLINE$3;
			__builtin_memset( &CXBECLINE$3, 0, 24ll );
			int64 RES$3;
			int64 vr$530 = fb_StrLen( (void*)((uint8*)&FBC$ + 2615ll), 129ll );
			if( vr$530 != 0ll) goto label$490;
			{
				FBSTRING TMP$295$4;
				__builtin_memset( &TMP$295$4, 0, 24ll );
				fb_StrAssign( (void*)&TMP$295$4, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
				FBSTRING* vr$535 = HSTRIPEXT( &TMP$295$4 );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)&TMP$295$4, -1ll, 0 );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 2615ll), 129ll, (void*)vr$535, -1ll, 0 );
				fb_StrDelete( (FBSTRING*)&TMP$295$4 );
			}
			label$490:;
			label$489:;
			fb_StrAssign( (void*)&CXBECLINE$3, -1ll, (void*)"-TITLE:\x22", 9ll, 0 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)((uint8*)&FBC$ + 2615ll), 129ll, 0 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)"\x22 ", 3ll, 0 );
			int64 vr$544 = FBGETOPTION( 14ll );
			if( vr$544 == 0ll) goto label$492;
			{
				FBSTRING TMP$301$4;
				fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)"-DUMPINFO:\x22", 12ll, 0 );
				__builtin_memset( &TMP$301$4, 0, 24ll );
				fb_StrAssign( (void*)&TMP$301$4, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
				FBSTRING* vr$550 = HSTRIPEXT( &TMP$301$4 );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)&TMP$301$4, -1ll, 0 );
				fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)vr$550, -1ll, 0 );
				fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)".cxbe\x22", 7ll, 0 );
				fb_StrDelete( (FBSTRING*)&TMP$301$4 );
			}
			label$492:;
			label$491:;
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)" -OUT:\x22", 8ll, 0 );
			__builtin_memset( &TMP$306$3, 0, 24ll );
			fb_StrAssign( (void*)&TMP$306$3, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
			FBSTRING* vr$561 = HSTRIPEXT( &TMP$306$3 );
			fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)&TMP$306$3, -1ll, 0 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)vr$561, -1ll, 0 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)".xbe", 5ll, 0 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)"\x22", 2ll, 0 );
			fb_StrDelete( (FBSTRING*)&TMP$306$3 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)" \x22", 3ll, 0 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)((uint8*)&FBC$ + 968ll), 261ll, 0 );
			fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)"\x22", 2ll, 0 );
			if( *(int64*)((uint8*)&FBC$ + 112ll) != 0ll) goto label$494;
			{
				fb_StrConcatAssign( (void*)&CXBECLINE$3, -1ll, (void*)" >nul", 6ll, 0 );
			}
			label$494:;
			label$493:;
			if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$496;
			{
				FBSTRING* vr$573 = fb_StrAllocTempDescZEx( (char*)"cxbe: ", 6ll );
				fb_PrintString( 0, (FBSTRING*)vr$573, 2 );
				fb_PrintString( 0, (FBSTRING*)&CXBECLINE$3, 1 );
			}
			label$496:;
			label$495:;
			FBCFINDBIN( 10ll, &CXBEPATH$3 );
			__builtin_memset( &TMP$311$3, 0, 24ll );
			FBSTRING* vr$580 = fb_StrConcat( &TMP$311$3, (void*)&CXBEPATH$3, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$312$3, 0, 24ll );
			FBSTRING* vr$583 = fb_StrConcat( &TMP$312$3, (void*)vr$580, -1ll, (void*)&CXBECLINE$3, -1ll );
			int32 vr$584 = fb_Shell( (FBSTRING*)vr$583 );
			RES$3 = (int64)vr$584;
			if( RES$3 == 0ll) goto label$498;
			{
				if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$500;
				{
					FBSTRING TMP$314$5;
					FBSTRING* vr$586 = fb_LongintToStr( RES$3 );
					__builtin_memset( &TMP$314$5, 0, 24ll );
					FBSTRING* vr$589 = fb_StrConcat( &TMP$314$5, (void*)"cxbe failed: exit code ", 24ll, (void*)vr$586, -1ll );
					fb_PrintString( 0, (FBSTRING*)vr$589, 1 );
				}
				label$500:;
				label$499:;
				fb_StrDelete( (FBSTRING*)&CXBECLINE$3 );
				fb_StrDelete( (FBSTRING*)&CXBEPATH$3 );
				fb_StrDelete( (FBSTRING*)&DEFFILE$1 );
				fb_StrDelete( (FBSTRING*)&DLLNAME$1 );
				fb_StrDelete( (FBSTRING*)&LDCLINE$1 );
				goto label$237;
			}
			label$498:;
			label$497:;
			FBSTRING* vr$596 = fb_StrAllocTempDescZ( (char*)((uint8*)&FBC$ + 968ll) );
			fb_FileKill( (FBSTRING*)vr$596 );
			fb_StrDelete( (FBSTRING*)&CXBECLINE$3 );
			fb_StrDelete( (FBSTRING*)&CXBEPATH$3 );
		}
		goto label$476;
		label$477:;
		static const void* tmp$894[6ll] = {
			&&label$483,
			&&label$483,
			&&label$476,
			&&label$476,
			&&label$478,
			&&label$488,
		};
		if( TMP$294$2 > 5ull ) goto label$476;
		goto *tmp$894[TMP$294$2 - 0ull];
		label$476:;
	}
	fb$result$1 = -1ll;
	fb_StrDelete( (FBSTRING*)&DEFFILE$1 );
	fb_StrDelete( (FBSTRING*)&DLLNAME$1 );
	fb_StrDelete( (FBSTRING*)&LDCLINE$1 );
	label$237:;
	return fb$result$1;
}

static void HREADOBJINFO( void )
{
	label$501:;
	FBSTRING DAT$1;
	__builtin_memset( &DAT$1, 0, 24ll );
	int64 LANG$1;
	label$503:;
	{
		{
			uint64 TMP$315$3;
			int64 vr$2 = OBJINFOREADNEXT( &DAT$1 );
			TMP$315$3 = (uint64)vr$2;
			goto label$507;
			label$508:;
			{
				STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 792ll), &DAT$1, 0ll );
			}
			goto label$506;
			label$509:;
			{
				STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 880ll), &DAT$1, 0ll );
			}
			goto label$506;
			label$510:;
			{
				if( *(int64*)((uint8*)&FBC$ + 4096ll) != 0ll) goto label$512;
				{
					char* vr$7 = OBJINFOGETFILENAME(  );
					ERRREPORTWARNEX( 20ll, (char*)vr$7, -1ll, 1ll, (char*)0ull );
					*(int64*)((uint8*)&FBC$ + 4096ll) = -1ll;
					FBSETOPTION( 36ll, -1ll );
				}
				label$512:;
				label$511:;
			}
			goto label$506;
			label$513:;
			{
				FBSETOPTION( 37ll, -1ll );
			}
			goto label$506;
			label$514:;
			{
				$7FB_LANG vr$8 = FBGETLANGID( (char*)*(char**)&DAT$1 );
				LANG$1 = vr$8;
				if( LANG$1 != -1ll) goto label$516;
				{
					LANG$1 = 0ll;
				}
				label$516:;
				label$515:;
				if( LANG$1 == *(int64*)((uint8*)&FBC$ + 4088ll)) goto label$518;
				{
					char* vr$9 = OBJINFOGETFILENAME(  );
					ERRREPORTWARNEX( 21ll, (char*)vr$9, -1ll, 1ll, (char*)0ull );
					*($7FB_LANG*)((uint8*)&FBC$ + 4088ll) = LANG$1;
					FBSETOPTION( 10ll, LANG$1 );
				}
				label$518:;
				label$517:;
			}
			goto label$506;
			label$519:;
			{
				goto label$504;
			}
			goto label$506;
			label$507:;
			static const void* tmp$895[5ll] = {
				&&label$508,
				&&label$509,
				&&label$510,
				&&label$513,
				&&label$514,
			};
			if( TMP$315$3 > 4ull ) goto label$519;
			goto *tmp$895[TMP$315$3 - 0ull];
			label$506:;
		}
	}
	label$505:;
	goto label$503;
	label$504:;
	OBJINFOREADEND(  );
	fb_StrDelete( (FBSTRING*)&DAT$1 );
	label$502:;
}

static void HCOLLECTOBJINFO( void )
{
	label$520:;
	FBSTRING* S$1;
	struct $11TSTRSETITEM* I$1;
	void* vr$1 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 400ll) );
	S$1 = (FBSTRING*)vr$1;
	label$522:;
	if( S$1 == (FBSTRING*)0ull) goto label$523;
	{
		OBJINFOREADOBJ( S$1 );
		HREADOBJINFO(  );
		void* vr$2 = LISTGETNEXT( (void*)S$1 );
		S$1 = (FBSTRING*)vr$2;
	}
	goto label$522;
	label$523:;
	void* vr$4 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 792ll) );
	I$1 = (struct $11TSTRSETITEM*)vr$4;
	label$524:;
	if( I$1 == (struct $11TSTRSETITEM*)0ull) goto label$525;
	{
		if( *(int64*)((uint8*)I$1 + 24ll) != 0ll) goto label$527;
		{
			OBJINFOREADLIB( (FBSTRING*)I$1, (struct $5TLIST*)((uint8*)&FBC$ + 880ll) );
			HREADOBJINFO(  );
		}
		label$527:;
		label$526:;
		void* vr$9 = LISTGETNEXT( (void*)I$1 );
		I$1 = (struct $11TSTRSETITEM*)vr$9;
	}
	goto label$524;
	label$525:;
	void* vr$11 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 464ll) );
	S$1 = (FBSTRING*)vr$11;
	label$528:;
	if( S$1 == (FBSTRING*)0ull) goto label$529;
	{
		OBJINFOREADLIBFILE( S$1 );
		HREADOBJINFO(  );
		void* vr$12 = LISTGETNEXT( (void*)S$1 );
		S$1 = (FBSTRING*)vr$12;
	}
	goto label$528;
	label$529:;
	label$521:;
}

static void HFATALINVALIDOPTION( FBSTRING* ARG$1, int64 IS_SOURCE$1 )
{
	FBSTRING TMP$316$1;
	FBSTRING TMP$317$1;
	FBSTRING TMP$318$1;
	int64 TMP$319$1;
	label$530:;
	if( IS_SOURCE$1 == 0ll) goto label$532;
	TMP$319$1 = 0ll;
	goto label$1653;
	label$532:;
	TMP$319$1 = -1ll;
	label$1653:;
	__builtin_memset( &TMP$318$1, 0, 24ll );
	__builtin_memset( &TMP$316$1, 0, 24ll );
	FBSTRING* vr$3 = fb_StrConcat( &TMP$316$1, (void*)"\x22", 2ll, (void*)ARG$1, -1ll );
	__builtin_memset( &TMP$317$1, 0, 24ll );
	FBSTRING* vr$6 = fb_StrConcat( &TMP$317$1, (void*)vr$3, -1ll, (void*)"\x22", 2ll );
	fb_StrAssign( (void*)&TMP$318$1, -1ll, (void*)vr$6, -1ll, 0 );
	ERRREPORTEX( 81ll, (char*)*(char**)&TMP$318$1, TMP$319$1, 1ll, (char*)0ull );
	fb_StrDelete( (FBSTRING*)&TMP$318$1 );
	FBCEND( 1ll );
	label$531:;
}

static void HCHECKWAITINGOBJFILE( void )
{
	label$533:;
	int64 vr$1 = fb_StrLen( (void*)((uint8*)&FBC$ + 16ll), -1ll );
	if( vr$1 <= 0ll) goto label$536;
	{
		FBSTRING TMP$320$2;
		FBSTRING TMP$321$2;
		__builtin_memset( &TMP$321$2, 0, 24ll );
		__builtin_memset( &TMP$320$2, 0, 24ll );
		FBSTRING* vr$6 = fb_StrConcat( &TMP$320$2, (void*)"-o ", 4ll, (void*)((uint8*)&FBC$ + 16ll), -1ll );
		fb_StrAssign( (void*)&TMP$321$2, -1ll, (void*)vr$6, -1ll, 0 );
		ERRREPORTEX( 292ll, (char*)*(char**)&TMP$321$2, -1ll, 1ll, (char*)0ull );
		fb_StrDelete( (FBSTRING*)&TMP$321$2 );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 16ll), -1ll, (void*)"", 1ll, 0 );
	}
	label$536:;
	label$535:;
	label$534:;
}

static void HSETIOFILE( struct $9FBCIOFILE* MODULE$1, FBSTRING* SRCFILE$1, int64 IS_RC$1 )
{
	label$537:;
	fb_StrAssign( (void*)MODULE$1, -1ll, (void*)SRCFILE$1, -1ll, 0 );
	int64 vr$3 = fb_StrLen( (void*)((uint8*)&FBC$ + 16ll), -1ll );
	if( vr$3 != 0ll) goto label$540;
	{
		*(int64*)((uint8*)MODULE$1 + 32ll) = 0ll;
		if( IS_RC$1 == 0ll) goto label$542;
		{
			FBSTRING TMP$323$3;
			__builtin_memset( &TMP$323$3, 0, 24ll );
			FBSTRING* vr$7 = fb_StrConcat( &TMP$323$3, (void*)SRCFILE$1, -1ll, (void*)".o", 3ll );
			fb_StrAssign( (void*)((uint8*)&FBC$ + 16ll), -1ll, (void*)vr$7, -1ll, 0 );
		}
		goto label$541;
		label$542:;
		{
			FBSTRING TMP$324$3;
			FBSTRING* vr$9 = HSTRIPEXT( SRCFILE$1 );
			__builtin_memset( &TMP$324$3, 0, 24ll );
			FBSTRING* vr$12 = fb_StrConcat( &TMP$324$3, (void*)vr$9, -1ll, (void*)".o", 3ll );
			fb_StrAssign( (void*)((uint8*)&FBC$ + 16ll), -1ll, (void*)vr$12, -1ll, 0 );
		}
		label$541:;
		*(struct $9FBCIOFILE**)((uint8*)&FBC$ + 8ll) = MODULE$1;
	}
	goto label$539;
	label$540:;
	{
		*(int64*)((uint8*)MODULE$1 + 32ll) = -1ll;
	}
	label$539:;
	FBSTRING* vr$16 = FBCADDOBJ( (FBSTRING*)((uint8*)&FBC$ + 16ll) );
	*(FBSTRING**)((uint8*)MODULE$1 + 24ll) = vr$16;
	fb_StrAssign( (void*)((uint8*)&FBC$ + 16ll), -1ll, (void*)"", 1ll, 0 );
	label$538:;
}

static void HADDBAS( FBSTRING* BASFILE$1 )
{
	label$543:;
	void* vr$1 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&FBC$ + 144ll) );
	HSETIOFILE( (struct $9FBCIOFILE*)vr$1, BASFILE$1, 0ll );
	label$544:;
}

static void HPARSEGNUTRIPLET( FBSTRING* ARG$1, int64 SEPARATOR$1, int64* OS$1, int64* CPUTYPE$1 )
{
	label$545:;
	FBSTRING ARCH$1;
	__builtin_memset( &ARCH$1, 0, 24ll );
	{
		int64 I$2;
		I$2 = 0ll;
		label$550:;
		{
			FBSTRING* vr$2 = fb_StrAllocTempDescZ( (char*)*(char**)((int64)(struct $11FBGNUOSINFO*)GNUOSMAP$ + (I$2 << (4ll & 63ll))) );
			int64 vr$3 = fb_StrInstr( 1ll, (FBSTRING*)ARG$1, (FBSTRING*)vr$2 );
			if( vr$3 <= 0ll) goto label$552;
			{
				*OS$1 = *(int64*)(((int64)(struct $11FBGNUOSINFO*)GNUOSMAP$ + (I$2 << (4ll & 63ll))) + 8ll);
				goto label$549;
			}
			label$552:;
			label$551:;
		}
		label$548:;
		I$2 = I$2 + 1ll;
		label$547:;
		if( I$2 <= 16ll) goto label$550;
		label$549:;
	}
	if( SEPARATOR$1 <= 0ll) goto label$554;
	{
		FBSTRING* vr$8 = fb_LEFT( (FBSTRING*)ARG$1, SEPARATOR$1 + -1ll );
		fb_StrAssign( (void*)&ARCH$1, -1ll, (void*)vr$8, -1ll, 0 );
		{
			int64 I$3;
			I$3 = 0ll;
			label$558:;
			{
				int32 vr$12 = fb_StrCompare( (void*)&ARCH$1, -1ll, *(void**)((int64)(struct $13FBGNUARCHINFO*)GNUARCHMAP$ + (I$3 << (4ll & 63ll))), 0ll );
				if( (int64)vr$12 != 0ll) goto label$560;
				{
					*CPUTYPE$1 = *(int64*)(((int64)(struct $13FBGNUARCHINFO*)GNUARCHMAP$ + (I$3 << (4ll & 63ll))) + 8ll);
					goto label$557;
				}
				label$560:;
				label$559:;
			}
			label$556:;
			I$3 = I$3 + 1ll;
			label$555:;
			if( I$3 <= 20ll) goto label$558;
			label$557:;
		}
	}
	label$554:;
	label$553:;
	fb_StrDelete( (FBSTRING*)&ARCH$1 );
	label$546:;
}

static void HPARSETARGETARG( FBSTRING* ARG$1, int64* OS$1, int64* CPUTYPE$1, int64* IS_GNU_TRIPLET$1 )
{
	label$569:;
	*OS$1 = -1ll;
	*CPUTYPE$1 = -1ll;
	*IS_GNU_TRIPLET$1 = 0ll;
	FBSTRING LCASEARG$1;
	FBSTRING* vr$3 = fb_StrLcase2( (FBSTRING*)ARG$1, 0 );
	fb_StrInit( (void*)&LCASEARG$1, -1ll, (void*)vr$3, -1ll, 0 );
	{
		int64 I$2;
		I$2 = 0ll;
		label$574:;
		{
			int32 vr$7 = fb_StrCompare( (void*)&LCASEARG$1, -1ll, *(void**)((int64)(struct $12FBOSARCHINFO*)FBOSARCHMAP$ + (I$2 * 24ll)), 0ll );
			if( (int64)vr$7 != 0ll) goto label$576;
			{
				*OS$1 = *(int64*)(((int64)(struct $12FBOSARCHINFO*)FBOSARCHMAP$ + (I$2 * 24ll)) + 8ll);
				*CPUTYPE$1 = *(int64*)(((int64)(struct $12FBOSARCHINFO*)FBOSARCHMAP$ + (I$2 * 24ll)) + 16ll);
				fb_StrDelete( (FBSTRING*)&LCASEARG$1 );
				goto label$570;
			}
			label$576:;
			label$575:;
		}
		label$572:;
		I$2 = I$2 + 1ll;
		label$571:;
		if( I$2 <= 16ll) goto label$574;
		label$573:;
	}
	int64 SEPARATOR$1;
	FBSTRING* vr$15 = fb_StrAllocTempDescZEx( (char*)"-", 1ll );
	int64 vr$16 = fb_StrInstr( 1ll, (FBSTRING*)ARG$1, (FBSTRING*)vr$15 );
	SEPARATOR$1 = vr$16;
	if( SEPARATOR$1 <= 0ll) goto label$578;
	{
		FBSTRING TMP$371$2;
		FBSTRING TMP$372$2;
		__builtin_memset( &TMP$371$2, 0, 24ll );
		FBSTRING* vr$20 = fb_LEFT( (FBSTRING*)&LCASEARG$1, SEPARATOR$1 + -1ll );
		fb_StrAssign( (void*)&TMP$371$2, -1ll, (void*)vr$20, -1ll, 0 );
		int64 vr$23 = FBIDENTIFYOS( &TMP$371$2 );
		*OS$1 = vr$23;
		fb_StrDelete( (FBSTRING*)&TMP$371$2 );
		__builtin_memset( &TMP$372$2, 0, 24ll );
		int64 vr$28 = fb_StrLen( (void*)&LCASEARG$1, -1ll );
		FBSTRING* vr$31 = fb_RIGHT( (FBSTRING*)&LCASEARG$1, vr$28 - SEPARATOR$1 );
		fb_StrAssign( (void*)&TMP$372$2, -1ll, (void*)vr$31, -1ll, 0 );
		int64 vr$35 = FBDEFAULTCPUTYPEFROMCPUFAMILYID( *OS$1, &TMP$372$2 );
		*CPUTYPE$1 = vr$35;
		fb_StrDelete( (FBSTRING*)&TMP$372$2 );
	}
	label$578:;
	label$577:;
	if( ((int64)-(*OS$1 < 0ll) & (int64)-(*CPUTYPE$1 < 0ll)) == 0ll) goto label$580;
	{
		HPARSEGNUTRIPLET( ARG$1, SEPARATOR$1, OS$1, CPUTYPE$1 );
		*IS_GNU_TRIPLET$1 = -1ll;
	}
	label$580:;
	label$579:;
	fb_StrDelete( (FBSTRING*)&LCASEARG$1 );
	label$570:;
}

static void HANDLEOPT( int64 OPTID$1, FBSTRING* ARG$1, int64 IS_SOURCE$1 )
{
	label$581:;
	{
		uint64 TMP$375$2;
		TMP$375$2 = (uint64)OPTID$1;
		goto label$584;
		label$585:;
		{
			FBCADDOBJ( ARG$1 );
		}
		goto label$583;
		label$586:;
		{
			int32 vr$0 = fb_StrCompare( (void*)ARG$1, -1ll, (void*)"native", 7ll );
			*(int64*)((uint8*)&FBC$ + 56ll) = (int64)-((int64)vr$0 == 0ll);
			int64 vr$3 = FBIDENTIFYFBCARCH( ARG$1 );
			*(int64*)((uint8*)&FBC$ + 48ll) = vr$3;
			if( *(int64*)((uint8*)&FBC$ + 48ll) >= 0ll) goto label$588;
			{
				FBSTRING TMP$378$4;
				FBSTRING TMP$379$4;
				__builtin_memset( &TMP$379$4, 0, 24ll );
				__builtin_memset( &TMP$378$4, 0, 24ll );
				FBSTRING* vr$7 = fb_StrConcat( &TMP$378$4, (void*)"-arch ", 7ll, (void*)ARG$1, -1ll );
				fb_StrAssign( (void*)&TMP$379$4, -1ll, (void*)vr$7, -1ll, 0 );
				HFATALINVALIDOPTION( &TMP$379$4, IS_SOURCE$1 );
				fb_StrDelete( (FBSTRING*)&TMP$379$4 );
			}
			label$588:;
			label$587:;
		}
		goto label$583;
		label$589:;
		{
			{
				FBSTRING TMP$380$4;
				fb_StrInit( (void*)&TMP$380$4, -1ll, (void*)ARG$1, -1ll, 0 );
				int32 vr$13 = fb_StrCompare( (void*)&TMP$380$4, -1ll, (void*)"att", 4ll );
				if( (int64)vr$13 != 0ll) goto label$591;
				label$592:;
				{
					*(int64*)((uint8*)&FBC$ + 64ll) = 1ll;
				}
				goto label$590;
				label$591:;
				int32 vr$16 = fb_StrCompare( (void*)&TMP$380$4, -1ll, (void*)"intel", 6ll );
				if( (int64)vr$16 != 0ll) goto label$593;
				label$594:;
				{
					*(int64*)((uint8*)&FBC$ + 64ll) = 0ll;
				}
				goto label$590;
				label$593:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$595:;
				label$590:;
				fb_StrDelete( (FBSTRING*)&TMP$380$4 );
			}
		}
		goto label$583;
		label$596:;
		{
			HADDBAS( ARG$1 );
		}
		goto label$583;
		label$597:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 3820ll), 261ll, (void*)ARG$1, -1ll, 0 );
		}
		goto label$583;
		label$598:;
		{
			FBSETOPTION( 0ll, 3ll );
			*(int64*)((uint8*)&FBC$ + 104ll) = -1ll;
		}
		goto label$583;
		label$599:;
		{
			*(int64*)((uint8*)&FBC$ + 104ll) = -1ll;
		}
		goto label$583;
		label$600:;
		{
			FBADDPREDEFINE( ARG$1 );
		}
		goto label$583;
		label$601:;
		{
			FBSETOPTION( 0ll, 2ll );
		}
		goto label$583;
		label$602:;
		{
			FBSETOPTION( 16ll, -1ll );
			FBSETOPTION( 21ll, -1ll );
		}
		goto label$583;
		label$603:;
		{
			FBSETOPTION( 22ll, -1ll );
		}
		goto label$583;
		label$604:;
		{
			FBSETOPTION( 23ll, -1ll );
		}
		goto label$583;
		label$605:;
		{
			FBSETOPTION( 15ll, -1ll );
		}
		goto label$583;
		label$606:;
		{
			FBSETOPTION( 13ll, -1ll );
		}
		goto label$583;
		label$607:;
		{
			FBSETOPTION( 14ll, -1ll );
		}
		goto label$583;
		label$608:;
		{
			FBSETOPTION( 19ll, -1ll );
		}
		goto label$583;
		label$609:;
		{
			FBSETOPTION( 20ll, -1ll );
		}
		goto label$583;
		label$610:;
		{
			FBSETOPTION( 21ll, -1ll );
		}
		goto label$583;
		label$611:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 1490ll), 129ll, (void*)ARG$1, -1ll, 0 );
		}
		goto label$583;
		label$612:;
		{
			FBSETOPTION( 16ll, -1ll );
			FBSETOPTION( 17ll, -1ll );
			FBSETOPTION( 21ll, -1ll );
		}
		goto label$583;
		label$613:;
		{
			FBSETOPTION( 16ll, -1ll );
			FBSETOPTION( 17ll, -1ll );
			FBSETOPTION( 18ll, -1ll );
			FBSETOPTION( 19ll, -1ll );
			FBSETOPTION( 22ll, -1ll );
			FBSETOPTION( 23ll, -1ll );
			FBSETOPTION( 20ll, -1ll );
			FBSETOPTION( 21ll, -1ll );
		}
		goto label$583;
		label$614:;
		{
			FBSETOPTION( 34ll, -1ll );
		}
		goto label$583;
		label$615:;
		{
			FBSETOPTION( 37ll, -1ll );
		}
		goto label$583;
		label$616:;
		{
			int64 VALUE$3;
			$7FB_LANG vr$22 = FBGETLANGID( (char*)*(char**)ARG$1 );
			VALUE$3 = vr$22;
			if( VALUE$3 != -1ll) goto label$618;
			{
				HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
			}
			label$618:;
			label$617:;
			int64 vr$23 = FBGETOPTION( 11ll );
			if( (IS_SOURCE$1 & vr$23) == 0ll) goto label$620;
			{
				ERRREPORTWARN( 30ll, (char*)0ull, 1ll, (char*)0ull );
			}
			goto label$619;
			label$620:;
			{
				FBSETOPTION( 10ll, VALUE$3 );
				FBSETOPTION( 11ll, -1ll );
				*($7FB_LANG*)((uint8*)&FBC$ + 4088ll) = VALUE$3;
				if( IS_SOURCE$1 == 0ll) goto label$622;
				{
					FBSETOPTION( 12ll, VALUE$3 );
				}
				label$622:;
				label$621:;
			}
			label$619:;
		}
		goto label$583;
		label$623:;
		{
			int64 VALUE$3;
			{
				FBSTRING TMP$383$4;
				FBSTRING* vr$25 = fb_StrUcase2( (FBSTRING*)ARG$1, 0 );
				fb_StrInit( (void*)&TMP$383$4, -1ll, (void*)vr$25, -1ll, 0 );
				int32 vr$28 = fb_StrCompare( (void*)&TMP$383$4, -1ll, (void*)"PRECISE", 8ll );
				if( (int64)vr$28 != 0ll) goto label$625;
				label$626:;
				{
					VALUE$3 = 0ll;
				}
				goto label$624;
				label$625:;
				int32 vr$31 = fb_StrCompare( (void*)&TMP$383$4, -1ll, (void*)"FAST", 5ll );
				if( (int64)vr$31 != 0ll) goto label$627;
				label$628:;
				{
					VALUE$3 = 1ll;
				}
				goto label$624;
				label$627:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$629:;
				label$624:;
				fb_StrDelete( (FBSTRING*)&TMP$383$4 );
			}
			FBSETOPTION( 6ll, VALUE$3 );
		}
		goto label$583;
		label$630:;
		{
			int64 VALUE$3;
			{
				FBSTRING TMP$386$4;
				FBSTRING* vr$34 = fb_StrUcase2( (FBSTRING*)ARG$1, 0 );
				fb_StrInit( (void*)&TMP$386$4, -1ll, (void*)vr$34, -1ll, 0 );
				int32 vr$37 = fb_StrCompare( (void*)&TMP$386$4, -1ll, (void*)"X87", 4ll );
				if( (int64)vr$37 == 0ll) goto label$633;
				label$634:;
				int32 vr$40 = fb_StrCompare( (void*)&TMP$386$4, -1ll, (void*)"FPU", 4ll );
				if( (int64)vr$40 != 0ll) goto label$632;
				label$633:;
				{
					VALUE$3 = 0ll;
				}
				goto label$631;
				label$632:;
				int32 vr$43 = fb_StrCompare( (void*)&TMP$386$4, -1ll, (void*)"SSE", 4ll );
				if( (int64)vr$43 != 0ll) goto label$635;
				label$636:;
				{
					VALUE$3 = 1ll;
				}
				goto label$631;
				label$635:;
				int32 vr$46 = fb_StrCompare( (void*)&TMP$386$4, -1ll, (void*)"NEON", 5ll );
				if( (int64)vr$46 != 0ll) goto label$637;
				label$638:;
				{
					VALUE$3 = 2ll;
				}
				goto label$631;
				label$637:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$639:;
				label$631:;
				fb_StrDelete( (FBSTRING*)&TMP$386$4 );
			}
			FBSETOPTION( 5ll, VALUE$3 );
		}
		goto label$583;
		label$640:;
		{
			FBSETOPTION( 13ll, -1ll );
			FBSETOPTION( 14ll, -1ll );
			FBSETOPTION( 15ll, -1ll );
		}
		goto label$583;
		label$641:;
		{
			{
				FBSTRING TMP$391$4;
				FBSTRING* vr$49 = fb_StrLcase2( (FBSTRING*)ARG$1, 0 );
				fb_StrInit( (void*)&TMP$391$4, -1ll, (void*)vr$49, -1ll, 0 );
				int32 vr$52 = fb_StrCompare( (void*)&TMP$391$4, -1ll, (void*)"gas", 4ll );
				if( (int64)vr$52 != 0ll) goto label$643;
				label$644:;
				{
					*(int64*)((uint8*)&FBC$ + 40ll) = 0ll;
				}
				goto label$642;
				label$643:;
				int32 vr$55 = fb_StrCompare( (void*)&TMP$391$4, -1ll, (void*)"gcc", 4ll );
				if( (int64)vr$55 != 0ll) goto label$645;
				label$646:;
				{
					*(int64*)((uint8*)&FBC$ + 40ll) = 1ll;
				}
				goto label$642;
				label$645:;
				int32 vr$58 = fb_StrCompare( (void*)&TMP$391$4, -1ll, (void*)"clang", 6ll );
				if( (int64)vr$58 != 0ll) goto label$647;
				label$648:;
				{
					*(int64*)((uint8*)&FBC$ + 40ll) = 2ll;
				}
				goto label$642;
				label$647:;
				int32 vr$61 = fb_StrCompare( (void*)&TMP$391$4, -1ll, (void*)"llvm", 5ll );
				if( (int64)vr$61 != 0ll) goto label$649;
				label$650:;
				{
					*(int64*)((uint8*)&FBC$ + 40ll) = 3ll;
				}
				goto label$642;
				label$649:;
				int32 vr$64 = fb_StrCompare( (void*)&TMP$391$4, -1ll, (void*)"gas64", 6ll );
				if( (int64)vr$64 != 0ll) goto label$651;
				label$652:;
				{
					*(int64*)((uint8*)&FBC$ + 40ll) = 4ll;
				}
				goto label$642;
				label$651:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$653:;
				label$642:;
				fb_StrDelete( (FBSTRING*)&TMP$391$4 );
			}
		}
		goto label$583;
		label$654:;
		{
			*(int64*)((uint8*)&FBC$ + 128ll) = -1ll;
		}
		goto label$583;
		label$655:;
		{
			FBSTRING TMP$395$3;
			__builtin_memset( &TMP$395$3, 0, 24ll );
			FBSTRING* vr$68 = PATHSTRIPDIV( ARG$1 );
			fb_StrAssign( (void*)&TMP$395$3, -1ll, (void*)vr$68, -1ll, 0 );
			FBADDINCLUDEPATH( &TMP$395$3 );
			fb_StrDelete( (FBSTRING*)&TMP$395$3 );
		}
		goto label$583;
		label$656:;
		{
			FBADDPREINCLUDE( ARG$1 );
		}
		goto label$583;
		label$657:;
		{
			STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 528ll), ARG$1, 0ll );
		}
		goto label$583;
		label$658:;
		{
			int64 VALUE$3;
			$7FB_LANG vr$74 = FBGETLANGID( (char*)*(char**)ARG$1 );
			VALUE$3 = vr$74;
			if( VALUE$3 != -1ll) goto label$660;
			{
				HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
			}
			label$660:;
			label$659:;
			int64 vr$75 = FBGETOPTION( 11ll );
			if( vr$75 != 0ll) goto label$662;
			{
				FBSETOPTION( 10ll, VALUE$3 );
				*($7FB_LANG*)((uint8*)&FBC$ + 4088ll) = VALUE$3;
				if( IS_SOURCE$1 == 0ll) goto label$664;
				{
					FBSETOPTION( 12ll, VALUE$3 );
				}
				label$664:;
				label$663:;
			}
			label$662:;
			label$661:;
		}
		goto label$583;
		label$665:;
		{
			FBSETOPTION( 0ll, 1ll );
		}
		goto label$583;
		label$666:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 1229ll), 261ll, (void*)ARG$1, -1ll, 0 );
			*(int64*)((uint8*)&FBC$ + 1624ll) = -1ll;
		}
		goto label$583;
		label$667:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 1632ll), 261ll, (void*)ARG$1, -1ll, 0 );
		}
		goto label$583;
		label$668:;
		{
			int64 VALUE$3;
			int32 vr$78 = fb_StrCompare( (void*)ARG$1, -1ll, (void*)"inf", 4ll );
			if( (int64)vr$78 != 0ll) goto label$670;
			{
				VALUE$3 = 2147483647ll;
			}
			goto label$669;
			label$670:;
			{
				int32 vr$80 = fb_VALINT( (FBSTRING*)ARG$1 );
				VALUE$3 = (int64)vr$80;
				if( VALUE$3 > 0ll) goto label$672;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$672:;
				label$671:;
			}
			label$669:;
			FBSETOPTION( 27ll, VALUE$3 );
		}
		goto label$583;
		label$673:;
		{
			FBSETOPTION( 36ll, -1ll );
			*(int64*)((uint8*)&FBC$ + 4096ll) = -1ll;
		}
		goto label$583;
		label$674:;
		{
			*(int64*)((uint8*)&FBC$ + 2744ll) = -1ll;
			*(int64*)((uint8*)&FBC$ + 2752ll) = -1ll;
		}
		goto label$583;
		label$675:;
		{
			FBSETOPTION( 26ll, 0ll );
		}
		goto label$583;
		label$676:;
		{
			FBSTRING TMP$397$3;
			struct $7FBARRAYI8FBSTRINGE LIBS$3;
			*(FBSTRING**)&LIBS$3 = (FBSTRING*)0ull;
			*(FBSTRING**)((uint8*)&LIBS$3 + 8ll) = (FBSTRING*)0ull;
			*(int64*)((uint8*)&LIBS$3 + 16ll) = 0ll;
			*(int64*)((uint8*)&LIBS$3 + 24ll) = 24ll;
			*(int64*)((uint8*)&LIBS$3 + 32ll) = 0ll;
			*(int64*)((uint8*)&LIBS$3 + 40ll) = 8ll;
			__builtin_memset( (void*)((uint8*)&LIBS$3 + 48ll), 0, 192ll );
			__builtin_memset( &TMP$397$3, 0, 24ll );
			fb_StrAssign( (void*)&TMP$397$3, -1ll, (void*)",", 2ll, 0 );
			HSPLITSTR( ARG$1, &TMP$397$3, &LIBS$3 );
			fb_StrDelete( (FBSTRING*)&TMP$397$3 );
			{
				int64 I$4;
				int64 vr$89 = fb_ArrayLBound( (struct $7FBARRAYIKvE*)&LIBS$3, 1ll );
				I$4 = vr$89;
				int64 TMP$398$4;
				int64 vr$91 = fb_ArrayUBound( (struct $7FBARRAYIKvE*)&LIBS$3, 1ll );
				TMP$398$4 = vr$91;
				goto label$677;
				label$680:;
				{
					int64 vr$95 = fb_StrLen( (void*)((I$4 * 24ll) + *(int64*)&LIBS$3), -1ll );
					if( vr$95 <= 0ll) goto label$682;
					{
						STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 704ll), (FBSTRING*)((I$4 * 24ll) + *(int64*)&LIBS$3), 0ll );
					}
					label$682:;
					label$681:;
				}
				label$678:;
				I$4 = I$4 + 1ll;
				label$677:;
				if( I$4 <= TMP$398$4) goto label$680;
				label$679:;
			}
			fb_ArrayStrErase( (struct $7FBARRAYIvE*)&LIBS$3 );
		}
		goto label$583;
		label$683:;
		{
			FBSETOPTION( 40ll, 0ll );
		}
		goto label$583;
		label$684:;
		{
			*(int64*)((uint8*)&FBC$ + 2768ll) = 0ll;
		}
		goto label$583;
		label$685:;
		{
			HCHECKWAITINGOBJFILE(  );
			if( *(struct $9FBCIOFILE**)((uint8*)&FBC$ + 8ll) == (struct $9FBCIOFILE*)0ull) goto label$687;
			{
				fb_StrAssign( *(void**)((uint8*)*(struct $9FBCIOFILE**)((uint8*)&FBC$ + 8ll) + 24ll), -1ll, (void*)ARG$1, -1ll, 0 );
				*(int64*)((uint8*)*(struct $9FBCIOFILE**)((uint8*)&FBC$ + 8ll) + 32ll) = -1ll;
			}
			goto label$686;
			label$687:;
			{
				fb_StrAssign( (void*)((uint8*)&FBC$ + 16ll), -1ll, (void*)ARG$1, -1ll, 0 );
			}
			label$686:;
		}
		goto label$583;
		label$688:;
		{
			int64 VALUE$3;
			int32 vr$105 = fb_StrCompare( (void*)ARG$1, -1ll, (void*)"max", 4ll );
			if( (int64)vr$105 != 0ll) goto label$690;
			{
				VALUE$3 = 3ll;
			}
			goto label$689;
			label$690:;
			{
				int32 vr$107 = fb_VALINT( (FBSTRING*)ARG$1 );
				VALUE$3 = (int64)vr$107;
				if( VALUE$3 >= 0ll) goto label$692;
				{
					VALUE$3 = 0ll;
				}
				goto label$691;
				label$692:;
				if( VALUE$3 <= 3ll) goto label$693;
				{
					VALUE$3 = 3ll;
				}
				label$693:;
				label$691:;
			}
			label$689:;
			FBSETOPTION( 8ll, VALUE$3 );
		}
		goto label$583;
		label$694:;
		{
			FBSTRING TMP$400$3;
			__builtin_memset( &TMP$400$3, 0, 24ll );
			FBSTRING* vr$110 = PATHSTRIPDIV( ARG$1 );
			fb_StrAssign( (void*)&TMP$400$3, -1ll, (void*)vr$110, -1ll, 0 );
			STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 616ll), &TMP$400$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$400$3 );
		}
		goto label$583;
		label$695:;
		{
			FBSETOPTION( 38ll, -1ll );
		}
		goto label$583;
		label$696:;
		{
			FBSETOPTION( 1ll, -1ll );
			*(int64*)((uint8*)&FBC$ + 72ll) = -1ll;
		}
		goto label$583;
		label$697:;
		{
			FBSTRING* vr$115 = PATHSTRIPDIV( ARG$1 );
			fb_StrAssign( (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)vr$115, -1ll, 0 );
			HREPLACESLASH( (char*)((uint8*)&FBC$ + 2776ll), 92ll );
		}
		goto label$583;
		label$698:;
		{
			{
				FBSTRING TMP$401$4;
				fb_StrInit( (void*)&TMP$401$4, -1ll, (void*)ARG$1, -1ll, 0 );
				int32 vr$120 = fb_StrCompare( (void*)&TMP$401$4, -1ll, (void*)"host", 5ll );
				if( (int64)vr$120 != 0ll) goto label$700;
				label$701:;
				{
					*(int64*)((uint8*)&FBC$ + 136ll) = 0ll;
				}
				goto label$699;
				label$700:;
				int32 vr$123 = fb_StrCompare( (void*)&TMP$401$4, -1ll, (void*)"target", 7ll );
				if( (int64)vr$123 != 0ll) goto label$702;
				label$703:;
				{
					*(int64*)((uint8*)&FBC$ + 136ll) = 1ll;
				}
				goto label$699;
				label$702:;
				int32 vr$126 = fb_StrCompare( (void*)&TMP$401$4, -1ll, (void*)"x", 2ll );
				if( (int64)vr$126 != 0ll) goto label$704;
				label$705:;
				{
					*(int64*)((uint8*)&FBC$ + 136ll) = 2ll;
				}
				goto label$699;
				label$704:;
				int32 vr$129 = fb_StrCompare( (void*)&TMP$401$4, -1ll, (void*)"fblibdir", 9ll );
				if( (int64)vr$129 != 0ll) goto label$706;
				label$707:;
				{
					*(int64*)((uint8*)&FBC$ + 136ll) = 3ll;
				}
				goto label$699;
				label$706:;
				int32 vr$132 = fb_StrCompare( (void*)&TMP$401$4, -1ll, (void*)"sha-1", 6ll );
				if( (int64)vr$132 != 0ll) goto label$708;
				label$709:;
				{
					*(int64*)((uint8*)&FBC$ + 136ll) = 4ll;
				}
				goto label$699;
				label$708:;
				int32 vr$135 = fb_StrCompare( (void*)&TMP$401$4, -1ll, (void*)"fork-id", 8ll );
				if( (int64)vr$135 != 0ll) goto label$710;
				label$711:;
				{
					*(int64*)((uint8*)&FBC$ + 136ll) = 5ll;
				}
				goto label$699;
				label$710:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$712:;
				label$699:;
				fb_StrDelete( (FBSTRING*)&TMP$401$4 );
			}
		}
		goto label$583;
		label$713:;
		{
			FBSETOPTION( 24ll, 1ll );
		}
		goto label$583;
		label$714:;
		{
			{
				FBSTRING TMP$408$4;
				fb_StrInit( (void*)&TMP$408$4, -1ll, (void*)ARG$1, -1ll, 0 );
				int32 vr$140 = fb_StrCompare( (void*)&TMP$408$4, -1ll, (void*)"default", 8ll );
				if( (int64)vr$140 == 0ll) goto label$717;
				label$718:;
				int32 vr$143 = fb_StrCompare( (void*)&TMP$408$4, -1ll, (void*)"gmon", 5ll );
				if( (int64)vr$143 != 0ll) goto label$716;
				label$717:;
				{
					FBSETOPTION( 24ll, 1ll );
				}
				goto label$715;
				label$716:;
				int32 vr$146 = fb_StrCompare( (void*)&TMP$408$4, -1ll, (void*)"fb", 3ll );
				if( (int64)vr$146 != 0ll) goto label$719;
				label$720:;
				{
					FBSETOPTION( 24ll, 2ll );
				}
				goto label$715;
				label$719:;
				int32 vr$149 = fb_StrCompare( (void*)&TMP$408$4, -1ll, (void*)"cycles", 7ll );
				if( (int64)vr$149 != 0ll) goto label$721;
				label$722:;
				{
					FBSETOPTION( 24ll, 3ll );
				}
				goto label$715;
				label$721:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$723:;
				label$715:;
				fb_StrDelete( (FBSTRING*)&TMP$408$4 );
			}
		}
		goto label$583;
		label$724:;
		{
			FBSETOPTION( 0ll, 3ll );
			*(int64*)((uint8*)&FBC$ + 72ll) = -1ll;
			*(int64*)((uint8*)&FBC$ + 80ll) = -1ll;
		}
		goto label$583;
		label$725:;
		{
			*(int64*)((uint8*)&FBC$ + 80ll) = -1ll;
		}
		goto label$583;
		label$726:;
		{
			FBSETOPTION( 0ll, 3ll );
			*(int64*)((uint8*)&FBC$ + 88ll) = -1ll;
			*(int64*)((uint8*)&FBC$ + 96ll) = -1ll;
		}
		goto label$583;
		label$727:;
		{
			*(int64*)((uint8*)&FBC$ + 96ll) = -1ll;
		}
		goto label$583;
		label$728:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 1893ll), 129ll, (void*)ARG$1, -1ll, 0 );
			{
				FBSTRING TMP$412$4;
				fb_StrInit( (void*)&TMP$412$4, -1ll, (void*)ARG$1, -1ll, 0 );
				int32 vr$155 = fb_StrCompare( (void*)&TMP$412$4, -1ll, (void*)"gui", 4ll );
				if( (int64)vr$155 != 0ll) goto label$730;
				label$731:;
				{
					FBSETOPTION( 42ll, 1ll );
				}
				label$730:;
				label$729:;
				fb_StrDelete( (FBSTRING*)&TMP$412$4 );
			}
		}
		goto label$583;
		label$732:;
		{
			FBSETOPTION( 41ll, -1ll );
		}
		goto label$583;
		label$733:;
		{
			*(int64*)((uint8*)&FBC$ + 2760ll) = -1ll;
		}
		goto label$583;
		label$734:;
		{
			*(int64*)((uint8*)&FBC$ + 2768ll) = -1ll;
		}
		goto label$583;
		label$735:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 2354ll), 261ll, (void*)ARG$1, -1ll, 0 );
		}
		goto label$583;
		label$736:;
		{
			int32 vr$159 = fb_VALINT( (FBSTRING*)ARG$1 );
			FBSETOPTION( 39ll, (int64)vr$159 << (10ll & 63ll) );
		}
		goto label$583;
		label$737:;
		{
			int64 OS$3;
			__builtin_memset( &OS$3, 0, 8ll );
			int64 CPUTYPE$3;
			__builtin_memset( &CPUTYPE$3, 0, 8ll );
			int64 IS_GNU_TRIPLET$3;
			__builtin_memset( &IS_GNU_TRIPLET$3, 0, 8ll );
			HPARSETARGETARG( ARG$1, &OS$3, &CPUTYPE$3, &IS_GNU_TRIPLET$3 );
			if( ((int64)-(OS$3 < 0ll) | (int64)-(CPUTYPE$3 < 0ll)) == 0ll) goto label$739;
			{
				HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
			}
			label$739:;
			label$738:;
			FBSETOPTION( 3ll, OS$3 );
			FBSETOPTION( 4ll, CPUTYPE$3 );
			if( (((int64)-(OS$3 != 0ll) | (int64)-(CPUTYPE$3 != 19ll)) | IS_GNU_TRIPLET$3) == 0ll) goto label$741;
			{
				FBSTRING TMP$413$4;
				fb_StrAssign( (void*)((uint8*)&FBC$ + 2096ll), 129ll, (void*)ARG$1, -1ll, 0 );
				__builtin_memset( &TMP$413$4, 0, 24ll );
				FBSTRING* vr$179 = fb_StrConcat( &TMP$413$4, (void*)((uint8*)&FBC$ + 2096ll), 129ll, (void*)"-", 2ll );
				fb_StrAssign( (void*)((uint8*)&FBC$ + 2225ll), 129ll, (void*)vr$179, -1ll, 0 );
			}
			label$741:;
			label$740:;
		}
		goto label$583;
		label$742:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 2615ll), 129ll, (void*)ARG$1, -1ll, 0 );
		}
		goto label$583;
		label$743:;
		{
			*(int64*)((uint8*)&FBC$ + 112ll) = -1ll;
		}
		goto label$583;
		label$744:;
		{
			int64 VALUE$3;
			{
				FBSTRING TMP$414$4;
				FBSTRING* vr$182 = fb_StrUcase2( (FBSTRING*)ARG$1, 0 );
				fb_StrInit( (void*)&TMP$414$4, -1ll, (void*)vr$182, -1ll, 0 );
				int32 vr$185 = fb_StrCompare( (void*)&TMP$414$4, -1ll, (void*)"NONE", 5ll );
				if( (int64)vr$185 == 0ll) goto label$747;
				label$748:;
				int32 vr$188 = fb_StrCompare( (void*)&TMP$414$4, -1ll, (void*)"0", 2ll );
				if( (int64)vr$188 != 0ll) goto label$746;
				label$747:;
				{
					VALUE$3 = 0ll;
				}
				goto label$745;
				label$746:;
				int32 vr$191 = fb_StrCompare( (void*)&TMP$414$4, -1ll, (void*)"1", 2ll );
				if( (int64)vr$191 != 0ll) goto label$749;
				label$750:;
				{
					VALUE$3 = 1ll;
				}
				goto label$745;
				label$749:;
				int32 vr$194 = fb_StrCompare( (void*)&TMP$414$4, -1ll, (void*)"2", 2ll );
				if( (int64)vr$194 != 0ll) goto label$751;
				label$752:;
				{
					VALUE$3 = 2ll;
				}
				goto label$745;
				label$751:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$753:;
				label$745:;
				fb_StrDelete( (FBSTRING*)&TMP$414$4 );
			}
			FBSETOPTION( 7ll, VALUE$3 );
		}
		goto label$583;
		label$754:;
		{
			if( IS_SOURCE$1 == 0ll) goto label$756;
			{
				if( *(int64*)((uint8*)&FBC$ + 120ll) != 0ll) goto label$758;
				{
					HPRINTVERSION( *(int64*)((uint8*)&FBC$ + 112ll) );
				}
				label$758:;
				label$757:;
			}
			label$756:;
			label$755:;
			*(int64*)((uint8*)&FBC$ + 120ll) = -1ll;
		}
		goto label$583;
		label$759:;
		{
			int64 VALUE$3;
			VALUE$3 = -1ll;
			{
				FBSTRING TMP$417$4;
				fb_StrInit( (void*)&TMP$417$4, -1ll, (void*)ARG$1, -1ll, 0 );
				int32 vr$199 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"all", 4ll );
				if( (int64)vr$199 != 0ll) goto label$761;
				label$762:;
				{
					VALUE$3 = 0ll;
				}
				goto label$760;
				label$761:;
				int32 vr$202 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"none", 5ll );
				if( (int64)vr$202 != 0ll) goto label$763;
				label$764:;
				{
					VALUE$3 = 4ll;
				}
				goto label$760;
				label$763:;
				int32 vr$205 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"param", 6ll );
				if( (int64)vr$205 != 0ll) goto label$765;
				label$766:;
				{
					int64 vr$207 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$207 | 2ll );
				}
				goto label$760;
				label$765:;
				int32 vr$210 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"escape", 7ll );
				if( (int64)vr$210 != 0ll) goto label$767;
				label$768:;
				{
					int64 vr$212 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$212 | 1ll );
				}
				goto label$760;
				label$767:;
				int32 vr$215 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"next", 5ll );
				if( (int64)vr$215 != 0ll) goto label$769;
				label$770:;
				{
					int64 vr$217 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$217 | 8ll );
				}
				goto label$760;
				label$769:;
				int32 vr$220 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"signedness", 11ll );
				if( (int64)vr$220 != 0ll) goto label$771;
				label$772:;
				{
					int64 vr$222 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$222 | 32ll );
				}
				goto label$760;
				label$771:;
				int32 vr$225 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"constness", 10ll );
				if( (int64)vr$225 != 0ll) goto label$773;
				label$774:;
				{
					int64 vr$227 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$227 | 128ll );
					VALUE$3 = 0ll;
				}
				goto label$760;
				label$773:;
				int32 vr$230 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"funcptr", 8ll );
				if( (int64)vr$230 != 0ll) goto label$775;
				label$776:;
				{
					int64 vr$232 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$232 | 64ll );
					VALUE$3 = 0ll;
				}
				goto label$760;
				label$775:;
				int32 vr$235 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"suffix", 7ll );
				if( (int64)vr$235 != 0ll) goto label$777;
				label$778:;
				{
					int64 vr$237 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$237 | 256ll );
				}
				goto label$760;
				label$777:;
				int32 vr$240 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"pedantic", 9ll );
				if( (int64)vr$240 != 0ll) goto label$779;
				label$780:;
				{
					FBSETOPTION( 28ll, 4294965527ll );
					if( VALUE$3 <= 1ll) goto label$782;
					{
						VALUE$3 = 1ll;
					}
					label$782:;
					label$781:;
				}
				goto label$760;
				label$779:;
				int32 vr$243 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"error", 6ll );
				if( (int64)vr$243 != 0ll) goto label$783;
				label$784:;
				{
					int64 vr$245 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$245 | 512ll );
				}
				goto label$760;
				label$783:;
				int32 vr$248 = fb_StrCompare( (void*)&TMP$417$4, -1ll, (void*)"upcast", 7ll );
				if( (int64)vr$248 != 0ll) goto label$785;
				label$786:;
				{
					int64 vr$250 = FBGETOPTION( 28ll );
					FBSETOPTION( 28ll, vr$250 | 1024ll );
				}
				goto label$760;
				label$785:;
				{
					int32 vr$252 = fb_VALINT( (FBSTRING*)ARG$1 );
					VALUE$3 = (int64)vr$252;
				}
				label$787:;
				label$760:;
				fb_StrDelete( (FBSTRING*)&TMP$417$4 );
			}
			if( VALUE$3 < 0ll) goto label$789;
			{
				FBSETOPTION( 25ll, VALUE$3 );
			}
			label$789:;
			label$788:;
		}
		goto label$583;
		label$790:;
		{
			FBSTRING TMP$430$3;
			FBSTRING TMP$431$3;
			FBSTRING TMP$432$3;
			FBSTRING* vr$256 = HREPLACE( (char*)*(char**)ARG$1, (char*)",", (char*)" " );
			__builtin_memset( &TMP$430$3, 0, 24ll );
			FBSTRING* vr$259 = fb_StrConcat( &TMP$430$3, (void*)" ", 2ll, (void*)vr$256, -1ll );
			__builtin_memset( &TMP$431$3, 0, 24ll );
			FBSTRING* vr$262 = fb_StrConcat( &TMP$431$3, (void*)vr$259, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$432$3, 0, 24ll );
			FBSTRING* vr$266 = fb_StrConcat( &TMP$432$3, (void*)((uint8*)&FBC$ + 2024ll), -1ll, (void*)vr$262, -1ll );
			fb_StrAssign( (void*)((uint8*)&FBC$ + 2024ll), -1ll, (void*)vr$266, -1ll, 0 );
		}
		goto label$583;
		label$791:;
		{
			FBSTRING TMP$433$3;
			FBSTRING TMP$434$3;
			FBSTRING TMP$435$3;
			FBSTRING* vr$269 = HREPLACE( (char*)*(char**)ARG$1, (char*)",", (char*)" " );
			__builtin_memset( &TMP$433$3, 0, 24ll );
			FBSTRING* vr$272 = fb_StrConcat( &TMP$433$3, (void*)" ", 2ll, (void*)vr$269, -1ll );
			__builtin_memset( &TMP$434$3, 0, 24ll );
			FBSTRING* vr$275 = fb_StrConcat( &TMP$434$3, (void*)vr$272, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$435$3, 0, 24ll );
			FBSTRING* vr$279 = fb_StrConcat( &TMP$435$3, (void*)((uint8*)&FBC$ + 2072ll), -1ll, (void*)vr$275, -1ll );
			fb_StrAssign( (void*)((uint8*)&FBC$ + 2072ll), -1ll, (void*)vr$279, -1ll, 0 );
		}
		goto label$583;
		label$792:;
		{
			FBSTRING TMP$436$3;
			FBSTRING TMP$437$3;
			FBSTRING TMP$438$3;
			FBSTRING* vr$282 = HREPLACE( (char*)*(char**)ARG$1, (char*)",", (char*)" " );
			__builtin_memset( &TMP$436$3, 0, 24ll );
			FBSTRING* vr$285 = fb_StrConcat( &TMP$436$3, (void*)" ", 2ll, (void*)vr$282, -1ll );
			__builtin_memset( &TMP$437$3, 0, 24ll );
			FBSTRING* vr$288 = fb_StrConcat( &TMP$437$3, (void*)vr$285, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$438$3, 0, 24ll );
			FBSTRING* vr$292 = fb_StrConcat( &TMP$438$3, (void*)((uint8*)&FBC$ + 2048ll), -1ll, (void*)vr$288, -1ll );
			fb_StrAssign( (void*)((uint8*)&FBC$ + 2048ll), -1ll, (void*)vr$292, -1ll, 0 );
		}
		goto label$583;
		label$793:;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 968ll), 261ll, (void*)ARG$1, -1ll, 0 );
		}
		goto label$583;
		label$794:;
		{
			{
				FBSTRING TMP$439$4;
				FBSTRING* vr$295 = fb_StrLcase2( (FBSTRING*)ARG$1, 0 );
				fb_StrInit( (void*)&TMP$439$4, -1ll, (void*)vr$295, -1ll, 0 );
				int32 vr$298 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"gosub-setjmp", 13ll );
				if( (int64)vr$298 != 0ll) goto label$796;
				label$797:;
				{
					FBSETOPTION( 29ll, -1ll );
				}
				goto label$795;
				label$796:;
				int32 vr$301 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"valist-as-ptr", 14ll );
				if( (int64)vr$301 != 0ll) goto label$798;
				label$799:;
				{
					FBSETOPTION( 30ll, -1ll );
				}
				goto label$795;
				label$798:;
				int32 vr$304 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"no-thiscall", 12ll );
				if( (int64)vr$304 != 0ll) goto label$800;
				label$801:;
				{
					FBSETOPTION( 31ll, -1ll );
				}
				goto label$795;
				label$800:;
				int32 vr$307 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"no-fastcall", 12ll );
				if( (int64)vr$307 != 0ll) goto label$802;
				label$803:;
				{
					FBSETOPTION( 32ll, -1ll );
				}
				goto label$795;
				label$802:;
				int32 vr$310 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"fbrt", 5ll );
				if( (int64)vr$310 != 0ll) goto label$804;
				label$805:;
				{
					FBSETOPTION( 33ll, -1ll );
				}
				goto label$795;
				label$804:;
				int32 vr$313 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"nocmdline", 10ll );
				if( (int64)vr$313 != 0ll) goto label$806;
				label$807:;
				{
					FBSETOPTION( 43ll, -1ll );
				}
				goto label$795;
				label$806:;
				int32 vr$316 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"retinflts", 10ll );
				if( (int64)vr$316 != 0ll) goto label$808;
				label$809:;
				{
					FBSETOPTION( 44ll, -1ll );
				}
				goto label$795;
				label$808:;
				int32 vr$319 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"nobuiltins", 11ll );
				if( (int64)vr$319 != 0ll) goto label$810;
				label$811:;
				{
					FBSETOPTION( 45ll, -1ll );
				}
				goto label$795;
				label$810:;
				int32 vr$322 = fb_StrCompare( (void*)&TMP$439$4, -1ll, (void*)"optabstract", 12ll );
				if( (int64)vr$322 != 0ll) goto label$812;
				label$813:;
				{
					FBSETOPTION( 46ll, -1ll );
				}
				goto label$795;
				label$812:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$814:;
				label$795:;
				fb_StrDelete( (FBSTRING*)&TMP$439$4 );
			}
		}
		goto label$583;
		label$584:;
		static const void* tmp$896[74ll] = {
			&&label$585,
			&&label$586,
			&&label$589,
			&&label$596,
			&&label$597,
			&&label$598,
			&&label$599,
			&&label$600,
			&&label$601,
			&&label$601,
			&&label$602,
			&&label$603,
			&&label$604,
			&&label$605,
			&&label$606,
			&&label$607,
			&&label$608,
			&&label$609,
			&&label$610,
			&&label$611,
			&&label$612,
			&&label$613,
			&&label$614,
			&&label$615,
			&&label$616,
			&&label$623,
			&&label$630,
			&&label$640,
			&&label$641,
			&&label$654,
			&&label$655,
			&&label$656,
			&&label$657,
			&&label$658,
			&&label$665,
			&&label$666,
			&&label$667,
			&&label$668,
			&&label$673,
			&&label$674,
			&&label$675,
			&&label$676,
			&&label$683,
			&&label$684,
			&&label$685,
			&&label$688,
			&&label$694,
			&&label$695,
			&&label$696,
			&&label$697,
			&&label$698,
			&&label$714,
			&&label$713,
			&&label$724,
			&&label$725,
			&&label$726,
			&&label$727,
			&&label$728,
			&&label$732,
			&&label$733,
			&&label$734,
			&&label$735,
			&&label$736,
			&&label$737,
			&&label$742,
			&&label$743,
			&&label$744,
			&&label$754,
			&&label$759,
			&&label$790,
			&&label$791,
			&&label$792,
			&&label$793,
			&&label$794,
		};
		if( TMP$375$2 > 73ull ) goto label$583;
		goto *tmp$896[TMP$375$2 - 0ull];
		label$583:;
	}
	label$582:;
}

static int64 PARSEOPTION( char* OPT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$815:;
	{
		uint64 TMP$449$2;
		TMP$449$2 = (uint64)*(uint8*)OPT$1;
		goto label$818;
		label$819:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$821;
			{
				fb$result$1 = 0ll;
				goto label$816;
			}
			label$821:;
			label$820:;
			int32 vr$5 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"arch", 5ll );
			if( (int64)vr$5 != 0ll) goto label$823;
			{
				fb$result$1 = 1ll;
				goto label$816;
			}
			label$823:;
			label$822:;
			int32 vr$7 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"asm", 4ll );
			if( (int64)vr$7 != 0ll) goto label$825;
			{
				fb$result$1 = 2ll;
				goto label$816;
			}
			label$825:;
			label$824:;
		}
		goto label$817;
		label$826:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$828;
			{
				fb$result$1 = 3ll;
				goto label$816;
			}
			label$828:;
			label$827:;
			int32 vr$11 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"buildprefix", 12ll );
			if( (int64)vr$11 != 0ll) goto label$830;
			{
				fb$result$1 = 4ll;
				goto label$816;
			}
			label$830:;
			label$829:;
		}
		goto label$817;
		label$831:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$833;
			{
				fb$result$1 = 5ll;
				goto label$816;
			}
			label$833:;
			label$832:;
		}
		goto label$817;
		label$834:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$836;
			{
				fb$result$1 = 6ll;
				goto label$816;
			}
			label$836:;
			label$835:;
		}
		goto label$817;
		label$837:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$839;
			{
				fb$result$1 = 7ll;
				goto label$816;
			}
			label$839:;
			label$838:;
			int32 vr$19 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"dll", 4ll );
			if( (int64)vr$19 != 0ll) goto label$841;
			{
				fb$result$1 = 8ll;
				goto label$816;
			}
			label$841:;
			label$840:;
			int32 vr$21 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"dylib", 6ll );
			if( (int64)vr$21 != 0ll) goto label$843;
			{
				fb$result$1 = 9ll;
				goto label$816;
			}
			label$843:;
			label$842:;
		}
		goto label$817;
		label$844:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$846;
			{
				fb$result$1 = 10ll;
				goto label$816;
			}
			label$846:;
			label$845:;
			int32 vr$25 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"ex", 3ll );
			if( (int64)vr$25 != 0ll) goto label$848;
			{
				fb$result$1 = 20ll;
				goto label$816;
			}
			label$848:;
			label$847:;
			int32 vr$27 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"earray", 7ll );
			if( (int64)vr$27 != 0ll) goto label$850;
			{
				fb$result$1 = 11ll;
				goto label$816;
			}
			label$850:;
			label$849:;
			int32 vr$29 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"earraydims", 11ll );
			if( (int64)vr$29 != 0ll) goto label$852;
			{
				fb$result$1 = 12ll;
				goto label$816;
			}
			label$852:;
			label$851:;
			int32 vr$31 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"eassert", 8ll );
			if( (int64)vr$31 != 0ll) goto label$854;
			{
				fb$result$1 = 13ll;
				goto label$816;
			}
			label$854:;
			label$853:;
			int32 vr$33 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"edebug", 7ll );
			if( (int64)vr$33 != 0ll) goto label$856;
			{
				fb$result$1 = 14ll;
				goto label$816;
			}
			label$856:;
			label$855:;
			int32 vr$35 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"edebuginfo", 11ll );
			if( (int64)vr$35 != 0ll) goto label$858;
			{
				fb$result$1 = 15ll;
				goto label$816;
			}
			label$858:;
			label$857:;
			int32 vr$37 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"elocation", 10ll );
			if( (int64)vr$37 != 0ll) goto label$860;
			{
				fb$result$1 = 16ll;
				goto label$816;
			}
			label$860:;
			label$859:;
			int32 vr$39 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"enullptr", 9ll );
			if( (int64)vr$39 != 0ll) goto label$862;
			{
				fb$result$1 = 17ll;
				goto label$816;
			}
			label$862:;
			label$861:;
			int32 vr$41 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"eunwind", 8ll );
			if( (int64)vr$41 != 0ll) goto label$864;
			{
				fb$result$1 = 18ll;
				goto label$816;
			}
			label$864:;
			label$863:;
			int32 vr$43 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"entry", 6ll );
			if( (int64)vr$43 != 0ll) goto label$866;
			{
				fb$result$1 = 19ll;
				goto label$816;
			}
			label$866:;
			label$865:;
			int32 vr$45 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"exx", 4ll );
			if( (int64)vr$45 != 0ll) goto label$868;
			{
				fb$result$1 = 21ll;
				goto label$816;
			}
			label$868:;
			label$867:;
			int32 vr$47 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"export", 7ll );
			if( (int64)vr$47 != 0ll) goto label$870;
			{
				fb$result$1 = 22ll;
				goto label$816;
			}
			label$870:;
			label$869:;
		}
		goto label$817;
		label$871:;
		{
			int32 vr$49 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"fbgfx", 6ll );
			if( (int64)vr$49 != 0ll) goto label$873;
			{
				fb$result$1 = 23ll;
				goto label$816;
			}
			label$873:;
			label$872:;
			int32 vr$51 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"forcelang", 10ll );
			if( (int64)vr$51 != 0ll) goto label$875;
			{
				fb$result$1 = 24ll;
				goto label$816;
			}
			label$875:;
			label$874:;
			int32 vr$53 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"fpmode", 7ll );
			if( (int64)vr$53 != 0ll) goto label$877;
			{
				fb$result$1 = 25ll;
				goto label$816;
			}
			label$877:;
			label$876:;
			int32 vr$55 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"fpu", 4ll );
			if( (int64)vr$55 != 0ll) goto label$879;
			{
				fb$result$1 = 26ll;
				goto label$816;
			}
			label$879:;
			label$878:;
		}
		goto label$817;
		label$880:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$882;
			{
				fb$result$1 = 27ll;
				goto label$816;
			}
			label$882:;
			label$881:;
			int32 vr$59 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"gen", 4ll );
			if( (int64)vr$59 != 0ll) goto label$884;
			{
				fb$result$1 = 28ll;
				goto label$816;
			}
			label$884:;
			label$883:;
		}
		goto label$817;
		label$885:;
		{
			int32 vr$61 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"help", 5ll );
			if( (int64)vr$61 != 0ll) goto label$887;
			{
				fb$result$1 = 29ll;
				goto label$816;
			}
			label$887:;
			label$886:;
		}
		goto label$817;
		label$888:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$890;
			{
				fb$result$1 = 30ll;
				goto label$816;
			}
			label$890:;
			label$889:;
			int32 vr$65 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"include", 8ll );
			if( (int64)vr$65 != 0ll) goto label$892;
			{
				fb$result$1 = 31ll;
				goto label$816;
			}
			label$892:;
			label$891:;
		}
		goto label$817;
		label$893:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$895;
			{
				fb$result$1 = 32ll;
				goto label$816;
			}
			label$895:;
			label$894:;
			int32 vr$69 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"lang", 5ll );
			if( (int64)vr$69 != 0ll) goto label$897;
			{
				fb$result$1 = 33ll;
				goto label$816;
			}
			label$897:;
			label$896:;
			int32 vr$71 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"lib", 4ll );
			if( (int64)vr$71 != 0ll) goto label$899;
			{
				fb$result$1 = 34ll;
				goto label$816;
			}
			label$899:;
			label$898:;
		}
		goto label$817;
		label$900:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$902;
			{
				fb$result$1 = 35ll;
				goto label$816;
			}
			label$902:;
			label$901:;
			int32 vr$75 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"map", 4ll );
			if( (int64)vr$75 != 0ll) goto label$904;
			{
				fb$result$1 = 36ll;
				goto label$816;
			}
			label$904:;
			label$903:;
			int32 vr$77 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"maxerr", 7ll );
			if( (int64)vr$77 != 0ll) goto label$906;
			{
				fb$result$1 = 37ll;
				goto label$816;
			}
			label$906:;
			label$905:;
			int32 vr$79 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"mt", 3ll );
			if( (int64)vr$79 != 0ll) goto label$908;
			{
				fb$result$1 = 38ll;
				goto label$816;
			}
			label$908:;
			label$907:;
		}
		goto label$817;
		label$909:;
		{
			int32 vr$81 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"noerrline", 10ll );
			if( (int64)vr$81 != 0ll) goto label$911;
			{
				fb$result$1 = 40ll;
				goto label$816;
			}
			label$911:;
			label$910:;
			int32 vr$83 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"nodeflibs", 10ll );
			if( (int64)vr$83 != 0ll) goto label$913;
			{
				fb$result$1 = 39ll;
				goto label$816;
			}
			label$913:;
			label$912:;
			int32 vr$85 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"nolib", 6ll );
			if( (int64)vr$85 != 0ll) goto label$915;
			{
				fb$result$1 = 41ll;
				goto label$816;
			}
			label$915:;
			label$914:;
			int32 vr$87 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"noobjinfo", 10ll );
			if( (int64)vr$87 != 0ll) goto label$917;
			{
				fb$result$1 = 42ll;
				goto label$816;
			}
			label$917:;
			label$916:;
			int32 vr$89 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"nostrip", 8ll );
			if( (int64)vr$89 != 0ll) goto label$919;
			{
				fb$result$1 = 43ll;
				goto label$816;
			}
			label$919:;
			label$918:;
		}
		goto label$817;
		label$920:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$922;
			{
				fb$result$1 = 44ll;
				goto label$816;
			}
			label$922:;
			label$921:;
		}
		goto label$817;
		label$923:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$925;
			{
				fb$result$1 = 45ll;
				goto label$816;
			}
			label$925:;
			label$924:;
		}
		goto label$817;
		label$926:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$928;
			{
				fb$result$1 = 46ll;
				goto label$816;
			}
			label$928:;
			label$927:;
			int32 vr$97 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"pic", 4ll );
			if( (int64)vr$97 != 0ll) goto label$930;
			{
				fb$result$1 = 47ll;
				goto label$816;
			}
			label$930:;
			label$929:;
			int32 vr$99 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"pp", 3ll );
			if( (int64)vr$99 != 0ll) goto label$932;
			{
				fb$result$1 = 48ll;
				goto label$816;
			}
			label$932:;
			label$931:;
			int32 vr$101 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"prefix", 7ll );
			if( (int64)vr$101 != 0ll) goto label$934;
			{
				fb$result$1 = 49ll;
				goto label$816;
			}
			label$934:;
			label$933:;
			int32 vr$103 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"print", 6ll );
			if( (int64)vr$103 != 0ll) goto label$936;
			{
				fb$result$1 = 50ll;
				goto label$816;
			}
			label$936:;
			label$935:;
			int32 vr$105 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"profile", 8ll );
			if( (int64)vr$105 != 0ll) goto label$938;
			{
				fb$result$1 = 52ll;
				goto label$816;
			}
			label$938:;
			label$937:;
			int32 vr$107 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"profgen", 8ll );
			if( (int64)vr$107 != 0ll) goto label$940;
			{
				fb$result$1 = 51ll;
				goto label$816;
			}
			label$940:;
			label$939:;
		}
		goto label$817;
		label$941:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$943;
			{
				fb$result$1 = 53ll;
				goto label$816;
			}
			label$943:;
			label$942:;
			int32 vr$111 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"rr", 3ll );
			if( (int64)vr$111 != 0ll) goto label$945;
			{
				fb$result$1 = 55ll;
				goto label$816;
			}
			label$945:;
			label$944:;
		}
		goto label$817;
		label$946:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$948;
			{
				fb$result$1 = 54ll;
				goto label$816;
			}
			label$948:;
			label$947:;
			int32 vr$115 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"RR", 3ll );
			if( (int64)vr$115 != 0ll) goto label$950;
			{
				fb$result$1 = 56ll;
				goto label$816;
			}
			label$950:;
			label$949:;
		}
		goto label$817;
		label$951:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$953;
			{
				fb$result$1 = 57ll;
				goto label$816;
			}
			label$953:;
			label$952:;
			int32 vr$119 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"showincludes", 13ll );
			if( (int64)vr$119 != 0ll) goto label$955;
			{
				fb$result$1 = 58ll;
				goto label$816;
			}
			label$955:;
			label$954:;
			int32 vr$121 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"static", 7ll );
			if( (int64)vr$121 != 0ll) goto label$957;
			{
				fb$result$1 = 59ll;
				goto label$816;
			}
			label$957:;
			label$956:;
			int32 vr$123 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"strip", 6ll );
			if( (int64)vr$123 != 0ll) goto label$959;
			{
				fb$result$1 = 60ll;
				goto label$816;
			}
			label$959:;
			label$958:;
			int32 vr$125 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"sysroot", 8ll );
			if( (int64)vr$125 != 0ll) goto label$961;
			{
				fb$result$1 = 61ll;
				goto label$816;
			}
			label$961:;
			label$960:;
		}
		goto label$817;
		label$962:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$964;
			{
				fb$result$1 = 62ll;
				goto label$816;
			}
			label$964:;
			label$963:;
			int32 vr$129 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"target", 7ll );
			if( (int64)vr$129 != 0ll) goto label$966;
			{
				fb$result$1 = 63ll;
				goto label$816;
			}
			label$966:;
			label$965:;
			int32 vr$131 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"title", 6ll );
			if( (int64)vr$131 != 0ll) goto label$968;
			{
				fb$result$1 = 64ll;
				goto label$816;
			}
			label$968:;
			label$967:;
		}
		goto label$817;
		label$969:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$971;
			{
				fb$result$1 = 65ll;
				goto label$816;
			}
			label$971:;
			label$970:;
			int32 vr$135 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"vec", 4ll );
			if( (int64)vr$135 != 0ll) goto label$973;
			{
				fb$result$1 = 66ll;
				goto label$816;
			}
			label$973:;
			label$972:;
			int32 vr$137 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"version", 8ll );
			if( (int64)vr$137 != 0ll) goto label$975;
			{
				fb$result$1 = 67ll;
				goto label$816;
			}
			label$975:;
			label$974:;
		}
		goto label$817;
		label$976:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$978;
			{
				fb$result$1 = 68ll;
				goto label$816;
			}
			label$978:;
			label$977:;
		}
		goto label$817;
		label$979:;
		{
			int32 vr$141 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"Wa", 3ll );
			if( (int64)vr$141 != 0ll) goto label$981;
			{
				fb$result$1 = 69ll;
				goto label$816;
			}
			label$981:;
			label$980:;
			int32 vr$143 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"Wl", 3ll );
			if( (int64)vr$143 != 0ll) goto label$983;
			{
				fb$result$1 = 71ll;
				goto label$816;
			}
			label$983:;
			label$982:;
			int32 vr$145 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"Wc", 3ll );
			if( (int64)vr$145 != 0ll) goto label$985;
			{
				fb$result$1 = 70ll;
				goto label$816;
			}
			label$985:;
			label$984:;
		}
		goto label$817;
		label$986:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$988;
			{
				fb$result$1 = 72ll;
				goto label$816;
			}
			label$988:;
			label$987:;
		}
		goto label$817;
		label$989:;
		{
			if( (int64)*(uint8*)((uint8*)OPT$1 + 1ll) != 0ll) goto label$991;
			{
				fb$result$1 = 73ll;
				goto label$816;
			}
			label$991:;
			label$990:;
		}
		goto label$817;
		label$992:;
		{
			int32 vr$151 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"-version", 9ll );
			if( (int64)vr$151 != 0ll) goto label$994;
			{
				fb$result$1 = 67ll;
				goto label$816;
			}
			label$994:;
			label$993:;
			int32 vr$153 = fb_StrCompare( (void*)OPT$1, 0ll, (void*)"-help", 6ll );
			if( (int64)vr$153 != 0ll) goto label$996;
			{
				fb$result$1 = 29ll;
				goto label$816;
			}
			label$996:;
			label$995:;
		}
		goto label$817;
		label$818:;
		static const void* tmp$897[78ll] = {
			&&label$992,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$834,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$923,
			&&label$817,
			&&label$817,
			&&label$946,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$979,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$817,
			&&label$819,
			&&label$826,
			&&label$831,
			&&label$837,
			&&label$844,
			&&label$871,
			&&label$880,
			&&label$885,
			&&label$888,
			&&label$817,
			&&label$817,
			&&label$893,
			&&label$900,
			&&label$909,
			&&label$920,
			&&label$926,
			&&label$817,
			&&label$941,
			&&label$951,
			&&label$962,
			&&label$817,
			&&label$969,
			&&label$976,
			&&label$986,
			&&label$817,
			&&label$989,
		};
		if( (TMP$449$2 - 45ull) > 77ull ) goto label$817;
		goto *tmp$897[TMP$449$2 - 45ull];
		label$817:;
	}
	fb$result$1 = -1ll;
	goto label$816;
	label$816:;
	return fb$result$1;
}

static void HANDLEARG( FBSTRING* ARG$1, int64 IS_SOURCE$1, int64 IS_FILE$1 )
{
	label$997:;
	if( *(int64*)&FBC$ < 0ll) goto label$1000;
	{
		int64 vr$0 = fb_StrLen( (void*)ARG$1, -1ll );
		if( vr$0 != 0ll) goto label$1002;
		{
			HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
		}
		label$1002:;
		label$1001:;
		HANDLEOPT( *(int64*)&FBC$, ARG$1, IS_SOURCE$1 );
		*(int64*)&FBC$ = -1ll;
		goto label$998;
	}
	label$1000:;
	label$999:;
	int64 vr$1 = fb_StrLen( (void*)ARG$1, -1ll );
	if( vr$1 != 0ll) goto label$1004;
	{
		goto label$998;
	}
	label$1004:;
	label$1003:;
	{
		uint8 TMP$527$2;
		TMP$527$2 = *(uint8*)*(char**)ARG$1;
		if( (uint64)(int64)TMP$527$2 != 45ull) goto label$1006;
		label$1007:;
		{
			char* OPT$3;
			OPT$3 = (char*)((uint8*)*(char**)ARG$1 + 1ll);
			if( (int64)*(uint8*)OPT$3 != 0ll) goto label$1009;
			{
				HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
			}
			label$1009:;
			label$1008:;
			int64 OPTID$3;
			int64 vr$9 = PARSEOPTION( OPT$3 );
			OPTID$3 = vr$9;
			if( OPTID$3 >= 0ll) goto label$1011;
			{
				HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
			}
			label$1011:;
			label$1010:;
			if( IS_SOURCE$1 == 0ll) goto label$1013;
			{
				if( (boolean)(*(boolean*)(((int64)(struct $18FBC_CMDLINE_OPTION*)CMDLINEOPTIONTB$ + (OPTID$3 << (4ll & 63ll))) + 1ll) == 0ll) == (boolean)0ll) goto label$1015;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$1015:;
				label$1014:;
			}
			label$1013:;
			label$1012:;
			if( *(boolean*)((int64)(struct $18FBC_CMDLINE_OPTION*)CMDLINEOPTIONTB$ + (OPTID$3 << (4ll & 63ll))) == (boolean)0ll) goto label$1017;
			{
				*(int64*)&FBC$ = OPTID$3;
			}
			goto label$1016;
			label$1017:;
			{
				HANDLEOPT( OPTID$3, ARG$1, IS_SOURCE$1 );
			}
			label$1016:;
			if( IS_SOURCE$1 == 0ll) goto label$1019;
			{
				if( *(boolean*)(((int64)(struct $18FBC_CMDLINE_OPTION*)CMDLINEOPTIONTB$ + (OPTID$3 << (4ll & 63ll))) + 2ll) == (boolean)0ll) goto label$1021;
				{
					FBRESTARTBEGINREQUEST( 2ll );
				}
				label$1021:;
				label$1020:;
				if( *(int64*)(((int64)(struct $18FBC_CMDLINE_OPTION*)CMDLINEOPTIONTB$ + (OPTID$3 << (4ll & 63ll))) + 8ll) == 0ll) goto label$1023;
				{
					FBRESTARTBEGINREQUEST( 8ll );
				}
				label$1023:;
				label$1022:;
			}
			label$1019:;
			label$1018:;
		}
		goto label$1005;
		label$1006:;
		if( (uint64)(int64)TMP$527$2 != 64ull) goto label$1024;
		label$1025:;
		{
			static int64 RECLEVEL$3 = 0ll;
			if( RECLEVEL$3 <= 128ll) goto label$1027;
			{
				ERRREPORTEX( 27ll, (char*)*(char**)ARG$1, -1ll, 1ll, (char*)0ull );
				FBCEND( 1ll );
			}
			label$1027:;
			label$1026:;
			int64 vr$17 = fb_StrLen( (void*)ARG$1, -1ll );
			FBSTRING* vr$19 = fb_RIGHT( (FBSTRING*)ARG$1, vr$17 + -1ll );
			fb_StrAssign( (void*)ARG$1, -1ll, (void*)vr$19, -1ll, 0 );
			int64 vr$20 = fb_StrLen( (void*)ARG$1, -1ll );
			if( vr$20 != 0ll) goto label$1029;
			{
				HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
			}
			label$1029:;
			label$1028:;
			RECLEVEL$3 = RECLEVEL$3 + 1ll;
			PARSEARGSFROMFILE( ARG$1, IS_SOURCE$1 );
			RECLEVEL$3 = RECLEVEL$3 + -1ll;
		}
		goto label$1005;
		label$1024:;
		{
			FBSTRING EXT$3;
			FBSTRING* vr$24 = HGETFILEEXT( (char*)*(char**)ARG$1 );
			fb_StrInit( (void*)&EXT$3, -1ll, (void*)vr$24, -1ll, 0 );
			FBSTRING* vr$27 = fb_StrLcase2( (FBSTRING*)&EXT$3, 0 );
			fb_StrAssign( (void*)&EXT$3, -1ll, (void*)vr$27, -1ll, 0 );
			{
				int32 vr$30 = fb_StrCompare( (void*)&EXT$3, -1ll, (void*)"bas", 4ll );
				if( (int64)vr$30 != 0ll) goto label$1032;
				label$1033:;
				{
					HADDBAS( ARG$1 );
				}
				goto label$1031;
				label$1032:;
				int32 vr$33 = fb_StrCompare( (void*)&EXT$3, -1ll, (void*)"o", 2ll );
				if( (int64)vr$33 != 0ll) goto label$1034;
				label$1035:;
				{
					FBCADDOBJ( ARG$1 );
				}
				goto label$1031;
				label$1034:;
				int32 vr$36 = fb_StrCompare( (void*)&EXT$3, -1ll, (void*)"a", 2ll );
				if( (int64)vr$36 != 0ll) goto label$1036;
				label$1037:;
				{
					STRLISTAPPEND( (struct $5TLIST*)((uint8*)&FBC$ + 464ll), ARG$1 );
				}
				goto label$1031;
				label$1036:;
				int32 vr$40 = fb_StrCompare( (void*)&EXT$3, -1ll, (void*)"rc", 3ll );
				if( (int64)vr$40 == 0ll) goto label$1039;
				label$1040:;
				int32 vr$43 = fb_StrCompare( (void*)&EXT$3, -1ll, (void*)"res", 4ll );
				if( (int64)vr$43 != 0ll) goto label$1038;
				label$1039:;
				{
					void* vr$46 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&FBC$ + 208ll) );
					HSETIOFILE( (struct $9FBCIOFILE*)vr$46, ARG$1, -1ll );
				}
				goto label$1031;
				label$1038:;
				int32 vr$48 = fb_StrCompare( (void*)&EXT$3, -1ll, (void*)"xpm", 4ll );
				if( (int64)vr$48 != 0ll) goto label$1041;
				label$1042:;
				{
					int64 vr$51 = fb_StrLen( (void*)((uint8*)&FBC$ + 272ll), -1ll );
					if( vr$51 <= 0ll) goto label$1044;
					{
						HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
					}
					label$1044:;
					label$1043:;
					HSETIOFILE( (struct $9FBCIOFILE*)((uint8*)&FBC$ + 272ll), ARG$1, -1ll );
				}
				goto label$1031;
				label$1041:;
				{
					HFATALINVALIDOPTION( ARG$1, IS_SOURCE$1 );
				}
				label$1045:;
				label$1031:;
			}
			fb_StrDelete( (FBSTRING*)&EXT$3 );
		}
		label$1030:;
		label$1005:;
	}
	label$998:;
}

static void PARSEARGSFROMFILE( FBSTRING* FILENAME$1, int64 IS_SOURCE$1 )
{
	label$1066:;
	int64 F$1;
	int32 vr$0 = fb_FileFree(  );
	F$1 = (int64)vr$0;
	int32 vr$3 = fb_FileOpen( (FBSTRING*)FILENAME$1, 2u, 0u, 0u, (int32)F$1, 0 );
	if( (int64)vr$3 == 0ll) goto label$1069;
	{
		ERRREPORTEX( 26ll, (char*)*(char**)FILENAME$1, -1ll, 1ll, (char*)0ull );
		FBCEND( 1ll );
	}
	label$1069:;
	label$1068:;
	FBSTRING ARGS$1;
	__builtin_memset( &ARGS$1, 0, 24ll );
	label$1070:;
	int32 vr$8 = fb_FileEof( (int32)F$1 );
	if( (int64)vr$8 != 0ll) goto label$1071;
	{
		fb_FileLineInput( (int32)F$1, (void*)&ARGS$1, -1ll, 0 );
		FBSTRING* vr$13 = fb_TRIM( (FBSTRING*)&ARGS$1 );
		fb_StrAssign( (void*)&ARGS$1, -1ll, (void*)vr$13, -1ll, 0 );
		FBCPARSEARGSFROMSTRING( (char*)*(char**)&ARGS$1, IS_SOURCE$1, -1ll );
	}
	goto label$1070;
	label$1071:;
	int32 vr$16 = fb_FileClose( (int32)F$1 );
	if( (int64)vr$16 == 0ll) goto label$1072;
	void* vr$18 = fb_ErrorThrowAt( 2958, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$18;
	label$1072:;
	fb_StrDelete( (FBSTRING*)&ARGS$1 );
	label$1067:;
}

static int64 HTARGETNEEDSPIC( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1073:;
	fb$result$1 = 0ll;
	int64 vr$1 = FBGETCPUFAMILY(  );
	if( vr$1 == 0ll) goto label$1076;
	{
		{
			uint64 TMP$535$3;
			int64 vr$2 = FBGETOPTION( 3ll );
			TMP$535$3 = (uint64)vr$2;
			goto label$1078;
			label$1079:;
			{
				fb$result$1 = -1ll;
			}
			goto label$1077;
			label$1078:;
			static const void* tmp$898[10ll] = {
				&&label$1079,
				&&label$1079,
				&&label$1077,
				&&label$1077,
				&&label$1079,
				&&label$1079,
				&&label$1079,
				&&label$1079,
				&&label$1077,
				&&label$1079,
			};
			if( (TMP$535$3 - 2ull) > 9ull ) goto label$1077;
			goto *tmp$898[TMP$535$3 - 2ull];
			label$1077:;
		}
	}
	goto label$1075;
	label$1076:;
	{
		int64 vr$3 = FBGETOPTION( 3ll );
		if( vr$3 != 3ll) goto label$1081;
		{
			fb$result$1 = -1ll;
		}
		label$1081:;
		label$1080:;
	}
	label$1075:;
	label$1074:;
	return fb$result$1;
}

static void HPARSEARGS( int64 ARGC$1, char** ARGV$1 )
{
	label$1082:;
	*(int64*)&FBC$ = -1ll;
	FBSTRING ARG$1;
	__builtin_memset( &ARG$1, 0, 24ll );
	{
		int64 I$2;
		I$2 = 1ll;
		int64 TMP$536$2;
		TMP$536$2 = ARGC$1 + -1ll;
		goto label$1084;
		label$1087:;
		{
			fb_StrAssign( (void*)&ARG$1, -1ll, *(void**)((uint8*)ARGV$1 + (I$2 << (3ll & 63ll))), 0ll, 0 );
			HANDLEARG( &ARG$1, 0ll, 0ll );
		}
		label$1085:;
		I$2 = I$2 + 1ll;
		label$1084:;
		if( I$2 <= TMP$536$2) goto label$1087;
		label$1086:;
	}
	if( *(int64*)&FBC$ < 0ll) goto label$1089;
	{
		FBSTRING TMP$537$2;
		__builtin_memset( &TMP$537$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$537$2, -1ll, *(void**)((uint8*)((uint8*)ARGV$1 + (ARGC$1 << (3ll & 63ll))) + -8ll), 0ll, 0 );
		HFATALINVALIDOPTION( &TMP$537$2, 0ll );
		fb_StrDelete( (FBSTRING*)&TMP$537$2 );
	}
	label$1089:;
	label$1088:;
	fb_StrDelete( (FBSTRING*)&ARG$1 );
	label$1083:;
}

static void HCHECKARGS( void )
{
	label$1090:;
	HCHECKWAITINGOBJFILE(  );
	{
		int64 TMP$538$2;
		int64 vr$0 = FBGETOPTION( 5ll );
		TMP$538$2 = vr$0;
		if( TMP$538$2 != 0ll) goto label$1093;
		label$1094:;
		{
			int64 vr$1 = FBGETOPTION( 7ll );
			if( vr$1 < 1ll) goto label$1096;
			{
				ERRREPORTEX( 284ll, (char*)"", -1ll, 1ll, (char*)0ull );
				FBCEND( 1ll );
			}
			label$1096:;
			label$1095:;
		}
		goto label$1092;
		label$1093:;
		if( TMP$538$2 != 1ll) goto label$1097;
		label$1098:;
		{
			int64 vr$2 = FBGETCPUFAMILY(  );
			int64 vr$4 = FBGETCPUFAMILY(  );
			if( ((int64)-(vr$2 != 0ll) & (int64)-(vr$4 != 1ll)) == 0ll) goto label$1100;
			{
				ERRREPORTEX( 330ll, (char*)"", -1ll, 1ll, (char*)0ull );
				FBCEND( 1ll );
			}
			label$1100:;
			label$1099:;
		}
		goto label$1092;
		label$1097:;
		if( TMP$538$2 != 2ll) goto label$1101;
		label$1102:;
		{
			int64 vr$7 = FBGETCPUFAMILY(  );
			int64 vr$9 = FBGETCPUFAMILY(  );
			if( ((int64)-(vr$7 != 2ll) & (int64)-(vr$9 != 3ll)) == 0ll) goto label$1104;
			{
				ERRREPORTEX( 331ll, (char*)"", -1ll, 1ll, (char*)0ull );
				FBCEND( 1ll );
			}
			label$1104:;
			label$1103:;
		}
		label$1101:;
		label$1092:;
	}
	if( *(int64*)((uint8*)&FBC$ + 48ll) < 0ll) goto label$1106;
	{
		FBSETOPTION( 4ll, *(int64*)((uint8*)&FBC$ + 48ll) );
	}
	label$1106:;
	label$1105:;
	int64 vr$12 = FBGETOPTION( 5ll );
	int64 vr$14 = FBGETOPTION( 4ll );
	if( ((int64)-(vr$12 == 2ll) & (int64)-(vr$14 < 17ll)) == 0ll) goto label$1108;
	{
		FBSETOPTION( 4ll, 17ll );
	}
	label$1108:;
	label$1107:;
	int64 vr$17 = FBGETOPTION( 3ll );
	int64 vr$19 = FBGETCPUFAMILY(  );
	if( ((int64)-(vr$17 == 4ll) & (int64)-(vr$19 != 0ll)) == 0ll) goto label$1110;
	{
		char* vr$22 = FBGETFBCARCH(  );
		ERRREPORTEX( 82ll, (char*)vr$22, -1ll, 1ll, (char*)0ull );
		FBCEND( 1ll );
	}
	label$1110:;
	label$1109:;
	int64 vr$23 = FBGETOPTION( 0ll );
	int64 vr$25 = FBGETOPTION( 3ll );
	if( ((int64)-(vr$23 == 2ll) | (int64)-(vr$25 == 3ll)) == 0ll) goto label$1112;
	{
		int64 vr$28 = HTARGETNEEDSPIC(  );
		if( vr$28 == 0ll) goto label$1114;
		{
			FBSETOPTION( 38ll, -1ll );
		}
		label$1114:;
		label$1113:;
	}
	label$1112:;
	label$1111:;
	int64 vr$29 = FBGETOPTION( 38ll );
	if( vr$29 == 0ll) goto label$1116;
	{
		int64 vr$30 = HTARGETNEEDSPIC(  );
		if( vr$30 != 0ll) goto label$1118;
		{
			ERRREPORTEX( 86ll, (char*)"", -1ll, 1ll, (char*)0ull );
		}
		label$1118:;
		label$1117:;
	}
	label$1116:;
	label$1115:;
	int64 vr$31 = FBGETCPUFAMILY(  );
	int64 vr$33 = FBGETOPTION( 3ll );
	if( ((int64)-(vr$31 == 0ll) & (int64)-(vr$33 != 10ll)) == 0ll) goto label$1120;
	{
		FBSETOPTION( 2ll, 0ll );
	}
	goto label$1119;
	label$1120:;
	{
		FBSETOPTION( 2ll, 1ll );
	}
	label$1119:;
	int64 vr$36 = FBGETOPTION( 2ll );
	int64 vr$38 = FBGETOPTION( 38ll );
	if( ((int64)-(vr$36 == 0ll) & vr$38) == 0ll) goto label$1122;
	{
		FBSETOPTION( 2ll, 1ll );
	}
	label$1122:;
	label$1121:;
	if( *(int64*)((uint8*)&FBC$ + 40ll) < 0ll) goto label$1124;
	{
		FBSETOPTION( 2ll, *(int64*)((uint8*)&FBC$ + 40ll) );
	}
	label$1124:;
	label$1123:;
	int64 vr$40 = FBGETOPTION( 2ll );
	int64 vr$42 = FBGETCPUFAMILY(  );
	int64 vr$45 = FBGETOPTION( 2ll );
	int64 vr$47 = FBGETCPUFAMILY(  );
	if( (((int64)-(vr$40 == 0ll) & (int64)-(vr$42 != 0ll)) | ((int64)-(vr$45 == 4ll) & (int64)-(vr$47 != 1ll))) == 0ll) goto label$1126;
	{
		char* vr$51 = FBGETFBCARCH(  );
		ERRREPORTEX( 83ll, (char*)vr$51, -1ll, 1ll, (char*)0ull );
		FBCEND( 1ll );
	}
	label$1126:;
	label$1125:;
	int64 vr$52 = FBGETOPTION( 2ll );
	int64 vr$54 = FBGETOPTION( 38ll );
	if( ((int64)-(vr$52 == 0ll) & vr$54) == 0ll) goto label$1128;
	{
		ERRREPORTEX( 85ll, (char*)"", -1ll, 1ll, (char*)0ull );
		FBCEND( 1ll );
	}
	label$1128:;
	label$1127:;
	{
		uint64 TMP$539$2;
		int64 vr$56 = FBGETOPTION( 3ll );
		TMP$539$2 = (uint64)vr$56;
		goto label$1130;
		label$1131:;
		{
		}
		goto label$1129;
		label$1132:;
		{
			struct $9FBCIOFILE* RC$3;
			void* vr$58 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 208ll) );
			RC$3 = (struct $9FBCIOFILE*)vr$58;
			if( RC$3 == (struct $9FBCIOFILE*)0ull) goto label$1134;
			{
				ERRREPORTEX( 291ll, (char*)*(char**)RC$3, -1ll, 1ll, (char*)0ull );
				FBCEND( 1ll );
			}
			label$1134:;
			label$1133:;
		}
		goto label$1129;
		label$1130:;
		static const void* tmp$899[6ll] = {
			&&label$1131,
			&&label$1131,
			&&label$1132,
			&&label$1132,
			&&label$1132,
			&&label$1131,
		};
		if( TMP$539$2 > 5ull ) goto label$1132;
		goto *tmp$899[TMP$539$2 - 0ull];
		label$1129:;
	}
	{
		uint64 TMP$540$2;
		int64 vr$60 = FBGETOPTION( 3ll );
		TMP$540$2 = (uint64)vr$60;
		goto label$1136;
		label$1137:;
		{
		}
		goto label$1135;
		label$1138:;
		{
			int64 vr$62 = fb_StrLen( (void*)((uint8*)&FBC$ + 272ll), -1ll );
			if( vr$62 <= 0ll) goto label$1140;
			{
				ERRREPORTEX( 291ll, (char*)*(char**)((uint8*)&FBC$ + 272ll), -1ll, 1ll, (char*)0ull );
				FBCEND( 1ll );
			}
			label$1140:;
			label$1139:;
		}
		goto label$1135;
		label$1136:;
		static const void* tmp$900[10ll] = {
			&&label$1137,
			&&label$1138,
			&&label$1138,
			&&label$1138,
			&&label$1137,
			&&label$1137,
			&&label$1137,
			&&label$1137,
			&&label$1137,
			&&label$1137,
		};
		if( (TMP$540$2 - 2ull) > 9ull ) goto label$1138;
		goto *tmp$900[TMP$540$2 - 2ull];
		label$1135:;
	}
	int64 vr$63 = FBGETOPTION( 3ll );
	int64 vr$65 = FBGETOPTION( 2ll );
	if( ((int64)-(vr$63 == 10ll) & (int64)-(vr$65 != 0ll)) == 0ll) goto label$1142;
	{
		FBSETOPTION( 9ll, 1ll );
	}
	label$1142:;
	label$1141:;
	if( *(int64*)((uint8*)&FBC$ + 64ll) < 0ll) goto label$1144;
	{
		{
			int64 TMP$541$3;
			int64 vr$68 = FBGETCPUFAMILY(  );
			TMP$541$3 = vr$68;
			if( TMP$541$3 == 0ll) goto label$1147;
			label$1148:;
			if( TMP$541$3 != 1ll) goto label$1146;
			label$1147:;
			{
			}
			goto label$1145;
			label$1146:;
			{
				FBSTRING TMP$542$4;
				__builtin_memset( &TMP$542$4, 0, 24ll );
				FBSTRING* vr$70 = FBGETTARGETID(  );
				fb_StrAssign( (void*)&TMP$542$4, -1ll, (void*)vr$70, -1ll, 0 );
				ERRREPORTEX( 319ll, (char*)*(char**)&TMP$542$4, -1ll, 1ll, (char*)0ull );
				fb_StrDelete( (FBSTRING*)&TMP$542$4 );
			}
			label$1149:;
			label$1145:;
		}
		{
			int64 TMP$543$3;
			int64 vr$73 = FBGETOPTION( 2ll );
			TMP$543$3 = vr$73;
			if( TMP$543$3 == 0ll) goto label$1152;
			label$1153:;
			if( TMP$543$3 != 4ll) goto label$1151;
			label$1152:;
			{
				if( *(int64*)((uint8*)&FBC$ + 64ll) == 0ll) goto label$1155;
				{
					ERRREPORTEX( 84ll, (char*)"", -1ll, 1ll, (char*)0ull );
				}
				label$1155:;
				label$1154:;
			}
			label$1151:;
			label$1150:;
		}
		FBSETOPTION( 9ll, *(int64*)((uint8*)&FBC$ + 64ll) );
	}
	label$1144:;
	label$1143:;
	FBSETOPTION( 39ll, -1ll );
	label$1091:;
}

static void FBCDETERMINEPREFIX( void )
{
	label$1156:;
	int64 vr$1 = fb_StrLen( (void*)((uint8*)&FBC$ + 2776ll), 261ll );
	if( vr$1 != 0ll) goto label$1159;
	{
		FBSTRING TMP$544$2;
		FBSTRING TMP$545$2;
		FBSTRING TMP$548$2;
		__builtin_memset( &TMP$544$2, 0, 24ll );
		FBSTRING* vr$3 = fb_ExePath(  );
		fb_StrAssign( (void*)&TMP$544$2, -1ll, (void*)vr$3, -1ll, 0 );
		FBSTRING* vr$6 = PATHSTRIPDIV( &TMP$544$2 );
		__builtin_memset( &TMP$545$2, 0, 24ll );
		FBSTRING* vr$9 = fb_StrConcat( &TMP$545$2, (void*)vr$6, -1ll, (void*)"\x5C", 2ll );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)vr$9, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&TMP$544$2 );
		__builtin_memset( &TMP$548$2, 0, 24ll );
		FBSTRING* vr$15 = fb_StrConcat( &TMP$548$2, (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)"..\x5C", 4ll );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)vr$15, -1ll, 0 );
	}
	goto label$1158;
	label$1159:;
	{
		FBSTRING TMP$549$2;
		FBSTRING TMP$550$2;
		__builtin_memset( &TMP$549$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$549$2, -1ll, (void*)((uint8*)&FBC$ + 2776ll), 261ll, 0 );
		FBSTRING* vr$21 = PATHSTRIPDIV( &TMP$549$2 );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)&TMP$549$2, -1ll, 0 );
		__builtin_memset( &TMP$550$2, 0, 24ll );
		FBSTRING* vr$26 = fb_StrConcat( &TMP$550$2, (void*)vr$21, -1ll, (void*)"\x5C", 2ll );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)vr$26, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&TMP$549$2 );
	}
	label$1158:;
	label$1157:;
}

static void FBCSETUPCOMPILERPATHS( void )
{
	FBSTRING TMP$559$1;
	FBSTRING TMP$560$1;
	FBSTRING TMP$561$1;
	FBSTRING TMP$562$1;
	FBSTRING TMP$563$1;
	FBSTRING TMP$564$1;
	FBSTRING TMP$565$1;
	FBSTRING TMP$566$1;
	label$1160:;
	FBSTRING TARGETID$1;
	FBSTRING* vr$0 = FBGETTARGETID(  );
	fb_StrInit( (void*)&TARGETID$1, -1ll, (void*)vr$0, -1ll, 0 );
	FBSTRING FBNAME$1;
	__builtin_memset( &FBNAME$1, 0, 24ll );
	fb_StrAssign( (void*)&FBNAME$1, -1ll, (void*)"freebasic", 10ll, 0 );
	FBSTRING LIBDIRNAME$1;
	fb_StrInit( (void*)&LIBDIRNAME$1, -1ll, (void*)"lib", 4ll, 0 );
	int64 vr$6 = fb_StrLen( (void*)((uint8*)&FBC$ + 3820ll), 261ll );
	if( vr$6 <= 0ll) goto label$1163;
	{
		FBSTRING TMP$553$2;
		FBSTRING TMP$554$2;
		FBSTRING TMP$555$2;
		__builtin_memset( &TMP$553$2, 0, 24ll );
		FBSTRING* vr$11 = fb_StrConcat( &TMP$553$2, (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)"bin", 4ll );
		__builtin_memset( &TMP$554$2, 0, 24ll );
		FBSTRING* vr$14 = fb_StrConcat( &TMP$554$2, (void*)vr$11, -1ll, (void*)"\x5C", 2ll );
		__builtin_memset( &TMP$555$2, 0, 24ll );
		FBSTRING* vr$17 = fb_StrConcat( &TMP$555$2, (void*)vr$14, -1ll, (void*)((uint8*)&FBC$ + 3820ll), 261ll );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 3037ll), 261ll, (void*)vr$17, -1ll, 0 );
	}
	goto label$1162;
	label$1163:;
	{
		FBSTRING TMP$556$2;
		FBSTRING TMP$557$2;
		FBSTRING TMP$558$2;
		__builtin_memset( &TMP$556$2, 0, 24ll );
		FBSTRING* vr$23 = fb_StrConcat( &TMP$556$2, (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)"bin", 4ll );
		__builtin_memset( &TMP$557$2, 0, 24ll );
		FBSTRING* vr$26 = fb_StrConcat( &TMP$557$2, (void*)vr$23, -1ll, (void*)"\x5C", 2ll );
		__builtin_memset( &TMP$558$2, 0, 24ll );
		FBSTRING* vr$29 = fb_StrConcat( &TMP$558$2, (void*)vr$26, -1ll, (void*)((uint8*)&FBC$ + 2225ll), 129ll );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 3037ll), 261ll, (void*)vr$29, -1ll, 0 );
	}
	label$1162:;
	__builtin_memset( &TMP$559$1, 0, 24ll );
	FBSTRING* vr$35 = fb_StrConcat( &TMP$559$1, (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)"include", 8ll );
	__builtin_memset( &TMP$560$1, 0, 24ll );
	FBSTRING* vr$38 = fb_StrConcat( &TMP$560$1, (void*)vr$35, -1ll, (void*)"\x5C", 2ll );
	__builtin_memset( &TMP$561$1, 0, 24ll );
	FBSTRING* vr$41 = fb_StrConcat( &TMP$561$1, (void*)vr$38, -1ll, (void*)&FBNAME$1, -1ll );
	fb_StrAssign( (void*)((uint8*)&FBC$ + 3298ll), 261ll, (void*)vr$41, -1ll, 0 );
	__builtin_memset( &TMP$562$1, 0, 24ll );
	FBSTRING* vr$49 = fb_StrConcat( &TMP$562$1, (void*)((uint8*)&FBC$ + 2776ll), 261ll, (void*)&LIBDIRNAME$1, -1ll );
	__builtin_memset( &TMP$563$1, 0, 24ll );
	FBSTRING* vr$52 = fb_StrConcat( &TMP$563$1, (void*)vr$49, -1ll, (void*)"\x5C", 2ll );
	__builtin_memset( &TMP$564$1, 0, 24ll );
	FBSTRING* vr$55 = fb_StrConcat( &TMP$564$1, (void*)vr$52, -1ll, (void*)&FBNAME$1, -1ll );
	__builtin_memset( &TMP$565$1, 0, 24ll );
	FBSTRING* vr$58 = fb_StrConcat( &TMP$565$1, (void*)vr$55, -1ll, (void*)"\x5C", 2ll );
	__builtin_memset( &TMP$566$1, 0, 24ll );
	FBSTRING* vr$61 = fb_StrConcat( &TMP$566$1, (void*)vr$58, -1ll, (void*)&TARGETID$1, -1ll );
	fb_StrAssign( (void*)((uint8*)&FBC$ + 3559ll), 261ll, (void*)vr$61, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&LIBDIRNAME$1 );
	fb_StrDelete( (FBSTRING*)&FBNAME$1 );
	fb_StrDelete( (FBSTRING*)&TARGETID$1 );
	label$1161:;
}

static void FBCPRINTTARGETINFO( void )
{
	FBSTRING TMP$568$1;
	FBSTRING TMP$569$1;
	label$1164:;
	FBSTRING S$1;
	FBSTRING* vr$0 = FBGETTARGETID(  );
	fb_StrInit( (void*)&S$1, -1ll, (void*)vr$0, -1ll, 0 );
	char* vr$2 = FBGETFBCARCH(  );
	__builtin_memset( &TMP$568$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$568$1, (void*)", ", 3ll, (void*)vr$2, 0ll );
	__builtin_memset( &TMP$569$1, 0, 24ll );
	FBSTRING* vr$9 = fb_StrConcat( &TMP$569$1, (void*)&S$1, -1ll, (void*)vr$5, -1ll );
	fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$9, -1ll, 0 );
	fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)", ", 3ll, 0 );
	int64 vr$12 = FBGETBITS(  );
	FBSTRING* vr$13 = fb_LongintToStr( vr$12 );
	fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$13, -1ll, 0 );
	fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"bit", 4ll, 0 );
	int64 vr$17 = fb_StrLen( (void*)((uint8*)&FBC$ + 2096ll), 129ll );
	if( vr$17 <= 0ll) goto label$1167;
	{
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)" (", 3ll, 0 );
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)((uint8*)&FBC$ + 2096ll), 129ll, 0 );
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)")", 2ll, 0 );
	}
	label$1167:;
	label$1166:;
	FBSTRING* vr$22 = fb_StrAllocTempDescZEx( (char*)"target:", 7ll );
	fb_PrintString( 0, (FBSTRING*)vr$22, 2 );
	fb_PrintString( 0, (FBSTRING*)&S$1, 1 );
	FBSTRING* vr$24 = fb_StrAllocTempDescZEx( (char*)"backend:", 8ll );
	fb_PrintString( 0, (FBSTRING*)vr$24, 2 );
	int64 vr$25 = FBGETOPTION( 2ll );
	FBSTRING* vr$26 = FBGETBACKENDNAME( vr$25 );
	fb_PrintString( 0, (FBSTRING*)vr$26, 1 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$1165:;
}

static void FBCDETERMINEMAINNAME( void )
{
	label$1168:;
	int64 vr$1 = fb_StrLen( (void*)((uint8*)&FBC$ + 1229ll), 261ll );
	if( vr$1 != 0ll) goto label$1171;
	{
		FBSTRING TMP$576$2;
		struct $9FBCIOFILE* M$2;
		void* vr$3 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 144ll) );
		M$2 = (struct $9FBCIOFILE*)vr$3;
		if( M$2 == (struct $9FBCIOFILE*)0ull) goto label$1173;
		{
			fb_StrAssign( (void*)((uint8*)&FBC$ + 1229ll), 261ll, (void*)M$2, -1ll, 0 );
		}
		goto label$1172;
		label$1173:;
		{
			FBSTRING* OBJF$3;
			void* vr$8 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 400ll) );
			OBJF$3 = (FBSTRING*)vr$8;
			if( OBJF$3 == (FBSTRING*)0ull) goto label$1175;
			{
				fb_StrAssign( (void*)((uint8*)&FBC$ + 1229ll), 261ll, (void*)OBJF$3, -1ll, 0 );
			}
			goto label$1174;
			label$1175:;
			{
				fb_StrAssign( (void*)((uint8*)&FBC$ + 1229ll), 261ll, (void*)"unnamed", 8ll, 0 );
			}
			label$1174:;
		}
		label$1172:;
		__builtin_memset( &TMP$576$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$576$2, -1ll, (void*)((uint8*)&FBC$ + 1229ll), 261ll, 0 );
		FBSTRING* vr$15 = HSTRIPEXT( &TMP$576$2 );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 1229ll), 261ll, (void*)&TMP$576$2, -1ll, 0 );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 1229ll), 261ll, (void*)vr$15, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&TMP$576$2 );
	}
	label$1171:;
	label$1170:;
	label$1169:;
}

static FBSTRING* HGETASMNAME( struct $9FBCIOFILE* MODULE$1, int64 STAGE$1 )
{
	FBSTRING TMP$581$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$1176:;
	char* EXT$1;
	FBSTRING ASMFILE$1;
	__builtin_memset( &ASMFILE$1, 0, 24ll );
	FBSTRING* vr$3 = HSTRIPEXT( *(FBSTRING**)((uint8*)MODULE$1 + 24ll) );
	fb_StrAssign( (void*)&ASMFILE$1, -1ll, (void*)vr$3, -1ll, 0 );
	int64 vr$5 = FBGETOPTION( 3ll );
	if( vr$5 == 12ll) goto label$1179;
	{
		EXT$1 = (char*)".asm";
	}
	goto label$1178;
	label$1179:;
	{
		EXT$1 = (char*)".o";
	}
	label$1178:;
	if( STAGE$1 != 1ll) goto label$1181;
	{
		{
			int64 TMP$578$3;
			int64 vr$6 = FBGETOPTION( 2ll );
			TMP$578$3 = vr$6;
			if( TMP$578$3 == 1ll) goto label$1184;
			label$1185:;
			if( TMP$578$3 != 2ll) goto label$1183;
			label$1184:;
			{
				EXT$1 = (char*)".c";
			}
			goto label$1182;
			label$1183:;
			if( TMP$578$3 != 3ll) goto label$1186;
			label$1187:;
			{
				EXT$1 = (char*)".ll";
			}
			label$1186:;
			label$1182:;
		}
	}
	label$1181:;
	label$1180:;
	__builtin_memset( &TMP$581$1, 0, 24ll );
	FBSTRING* vr$10 = fb_StrConcat( &TMP$581$1, (void*)&ASMFILE$1, -1ll, (void*)EXT$1, 0ll );
	fb_StrAssign( (void*)&ASMFILE$1, -1ll, (void*)vr$10, -1ll, 0 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&ASMFILE$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&ASMFILE$1 );
	label$1177:;
	FBSTRING* vr$16 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$16;
}

static void HCOMPILEBAS( struct $9FBCIOFILE* MODULE$1, int64 IS_MAIN$1, int64 IS_FBCTINF$1, int64 MODULE_COUNT$1 )
{
	label$1188:;
	int64 PREVLANG$1;
	int64 PREVOUTTYPE$1;
	FBSTRING ASMFILE$1;
	__builtin_memset( &ASMFILE$1, 0, 24ll );
	FBSTRING PPONLYFILE$1;
	__builtin_memset( &PPONLYFILE$1, 0, 24ll );
	FBSTRING* vr$2 = HGETASMNAME( MODULE$1, 1ll );
	fb_StrAssign( (void*)&ASMFILE$1, -1ll, (void*)vr$2, -1ll, 0 );
	int64 vr$4 = FBGETOPTION( 1ll );
	if( vr$4 == 0ll) goto label$1191;
	{
		fb_StrAssign( (void*)&PPONLYFILE$1, -1ll, *(void**)((uint8*)MODULE$1 + 24ll), -1ll, 0 );
		if( *(int64*)((uint8*)MODULE$1 + 32ll) != 0ll) goto label$1193;
		{
			FBSTRING TMP$583$3;
			FBSTRING* vr$9 = HSTRIPEXT( &PPONLYFILE$1 );
			__builtin_memset( &TMP$583$3, 0, 24ll );
			FBSTRING* vr$12 = fb_StrConcat( &TMP$583$3, (void*)vr$9, -1ll, (void*)".pp.bas", 8ll );
			fb_StrAssign( (void*)&PPONLYFILE$1, -1ll, (void*)vr$12, -1ll, 0 );
		}
		label$1193:;
		label$1192:;
	}
	label$1191:;
	label$1190:;
	if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$1195;
	{
		FBSTRING* vr$14 = fb_StrAllocTempDescZEx( (char*)"compiling: ", 11ll );
		fb_PrintString( 0, (FBSTRING*)vr$14, 2 );
		fb_PrintString( 0, (FBSTRING*)MODULE$1, 0 );
		FBSTRING* vr$17 = fb_StrAllocTempDescZEx( (char*)" -o ", 4ll );
		fb_PrintString( 0, (FBSTRING*)vr$17, 0 );
		fb_PrintString( 0, (FBSTRING*)&ASMFILE$1, 0 );
		int64 vr$19 = FBGETOPTION( 1ll );
		if( vr$19 == 0ll) goto label$1197;
		{
			FBSTRING TMP$587$3;
			__builtin_memset( &TMP$587$3, 0, 24ll );
			FBSTRING* vr$23 = fb_StrConcat( &TMP$587$3, (void*)" -pp ", 6ll, (void*)&PPONLYFILE$1, -1ll );
			fb_PrintString( 0, (FBSTRING*)vr$23, 0 );
		}
		label$1197:;
		label$1196:;
		if( IS_MAIN$1 == 0ll) goto label$1199;
		{
			FBSTRING* vr$24 = fb_StrAllocTempDescZEx( (char*)" (main module)", 14ll );
			fb_PrintString( 0, (FBSTRING*)vr$24, 0 );
		}
		goto label$1198;
		label$1199:;
		if( IS_FBCTINF$1 == 0ll) goto label$1200;
		{
			FBSTRING* vr$25 = fb_StrAllocTempDescZEx( (char*)" (FB compile-time info)", 23ll );
			fb_PrintString( 0, (FBSTRING*)vr$25, 0 );
		}
		label$1200:;
		label$1198:;
		fb_PrintVoid( 0, 1 );
	}
	label$1195:;
	label$1194:;
	int64 vr$26 = FBGETOPTION( 12ll );
	if( vr$26 == -1ll) goto label$1202;
	{
		int64 vr$27 = FBGETOPTION( 12ll );
		FBSETOPTION( 10ll, vr$27 );
	}
	label$1202:;
	label$1201:;
	int64 vr$28 = FBGETOPTION( 10ll );
	PREVLANG$1 = vr$28;
	int64 vr$29 = FBGETOPTION( 0ll );
	PREVOUTTYPE$1 = vr$29;
	if( IS_FBCTINF$1 == 0ll) goto label$1204;
	{
		FBSETOPTION( 0ll, 3ll );
	}
	label$1204:;
	label$1203:;
	label$1205:;
	{
		int64 vr$31 = FBGETOPTION( 2ll );
		int64 vr$33 = FBGETOPTION( 2ll );
		if( (~(*(int64*)((uint8*)&FBC$ + 80ll)) & (((int64)-(vr$31 != 0ll) & (int64)-(vr$33 != 4ll)) | ~(*(int64*)((uint8*)&FBC$ + 96ll)))) == 0ll) goto label$1209;
		{
			FBCADDTEMP( &ASMFILE$1 );
		}
		goto label$1208;
		label$1209:;
		if( MODULE_COUNT$1 != 1ll) goto label$1210;
		{
			int64 vr$40 = FBRESTARTGETCOUNT(  );
			if( vr$40 <= 0ll) goto label$1212;
			{
				FBCREMOVETEMP( &ASMFILE$1 );
			}
			label$1212:;
			label$1211:;
		}
		label$1210:;
		label$1208:;
		FBINIT( IS_MAIN$1, (char*)((uint8*)&FBC$ + 1490ll), MODULE_COUNT$1 );
		if( IS_FBCTINF$1 == 0ll) goto label$1214;
		{
			FBSETLIBS( (struct $7TSTRSET*)((uint8*)&FBC$ + 792ll), (struct $7TSTRSET*)((uint8*)&FBC$ + 880ll) );
		}
		goto label$1213;
		label$1214:;
		{
			FBSETLIBS( (struct $7TSTRSET*)((uint8*)&FBC$ + 528ll), (struct $7TSTRSET*)((uint8*)&FBC$ + 616ll) );
		}
		label$1213:;
		FBCOMPILE( (char*)*(char**)MODULE$1, (char*)*(char**)&ASMFILE$1, &PPONLYFILE$1, IS_MAIN$1 );
		int64 vr$49 = ERRGETCOUNT(  );
		if( vr$49 <= 0ll) goto label$1216;
		{
			FBCEND( 1ll );
		}
		label$1216:;
		label$1215:;
		int64 vr$50 = FBSHOULDRESTART(  );
		if( vr$50 != 0ll) goto label$1218;
		{
			goto label$1206;
		}
		label$1218:;
		label$1217:;
		FBRESTARTENDREQUEST( 7ll );
		FBEND(  );
		int64 vr$51 = FBSHOULDRESTART(  );
		if( vr$51 == 0ll) goto label$1220;
		{
			int64 vr$52 = FBGETOPTION( 12ll );
			if( vr$52 != -1ll) goto label$1222;
			{
				FBSETOPTION( 10ll, PREVLANG$1 );
			}
			label$1222:;
			label$1221:;
			fb_StrDelete( (FBSTRING*)&PPONLYFILE$1 );
			fb_StrDelete( (FBSTRING*)&ASMFILE$1 );
			goto label$1189;
		}
		label$1220:;
		label$1219:;
	}
	label$1207:;
	goto label$1205;
	label$1206:;
	if( IS_FBCTINF$1 != 0ll) goto label$1224;
	{
		FBGETLIBS( (struct $7TSTRSET*)((uint8*)&FBC$ + 792ll), (struct $7TSTRSET*)((uint8*)&FBC$ + 880ll) );
	}
	label$1224:;
	label$1223:;
	FBEND(  );
	if( IS_FBCTINF$1 == 0ll) goto label$1226;
	{
		FBSETOPTION( 0ll, PREVOUTTYPE$1 );
	}
	label$1226:;
	label$1225:;
	FBSETOPTION( 10ll, PREVLANG$1 );
	fb_StrDelete( (FBSTRING*)&PPONLYFILE$1 );
	fb_StrDelete( (FBSTRING*)&ASMFILE$1 );
	label$1189:;
}

static void HCOMPILEMODULES( void )
{
	label$1227:;
	int64 ISMAIN$1;
	int64 CHECKMAIN$1;
	FBSTRING MAINFILE$1;
	__builtin_memset( &MAINFILE$1, 0, 24ll );
	struct $9FBCIOFILE* MODULE$1;
	ISMAIN$1 = 0ll;
	{
		int64 TMP$590$2;
		int64 vr$1 = FBGETOPTION( 0ll );
		TMP$590$2 = vr$1;
		if( TMP$590$2 == 0ll) goto label$1231;
		label$1232:;
		if( TMP$590$2 != 2ll) goto label$1230;
		label$1231:;
		{
			CHECKMAIN$1 = -1ll;
		}
		goto label$1229;
		label$1230:;
		{
			CHECKMAIN$1 = *(int64*)((uint8*)&FBC$ + 1624ll);
		}
		label$1233:;
		label$1229:;
	}
	if( CHECKMAIN$1 == 0ll) goto label$1235;
	{
		FBSTRING* vr$3 = HSTRIPPATH( (char*)((uint8*)&FBC$ + 1229ll) );
		fb_StrAssign( (void*)&MAINFILE$1, -1ll, (void*)vr$3, -1ll, 0 );
	}
	label$1235:;
	label$1234:;
	void* vr$6 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 144ll) );
	MODULE$1 = (struct $9FBCIOFILE*)vr$6;
	if( MODULE$1 != (struct $9FBCIOFILE*)0ull) goto label$1237;
	{
		STRSETCOPY( (struct $7TSTRSET*)((uint8*)&FBC$ + 792ll), (struct $7TSTRSET*)((uint8*)&FBC$ + 528ll) );
		STRSETCOPY( (struct $7TSTRSET*)((uint8*)&FBC$ + 880ll), (struct $7TSTRSET*)((uint8*)&FBC$ + 616ll) );
		fb_StrDelete( (FBSTRING*)&MAINFILE$1 );
		goto label$1228;
	}
	label$1237:;
	label$1236:;
	int64 MODULE_COUNT$1;
	MODULE_COUNT$1 = 0ll;
	label$1238:;
	{
		if( CHECKMAIN$1 == 0ll) goto label$1242;
		{
			FBSTRING TMP$591$3;
			__builtin_memset( &TMP$591$3, 0, 24ll );
			FBSTRING* vr$15 = HSTRIPEXT( (FBSTRING*)MODULE$1 );
			fb_StrAssign( (void*)&TMP$591$3, -1ll, (void*)vr$15, -1ll, 0 );
			FBSTRING* vr$17 = HSTRIPPATH( (char*)*(char**)&TMP$591$3 );
			int32 vr$19 = fb_StrCompare( (void*)&MAINFILE$1, -1ll, (void*)vr$17, -1ll );
			ISMAIN$1 = (int64)-((int64)vr$19 == 0ll);
			fb_StrDelete( (FBSTRING*)&TMP$591$3 );
		}
		label$1242:;
		label$1241:;
		MODULE_COUNT$1 = MODULE_COUNT$1 + 1ll;
		HCOMPILEBAS( MODULE$1, ISMAIN$1, 0ll, MODULE_COUNT$1 );
		int64 vr$24 = FBSHOULDRESTART(  );
		if( vr$24 == 0ll) goto label$1244;
		{
			fb_StrDelete( (FBSTRING*)&MAINFILE$1 );
			goto label$1228;
		}
		label$1244:;
		label$1243:;
		void* vr$26 = LISTGETNEXT( (void*)MODULE$1 );
		MODULE$1 = (struct $9FBCIOFILE*)vr$26;
	}
	label$1240:;
	if( MODULE$1 != (struct $9FBCIOFILE*)0ull) goto label$1238;
	label$1239:;
	fb_StrDelete( (FBSTRING*)&MAINFILE$1 );
	label$1228:;
}

static int64 HPARSEXPM( FBSTRING* XPMFILE$1, FBSTRING* CODE$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1245:;
	fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)"\x0A" "dim shared as zstring ptr ", 28ll, 0 );
	fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)"fb_program_icon_data", 21ll, 0 );
	fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)"(0 to ...) = _\x0A{ _\x0A", 20ll, 0 );
	int64 F$1;
	int32 vr$1 = fb_FileFree(  );
	F$1 = (int64)vr$1;
	int32 vr$4 = fb_FileOpen( (FBSTRING*)XPMFILE$1, 2u, 0u, 0u, (int32)F$1, 0 );
	if( (int64)vr$4 == 0ll) goto label$1248;
	{
		goto label$1246;
	}
	label$1248:;
	label$1247:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	fb_FileLineInput( (int32)F$1, (void*)&LN$1, -1ll, 0 );
	FBSTRING* vr$10 = fb_StrUcase2( (FBSTRING*)&LN$1, 0 );
	int32 vr$11 = fb_StrCompare( (void*)vr$10, -1ll, (void*)"/* XPM */", 10ll );
	if( (int64)vr$11 == 0ll) goto label$1250;
	{
		int32 vr$14 = fb_FileClose( (int32)F$1 );
		if( (int64)vr$14 == 0ll) goto label$1251;
		void* vr$16 = fb_ErrorThrowAt( 3588, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
		goto *vr$16;
		label$1251:;
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$1246;
	}
	label$1250:;
	label$1249:;
	int64 SAW_ROWS$1;
	SAW_ROWS$1 = 0ll;
	label$1252:;
	int32 vr$19 = fb_FileEof( (int32)F$1 );
	if( (int64)vr$19 != 0ll) goto label$1253;
	{
		fb_FileLineInput( (int32)F$1, (void*)&LN$1, -1ll, 0 );
		int64 vr$24 = fb_StrLen( (void*)&LN$1, -1ll );
		FBSTRING* vr$25 = fb_StrAllocTempDescZEx( (char*)"\x22", 1ll );
		int64 vr$27 = fb_StrInstr( 1ll, (FBSTRING*)&LN$1, (FBSTRING*)vr$25 );
		FBSTRING* vr$31 = fb_RIGHT( (FBSTRING*)&LN$1, (vr$24 - vr$27) + 1ll );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$31, -1ll, 0 );
		FBSTRING* vr$33 = fb_StrAllocTempDescZEx( (char*)"\x22", 1ll );
		int64 vr$35 = fb_StrInstr( 2ll, (FBSTRING*)&LN$1, (FBSTRING*)vr$33 );
		FBSTRING* vr$37 = fb_LEFT( (FBSTRING*)&LN$1, vr$35 );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$37, -1ll, 0 );
		int64 vr$40 = fb_StrLen( (void*)&LN$1, -1ll );
		if( vr$40 <= 0ll) goto label$1255;
		{
			FBSTRING TMP$598$3;
			if( SAW_ROWS$1 == 0ll) goto label$1257;
			{
				fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)", _\x0A", 5ll, 0 );
			}
			label$1257:;
			label$1256:;
			__builtin_memset( &TMP$598$3, 0, 24ll );
			FBSTRING* vr$44 = fb_StrConcat( &TMP$598$3, (void*)"\x09@", 3ll, (void*)&LN$1, -1ll );
			fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)vr$44, -1ll, 0 );
			SAW_ROWS$1 = -1ll;
		}
		label$1255:;
		label$1254:;
	}
	goto label$1252;
	label$1253:;
	int32 vr$46 = fb_FileClose( (int32)F$1 );
	if( (int64)vr$46 == 0ll) goto label$1258;
	void* vr$48 = fb_ErrorThrowAt( 3618, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$48;
	label$1258:;
	if( SAW_ROWS$1 != 0ll) goto label$1260;
	{
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$1246;
	}
	label$1260:;
	label$1259:;
	fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)" _ \x0A", 5ll, 0 );
	fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)"}\x0A\x0A", 4ll, 0 );
	fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)"extern as zstring ptr ptr fb_program_icon alias \x22" "fb_program_icon\x22\x0A", 67ll, 0 );
	fb_StrConcatByref( (void*)CODE$1, -1ll, (void*)"dim shared as zstring ptr ptr fb_program_icon = @fb_program_icon_data(0)\x0A", 74ll, 0 );
	fb$result$1 = -1ll;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$1246:;
	return fb$result$1;
}

static int64 HCOMPILEXPM( void )
{
	int64 TMP$609$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1261:;
	FBSTRING XPMFILE$1;
	__builtin_memset( &XPMFILE$1, 0, 24ll );
	FBSTRING CODE$1;
	__builtin_memset( &CODE$1, 0, 24ll );
	int64 FO$1;
	int64 vr$4 = fb_StrLen( (void*)((uint8*)&FBC$ + 272ll), -1ll );
	if( vr$4 != 0ll) goto label$1264;
	{
		fb$result$1 = -1ll;
		fb_StrDelete( (FBSTRING*)&CODE$1 );
		fb_StrDelete( (FBSTRING*)&XPMFILE$1 );
		goto label$1262;
	}
	label$1264:;
	label$1263:;
	fb_StrAssign( (void*)&XPMFILE$1, -1ll, (void*)((uint8*)&FBC$ + 272ll), -1ll, 0 );
	int64 vr$9 = fb_StrLen( *(void**)((uint8*)&FBC$ + 296ll), -1ll );
	if( vr$9 <= 0ll) goto label$1266;
	{
		FBSTRING* vr$10 = HSTRIPEXT( *(FBSTRING**)((uint8*)&FBC$ + 296ll) );
		fb_StrAssign( (void*)((uint8*)&FBC$ + 272ll), -1ll, (void*)vr$10, -1ll, 0 );
	}
	label$1266:;
	label$1265:;
	fb_StrConcatByref( (void*)((uint8*)&FBC$ + 272ll), -1ll, (void*)".bas", 5ll, 0 );
	if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$1268;
	{
		FBSTRING TMP$607$2;
		FBSTRING TMP$608$2;
		FBSTRING* vr$13 = fb_StrAllocTempDescZEx( (char*)"parsing xpm: ", 13ll );
		fb_PrintString( 0, (FBSTRING*)vr$13, 2 );
		__builtin_memset( &TMP$607$2, 0, 24ll );
		FBSTRING* vr$18 = fb_StrConcat( &TMP$607$2, (void*)&XPMFILE$1, -1ll, (void*)" -o ", 5ll );
		__builtin_memset( &TMP$608$2, 0, 24ll );
		FBSTRING* vr$21 = fb_StrConcat( &TMP$608$2, (void*)vr$18, -1ll, (void*)((uint8*)&FBC$ + 272ll), -1ll );
		fb_PrintString( 0, (FBSTRING*)vr$21, 1 );
	}
	label$1268:;
	label$1267:;
	int64 vr$24 = HPARSEXPM( &XPMFILE$1, &CODE$1 );
	if( vr$24 != 0ll) goto label$1270;
	{
		fb_StrDelete( (FBSTRING*)&CODE$1 );
		fb_StrDelete( (FBSTRING*)&XPMFILE$1 );
		goto label$1262;
	}
	label$1270:;
	label$1269:;
	int32 vr$27 = fb_FileFree(  );
	FO$1 = (int64)vr$27;
	int32 vr$31 = fb_FileOpen( (FBSTRING*)((uint8*)&FBC$ + 272ll), 3u, 0u, 0u, (int32)FO$1, 0 );
	if( (int64)vr$31 == 0ll) goto label$1272;
	{
		fb_StrDelete( (FBSTRING*)&CODE$1 );
		fb_StrDelete( (FBSTRING*)&XPMFILE$1 );
		goto label$1262;
	}
	label$1272:;
	label$1271:;
	TMP$609$1 = FO$1;
	fb_PrintString( (int32)TMP$609$1, (FBSTRING*)&CODE$1, 0 );
	int32 vr$38 = fb_FileClose( (int32)FO$1 );
	if( (int64)vr$38 == 0ll) goto label$1273;
	void* vr$40 = fb_ErrorThrowAt( 3674, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$40;
	label$1273:;
	if( *(int64*)((uint8*)&FBC$ + 80ll) != 0ll) goto label$1275;
	{
		FBCADDTEMP( (FBSTRING*)((uint8*)&FBC$ + 272ll) );
	}
	label$1275:;
	label$1274:;
	HCOMPILEBAS( (struct $9FBCIOFILE*)((uint8*)&FBC$ + 272ll), 0ll, 0ll, -1ll );
	fb$result$1 = -1ll;
	fb_StrDelete( (FBSTRING*)&CODE$1 );
	fb_StrDelete( (FBSTRING*)&XPMFILE$1 );
	label$1262:;
	return fb$result$1;
}

static int64 HCOMPILESTAGE2MODULE( struct $9FBCIOFILE* MODULE$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1276:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	FBSTRING ASMFILE$1;
	__builtin_memset( &ASMFILE$1, 0, 24ll );
	FBSTRING* vr$3 = HGETASMNAME( MODULE$1, 2ll );
	fb_StrAssign( (void*)&ASMFILE$1, -1ll, (void*)vr$3, -1ll, 0 );
	int64 vr$6 = FBGETOPTION( 3ll );
	if( (~(*(int64*)((uint8*)&FBC$ + 96ll)) & ((int64)-(vr$6 != 12ll) | ~(*(int64*)((uint8*)&FBC$ + 104ll)))) == 0ll) goto label$1279;
	{
		FBCADDTEMP( &ASMFILE$1 );
	}
	label$1279:;
	label$1278:;
	{
		int64 TMP$610$2;
		int64 vr$12 = FBGETOPTION( 2ll );
		TMP$610$2 = vr$12;
		if( TMP$610$2 == 1ll) goto label$1282;
		label$1283:;
		if( TMP$610$2 != 2ll) goto label$1281;
		label$1282:;
		{
			int64 TMP$642$3;
			boolean ISM64TARGET$3;
			ISM64TARGET$3 = (boolean)0ll;
			{
				int64 TMP$611$4;
				int64 vr$13 = FBGETCPUFAMILY(  );
				TMP$611$4 = vr$13;
				if( TMP$611$4 != 0ll) goto label$1285;
				label$1286:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-m32 ", 6ll, 0 );
				}
				goto label$1284;
				label$1285:;
				if( TMP$611$4 != 1ll) goto label$1287;
				label$1288:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-m64 ", 6ll, 0 );
					ISM64TARGET$3 = (boolean)1ll;
				}
				goto label$1284;
				label$1287:;
				if( TMP$611$4 != 4ll) goto label$1289;
				label$1290:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-m32 ", 6ll, 0 );
				}
				goto label$1284;
				label$1289:;
				if( TMP$611$4 == 5ll) goto label$1292;
				label$1293:;
				if( TMP$611$4 != 6ll) goto label$1291;
				label$1292:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-m64 ", 6ll, 0 );
					ISM64TARGET$3 = (boolean)1ll;
				}
				label$1291:;
				label$1284:;
			}
			int64 vr$18 = FBGETOPTION( 3ll );
			if( vr$18 == 12ll) goto label$1295;
			{
				{
					int64 TMP$614$5;
					int64 vr$19 = FBGETCPUFAMILY(  );
					TMP$614$5 = vr$19;
					if( TMP$614$5 == 4ll) goto label$1298;
					label$1299:;
					if( TMP$614$5 == 5ll) goto label$1298;
					label$1300:;
					if( TMP$614$5 == 6ll) goto label$1298;
					label$1301:;
					if( TMP$614$5 != 8ll) goto label$1297;
					label$1298:;
					{
						if( *(int64*)((uint8*)&FBC$ + 56ll) == 0ll) goto label$1303;
						{
							fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mcpu=native ", 14ll, 0 );
						}
						goto label$1302;
						label$1303:;
						{
							FBSTRING TMP$617$7;
							FBSTRING TMP$618$7;
							FBSTRING TMP$619$7;
							char* vr$21 = FBGETGCCARCH(  );
							__builtin_memset( &TMP$617$7, 0, 24ll );
							FBSTRING* vr$24 = fb_StrConcat( &TMP$617$7, (void*)"-mcpu=", 7ll, (void*)vr$21, 0ll );
							__builtin_memset( &TMP$618$7, 0, 24ll );
							FBSTRING* vr$27 = fb_StrConcat( &TMP$618$7, (void*)vr$24, -1ll, (void*)" ", 2ll );
							__builtin_memset( &TMP$619$7, 0, 24ll );
							FBSTRING* vr$31 = fb_StrConcat( &TMP$619$7, (void*)&LN$1, -1ll, (void*)vr$27, -1ll );
							fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$31, -1ll, 0 );
						}
						label$1302:;
					}
					goto label$1296;
					label$1297:;
					{
						if( *(int64*)((uint8*)&FBC$ + 56ll) == 0ll) goto label$1306;
						{
							fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-march=native ", 15ll, 0 );
						}
						goto label$1305;
						label$1306:;
						{
							FBSTRING TMP$622$7;
							FBSTRING TMP$623$7;
							FBSTRING TMP$624$7;
							char* vr$34 = FBGETGCCARCH(  );
							__builtin_memset( &TMP$622$7, 0, 24ll );
							FBSTRING* vr$37 = fb_StrConcat( &TMP$622$7, (void*)"-march=", 8ll, (void*)vr$34, 0ll );
							__builtin_memset( &TMP$623$7, 0, 24ll );
							FBSTRING* vr$40 = fb_StrConcat( &TMP$623$7, (void*)vr$37, -1ll, (void*)" ", 2ll );
							__builtin_memset( &TMP$624$7, 0, 24ll );
							FBSTRING* vr$44 = fb_StrConcat( &TMP$624$7, (void*)&LN$1, -1ll, (void*)vr$40, -1ll );
							fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$44, -1ll, 0 );
						}
						label$1305:;
					}
					label$1304:;
					label$1296:;
				}
			}
			label$1295:;
			label$1294:;
			int64 vr$46 = FBGETOPTION( 3ll );
			int64 vr$48 = FBGETOPTION( 4ll );
			if( ((int64)-(vr$46 == 3ll) & (int64)-(vr$48 == 17ll)) == 0ll) goto label$1308;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mfloat-abi=softfp -mfpu=vfpv3-d16 ", 36ll, 0 );
			}
			label$1308:;
			label$1307:;
			int64 vr$52 = FBGETOPTION( 38ll );
			if( vr$52 == 0ll) goto label$1310;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fPIC ", 7ll, 0 );
			}
			label$1310:;
			label$1309:;
			int64 vr$54 = FBGETOPTION( 3ll );
			if( vr$54 == 12ll) goto label$1312;
			{
				int64 vr$55 = FBGETOPTION( 2ll );
				if( vr$55 != 2ll) goto label$1314;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fno-integrated-as ", 20ll, 0 );
				}
				label$1314:;
				label$1313:;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-S ", 4ll, 0 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-nostdlib -nostdinc ", 21ll, 0 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-Wall ", 7ll, 0 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-Wno-unused ", 13ll, 0 );
			}
			goto label$1311;
			label$1312:;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-c -nostdlib -nostdinc -Wall -Wno-unused-label -Wno-unused-function -Wno-unused-variable ", 90ll, 0 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-Wno-warn-absolute-paths ", 26ll, 0 );
			}
			label$1311:;
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-Wno-main ", 11ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-Werror-implicit-function-declaration ", 39ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-O", 3ll, 0 );
			int64 vr$66 = FBGETOPTION( 8ll );
			FBSTRING* vr$67 = fb_LongintToStr( vr$66 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$67, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fno-strict-aliasing ", 22ll, 0 );
			{
				uint64 TMP$640$4;
				int64 vr$71 = FBGETOPTION( 3ll );
				TMP$640$4 = (uint64)vr$71;
				goto label$1316;
				label$1317:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fno-ident ", 12ll, 0 );
				}
				goto label$1315;
				label$1316:;
				static const void* tmp$901[1ll] = {
					&&label$1317,
				};
				if( TMP$640$4 > 0ull ) goto label$1315;
				goto *tmp$901[TMP$640$4 - 0ull];
				label$1315:;
			}
			int64 vr$73 = FBGETOPTION( 3ll );
			if( vr$73 == 12ll) goto label$1318;
			int64 vr$74 = FBGETOPTION( 3ll );
			TMP$642$3 = (int64)-(vr$74 != 3ll);
			goto label$1654;
			label$1318:;
			TMP$642$3 = 0ll;
			label$1654:;
			if( TMP$642$3 == 0ll) goto label$1320;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-frounding-math ", 17ll, 0 );
			}
			label$1320:;
			label$1319:;
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fno-math-errno ", 17ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fwrapv ", 9ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fno-exceptions -fno-asynchronous-unwind-tables ", 49ll, 0 );
			int64 vr$82 = FBGETOPTION( 21ll );
			if( ((int64)-((int64)-ISM64TARGET$3 == -1ll) | (int64)-(vr$82 == -1ll)) == 0ll) goto label$1322;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-funwind-tables ", 17ll, 0 );
			}
			goto label$1321;
			label$1322:;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-fno-unwind-tables ", 20ll, 0 );
			}
			label$1321:;
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-Wno-format ", 13ll, 0 );
			int64 vr$88 = FBGETOPTION( 14ll );
			if( vr$88 == 0ll) goto label$1324;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-g ", 4ll, 0 );
			}
			label$1324:;
			label$1323:;
			int64 vr$90 = FBGETOPTION( 24ll );
			if( vr$90 != 1ll) goto label$1326;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-pg ", 5ll, 0 );
			}
			label$1326:;
			label$1325:;
			int64 vr$92 = FBGETOPTION( 5ll );
			if( vr$92 != 1ll) goto label$1328;
			{
				int64 vr$93 = FBGETOPTION( 3ll );
				if( vr$93 != 3ll) goto label$1330;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mfpmath=sse -mssse3 ", 22ll, 0 );
				}
				goto label$1329;
				label$1330:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mfpmath=sse -msse2 ", 21ll, 0 );
				}
				label$1329:;
			}
			goto label$1327;
			label$1328:;
			int64 vr$96 = FBGETOPTION( 5ll );
			if( vr$96 != 2ll) goto label$1331;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mfpu=neon -funsafe-math-optimizations ", 40ll, 0 );
			}
			label$1331:;
			label$1327:;
			{
				int64 TMP$655$4;
				int64 vr$98 = FBGETCPUFAMILY(  );
				TMP$655$4 = vr$98;
				if( TMP$655$4 == 0ll) goto label$1334;
				label$1335:;
				if( TMP$655$4 != 1ll) goto label$1333;
				label$1334:;
				{
					int64 vr$99 = FBGETOPTION( 9ll );
					if( vr$99 != 0ll) goto label$1337;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-masm=intel ", 13ll, 0 );
					}
					label$1337:;
					label$1336:;
				}
				label$1333:;
				label$1332:;
			}
		}
		goto label$1280;
		label$1281:;
		if( TMP$610$2 != 3ll) goto label$1338;
		label$1339:;
		{
			{
				int64 TMP$657$4;
				int64 vr$101 = FBGETCPUFAMILY(  );
				TMP$657$4 = vr$101;
				if( TMP$657$4 != 0ll) goto label$1341;
				label$1342:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-march=x86 ", 12ll, 0 );
				}
				goto label$1340;
				label$1341:;
				if( TMP$657$4 != 1ll) goto label$1343;
				label$1344:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-march=x86-64 ", 15ll, 0 );
				}
				goto label$1340;
				label$1343:;
				if( TMP$657$4 != 2ll) goto label$1345;
				label$1346:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-march=arm ", 12ll, 0 );
				}
				goto label$1340;
				label$1345:;
				if( TMP$657$4 != 3ll) goto label$1347;
				label$1348:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-march=armv8-a ", 16ll, 0 );
				}
				goto label$1340;
				label$1347:;
				if( TMP$657$4 != 4ll) goto label$1349;
				label$1350:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mcpu=powerpc ", 15ll, 0 );
				}
				goto label$1340;
				label$1349:;
				if( TMP$657$4 != 5ll) goto label$1351;
				label$1352:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mcpu=powerpc64 ", 17ll, 0 );
				}
				goto label$1340;
				label$1351:;
				if( TMP$657$4 != 6ll) goto label$1353;
				label$1354:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-mcpu=powerpc64le ", 19ll, 0 );
				}
				label$1353:;
				label$1340:;
			}
			int64 vr$109 = FBGETOPTION( 38ll );
			if( vr$109 == 0ll) goto label$1356;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-relocation-model=pic ", 23ll, 0 );
			}
			label$1356:;
			label$1355:;
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-O", 3ll, 0 );
			int64 vr$112 = FBGETOPTION( 8ll );
			FBSTRING* vr$113 = fb_LongintToStr( vr$112 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$113, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
			{
				int64 TMP$666$4;
				int64 vr$116 = FBGETCPUFAMILY(  );
				TMP$666$4 = vr$116;
				if( TMP$666$4 == 0ll) goto label$1359;
				label$1360:;
				if( TMP$666$4 != 1ll) goto label$1358;
				label$1359:;
				{
					int64 vr$117 = FBGETOPTION( 9ll );
					if( vr$117 != 0ll) goto label$1362;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"--x86-asm-syntax=intel ", 24ll, 0 );
					}
					label$1362:;
					label$1361:;
				}
				label$1358:;
				label$1357:;
			}
		}
		label$1338:;
		label$1280:;
	}
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	FBSTRING* vr$120 = HGETASMNAME( MODULE$1, 1ll );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$120, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22 ", 3ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-o \x22", 5ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&ASMFILE$1, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)((uint8*)&FBC$ + 2072ll), -1ll, 0 );
	$7FBCTOOL CCOMPILER$1;
	CCOMPILER$1 = 0ll;
	{
		int64 TMP$670$2;
		int64 vr$129 = FBGETOPTION( 2ll );
		TMP$670$2 = vr$129;
		if( TMP$670$2 != 1ll) goto label$1364;
		label$1365:;
		{
			CCOMPILER$1 = 4ll;
			int64 vr$130 = FBGETOPTION( 3ll );
			if( vr$130 != 12ll) goto label$1367;
			{
				CCOMPILER$1 = 15ll;
			}
			label$1367:;
			label$1366:;
			int64 vr$132 = FBCRUNBIN( (char*)"compiling C", CCOMPILER$1, &LN$1 );
			fb$result$1 = vr$132;
		}
		goto label$1363;
		label$1364:;
		if( TMP$670$2 != 2ll) goto label$1368;
		label$1369:;
		{
			CCOMPILER$1 = 6ll;
			int64 vr$134 = FBCRUNBIN( (char*)"compiling C", CCOMPILER$1, &LN$1 );
			fb$result$1 = vr$134;
		}
		goto label$1363;
		label$1368:;
		if( TMP$670$2 != 3ll) goto label$1370;
		label$1371:;
		{
			CCOMPILER$1 = 5ll;
			int64 vr$136 = FBCRUNBIN( (char*)"compiling LLVM IR", CCOMPILER$1, &LN$1 );
			fb$result$1 = vr$136;
		}
		label$1370:;
		label$1363:;
	}
	fb_StrDelete( (FBSTRING*)&ASMFILE$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$1277:;
	return fb$result$1;
}

static void HCOMPILESTAGE2MODULES( void )
{
	label$1372:;
	struct $9FBCIOFILE* MODULE$1;
	void* vr$1 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 144ll) );
	MODULE$1 = (struct $9FBCIOFILE*)vr$1;
	label$1374:;
	if( MODULE$1 == (struct $9FBCIOFILE*)0ull) goto label$1375;
	{
		int64 vr$2 = HCOMPILESTAGE2MODULE( MODULE$1 );
		if( vr$2 != 0ll) goto label$1377;
		{
			FBCEND( 1ll );
		}
		label$1377:;
		label$1376:;
		void* vr$3 = LISTGETNEXT( (void*)MODULE$1 );
		MODULE$1 = (struct $9FBCIOFILE*)vr$3;
	}
	goto label$1374;
	label$1375:;
	label$1373:;
}

static int64 HASSEMBLEMODULE( struct $9FBCIOFILE* MODULE$1 )
{
	FBSTRING TMP$680$1;
	FBSTRING TMP$681$1;
	FBSTRING TMP$682$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1378:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	$7FBCTOOL ASSEMBLER$1;
	ASSEMBLER$1 = 0ll;
	int64 vr$2 = FBGETOPTION( 3ll );
	int64 vr$4 = FBGETCPUFAMILY(  );
	if( ((int64)-(vr$2 == 0ll) & (int64)-(vr$4 == 3ll)) == 0ll) goto label$1381;
	{
		ASSEMBLER$1 = 4ll;
	}
	label$1381:;
	label$1380:;
	if( ASSEMBLER$1 != 0ll) goto label$1383;
	{
		{
			int64 TMP$673$3;
			int64 vr$7 = FBGETOPTION( 3ll );
			TMP$673$3 = vr$7;
			if( TMP$673$3 != 12ll) goto label$1385;
			label$1386:;
			{
				ASSEMBLER$1 = 0ll;
			}
			goto label$1384;
			label$1385:;
			{
				ASSEMBLER$1 = 1ll;
			}
			label$1387:;
			label$1384:;
		}
	}
	label$1383:;
	label$1382:;
	if( ASSEMBLER$1 != 0ll) goto label$1389;
	{
		fb$result$1 = -1ll;
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$1379;
	}
	label$1389:;
	label$1388:;
	{
		if( ASSEMBLER$1 == 6ll) goto label$1392;
		label$1393:;
		if( ASSEMBLER$1 != 4ll) goto label$1391;
		label$1392:;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-c ", 4ll, 0 );
		}
		goto label$1390;
		label$1391:;
		{
			{
				int64 TMP$675$4;
				int64 vr$10 = FBGETCPUFAMILY(  );
				TMP$675$4 = vr$10;
				if( TMP$675$4 != 0ll) goto label$1396;
				label$1397:;
				{
					int64 vr$11 = FBGETOPTION( 3ll );
					if( vr$11 != 10ll) goto label$1399;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-arch i386 ", 12ll, 0 );
					}
					goto label$1398;
					label$1399:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"--32 ", 6ll, 0 );
					}
					label$1398:;
				}
				goto label$1395;
				label$1396:;
				if( TMP$675$4 != 1ll) goto label$1400;
				label$1401:;
				{
					int64 vr$14 = FBGETOPTION( 3ll );
					if( vr$14 != 10ll) goto label$1403;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"-arch x86_64 ", 14ll, 0 );
					}
					goto label$1402;
					label$1403:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"--64 ", 6ll, 0 );
					}
					label$1402:;
				}
				label$1400:;
				label$1395:;
			}
			int64 vr$17 = FBGETOPTION( 14ll );
			if( vr$17 != 0ll) goto label$1405;
			{
				int64 TMP$678$4;
				int64 vr$18 = FBGETCPUFAMILY(  );
				if( vr$18 == 0ll) goto label$1406;
				int64 vr$19 = FBGETCPUFAMILY(  );
				TMP$678$4 = (int64)-(vr$19 == 1ll);
				goto label$1655;
				label$1406:;
				TMP$678$4 = -1ll;
				label$1655:;
				if( TMP$678$4 == 0ll) goto label$1408;
				{
					int64 vr$21 = FBGETOPTION( 3ll );
					if( vr$21 == 10ll) goto label$1410;
					{
						int64 vr$22 = FBGETOPTION( 3ll );
						if( vr$22 == 12ll) goto label$1412;
						{
							fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"--strip-local-absolute ", 24ll, 0 );
						}
						label$1412:;
						label$1411:;
					}
					label$1410:;
					label$1409:;
				}
				label$1408:;
				label$1407:;
			}
			label$1405:;
			label$1404:;
		}
		label$1394:;
		label$1390:;
	}
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	FBSTRING* vr$25 = HGETASMNAME( MODULE$1, 2ll );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$25, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22 ", 3ll, 0 );
	__builtin_memset( &TMP$680$1, 0, 24ll );
	FBSTRING* vr$31 = fb_StrConcat( &TMP$680$1, (void*)"-o \x22", 5ll, *(void**)((uint8*)MODULE$1 + 24ll), -1ll );
	__builtin_memset( &TMP$681$1, 0, 24ll );
	FBSTRING* vr$34 = fb_StrConcat( &TMP$681$1, (void*)vr$31, -1ll, (void*)"\x22", 2ll );
	__builtin_memset( &TMP$682$1, 0, 24ll );
	FBSTRING* vr$38 = fb_StrConcat( &TMP$682$1, (void*)&LN$1, -1ll, (void*)vr$34, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$38, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)((uint8*)&FBC$ + 2024ll), -1ll, 0 );
	int64 vr$43 = FBCRUNBIN( (char*)"assembling", ASSEMBLER$1, &LN$1 );
	if( vr$43 != 0ll) goto label$1414;
	{
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$1379;
	}
	label$1414:;
	label$1413:;
	if( *(int64*)((uint8*)&FBC$ + 104ll) != 0ll) goto label$1416;
	{
		FBCADDTEMP( *(FBSTRING**)((uint8*)MODULE$1 + 24ll) );
	}
	label$1416:;
	label$1415:;
	fb$result$1 = -1ll;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$1379:;
	return fb$result$1;
}

static void HASSEMBLEMODULES( void )
{
	label$1417:;
	struct $9FBCIOFILE* MODULE$1;
	void* vr$1 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 144ll) );
	MODULE$1 = (struct $9FBCIOFILE*)vr$1;
	label$1419:;
	if( MODULE$1 == (struct $9FBCIOFILE*)0ull) goto label$1420;
	{
		int64 vr$2 = HASSEMBLEMODULE( MODULE$1 );
		if( vr$2 != 0ll) goto label$1422;
		{
			FBCEND( 1ll );
		}
		label$1422:;
		label$1421:;
		void* vr$3 = LISTGETNEXT( (void*)MODULE$1 );
		MODULE$1 = (struct $9FBCIOFILE*)vr$3;
	}
	goto label$1419;
	label$1420:;
	label$1418:;
}

static int64 HASSEMBLERC( struct $9FBCIOFILE* RC$1 )
{
	FBSTRING TMP$685$1;
	FBSTRING TMP$686$1;
	FBSTRING TMP$687$1;
	FBSTRING TMP$688$1;
	FBSTRING TMP$689$1;
	FBSTRING TMP$690$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1423:;
	FBSTRING LN$1;
	fb_StrInit( (void*)&LN$1, -1ll, (void*)"--output-format=coff --include-dir=.", 37ll, 0 );
	__builtin_memset( &TMP$685$1, 0, 24ll );
	FBSTRING* vr$6 = fb_StrConcat( &TMP$685$1, (void*)" \x22", 3ll, (void*)RC$1, -1ll );
	__builtin_memset( &TMP$686$1, 0, 24ll );
	FBSTRING* vr$9 = fb_StrConcat( &TMP$686$1, (void*)vr$6, -1ll, (void*)"\x22", 2ll );
	__builtin_memset( &TMP$687$1, 0, 24ll );
	FBSTRING* vr$13 = fb_StrConcat( &TMP$687$1, (void*)&LN$1, -1ll, (void*)vr$9, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$13, -1ll, 0 );
	__builtin_memset( &TMP$688$1, 0, 24ll );
	FBSTRING* vr$18 = fb_StrConcat( &TMP$688$1, (void*)" \x22", 3ll, *(void**)((uint8*)RC$1 + 24ll), -1ll );
	__builtin_memset( &TMP$689$1, 0, 24ll );
	FBSTRING* vr$21 = fb_StrConcat( &TMP$689$1, (void*)vr$18, -1ll, (void*)"\x22", 2ll );
	__builtin_memset( &TMP$690$1, 0, 24ll );
	FBSTRING* vr$25 = fb_StrConcat( &TMP$690$1, (void*)&LN$1, -1ll, (void*)vr$21, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$25, -1ll, 0 );
	int64 vr$28 = FBCRUNBIN( (char*)"compiling rc", 9ll, &LN$1 );
	fb$result$1 = vr$28;
	if( *(int64*)((uint8*)&FBC$ + 104ll) != 0ll) goto label$1426;
	{
		FBCADDTEMP( *(FBSTRING**)((uint8*)RC$1 + 24ll) );
	}
	label$1426:;
	label$1425:;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$1424:;
	return fb$result$1;
}

static void HASSEMBLERCS( void )
{
	label$1427:;
	struct $9FBCIOFILE* RC$1;
	void* vr$1 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 208ll) );
	RC$1 = (struct $9FBCIOFILE*)vr$1;
	label$1429:;
	if( RC$1 == (struct $9FBCIOFILE*)0ull) goto label$1430;
	{
		int64 vr$2 = HASSEMBLERC( RC$1 );
		if( vr$2 != 0ll) goto label$1432;
		{
			FBCEND( 1ll );
		}
		label$1432:;
		label$1431:;
		void* vr$3 = LISTGETNEXT( (void*)RC$1 );
		RC$1 = (struct $9FBCIOFILE*)vr$3;
	}
	goto label$1429;
	label$1430:;
	label$1428:;
}

static void HASSEMBLEXPM( void )
{
	label$1433:;
	int64 vr$1 = fb_StrLen( (void*)((uint8*)&FBC$ + 272ll), -1ll );
	if( vr$1 <= 0ll) goto label$1436;
	{
		int64 vr$2 = FBGETOPTION( 2ll );
		if( vr$2 == 0ll) goto label$1438;
		{
			HCOMPILESTAGE2MODULE( (struct $9FBCIOFILE*)((uint8*)&FBC$ + 272ll) );
		}
		label$1438:;
		label$1437:;
		int64 vr$5 = HASSEMBLEMODULE( (struct $9FBCIOFILE*)((uint8*)&FBC$ + 272ll) );
		if( vr$5 != 0ll) goto label$1440;
		{
			FBCEND( 1ll );
		}
		label$1440:;
		label$1439:;
	}
	label$1436:;
	label$1435:;
	label$1434:;
}

static int64 HCOMPILEFBCTINF( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1441:;
	struct $9FBCIOFILE FBCTINF$1;
	_ZN9FBCIOFILEC1Ev( &FBCTINF$1 );
	FBSTRING OBJFILE$1;
	__builtin_memset( &OBJFILE$1, 0, 24ll );
	int64 FO$1;
	fb_StrAssign( (void*)&FBCTINF$1, -1ll, (void*)"__fb_ct.inf.bas", 16ll, 0 );
	fb_StrAssign( (void*)&OBJFILE$1, -1ll, (void*)"__fb_ct.inf", 12ll, 0 );
	*(FBSTRING**)((uint8*)&FBCTINF$1 + 24ll) = &OBJFILE$1;
	if( *(int64*)((uint8*)&FBC$ + 112ll) == 0ll) goto label$1444;
	{
		FBSTRING* vr$6 = fb_StrAllocTempDescZEx( (char*)"creating: ", 10ll );
		fb_PrintString( 0, (FBSTRING*)vr$6, 2 );
		fb_PrintString( 0, (FBSTRING*)&FBCTINF$1, 1 );
	}
	label$1444:;
	label$1443:;
	int32 vr$8 = fb_FileFree(  );
	FO$1 = (int64)vr$8;
	int32 vr$12 = fb_FileOpen( (FBSTRING*)&FBCTINF$1, 3u, 0u, 0u, (int32)FO$1, 0 );
	if( (int64)vr$12 == 0ll) goto label$1446;
	{
		fb_StrDelete( (FBSTRING*)&OBJFILE$1 );
		_ZN9FBCIOFILED1Ev( &FBCTINF$1 );
		goto label$1442;
	}
	label$1446:;
	label$1445:;
	int32 vr$17 = fb_FileClose( (int32)FO$1 );
	if( (int64)vr$17 == 0ll) goto label$1447;
	void* vr$19 = fb_ErrorThrowAt( 4165, (char*)"fbc.bas", (void*)0ull, (void*)0ull );
	goto *vr$19;
	label$1447:;
	if( *(int64*)((uint8*)&FBC$ + 80ll) != 0ll) goto label$1449;
	{
		FBCADDTEMP( (FBSTRING*)&FBCTINF$1 );
	}
	label$1449:;
	label$1448:;
	HCOMPILEBAS( &FBCTINF$1, 0ll, -1ll, -1ll );
	int64 vr$22 = FBGETOPTION( 2ll );
	if( vr$22 == 0ll) goto label$1451;
	{
		HCOMPILESTAGE2MODULE( &FBCTINF$1 );
	}
	label$1451:;
	label$1450:;
	int64 vr$25 = HASSEMBLEMODULE( &FBCTINF$1 );
	fb$result$1 = vr$25;
	fb_StrDelete( (FBSTRING*)&OBJFILE$1 );
	_ZN9FBCIOFILED1Ev( &FBCTINF$1 );
	label$1442:;
	return fb$result$1;
}

static int64 HARCHIVEFILES( void )
{
	FBSTRING TMP$695$1;
	FBSTRING TMP$696$1;
	FBSTRING TMP$704$1;
	int64 TMP$705$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$1452:;
	HSETOUTNAME(  );
	FBSTRING* vr$2 = fb_StrAllocTempDescZ( (char*)((uint8*)&FBC$ + 968ll) );
	int32 vr$3 = fb_FileKill( (FBSTRING*)vr$2 );
	if( (int64)vr$3 == 0ll) goto label$1455;
	{
	}
	label$1455:;
	label$1454:;
	FBSTRING LN$1;
	__builtin_memset( &TMP$695$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$695$1, (void*)"-rsc \x22", 7ll, (void*)((uint8*)&FBC$ + 968ll), 261ll );
	__builtin_memset( &TMP$696$1, 0, 24ll );
	FBSTRING* vr$11 = fb_StrConcat( &TMP$696$1, (void*)vr$8, -1ll, (void*)"\x22 ", 3ll );
	fb_StrInit( (void*)&LN$1, -1ll, (void*)vr$11, -1ll, 0 );
	int64 vr$13 = FBGETOPTION( 40ll );
	int64 vr$14 = FBISCROSSCOMP(  );
	if( (vr$13 & ~vr$14) == 0ll) goto label$1457;
	{
		FBSTRING TMP$700$2;
		int64 vr$17 = HCOMPILEFBCTINF(  );
		if( vr$17 == 0ll) goto label$1459;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22__fb_ct.inf\x22 ", 15ll, 0 );
		}
		label$1459:;
		label$1458:;
		__builtin_memset( &TMP$700$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$700$2, -1ll, (void*)"__fb_ct.inf", 12ll, 0 );
		FBCADDTEMP( &TMP$700$2 );
		fb_StrDelete( (FBSTRING*)&TMP$700$2 );
	}
	label$1457:;
	label$1456:;
	FBSTRING* OBJFILE$1;
	void* vr$24 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 400ll) );
	OBJFILE$1 = (FBSTRING*)vr$24;
	label$1460:;
	if( OBJFILE$1 == (FBSTRING*)0ull) goto label$1461;
	{
		FBSTRING TMP$701$2;
		FBSTRING TMP$702$2;
		FBSTRING TMP$703$2;
		__builtin_memset( &TMP$701$2, 0, 24ll );
		FBSTRING* vr$27 = fb_StrConcat( &TMP$701$2, (void*)"\x22", 2ll, (void*)OBJFILE$1, -1ll );
		__builtin_memset( &TMP$702$2, 0, 24ll );
		FBSTRING* vr$30 = fb_StrConcat( &TMP$702$2, (void*)vr$27, -1ll, (void*)"\x22 ", 3ll );
		__builtin_memset( &TMP$703$2, 0, 24ll );
		FBSTRING* vr$34 = fb_StrConcat( &TMP$703$2, (void*)&LN$1, -1ll, (void*)vr$30, -1ll );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$34, -1ll, 0 );
		void* vr$36 = LISTGETNEXT( (void*)OBJFILE$1 );
		OBJFILE$1 = (FBSTRING*)vr$36;
	}
	goto label$1460;
	label$1461:;
	$7FBCTOOL AR$1;
	AR$1 = 2ll;
	int64 vr$37 = FBGETOPTION( 3ll );
	if( vr$37 != 12ll) goto label$1463;
	{
		AR$1 = 13ll;
	}
	label$1463:;
	label$1462:;
	uint32 TARGETPREFIXLEN$1;
	__builtin_memset( &TARGETPREFIXLEN$1, 0, 4ll );
	int64 vr$40 = fb_StrLen( (void*)((uint8*)&FBC$ + 2225ll), 129ll );
	TARGETPREFIXLEN$1 = (uint32)vr$40;
	int64 TOOLNAMELEN$1;
	__builtin_memset( &TMP$704$1, 0, 24ll );
	FBSTRING* vr$46 = fb_StrConcat( &TMP$704$1, (void*)((int64)(struct $11FBCTOOLINFO*)FBCTOOLTB$ + (AR$1 * 304ll)), 16ll, (void*)".exe", 5ll );
	int64 vr$47 = fb_StrLen( (void*)vr$46, -1ll );
	int64 vr$50 = fb_StrLen( (void*)((uint8*)&FBC$ + 3820ll), 261ll );
	if( (int64)TARGETPREFIXLEN$1 <= vr$50) goto label$1464;
	TMP$705$1 = (int64)TARGETPREFIXLEN$1;
	goto label$1656;
	label$1464:;
	int64 vr$53 = fb_StrLen( (void*)((uint8*)&FBC$ + 3820ll), 261ll );
	TMP$705$1 = vr$53;
	label$1656:;
	TOOLNAMELEN$1 = vr$47 + TMP$705$1;
	int64 vr$55 = FBGETOPTION( 3ll );
	int64 vr$58 = fb_StrLen( (void*)&LN$1, -1ll );
	if( ((int64)-(vr$55 == 4ll) | (int64)-(vr$58 > (2047ll - TOOLNAMELEN$1))) == 0ll) goto label$1466;
	{
		int64 vr$63 = HPUTLDARGSINTOFILE( &LN$1 );
		if( vr$63 != 0ll) goto label$1468;
		{
			fb_StrDelete( (FBSTRING*)&LN$1 );
			goto label$1453;
		}
		label$1468:;
		label$1467:;
	}
	label$1466:;
	label$1465:;
	int64 vr$66 = FBCRUNBIN( (char*)"archiving", AR$1, &LN$1 );
	fb$result$1 = vr$66;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$1453:;
	return fb$result$1;
}

static void HSETDEFAULTLIBPATHS( void )
{
	FBSTRING TMP$707$1;
	FBSTRING TMP$708$1;
	label$1469:;
	__builtin_memset( &TMP$707$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$707$1, -1ll, (void*)((uint8*)&FBC$ + 3559ll), 261ll, 0 );
	FBCADDDEFLIBPATH( &TMP$707$1 );
	fb_StrAssign( (void*)((uint8*)&FBC$ + 3559ll), 261ll, (void*)&TMP$707$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&TMP$707$1 );
	__builtin_memset( &TMP$708$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$708$1, -1ll, (void*)".", 2ll, 0 );
	FBCADDDEFLIBPATH( &TMP$708$1 );
	fb_StrDelete( (FBSTRING*)&TMP$708$1 );
	{
		int64 TMP$709$2;
		int64 vr$11 = FBGETOPTION( 3ll );
		TMP$709$2 = vr$11;
		if( TMP$709$2 != 3ll) goto label$1472;
		label$1473:;
		{
		}
		goto label$1471;
		label$1472:;
		if( TMP$709$2 != 12ll) goto label$1474;
		label$1475:;
		{
		}
		goto label$1471;
		label$1474:;
		{
			FBCADDLIBPATHFOR( (char*)"libgcc.a" );
			{
				int64 TMP$711$4;
				int64 vr$12 = FBGETOPTION( 3ll );
				TMP$711$4 = vr$12;
				if( TMP$711$4 != 6ll) goto label$1478;
				label$1479:;
				{
					FBCADDLIBPATHFOR( (char*)"libc++.so" );
				}
				goto label$1477;
				label$1478:;
				if( TMP$711$4 != 4ll) goto label$1480;
				label$1481:;
				{
					FBCADDLIBPATHFOR( (char*)"libstdcx.a" );
				}
				goto label$1477;
				label$1480:;
				{
					FBCADDLIBPATHFOR( (char*)"libstdc++.so" );
				}
				label$1482:;
				label$1477:;
			}
		}
		label$1476:;
		label$1471:;
	}
	{
		int64 TMP$715$2;
		int64 vr$13 = FBGETOPTION( 3ll );
		TMP$715$2 = vr$13;
		if( TMP$715$2 != 4ll) goto label$1484;
		label$1485:;
		{
			FBCADDLIBPATHFOR( (char*)"libm.a" );
		}
		goto label$1483;
		label$1484:;
		if( TMP$715$2 != 0ll) goto label$1486;
		label$1487:;
		{
			FBCADDLIBPATHFOR( (char*)"libmingw32.a" );
		}
		label$1486:;
		label$1483:;
	}
	label$1470:;
}

static void FBCADDDEFLIB( char* LIBNAME$1 )
{
	FBSTRING TMP$718$1;
	label$1488:;
	__builtin_memset( &TMP$718$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$718$1, -1ll, (void*)LIBNAME$1, 0ll, 0 );
	STRSETADD( (struct $7TSTRSET*)((uint8*)&FBC$ + 792ll), &TMP$718$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$718$1 );
	label$1489:;
}

static FBSTRING* HGETFBLIBNAMESUFFIX( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$1490:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	int64 vr$2 = FBGETOPTION( 36ll );
	if( vr$2 == 0ll) goto label$1493;
	{
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"mt", 3ll, 0 );
	}
	label$1493:;
	label$1492:;
	int64 vr$4 = FBGETOPTION( 38ll );
	if( vr$4 == 0ll) goto label$1495;
	{
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"pic", 4ll, 0 );
	}
	label$1495:;
	label$1494:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$1491:;
	FBSTRING* vr$10 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$10;
}

static void HADDDEFAULTLIBS( void )
{
	label$1496:;
	int64 vr$0 = FBGETOPTION( 33ll );
	if( vr$0 == 0ll) goto label$1499;
	{
		FBSTRING TMP$719$2;
		FBSTRING TMP$720$2;
		__builtin_memset( &TMP$720$2, 0, 24ll );
		FBSTRING* vr$2 = HGETFBLIBNAMESUFFIX(  );
		__builtin_memset( &TMP$719$2, 0, 24ll );
		FBSTRING* vr$5 = fb_StrConcat( &TMP$719$2, (void*)"fbrt", 5ll, (void*)vr$2, -1ll );
		fb_StrAssign( (void*)&TMP$720$2, -1ll, (void*)vr$5, -1ll, 0 );
		FBCADDDEFLIB( (char*)*(char**)&TMP$720$2 );
		fb_StrDelete( (FBSTRING*)&TMP$720$2 );
	}
	goto label$1498;
	label$1499:;
	{
		FBSTRING TMP$721$2;
		FBSTRING TMP$722$2;
		__builtin_memset( &TMP$722$2, 0, 24ll );
		FBSTRING* vr$9 = HGETFBLIBNAMESUFFIX(  );
		__builtin_memset( &TMP$721$2, 0, 24ll );
		FBSTRING* vr$12 = fb_StrConcat( &TMP$721$2, (void*)"fb", 3ll, (void*)vr$9, -1ll );
		fb_StrAssign( (void*)&TMP$722$2, -1ll, (void*)vr$12, -1ll, 0 );
		FBCADDDEFLIB( (char*)*(char**)&TMP$722$2 );
		fb_StrDelete( (FBSTRING*)&TMP$722$2 );
	}
	label$1498:;
	int64 vr$15 = FBGETOPTION( 37ll );
	if( vr$15 == 0ll) goto label$1501;
	{
		FBSTRING TMP$723$2;
		FBSTRING TMP$724$2;
		__builtin_memset( &TMP$724$2, 0, 24ll );
		FBSTRING* vr$17 = HGETFBLIBNAMESUFFIX(  );
		__builtin_memset( &TMP$723$2, 0, 24ll );
		FBSTRING* vr$20 = fb_StrConcat( &TMP$723$2, (void*)"fbgfx", 6ll, (void*)vr$17, -1ll );
		fb_StrAssign( (void*)&TMP$724$2, -1ll, (void*)vr$20, -1ll, 0 );
		FBCADDDEFLIB( (char*)*(char**)&TMP$724$2 );
		fb_StrDelete( (FBSTRING*)&TMP$724$2 );
		{
			uint64 TMP$725$3;
			int64 vr$23 = FBGETOPTION( 3ll );
			TMP$725$3 = (uint64)vr$23;
			goto label$1503;
			label$1504:;
			{
				FBCADDDEFLIB( (char*)"gdi32" );
				FBCADDDEFLIB( (char*)"winmm" );
			}
			goto label$1502;
			label$1505:;
			{
				FBCADDDEFLIB( (char*)"X11" );
				FBCADDDEFLIB( (char*)"Xext" );
				FBCADDDEFLIB( (char*)"Xpm" );
				FBCADDDEFLIB( (char*)"Xrandr" );
				FBCADDDEFLIB( (char*)"Xrender" );
			}
			goto label$1502;
			label$1506:;
			{
				ERRREPORTEX( 329ll, (char*)"", -1ll, 1ll, (char*)0ull );
			}
			goto label$1502;
			label$1503:;
			static const void* tmp$902[12ll] = {
				&&label$1504,
				&&label$1504,
				&&label$1505,
				&&label$1506,
				&&label$1502,
				&&label$1502,
				&&label$1505,
				&&label$1505,
				&&label$1505,
				&&label$1505,
				&&label$1505,
				&&label$1505,
			};
			if( TMP$725$3 > 11ull ) goto label$1502;
			goto *tmp$902[TMP$725$3 - 0ull];
			label$1502:;
		}
	}
	label$1501:;
	label$1500:;
	{
		uint64 TMP$733$2;
		int64 vr$24 = FBGETOPTION( 3ll );
		TMP$733$2 = (uint64)vr$24;
		goto label$1508;
		label$1509:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"cygwin" );
			FBCADDDEFLIB( (char*)"kernel32" );
			FBCADDDEFLIB( (char*)"user32" );
			int64 vr$25 = FBGETOPTION( 24ll );
			if( vr$25 != 1ll) goto label$1511;
			{
				FBCADDDEFLIB( (char*)"gmon" );
			}
			label$1511:;
			label$1510:;
		}
		goto label$1507;
		label$1512:;
		{
			FBCADDDEFLIB( (char*)"System" );
			FBCADDDEFLIB( (char*)"pthread" );
			FBCADDDEFLIB( (char*)"ncurses" );
		}
		goto label$1507;
		label$1513:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"amiga" );
			FBCADDDEFLIB( (char*)"m" );
		}
		goto label$1507;
		label$1514:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"arosc" );
			FBCADDDEFLIB( (char*)"autoinit" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"m" );
		}
		goto label$1507;
		label$1515:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"m" );
		}
		goto label$1507;
		label$1516:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"m" );
			int64 vr$26 = FBGETOPTION( 36ll );
			if( vr$26 == 0ll) goto label$1518;
			{
				FBCADDDEFLIB( (char*)"pthread" );
				FBCADDDEFLIB( (char*)"socket" );
			}
			label$1518:;
			label$1517:;
		}
		goto label$1507;
		label$1519:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"pthread" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"m" );
			FBCADDDEFLIB( (char*)"ncurses" );
		}
		goto label$1507;
		label$1520:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"pthread" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"m" );
			FBCADDDEFLIB( (char*)"ncurses" );
		}
		goto label$1507;
		label$1521:;
		{
			FBSTRING* vr$27 = FBCFINDLIBFILE( (char*)"libtinfo.a" );
			int64 vr$28 = fb_StrLen( (void*)vr$27, -1ll );
			FBSTRING* vr$30 = FBCFINDLIBFILE( (char*)"libtinfo.so" );
			int64 vr$31 = fb_StrLen( (void*)vr$30, -1ll );
			if( ((int64)-(vr$28 > 0ll) | (int64)-(vr$31 > 0ll)) == 0ll) goto label$1523;
			{
				FBCADDDEFLIB( (char*)"tinfo" );
			}
			goto label$1522;
			label$1523:;
			{
				FBCADDDEFLIB( (char*)"ncurses" );
			}
			label$1522:;
			FBCADDDEFLIB( (char*)"m" );
			FBCADDDEFLIB( (char*)"dl" );
			FBCADDDEFLIB( (char*)"pthread" );
			FBCADDDEFLIB( (char*)"gcc" );
			FBSTRING* vr$34 = FBCFINDLIBFILE( (char*)"libgcc_eh.a" );
			int64 vr$35 = fb_StrLen( (void*)vr$34, -1ll );
			FBSTRING* vr$37 = FBCFINDLIBFILE( (char*)"libgcc_eh.so" );
			int64 vr$38 = fb_StrLen( (void*)vr$37, -1ll );
			if( ((int64)-(vr$35 > 0ll) | (int64)-(vr$38 > 0ll)) == 0ll) goto label$1525;
			{
				FBCADDDEFLIB( (char*)"gcc_eh" );
			}
			label$1525:;
			label$1524:;
			FBCADDDEFLIB( (char*)"c" );
		}
		goto label$1507;
		label$1526:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"pthread" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"m" );
			FBCADDDEFLIB( (char*)"ncurses" );
		}
		goto label$1507;
		label$1527:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"pthread" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"m" );
			FBCADDDEFLIB( (char*)"ncurses" );
		}
		goto label$1507;
		label$1528:;
		{
			FBCADDDEFLIB( (char*)"m" );
			FBCADDDEFLIB( (char*)"dl" );
			FBCADDDEFLIB( (char*)"c" );
		}
		goto label$1507;
		label$1529:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"msvcrt" );
			FBCADDDEFLIB( (char*)"kernel32" );
			FBCADDDEFLIB( (char*)"user32" );
			FBCADDDEFLIB( (char*)"mingw32" );
			FBCADDDEFLIB( (char*)"mingwex" );
			FBCADDDEFLIB( (char*)"moldname" );
			FBSTRING* vr$41 = FBCFINDLIBFILE( (char*)"libgcc_eh.a" );
			int64 vr$42 = fb_StrLen( (void*)vr$41, -1ll );
			FBSTRING* vr$44 = FBCFINDLIBFILE( (char*)"libgcc_eh.dll.a" );
			int64 vr$45 = fb_StrLen( (void*)vr$44, -1ll );
			if( ((int64)-(vr$42 > 0ll) | (int64)-(vr$45 > 0ll)) == 0ll) goto label$1531;
			{
				FBCADDDEFLIB( (char*)"gcc_eh" );
			}
			label$1531:;
			label$1530:;
			int64 vr$48 = FBGETOPTION( 24ll );
			if( vr$48 != 1ll) goto label$1533;
			{
				FBCADDDEFLIB( (char*)"gmon" );
			}
			label$1533:;
			label$1532:;
		}
		goto label$1507;
		label$1534:;
		{
			FBCADDDEFLIB( (char*)"gcc" );
			FBCADDDEFLIB( (char*)"fbgfx" );
			FBCADDDEFLIB( (char*)"openxdk" );
			FBCADDDEFLIB( (char*)"hal" );
			FBCADDDEFLIB( (char*)"c" );
			FBCADDDEFLIB( (char*)"usb" );
			FBCADDDEFLIB( (char*)"xboxkrnl" );
			FBCADDDEFLIB( (char*)"m" );
			int64 vr$49 = FBGETOPTION( 24ll );
			if( vr$49 != 1ll) goto label$1536;
			{
				FBCADDDEFLIB( (char*)"gmon" );
			}
			label$1536:;
			label$1535:;
		}
		goto label$1507;
		label$1508:;
		static const void* tmp$903[17ll] = {
			&&label$1529,
			&&label$1509,
			&&label$1521,
			&&label$1528,
			&&label$1516,
			&&label$1534,
			&&label$1519,
			&&label$1520,
			&&label$1520,
			&&label$1527,
			&&label$1512,
			&&label$1526,
			&&label$1507,
			&&label$1513,
			&&label$1514,
			&&label$1515,
			&&label$1515,
		};
		if( TMP$733$2 > 16ull ) goto label$1507;
		goto *tmp$903[TMP$733$2 - 0ull];
		label$1507:;
	}
	label$1497:;
}

static void HEXCLUDELIBSFROMLINK( void )
{
	label$1537:;
	struct $11TSTRSETITEM* I$1;
	void* vr$1 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&FBC$ + 704ll) );
	I$1 = (struct $11TSTRSETITEM*)vr$1;
	label$1539:;
	if( I$1 == (struct $11TSTRSETITEM*)0ull) goto label$1540;
	{
		{
			FBSTRING TMP$758$3;
			fb_StrInit( (void*)&TMP$758$3, -1ll, (void*)I$1, -1ll, 0 );
			int32 vr$6 = fb_StrCompare( (void*)&TMP$758$3, -1ll, (void*)"fbrt0.o", 8ll );
			if( (int64)vr$6 == 0ll) goto label$1543;
			label$1544:;
			int32 vr$9 = fb_StrCompare( (void*)&TMP$758$3, -1ll, (void*)"fbrt0pic.o", 11ll );
			if( (int64)vr$9 == 0ll) goto label$1543;
			label$1545:;
			int32 vr$12 = fb_StrCompare( (void*)&TMP$758$3, -1ll, (void*)"fbrt1.o", 8ll );
			if( (int64)vr$12 == 0ll) goto label$1543;
			label$1546:;
			int32 vr$15 = fb_StrCompare( (void*)&TMP$758$3, -1ll, (void*)"fbrt1pic.o", 11ll );
			if( (int64)vr$15 == 0ll) goto label$1543;
			label$1547:;
			int32 vr$18 = fb_StrCompare( (void*)&TMP$758$3, -1ll, (void*)"fbrt2.o", 8ll );
			if( (int64)vr$18 == 0ll) goto label$1543;
			label$1548:;
			int32 vr$21 = fb_StrCompare( (void*)&TMP$758$3, -1ll, (void*)"fbrt2pic.o", 11ll );
			if( (int64)vr$21 != 0ll) goto label$1542;
			label$1543:;
			{
				*(int64*)((uint8*)&FBC$ + 2752ll) = -1ll;
			}
			goto label$1541;
			label$1542:;
			{
				STRSETDEL( (struct $7TSTRSET*)((uint8*)&FBC$ + 792ll), (FBSTRING*)I$1 );
			}
			label$1549:;
			label$1541:;
			fb_StrDelete( (FBSTRING*)&TMP$758$3 );
		}
		void* vr$27 = LISTGETNEXT( (void*)I$1 );
		I$1 = (struct $11TSTRSETITEM*)vr$27;
	}
	goto label$1539;
	label$1540:;
	label$1538:;
}

static void HPRINTOPTIONS( int64 VERBOSE$1 )
{
	label$1550:;
	FBSTRING* vr$0 = fb_StrAllocTempDescZEx( (char*)"usage: fbc [options] <input files>", 34ll );
	fb_PrintString( 0, (FBSTRING*)vr$0, 1 );
	FBSTRING* vr$1 = fb_StrAllocTempDescZEx( (char*)"input files:", 12ll );
	fb_PrintString( 0, (FBSTRING*)vr$1, 1 );
	FBSTRING* vr$2 = fb_StrAllocTempDescZEx( (char*)"  *.a = static library, *.o = object file, *.bas = source", 57ll );
	fb_PrintString( 0, (FBSTRING*)vr$2, 1 );
	FBSTRING* vr$3 = fb_StrAllocTempDescZEx( (char*)"  *.rc = resource script, *.res = compiled resource (win32)", 59ll );
	fb_PrintString( 0, (FBSTRING*)vr$3, 1 );
	FBSTRING* vr$4 = fb_StrAllocTempDescZEx( (char*)"  *.xpm = icon resource (*nix/*bsd)", 35ll );
	fb_PrintString( 0, (FBSTRING*)vr$4, 1 );
	FBSTRING* vr$5 = fb_StrAllocTempDescZEx( (char*)"options:", 8ll );
	fb_PrintString( 0, (FBSTRING*)vr$5, 1 );
	FBSTRING* vr$6 = fb_StrAllocTempDescZEx( (char*)"  @<file>          Read more command line arguments from a file", 63ll );
	fb_PrintString( 0, (FBSTRING*)vr$6, 1 );
	FBSTRING* vr$7 = fb_StrAllocTempDescZEx( (char*)"  -a <file>        Treat file as .o/.a input file", 49ll );
	fb_PrintString( 0, (FBSTRING*)vr$7, 1 );
	FBSTRING* vr$8 = fb_StrAllocTempDescZEx( (char*)"  -arch <type>     Set target architecture (default: 686)", 57ll );
	fb_PrintString( 0, (FBSTRING*)vr$8, 1 );
	FBSTRING* vr$9 = fb_StrAllocTempDescZEx( (char*)"  -asm att|intel   Set asm format (-gen gcc|llvm, x86 or x86_64 only)", 69ll );
	fb_PrintString( 0, (FBSTRING*)vr$9, 1 );
	FBSTRING* vr$10 = fb_StrAllocTempDescZEx( (char*)"  -b <file>        Treat file as .bas input file", 48ll );
	fb_PrintString( 0, (FBSTRING*)vr$10, 1 );
	if( VERBOSE$1 == 0ll) goto label$1553;
	{
		FBSTRING* vr$11 = fb_StrAllocTempDescZEx( (char*)"  -buildprefix <name>  specify prefix on tool names (as, ar, ld)", 64ll );
		fb_PrintString( 0, (FBSTRING*)vr$11, 1 );
	}
	label$1553:;
	label$1552:;
	FBSTRING* vr$12 = fb_StrAllocTempDescZEx( (char*)"  -c               Compile only, do not link", 44ll );
	fb_PrintString( 0, (FBSTRING*)vr$12, 1 );
	FBSTRING* vr$13 = fb_StrAllocTempDescZEx( (char*)"  -C               Preserve temporary .o files", 46ll );
	fb_PrintString( 0, (FBSTRING*)vr$13, 1 );
	FBSTRING* vr$14 = fb_StrAllocTempDescZEx( (char*)"  -d <name>[=<val>]  Add a global #define", 41ll );
	fb_PrintString( 0, (FBSTRING*)vr$14, 1 );
	FBSTRING* vr$15 = fb_StrAllocTempDescZEx( (char*)"  -dll             Same as -dylib", 33ll );
	fb_PrintString( 0, (FBSTRING*)vr$15, 1 );
	FBSTRING* vr$16 = fb_StrAllocTempDescZEx( (char*)"  -dylib           Create a DLL (win32) or shared library (*nix/*BSD)", 69ll );
	fb_PrintString( 0, (FBSTRING*)vr$16, 1 );
	FBSTRING* vr$17 = fb_StrAllocTempDescZEx( (char*)"  -e               Enable runtime error checking", 48ll );
	fb_PrintString( 0, (FBSTRING*)vr$17, 1 );
	if( VERBOSE$1 == 0ll) goto label$1555;
	{
		FBSTRING* vr$18 = fb_StrAllocTempDescZEx( (char*)"  -earray          Enable array bounds checking", 47ll );
		fb_PrintString( 0, (FBSTRING*)vr$18, 1 );
		FBSTRING* vr$19 = fb_StrAllocTempDescZEx( (char*)"  -earraydims      Enable array dimensions checking", 51ll );
		fb_PrintString( 0, (FBSTRING*)vr$19, 1 );
		FBSTRING* vr$20 = fb_StrAllocTempDescZEx( (char*)"  -eassert         Enable assert() and assertwarn() checking", 60ll );
		fb_PrintString( 0, (FBSTRING*)vr$20, 1 );
		FBSTRING* vr$21 = fb_StrAllocTempDescZEx( (char*)"  -edebug          Enable __FB_DEBUG__", 38ll );
		fb_PrintString( 0, (FBSTRING*)vr$21, 1 );
		FBSTRING* vr$22 = fb_StrAllocTempDescZEx( (char*)"  -edebuginfo      Add debug info", 33ll );
		fb_PrintString( 0, (FBSTRING*)vr$22, 1 );
		FBSTRING* vr$23 = fb_StrAllocTempDescZEx( (char*)"  -elocation       Enable error location reporting", 50ll );
		fb_PrintString( 0, (FBSTRING*)vr$23, 1 );
		FBSTRING* vr$24 = fb_StrAllocTempDescZEx( (char*)"  -enullptr        Enable null-pointer checking", 47ll );
		fb_PrintString( 0, (FBSTRING*)vr$24, 1 );
		FBSTRING* vr$25 = fb_StrAllocTempDescZEx( (char*)"  -eunwind         Enable call stack unwind information", 55ll );
		fb_PrintString( 0, (FBSTRING*)vr$25, 1 );
		FBSTRING* vr$26 = fb_StrAllocTempDescZEx( (char*)"  -entry <name>    Change the entry point of the program from main()", 68ll );
		fb_PrintString( 0, (FBSTRING*)vr$26, 1 );
	}
	label$1555:;
	label$1554:;
	FBSTRING* vr$27 = fb_StrAllocTempDescZEx( (char*)"  -ex              -e plus RESUME support", 41ll );
	fb_PrintString( 0, (FBSTRING*)vr$27, 1 );
	FBSTRING* vr$28 = fb_StrAllocTempDescZEx( (char*)"  -exx             -ex plus array bounds/null-pointer checking", 62ll );
	fb_PrintString( 0, (FBSTRING*)vr$28, 1 );
	FBSTRING* vr$29 = fb_StrAllocTempDescZEx( (char*)"  -export          Export symbols for dynamic linkage", 53ll );
	fb_PrintString( 0, (FBSTRING*)vr$29, 1 );
	if( VERBOSE$1 == 0ll) goto label$1557;
	{
		FBSTRING* vr$30 = fb_StrAllocTempDescZEx( (char*)"  -fbgfx           Link to the appropriate libfbgfx variant (normally automatic)", 80ll );
		fb_PrintString( 0, (FBSTRING*)vr$30, 1 );
	}
	label$1557:;
	label$1556:;
	FBSTRING* vr$31 = fb_StrAllocTempDescZEx( (char*)"  -forcelang <name>  Override #lang statements in source code", 61ll );
	fb_PrintString( 0, (FBSTRING*)vr$31, 1 );
	if( VERBOSE$1 == 0ll) goto label$1559;
	{
		FBSTRING* vr$32 = fb_StrAllocTempDescZEx( (char*)"  -fpmode fast|precise  Select floating-point math accuracy/speed", 65ll );
		fb_PrintString( 0, (FBSTRING*)vr$32, 1 );
		FBSTRING* vr$33 = fb_StrAllocTempDescZEx( (char*)"  -fpu x87|sse|neon  Set target FPU", 35ll );
		fb_PrintString( 0, (FBSTRING*)vr$33, 1 );
	}
	label$1559:;
	label$1558:;
	FBSTRING* vr$34 = fb_StrAllocTempDescZEx( (char*)"  -g               Add debug info, enable __FB_DEBUG__, and enable assert()", 75ll );
	fb_PrintString( 0, (FBSTRING*)vr$34, 1 );
	if( VERBOSE$1 == 0ll) goto label$1561;
	{
		FBSTRING* vr$35 = fb_StrAllocTempDescZEx( (char*)"  -gen gas         Select GNU gas 32-bit assembler backend", 58ll );
		fb_PrintString( 0, (FBSTRING*)vr$35, 1 );
		FBSTRING* vr$36 = fb_StrAllocTempDescZEx( (char*)"  -gen gas64       Select GNU gas 64-bit assembler backend", 58ll );
		fb_PrintString( 0, (FBSTRING*)vr$36, 1 );
		FBSTRING* vr$37 = fb_StrAllocTempDescZEx( (char*)"  -gen gcc         Select GNU gcc C backend", 43ll );
		fb_PrintString( 0, (FBSTRING*)vr$37, 1 );
		FBSTRING* vr$38 = fb_StrAllocTempDescZEx( (char*)"  -gen llvm        Select LLVM backend", 38ll );
		fb_PrintString( 0, (FBSTRING*)vr$38, 1 );
		FBSTRING* vr$39 = fb_StrAllocTempDescZEx( (char*)"  -gen clang       Select clang C backend", 41ll );
		fb_PrintString( 0, (FBSTRING*)vr$39, 1 );
	}
	goto label$1560;
	label$1561:;
	{
		FBSTRING* vr$40 = fb_StrAllocTempDescZEx( (char*)"  -gen <backend>   Select code generation backend (gas|gas64|gcc|llvm|clang)", 76ll );
		fb_PrintString( 0, (FBSTRING*)vr$40, 1 );
	}
	label$1560:;
	FBSTRING* vr$41 = fb_StrAllocTempDescZEx( (char*)"  [-]-help         Show this help output; use '-help -v' to show verbose help", 77ll );
	fb_PrintString( 0, (FBSTRING*)vr$41, 1 );
	FBSTRING* vr$42 = fb_StrAllocTempDescZEx( (char*)"  -i <path>        Add an include file search path", 50ll );
	fb_PrintString( 0, (FBSTRING*)vr$42, 1 );
	FBSTRING* vr$43 = fb_StrAllocTempDescZEx( (char*)"  -include <file>  Pre-#include a file for each input .bas", 58ll );
	fb_PrintString( 0, (FBSTRING*)vr$43, 1 );
	FBSTRING* vr$44 = fb_StrAllocTempDescZEx( (char*)"  -l <name>        Link in a library", 36ll );
	fb_PrintString( 0, (FBSTRING*)vr$44, 1 );
	FBSTRING* vr$45 = fb_StrAllocTempDescZEx( (char*)"  -lang <name>     Select FB dialect: fb, deprecated, fblite, qb", 64ll );
	fb_PrintString( 0, (FBSTRING*)vr$45, 1 );
	FBSTRING* vr$46 = fb_StrAllocTempDescZEx( (char*)"  -lib             Create a static library", 42ll );
	fb_PrintString( 0, (FBSTRING*)vr$46, 1 );
	FBSTRING* vr$47 = fb_StrAllocTempDescZEx( (char*)"  -m <name>        Specify main module (default if not -c: first input .bas)", 76ll );
	fb_PrintString( 0, (FBSTRING*)vr$47, 1 );
	FBSTRING* vr$48 = fb_StrAllocTempDescZEx( (char*)"  -map <file>      Save linking map to file", 43ll );
	fb_PrintString( 0, (FBSTRING*)vr$48, 1 );
	FBSTRING* vr$49 = fb_StrAllocTempDescZEx( (char*)"  -maxerr <n>      Only show <n> errors", 39ll );
	fb_PrintString( 0, (FBSTRING*)vr$49, 1 );
	FBSTRING* vr$50 = fb_StrAllocTempDescZEx( (char*)"  -mt              Use thread-safe FB runtime", 45ll );
	fb_PrintString( 0, (FBSTRING*)vr$50, 1 );
	FBSTRING* vr$51 = fb_StrAllocTempDescZEx( (char*)"  -nodeflibs       Do not include the default libraries when linking", 68ll );
	fb_PrintString( 0, (FBSTRING*)vr$51, 1 );
	FBSTRING* vr$52 = fb_StrAllocTempDescZEx( (char*)"  -noerrline       Do not show source context in error messages", 63ll );
	fb_PrintString( 0, (FBSTRING*)vr$52, 1 );
	FBSTRING* vr$53 = fb_StrAllocTempDescZEx( (char*)"  -nolib <a,b,c>   Do not include the specified libraries when linking", 70ll );
	fb_PrintString( 0, (FBSTRING*)vr$53, 1 );
	FBSTRING* vr$54 = fb_StrAllocTempDescZEx( (char*)"  -noobjinfo       Do not read/write compile-time info from/to .o and .a files", 78ll );
	fb_PrintString( 0, (FBSTRING*)vr$54, 1 );
	FBSTRING* vr$55 = fb_StrAllocTempDescZEx( (char*)"  -nostrip         Do not strip symbol information from the output file", 71ll );
	fb_PrintString( 0, (FBSTRING*)vr$55, 1 );
	FBSTRING* vr$56 = fb_StrAllocTempDescZEx( (char*)"  -o <file>        Set .o (or -pp .bas) file name for prev/next input file", 74ll );
	fb_PrintString( 0, (FBSTRING*)vr$56, 1 );
	FBSTRING* vr$57 = fb_StrAllocTempDescZEx( (char*)"  -O <value>       Optimization level (default: 0)", 50ll );
	fb_PrintString( 0, (FBSTRING*)vr$57, 1 );
	FBSTRING* vr$58 = fb_StrAllocTempDescZEx( (char*)"  -p <path>        Add a library search path", 44ll );
	fb_PrintString( 0, (FBSTRING*)vr$58, 1 );
	FBSTRING* vr$59 = fb_StrAllocTempDescZEx( (char*)"  -pic             Generate position-independent code (non-x86 Unix shared libs)", 80ll );
	fb_PrintString( 0, (FBSTRING*)vr$59, 1 );
	FBSTRING* vr$60 = fb_StrAllocTempDescZEx( (char*)"  -pp              Write out preprocessed input file (.pp.bas) only", 67ll );
	fb_PrintString( 0, (FBSTRING*)vr$60, 1 );
	FBSTRING* vr$61 = fb_StrAllocTempDescZEx( (char*)"  -prefix <path>   Set the compiler prefix path", 47ll );
	fb_PrintString( 0, (FBSTRING*)vr$61, 1 );
	FBSTRING* vr$62 = fb_StrAllocTempDescZEx( (char*)"  -print host|target  Display host/target system name", 53ll );
	fb_PrintString( 0, (FBSTRING*)vr$62, 1 );
	FBSTRING* vr$63 = fb_StrAllocTempDescZEx( (char*)"  -print fblibdir  Display the compiler's lib/ path", 51ll );
	fb_PrintString( 0, (FBSTRING*)vr$63, 1 );
	FBSTRING* vr$64 = fb_StrAllocTempDescZEx( (char*)"  -print x         Display output binary/library file name (if known)", 69ll );
	fb_PrintString( 0, (FBSTRING*)vr$64, 1 );
	if( VERBOSE$1 == 0ll) goto label$1563;
	{
		FBSTRING* vr$65 = fb_StrAllocTempDescZEx( (char*)"  -print fork-id   Display compiler's fork identifier (if set)", 62ll );
		fb_PrintString( 0, (FBSTRING*)vr$65, 1 );
		FBSTRING* vr$66 = fb_StrAllocTempDescZEx( (char*)"  -print sha-1     Display compiler's source code commit sha-1 (if known)", 73ll );
		fb_PrintString( 0, (FBSTRING*)vr$66, 1 );
	}
	label$1563:;
	label$1562:;
	FBSTRING* vr$67 = fb_StrAllocTempDescZEx( (char*)"  -profile         Enable function profiling", 44ll );
	fb_PrintString( 0, (FBSTRING*)vr$67, 1 );
	FBSTRING* vr$68 = fb_StrAllocTempDescZEx( (char*)"  -profgen         Set the profiling code generation type (gmon|fb|cycles)", 74ll );
	fb_PrintString( 0, (FBSTRING*)vr$68, 1 );
	FBSTRING* vr$69 = fb_StrAllocTempDescZEx( (char*)"  -r               Write out .asm/.c/.ll (-gen gas/gcc/llvm) only", 65ll );
	fb_PrintString( 0, (FBSTRING*)vr$69, 1 );
	FBSTRING* vr$70 = fb_StrAllocTempDescZEx( (char*)"  -rr              Write out the final .asm only", 48ll );
	fb_PrintString( 0, (FBSTRING*)vr$70, 1 );
	FBSTRING* vr$71 = fb_StrAllocTempDescZEx( (char*)"  -R               Preserve temporary .asm/.c/.ll/.def files", 60ll );
	fb_PrintString( 0, (FBSTRING*)vr$71, 1 );
	FBSTRING* vr$72 = fb_StrAllocTempDescZEx( (char*)"  -RR              Preserve the final .asm file", 47ll );
	fb_PrintString( 0, (FBSTRING*)vr$72, 1 );
	FBSTRING* vr$73 = fb_StrAllocTempDescZEx( (char*)"  -s console|gui   Select win32 subsystem", 41ll );
	fb_PrintString( 0, (FBSTRING*)vr$73, 1 );
	FBSTRING* vr$74 = fb_StrAllocTempDescZEx( (char*)"  -showincludes    Display a tree of file names of #included files", 66ll );
	fb_PrintString( 0, (FBSTRING*)vr$74, 1 );
	FBSTRING* vr$75 = fb_StrAllocTempDescZEx( (char*)"  -static          Prefer static libraries over dynamic ones when linking", 73ll );
	fb_PrintString( 0, (FBSTRING*)vr$75, 1 );
	FBSTRING* vr$76 = fb_StrAllocTempDescZEx( (char*)"  -strip           Omit all symbol information from the output file", 67ll );
	fb_PrintString( 0, (FBSTRING*)vr$76, 1 );
	FBSTRING* vr$77 = fb_StrAllocTempDescZEx( (char*)"  -sysroot <path>  Linker sysroot, needed by some cross-compiling toolchains", 76ll );
	fb_PrintString( 0, (FBSTRING*)vr$77, 1 );
	FBSTRING* vr$78 = fb_StrAllocTempDescZEx( (char*)"  -t <value>       Set .exe stack size in kbytes, default: 1024 (win32/dos)", 75ll );
	fb_PrintString( 0, (FBSTRING*)vr$78, 1 );
	if( VERBOSE$1 == 0ll) goto label$1565;
	{
		FBSTRING* vr$79 = fb_StrAllocTempDescZEx( (char*)"  -target <name>   Set cross-compilation target", 47ll );
		fb_PrintString( 0, (FBSTRING*)vr$79, 1 );
	}
	goto label$1564;
	label$1565:;
	{
		FBSTRING* vr$80 = fb_StrAllocTempDescZEx( (char*)"  -target <name>   Set cross-compilation target", 47ll );
		fb_PrintString( 0, (FBSTRING*)vr$80, 1 );
	}
	label$1564:;
	FBSTRING* vr$81 = fb_StrAllocTempDescZEx( (char*)"  -title <name>    Set XBE display title (xbox)", 47ll );
	fb_PrintString( 0, (FBSTRING*)vr$81, 1 );
	FBSTRING* vr$82 = fb_StrAllocTempDescZEx( (char*)"  -v               Be verbose", 29ll );
	fb_PrintString( 0, (FBSTRING*)vr$82, 1 );
	FBSTRING* vr$83 = fb_StrAllocTempDescZEx( (char*)"  -vec <n>         Automatic vectorization level (default: 0)", 61ll );
	fb_PrintString( 0, (FBSTRING*)vr$83, 1 );
	FBSTRING* vr$84 = fb_StrAllocTempDescZEx( (char*)"  [-]-version      Show compiler version", 40ll );
	fb_PrintString( 0, (FBSTRING*)vr$84, 1 );
	FBSTRING* vr$85 = fb_StrAllocTempDescZEx( (char*)"  -w all|pedantic|<n>  Set min warning level: all, pedantic or a value", 70ll );
	fb_PrintString( 0, (FBSTRING*)vr$85, 1 );
	if( VERBOSE$1 == 0ll) goto label$1567;
	{
		FBSTRING* vr$86 = fb_StrAllocTempDescZEx( (char*)"  -w all           Enable all warnings", 38ll );
		fb_PrintString( 0, (FBSTRING*)vr$86, 1 );
		FBSTRING* vr$87 = fb_StrAllocTempDescZEx( (char*)"  -w none          Disable all warnings", 39ll );
		fb_PrintString( 0, (FBSTRING*)vr$87, 1 );
		FBSTRING* vr$88 = fb_StrAllocTempDescZEx( (char*)"  -w param         Enable parameter warnings", 44ll );
		fb_PrintString( 0, (FBSTRING*)vr$88, 1 );
		FBSTRING* vr$89 = fb_StrAllocTempDescZEx( (char*)"  -w escape        Enable string escape sequence warnings", 57ll );
		fb_PrintString( 0, (FBSTRING*)vr$89, 1 );
		FBSTRING* vr$90 = fb_StrAllocTempDescZEx( (char*)"  -w next          Enable next statement warnings", 49ll );
		fb_PrintString( 0, (FBSTRING*)vr$90, 1 );
		FBSTRING* vr$91 = fb_StrAllocTempDescZEx( (char*)"  -w signedness    Enable type signedness warnings", 50ll );
		fb_PrintString( 0, (FBSTRING*)vr$91, 1 );
		FBSTRING* vr$92 = fb_StrAllocTempDescZEx( (char*)"  -w constness     Enable const type warnings", 45ll );
		fb_PrintString( 0, (FBSTRING*)vr$92, 1 );
		FBSTRING* vr$93 = fb_StrAllocTempDescZEx( (char*)"  -w suffix        Enable invalid suffix warnings", 49ll );
		fb_PrintString( 0, (FBSTRING*)vr$93, 1 );
		FBSTRING* vr$94 = fb_StrAllocTempDescZEx( (char*)"  -w error         Report warnings as errors", 44ll );
		fb_PrintString( 0, (FBSTRING*)vr$94, 1 );
		FBSTRING* vr$95 = fb_StrAllocTempDescZEx( (char*)"  -w upcast        Enable warning when up-casting discards initializers", 71ll );
		fb_PrintString( 0, (FBSTRING*)vr$95, 1 );
	}
	label$1567:;
	label$1566:;
	FBSTRING* vr$96 = fb_StrAllocTempDescZEx( (char*)"  -Wa <a,b,c>      Pass options to 'as'", 39ll );
	fb_PrintString( 0, (FBSTRING*)vr$96, 1 );
	FBSTRING* vr$97 = fb_StrAllocTempDescZEx( (char*)"  -Wc <a,b,c>      Pass options to 'gcc' (-gen gcc) or 'llc' (-gen llvm)", 72ll );
	fb_PrintString( 0, (FBSTRING*)vr$97, 1 );
	FBSTRING* vr$98 = fb_StrAllocTempDescZEx( (char*)"  -Wl <a,b,c>      Pass options to 'ld'", 39ll );
	fb_PrintString( 0, (FBSTRING*)vr$98, 1 );
	FBSTRING* vr$99 = fb_StrAllocTempDescZEx( (char*)"  -x <file>        Set output executable/library file name", 58ll );
	fb_PrintString( 0, (FBSTRING*)vr$99, 1 );
	if( VERBOSE$1 == 0ll) goto label$1569;
	{
		FBSTRING* vr$100 = fb_StrAllocTempDescZEx( (char*)"  -z fbrt          Link with 'fbrt' instead of 'fb' runtime library", 67ll );
		fb_PrintString( 0, (FBSTRING*)vr$100, 1 );
		FBSTRING* vr$101 = fb_StrAllocTempDescZEx( (char*)"  -z gosub-setjmp  Use setjmp/longjmp to implement GOSUB", 56ll );
		fb_PrintString( 0, (FBSTRING*)vr$101, 1 );
		FBSTRING* vr$102 = fb_StrAllocTempDescZEx( (char*)"  -z no-thiscall   Don't use '__thiscall' calling convention", 60ll );
		fb_PrintString( 0, (FBSTRING*)vr$102, 1 );
		FBSTRING* vr$103 = fb_StrAllocTempDescZEx( (char*)"  -z no-fastcall   Don't use '__fastcall' calling convention", 60ll );
		fb_PrintString( 0, (FBSTRING*)vr$103, 1 );
		FBSTRING* vr$104 = fb_StrAllocTempDescZEx( (char*)"  -z nobuiltins    Disable all non-required builtin procedure definitions", 73ll );
		fb_PrintString( 0, (FBSTRING*)vr$104, 1 );
		FBSTRING* vr$105 = fb_StrAllocTempDescZEx( (char*)"  -z nocmdline     Disable #cmdline source directives", 53ll );
		fb_PrintString( 0, (FBSTRING*)vr$105, 1 );
		FBSTRING* vr$106 = fb_StrAllocTempDescZEx( (char*)"  -z optabstract   Only supports optimizing purely abstract types", 65ll );
		fb_PrintString( 0, (FBSTRING*)vr$106, 1 );
		FBSTRING* vr$107 = fb_StrAllocTempDescZEx( (char*)"  -z retinflts     Enable returning some types in floating point registers", 74ll );
		fb_PrintString( 0, (FBSTRING*)vr$107, 1 );
		FBSTRING* vr$108 = fb_StrAllocTempDescZEx( (char*)"  -z valist-as-ptr Use pointer expressions to implement CVA_*() macros", 70ll );
		fb_PrintString( 0, (FBSTRING*)vr$108, 1 );
	}
	goto label$1568;
	label$1569:;
	{
		FBSTRING* vr$109 = fb_StrAllocTempDescZEx( (char*)"  -z <option>      Extended options (see fbc -help -v)", 54ll );
		fb_PrintString( 0, (FBSTRING*)vr$109, 1 );
	}
	label$1568:;
	label$1551:;
}

static void HPRINTVERSION( int64 VERBOSE$1 )
{
	FBSTRING TMP$876$1;
	FBSTRING TMP$877$1;
	FBSTRING TMP$878$1;
	FBSTRING TMP$879$1;
	label$1574:;
	FBSTRING CONFIG$1;
	__builtin_memset( &CONFIG$1, 0, 24ll );
	int64 vr$1 = FBGETHOSTBITS(  );
	FBSTRING* vr$2 = fb_LongintToStr( vr$1 );
	FBSTRING* vr$3 = FBGETHOSTID(  );
	__builtin_memset( &TMP$876$1, 0, 24ll );
	FBSTRING* vr$6 = fb_StrConcat( &TMP$876$1, (void*)"FreeBASIC Compiler - Version 1.20.0 (2026-09-11), built for ", 61ll, (void*)vr$3, -1ll );
	__builtin_memset( &TMP$877$1, 0, 24ll );
	FBSTRING* vr$9 = fb_StrConcat( &TMP$877$1, (void*)vr$6, -1ll, (void*)" (", 3ll );
	__builtin_memset( &TMP$878$1, 0, 24ll );
	FBSTRING* vr$12 = fb_StrConcat( &TMP$878$1, (void*)vr$9, -1ll, (void*)vr$2, -1ll );
	__builtin_memset( &TMP$879$1, 0, 24ll );
	FBSTRING* vr$15 = fb_StrConcat( &TMP$879$1, (void*)vr$12, -1ll, (void*)"bit)", 5ll );
	fb_PrintString( 0, (FBSTRING*)vr$15, 1 );
	FBSTRING* vr$16 = fb_StrAllocTempDescZEx( (char*)"Copyright (C) 2004-2025 The FreeBASIC development team.", 55ll );
	fb_PrintString( 0, (FBSTRING*)vr$16, 1 );
	int64 vr$18 = fb_StrLen( (void*)&CONFIG$1, -1ll );
	if( vr$18 <= 0ll) goto label$1577;
	{
		fb_PrintString( 0, (FBSTRING*)&CONFIG$1, 1 );
	}
	label$1577:;
	label$1576:;
	if( VERBOSE$1 == 0ll) goto label$1579;
	{
		FBCPRINTTARGETINFO(  );
		goto label$1581;
		{
			FBSTRING* vr$20 = fb_StrAllocTempDescZEx( (char*)"source sha-1: ", 14ll );
			fb_PrintString( 0, (FBSTRING*)vr$20, 1 );
		}
		label$1581:;
		label$1580:;
		goto label$1583;
		{
			FBSTRING* vr$21 = fb_StrAllocTempDescZEx( (char*)"fbc fork id:  ", 14ll );
			fb_PrintString( 0, (FBSTRING*)vr$21, 1 );
		}
		label$1583:;
		label$1582:;
	}
	label$1579:;
	label$1578:;
	fb_StrDelete( (FBSTRING*)&CONFIG$1 );
	label$1575:;
}

__attribute__(( constructor )) static void _GLOBAL__I( void )
{
	label$1641:;
	_ZN6FBCCTXC1Ev( &FBC$ );
	label$1642:;
}

__attribute__(( destructor )) static void _GLOBAL__D( void )
{
	label$1644:;
	_ZN6FBCCTXD1Ev( &FBC$ );
	label$1645:;
}
