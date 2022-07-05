import os
from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension

os.environ['LDFLAGS'] = " ".join([
    # "-framework CoreServices",
    "-framework CoreFoundation",
    # "-framework AudioUnit",
    # "-framework AudioToolbox",
    # "-framework CoreAudio",
])

os.environ['CPPFLAGS'] = " ".join([
     "-std=c++14",
])

os.environ['CC'] = " ".join([
     "clang++",
])



DEFINE_MACROS = [
    ('PD', 1),
    ('HAVE_UNISTD_H', 1),
    ('HAVE_LIBDL', 1),
    ('USEAPI_DUMMY', 1),
    ('LIBPD_EXTRA', 1),
    # ('PDINSTANCE', 1),   # compile with multi-instance support
    # ('PDTHREADS', 1),    # compile with per-thread storage for global variables, required for multi-instance support
    # ('PD_FLOATSIZE', 1), # set the float precision, 32 (default) or 64, ex. `PD_FLOATSIZE=64`
]

INCLUDE_DIRS = [
    "include",
    "/usr/local/include",
    "../libpd_wrapper",
    "../libpd_wrapper/util",
    "../pure-data/src",
    # "../pure-data/portaudio/portaudio/include",
    # "../pure-data/portaudio/portaudio/src/common",
]

LIBRARIES = [
    'm',
    'dl',
    'pthread',
    # 'portaudio', # requires portaudio to be installed system-wide
]

LIBRARY_DIRS = [
    '/usr/local/lib',
    '../libs',
]

EXTRA_OBJECTS = [
    '../libs/libpd.a',
    # '../libs/libportaudio.a',
]

# SOURCES = sorted(
#     list(glob("bind/*.cpp")) +
#     ['bind/std/vector.cpp']
# )

SOURCES = sorted(glob("bind/*.cpp"))

LIBPD_EXTENSION = Pybind11Extension("libpd",
    SOURCES,  # Sort source files for reproducibility
    define_macros = DEFINE_MACROS,
    include_dirs = INCLUDE_DIRS,
    libraries = LIBRARIES,
    library_dirs = LIBRARY_DIRS,
    extra_objects = EXTRA_OBJECTS,
)



setup(
    name="pd in pybind11", 
    ext_modules=[LIBPD_EXTENSION],
)


