# pyhola

This repo wraps a small part of the [adaptagrams](https://github.com/mjwybrow/adaptagrams) c++ library using [pybind11](https://github.com/pybind/pybind11). Specifically, it wraps the HOLA algorithm (Human-like Orthogonal Layout Algorithm), a very promising graph layout algorithm which approximates to what a human would do. It is explained in [this](https://skieffer.info/publications/kieffer2016hola.pdf) paper.

The HOLA algorithm is part of the [libdialect](http://www.adaptagrams.org/documentation/libdialect.html) module of the adaptagrams library.

The [old python project](https://github.com/skieffer/hola) for hola may also be useful for reference.


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


## Credits and Licensing

All rights reserved to the original respective authors:

>>Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.
HOLA: Human-like Orthogonal Network Layout. In Visualization and Computer Graphics, IEEE Transactions on, Volume 22, Issue 1, pages 349 - 358. IEEE, 2016. DOI

This thin pybind11 wrapper is placed in the public domain.
