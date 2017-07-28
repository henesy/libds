#!/bin/bash
# Local libs for multi-user systems may be stored in $HOME/*/*

files=$(ls -1 *.c)
#gcc -ggdb *.c -L/usr/include -L/usr/lib -ldumb

echo
echo 'Cleaning all tests⋯'
./clean.sh

echo
echo 'Building all tests⋯'
for f in $files
do
        gcc -ggdb -o "${f%.*}".out $f -I $HOME/include -L $HOME/lib -ldumb
done

echo
echo 'Testing all tests⋯'
files=$(ls -1 *.out)
for f in $files
do
	./$f
done

