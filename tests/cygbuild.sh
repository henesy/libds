#!/bin/sh
files=$(ls -1 *.c)
#gcc -ggdb *.c -L'C:/cygwin64/usr/include' -L'C:/cygwin64/usr/x86_64-pc-cygwin/lib' -ldumb

echo
echo 'Building all tests⋯'
for f in $files
do
	gcc -ggdb -o "${f%.*}".out $f -L'C:/cygwin64/usr/include' -L'C:/cygwin64/usr/x86_64-pc-cygwin/lib' -ldumb
done
