#include <std/base/constant_symbols.h>
#if !defined(STD_PLATFORM_NOLIBC) && !defined(STD_COMPILER_TCC)

#include "entrypoint.h"
#include <std/runtime/runtime.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

#include <std/windows/constants.h>
#include <std/windows/kernel32.h>

int _start(void) {
	/* TODO: Split entrypoints */
	#ifdef STD_PLATFORM_WINDOWS
		SetConsoleOutputCP(STD_WINDOWS_CP_UTF8);
		SetConsoleCP(STD_WINDOWS_CP_UTF8);
	#endif
	std_runtimeglobals_init();

	std_main();

	return 0;
}

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif
