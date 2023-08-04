

.PHONY: all build clean

all: build

build:
	@mkdir -p build && cd build && cmake .. && cmake --build . --config Release

# node:
# 	@g++ -std=c++11 -o node node.cpp


clean:
	@rm -rf build