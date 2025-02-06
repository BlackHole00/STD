@echo off

cl /c /GS- /W4 /Istd\include /Fobuild\stdlib_msvc_amd64_c.obj std\src\_build.c
if %errorlevel% neq 0 (popd; exit /b %errorlevel%)
cl /c /GS- /W4 /Istd\include /Fobuild\stdlib_msvc_amd64_cpp.obj std\src\_build.cpp
if %errorlevel% neq 0 (popd; exit /b %errorlevel%)
cl /c /GS- /W4 /Istd\include /Fobuild\main_msvc_amd64_c.obj main\main.c
if %errorlevel% neq 0 (popd; exit /b %errorlevel%)
cl /c /GS- /W4 /Istd\include /Fobuild\main_msvc_amd64_cpp.obj main\main.cpp
if %errorlevel% neq 0 (popd; exit /b %errorlevel%)

link /ENTRY:_start /SUBSYSTEM:Windows build\stdlib_msvc_amd64_c.obj build\main_msvc_amd64_c.obj /OUT:build\main_msvc_amd64_c.exe
link /ENTRY:_start /SUBSYSTEM:Windows build\stdlib_msvc_amd64_cpp.obj build\main_msvc_amd64_cpp.obj /OUT:build\main_msvc_amd64_cpp.exe

popd

