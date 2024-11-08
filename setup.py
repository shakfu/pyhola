# Available at setup time due to pyproject.toml
import os
import platform
from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup

__version__ = "0.1.0"


PLATFORM = platform.system()

CWD = os.getcwd()

if not os.path.exists("thirdparty/adaptagrams"):
    os.system("scripts/setup.sh")

ADAPTAGRAMS_INCLUDE = os.path.join(CWD, "thirdparty/adaptagrams/include")
ADAPTAGRAMS_LIBS_DIR = os.path.join(CWD, "thirdparty/adaptagrams/lib")

DEFINE_MACROS = []
EXTRA_COMPILE_ARGS = ['-std=c++14']
EXTRA_LINK_ARGS = []

EXTRA_OBJECTS = [
    f'{ADAPTAGRAMS_LIBS_DIR}/libavoid.a',
    f'{ADAPTAGRAMS_LIBS_DIR}/libcola.a',
    f'{ADAPTAGRAMS_LIBS_DIR}/libdialect.a',
    f'{ADAPTAGRAMS_LIBS_DIR}/libproject.a',
    f'{ADAPTAGRAMS_LIBS_DIR}/libtopology.a',
    f'{ADAPTAGRAMS_LIBS_DIR}/libvpsc.a',
]
INCLUDE_DIRS = [
    "src/pyhola",
    ADAPTAGRAMS_INCLUDE,
]
LIBRARY_DIRS = [
    ADAPTAGRAMS_LIBS_DIR,
]
LIBRARIES = []


if PLATFORM == 'Darwin':
    EXTRA_LINK_ARGS.append('-mmacosx-version-min=15.0')


ext_modules = [
    Pybind11Extension(
        name="pyhola",
        sources=["src/pyhola.cpp"],
        define_macros=[("VERSION_INFO", __version__)],
        include_dirs=INCLUDE_DIRS,
        libraries=LIBRARIES,
        library_dirs=LIBRARY_DIRS,
        extra_objects=EXTRA_OBJECTS,
        extra_compile_args=EXTRA_COMPILE_ARGS,
        extra_link_args=EXTRA_LINK_ARGS,
        cxx_std=14,
        language="c++",
    ),
]

setup(
    name="pyhola",
    version=__version__,
    author="Shakeeb Alireza",
    author_email="sa@example.org",
    url="https://github.com/shakfu/pyhola",
    description="A pybind11 wrapper to adaptagrams HOLA: Human-like Orthogonal Layout Algorithm.",
    long_description="",
    ext_modules=ext_modules,
    zip_safe=False,
    python_requires=">=3.7",
)
