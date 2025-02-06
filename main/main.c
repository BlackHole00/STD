#include <std/std.h>

void test_print(void) {
	print_cstring("Hello world!\n\n");
}

void test_slice(void) {
	usize i;
	char array[64];
	std_Slice array_slice;
	char character;

	character = '0';
	for (i = 0; i < 64; i++) {
		array[i] = character;
		character++;
	}

	array_slice = std_slice_create(array, 64, sizeof(char));
	for (i = 0; i < array_slice.count; i++) {
		character = *(char*)std_slice_get(array_slice, i);
		print_char(character);
	}

	print_char('\n');
	print_char('\n');
}

void test_chars(void) {
	char a_ascii = 0x61;
	char accented_a_ascii = 0x83;

	rune a_utf8 = 0x00000061;
	rune accented_a_utf8 = 0x0000a1c3;
	rune watashi_kanji = 0x0081a7e7;
	rune smile_emoji = 0x80989ff0;
 
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
	print_cstring("accented_a_ascii, is extended ascii: ");
	print_cstring(is_extended_ascii ? "OK\n" : "NO\n");

	is_ascii = std_rune_is_ascii(a_utf8);
	print_cstring("a_utf8, is ascii: ");
	print_cstring(is_ascii ? "OK\n" : "NO\n");

	is_ascii = std_rune_is_ascii(accented_a_utf8);
	print_cstring("accented_a_utf8, is ascii: ");
	print_cstring(is_ascii ? "OK\n" : "NO\n");

	bytes_used = std_rune_bytes_used(a_utf8);
	print_cstring("a_utf8, bytes: ");
	print_cstring(&"1234"[bytes_used - 1]);
	print_cstring("\n");

	bytes_used = std_rune_bytes_used(accented_a_utf8);
	print_cstring("accented_a_utf8, bytes: ");
	print_cstring(&"1234"[bytes_used - 1]);
	print_cstring("\n");

	bytes_used = std_rune_bytes_used(watashi_kanji);
	print_cstring("watashi_kanji, bytes: ");
	print_cstring(&"1234"[bytes_used - 1]);
	print_cstring("\n");

	bytes_used = std_rune_bytes_used(smile_emoji);
	print_cstring("smile_emoji, bytes: ");
	print_cstring(&"1234"[bytes_used - 1]);
	print_cstring("\n");

	valid = std_rune_is_valid(a_utf8);
	print_cstring("a_utf8, valid: ");
	print_cstring(valid ? "OK\n" : "NO\n");

	valid = std_rune_is_valid(accented_a_utf8);
	print_cstring("accented_a_utf8, valid: ");
	print_cstring(valid ? "OK\n" : "NO\n");

	valid = std_rune_is_valid(watashi_kanji);
	print_cstring("watashi_kanji, valid: ");
	print_cstring(valid ? "OK\n" : "NO\n");

	valid = std_rune_is_valid(smile_emoji);
	print_cstring("smile_emoji, valid: ");
	print_cstring(valid ? "OK\n" : "NO\n");

	valid = std_rune_is_valid(0xFFFFFFFF);
	print_cstring("invalid rune, valid: ");
	print_cstring(valid ? "OK\n" : "NO\n");

	print_cstring("a_utf8 == a_ascii: ");
	print_cstring(std_rune_to_char(a_utf8) == a_ascii ? "OK " : "NO ");
	print_cstring(a_utf8 == std_char_to_rune(a_ascii) ? "OK\n" : "NO\n");

	print_cstring("\n");
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

	print_cstring(cstring.count == 13 ? "OK\n" : "NO\n");
	print_cstring(standard_string.count == 5 ? "OK\n" : "NO\n");
	print_cstring(utf8_string.count == 5 ? "OK\n" : "NO\n");

	while (stringiterator_next(&cstring_iterator, &character)) {
		print_rune(character);
	}
	print_cstring("\n");

	while (stringiterator_next(&standard_string_iterator, &character)) {
		print_rune(character);
	}
	print_cstring("\n");

	while (stringiterator_next(&utf8_string_iterator, &character)) {
		print_rune(character);
	}
	print_cstring("\n");

	for (i = 0; i < cstring.count; i++) {
		character = string_get(cstring, i);
		print_rune(character);
	}
	print_cstring("\n");

	for (i = 0; i < standard_string.count; i++) {
		character = string_get(cstring, i);
		print_rune(character);
	}
	print_cstring("\n");

	for (i = 0; i < utf8_string.count; i++) {
		character = string_get(cstring, i);
		print_rune(character);
	}
	print_cstring("\n");

	print_cstring("\n");
}

void test_page(void) {
	PageDescriptor page_descriptor;
	Page page;
	std_Slice page_slice;

	page_descriptor.page_address = 0;
	page_descriptor.page_size = 16 * MEM_KILOBYTE;
	page_descriptor.protection = STD_PAGEPROTECTION_READ | STD_PAGEPROTECTION_WRITE;

	page_create(&page, page_descriptor);
	page_slice = std_page_as_slice(page, sizeof(usize));
	*(usize*)std_slice_get(page_slice, 1000) = 0x01;

	page_destroy(page);
}

void std_main(void) {
	test_print();
	test_slice();
	test_chars();
	test_string();
	test_page();
}

