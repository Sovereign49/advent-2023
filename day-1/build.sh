#!/bin/bash
CFLAGS=-Wall
mkdir -p build
g++ $CFLAGS -o build/part1.out src/part1.cpp
g++ $CFLAGS -o build/part2.out src/part2.cpp
echo "Build Finished"
