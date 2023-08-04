#include "node.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace py::literals;

PYBIND11_MODULE(node_pybind, m) {
    m.doc() = "pybind11 node example";

    py::class_<Node, Node_SP>(m, "Node")
        .def_static("allocate", &Node::allocate,  "allocate width, height", "w"_a, "h"_a)
        .def_property("w", &Node::get_width, &Node::set_width)
        .def_property("h", &Node::get_height, &Node::set_height)
        ;
}
