#ifndef _STD_BASECONSTANTSYMBOLS_INCLUDED
#define _STD_BASECONSTANTSYMBOLS_INCLUDED

#include <std/base/compiler_constant_symbols.h>
#include <std/base/language_constant_symbols.h>
#include <std/base/architecture_constant_symbols.h>
#include <std/base/platform_constant_symbols.h>
#include <std/base/endianness_constant_symbols.h>

#ifdef STD_LANGUAGE_C_OLD
	#error "STD requires a C89 or CPP compliant compiler"
#endif
/*
TODO: Apply the MVP targets when STD is mature enough
#if !defined(STD_ARCHITECTURE_ARM64) && !defined(STD_ARCHITECTURE_AMD64)
	#error "STD requires an arm64 or amd64 capable cpu for the time being"
#endif
#if !defined(STD_PLATFORM_POSIX) && !defined(STD_PLATFORM_WINDOWS)
	#error "STD supports only posix and windows for the time being"
#endif
*/

/* #ifndef STD_PLATFORM_DARWIN
	#error "STD supports only Darwin for the time being"
#endif
#ifndef STD_ARCHITECTURE_ARM64
	#error "STD supports only ARM64 for the time being"
#endif */
/*#ifndef STD_ENDIANNESS_LITTLE
	#error "STD expects a little endian system currently"
#endif*/

#endif

