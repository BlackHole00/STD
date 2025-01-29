#ifndef _STD_TYPES_INCLUDED
#define _STD_TYPES_INCLUDED

typedef unsigned char byte;

typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
typedef signed int i32;

/* TODO: Support msvc (__int64) and gcc (#pragma gcc ...) */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlong-long"
typedef unsigned long long int u64;
typedef signed long long int i64;

/* TODO: Change for 32 bits systems */
typedef unsigned long long int usize;
typedef signed long long int isize;
typedef unsigned long long int uintptr;
#pragma clang diagnostic pop

/** @brief a single UTF-8 encoded big-endian character */
typedef u32 rune;
/** @brief a single extended ASCII (8 bits) encoded character */
/* typedef char char; */

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

#define invalid_char (char)0x81
#define invalid_rune (rune)0xffffffff

#define null (void*)(0)

#endif
