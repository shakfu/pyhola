# pyhola

This repo wraps a small part of the [adaptagrams](https://github.com/mjwybrow/adaptagrams) c++ library using [pybind11](https://github.com/pybind/pybind11). Specifically, it wraps the HOLA algorithm (Human-like Orthogonal Layout Algorithm), a very promising graph layout algorithm which approximates to what a human would do. It is explained in [this](https://skieffer.info/publications/kieffer2016hola.pdf) paper.

The HOLA algorithm is part of the [libdialect](http://www.adaptagrams.org/documentation/libdialect.html) module of the adaptagrams library.

The [old python project](https://github.com/skieffer/hola) for hola may also be useful for reference.

There is a parallel effort to use [binder](https://github.com/RosettaCommons/binder) (see below) to wrap the whole of libdialect automatically. This is ongoing effort.

There is a manually wrapped `pyhola` part which works. Just 

```
make pyhola
```

## Status

The objective is to wrap as much of libdialect as possible

- [x] libdialect/aca.h
- [ ] libdialect/chains.h
- [ ] libdialect/commontypes.h
- [ ] libdialect/constraints.h
- [ ] libdialect/expansion.h
- [ ] libdialect/faces.h
- [x] libdialect/graphs.h
- [x] libdialect/hola.h
- [ ] libdialect/io.h
- [ ] libdialect/libdialect.h
- [ ] libdialect/logging.h
- [ ] libdialect/nearalign.h
- [ ] libdialect/nodeconfig.h
- [x] libdialect/opts.h
- [ ] libdialect/ortho.h
- [ ] libdialect/peeling.h
- [ ] libdialect/planarize.h
- [ ] libdialect/quadaction.h
- [ ] libdialect/treeplacement.h
- [x] libdialect/trees.h
- [ ] libdialect/util.h


## Usage

You will need `pybind11` installed:

```
pip install pybind11
```

Then use the included Makefile to compile the pybind11 extension.

```bash

make

```

to test (requires `pytest`)

```bash

make test

```

or

```bash

pytest

```

to clean the test output:

```bash

make clean

```


The compiled static `lib` files (compiled on 64bit macOS Catalina) and `include` files for the `adaptagrams` library are only included for convenience.


## Implementation

Uses [binder](https://github.com/RosettaCommons/binder), a tool to autogenerate [pybind11](https://github.com/pybind/pybind11) bindings for c++ code. The generated code is then manually fixed and tweaked to create the current library.

To build and test binder

1. `brew install cmake ninja pybind11`

2. build binder using the `build.py` script in the `binder` repo. Ignore the documentation
   since it has dated installation instructions.

3. copy or move the resulting `build` binder directory to `~/.binder` and
   symlink as follows: `~/.binder/bin/binder` to `/usr/local/bin/binder`

4. run `./build.sh` in this directory and a demo python extension should be in the `build` directory



## Credits and Licensing

All rights reserved to the original respective authors:

>>Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.
HOLA: Human-like Orthogonal Network Layout. In Visualization and Computer Graphics, IEEE Transactions on, Volume 22, Issue 1, pages 349 - 358. IEEE, 2016. DOI

This thin pybind11 wrapper is placed in the public domain.
