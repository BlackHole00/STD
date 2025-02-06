#ifndef _STD_BASESTRING_INCLUDED
#define _STD_BASESTRING_INCLUDED

#include <std/base/constant_symbols.h>
#include <std/base/types.h>
#include <std/base/runes.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	@struct std_String
	@brief represents an utf8 encoded string
	@note prefer passing strings by value
*/
typedef struct std_String {
	/** @brief a pointer to the first byte of the string */
	byte* data;
	/** @brief the length in bytes of the string */
	usize length;
	/**
		@brief the number of characters in the string
		@note this might be different than length
	*/
	usize count;
} std_String;

/**
	@struct std_StringIterator
*/
typedef struct std_StringIterator {
	std_String string;
	usize current_byte_idx;
} std_StringIterator;

/**
	@fn std_string_create
	@brief creates a string from a buffer of data
	@param data a pointer to the buffer
	@param length the length of the buffer
	@return a new string pointing to the buffer if the utf8 encoding is 
		correct. Returns a null string otherwise
	@note the string will take a reference of the data, it will not allocate
		a new buffer
*/
std_String std_string_create(byte* data, usize length);

/**
	@fn std_string_from_cstring
	@brief creates a string from a ascii-encoded cstring
	@param cstring the string
	@return a new string pointing to the provided input string
	@note the string will take a reference to the cstring, it will not
		allocate a new buffer
*/
std_String std_string_from_cstring(const char* cstring);

/**
	@fn std_string_is_null
	@brief checks if the string is null (it points to null)
	@param string
*/
bool std_string_is_null(std_String string);

/**
	@fn std_string_is_empty
	@brief checks if the string is empty (it is null or has length 0)
	@param string
*/
bool std_string_is_empty(std_String string);

/**
	@fn std_string_is_ascii
	@brief checks if the string is ascii encoded
	@param string
*/
bool std_string_is_ascii(std_String string);

/**
	@fn std_string_get
	@brief returns the i-th rune of the string
	@param string
	@param index
	@return returns the specified rune. If the index is out of bounds,
		invalid_rune will be returned
*/
rune std_string_get(std_String string, usize index);

/**
	@fn std_string_is_index_valid
	@brief checks if a given rune index is valid
	@param string
	@param index
*/
bool std_string_is_index_valid(std_String string, usize index);

/**
	@fn std_string_iterator
	@brief returns an iterator for the current string
	@param string
*/
std_StringIterator std_string_iterator(std_String string);

/**
	@fn std_stringiterator_next
	@brief gets the next element of the iterator
	@param iterator
	@param element
	@return true if the current element is valid, false if it is not and
		the iterator does not have other elements
*/
bool std_stringiterator_next(std_StringIterator* iterator, rune* element);

#ifndef STD_DISALLOW_GLOBAL_NAMESPACE
	#define String std_String
	#define StringIterator std_StringIterator

	#define string_create std_string_create
	#define string_from_cstring std_string_from_cstring
	#define string_is_null std_string_is_null
	#define string_is_empty std_string_is_empty
	#define string_is_ascii std_string_is_ascii
	#define string_get std_string_get
	#define string_iterator std_string_iterator

	#define stringiterator_next std_stringiterator_next
#endif

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif
