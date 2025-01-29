#ifndef _STD_ENTRYPOINT_DEFINED
#define _STD_ENTRYPOINT_DEFINED

#include <std/constant_symbols.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	@fn std_main
	@brief The expected entry point of the user application. The user must
		declare its body
*/
extern void std_main(void);

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif
