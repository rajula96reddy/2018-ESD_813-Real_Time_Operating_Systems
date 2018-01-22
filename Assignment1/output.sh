#!/bin/bash
gcc test.c
./a.out $1
python Graph.py
