"""

recursively converts

    #include "sub/foo.h"   -> #include <sub/foo.h>

    also

    #include "sub/foo.hpp" -> #include <sub/foo.hpp>




"""
import os
import re
import glob
import argparse
import shutil

pattern = re.compile(r'^#include \"(.+)\"')

SUFFIXES = ['.h', '.hpp']

def convert_to_braces(line):
    m = pattern.match(line)
    if m:
        return f'#include <{m.group(1)}>\n'
    raise ValueError

def convert_headers_to_braces_by_suffix(path, suffix='.h'):
    print(f"convert for suffix {suffix}")
    includes = glob.glob(f"{path}/**/*{suffix}")
    for include in includes:
        print(include)
        with open(include) as f:
            lines = f.readlines()
        _result = []
        for line in lines:
            if line.startswith("#include "):
                if line.endswith('"\n'):
                    line = line.strip()
                    converted = convert_to_braces(line)
                    _result.append(converted)
                    print('\t', line, '->', converted.strip())
                    continue

            _result.append(line)
        with open(include, 'w') as g:
            g.writelines(_result)
        print()

def convert_headers_to_braces(path):
    for suffix in SUFFIXES:
        convert_headers_to_braces_by_suffix(path, suffix)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Convert headers to point braces (backups swill be made).')
    parser.add_argument('path', help='path to include directory')
    args = parser.parse_args()
    if args.path:
        shutil.copytree(args.path, f'{args.path}__BACKUP')
        convert_headers_to_braces(args.path)

