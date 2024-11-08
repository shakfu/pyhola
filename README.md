# pyhola

This project wraps a key part of the [adaptagrams](https://github.com/mjwybrow/adaptagrams) c++ library using [pybind11](https://github.com/pybind/pybind11). Specifically, it wraps the HOLA algorithm (Human-like Orthogonal Layout Algorithm) in `libdialect`: a very promising graph layout algorithm which approximates to what a human would do if the given the task to layout a graph. Further details are provided in [this](https://skieffer.info/publications/kieffer2016hola.pdf) paper.

The HOLA algorithm is part of the [libdialect](http://www.adaptagrams.org/documentation/libdialect.html) module of the adaptagrams library.

Note that the the adaptagrams library provides a comprehensive swig-based python wrapper which is likely useful for most use-cases.

This project provide a targeted pybind11 wrapper for the HOLA algorithm, and tries to provide a pythonic api along the way.

`pyhola` and the adaptagrams swig-based python wrapper have been used successfully in the [py2max project](https://github.com/shakfu/py2max), to provide auto-layout capability of programmatically generated Max patches.


## Status

- The HOLA algorithm in `pyhola` build is functional and can be tested via available tests.


## Building

You will need `pybind11` installed:

```
pip install pybind11
```

There are two ways to build pyhola:

1. Building via setup.py

```sh
make

# or

python3 setup.py build_ext --inplace
```

2. Build via cmake

```sh
make cmake

# or

mkdir -p build && cd build && cmake .. && cmake --build . --config Release
```

In both cases, the [adaptagrams](https://github.com/shakfu/adaptagrams) dependencies will be downloaded and built and installed in a newly created `thirdparty` folder, and these will be used to build `pyhola`, with the resulting compiled extension to be placed in the `src` folder.


To test (requires `pytest`)

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

## Credits and Licensing

All rights reserved to the original respective authors:

```text
Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.
HOLA: Human-like Orthogonal Network Layout. In Visualization and Computer Graphics, IEEE Transactions on, Volume 22, Issue 1, pages 349 - 358. IEEE, 2016. DOI
```

Thanks to [Wenzel Jakob](https://github.com/wjakob), developer of pybind11 and nanobind for making this project possible.

This thin pybind11 wrapper is placed in the public domain.
