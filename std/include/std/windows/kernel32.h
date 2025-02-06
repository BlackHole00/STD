#ifndef _STD_WINDOWSKERNEL32_INCLUDED
#define _STD_WINDOWSKERNEL32_INCLUDED

#include <std/base/constant_symbols.h>
#ifdef STD_PLATFORM_WINDOWS

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

#include <std/windows/types.h>

#pragma comment(lib, "kernel32.Lib")

extern std_LPVOID VirtualAlloc(
	std_LPVOID lpAddress,
	std_SIZE_T dwSize,
	std_DWORD flAllocationType,
	std_DWORD flProtect
);
extern std_BOOL VirtualFree(std_LPVOID lpAddress, std_SIZE_T dwSize, std_DWORD dwFreeType);

extern std_HANDLE GetStdHandle(std_DWORD nStdHandle);
extern std_BOOL SetConsoleOutputCP(std_UINT wCodePageID);
extern std_BOOL SetConsoleCP(std_UINT wCodePageID);
extern std_BOOL WriteConsoleA(
	std_HANDLE hConsoleOutput,
	const std_VOID* lpBuffer,
	std_DWORD nNumberOfCharsToWrite,
	std_LPDWORD lpNumberOfCharsWritten,
	std_LPVOID lpReserved
);

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif
#endif

