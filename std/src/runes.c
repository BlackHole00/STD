#include <std/base/runes.h>

u8 std_rune_header_size(byte byte) {
	if ((byte & 0x80) == 0) {
		return 1;
	}
	if ((byte & 0xE0) == 0xC0) {
		return 2;
	}
	if ((byte & 0xF0) == 0xE0) {
		return 3;
	}
	if ((byte & 0xF8) == 0xF0) {
		return 4;
	}
	return 0;
}

rune std_rune_from_pointer(byte* pointer) {
	u8 i;
	usize rune_size;
	union {
		byte bytes[4];
		rune rune;
	} rune_bytes;

	rune_bytes.rune = 0;
	rune_bytes.bytes[0] = pointer[0];

	rune_size = std_rune_header_size(pointer[0]);
	for (i = 1; i < rune_size; i++) {
		rune_bytes.bytes[i] = pointer[i];
	}

	return rune_bytes.rune;
}

u8 std_rune_bytes_used(rune utf8_rune) {
	if (utf8_rune == invalid_rune) {
		return 0;
	}

	return std_rune_header_size(utf8_rune << 24 >> 24);
}

bool std_rune_is_valid(rune utf8_rune) {
	if (utf8_rune == invalid_rune) {
		return false;
	}

	/* TODO: Support big-endian */
	if ((utf8_rune & 0x00000080) == 0) {
		return true;
	}
	if ((utf8_rune & 0x0000C0E0) == 0x000080C0) {
		return true;
	}
	if ((utf8_rune & 0x00C0C0F0) == 0x008080E0) {
		return true;
	}
	if ((utf8_rune & 0xC0C0C0F0) == 0x808080F0) {
		return true;
	}

	return false;
}

bool std_rune_is_ascii(rune utf8_rune) {
	return (utf8_rune & 0x00000080) == 0;
}

char std_rune_to_char(rune utf8_rune) {
	if (std_rune_is_ascii(utf8_rune)) {
		return (char)(utf8_rune << 24 >> 24);
	} else {
		return invalid_char;
	}
}

bool std_char_is_valid(char character) {
	return character != invalid_char;
}

bool std_char_is_extended_ascii(char character) {
	return (character & 0x80) != 0;
}

rune std_char_to_rune(char character) {
	if (std_char_is_extended_ascii(character)) {
		return invalid_rune;
	}

	return (rune)character;
}


