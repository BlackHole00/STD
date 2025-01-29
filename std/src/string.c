#include <std/string.h>

std_String std_string_create(byte* data, usize length) {
	std_String string;
	byte* curret_ptr;
	usize i = 0;

	string.data = data;
	string.length = length;
	string.count = 0;

	curret_ptr = data;
	while (i < length) {
		usize current_rune_size;
		rune current_rune = std_rune_from_pointer(curret_ptr);
		
		current_rune_size = std_rune_bytes_used(current_rune);
		if (current_rune_size == 0) {
			goto string_create_invalid_encoding;
		}

		string.count++;
		i += current_rune_size;
		data += current_rune_size;
	}

	return string;

string_create_invalid_encoding:
	string.data = (byte*)null;
	string.length = 0;
	string.count = 0;

	return string;
}

std_String std_string_from_cstring(const char* cstring) {
	std_String string;
	usize i = 0;

	while (cstring[i] != 0) {
		i++;
	}

	string.data = (byte*)cstring;
	string.count = i;
	string.length = i;
	return string;
}

bool std_string_is_ascii(std_String string) {
	return string.count == string.length;
}

rune std_string_get(std_String string, usize index) {
	rune result;
	usize i;
	byte* current_ptr;
	u8 current_rune_size;

	if (index >= string.count) {
		return invalid_rune;
	}
	if (std_string_is_ascii(string)) {
		return (rune)string.data[index];
	}

	current_ptr = string.data;
	i = 0;
	while (i < string.count && i < index) {
		rune current_rune = std_rune_from_pointer(current_ptr);
		current_rune_size = std_rune_bytes_used(current_rune);

		/* TODO: assert current_rune_size != 0 */
		
		current_ptr += current_rune_size;
		i++;
	}

	result = std_rune_from_pointer(current_ptr);
	return result;
}

std_StringIterator std_string_iterator(std_String string) {
	std_StringIterator iterator;
	iterator.string = string;
	iterator.current_byte_idx = 0;

	return iterator;
}

bool std_stringiterator_next(std_StringIterator* iterator, rune* element) {
	usize current_byte;
	byte* current_ptr;
	rune current_rune;
	u8 current_rune_size;

	if (iterator->current_byte_idx >= iterator->string.length) {
		return false;
	}

	current_byte = iterator->current_byte_idx;
	current_ptr = &iterator->string.data[current_byte];
	current_rune = std_rune_from_pointer(current_ptr);
	current_rune_size = std_rune_bytes_used(current_rune);

	iterator->current_byte_idx += current_rune_size;

	*element = current_rune;
	return true;
}

