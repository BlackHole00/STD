#ifndef _STD_BASELANGUAGECONSTANTSYMBOLS_INCLUDED
#define _STD_BASELANGUAGECONSTANTSYMBOLS_INCLUDED

#include <std/base/compiler_constant_symbols.h>

#ifdef __cplusplus
	#define STD_LANGUAGE_CPP 1

	#if __cplusplus == 1
		#define STD_LANGUAGE_CPP_OLD 1
		#define STD_LANGUAGE_VERSION 0
	#elif __cplusplus == 199711L
		#define STD_LANGUAGE_CPP_98 1
		#define STD_LANGUAGE_VERSION 98
	#elif __cplusplus == 201103L
		#define STD_LANGUAGE_CPP_11 1
		#define STD_LANGUAGE_VERSION 11
	#elif __cplusplus == 201402L
		#define STD_LANGUAGE_CPP_14 1
		#define STD_LANGUAGE_VERSION 14
	#elif __cplusplus == 201703L
		#define STD_LANGUAGE_CPP_17 1
		#define STD_LANGUAGE_VERSION 17
	#elif __cplusplus == 202002L
		#define STD_LANGUAGE_CPP_20 1
		#define STD_LANGUAGE_VERSION 20
	#elif __cplusplus == 202302L
		#define STD_LANGUAGE_CPP_23 1
		#define STD_LANGUAGE_VERSION 23
	#endif
#else
	#define STD_LANGUAGE_C 1

	#ifndef STD_COMPILER_MSVC
		#ifndef __STDC__ 
			#define STD_LANGUAGE_C_OLD 1
			#define STD_LANGUAGE_VERSION 0
		#elif !defined(__STDC_VERSION__)
			#define STD_LANGUAGE_C_89 1
			#define STD_LANGUAGE_VERSION 89
		#elif __STDC_VERSION__ == 199409L
			#define STD_LANGUAGE_C_95 1
			#define STD_LANGUAGE_VERSION 95
		#elif __STDC_VERSION__ == 199901L
			#define STD_LANGUAGE_C_99 1
			#define STD_LANGUAGE_VERSION 99
		#elif __STDC_VERSION__ == 201112L
			#define STD_LANGUAGE_C_11 1
			#define STD_LANGUAGE_VERSION 11
		#elif __STDC_VERSION__ == 201710L
			#define STD_LANGUAGE_C_17 1
			#define STD_LANGUAGE_VERSION 17
		#elif __STDC_VERSION__ == 202311L
			#define STD_LANGUAGE_C_23 1
			#define STD_LANGUAGE_VERSION 23
		#else
			#define STD_LANGUAGE_C_90 1
			#define STD_LANGUAGE_VERSION 90
		#endif
	#else
		#ifndef __STDC__
			#define STD_LANGUAGE_C_99 1
			#define STD_LANGUAGE_VERSION 99
		#elif !defined(__STDC_VERSION__)
			#define STD_LANGUAGE_C_99 1
			#define STD_LANGUAGE_VERSION 99
			#define STD_LANGUAGE_MS_EXTENSIONS 1
		#elif __STDC_VERSION__ == 201112L
			#define STD_LANGUAGE_C_11 1
			#define STD_LANGUAGE_VERSION 11
			#define STD_LANGUAGE_MS_EXTENSIONS 1
		#elif __STDC_VERSION__ == 201710L
			#define STD_LANGUAGE_C_17 1
			#define STD_LANGUAGE_VERSION 17
			#define STD_LANGUAGE_MS_EXTENSIONS 1
		#else /* unknown msvc version and language standatd */
			#define STD_LANGUAGE_C_OLD 1
			#define STD_LANGUAGE_VERSION 0
		#endif
	#endif
#endif

#endif

