#ifndef _STD_SLICE_INCLUDED
#define _STD_SLICE_INCLUDED

#include <std/constant_symbols.h>
#include <std/types.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

/**
	@struct std_Slice
	@brief represents a reference to some elements. It can be seen as a 
		safer pointer
	@usage prefer passing it by value
*/
typedef struct std_Slice {
	/** @brief a pointer to the first element of the referenced data */
	void* data;
	/** @brief the length in bytes of the referenced data */
	usize length;
	/** @brief the number of elements */
	usize count;
	/** @brief the size in bytes of a single element */
	u32 element_size;
} std_Slice;

/**
	@fn std_slice_create
	@brief creates new slice
	@param data the data to be referenced
	@param count the number of elements in the data
	@param element_size the size of a single element. If 0 it will be
		interpreted as 1 (byte slice)
	@return the slice referencing the specified data
*/
std_Slice std_slice_create(void* data, usize count, u32 element_size);

/**
	@fn std_slice_is_null
	@brief checks if a slice is null
	@return true if the data field is null, false otherwise
*/
bool std_slice_is_null(std_Slice slice);

/**
	@fn std_slice_is_empty
	@brief checks if a slice is empty
	@return true if the data field is null or the length is zero, false
		otherwise
*/
bool std_slice_is_empty(std_Slice slice);

/**
	@fn std_slice_is_index_valid
	@brief checks if a given index is valid
*/
bool std_slice_is_index_valid(std_Slice slice, usize index);

/**
	@fn std_slice_get
	@brief gets the pointer to the i-th element of the referenced data
	@param slice
	@param index the index to be used
	@returns a valid pointer if the index is valid (within bounds), null
		otherwise
*/
void* std_slice_get(std_Slice slice, usize index);

/**
	@fn std_slice_get_by_offset
	@brief gets the pointer to the i-th byte of the referenced data,
		ignoring the size of the single items
	@param slice
	@param offset the byte offset to be used
	@returns a valid pointer if the offset is valid (within bounds), null
		otherwise
*/
void* std_slice_get_by_offset(std_Slice slice, usize offset);

#ifndef STD_DISALLOW_GLOBAL_NAMESPACE
	#define Slice std_Slice

	#define slice_create std_slice_create
	#define slice_is_null std_slice_is_null
	#define slice_is_empty std_slice_is_empty
	#define slice_is_index_valid std_slice_is_index_valid
	#define slice_get std_slice_get
	#define slice_get_by_offset std_slice_get_by_offset
#endif

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif

