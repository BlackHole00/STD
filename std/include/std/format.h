#ifndef _STD_FORMAT_INCLUDED
#define _STD_FORMAT_INCLUDED

/* TODO: This entire file is temporary, implement a stream and printing system */

#include <std/base/constant_symbols.h>
#include <std/base/string.h>

#include <std/posix/syscalls.h>
#include <std/windows/constants.h>
#include <std/windows/kernel32.h>

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

#ifdef STD_PLATFORM_POSIX
			std_posix_syscall_write(0, &"01"[current_bit], 1);
#elif defined(STD_PLATFORM_WINDOWS)
			WriteConsoleA(GetStdHandle(STD_WINDOWS_STD_OUTPUT_HANDLE), &"01"[current_bit], 1, (std_LPDWORD)null, null);
#endif
			mask >>= 1;
		}
	}
}

void print_char(char character) {
#ifdef STD_PLATFORM_POSIX
	std_posix_syscall_write(0, &character, 1);
#elif defined(STD_PLATFORM_WINDOWS)
	WriteConsoleA(GetStdHandle(STD_WINDOWS_STD_OUTPUT_HANDLE), &character, 1, (std_LPDWORD)null, null);
#endif
}

void print_rune(rune character) {
#ifdef STD_PLATFORM_POSIX
	std_posix_syscall_write(0, &character, std_rune_bytes_used(character));
#elif defined(STD_PLATFORM_WINDOWS)
	WriteConsoleA(
		GetStdHandle(STD_WINDOWS_STD_OUTPUT_HANDLE),
		&character,
		std_rune_bytes_used(character),
		(std_LPDWORD)null,
		null
	);
#endif
}

void print_string(std_String string) {
#ifdef STD_PLATFORM_POSIX
	std_posix_syscall_write(0, string.data, string.length);
#elif defined(STD_PLATFORM_WINDOWS)
	WriteConsoleA(GetStdHandle(STD_WINDOWS_STD_OUTPUT_HANDLE), string.data, string.length, (std_LPDWORD)null, null);
#endif
}

void print_cstring(const char* cstring) {
	usize string_length = 0;
	while (cstring[string_length] != '\0') {
		string_length++;
	}

#ifdef STD_PLATFORM_POSIX
	std_posix_syscall_write(0, cstring, string_length);
#elif defined(STD_PLATFORM_WINDOWS)
	WriteConsoleA(GetStdHandle(STD_WINDOWS_STD_OUTPUT_HANDLE), cstring, string_length, (std_LPDWORD)null, null);
#endif
}

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif

