@echo off

if not exist build ( mkdir build )

cmake -B build
cmake --build build

if not exist bin ( mkdir bin )

copy build\Debug\*.* bin\
