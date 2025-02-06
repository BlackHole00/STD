#include <std/runtime/runtime.h>
#include "runtime_implementation.h"

std_RuntimeGlobals g_runtime_globals;

bool std_runtimeglobals_init(void) {
	return _std_runtimeglobals_init();
}

