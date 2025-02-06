#!/bin/sh
# set -e

if test -z "$TCC"; then
	TCC=tcc
fi
if test -z "$LINK"; then
	LINK=ld
fi

as --target=aarch64-unknown-linux-gnu -c std/src/syscalls_arm64_darwin.s -o build/stdlib_tcc_arm64_s.o
$TCC -g -bt -gdwarf -nostdlib -Istd/include -DSTD_PLATFORM_DARWIN=1 -c std/src/_build.c -o build/stdlib_tcc_arm64_c.o
$TCC -g -bt -gdwarf -nostdlib -Istd/include -DSTD_PLATFORM_DARWIN=1 -c main/main.c -o build/main_tcc_arm64_c.o

objconv -fmacho64 build/stdlib_tcc_arm64_s.o build/stdlib_tcc_arm64_s_macho.o
objconv -fmacho64 build/stdlib_tcc_arm64_c.o build/stdlib_tcc_arm64_c_macho.o
objconv -fmacho64 build/main_tcc_arm64_c.o build/main_tcc_arm64_c_macho.o
$LINK -o build/main_tcc_arm64 build/main_tcc_arm64_c_macho.o build/stdlib_tcc_arm64_c_macho.o build/stdlib_tcc_arm64_s_macho.o

