import pytest
import sys
import os
from os.path import exists, join
parentdir = os.path.dirname(__file__)

try:
    # assumes pyhola has just been built in the project directory
    sys.path.insert(0, join(os.path.dirname(parentdir), 'build'))
    import pyhola_nano as pyhola
    from pyhola_nano import Graph, Node, Edge, graph_from_tglf_file, do_hola
    HAS_PYHOLA_NANO = True
except ImportError:
    HAS_PYHOLA_NANO = False




def output(g, name):
    os.makedirs('outputs', exist_ok=True)
    tglf = f'outputs/{name}.tglf'
    svg = f'outputs/{name}.svg'
    with open(tglf, 'w') as f:
        f.write(g.to_tglf())
    assert exists(tglf)
    with open(svg, 'w') as f:
        f.write(g.to_svg())
    assert exists(svg)

def get_test_graph():
    return graph_from_tglf_file(os.path.join(parentdir, 'test_graph.tglf'))

@pytest.mark.skipif(not HAS_PYHOLA_NANO, reason="requires pyhola_nano")
def test_graph_from_tglf_file():
    g = get_test_graph()
    assert g.get_num_nodes() == 30
    assert g.get_num_edges() == 33

@pytest.mark.skipif(not HAS_PYHOLA_NANO, reason="requires pyhola_nano")
def test_do_hola():
    g = get_test_graph()
    output(g, 'before')
    do_hola(g)
    output(g, 'after')

@pytest.mark.skipif(not HAS_PYHOLA_NANO, reason="requires pyhola_nano")
def test_graph():
    g = Graph()
    assert g.get_num_nodes() == 0
    assert g.get_num_edges() == 0

@pytest.mark.skipif(not HAS_PYHOLA_NANO, reason="requires pyhola_nano")
def test_node():
    g = Graph()
    n = Node.allocate(10.2, 3.4)
    g.add_node(n)
    d = n.get_dimensions()
    assert d == (10.2, 3.4)
    assert g.get_num_nodes() == 1

@pytest.mark.skipif(not HAS_PYHOLA_NANO, reason="requires pyhola_nano")
def test_edge():
    g = Graph()
    n1 = Node.allocate(3.2, 2.1)
    n2 = Node.allocate(2.1, 1.1)
    n3 = Node.allocate(4.1, 3.1)
    n4 = Node.allocate(3.2, 5.1)
    nodes = [n1,n2,n3,n4]
    for n in nodes:
        g.add_node(n)

    g.add_edge(n1, n2)
    e1 = Edge.allocate(n3, n4)
    g.add_edge(e1)
    assert g.get_num_nodes() == 4
    assert g.get_num_edges() == 2

    assert g.to_tglf()

#    do_hola(g)
