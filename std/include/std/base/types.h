#ifndef _STD_BASETYPES_INCLUDED
#define _STD_BASETYPES_INCLUDED

#include <std/base/constant_symbols.h>

typedef unsigned char byte;

typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
typedef signed int i32;

/* TODO: Support msvc (__int64) and gcc (#pragma gcc ...) */
#ifdef STD_COMPILER_CLANG
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wlong-long"
#elif defined(STD_COMPILER_GCC)
	#pragma gcc diagnostic push
	#pragma gcc diagnostic ignored "-Wlong-long"
#endif

typedef unsigned long long int u64;
typedef signed long long int i64;

/* TODO: Change for 32 bits systems */
typedef unsigned long long int usize;
typedef signed long long int isize;
typedef unsigned long long int uintptr;

#ifdef STD_COMPILER_CLANG
	#pragma clang diagnostic pop
#elif defined(STD_COMPILER_GCC)
	#pragma gcc diagnostic pop
#endif

/**
	@class rune
	@brief A single UTF-8 encoded big-endian character.
	@see char
*/
typedef u32 rune;

/**
	@class char
	@brief A single extended ASCII (8 bits) encoded character.
	@see rune
*/
typedef char _doc_char;

typedef float f32;
typedef double f64;

typedef u16 b16;
typedef u32 b32;
typedef u64 b64;
#ifndef __cplusplus
	typedef byte bool;

	enum {
		false	= 0,
		true	= 1
	};
#endif

/**
	@def invalid_char
	@brief A value representing an invalid character.
	@memberof char
*/
#define invalid_char (char)-127

/**
	@def invalid_rune
	@brief A value representing an invalid rune.
	@memberof rune
*/
#define invalid_rune (rune)0xffffffff

/**
	@def null
	@brief A value representing an invalid address.
*/
#define null (void*)(0)

#endif
