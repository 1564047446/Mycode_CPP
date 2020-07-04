#!/bin/bash

for (( i = 0; i < 100; i++ )); do
    python test.py
    echo "hello world"
    g++ 快速排序非递归.cpp -o dd
    ./dd < input > output2
    #echo "hello world"
    flag=$(diff output2 output | wc -l)
    if [[ $flag > 0 ]]; then
        echo "$i : Wrong Answer"
        #exit
    else 
        echo "$i : Accept"
    fi
done
