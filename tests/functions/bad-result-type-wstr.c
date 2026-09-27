typedef   signed char       int8;
typedef unsigned char      uint8;
typedef   signed short      int16;
typedef unsigned short     uint16;
typedef   signed int        int32;
typedef unsigned int       uint32;
typedef   signed long long  int64;
typedef unsigned long long uint64;
typedef struct { char *data; int64 len; int64 size; } FBSTRING;
typedef struct { uint16 *data; int64 len; int64 size; } FBWSTRING;
typedef int8 boolean;
uint16* fb_WstrAssignFromA( uint16*, int64, void*, int64 );
static void fb_ctor__badzresultztypezwstr( void ) __attribute__(( constructor ));

uint16* F( void )
{
	uint16 fb$result$1[1];
	__builtin_memset( (uint16*)fb$result$1, 0, 2ll );
	label$2:;
	fb_WstrAssignFromA( (uint16*)fb$result$1, 1ll, (void*)"123", 4ll );
	label$3:;
	return *(uint16**)fb$result$1;
}
