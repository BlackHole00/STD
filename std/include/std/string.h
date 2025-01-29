#ifndef _STD_STRING_INCLUDED
#define _STD_STRING_INCLUDED

#include <std/constant_symbols.h>
#include <std/types.h>
#include <std/runes.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/* UTF8 */
typedef struct std_String {
	byte* data;
	/* length in bytes of the string */
	usize length;
	/* number of characters */
	usize count;
} std_String;

typedef struct std_StringIterator {
	std_String string;
	usize current_byte_idx;
} std_StringIterator;

std_String std_string_create(byte* data, usize length);
std_String std_string_from_cstring(const char* cstring);
bool std_string_is_ascii(std_String string);
rune std_string_get(std_String string, usize index);
std_StringIterator std_string_iterator(std_String string);

bool std_stringiterator_next(std_StringIterator* iterator, rune* element);

#ifndef STD_DISALLOW_GLOBAL_NAMESPACE
	#define String std_String
	#define StringIterator std_StringIterator

	#define string_create std_string_create
	#define string_from_cstring std_string_from_cstring
	#define string_get std_string_get
	#define string_iterator std_string_iterator

	#define stringiterator_next std_stringiterator_next
#endif

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif
