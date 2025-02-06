#include <std/base/constant_symbols.h>
#if defined(STD_PLATFORM_LIBC) || defined(STD_COMPILER_TCC)

#include "entrypoint.h"

int main(void) {
	std_main();

	return 0;
}

#endif
