#!/bin/bash

echo "" > temp.txt

for file_name in $(ls -tr | grep 'png');
do
	echo "$file_name" >> temp.txt
done

eval "g++ -std=c++2a main.cpp" # todo: use Makefile and make command to do this

for file_name in $(ls -tr | grep 'a' | grep -v '.cpp');
do
	eval "./$file_name"
done
