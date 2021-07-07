#include <string.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "libdialect/graphs.h"
#include "libdialect/hola.h"
#include "libdialect/io.h"

namespace py = pybind11;

using namespace dialect;
using namespace pybind11::literals;

template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;


PYBIND11_MODULE(pyhola, m)
{
    m.doc() = "pyhola module: an adaptagrams library wrapper using pybind11.";
    m.attr("__version__") = "0.0.1";

    m.def("graph_from_tglf_file", &buildGraphFromTglfFile, "build graph from .tglf file");

    m.def("do_hola", static_cast<void (*)(Graph &g, const HolaOpts &h, Logger *l)>(&doHOLA), "layout a graph with options");
    m.def("do_hola", static_cast<void (*)(Graph &g)>(&doHOLA), "layout a graph");

    py::class_<Graph, Graph_SP>(m, "Graph")
        .def(pybind11::init([]() { return new Graph(); }))
        .def(pybind11::init([](Graph const &o) { return new Graph(o); }))
        .def_readwrite("debug_output_path", &Graph::m_debugOutputPath)
        .def_readwrite("projection_debug_level", &Graph::m_projectionDebugLevel)
        .def("add_node", overload_cast_<Node_SP, bool>()(&Graph::addNode), "add node", "node"_a, "take_ownership"_a = true)
        .def("add_node", overload_cast_<double, double>()(&Graph::addNode), "add node (w, h)")
        .def("add_node", overload_cast_<double, double, double, double>()(&Graph::addNode), "add node (x, y, w, h)")
        .def("add_edge", overload_cast_<Edge_SP, bool>()(&Graph::addEdge), "add edge from edge instance", "edge"_a, "take_ownership"_a = true)
        .def("add_edge", overload_cast_<Node_SP, Node_SP>()(&Graph::addEdge), "add edge from (src node, dst node)")
        .def("get_node", &Graph::getNode, "get node from id")
        .def("get_nodemap", &Graph::getNodeLookup, "get map of nodes by id")
        .def("to_tglf", &Graph::writeTglf, "returns tglf string", "use_external_ids"_a = false)
        .def("to_svg", &Graph::writeSvg, "returns svg string", "use_external_ids"_a = false)
        .def("assign", &Graph::operator=, "Copy-assignment operator.", py::return_value_policy::automatic, py::arg("other"))
        .def("get_max_degree", &Graph::getMaxDegree, "Reports the maximum degree of any Node in this Graph.")
        .def("has_node", &Graph::hasNode, "Returns true if this Graph has a Node of the given ID.", py::arg("id"))
        .def("has_edge", &Graph::hasEdge, "Returns true if this Graph has an Edge of the given ID.", py::arg("id"))
        .def("sever_edge", &Graph::severEdge, "Sever an Edge in this Graph.", py::arg("edge"))
        .def("sever_node", &Graph::severNode, "Sever all the Edges incident to a Node in this Graph.", py::arg("node"))
        .def("remove_node", &Graph::removeNode, "Remove a Node from this Graph.", py::arg("node"))
        .def("sever_remove_node", (void (Graph::*)(const class Node &)) &Graph::severAndRemoveNode, "Convenience method to completely remove a Node from the Graph.", py::arg("node"))
        .def("sever_remove_node", (void (Graph::*)(unsigned int)) &Graph::severAndRemoveNode, "Convenience method to completely remove a Node from the Graph.", py::arg("nodeID"))
        .def("get_num_nodes", &Graph::getNumNodes, "Say how many Nodes there are in this Graph.")
        .def("get_num_edges", &Graph::getNumEdges, "Say how many Edges there are in this Graph.")
        .def("is_empty", &Graph::isEmpty, "Say whether the Graph is empty, meaning that it has no Nodes.")
        .def("is_tree", &Graph::isTree, "Say whether the Graph is a tree.")
        .def("compute_avg_node_dim", &Graph::computeAvgNodeDim, "Compute the average of all heights and widths of Nodes in this Graph.")
        .def("get_iel", &Graph::getIEL, "Read the ideal edge length of this Graph.")
        .def("recompute_iel", &Graph::recomputeIEL, "Recompute, store, and return the Graph's ideal edge length.")
        .def("rotate_90cw", [](Graph &o) -> void { return o.rotate90cw(); },"")
        .def("rotate_90cw", (void (Graph::*)(struct ColaOptions *)) &Graph::rotate90cw, "Rotate the layout and the constraints 90 degrees clockwise.", py::arg("opts"))
        .def("rotate_90acw", [](Graph &o) -> void { return o.rotate90acw(); }, "")
        .def("rotate_90acw", (void (Graph::*)(struct ColaOptions *)) &Graph::rotate90acw, "Rotate the layout and the constraints 90 degrees anticlockwise.", py::arg("opts"))
        .def("rotate_180", (void (Graph::*)()) &Graph::rotate180, "Rotate the layout and the constraints 180 degrees.")
        .def("translate", &Graph::translate, "Translate the entire layout by a given amount in each dimension.", py::arg("dx"), py::arg("dy"))
        .def("put_in_base_position", &Graph::putInBasePosition, "Put the Graph into a basic position useful for making unit test inputs.")
        .def("destress", (void (Graph::*)(const struct ColaOptions &)) &Graph::destress, "Reduce stress via libcola's gradient-descent procedures.", py::arg("opts"))
        .def("destress", (void (Graph::*)()) & Graph::destress, "Convenience method to destress with default options.")
        .def("solidify_aligned_edges", &Graph::solidifyAlignedEdges, "Add Nodes to represent aligned Edges in one dimension, constraining them to stay aligned.", py::arg("dim"), py::arg("opts"))
        .def("make_feasible", &Graph::makeFeasible, "Make feasible. This means that, among those constraints that offer alternatives, we look for satisfiable alternatives in order of increasing cost (cost = separation violation).", py::arg("opts"))
        .def("project", [](Graph &o, const struct ColaOptions &a0, enum vpsc::Dim const &a1) -> int { return o.project(a0, a1); }, "", py::arg("opts"), py::arg("dim"))
        .def("project", (int (Graph::*)(const struct ColaOptions &, enum vpsc::Dim, int)) &Graph::project, "Project onto cola constraints.", py::arg("opts"), py::arg("dim"), py::arg("accept"))
        .def("apply_proj_seq", [](Graph &o, const struct ColaOptions &a0, class ProjSeq &a1) -> bool { return o.applyProjSeq(a0, a1); }, "", py::arg("opts"), py::arg("ps"))
        .def("apply_proj_seq", (bool (Graph::*)(const struct ColaOptions &, class ProjSeq &, int)) & Graph::applyProjSeq, "Attempt to apply the projections given by a ProjSeq object.", py::arg("opts"), py::arg("ps"), py::arg("accept"))
        .def("update_nodes_from_rects", [](Graph &o) -> void { return o.updateNodesFromRects(); }, "")
        .def("update_nodes_from_rects", [](Graph &o, bool const &a0) -> void { return o.updateNodesFromRects(a0); }, "", py::arg("xAxis"))
        .def("update_nodes_from_rects", (void (Graph::*)(bool, bool)) &Graph::updateNodesFromRects, "For use with various layout actions, this method asks the Graph to update Node positions based on its internal vpsc Rectangles that were used in the layout operation.", py::arg("xAxis"), py::arg("yAxis"))
        .def("update_cola_graph_rep", &Graph::updateColaGraphRep, "Refresh, as needed, the data structures necessary for applying the methods of libcola to this Graph.", py::return_value_policy::automatic)
        .def("build_root_cluster", &Graph::buildRootCluster, "Build a cola::RootCluster based on the node clusters specified in a ColaOptions object.", py::return_value_policy::automatic, py::arg("opts"))
        .def("get_cola_graph_rep", &Graph::getColaGraphRep, "Access the cola graph rep for this Graph.", py::return_value_policy::automatic)
        .def("get_sep_matrix", &Graph::getSepMatrix, "Access the separation matrix for this Graph.", py::return_value_policy::automatic)
        .def("push_node_positions", &Graph::pushNodePositions, "Save node positions on internal stack.")
        .def("pop_node_positions", &Graph::popNodePositions, "Restore node positions from internal stack.")
        .def("set_edge_thickness", &Graph::setEdgeThickness, "Set the edge thickness.", py::arg("t"))
        .def("get_edge_thickness", &Graph::getEdgeThickness, "Get the edge thickness.")
        .def("pad_all_nodes", &Graph::padAllNodes, "Add padding to all ndoes.", py::arg("dw"), py::arg("dh"))
        .def("set_poses_in_corresp_nodes", &Graph::setPosesInCorrespNodes, "Update positions of Nodes in a given Graph to equal those of the corresponding Nodes (same ID) in this Graph.", py::arg("H"))
        .def("set_routes_in_corresp_edges", [](Graph &o, class Graph &a0) -> void { return o.setRoutesInCorrespEdges(a0); }, "", py::arg("H"))
        .def("set_routes_in_corresp_edges", (void (Graph::*)(class Graph &, bool)) &Graph::setRoutesInCorrespEdges, "Update routes of Edges in a given Graph to equal those of the corresponding Edges (same source and target) in this Graph.", py::arg("H"), py::arg("directed"))
        .def("route", &Graph::route, "Do a libavoid connector routing on all Edges in the Graph.    The type of routing you want (orthogonal or polyline).", py::arg("routingType"))
        .def("clear_all_routes", &Graph::clearAllRoutes, "Clear all Edge routes. C++: Graph::clearAllRoutes() --> void")
        .def("build_routes", &Graph::buildRoutes, "Ask all Edges to build their routes based on their bend nodes.")
        .def("add_bendless_subnetwork_to_routing_adapter", &Graph::addBendlessSubnetworkToRoutingAdapter, "Add all Nodes, and all those Edges having no bend nodes within them, to a given routingAdapter.", py::arg("ra"))
        .def("clear_all_constraints", &Graph::clearAllConstraints, "Clear all constraints in this Graph's SepMatrix")
        .def("set_corresponding_constraints", &Graph::setCorrespondingConstraints, "Set corresponding constraints in another Graph.", py::arg("H"))
        ;

    py::class_<Node, Node_SP>(m, "Node")
        .def_static("allocate", overload_cast_<double, double>()(&Node::allocate), "allocate width, height", "w"_a, "h"_a)
        .def_static("allocate", overload_cast_<double, double, double, double>()(&Node::allocate), "allocate width, height", "x"_a, "y"_a, "w"_a, "h"_a)
        .def_property_readonly("id", &Node::id, "Access the unique ID of a given instance.")

        .def("get_dimensions", &Node::getDimensions, "return width and height")
        .def("get_degree", &Node::getDegree, "Check the degree (number of incident Edges) of the Node.")
        .def("set_centre", &Node::setCentre, "set centre pos", "cx"_a, "cy"_a = 10)
        .def("translate", &Node::translate, "adjust centre pos", "dx"_a, "dy"_a)

        .def("set_graph", &Node::setGraph, "Tell the Node which Graph it belongs to.", py::arg("graph"))
        .def("get_graph", &Node::getGraph, "Access the Graph to which the Node belongs.", py::return_value_policy::automatic)
        .def("remove_edge", &Node::removeEdge, "Remove an incident Edge.", py::arg("edge"))
        .def("copy_geometry", &Node::copyGeometry, "Give this Node the same coordinates and dimensions as another.", py::arg("other"))
        .def("copy_other_ghost_properties", &Node::copyOtherGhostProperties, "Copy other properties of Ghost nodes besides geometry.", py::arg("other"))
        .def("get_bounding_box", &Node::getBoundingBox, "Get the bounding box for this Node.\n\nC++: Node::getBoundingBox() const --> struct BoundingBox")
        .def("get_boundary_compass_pt", &Node::getBoundaryCompassPt, "Get the point on the boundary of this Node in a given direction from its centre.", py::arg("dir"))
        .def("set_centre", &Node::setCentre, "Set the position of the node, by setting its centre coordinates.", py::arg("cx"), py::arg("cy"))
        .def("translate", &Node::translate, "Update the position of the node, by adding to its centre coordinates.", py::arg("dx"), py::arg("dy"))
        .def("get_centre", &Node::getCentre, "Get the centre coordinates of the node.")
        .def("set_external_id", &Node::setExternalId, "Set an externally-determined ID -- useful for TGLF and others.", py::arg("id"))
        .def("get_external_id", &Node::getExternalId, "Get the external ID.")
        .def("set_dims", &Node::setDims, "Set the dimensions of the node.", py::arg("w"), py::arg("h"))
        .def("set_bounding_box", &Node::setBoundingBox, "Set the bounding box of the node which sets both the dimensions and the centre point.", py::arg("x"), py::arg("X"), py::arg("y"), py::arg("Y"))
        .def("add_padding", &Node::addPadding, "Add padding to the node's dimensions.", py::arg("dw"), py::arg("dh"))
        .def("update_posn_from_rect", &Node::updatePosnFromRect, "Update the position of this Node to equal that of the given Rectangle.", py::arg("r"))
        .def("update_x_coord_from_rect", &Node::updateXCoordFromRect, "Update the x-coordinate of this Node to equal that of the given Rectangle.", py::arg("r"))
        .def("update_y_coord_from_rect", &Node::updateYCoordFromRect, "Update the y-coordinate of this Node to equal that of the given Rectangle.", py::arg("r"))
        .def("make_libavoid_polygon", &Node::makeLibavoidPolygon, "Build and return a Polygon to represent this Node in libavoid.")
        .def("is_root", &Node::isRoot, "Check whether this Node has been marked as being a root -- useful when working with trees, and can be safely ignored when working with other sorts of graphs.")
        .def("set_is_root", &Node::setIsRoot, "Say whether this Node is a root.", py::arg("isRoot"))
        .def("lies_opposite_segment", [](Node &o, const struct LineSegment &a0) -> bool { return o.liesOppositeSegment(a0); }, "", py::arg("seg"))
        .def("lies_opposite_segment", (bool (Node::*)(const struct LineSegment &, bool)) &Node::liesOppositeSegment, "Check whether this Node lies opposite a LineSegment.", py::arg("seg"), pybind11::arg("openInterval"))
        ;

    py::class_<Edge, Edge_SP>(m, "Edge")
		.def( pybind11::init( [](Edge const &o){ return new Edge(o); } ) )
        .def("allocate", &Edge::allocate, "allocate edge from src node to dst node")
		.def("id", &Edge::id, "Access the unique ID of this instance.")
		.def("set_graph", &Edge::setGraph, "Tell the Edge which Graph it belongs to.", py::arg("graph"))
		.def("sever", &Edge::sever, "Sever this Edge, i.e. remove it from the Nodes to which it is attached.")
		.def("get_bounding_box", &Edge::getBoundingBox, "Get the bounding box for the edge, including its end points and route points.")
		.def("add_route_point", &Edge::addRoutePoint, "Add a point to the route.", py::arg("x"), py::arg("y"))
		.def("has_bend_nodes", &Edge::hasBendNodes, "Check whether this Edge has any bend nodes.")
		.def("rotate_90cw", &Edge::rotate90cw, "Rotate the connector route 90 degrees clockwise.")
		.def("rotate_90acw", &Edge::rotate90acw, "Rotate the connector route 90 degrees anticlockwise.")
		.def("rotate_180", &Edge::rotate180, "Rotate the connector route 180 degrees")
		.def("translate", &Edge::translate, "Translate the connector route by a given amount in each dimension.", py::arg("dx"), py::arg("dy"))
		.def("clear_route_and_bends", &Edge::clearRouteAndBends, "Clear the connector route and drop all bend nodes.")
		.def("build_route_from_bends", &Edge::buildRouteFromBends, "Build a connector route based on the bend nodes.")
        ;
}
