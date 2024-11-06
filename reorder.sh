#!/bin/bash

echo $(ls | grep -v reorder.sh | grep -v README) >> temp
