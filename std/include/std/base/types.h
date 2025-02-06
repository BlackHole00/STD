#ifndef _STD_BASETYPES_INCLUDED
#define _STD_BASETYPES_INCLUDED

#include <std/base/constant_symbols.h>

/**
	@class byte
	@brief An unsigned byte. The STD equivalent to uint8_t.
	@see u8
*/
typedef unsigned char byte;

/**
	@class u8
	@brief An unsigned byte. The STD equivalent to uint8_t.
	@see u8
*/
typedef unsigned char u8;

/**
	@class i8
	@brief A signed byte. The STD equivalent to int8_t.
*/
typedef signed char i8;

/**
	@class u16
	@brief An unsigned 16-bit wide short. The STD equivalent to uint16_t.
*/
typedef unsigned short u16;

/**
	@class i16
	@brief A signed 16-bit wide short. The STD equivalent to int16_t.
*/
typedef signed short i16;

/**
	@class u32
	@brief An unsigned 32-bit wide int. The STD equivalent to uint32_t.
*/
typedef unsigned int u32;

/**
	@class i32
	@brief A signed 32-bit wide int. The STD equivalent to int32_t.
*/
typedef signed int i32;

#ifdef STD_COMPILER_CLANG
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wlong-long"
#elif defined(STD_COMPILER_GCC)
	#pragma gcc diagnostic push
	#pragma gcc diagnostic ignored "-Wlong-long"
#endif

/**
	@class u64
	@brief An unsigned 64-bit wide int. The STD equivalent to uint64_t.
*/
typedef unsigned long long int u64;


/**
	@class i64
	@brief A signed 64-bit wide int. The STD equivalent to int64_t.
*/
typedef signed long long int i64;

/* TODO: Change for 32 bits systems */
/**
	@class usize
	@brief An unsigned integer guaranteed to be register wide. The STD
		equivalent to size_t.
	@note When doing operations on pointer values prefer using @ref uintptr.
	@see uinptr
*/
typedef unsigned long long int usize;

/**
	@class isize
	@brief An signed integer guaranteed to be register wide. The STD
		equivalent to ssize_t.
*/
typedef signed long long int isize;

/**
	@class uintptr
	@brief An unsigned integer guaranteed to be register wide. The STD
		equivalent to size_t.
	@note Prefer using uintptr only when doing operations on pointer values.
		In other cases prefer using @ref usize.
	@see usize
*/
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

/**
	@class f32
	@brief A 32-bit wide floating point number.
*/
typedef float f32;

/**
	@class f64
	@brief A 64-bit wide floating point number.
	@see true
	@see false
*/
typedef double f64;

/**
	@class b16
	@brief A 16-bit wide boolean value.
	@see true
	@see false
*/
typedef u16 b16;

/**
	@class b32
	@brief A 32-bit wide boolean value.
	@see true
	@see false
*/
typedef u32 b32;

/**
	@class b64
	@brief A 64-bit wide boolean value.
	@see true
	@see false
*/
typedef u64 b64;

#ifndef STD_LANGUAGE_CPP
	/**
		@class bool
		@brief An 8-bit wide boolean value.
		@see b8
		@see true
		@see false
	*/
	typedef u8 bool;

	enum {
		false	= 0,
		true	= 1
	};
#endif

/**
	@class b8
	@brief An 8-bit wide boolean value.
	@see bool
	@see true
	@see false
*/
typedef bool b8;

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
