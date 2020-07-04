#!/usr/bin/env python
# coding=utf-8

import random

fin = open("input", "w")
fout = open("output", "w")

fin.write("100\n")
arr = []
for i in xrange(0, 100):
    arr.append(random.randint(0, 1000))

for x in arr:
    fin.write(str(x) + "\n")
arr.sort()

for x in arr:
    fout.write(str(x) + "\n")
