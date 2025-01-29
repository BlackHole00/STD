#!/bin/sh

set -e

if test -z "$CC"; then
	CC=clang
fi
if test -z "$CPPC"; then
	CPPC=clang++
fi
if test -z "$LD"; then
	LD=ld
fi
if test -z "$AS"; then
	AS=as
fi

BUILD_ARGS="-Wall -Wextra -Wpedantic -g -ansi -static -ffreestanding -nodefaultlibs -fno-builtin -nostdlib -Wno-main-return-type  -Istd/include -fno-stack-protector"
BUILD_ARGS_XX="-Wall -Wextra -Wpedantic -std=c++98 -g -static -ffreestanding -nodefaultlibs -nostdinc++ -fno-builtin -nostdlib -Wno-main-return-type  -Istd/include -fno-stack-protector"

echo "Assembling _build.s"
$AS -g std/src/_build.s -o build/stdlib_asm.o

echo "Compiling _build.c"
$CC $BUILD_ARGS -c std/src/_build.c -o build/stdlib_c.o

echo "Compiling _build.cpp"
$CPPC $BUILD_ARGS_XX -c std/src/_build.cpp -o build/stdlib_cpp.o

echo "Compiling main"
$CC $BUILD_ARGS -Istd/include -c main/main.c -o build/main.o
$CPPC $BUILD_ARGS_XX -Istd/include -c main/main.cpp -o build/main_cpp.o

echo "Linking"
$LD -e __start -o build/main build/main.o build/stdlib_c.o build/stdlib_asm.o
$LD -e __start -o build/mainpp build/main_cpp.o build/stdlib_cpp.o build/stdlib_asm.o

if [[ "$(uname)" == "Darwin" ]]; then
	echo "Signing execuitable"
	codesign -s - -v -f --entitlements build/debug.plist build/main
	codesign -s - -v -f --entitlements build/debug.plist build/mainpp
fi

