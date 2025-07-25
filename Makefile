ADAPTAGRAMS := thirdparty/adaptagrams/lib/libdialect.a

.PHONY: all build test clean swig_python

all: build

$(ADAPTAGRAMS):
	@scripts/setup.sh

cmake: $(ADAPTAGRAMS)
	@mkdir -p build && cd build && cmake .. && cmake --build . --config Release

build:
	python3 setup.py build_ext --inplace

swig_python: $(ADAPTAGRAMS)
	@cd build/adaptagrams && make python

test:
	@pytest


clean:
	@rm -rf .pytest_cache
	@rm -rf __pycache__ tests/__pycache__
	@rm -rf outputs build thirdparty
