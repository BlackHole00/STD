#ifndef _STD_FORMAT_INCLUDED
#define _STD_FORMAT_INCLUDED

#include <std/constant_symbols.h>
#include <std/string.h>
#include <std/syscalls.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

void print_bytes(void* data, usize size) {
	usize i;
	byte* data_as_bytes = (byte*)data;

	for (i = 0; i < size; i++) {
		usize j;
		byte mask = 0x80;
		byte current_byte = data_as_bytes[i];

		for (j = 0; j < 8; j++) {
			byte current_bit = (current_byte & mask) != 0;

			std_syscall_write(0, &"01"[current_bit], 1);
			mask >>= 1;
		}
	}
}

void print_char(char character) {
	std_syscall_write(0, &character, 1);
}

void print_rune(rune character) {
	std_syscall_write(0, &character, std_rune_bytes_used(character));
}

void print_string(std_String string) {
	std_syscall_write(0, string.data, string.length);
}

void print_cstring(const char* cstring) {
	usize string_length = 0;
	while (cstring[string_length] != '\0') {
		string_length++;
	}

	std_syscall_write(0, cstring, string_length);
}

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif

