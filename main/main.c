#include <std/std.h>

void test_print(void) {
	std_syscall_write(0, "Hello world!\n\n", 15);
}

void test_slice(void) {
	usize i;
	char array[64];
	Slice array_slice;
	char character;

	character = '0';
	for (i = 0; i < 64; i++) {
		array[i] = character;
		character++;
	}

	array_slice = slice_create(array, 64, sizeof(char));
	for (i = 0; i < array_slice.count; i++) {
		character = *(char*)slice_get(array_slice, i);
		print_char(character);
	}

	print_char('\n');
	print_char('\n');
}

void test_chars(void) {
	char a_ascii = 0x61;
	char accented_a_ascii = 0x83;

	rune a_utf8 = 0x00000061;		/* 01100001 00000000 00000000 00000000 */
	rune accented_a_utf8 = 0x0000a1c3;	/* 11000011 10100001 00000000 00000000 */
	rune watashi_kanji = 0x0081a7e7;	/* 11100111 01111010 10000001 00000000 */
	rune smile_emoji = 0x80989ff0;		/* 11110000 10011111 10011000 10000000 */ 
 
	bool is_extended_ascii;
	bool is_ascii;
	bool valid;

	u8 bytes_used;

	print_rune(a_utf8);
	print_rune(accented_a_utf8);
	print_rune(watashi_kanji);
	print_rune(smile_emoji);
	print_char('\n');

	is_extended_ascii = std_char_is_extended_ascii(a_ascii);
	print_cstring("a_ascii, is extended ascii: ");
	print_cstring(is_extended_ascii ? "OK\n" : "NO\n");

	is_extended_ascii = std_char_is_extended_ascii(accented_a_ascii);
	std_syscall_write(0, "accented_a_ascii, is extended ascii: ", 37);
	std_syscall_write(0, is_extended_ascii ? "OK\n" : "NO\n", 3);

	is_ascii = std_rune_is_ascii(a_utf8);
	std_syscall_write(0, "a_utf8, is ascii: ", 18);
	std_syscall_write(0, is_ascii ? "OK\n" : "NO\n", 3);

	is_ascii = std_rune_is_ascii(accented_a_utf8);
	std_syscall_write(0, "accented_a_utf8, is ascii: ", 27);
	std_syscall_write(0, is_ascii ? "OK\n" : "NO\n", 3);

	bytes_used = std_rune_bytes_used(a_utf8);
	std_syscall_write(0, "a_utf8, bytes: ", 15);
	std_syscall_write(0, &"1234"[bytes_used - 1], 1);
	std_syscall_write(0, "\n", 1);

	bytes_used = std_rune_bytes_used(accented_a_utf8);
	std_syscall_write(0, "accented_a_utf8, bytes: ", 24);
	std_syscall_write(0, &"1234"[bytes_used - 1], 1);
	std_syscall_write(0, "\n", 1);

	bytes_used = std_rune_bytes_used(watashi_kanji);
	std_syscall_write(0, "watashi_kanji, bytes: ", 22);
	std_syscall_write(0, &"1234"[bytes_used - 1], 1);
	std_syscall_write(0, "\n", 1);

	bytes_used = std_rune_bytes_used(smile_emoji);
	std_syscall_write(0, "smile_emoji, bytes: ", 20);
	std_syscall_write(0, &"1234"[bytes_used - 1], 1);
	std_syscall_write(0, "\n", 1);

	valid = std_rune_is_valid(a_utf8);
	std_syscall_write(0, "a_utf8, valid: ", 15);
	std_syscall_write(0, valid ? "OK\n" : "NO\n", 3);

	valid = std_rune_is_valid(accented_a_utf8);
	std_syscall_write(0, "accented_a_utf8, valid: ", 24);
	std_syscall_write(0, valid ? "OK\n" : "NO\n", 3);

	valid = std_rune_is_valid(watashi_kanji);
	std_syscall_write(0, "watashi_kanji, valid: ", 22);
	std_syscall_write(0, valid ? "OK\n" : "NO\n", 3);

	valid = std_rune_is_valid(smile_emoji);
	std_syscall_write(0, "smile_emoji, valid: ", 20);
	std_syscall_write(0, valid ? "OK\n" : "NO\n", 3);

	valid = std_rune_is_valid(0xFFFFFFFF);
	std_syscall_write(0, "invalid rune, valid: ", 21);
	std_syscall_write(0, valid ? "OK\n" : "NO\n", 3);

	std_syscall_write(0, "a_utf8 == a_ascii: ", 19);
	std_syscall_write(0, std_rune_to_char(a_utf8) == a_ascii ? "OK " : "NO ", 3);
	std_syscall_write(0, a_utf8 == std_char_to_rune(a_ascii) ? "OK\n" : "NO\n", 3);

	std_syscall_write(0, "\n", 1);
}

void test_string(void) {
	String cstring;
	String standard_string;
	String utf8_string;
	StringIterator cstring_iterator;
	StringIterator standard_string_iterator;
	StringIterator utf8_string_iterator;

	const char* cstring_raw = "Hello string!";
	byte standard_raw[] = { 0x68, 0x65, 0x6c, 0x6c, 0x6f }; /* hello */
	byte utf8_raw[] = { /* watashi ha neko desu */
		0xe7, 0xa7, 0x81, 0xe3, 0x81, 0xaf, 0xe7, 0x8c, 0xab, 0xe3, 0x81, 0xa7, 0xe3, 0x81, 0x99
	};

	usize i = 0;
	rune character;

	cstring = string_from_cstring(cstring_raw);
	standard_string = string_create(standard_raw, 5);
	utf8_string = string_create(utf8_raw, 15);

	cstring_iterator = string_iterator(cstring);
	standard_string_iterator = string_iterator(standard_string);
	utf8_string_iterator = string_iterator(utf8_string);

	std_syscall_write(0, cstring.count == 13 ? "OK\n" : "NO\n", 3);
	std_syscall_write(0, standard_string.count == 5 ? "OK\n" : "NO\n", 3);
	std_syscall_write(0, utf8_string.count == 5 ? "OK\n" : "NO\n", 3);

	while (stringiterator_next(&cstring_iterator, &character)) {
		u8 character_size = rune_bytes_used(character);
		std_syscall_write(0, &character, character_size);
	}
	std_syscall_write(0, "\n", 1);

	while (stringiterator_next(&standard_string_iterator, &character)) {
		u8 character_size = rune_bytes_used(character);
		std_syscall_write(0, &character, character_size);
	}
	std_syscall_write(0, "\n", 1);

	while (stringiterator_next(&utf8_string_iterator, &character)) {
		u8 character_size = rune_bytes_used(character);
		std_syscall_write(0, &character, character_size);
	}
	std_syscall_write(0, "\n", 1);

	for (i = 0; i < cstring.count; i++) {
		u8 character_size;

		character = string_get(cstring, i);
		character_size = rune_bytes_used(character);

		std_syscall_write(0, &character, character_size);
	}
	std_syscall_write(0, "\n", 1);

	for (i = 0; i < standard_string.count; i++) {
		u8 character_size;

		character = string_get(standard_string, i);
		character_size = rune_bytes_used(character);

		std_syscall_write(0, &character, character_size);
	}
	std_syscall_write(0, "\n", 1);

	for (i = 0; i < utf8_string.count; i++) {
		u8 character_size;

		character = string_get(utf8_string, i);
		character_size = rune_bytes_used(character);

		std_syscall_write(0, &character, character_size);
	}
	std_syscall_write(0, "\n", 1);

	std_syscall_write(0, "\n", 1);
}

void test_mmap(void) {
	usize i;
	rune character;
	void* memory;
	char* string_memory;
	String string;

	memory = std_syscall_mmap(null, 1024, 0x01 | 0x02, 0x1000 | 0x0002, -1, 0);
	if ((isize)memory == -1) {
		return;
	}

	string_memory = (char*)memory;
	string_memory[0] = 'h';
	string_memory[1] = 'e';
	string_memory[2] = 'l';
	string_memory[3] = 'l';
	string_memory[4] = 'o';
	string_memory[5] = '\0';

	string = string_from_cstring(string_memory);
	for (i = 0; i < string.count; i++) {
		u8 character_size;

		character = string_get(string, i);
		character_size = rune_bytes_used(character);

		std_syscall_write(0, &character, character_size);
	}
	std_syscall_write(0, "\n", 1);

	std_syscall_munmap(memory, 1024);
}

void test_page(void) {
	PageDescriptor page_descriptor;
	Page page;
	Slice page_slice;

	page_descriptor.page_address = 0;
	page_descriptor.page_size = 16 * MEM_KILOBYTE;
	page_descriptor.protection = STD_PAGEPROTECTION_READ | STD_PAGEPROTECTION_WRITE;

	page_create(&page, page_descriptor);
	page_slice = std_page_as_slice(page, sizeof(usize));
	*(usize*)slice_get(page_slice, 1000) = 0x01;

	page_destroy(page);
}

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

void std_main(void) {
	test_print();
	test_slice();
	test_chars();
	test_string();
	test_mmap();
	test_page();
}

#ifdef STD_LANGUAGE_CPP
}
#endif
