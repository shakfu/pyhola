NAME := "pyhola"
# CPPFLAGS += "-Wno-c++11-extensions"
STDVER := "-std=c++14"
PYBIND_INCLUDES := $(shell python3 -m pybind11 --includes)
EXTENSION_SUFFIX := $(shell python3-config --extension-suffix)
PY_INCLUDES := $(shell python3-config --includes)
EXTENSION := $(NAME)$(EXTENSION_SUFFIX)

SYS_CPP_INCLUDE=/Library/Developer/CommandLineTools/usr/include/c++/v1
SYS_C_INCLUDE=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include
PWD=$(shell pwd)

ALL_INCLUDES=all_includes.hpp
CONFIG_FILE=config.txt
NAMESPACE_TO_BIND=dialect
NAMESPACE_TO_SKIP='std'


all: build

build:
	@mkdir -p build && cd build && cmake .. && cmake --build . --config Release

nano: # build with pyhola_nano
	@mkdir -p build && cd build && cmake .. -DBUILD_PYHOLA_NANO=ON && cmake --build . --config Release

bind:
	@mkdir -p bind
	@binder \
		--root-module $(NAME) \
		--prefix $(PWD)/bind \
		--config=$(CONFIG_FILE) \
		--bind $(NAMESPACE_TO_BIND) \
		--skip $(NAMESPACE_TO_SKIP) \
		$(ALL_INCLUDES) \
		-- $(STDVER) \
		-isystem $(SYS_C_INCLUDE) \
		-I/usr/local/include \
		-I$(SYS_C_INCLUDE) \
		-I$(SYS_CPP_INCLUDE) \
		-I$(PWD)/include \
		-DNDEBUG

test:
	@pytest

clean:
	@rm -rf .pytest_cache
	@rm -rf __pycache__
	@rm -rf tests/__pycache__
	@rm -rf outputs
	@rm -rf bind build


.PHONY: all build nano clean regen test


regen: clean bind

