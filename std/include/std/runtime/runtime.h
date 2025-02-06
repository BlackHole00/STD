#ifndef _STD_RUNTIMERUNTIME_INCLUDED
#define _STD_RUNTIMERUNTIME_INCLUDED

#include <std/base/types.h>

typedef struct std_RuntimeGlobals {
	usize page_size;
} std_RuntimeGlobals;
extern std_RuntimeGlobals g_runtime_globals;

bool std_runtimeglobals_init(void);

#endif

