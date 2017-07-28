#!/bin/sh
files=$(ls -1 *.c)
#gcc -ggdb *.c -L/usr/include -L/usr/lib -ldumb

echo
echo 'Building all tests⋯'
for f in $files
do
	gcc -ggdb -o "${f%.*}".out $f -L/usr/include -L/usr/lib -ldumb
done
