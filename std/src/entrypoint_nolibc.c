#ifndef STD_PLATFORM_NOLIBC

#include "entrypoint.h"

#ifdef __cplusplus
extern "C" {
#endif

	int _start(void) {
		std_main();

		return 0;
	}

#ifdef __cplusplus
}
#endif

#endif
