#include <string.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// hola
#include <libdialect/graphs.h>
#include <libdialect/hola.h>
#include <libdialect/io.h>
#include <libdialect/opts.h>

// aca
#include <libdialect/aca.h>

// extras
#include <libdialect/trees.h>

// libavoid::Point
#include <libavoid/geomtypes.h>

// constraints
#include <libdialect/constraints.h>
#include <libcola/compound_constraints.h>


namespace py = pybind11;

using namespace dialect;
using namespace pybind11::literals;

template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;


PYBIND11_MODULE(pyhola, m)
{
    m.doc() = "pyhola module: an adaptagrams library wrapper using pybind11.";
    m.attr("__version__") = "0.0.1";

    //------------------------------------------------------------------------
    // libdialect/graphs.h

    m.def("graph_from_tglf_file", &buildGraphFromTglfFile, "build graph from .tglf file");

    m.def("do_hola", static_cast<void (*)(Graph &g, const HolaOpts &h, Logger *l)>(&doHOLA), "layout a graph with options");
    m.def("do_hola", static_cast<void (*)(Graph &g)>(&doHOLA), "layout a graph");

    py::class_<Graph, Graph_SP>(m, "Graph", "The Graph class represents graphs consisting of nodes and edges.")
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

    py::class_<BoundingBox, std::shared_ptr<BoundingBox>>(m, "BoundingBox", "A bounding box, given by the extreme coordinates.")
        .def( pybind11::init<double, double, double, double>(), pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y") )
        .def( pybind11::init( [](){ return new BoundingBox(); } ) )
        .def( pybind11::init( [](BoundingBox const &o){ return new BoundingBox(o); } ) )
        .def_readwrite("x", &BoundingBox::x)
        .def_readwrite("X", &BoundingBox::X)
        .def_readwrite("y", &BoundingBox::y)
        .def_readwrite("Y", &BoundingBox::Y)
        .def("__iadd__", (struct BoundingBox & (BoundingBox::*)(const struct BoundingBox &)) &BoundingBox::operator+=, "Adding two bounding boxes returns the bounding box of their union.\n\nC++: BoundingBox::operator+=(const struct BoundingBox &) --> struct BoundingBox &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"))
        .def("repr", (std::string (BoundingBox::*)() const) &BoundingBox::repr, "Write a simple representation of the bounding box.\n\nC++: BoundingBox::repr() const --> std::string")
        .def("w", (double (BoundingBox::*)() const) &BoundingBox::w, "Get the width of the box.\n\nC++: BoundingBox::w() const --> double")
        .def("h", (double (BoundingBox::*)() const) &BoundingBox::h, "Get the height of the box.\n\nC++: BoundingBox::h() const --> double")
        .def("getInterval", (struct std::pair<double, double> (BoundingBox::*)(enum vpsc::Dim)) &BoundingBox::getInterval, "Get the interval in a given dimension.\n \n\n  The desired interval's variable dimension; thus, X if you want the box's\n                 horizontal interval, Y if you want its vertical interval.\n\nC++: BoundingBox::getInterval(enum vpsc::Dim) --> struct std::pair<double, double>", pybind11::arg("dim"))
        .def("centre", (class Avoid::Point (BoundingBox::*)() const) &BoundingBox::centre, "Get the centre of the box.\n\nC++: BoundingBox::centre() const --> class Avoid::Point")
        .def("buildSideSegment", (class std::shared_ptr<struct LineSegment> (BoundingBox::*)(enum CardinalDir) const) &BoundingBox::buildSideSegment, "Build a LineSegment representing a side of the box.\n\nC++: BoundingBox::buildSideSegment(enum CardinalDir) const --> class std::shared_ptr<struct LineSegment>", pybind11::arg("side"))
        .def("perimeter", (double (BoundingBox::*)() const) &BoundingBox::perimeter, "Compute the perimeter of the box.\n\nC++: BoundingBox::perimeter() const --> double")
        ;

    py::class_<ColaOptions, std::shared_ptr<ColaOptions>>(m, "ColaOptions", "Provides a simple way to set any or all of the various\n         optional arguments to libcola layout methods.")
        .def( pybind11::init( [](){ return new ColaOptions(); } ) )
        .def( pybind11::init( [](ColaOptions const &o){ return new ColaOptions(o); } ) )
        .def_readwrite("idealEdgeLength", &ColaOptions::idealEdgeLength)
        .def_readwrite("preventOverlaps", &ColaOptions::preventOverlaps)
        .def_readwrite("solidifyAlignedEdges", &ColaOptions::solidifyAlignedEdges)
        .def_readwrite("solidEdgeExemptions", &ColaOptions::solidEdgeExemptions)
        .def_readwrite("xAxis", &ColaOptions::xAxis)
        .def_readwrite("yAxis", &ColaOptions::yAxis)
        .def_readwrite("makeFeasible", &ColaOptions::makeFeasible)
        .def_readwrite("makeFeasible_xBorder", &ColaOptions::makeFeasible_xBorder)
        .def_readwrite("makeFeasible_yBorder", &ColaOptions::makeFeasible_yBorder)
        .def_readwrite("useNeighbourStress", &ColaOptions::useNeighbourStress)
        .def_readwrite("nbrStressIELScalar", &ColaOptions::nbrStressIELScalar)
        .def_readwrite("useMajorization", &ColaOptions::useMajorization)
        .def_readwrite("useScaling", &ColaOptions::useScaling)
        .def_readwrite("ccs", &ColaOptions::ccs)
        .def_readwrite("nodeClusters", &ColaOptions::nodeClusters)
        .def_readwrite("eLengths", &ColaOptions::eLengths)
        ;

    py::class_<ColaGraphRep, std::shared_ptr<ColaGraphRep>>(m, "ColaGraphRep", "Bundles those data structures required in order to represent\n         a Graph in libcola, and to map infomration between the libcola\n         and libdialect representations.")
        .def( pybind11::init( [](ColaGraphRep const &o){ return new ColaGraphRep(o); } ) )
        .def( pybind11::init( [](){ return new ColaGraphRep(); } ) )
        .def_readwrite("rs", &ColaGraphRep::rs)
        .def_readwrite("es", &ColaGraphRep::es)
        .def_readwrite("id2ix", &ColaGraphRep::id2ix)
        .def_readwrite("ix2id", &ColaGraphRep::ix2id)
        .def("assign", (struct ColaGraphRep & (ColaGraphRep::*)(const struct ColaGraphRep &)) &ColaGraphRep::operator=, "C++: ColaGraphRep::operator=(const struct ColaGraphRep &) --> struct ColaGraphRep &", pybind11::return_value_policy::automatic, pybind11::arg(""))
        ;

    py::class_<NodeIdCmp, std::shared_ptr<NodeIdCmp>>(m, "NodeIdCmp", "Useful for set operations on Node lookups.\n \n\n  Thanks to https://stackoverflow.com/a/15579928")
        .def( pybind11::init( [](){ return new NodeIdCmp(); } ) )
        .def("__call__", (bool (NodeIdCmp::*)(unsigned int, const struct std::pair<unsigned int, class std::shared_ptr<class Node> > &) const) &NodeIdCmp::operator(), "C++: NodeIdCmp::operator()(unsigned int, const struct std::pair<unsigned int, class std::shared_ptr<class Node> > &) const --> bool", pybind11::arg("i"), pybind11::arg("p"))
        .def("__call__", (bool (NodeIdCmp::*)(const struct std::pair<unsigned int, class std::shared_ptr<class Node> > &, unsigned int) const) &NodeIdCmp::operator(), "C++: NodeIdCmp::operator()(const struct std::pair<unsigned int, class std::shared_ptr<class Node> > &, unsigned int) const --> bool", pybind11::arg("p"), pybind11::arg("i"))
        ;

    py::class_<HolaOpts, std::shared_ptr<HolaOpts>>(m, "HolaOpts", "")
        .def( pybind11::init( [](){ return new HolaOpts(); } ) )
        .def_readwrite("defaultTreeGrowthDir", &HolaOpts::defaultTreeGrowthDir)
        .def_readwrite("treeLayoutScalar_nodeSep", &HolaOpts::treeLayoutScalar_nodeSep)
        .def_readwrite("treeLayoutScalar_rankSep", &HolaOpts::treeLayoutScalar_rankSep)
        .def_readwrite("preferConvexTrees", &HolaOpts::preferConvexTrees)
        .def_readwrite("peeledTreeRouting", &HolaOpts::peeledTreeRouting)
        .def_readwrite("wholeTreeRouting", &HolaOpts::wholeTreeRouting)
        .def_readwrite("orthoHubAvoidFlatTriangles", &HolaOpts::orthoHubAvoidFlatTriangles)
        .def_readwrite("useACAforLinks", &HolaOpts::useACAforLinks)
        .def_readwrite("routingScalar_crossingPenalty", &HolaOpts::routingScalar_crossingPenalty)
        .def_readwrite("routingScalar_segmentPenalty", &HolaOpts::routingScalar_segmentPenalty)
        .def_readwrite("treePlacement_favourCardinal", &HolaOpts::treePlacement_favourCardinal)
        .def_readwrite("treePlacement_favourExternal", &HolaOpts::treePlacement_favourExternal)
        .def_readwrite("treePlacement_favourIsolation", &HolaOpts::treePlacement_favourIsolation)
        .def_readwrite("expansion_doCostlierDimensionFirst", &HolaOpts::expansion_doCostlierDimensionFirst)
        .def_readwrite("expansion_estimateMethod", &HolaOpts::expansion_estimateMethod)
        .def_readwrite("do_near_align", &HolaOpts::do_near_align)
        .def_readwrite("align_reps", &HolaOpts::align_reps)
        .def_readwrite("nearAlignScalar_kinkWidth", &HolaOpts::nearAlignScalar_kinkWidth)
        .def_readwrite("nearAlignScalar_scope", &HolaOpts::nearAlignScalar_scope)
        .def_readwrite("nodePaddingScalar", &HolaOpts::nodePaddingScalar)
        .def_readwrite("preferredAspectRatio", &HolaOpts::preferredAspectRatio)
        .def_readwrite("preferredTreeGrowthDir", &HolaOpts::preferredTreeGrowthDir)
        .def_readwrite("putUlcAtOrigin", &HolaOpts::putUlcAtOrigin)
        ;


    //------------------------------------------------------------------------
    // libavoid/geomtypes.h
    py::class_<Avoid::Point, std::shared_ptr<Avoid::Point>>(m, "Point")
        .def( pybind11::init<const double, const double>(), pybind11::arg("x"), pybind11::arg("y") )
        .def( pybind11::init( [](){ return new Avoid::Point(); } ) )
        .def_readonly("x", &Avoid::Point::x)
        .def_readonly("y", &Avoid::Point::y)
        ;


    //------------------------------------------------------------------------
    // libdialect/trees.h

    py::class_<Tree, std::shared_ptr<Tree>>(m, "Tree")
        .def( pybind11::init<std::shared_ptr<Graph>, std::shared_ptr<Node>>(), pybind11::arg("G"), pybind11::arg("root") )
        .def( pybind11::init( [](Tree const &o){ return new Tree(o); } ) )
        .def("symmetricLayout", [](Tree &o, enum CardinalDir const & a0, double const & a1, double const & a2) -> void { return o.symmetricLayout(a0, a1, a2); }, "", pybind11::arg("growthDir"), pybind11::arg("nodeSep"), pybind11::arg("rankSep"))
        .def("symmetricLayout", (void (Tree::*)(enum CardinalDir, double, double, bool)) &Tree::symmetricLayout, "Apply the Symmetric Layout algorithm of Manning & Atallah\n             See Manning, Joseph, and Mikhail J. Atallah.\n             \"Fast detection and display of symmetry in trees.\" (1985).\n\n \n  The direction in which the tree should grow.\n \n\n  Minimal gap between nodes on the same rank.\n \n\n  Minimal separation between ranks.\n \n\n  If true, the broadest and deepest subtrees are\n                             placed near the centre; if false, the opposite.\n\nC++: Tree::symmetricLayout(enum CardinalDir, double, double, bool) --> void", pybind11::arg("growthDir"), pybind11::arg("nodeSep"), pybind11::arg("rankSep"), pybind11::arg("convexOrdering"))
        .def("flip", (void (Tree::*)()) &Tree::flip, "Flip the tree's layout over the axis running through the root node\n         and aligned with the growth direction.\n\nC++: Tree::flip() --> void")
        .def("translate", (void (Tree::*)(Avoid::Point)) &Tree::translate, "Translate the tree's layout by a given vector.\n\n \n  The vector by which to translate.\n\nC++: Tree::translate(Avoid::Point) --> void", pybind11::arg("vect"))
        .def("rotate", (void (Tree::*)(enum CardinalDir)) &Tree::rotate, "Rotate the tree's layout to attain a desired growth direction.\n\n \n  The desired growth direction.\n\nC++: Tree::rotate(enum CardinalDir) --> void", pybind11::arg("dg"))
        .def("rotateGrowthDirCW", (void (Tree::*)(unsigned int)) &Tree::rotateGrowthDirCW, "Do not rotate the layout, but simply update the Tree's growth direction by rotating clockwise.\n \n\n  How many quarter turns clockwise to rotate the growth direction.\n\nC++: Tree::rotateGrowthDirCW(unsigned int) --> void", pybind11::arg("quarterTurns"))
        .def("underlyingGraph", (std::shared_ptr<Graph> (Tree::*)() const) &Tree::underlyingGraph, "Access the Tree's underlying Graph.\n\nC++: Tree::underlyingGraph() const --> std::shared_ptr<Graph>")
        .def("getRootNode", (std::shared_ptr<Node> (Tree::*)() const) &Tree::getRootNode, "Access the Tree's root Node.\n\nC++: Tree::getRootNode() const --> std::shared_ptr<Node>")
        .def("repr", (std::string (Tree::*)() const) &Tree::repr, "Write a string representation of this Tree.\n         Useful for debugging.\n\nC++: Tree::repr() const --> std::string")
        .def("getRootNodeID", (unsigned int (Tree::*)() const) &Tree::getRootNodeID, "Check the ID of the root ndoe.\n\nC++: Tree::getRootNodeID() const --> unsigned int")
        .def("isSymmetrical", (bool (Tree::*)() const) &Tree::isSymmetrical, "Check whether the layout is symmetrical.\n\n \n  Just because you have called a Tree's symmetricLayout method, does not\n        mean it acutally got a symmetrical layout! That is only possible if the\n        Tree's structure is in fact symmetrical. This method informs you whether\n        the latter is the case.\n\nC++: Tree::isSymmetrical() const --> bool")
        .def("buildRootlessBox", (std::shared_ptr<Node> (Tree::*)(enum CardinalDir) const) &Tree::buildRootlessBox, "Determine the size of the tree minus the root node, and the position\n         relative to the root node.\n\n \n  Before calling this method, the Tree should have been laid out, so the root\n        node should be centred at (0, 0), and the Tree's growth direction should be set.\n\n \n  The growth direction with respect to which the box should be computed.\n\n \n  A Node whose dimensions w x h gives the dimensions of the bounding box\n          of the tree, minus the root node (but not minus the inter-rank space between\n          the root node and the first rank), and whose position (x, y) gives the\n          vector from the centre of the root node to the centre of this box.\n\nC++: Tree::buildRootlessBox(enum CardinalDir) const --> std::shared_ptr<Node>", pybind11::arg("growthDir"))
        .def("size", (unsigned long (Tree::*)() const) &Tree::size, "Check how many nodes are in the tree.\n\nC++: Tree::size() const --> unsigned long")
        .def("addNetworkToRoutingAdapter", [](Tree &o, struct RoutingAdapter & a0, enum TreeRoutingType const & a1) -> void { return o.addNetworkToRoutingAdapter(a0, a1); }, "", pybind11::arg("ra"), pybind11::arg("trt"))
        .def("addNetworkToRoutingAdapter", (void (Tree::*)(struct RoutingAdapter &, enum TreeRoutingType, std::shared_ptr<Graph>)) &Tree::addNetworkToRoutingAdapter, "Add the nodes and edges of this Tree to a RoutingAdapter.\n         This is useful either for routing just the Tree itself, or for adding the internal part\n         of the tree (i.e. everything except the root node) to another graph where the tree is\n         rooted.\n \n\n  The RoutingAdapter we are to augment.\n \n\n  Which type of routing you want.\n \n\n  The core Graph in the case that this Tree has been peeled off a core, and is\n                  to be reattched.\n \n\n If a core Graph is given, then the root node of the tree will be omitted from the RoutingAdapter.\n\nC++: Tree::addNetworkToRoutingAdapter(struct RoutingAdapter &, enum TreeRoutingType, std::shared_ptr<Graph>) --> void", pybind11::arg("ra"), pybind11::arg("trt"), pybind11::arg("core"))
        .def("addNetwork", (void (Tree::*)(Graph &, std::map<unsigned int, std::shared_ptr<Node>, struct std::less<unsigned int>, std::allocator<struct std::pair<const unsigned int, std::shared_ptr<Node> > > > &, std::map<unsigned int, std::shared_ptr<Edge>, struct std::less<unsigned int>, std::allocator<struct std::pair<const unsigned int, std::shared_ptr<Edge> > > > &)) &Tree::addNetwork, "Add the Nodes and Edges of this tree to a Graph.\n \n\n  The Graph to which the Nodes and Edges are to be added.\n \n\n  A place to record the tree nodes that are constructred.\n \n\n  A place to record the tree edges that are constructred.\n \n\n  Before adding each Node to the given Graph G we check whether G already has a Node that reports\n        the same ID; if it does, we do not add the Node. This is useful so that root nodes are not\n        overwritten when reattaching peeled trees to a core graph.\n\nC++: Tree::addNetwork(Graph &, std::map<unsigned int, std::shared_ptr<Node>, struct std::less<unsigned int>, std::allocator<struct std::pair<const unsigned int, std::shared_ptr<Node> > > > &, std::map<unsigned int, std::shared_ptr<Edge>, struct std::less<unsigned int>, std::allocator<struct std::pair<const unsigned int, std::shared_ptr<Edge> > > > &) --> void", pybind11::arg("G"), pybind11::arg("treeNodes"), pybind11::arg("treeEdges"))
        .def("addConstraints", (void (Tree::*)(Graph &, bool)) &Tree::addConstraints, "Set constraints in a given Graph's SepMatrix in order to maintain the layout of the tree.\n \n\n  The Graph to which the constraints are to be added.\n \n\n  Say whether an alignment constraint should be set between the root node and\n                       a centre node (if present) in the first rank. For example, this should be set\n                       false in the case of a peeled tree being reattached with ordinal placement direction.\n \n\n  The given Graph G must have Nodes matching the IDs of those in this Tree.\n\nC++: Tree::addConstraints(Graph &, bool) --> void", pybind11::arg("G"), pybind11::arg("alignRoot"))
        .def("addBufferNodesAndConstraints", (void (Tree::*)(Graph &, std::map<unsigned int, std::shared_ptr<Node>, struct std::less<unsigned int>, std::allocator<struct std::pair<const unsigned int, std::shared_ptr<Node> > > > &)) &Tree::addBufferNodesAndConstraints, "Add buffer nodes to help keep separation between the nodes of the tree and the remainder of\n         the given graph G. Set constraints to keep the buffer nodes in place.\n \n\n  The Graph to which the Nodes and constraints are to be added.\n \n\n  A place to record the buffer nodes that are constructred.\n \n\n  This Tree's addNetworkAndConstraints should have been called first, for the same Graph G.\n\nC++: Tree::addBufferNodesAndConstraints(class Graph &, class std::map<unsigned int, class std::shared_ptr<class Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class Node> > > > &) --> void", pybind11::arg("G"), pybind11::arg("bufferNodes"))
        ;

    //------------------------------------------------------------------------
    // libdialect/aca.h

    py::class_<ACALayout, std::shared_ptr<ACALayout>>(m, "ACALayout", "Implements the Adaptive Constrained Alignment (ACA) algorithm.\n\n See\n Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.\n \"Incremental grid-like layout using soft and hard constraints.\" In Graph\n Drawing 2013, pp. 448-459. Springer International Publishing, 2013.")
        .def( pybind11::init<class std::shared_ptr<class Graph>>(), pybind11::arg("G") )
        .def( pybind11::init( [](ACALayout const &o){ return new ACALayout(o); } ) )
        .def_readwrite("aStateBeforeChop", &ACALayout::aStateBeforeChop)
        .def("createAlignments", (void (ACALayout::*)()) &ACALayout::createAlignments, "Creates alignments.\n\n This is the main functionality of ACA. This function should be called\n on an existing layout in order to greedily align edges until any further\n alignments would create edge overlaps.\n\n If the graph does not have an initial layout already, then the 'layout'\n function may be called instead.\n\nC++: ACALayout::createAlignments() --> void")
        .def("createOneAlignment", (bool (ACALayout::*)()) &ACALayout::createOneAlignment, "Creates one alignment.\n\n Call this function instead of createAlignments in order to create just\n one alignment and then stop. The return value is true if and only if a\n new alignment was actually created.\n\n Thus, repeatedly calling this function until it returns false achieves\n the exact same result as simply calling createAlignments.\n\nC++: ACALayout::createOneAlignment() --> bool")
        .def("layout", (void (ACALayout::*)()) &ACALayout::layout, "Do an initial stress-minimising layout, and then create alignments.\n\n This is a convenience function which first does a constrained force-directed\n layout of the given graph, and then calls the 'createAlignments' function.\n\nC++: ACALayout::layout() --> void")
        .def("removeOverlaps", (void (ACALayout::*)()) &ACALayout::removeOverlaps, "Do an FD layout with overlap prevention, then stop.\n\nC++: ACALayout::removeOverlaps() --> void")
        .def("layoutWithCurrentConstraints", (void (ACALayout::*)()) &ACALayout::layoutWithCurrentConstraints, "Run layout with current constraints, and with or without overlap\n prevention, as per the current settings.\n\nC++: ACALayout::layoutWithCurrentConstraints() --> void")
        .def("updateGraph", (void (ACALayout::*)()) &ACALayout::updateGraph, "For forward compatibility (i.e. with Graphs), we offer a convenience method\n        to update the Graph (when we have one) with the positions and constraints chosen\n        by this object.\n\nC++: ACALayout::updateGraph() --> void")
        .def("updateSepMatrix", (void (ACALayout::*)()) &ACALayout::updateSepMatrix, "Update the SepMatrix of the Graph on which this ACALayout was built (if any).\n\nC++: ACALayout::updateSepMatrix() --> void")
        .def("updateSepMatrix", (void (ACALayout::*)(class SepMatrix &, const class std::map<unsigned long, unsigned int, struct std::less<unsigned long>, class std::allocator<struct std::pair<const unsigned long, unsigned int> > > &)) &ACALayout::updateSepMatrix, "Update a given SepMatrix with all the ordered alignment constraints generated\n        by this ACA layout.\n\n \n  the SepMatrix to be updated.\n \n\n  a mapping from Rectangle indices back to the IDs of the Nodes they represent.\n\nC++: ACALayout::updateSepMatrix(class SepMatrix &, const class std::map<unsigned long, unsigned int, struct std::less<unsigned long>, class std::allocator<struct std::pair<const unsigned long, unsigned int> > > &) --> void", pybind11::arg("M"), pybind11::arg("ix2id"))
        .def("outputInstanceToSVG", (void (ACALayout::*)(std::string)) &ACALayout::outputInstanceToSVG, "C++: ACALayout::outputInstanceToSVG(std::string) --> void", pybind11::arg("filename"))
        .def("getFDLayout", (class cola::ConstrainedFDLayout * (ACALayout::*)()) &ACALayout::getFDLayout, "C++: ACALayout::getFDLayout() --> class cola::ConstrainedFDLayout *", pybind11::return_value_policy::automatic)
        .def("addBendPointPenalty", (void (ACALayout::*)(bool)) &ACALayout::addBendPointPenalty, "Control whether we avoid making bend points.\n\n We refer to a node of degree 2 as a \"bend point\" when one of its\n edges has been aligned horizontally and the other vertically.\n\n The default value of addBendPointPenalty is true. In this case a penalty\n score is added when choosing the next alignment in order to postpone\n creating bend points until no other choices remain.\n\n If set to false then there is no penalty score to postpone the creation\n of bend points.\n\n When there is both bend point penalty and leaf penalty (see below), then\n bend points will be created before leaf edges are aligned. This can be\n reversed by altering the BP_PENALTY and LEAF_PENALTY constants.\n\nC++: ACALayout::addBendPointPenalty(bool) --> void", pybind11::arg("b"))
        .def("favourLongEdges", (void (ACALayout::*)(bool)) &ACALayout::favourLongEdges, "Prefer long edges instead of ones that are close to aligned.\n\n This defaults to 'false', in which case ACA prefers to align edges that\n are almost aligned already. When set to 'true' it will instead choose\n the longest edges first.\n\nC++: ACALayout::favourLongEdges(bool) --> void", pybind11::arg("b"))
        .def("postponeLeaves", (void (ACALayout::*)(bool)) &ACALayout::postponeLeaves, "Say whether alignment of leaf edges should be saved for last.\n\n The default value is true.\n\nC++: ACALayout::postponeLeaves(bool) --> void", pybind11::arg("b"))
        .def("useNonLeafDegree", (void (ACALayout::*)(bool)) &ACALayout::useNonLeafDegree, "Say whether leaves should be counted when computing node degrees.\n\n The default value is true.\n\n This setting matters only if addBendPointPenalty is set to true.\n In that case, if useNonLeafDegree is also true then the nodes identified\n as potential bend points will be those having exactly 2 /non-leaf/ neighbours.\n\n When there is both leaf penalty and bend point penalty (see above), then\n bend points will be created before leaf edges are aligned. This can be\n reversed by altering the BP_PENALTY and LEAF_PENALTY constants.\n\nC++: ACALayout::useNonLeafDegree(bool) --> void", pybind11::arg("b"))
        .def("allAtOnce", (void (ACALayout::*)(bool)) &ACALayout::allAtOnce, "Say whether alignment choices should alternate with stress\n        minimisation steps.\n\n The default value of allAtOnce is false. In this case, after each new\n alignment is chosen, stress is again minimised before choosing the\n next one.\n\n If you set allAtOnce to true, then all the alignments will be chosen based\n on the initial layout, and then they will all be applied at once.\n\nC++: ACALayout::allAtOnce(bool) --> void", pybind11::arg("b"))
        .def("aggressiveOrdering", (void (ACALayout::*)(bool)) &ACALayout::aggressiveOrdering, "Say whether to consider changing orthogonal ordering of nodes.\n\n The default value is false. In that case, consider a pair of nodes\n u, v where v currently lies to the southeast of u. Then when ACA\n considers aligning u and v it will only consider putting v east or\n south of u; it will not consider reversing their current ordering in\n either dimension.\n\n In the same example, if you set aggressiveOrdering to true, then ACA\n will also consider putting v north and west of u.\n\n In the exceptional case of a node v lying, say, precisely east of a node\n u despite not being constrained to that alignment, then ACA will consider\n placing v east, north, and south of u even with aggressiveOrdering set\n to false. (But it will consider west only with it set to true.)\n\nC++: ACALayout::aggressiveOrdering(bool) --> void", pybind11::arg("b"))
        .def("setAvoidNodeOverlaps", (void (ACALayout::*)(bool)) &ACALayout::setAvoidNodeOverlaps, "Specifies whether non-overlap constraints should be\n         automatically generated between all nodes.\n\n \n     New boolean value for this option.\n\nC++: ACALayout::setAvoidNodeOverlaps(bool) --> void", pybind11::arg("avoidOverlaps"))
        .def("setNodeAliases", (void (ACALayout::*)(class std::map<int, int, struct std::less<int>, class std::allocator<struct std::pair<const int, int> > >)) &ACALayout::setNodeAliases, "Set certain nodes to be used in place of others.\n\n Pass a map m. Then for each computation that involves a node u, we will check\n whether u is a key in m, and if so will use m(u) instead.\n\nC++: ACALayout::setNodeAliases(class std::map<int, int, struct std::less<int>, class std::allocator<struct std::pair<const int, int> > >) --> void", pybind11::arg("aliases"))
        .def("setClusterHierarchy", (void (ACALayout::*)(class cola::RootCluster *)) &ACALayout::setClusterHierarchy, "sets the cluster hierarchy of the underlying FDLayout.\n\nC++: ACALayout::setClusterHierarchy(class cola::RootCluster *) --> void", pybind11::arg("rc"))
        .def("edgeIsAligned", (bool (ACALayout::*)(int) const) &ACALayout::edgeIsAligned, "Check whether an edge is aligned.\n\n Pass the index of the edge. The returned boolean says whether ACA aligned this edge.\n\nC++: ACALayout::edgeIsAligned(int) const --> bool", pybind11::arg("j"))
        .def("nodesAreAligned", (bool (ACALayout::*)(int, int) const) &ACALayout::nodesAreAligned, "C++: ACALayout::nodesAreAligned(int, int) const --> bool", pybind11::arg("i"), pybind11::arg("j"))
        .def("layoutPeriod", (void (ACALayout::*)(unsigned int)) &ACALayout::layoutPeriod, "C++: ACALayout::layoutPeriod(unsigned int) --> void", pybind11::arg("p"))
        .def("doFinalLayout", (void (ACALayout::*)(bool)) &ACALayout::doFinalLayout, "C++: ACALayout::doFinalLayout(bool) --> void", pybind11::arg("b"))
        .def("initOrdAlign", (struct OrderedAlignment * (ACALayout::*)(int, enum ACASepFlag) const) &ACALayout::initOrdAlign, "C++: ACALayout::initOrdAlign(int, enum ACASepFlag) const --> struct OrderedAlignment *", pybind11::return_value_policy::automatic, pybind11::arg("j"), pybind11::arg("sf"))
        .def("initOrdAlign", [](ACALayout const &o, int const & a0, int const & a1, enum ACASepFlag const & a2) -> OrderedAlignment * { return o.initOrdAlign(a0, a1, a2); }, "", pybind11::return_value_policy::automatic, pybind11::arg("s"), pybind11::arg("t"), pybind11::arg("sf"))
        .def("initOrdAlign", (struct OrderedAlignment * (ACALayout::*)(int, int, enum ACASepFlag, int) const) &ACALayout::initOrdAlign, "C++: ACALayout::initOrdAlign(int, int, enum ACASepFlag, int) const --> struct OrderedAlignment *", pybind11::return_value_policy::automatic, pybind11::arg("s"), pybind11::arg("t"), pybind11::arg("sf"), pybind11::arg("edgeIndex"))
        .def("mostRecentOA", (struct OrderedAlignment * (ACALayout::*)()) &ACALayout::mostRecentOA, "C++: ACALayout::mostRecentOA() --> struct OrderedAlignment *", pybind11::return_value_policy::automatic)
        .def("writeAlignmentTable", (std::string (ACALayout::*)() const) &ACALayout::writeAlignmentTable, "C++: ACALayout::writeAlignmentTable() const --> std::string")
        .def("writeStateForNodeIds", (std::string (ACALayout::*)(unsigned int, unsigned int)) &ACALayout::writeStateForNodeIds, "C++: ACALayout::writeStateForNodeIds(unsigned int, unsigned int) --> std::string", pybind11::arg("id1"), pybind11::arg("id2"))
        ;


    py::class_<OrderedAlignment, std::shared_ptr<OrderedAlignment>>(m,  "OrderedAlignment", "")
        .def( pybind11::init( [](){ return new OrderedAlignment(); } ) )
        .def_readwrite("af", &OrderedAlignment::af)
        .def_readwrite("sf", &OrderedAlignment::sf)
        .def_readwrite("dim", &OrderedAlignment::dim)
        .def_readwrite("src", &OrderedAlignment::src)
        .def_readwrite("tgt", &OrderedAlignment::tgt)
        .def_readwrite("offsetSrc", &OrderedAlignment::offsetSrc)
        .def_readwrite("offsetTgt", &OrderedAlignment::offsetTgt)
        .def_readwrite("edgeIndex", &OrderedAlignment::edgeIndex)
        .def_readwrite("penalty", &OrderedAlignment::penalty)
        ;

    m.def("sortOrdAlignsByPenalty", (bool (*)(const struct OrderedAlignment *, const struct OrderedAlignment *)) &sortOrdAlignsByPenalty, "C++: sortOrdAlignsByPenalty(const struct OrderedAlignment *, const struct OrderedAlignment *) --> bool", pybind11::arg("lhs"), pybind11::arg("rhs"));

    py::enum_<ACAFlag>(m, "ACAFlag", py::arithmetic(), "")
        .value("ACAHORIZ", ACAHORIZ)
        .value("ACAVERT", ACAVERT)
        .value("ACADELIB", ACADELIB)
        .value("ACACONN", ACACONN)
        ;

    py::enum_<ACASepFlag>(m, "ACASepFlag", py::arithmetic(), "")
        .value("ACANOSEP", ACANOSEP)
        .value("ACANORTH", ACANORTH)
        .value("ACAEAST", ACAEAST)
        .value("ACASOUTH", ACASOUTH)
        .value("ACAWEST", ACAWEST)
        .value("ACANORTHEAST", ACANORTHEAST)
        .value("ACASOUTHEAST", ACASOUTHEAST)
        .value("ACANORTHWEST", ACANORTHWEST)
        .value("ACASOUTHWEST", ACASOUTHWEST)
        .value("ACANORTHSOUTH", ACANORTHSOUTH)
        .value("ACAEASTWEST", ACAEASTWEST)
        .value("ACANOTNORTH", ACANOTNORTH)
        .value("ACANOTEAST", ACANOTEAST)
        .value("ACANOTSOUTH", ACANOTSOUTH)
        .value("ACANOTWEST", ACANOTWEST)
        .value("ACAALLSEP", ACAALLSEP)
        ;
        
    m.def("negateSepFlag", (enum ACASepFlag (*)(enum ACASepFlag)) &negateSepFlag, "C++: negateSepFlag(enum ACASepFlag) --> enum ACASepFlag", pybind11::arg("sf"));

    m.def("sepToAlignFlag", (enum ACAFlag (*)(enum ACASepFlag)) &sepToAlignFlag, "C++: sepToAlignFlag(enum ACASepFlag) --> enum ACAFlag", pybind11::arg("sf"));

    m.def("perpAlignFlag", (enum ACAFlag (*)(enum ACAFlag)) &perpAlignFlag, "C++: perpAlignFlag(enum ACAFlag) --> enum ACAFlag", pybind11::arg("af"));

    m.def("vectorToSepFlag", (enum ACASepFlag (*)(double, double)) &vectorToSepFlag, "C++: vectorToSepFlag(double, double) --> enum ACASepFlag", pybind11::arg("dx"), pybind11::arg("dy"));

    m.def("propsedSepConflictsWithExistingPosition", (bool (*)(enum ACASepFlag, enum ACASepFlag)) &propsedSepConflictsWithExistingPosition, "C++: propsedSepConflictsWithExistingPosition(enum dialect::ACASepFlag, enum dialect::ACASepFlag) --> bool", pybind11::arg("pro"), pybind11::arg("ex"));


    //------------------------------------------------------------------------
    // libdialect/constraints.h

    struct PyCallBack_dialect_SepMatrix : public dialect::SepMatrix {
        using dialect::SepMatrix::SepMatrix;

        std::string toString() const override {
            pybind11::gil_scoped_acquire gil;
            pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "toString");
            if (overload) {
                auto o = overload.operator()<pybind11::return_value_policy::reference>();
                if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
                    static pybind11::detail::override_caster_t<std::string> caster;
                    return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
                }
                else return pybind11::detail::cast_safe<std::string>(std::move(o));
            }
            return SepMatrix::toString();
        }
        void markAllSubConstraintsAsInactive() override {
            pybind11::gil_scoped_acquire gil;
            pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "markAllSubConstraintsAsInactive");
            if (overload) {
                auto o = overload.operator()<pybind11::return_value_policy::reference>();
                if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
                    static pybind11::detail::override_caster_t<void> caster;
                    return pybind11::detail::cast_ref<void>(std::move(o), caster);
                }
                else return pybind11::detail::cast_safe<void>(std::move(o));
            }
            return SepMatrix::markAllSubConstraintsAsInactive();
        }
        void updatePosition(const enum vpsc::Dim a0) override {
            pybind11::gil_scoped_acquire gil;
            pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "updatePosition");
            if (overload) {
                auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
                if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
                    static pybind11::detail::override_caster_t<void> caster;
                    return pybind11::detail::cast_ref<void>(std::move(o), caster);
                }
                else return pybind11::detail::cast_safe<void>(std::move(o));
            }
            return CompoundConstraint::updatePosition(a0);
        }
        void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
            pybind11::gil_scoped_acquire gil;
            pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "updateVarIDsWithMapping");
            if (overload) {
                auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
                if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
                    static pybind11::detail::override_caster_t<void> caster;
                    return pybind11::detail::cast_ref<void>(std::move(o), caster);
                }
                else return pybind11::detail::cast_safe<void>(std::move(o));
            }
            return CompoundConstraint::updateVarIDsWithMapping(a0, a1);
        }
        bool subConstraintsRemaining() const override {
            pybind11::gil_scoped_acquire gil;
            pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "subConstraintsRemaining");
            if (overload) {
                auto o = overload.operator()<pybind11::return_value_policy::reference>();
                if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
                    static pybind11::detail::override_caster_t<bool> caster;
                    return pybind11::detail::cast_ref<bool>(std::move(o), caster);
                }
                else return pybind11::detail::cast_safe<bool>(std::move(o));
            }
            return CompoundConstraint::subConstraintsRemaining();
        }
        void markCurrSubConstraintAsActive(const bool a0) override {
            pybind11::gil_scoped_acquire gil;
            pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "markCurrSubConstraintAsActive");
            if (overload) {
                auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
                if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
                    static pybind11::detail::override_caster_t<void> caster;
                    return pybind11::detail::cast_ref<void>(std::move(o), caster);
                }
                else return pybind11::detail::cast_safe<void>(std::move(o));
            }
            return CompoundConstraint::markCurrSubConstraintAsActive(a0);
        }
        void printCreationCode(struct __sFILE * a0) const override {
            pybind11::gil_scoped_acquire gil;
            pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "printCreationCode");
            if (overload) {
                auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
                if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
                    static pybind11::detail::override_caster_t<void> caster;
                    return pybind11::detail::cast_ref<void>(std::move(o), caster);
                }
                else return pybind11::detail::cast_safe<void>(std::move(o));
            }
            return CompoundConstraint::printCreationCode(a0);
        }
    };

    py::class_<cola::CompoundConstraint, std::shared_ptr<cola::CompoundConstraint>>(m, "CompoundConstraint", "An abstract base class for all high-level compound constraints.\n\n A compound constraint is a conceptual, diagramming application oriented\n type of constraint, which can be translated into a set of simple\n separation constraints, possibly extra dummy variables, and perhaps\n even some extra terms for the quadratic objective function used\n in the gradient projection solver.")
        .def("updatePosition", (void (cola::CompoundConstraint::*)(const enum vpsc::Dim)) &cola::CompoundConstraint::updatePosition, "Implemented by the compound constraint to send position\n        information back to the interface.\n\n This will be called for each compound constraint once the VPSC \n instance is solved to allow them to pass information such as \n variable values back to the graphical user interface.\n\n \n   The current active dimension.\n\nC++: cola::CompoundConstraint::updatePosition(const enum vpsc::Dim) --> void", pybind11::arg("dim"))
        .def("toString", (std::string (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::CompoundConstraint::toString() const --> std::string")
        .def("dimension", (enum vpsc::Dim (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::dimension, "C++: cola::CompoundConstraint::dimension() const --> enum vpsc::Dim")
        .def("priority", (unsigned int (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::priority, "C++: cola::CompoundConstraint::priority() const --> unsigned int")
        .def("updateVarIDsWithMapping", [](cola::CompoundConstraint &o, const class cola::VariableIDMap & a0) -> void { return o.updateVarIDsWithMapping(a0); }, "", pybind11::arg("idMap"))
        .def("updateVarIDsWithMapping", (void (cola::CompoundConstraint::*)(const class cola::VariableIDMap &, bool)) &cola::CompoundConstraint::updateVarIDsWithMapping, "C++: cola::CompoundConstraint::updateVarIDsWithMapping(const class cola::VariableIDMap &, bool) --> void", pybind11::arg("idMap"), pybind11::arg("forward"))
        .def("markAllSubConstraintsAsInactive", (void (cola::CompoundConstraint::*)()) &cola::CompoundConstraint::markAllSubConstraintsAsInactive, "C++: cola::CompoundConstraint::markAllSubConstraintsAsInactive() --> void")
        .def("subConstraintsRemaining", (bool (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::subConstraintsRemaining, "C++: cola::CompoundConstraint::subConstraintsRemaining() const --> bool")
        .def("markCurrSubConstraintAsActive", (void (cola::CompoundConstraint::*)(const bool)) &cola::CompoundConstraint::markCurrSubConstraintAsActive, "C++: cola::CompoundConstraint::markCurrSubConstraintAsActive(const bool) --> void", pybind11::arg("satisfiable"))
        .def("printCreationCode", (void (cola::CompoundConstraint::*)(struct __sFILE *) const) &cola::CompoundConstraint::printCreationCode, "C++: cola::CompoundConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"))
        .def("shouldCombineSubConstraints", (bool (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::shouldCombineSubConstraints, "C++: cola::CompoundConstraint::shouldCombineSubConstraints() const --> bool")
        .def("assign", (class cola::CompoundConstraint & (cola::CompoundConstraint::*)(const class cola::CompoundConstraint &)) &cola::CompoundConstraint::operator=, "C++: cola::CompoundConstraint::operator=(const class cola::CompoundConstraint &) --> class cola::CompoundConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""))
        ;

    py::class_<SepMatrix, std::shared_ptr<SepMatrix>, PyCallBack_dialect_SepMatrix, cola::CompoundConstraint>(m, "SepMatrix", "")
        .def( pybind11::init<class Graph *>(), pybind11::arg("G") )
        .def( pybind11::init( [](PyCallBack_dialect_SepMatrix const &o){ return new PyCallBack_dialect_SepMatrix(o); } ) )
        .def( pybind11::init( [](SepMatrix const &o){ return new SepMatrix(o); } ) )
        .def("addSep", (void (SepMatrix::*)(unsigned int, unsigned int, enum GapType, enum SepDir, enum SepType, double)) &SepMatrix::addSep, "Add a constraint.\n\n \n   The specified separation is /added/ to any existing constraints\n         between the two nodes. It overwrites anything with which it is\n         in conflict, but leaves everything else intact. For example, if\n         the second node was already constrained to lie UP and to the LEFT\n         of the first, and then a RIGHT sep is added, then the second node\n         will be constrained to lie UP and to the RIGHT of the first.\n\n \n   You cannot /remove/ a constraint using this method. If NONE is passed\n         as the SepType, nothing happens.\n\n \n  The ID of the first node.\n \n\n  The ID of the second node.\n \n\n  The gap type (centre-to-centre, or between opposing boundaries).\n \n\n  The direction of the separation from the first node\n                 to the second node.\n \n\n  The type of the separation.\n \n\n  The size of the separation.\n\nC++: SepMatrix::addSep(unsigned int, unsigned int, enum GapType, enum SepDir, enum SepType, double) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("gt"), pybind11::arg("sd"), pybind11::arg("st"), pybind11::arg("gap"))
        .def("setCardinalOP", (void (SepMatrix::*)(unsigned int, unsigned int, enum CardinalDir)) &SepMatrix::setCardinalOP, "Convenience method, for setting that particular type of cardinal separation that merely\n         prevents overlap in the stated direction.\n \n\n SepMatrix::addSep\n\nC++: SepMatrix::setCardinalOP(unsigned int, unsigned int, enum CardinalDir) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("dir"))
        .def("addFixedRelativeSep", (void (SepMatrix::*)(unsigned int, unsigned int, double, double)) &SepMatrix::addFixedRelativeSep, "Constrain two Nodes to sit at a fixed separation between their centre coordinates.\n\n \n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n \n\n   The desired fixed value for v.x - u.x (centre coordinates)\n \n\n   The desired fixed value for v.y - u.y (centre coordinates)\n\nC++: SepMatrix::addFixedRelativeSep(unsigned int, unsigned int, double, double) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("dx"), pybind11::arg("dy"))
        .def("addFixedRelativeSep", (void (SepMatrix::*)(unsigned int, unsigned int)) &SepMatrix::addFixedRelativeSep, "Constrain two Nodes to sit at their present exact separation.\n\n \n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n\nC++: SepMatrix::addFixedRelativeSep(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"))
        .def("hAlign", (void (SepMatrix::*)(unsigned int, unsigned int)) &SepMatrix::hAlign, "Align a pair of nodes horizontally.\n\nC++: SepMatrix::hAlign(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"))
        .def("vAlign", (void (SepMatrix::*)(unsigned int, unsigned int)) &SepMatrix::vAlign, "Align a pair of nodes vertically.\n\nC++: SepMatrix::vAlign(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"))
        .def("alignByEquatedCoord", (void (SepMatrix::*)(unsigned int, unsigned int, enum vpsc::Dim)) &SepMatrix::alignByEquatedCoord, "Align a pair of nodes by saying which is the coordinate to be equated.\n \n\n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n \n\n  vpsc::Dim naming the coordinate to be equated. Thus XDIM means x-coords will\n                      be equated, giving a vertical alignment; YDIM means y-coords will be equated,\n                      giving a horizontal alignment.\n\nC++: SepMatrix::alignByEquatedCoord(unsigned int, unsigned int, enum vpsc::Dim) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("eqCoord"))
        .def("free", (void (SepMatrix::*)(unsigned int, unsigned int)) &SepMatrix::free, "Free a pair of Nodes; i.e. remove the SepPair for these Nodes\n         completely.\n\nC++: SepMatrix::free(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"))
        .def("clear", (void (SepMatrix::*)()) &SepMatrix::clear, "Clear all constraints.\n\n \n We do not destroy the SepPairs; we merely erase our pointers to them.\n\nC++: SepMatrix::clear() --> void")
        .def("setCorrespondingConstraints", (void (SepMatrix::*)(class SepMatrix &) const) &SepMatrix::setCorrespondingConstraints, "Set corresponding constraints in another SepMatrix.\n\n         This means that for each constraint between nodes of IDs id1 and id2 in this\n         SepMatrix, we set that constraint in the other SepMatrix if and only if its\n         underlying Graph contains Nodes of IDs id1 and id2.\n \n\n  The other SepMatrix.\n\nC++: SepMatrix::setCorrespondingConstraints(class SepMatrix &) const --> void", pybind11::arg("matrix"))
        .def("setSepPair", (void (SepMatrix::*)(unsigned int, unsigned int, class std::shared_ptr<struct SepPair>)) &SepMatrix::setSepPair, "Set a SepPair directly into another SepMatrix.\n \n\n  The primary ID under which the SepPair is to be stored.\n \n\n  The secondary ID under which the SepPair is to be stored.\n \n\n  The SepPair to be stored.\n \n\n  Runtime error if id1 >= id2.\n\nC++: SepMatrix::setSepPair(unsigned int, unsigned int, class std::shared_ptr<struct SepPair>) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("sp"))
        .def("transform", (void (SepMatrix::*)(enum SepTransform)) &SepMatrix::transform, "Apply a transformation to all Nodes.\n\nC++: SepMatrix::transform(enum SepTransform) --> void", pybind11::arg("tf"))
        .def("transformClosedSubset", (void (SepMatrix::*)(enum SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &)) &SepMatrix::transformClosedSubset, "Apply a transformation to a closed subset of all Nodes.\n\n \n  the transformation to be performed\n \n\n  the set of IDs of all Nodes to which the transformation\n                  should be applied. /Both/ Nodes must be in the set.\n \n\n transformOpenSubset\n\nC++: SepMatrix::transformClosedSubset(enum SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &) --> void", pybind11::arg("tf"), pybind11::arg("ids"))
        .def("transformOpenSubset", (void (SepMatrix::*)(enum SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &)) &SepMatrix::transformOpenSubset, "Apply a transformation to an open subset of all Nodes.\n\n \n  the transformation to be performed\n \n\n  the set of IDs of all Nodes to which the transformation\n                  should be applied. /At least one/ Node must be in the set.\n \n\n transformClosedSubset\n\nC++: SepMatrix::transformOpenSubset(enum SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &) --> void", pybind11::arg("tf"), pybind11::arg("ids"))
        .def("removeNode", (void (SepMatrix::*)(unsigned int)) &SepMatrix::removeNode, "Remove all records for the Node of given ID.\n\nC++: SepMatrix::removeNode(unsigned int) --> void", pybind11::arg("id"))
        .def("removeNodes", (void (SepMatrix::*)(const class std::map<unsigned int, class std::shared_ptr<class Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class Node> > > > &)) &SepMatrix::removeNodes, "Remove all records for the given Nodes.\n\nC++: SepMatrix::removeNodes(const class std::map<unsigned int, class std::shared_ptr<class Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class Node> > > > &) --> void", pybind11::arg("nodes"))
        .def("getCardinalDir", (enum CardinalDir (SepMatrix::*)(unsigned int, unsigned int) const) &SepMatrix::getCardinalDir, "Get the cardinal direction of the separation between two Nodes.\n \n\n  The ID of one of the Nodes.\n \n\n  The ID of the other Node.\n \n\n  Runtime exception if this separation is not cardinal.\n \n\n The cardinal direction.\n\nC++: SepMatrix::getCardinalDir(unsigned int, unsigned int) const --> enum CardinalDir", pybind11::arg("id1"), pybind11::arg("id2"))
        .def("getAlignedSets", (void (SepMatrix::*)(class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &, class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &) const) &SepMatrix::getAlignedSets, "Determine which sets of nodes are aligned with one another.\n \n\n  Will be populated with a lookup from Node ID to set of IDs of\n                    all Nodes that are horizontally aligned with that one.\n \n\n  Like hSets, only for vertical alignment.\n\nC++: SepMatrix::getAlignedSets(class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &, class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &) const --> void", pybind11::arg("hSets"), pybind11::arg("vSets"))
        .def("areHAligned", (bool (SepMatrix::*)(unsigned int, unsigned int) const) &SepMatrix::areHAligned, "Check whether two nodes are horizontally aligned.\n\nC++: SepMatrix::areHAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"))
        .def("areVAligned", (bool (SepMatrix::*)(unsigned int, unsigned int) const) &SepMatrix::areVAligned, "Check whether two nodes are vertically aligned.\n\nC++: SepMatrix::areVAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"))
        .def("writeTglf", (std::string (SepMatrix::*)(class std::map<unsigned int, unsigned int, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, unsigned int> > >) const) &SepMatrix::writeTglf, "Write a representation of all constraints in the format of\n         the SEPCO'S section of the TGLF file format.\n \n\n  Mapping from internal Node IDs to external IDs for the TGLF output.\n\nC++: SepMatrix::writeTglf(class std::map<unsigned int, unsigned int, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, unsigned int> > >) const --> std::string", pybind11::arg("id2ext"))
        .def("setGraph", (void (SepMatrix::*)(class Graph *)) &SepMatrix::setGraph, "Set the related Graph.\n\nC++: SepMatrix::setGraph(class Graph *) --> void", pybind11::arg("G"))
        .def("getGraph", (class Graph * (SepMatrix::*)()) &SepMatrix::getGraph, "Get the Graph.\n\nC++: SepMatrix::getGraph() --> class Graph *", pybind11::return_value_policy::automatic)
        .def("roundGapsUpward", (void (SepMatrix::*)()) &SepMatrix::roundGapsUpward, "Round gaps up to next largest integer. Useful if desiring to move all nodes to\n         integer coordaintes.\n\nC++: SepMatrix::roundGapsUpward() --> void")
        .def("setExtraBdryGap", (void (SepMatrix::*)(double)) &SepMatrix::setExtraBdryGap, "Set a global value to be added onto the gap value for all GapType::BDRY constraints.\n\nC++: SepMatrix::setExtraBdryGap(double) --> void", pybind11::arg("extraBdryGap"))
        .def("getExtraBdryGap", (double (SepMatrix::*)() const) &SepMatrix::getExtraBdryGap, "C++: SepMatrix::getExtraBdryGap() const --> double")
        .def("toString", (std::string (SepMatrix::*)() const) &SepMatrix::toString, "C++: SepMatrix::toString() const --> std::string")
        .def("markAllSubConstraintsAsInactive", (void (SepMatrix::*)()) &SepMatrix::markAllSubConstraintsAsInactive, "C++: SepMatrix::markAllSubConstraintsAsInactive() --> void")
        .def("assign", (class SepMatrix & (SepMatrix::*)(const class SepMatrix &)) &SepMatrix::operator=, "C++: SepMatrix::operator=(const class SepMatrix &) --> class SepMatrix &", pybind11::return_value_policy::automatic, pybind11::arg(""))
        ;

}
