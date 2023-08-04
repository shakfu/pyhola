#include "node.h"

#include <nanobind/nanobind.h>
#include <nanobind/stl/shared_ptr.h>


namespace nb = nanobind;
using namespace nb::literals;


NB_MODULE(node_nano, m) {
    m.doc() = "nanobind node example";

    nb::class_<Node>(m, "Node")
        .def_static("allocate", &Node::allocate, "allocate width, height", "w"_a, "h"_a)
        .def_prop_rw("w", &Node::get_width, &Node::set_width)
        .def_prop_rw("h", &Node::get_height, &Node::set_height)
        ;

    nb::class_<Node_SP>(m, "Node_SP")
        .def(nb::init<std::shared_ptr<Node>>())
        ;
}
