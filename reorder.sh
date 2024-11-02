#!/bin/bash
# 用于快速重命名全部文件

let i1=1
for file in $(ls | grep -v reorder.sh | grep -v README); do
    [ -f $file ] && mv $file $(printf "%09d" $i1).png && let i1=i1+1
done

let i2=1

for file in $(ls -tr | grep -v reorder.sh | grep -v README); do
    [ -f $file ] && mv $file $(printf "%03d" $i2).png && let i2=i2+1
done

let sum=i1-1;

echo $"All done. $sum photos"

echo $'# Wallpapers

## How to use reorder.sh

### On Windows

- dep: Git Bash

open Git bash and then:

```bash
./reorder.sh
```

### On Linux

```bash
./reorder.sh
```

## Preview\n' > README.md

for file in $(ls | grep -v reorder.sh | grep -v README); do
    echo "$file  " >> README.md
    echo "![$file]($file)" >> README.md
done
