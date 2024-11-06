#!/bin/bash

for file_name in $(ls -tr | grep 'png');
do
	echo $file_name >> temp.txt
done
