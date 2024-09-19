# pyhola

This project wraps a key part of the [adaptagrams](https://github.com/mjwybrow/adaptagrams) c++ library using [pybind11](https://github.com/pybind/pybind11). Specifically, it wraps the HOLA algorithm (Human-like Orthogonal Layout Algorithm) in `libdialect`: a very promising graph layout algorithm which approximates to what a human would do if the given the task to layout a graph. Further details are provided in [this](https://skieffer.info/publications/kieffer2016hola.pdf) paper.

The HOLA algorithm is part of the [libdialect](http://www.adaptagrams.org/documentation/libdialect.html) module of the adaptagrams library.

Note that the the adaptagrams library provides a comprehensive swig-based python wrapper which is likely useful for most use-cases.

This project provide a targeted pybind11 wrapper for the HOLA algorithm, and tries to provide a pythonic api along the way. There is also a [nanobind](https://github.com/wjakob/nanobind) wrapper in development which is still not functional.

`pyhola` and the adaptagrams swig-based python wrapper have been used successfully in the [py2max project](https://github.com/shakfu/py2max), to provide auto-layout capability of programmatically generated Max patches.

To build pyhola:


```
make
```

## Status

- HOLA algorithm in `pyhola_pybind11` build is functional  other builds, `pyhola_bind` (generated) is not functional.


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

You can compile your own more recent libs and just drop them into this project.


## Future Directions:

- [ ] Wrap all of adaptagrms libs: after manually wrapping the core HOLA algorithm, there is an ongoing effort to use [binder](https://github.com/RosettaCommons/binder) (see below) to wrap the whole of the adaptagrams libs automatically.  While a decent portion is wrapped, there are still a few errors which remain. (see `bind/remaining-errors.diff`)


## Binder Usage

To use [binder](https://github.com/RosettaCommons/binder), a tool to autogenerate [pybind11](https://github.com/pybind/pybind11) bindings for c++ code, build it and use the resulting binary to generate code which can then be manually fixed and tweaked to supplement the current `pyhola` library.

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

Thanks to [Wenzel Jakob](https://github.com/wjakob), developer of pybind11 and nanobind for making this project possible.

This thin pybind11 wrapper is placed in the public domain.
