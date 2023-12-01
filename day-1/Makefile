CVERSION := c++20
CC := g++

all: build/part1.out build/part2.out

build/part1.out: src/part1.cpp build/
	${CC} -o build/part1.out src/part1.cpp

build/part2.out: src/part2.cpp build/
	${CC} -o build/part2.out src/part2.cpp

build/:
	mkdir build
