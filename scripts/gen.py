#!/usr/bin/env python3

import os
import sys

from typing import Optional

try:
    import litgen
except ImportError:
    print("litgen not installed, run scripts/setup_litgen.sh to install it into a .venv")
    sys.exit(0)

class Generator:
    def __init__(self, name: str, output_dir: str, headers: list[str], options: Optional[litgen.LitgenOptions] = None):
        self.name = name
        self.headers = headers
        self.output_dir = output_dir
        self.options = options if options else litgen.LitgenOptions()
        self.results = {}

    def process(self):
        self.analyze()
        self.generate()

    def analyze(self):
        for header_path in self.headers:
            with open(header_path) as f:
                cpp_code = f.read()
                generated_code = litgen.generate_code(self.options, cpp_code)
                self.results[header_path] = generated_code

    def generate(self):
        if not self.results:
            raise RuntimeError(".analyze() must be run before .generate()")
        self.write_wrapper_cpp()
        self.write_stub_py()

    def write_wrapper_cpp(self):
        assert self.results, "cannot write before code is analyzed."
        os.makedirs(self.output_dir, exist_ok=True)
        outfile_cpp = os.path.join(self.output_dir, f"{self.name}_wrap.cpp")
        s = ""
        for key, gen in self.results.items():
            s += f"// {key}"
            s += gen.pydef_code
            s += "\n\n"
            s += gen.glue_code
            s += "\n\n"
            s += "//" + "-" * 79
            s += "\n\n"
        with open(outfile_cpp, 'w') as f:
            f.write(s)

    def write_stub_py(self):
        assert self.results, "cannot write before code is analyzed."
        os.makedirs(self.output_dir, exist_ok=True)
        outfile_py = os.path.join(self.output_dir, f"{self.name}_stub.py")
        s = ""
        for key, gen in self.results.items():
            s += f"# {key}"
            s += gen.stub_code
            s += "\n\n"
            s += "#" + "-" * 79
            s += "\n\n"

        with open(outfile_py, 'w') as f:
            f.write(s)

if __name__ == '__main__':
    ADAPTAGRAMS="thirdparty/adaptagrams/include"


    HEADERS = [os.path.join(ADAPTAGRAMS, h) for h in [
        "libdialect/graphs.h",
        "libdialect/hola.h",
        "libdialect/io.h",
        "libdialect/opts.h",
        "libdialect/aca.h",
        "libdialect/trees.h",
        "libavoid/geomtypes.h",
        "libdialect/constraints.h",
        "libcola/compound_constraints.h",
        "libcola/cola.h",
    ]]


    # Instantiate some options
    OPTIONS = litgen.LitgenOptions()
    OPTIONS.python_strip_empty_comment_lines = True
    OPTIONS.python_run_black_formatter = True
    OPTIONS.namespaces_root = [
        "dialect",
    ]

    gen = Generator('hola', 'build/gen', headers=HEADERS, options=OPTIONS)
    gen.process()
