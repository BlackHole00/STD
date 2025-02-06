#ifndef _STD_BASESTRING_INCLUDED
#define _STD_BASESTRING_INCLUDED

#include <std/base/constant_symbols.h>
#include <std/base/types.h>
#include <std/base/runes.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	Represents a reference to an utf8 encoded string. Since utf8 is backward
	compatible with non-extended ansi, `std_String` can be used to also
	represent cstrings.

	A slice has three possible states:
		- null: the string is referencing a @ref null string (the
			default state)
		- empty: the string is referencing a valid string, but the 
			number of elements is set to 0. It can be usefull for 
			substrings.
		- valid: the string is referencing a valid string and the 
			number of elements is not 0
	Please note that it is preferrable to pass slices by value.

	Conceptually strings are equivalent to `std::string_view`.

	@brief Represents an utf8 encoded string.
	@note Strings **do not own** any data. Any operation on strings will
		never allocate, deallocate or create copies of the referenced
		data. For operations related to memory menagament, consider
		looking at std/mem.h. Consider `std_String` as
		`std::string_view`, not `std::string`.
	@see std_StringIterator
*/
typedef struct std_String {
	/** @brief A pointer to the first byte of the string. */
	byte* data;
	/** @brief The length in bytes of the string. */
	usize length;
	/**
		If the string contains non-ascii characters, the count is
		different from @ref length.
		@brief The number of characters in the string.
	*/
	usize count;
} std_String;

/**
	@brief An iterator over a string.
	@see std_String
	@see std_string_iterator
*/
typedef struct std_StringIterator {
	/** @brief The referenced string. */
	std_String string;
	/** @brief The byte currently read. */
	usize current_byte_idx;
} std_StringIterator;

/**
	@brief Creates a string from a buffer of data.
	@param data A pointer to the buffer.
	@param length The length of the buffer.
	@return A new string pointing to the buffer if the utf8 encoding is 
		correct. A null string otherwise.
	@note The string will take a reference of the data, it will not allocate
		a new buffer.
	@memberof std_String
*/
std_String std_string_create(byte* data, usize length);

/**
	@brief Creates a string from a ascii-encoded cstring.
	@param cstring The string.
	@return A new string pointing to the provided input string if the
		cstring does not include any extended-ascii character. A null
		string otherwise.
	@note The string will take a reference to the cstring, it will not
		allocate a new buffer.
	@memberof std_String
*/
std_String std_string_from_cstring(const char* cstring);

/**
	@brief Checks if the string is null.
	@param string The string.
	@return @ref true if the string is in the null state. @ref false 
		otherwise
	@memberof std_String
*/
bool std_string_is_null(std_String string);

/**
	@brief Checks if the string is empty (it is null or has length 0).
	@param string The string.
	@return @ref true if the string is null or its is empty. @ref false
		otherwise.
	@memberof std_String
*/
bool std_string_is_empty(std_String string);

/**
	@brief Checks if the string is ascii encoded.
	@param string The string.
	@return @ref true if the string is ascii encoded. @ref false otherwise.
	@memberof std_String
*/
bool std_string_is_ascii(std_String string);

/**
	@brief Returns the i-th rune of the string.
	@param string The string.
	@param index The index.
	@return The specified rune. If the index is out of bounds,
		@ref invalid_rune will be returned.
	@memberof std_String
*/
rune std_string_get(std_String string, usize index);

/**
	@brief Checks if a given rune index is valid.
	@param string The string.
	@param index The index.
	@return @ref true if the index is valid and can be used to index the
		string. @ref false otherwise.
	@memberof std_String
*/
bool std_string_is_index_valid(std_String string, usize index);

/**
	@brief Returns an iterator for a string.
	@param string The string.
	@return An iterator referencing the string.
	@memberof std_String
*/
std_StringIterator std_string_iterator(std_String string);

/**
	@brief Gets the next element of the iterator.
	@param iterator The iterator.
	@param[out] element The current rune.
	@return @ref true if the current rune is valid, @ref false if it is not
		and the iterator does not have other elements.
	@memberof std_StringIterator
*/
bool std_stringiterator_next(std_StringIterator* iterator, rune* element);

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif
