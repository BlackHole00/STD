#ifndef _STD_WINDOWSTYPES_DEFINED
#define _STD_WINDOWSTYPES_DEFINED

#include <std/base/constant_symbols.h>
#ifdef STD_PLATFORM_WINDOWS

#include <std/base/types.h>

typedef void std_VOID;

typedef void* std_LPVOID;
typedef void* std_HANDLE;

typedef u32 std_UINT;
typedef usize std_SIZE_T;
typedef u32 std_DWORD;
typedef u32* std_LPDWORD;

typedef b32 std_BOOL;

#ifndef STD_DISALLOW_GLOBAL_NAMESPACE
	#define VOID std_VOID
	#define LPVOID std_LPVOID
	#define HANDLE std_HANDLE
	#define SIZE_T std_SIZE_T
	#define DWORD std_DWORD
	#define LPDWORD std_LPDWORD
	#define BOOL std_BOOL
#endif

#endif
#endif

