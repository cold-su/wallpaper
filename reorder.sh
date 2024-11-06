#!/bin/bash

echo "" > temp.txt

for file_name in $(ls -tr | grep 'png');
do
	echo "$file_name" >> temp.txt
done
