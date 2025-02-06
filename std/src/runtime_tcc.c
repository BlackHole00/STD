#include <std/base/constant_symbols.h>
#ifdef STD_COMPILER_TCC

#include <std/base/types.h>

void* memmove(void* destination, const void* source, usize size) {
	usize i;

	u32* destination_words = (u32*)source;
	u32* source_words = (u32*)source;
	byte* destination_bytes = (byte*)source;
	byte* source_bytes = (byte*)source;

	for (i = 0; i < size / 4; i++) {
		destination_words[i] = source_words[i];
	}
	for (i = 0; i < size % 4; i++) {
		destination_bytes[size / 4 * 4 + i] = source_bytes[size / 4 * 4 + i];
	}

	return destination;
}

void* memset(void* data, i32 value, usize size) {
	usize i;
	byte* data_bytes = (byte*)data;

	for (i = 0; i < size; i++) {
		data_bytes[i] = (byte)value;
	}

	return data;
}

#endif

