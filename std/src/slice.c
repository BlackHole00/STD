#include <std/slice.h>

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

void* std_slice_get_by_offset(std_Slice slice, usize offset) {
	byte* data_as_bytes;

	if (offset >= slice.length) {
		return null;
	}

	data_as_bytes = (byte*)slice.data;
	return &data_as_bytes[offset];
}

