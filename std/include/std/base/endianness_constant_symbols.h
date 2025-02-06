#ifndef _STD_BASEENDIANNESSCONSTANTSYMBOLS_INCLUDED
#define _STD_BASEENDIANNESSCONSTANTSYMBOLS_INCLUDED

#include <std/base/architecture_constant_symbols.h>
#include <std/base/platform_constant_symbols.h>

#if defined(STD_ARCHITECTURE_AMD64) || defined(STD_ARCHITECTURE_I386)
	#define STD_ENDIANNESS_LITTLE 1

#elif defined(STD_ARCHITECTURE_ARM64)
	#if defined(STD_PLATFORM_LINUX) || defined(STD_PLATFORM_DARWIN) || defined(STD_PLATFORM_ANDROID)
		#define STD_ENDIANNESS_LITTLE 1
	#endif

#else
	#define STD_ENDIANNESS_UNKNOWN 1

#endif

#endif


