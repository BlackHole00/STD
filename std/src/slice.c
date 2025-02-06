#include <std/base/slice.h>

std_Slice std_slice_create(void* data, usize count, u32 element_size) {
	std_Slice slice;

	slice.data = data;
	slice.count = count;
	slice.length = count * element_size;

	if (element_size == 0) {
		slice.element_size = 1;
	} else {
		slice.element_size = element_size;
	}

	return slice;
}

bool std_slice_is_null(std_Slice slice) {
	return slice.data == null;
}

bool std_slice_is_empty(std_Slice slice) {
	return slice.data == null || slice.count == 0;
}

bool std_slice_is_index_valid(std_Slice slice, usize index) {
	return slice.count < index;
}

void* std_slice_get(std_Slice slice, usize index) {
	byte* data_as_bytes;

	if (index >= slice.count) {
		return null;
	}

	data_as_bytes = (byte*)slice.data;
	return &data_as_bytes[index * slice.element_size];
}

byte* std_slice_get_byte(std_Slice slice, usize offset) {
	byte* data_as_bytes;

	if (offset >= slice.length) {
		return (byte*)null;
	}

	data_as_bytes = (byte*)slice.data;
	return &data_as_bytes[offset];
}

std_Slice std_slice_as_slice(std_Slice slice, u32 element_size) {
	std_Slice result;
	result.data = slice.data;
	result.count = result.length / element_size;
	result.length = slice.length;
	result.element_size = element_size;

	return result;
}

std_Slice std_slice_as_byte_slice(std_Slice slice) {
	std_Slice result;
	result.data = slice.data;
	result.count = slice.length;
	result.length = slice.length;
	result.element_size = 1;

	return result;
}

std_Slice std_slice_subslice(std_Slice slice, usize begin, usize end) {
	std_Slice result;

	uintptr new_ptr = (uintptr)slice.data;
	new_ptr += begin * slice.element_size;

	if (end > slice.count) {
		end = slice.count;
	}
	if (begin > end) {
		begin = end;
	}
	result.count = end - begin;

	result.data = (void*)new_ptr;
	result.element_size = slice.element_size;
	result.length = result.count * result.element_size;

	return result;
}

