#include <std/base/constant_symbols.h>
#ifdef STD_PLATFORM_POSIX

#include <std/runtime/runtime.h>
#include "runtime_implementation.h"

#include <std/posix/constants.h>
#include <std/posix/syscalls.h>

#ifdef STD_LANGUAGE_C
extern void print_cstring(const char* cstring);
#else
extern "C" void print_cstring(const char* cstring);
#endif

bool _std_runtimeglobals_init(void) {
	i32 sysctl_query[2] = { STD_POSIX_CTL_HW, STD_POSIX_HW_PAGESIZE };
	usize result_size = sizeof(usize);

	i32 result = std_posix_syscall_sysctl(
		sysctl_query,
		2,
		&g_runtime_globals.page_size,
		&result_size, 
		null,
		0
	);

	if (result == -1) {
		return false;
	} else {
		return true;
	}
}

#endif

