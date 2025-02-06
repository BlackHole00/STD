#ifndef _STD_BASERUNES_INCLUDED
#define _STD_BASERUNES_INCLUDED

#include <std/base/constant_symbols.h>
#include <std/base/types.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	@fn std_rune_bytes_used
	@brief returns the number of bytes actually used in the utf8 rune. 0 if
		the rune is not properly encoded or invalid
	@param utf8_rune
	@return returns the bytes used by the rune (1 to 4). Returns 0 if the
		rune is invalid or if its encoding is incorrect
*/
u8 std_rune_bytes_used(rune utf8_rune);

/**
	@fn std_rune_from_pointer
	@brief parses the data passed as input and returns the corresponding 
	rune
	@param pointer
	@return the rune if the data encoding is valid. invalid_rune otherwise
*/
rune std_rune_from_pointer(byte* pointer);

/**
	@fn std_rune_is_valid
	@brief checks if the rune is a valid utf8 character (and thus is 
		encoded correctly)
	@param utf8_rune
*/
bool std_rune_is_valid(rune utf8_rune);

/**
	@fn std_rune_is_ascii
	@brief checks if a rune is an ascii character
	@param utf8_rune
*/
bool std_rune_is_ascii(rune utf8_rune);

/**
	@fn std_rune_to_char
	@brief converts a rune to a char
	@param utf8_rune
	@return the converted ascii encoded character. invalid_char if the rune
		is not representable by a standard char
*/
char std_rune_to_char(rune utf8_rune);

/**
	@fn std_char_is_valid
	@brief checks if a char is valid
	@param character
*/
bool std_char_is_valid(char character);

/**
	@fn std_char_is_extended_ascii
	@brief checks if a char is extended ascii
	@param character
*/
bool std_char_is_extended_ascii(char character);

/**
	@fn std_char_to_rune
	@brief converts a char to a rune
	@param character
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

