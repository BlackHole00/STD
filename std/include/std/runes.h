#ifndef _STD_RUNES_INCLUDED
#define _STD_RUNES_INCLUDED

#include <std/constant_symbols.h>
#include <std/types.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	@fn std_rune_bytes_used
	@brief returns the number of bytes actually used in the utf8 rune. 0 if
		the rune is not properly encoded or invalid
*/
u8 std_rune_bytes_used(rune utf8_rune);

rune std_rune_from_pointer(byte* pointer);

/**
	@fn std_rune_is_valid
	@brief checks if the rune is a valid utf8 character (and thus is 
		encoded correctly)
*/
bool std_rune_is_valid(rune utf8_rune);

/**
	@fn std_rune_is_ascii
	@brief checks if a rune is an ascii character
*/
bool std_rune_is_ascii(rune utf8_rune);

/**
	@fn std_rune_to_char
	@brief converts a rune to a char
	@return the converted ascii encoded character. invalid_char if the rune
		is not representable by a standard char
*/
char std_rune_to_char(rune utf8_rune);

/**
	@fn std_char_is_valid
	@brief checks if a char is valid
*/
bool std_char_is_valid(char character);

/**
	@fn std_char_is_extended_ascii
	@brief checks if a char is extended ascii
*/
bool std_char_is_extended_ascii(char character);

/**
	@fn std_char_to_rune
	@brief converts a char to a rune
	@return the converted utf8 encoded character. invalid_rune if the char
		is not representable a rune (char is in extended ascii or 
		invalid_char)
*/
rune std_char_to_rune(char character);

#ifndef STD_DISALLOW_GLOBAL_NAMESPACE
	#define rune_from_pointer std_rune_from_pointer
	#define rune_bytes_used std_rune_bytes_used
	#define rune_is_valid std_rune_is_valid
	#define rune_is_ascii std_rune_is_ascii
	#define rune_to_char std_rune_to_char

	#define char_is_valid std_char_is_valid
	#define char_is_extended_ascii std_char_is_extended_ascii
	#define char_to_rune std_char_to_rune
#endif

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif

