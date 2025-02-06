#ifndef _STD_BASERUNES_INCLUDED
#define _STD_BASERUNES_INCLUDED

#include <std/base/constant_symbols.h>
#include <std/base/types.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	@brief Returns the bytes used by a rune.
	@param utf8_rune The rune.
	@return Returns the bytes used by the rune (1 to 4). Returns 0 if the
		rune is invalid or if its encoding is incorrect.
	@memberof rune
*/
u8 std_rune_bytes_used(rune utf8_rune);

/**
	@brief Parses the data passed as input and returns the corresponding 
	rune.
	@param pointer The pointer the the first byte of the data.
	@return The parsed rune if the data encoding is valid. @ref invalid_rune
		otherwise.
	@memberof rune
*/
rune std_rune_from_pointer(byte* pointer);

/**
	@brief Checks if the rune is a valid utf8 character.
	@param utf8_rune The rune.
	@return @ref true if the rune is a valid utf8 character (thus it is not
		@ref invalid_rune and its encoding is valid). @ref false 
		otherwise.
	@memberof rune
*/
bool std_rune_is_valid(rune utf8_rune);

/**
	@brief Checks if a rune is an ascii character.
	@param utf8_rune The rune.
	@return @ref true if the rune is a non-extended ascii character 
		(values 0-127). @ref false otherwise.
	@memberof rune
*/
bool std_rune_is_ascii(rune utf8_rune);

/**
	@brief Converts a rune to a char.
	@param utf8_rune The rune.
	@return the converted ascii encoded character. @ref invalid_char if the
		rune is not representable by a standard char.
	@memberof rune
*/
char std_rune_to_char(rune utf8_rune);

/**
	@brief Checks if a char is valid.
	@param character The character.
	@return @ref true if the character is not @ref invalid_char. @ref false
		otherwise.
	@memberof char
*/
bool std_char_is_valid(char character);

/**
	@brief Checks if a char is extended ascii.
	@param character The character.
	@return @ref true if the character is extended ascii (value 128-255).
		@ref false otherwise.
	@memberof char
*/
bool std_char_is_extended_ascii(char character);

/**
	@brief Converts a char to a rune.
	@param character The character
	@return The converted utf8 encoded character. @ref invalid_rune if the 
		character is not representable a rune (aka it is encoded in
		extended ascii or it is @ref invalid_char).
	@memberof char
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

