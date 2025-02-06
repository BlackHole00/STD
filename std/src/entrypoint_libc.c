#include <std/base/constant_symbols.h>
#if defined(STD_PLATFORM_LIBC) || defined(STD_COMPILER_TCC)

#include "entrypoint.h"
#include <std/runtime/runtime.h>

int main(void) {
	std_main();
	std_runtimeglobals_init();

	return 0;
}

#endif
