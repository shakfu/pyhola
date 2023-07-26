#include <string.h>
#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <libdialect/graphs.h>
#include <libdialect/hola.h>
#include <libdialect/io.h>
#include <libavoid/geomtypes.h>

#include <nanobind/stl/shared_ptr.h>

namespace nb = nanobind;

using namespace nb::literals;

using namespace dialect;


NB_MODULE(pyhola_nano, m)
{
    m.doc() = "pyhola_nano module: an adaptagrams library wrapper using nanobind.";
    m.attr("__version__") = "0.0.1";

    //------------------------------------------------------------------------
    // libdialect/io.h

    m.def("graph_from_tglf_file", &buildGraphFromTglfFile, "build graph from .tglf file");

    //------------------------------------------------------------------------
    // libdialect/hola.h

    m.def("do_hola", [](Graph &g, const HolaOpts &h) { doHOLA(g, h); }, "layout a graph with options");
    m.def("do_hola", static_cast<void (*)(Graph &g, const HolaOpts &h, Logger *l)>(&doHOLA), "layout a graph with options");
    m.def("do_hola", static_cast<void (*)(Graph &g)>(&doHOLA), "layout a graph");

    //------------------------------------------------------------------------
    // libdialect/graphs.h

    nb::class_<Graph>(m, "Graph", "The Graph class represents graphs consisting of nodes and edges.")
        .def(nb::init<>())
        .def_rw("debug_output_path", &Graph::m_debugOutputPath)
        .def_rw("projection_debug_level", &Graph::m_projectionDebugLevel)
        .def("add_node", nb::overload_cast<Node_SP, bool>(&Graph::addNode), "node"_a, "take_ownership"_a = true, "add node")
        .def("add_node", nb::overload_cast<double, double>(&Graph::addNode), "add node (w, h)")
        .def("add_node", nb::overload_cast<double, double, double, double>(&Graph::addNode), "add node (x, y, w, h)")
        .def("add_edge", nb::overload_cast<Edge_SP, bool>(&Graph::addEdge), "edge"_a, "take_ownership"_a = true, "add edge from edge instance")
        .def("add_edge", nb::overload_cast<Node_SP, Node_SP>(&Graph::addEdge), "add edge from (src node, dst node)")

        .def("get_node", &Graph::getNode, "get node from id")
        .def("get_nodemap", &Graph::getNodeLookup, "get map of nodes by id")
        .def("to_tglf", &Graph::writeTglf, "returns tglf string", "use_external_ids"_a = false)
        .def("to_svg", &Graph::writeSvg, "returns svg string", "use_external_ids"_a = false)
        // .def("assign", &Graph::operator=, "Copy-assignment operator.", nb::return_value_policy::automatic, nb::arg("other"))
        .def("get_max_degree", &Graph::getMaxDegree, "Reports the maximum degree of any Node in this Graph.")
        .def("has_node", &Graph::hasNode, "Returns true if this Graph has a Node of the given ID.", nb::arg("id"))
        .def("has_edge", &Graph::hasEdge, "Returns true if this Graph has an Edge of the given ID.", nb::arg("id"))
        .def("sever_edge", &Graph::severEdge, "Sever an Edge in this Graph.", nb::arg("edge"))
        .def("sever_node", &Graph::severNode, "Sever all the Edges incident to a Node in this Graph.", nb::arg("node"))
        .def("remove_node", &Graph::removeNode, "Remove a Node from this Graph.", nb::arg("node"))
        .def("get_num_nodes", &Graph::getNumNodes, "Say how many Nodes there are in this Graph.")
        .def("get_num_edges", &Graph::getNumEdges, "Say how many Edges there are in this Graph.")
        .def("is_empty", &Graph::isEmpty, "Say whether the Graph is empty, meaning that it has no Nodes.")
        .def("is_tree", &Graph::isTree, "Say whether the Graph is a tree.")
        ;

    nb::class_<Graph_SP>(m, "Graph_SP")
        .def(nb::init<std::shared_ptr<Graph>>())
        ;

    nb::class_<Node>(m, "Node")
        .def_static("allocate", nb::overload_cast<double, double>(&Node::allocate), "allocate width, height", "w"_a, "h"_a)
        .def_static("allocate", nb::overload_cast<double, double, double, double>(&Node::allocate), "allocate width, height", "x"_a, "y"_a, "w"_a, "h"_a)
        .def_prop_ro("id", &Node::id, "Access the unique ID of a given instance.")

        .def("get_dimensions", &Node::getDimensions, "return width and height")
        .def("get_degree", &Node::getDegree, "Check the degree (number of incident Edges) of the Node.")
        .def("set_centre", &Node::setCentre, "set centre pos", "cx"_a, "cy"_a = 10)
        .def("translate", &Node::translate, "Update the position of the node, by adding to its centre coordinates.", "dx"_a, "dy"_a)

        .def("set_graph", &Node::setGraph, "Tell the Node which Graph it belongs to.", nb::arg("graph"))
        // .def("get_graph", &Node::getGraph, "Access the Graph to which the Node belongs.", nb::return_value_policy::automatic)
        .def("remove_edge", &Node::removeEdge, "Remove an incident Edge.", nb::arg("edge"))
        .def("copy_geometry", &Node::copyGeometry, "Give this Node the same coordinates and dimensions as another.", nb::arg("other"))
        // .def("copy_other_ghost_properties", &Node::copyOtherGhostProperties, "Copy other properties of Ghost nodes besides geometry.", nb::arg("other"))
        .def("get_bounding_box", &Node::getBoundingBox, "Get the bounding box for this Node.\n\nC++: Node::getBoundingBox() const --> struct BoundingBox")
        .def("get_boundary_compass_pt", &Node::getBoundaryCompassPt, "Get the point on the boundary of this Node in a given direction from its centre.", nb::arg("dir"))
        .def("set_centre", &Node::setCentre, "Set the position of the node, by setting its centre coordinates.", nb::arg("cx"), nb::arg("cy"))
        .def("get_centre", &Node::getCentre, "Get the centre coordinates of the node.")
        .def("set_external_id", &Node::setExternalId, "Set an externally-determined ID -- useful for TGLF and others.", nb::arg("id"))
        .def("get_external_id", &Node::getExternalId, "Get the external ID.")
        .def("set_dims", &Node::setDims, "Set the dimensions of the node.", nb::arg("w"), nb::arg("h"))
        .def("set_bounding_box", &Node::setBoundingBox, "Set the bounding box of the node which sets both the dimensions and the centre point.", nb::arg("x"), nb::arg("X"), nb::arg("y"), nb::arg("Y"))
        .def("add_padding", &Node::addPadding, "Add padding to the node's dimensions.", nb::arg("dw"), nb::arg("dh"))
        .def("update_posn_from_rect", &Node::updatePosnFromRect, "Update the position of this Node to equal that of the given Rectangle.", nb::arg("r"))
        .def("update_x_coord_from_rect", &Node::updateXCoordFromRect, "Update the x-coordinate of this Node to equal that of the given Rectangle.", nb::arg("r"))
        .def("update_y_coord_from_rect", &Node::updateYCoordFromRect, "Update the y-coordinate of this Node to equal that of the given Rectangle.", nb::arg("r"))
        .def("make_libavoid_polygon", &Node::makeLibavoidPolygon, "Build and return a Polygon to represent this Node in libavoid.")
        .def("is_root", &Node::isRoot, "Check whether this Node has been marked as being a root -- useful when working with trees, and can be safely ignored when working with other sorts of graphs.")
        .def("set_is_root", &Node::setIsRoot, "Say whether this Node is a root.", nb::arg("isRoot"))
        // .def("lies_opposite_segment", [](Node &o, const struct LineSegment &a0) -> bool { return o.liesOppositeSegment(a0); }, "", nb::arg("seg"))
        // .def("lies_opposite_segment", (bool (Node::*)(const struct LineSegment &, bool)) &Node::liesOppositeSegment, "Check whether this Node lies opposite a LineSegment.", nb::arg("seg"), nb::arg("openInterval"))
        ;

    nb::class_<Node_SP>(m, "Node_SP")
        .def(nb::init<std::shared_ptr<Node>>())
        ;


    nb::class_<Edge>(m, "Edge")
        // .def( nb::init( [](Edge const &o){ return new Edge(o); } ) )
        .def("allocate", &Edge::allocate, "allocate edge from src node to dst node")
        .def("id", &Edge::id, "Access the unique ID of this instance.")
        .def("set_graph", &Edge::setGraph, "Tell the Edge which Graph it belongs to.", nb::arg("graph"))
        .def("sever", &Edge::sever, "Sever this Edge, i.e. remove it from the Nodes to which it is attached.")
        .def("get_bounding_box", &Edge::getBoundingBox, "Get the bounding box for the edge, including its end points and route points.")
        .def("add_route_point", &Edge::addRoutePoint, "Add a point to the route.", nb::arg("x"), nb::arg("y"))
        .def("has_bend_nodes", &Edge::hasBendNodes, "Check whether this Edge has any bend nodes.")
        .def("rotate_90cw", &Edge::rotate90cw, "Rotate the connector route 90 degrees clockwise.")
        .def("rotate_90acw", &Edge::rotate90acw, "Rotate the connector route 90 degrees anticlockwise.")
        .def("rotate_180", &Edge::rotate180, "Rotate the connector route 180 degrees")
        .def("translate", &Edge::translate, "Translate the connector route by a given amount in each dimension.", nb::arg("dx"), nb::arg("dy"))
        .def("clear_route_and_bends", &Edge::clearRouteAndBends, "Clear the connector route and drop all bend nodes.")
        .def("build_route_from_bends", &Edge::buildRouteFromBends, "Build a connector route based on the bend nodes.")
        ;

    nb::class_<Edge_SP>(m, "Edge_SP")
        .def(nb::init<std::shared_ptr<Edge>>())
        ;

    nb::class_<BoundingBox>(m, "BoundingBox", "A bounding box, given by the extreme coordinates.")
        .def( nb::init<double, double, double, double>(), nb::arg("x"), nb::arg("X"), nb::arg("y"), nb::arg("Y") )
        .def(nb::init<>())
        .def_rw("x", &BoundingBox::x)
        .def_rw("X", &BoundingBox::X)
        .def_rw("y", &BoundingBox::y)
        .def_rw("Y", &BoundingBox::Y)
        .def("repr", (std::string (BoundingBox::*)() const) &BoundingBox::repr, "Write a simple representation of the bounding box.")
        .def("w", (double (BoundingBox::*)() const) &BoundingBox::w, "Get the width of the box.")
        .def("h", (double (BoundingBox::*)() const) &BoundingBox::h, "Get the height of the box.")
        .def("get_interval", (struct std::pair<double, double> (BoundingBox::*)(enum vpsc::Dim)) &BoundingBox::getInterval, "Get the interval in a given dimension. The desired interval's variable dimension; thus, X if you want the box's horizontal interval, Y if you want its vertical interval.", nb::arg("dim"))
        .def("centre", (class Avoid::Point (BoundingBox::*)() const) &BoundingBox::centre, "Get the centre of the box.")
        .def("perimeter", (double (BoundingBox::*)() const) &BoundingBox::perimeter, "Compute the perimeter of the box.")
        ;


    nb::class_<HolaOpts>(m, "HolaOpts", "options for hola")
        .def(nb::init<>())
        .def_rw("defaultTreeGrowthDir", &HolaOpts::defaultTreeGrowthDir)
        .def_rw("treeLayoutScalar_nodeSep", &HolaOpts::treeLayoutScalar_nodeSep)
        .def_rw("treeLayoutScalar_rankSep", &HolaOpts::treeLayoutScalar_rankSep)
        .def_rw("preferConvexTrees", &HolaOpts::preferConvexTrees)
        .def_rw("peeledTreeRouting", &HolaOpts::peeledTreeRouting)
        .def_rw("wholeTreeRouting", &HolaOpts::wholeTreeRouting)
        .def_rw("orthoHubAvoidFlatTriangles", &HolaOpts::orthoHubAvoidFlatTriangles)
        .def_rw("useACAforLinks", &HolaOpts::useACAforLinks)
        .def_rw("routingScalar_crossingPenalty", &HolaOpts::routingScalar_crossingPenalty)
        .def_rw("routingScalar_segmentPenalty", &HolaOpts::routingScalar_segmentPenalty)
        .def_rw("treePlacement_favourCardinal", &HolaOpts::treePlacement_favourCardinal)
        .def_rw("treePlacement_favourExternal", &HolaOpts::treePlacement_favourExternal)
        .def_rw("treePlacement_favourIsolation", &HolaOpts::treePlacement_favourIsolation)
        .def_rw("expansion_doCostlierDimensionFirst", &HolaOpts::expansion_doCostlierDimensionFirst)
        .def_rw("expansion_estimateMethod", &HolaOpts::expansion_estimateMethod)
        .def_rw("do_near_align", &HolaOpts::do_near_align)
        .def_rw("align_reps", &HolaOpts::align_reps)
        .def_rw("nearAlignScalar_kinkWidth", &HolaOpts::nearAlignScalar_kinkWidth)
        .def_rw("nearAlignScalar_scope", &HolaOpts::nearAlignScalar_scope)
        .def_rw("nodePaddingScalar", &HolaOpts::nodePaddingScalar)
        .def_rw("preferredAspectRatio", &HolaOpts::preferredAspectRatio)
        .def_rw("preferredTreeGrowthDir", &HolaOpts::preferredTreeGrowthDir)
        .def_rw("putUlcAtOrigin", &HolaOpts::putUlcAtOrigin)
        ;

    //------------------------------------------------------------------------
    // libavoid/geomtypes.h

    nb::class_<Avoid::Point>(m, "Point")
        .def( nb::init<const double, const double>(), nb::arg("x"), nb::arg("y") )
        .def(nb::init<>())
        .def_ro("x", &Avoid::Point::x)
        .def_ro("y", &Avoid::Point::y)
        ;
}
