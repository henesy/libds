#!/bin/sh

./clean.sh
./build.sh

files=$(ls -1 *.out)

echo
echo 'Running all tests⋯'
for f in $files
do
	./$f
done

echo
echo 'Done.'
echo
