#!/usr/bin/env python3

import os

example = """\

"""

SPACE = ' '*4

# line cleanup funcs
rm_semi = lambda line: line.rstrip(';') if line.endswith(';') else line
rm_cl = lambda line: line.lstrip('cl') if line.startswith('cl.') else line
rm_dialect = lambda line: line.replace('dialect::', '')

rpl_m_dialect = lambda line: line.replace(' cl(M("dialect"),', '(m, ')
rpl_py_class = lambda line: line.replace('pybind11::class_', 'py::class_')

head_transformers = [
    rpl_m_dialect,
    rpl_py_class,
    rm_dialect,
    rm_semi,
]

body_transformers = [
    rm_semi,
    rm_cl,
    rm_dialect,
    rpl_m_dialect,
]

def process(text):
    result = []
    lines =  [line.strip().lstrip() for line in text.splitlines() if line]
    head = lines.pop(0)
    for f in head_transformers:
        head = f(head)
    result.append(head)
    for i in lines:
        for f in body_transformers:
            i = f(i)
        result.append(f"{SPACE}{i}")
    result.append(f'{SPACE};')
    return '\n'.join(result)

print(process(example))
# with open('result.cpp','w') as f:
#     f.write(process(example))

