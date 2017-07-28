#!/bin/sh
files=$(ls -1 *.c)
#gcc -ggdb *.c -L'C:/mingw/include' -L'C:/mingw/lib' -ldumb

echo
echo 'Building all tests⋯'
for f in $files
do
	gcc -ggdb -o "${f%.*}".out $f -L'C:/mingw/include' -L'C:/mingw/lib' -ldumb
done
