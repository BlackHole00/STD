#!/bin/sh

set -e

if test -z "$CC"; then
	CC=clang
fi
if test -z "$CPPC"; then
	CPPC=clang++
fi
if test -z "$LINK"; then
	LINK=ld
fi
if test -z "$AS"; then
	AS=as
fi

BUILD_ARGS="-Wall -Wextra -Wpedantic -g -ansi -static -ffreestanding -nodefaultlibs -fno-builtin -nostdlib -Wno-main-return-type  -Istd/include -fno-stack-protector"
BUILD_ARGS_XX="-Wall -Wextra -Wpedantic -std=c++98 -g -static -ffreestanding -nodefaultlibs -nostdinc++ -fno-builtin -nostdlib -Wno-main-return-type  -Istd/include -fno-stack-protector"

echo "Assembling _build.s"
$AS -g std/src/_build.s -o build/stdlib_gnu_arm64_s.o

echo "Compiling _build.c"
$CC $BUILD_ARGS -c std/src/_build.c -o build/stdlib_gnu_arm64_c.o

echo "Compiling _build.cpp"
$CPPC $BUILD_ARGS_XX -c std/src/_build.cpp -o build/stdlib_gnu_arm64_cpp.o

echo "Compiling main"
$CC $BUILD_ARGS -Istd/include -c main/main.c -o build/main_gnu_arm64_c.o
$CPPC $BUILD_ARGS_XX -Istd/include -c main/main.cpp -o build/main_gnu_arm64_cpp.o

echo "Linking"
$LINK -e __start -o build/main_gnu_arm64_c build/main_gnu_arm64_c.o build/stdlib_gnu_arm64_c.o build/stdlib_gnu_arm64_s.o
$LINK -e __start -o build/main_gnu_arm64_cpp build/main_gnu_arm64_cpp.o build/stdlib_gnu_arm64_cpp.o build/stdlib_gnu_arm64_s.o

if [[ "$(uname)" == "Darwin" ]]; then
	echo "Signing execuitable"
	codesign -s - -v -f --entitlements build/debug.plist build/main_gnu_arm64_c
	codesign -s - -v -f --entitlements build/debug.plist build/main_gnu_arm64_cpp
fi

