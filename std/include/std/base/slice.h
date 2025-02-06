#ifndef _STD_BASESLICE_INCLUDED
#define _STD_BASESLICE_INCLUDED

#include <std/base/constant_symbols.h>
#include <std/base/types.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	A slice pepresents a fat pointer to some elements. This means that 
	internally it contains a reference to the first element and the number
	of consecutive elements.
	A slice has three possible states:
		- null: the slice is referencing a @ref null pointer (the
			default state)
		- empty: the slice is referencing a valid pointer, but the 
			number of elements is set to 0. It can be usefull for 
			subslicing
		- valid: the slice is referencing a valid pointer and the 
			number of elements is not 0
	Please note that it is preferrable to pass slices by value.

	@brief Represents a reference to some elements. It can be seen as a
		safer pointer.
	@note Slices **do not own** any data. Any operation on slices will never
		allocate, deallocate or create copies of the referenced data.
		For operations related to memory menagament, consider looking at
		@ref std/mem.h.
*/
typedef struct std_Slice {
	/** @brief A pointer to the first element of the referenced data. */
	void* data;
	/** @brief The length in bytes of the referenced data. */
	usize length;
	/** @brief The number of elements. */
	usize count;
	/** @brief The size in bytes of a single element. */
	u32 element_size;
} std_Slice;

/**
	@brief Creates new slice.
	@param data The data to be referenced.
	@param count The number of elements in the data
	@param element_size The size of a single element. If 0 it will be
		interpreted as 1 (byte slice).
	@return The slice referencing the specified data.
	@memberof std_Slice
*/
std_Slice std_slice_create(void* data, usize count, u32 element_size);

/**
	@brief Checks if a slice is null.
	@param slice The slice.
	@return @ref true if the slice is in the null state, @ref false 
		otherwise.
	@memberof std_Slice
*/
bool std_slice_is_null(std_Slice slice);

/**
	@brief Checks if a slice is empty.
	@param slice The slice.
	@return @ref true if the slice is in the empty state, @ref false 
		otherwise.
	@memberof std_Slice
*/
bool std_slice_is_empty(std_Slice slice);

/**
	@brief Checks if a given index is valid.
	@param slice The slice.
	@param index The index.
	@return @ref true if the specified index can be used to access the slice
		(it is within bounds), @ref false otherwise.
	@memberof std_Slice
*/
bool std_slice_is_index_valid(std_Slice slice, usize index);

/**
	@brief Gets the pointer to the i-th element of the referenced data.
	@param slice The slice.
	@param index The index.
	@returns A pointer to the i-th element if the index is valid (within 
		bounds), @ref null otherwise.
	@memberof std_Slice
*/
void* std_slice_get(std_Slice slice, usize index);

/**
	@brief Gets the pointer to the i-th byte of the referenced data, 
		ignoring the size of the single items.
	@param slice The slice.
	@param offset the byte offset to be used.
	@returns A valid pointer if the offset is valid (within bounds), @ref 
		null otherwise.
	@memberof std_Slice
*/
byte* std_slice_get_byte(std_Slice slice, usize offset);

/**
	@brief Converts the slice to a slice with elements of different size.
	@param slice The slice to convert.
	@param element_size The size of the elements of the new size.
	@return The converted slice with the new element size.
	@note This operation is a transmutation. No new memory is allocated and
		no casts occur.
	@memberof std_Slice
*/
std_Slice std_slice_as_slice(std_Slice slice, u32 element_size);

/**
	@brief Converts a slice into a slice of bytes.
	@param slice The slice.
	@returns The provided slice converted into a slice of bytes.
	@memberof std_Slice
*/
std_Slice std_slice_as_byte_slice(std_Slice slice);

/**
	Given a slice and valid indices begin and end, creates a new subslice
	that points to the begin-th element of the original data and has 
	end - begin number of items (begin is inclusive, end is exclusive).

	@brief Creates a subslice.
	@param slice The slice to subslice.
	@param begin The index of the first element of the subslice (inclusive).
	@param end The index of the element after the last to be included in the
		subslice (thus the index is exclusive)
	@return The subslice referencing the data as defined above 
		`(slice[begin..<end])`.
	@note Subslicing does not copy the backing data of the original slice, 
		it only takes a reference to it.
	@memberof std_Slice
*/
std_Slice std_slice_subslice(std_Slice slice, usize begin, usize end);

/**
	@brief Creates a new slice from an array literal
	@param _array The array literal.
	@return A new slice referencing the entirity of the array.
	@memberof std_Slice
*/
#define STD_SLICE_FROM_ARRAY(_array) std_slice_create(_array, sizeof(_array), sizeof(*_array))

/**
	@brief Creates a slice referencing a single element.
	@param _element The element.
	@return A new slice referencing a single element.
	@memberof std_Slice
*/
#define STD_SLICE_FROM_ELEMENT(_element) std_slice_create(&(_element), sizeof(_element), sizeof(_element))

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif

