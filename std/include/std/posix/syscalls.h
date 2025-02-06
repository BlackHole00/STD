#ifndef _STD_POSIXSYSCALLS_INCLUDED
#define _STD_POSIXSYSCALLS_INCLUDED

#include <std/base/constant_symbols.h>
#ifdef STD_PLATFORM_POSIX

#include <std/base/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
	@fn std_syscall_write
	@brief calls the write syscall
	@param file_descriptor
	@param buffer
	@param buffer_size
	@return the number of bytes written. -1 if an error occurred
*/
extern isize std_posix_syscall_write(u32 file_descriptor, const void* buffer, usize buffer_size);

/**
	@fn std_syscall_mmap
	@brief calls the mmap syscall
	@param base_address
*/
extern void* std_posix_syscall_mmap(
	void* base_address,
	isize length,
	i32 protection,
	i32 flags,
	i32 file_descriptor,
	isize offset
);

extern i32 std_posix_syscall_munmap(void* address, usize length);

extern i32 std_posix_syscall_sysctl(const char* name, u32 name_length, void* old_value, usize old_value_length, void* new_value, usize new_value_length);

#ifdef __cplusplus
}
#endif

#endif
#endif

