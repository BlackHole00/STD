#ifndef _STD_BASECOMPILERCONSTANTSYMBOLS_INCLUDED
#define _STD_BASECOMPILERCONSTANTSYMBOLS_INCLUDED

#ifdef __clang__
	#define STD_COMPILER_CLANG
#elif defined(__TINYC__)
	#define STD_COMPILER_TCC
#elif defined(__GNUC__)
	#define STD_COMPILER_GCC
#elif defined(_MSC_VER)
	#define STD_COMPILER_MSVC
#elif defined(__INTEL_COMPILER)
	#define STD_COMPILER_INTEL
#else
	#define STD_COMPILER_UNKNOWN
#endif

#endif

