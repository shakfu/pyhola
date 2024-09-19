#include <libdialect/constraints.h>
#include <libdialect/faces.h>
#include <libdialect/graphs.h>
#include <libdialect/logging.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/quadaction.h>
#include <libdialect/routing.h>
#include <libdialect/treeplacement.h>
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <cstdlib>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_libdialect_quadaction(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::Arrangement file:libdialect/quadaction.h line:181
		pybind11::class_<dialect::Arrangement, std::shared_ptr<dialect::Arrangement>> cl(M("dialect"), "Arrangement", "Represents the arrangement of all Nbrs around a centre node.");
		cl.def( pybind11::init<int>(), pybind11::arg("nbrs") );

		cl.def_readwrite("nbrs", &dialect::Arrangement::nbrs);
		cl.def_readwrite("semis", &dialect::Arrangement::semis);
		cl.def_readwrite("quads", &dialect::Arrangement::quads);
		cl.def("vacancy", (int (dialect::Arrangement::*)() const) &dialect::Arrangement::vacancy, "Get the \"vacancy vector\" for this Arrangement\n\n \n  vector of 0's and 1's, where 0 means the corresponding semiaxis\n          is vacant, and 1 means it is occupied\n\nC++: dialect::Arrangement::vacancy() const --> int");
		cl.def("dist", (int (dialect::Arrangement::*)() const) &dialect::Arrangement::dist, "Get the \"distribution vector\" for this Arrangement\n\n \n  vector telling how many Nbrs are in each quadrant\n\nC++: dialect::Arrangement::dist() const --> int");
		cl.def("rDist", (int (dialect::Arrangement::*)() const) &dialect::Arrangement::rDist, "Get the \"reduced distribution vector\" for this Arrangement\n\n \n  vector of 0's, 1's, and 2's telling, respectively, whether there\n          are zero, one, or >= 2 Nbrs are in each quadrant\n\nC++: dialect::Arrangement::rDist() const --> int");
		cl.def("getBasicAssignment", (int (dialect::Arrangement::*)() const) &dialect::Arrangement::getBasicAssignment, "Get the \"basic Assignment\" for this Arrangement.\n\n \n  the Assignment in which no quad actions have been taken, i.e.\n          in which the semiaxees are just as initially defined, and in\n          which the cost is zero.\n\nC++: dialect::Arrangement::getBasicAssignment() const --> int");
		cl.def("getAssignmentForQuadAction", (int (dialect::Arrangement::*)(int) const) &dialect::Arrangement::getAssignmentForQuadAction, "Get the Assignment resulting from a given quad action.\n\n \n  a string of four letters chosen from among\n                     {A, B, C, D}, representing the action to be taken\n                     in each of the four quadrants.\n\n \n  the Assignment resulting from the quad action.\n\nC++: dialect::Arrangement::getAssignmentForQuadAction(int) const --> int", pybind11::arg("quadAction"));
		cl.def("computeNAssignments", (int (dialect::Arrangement::*)(unsigned int) const) &dialect::Arrangement::computeNAssignments, "Compute all possible Assignments in which precisely\n         N semiaxes are occupied, sorted by ascending cost.\n\n \n  the number of semiaxes to be occupied\n\n \n  vector of Assignment_SPs, sorted by ascending cost.\n\nC++: dialect::Arrangement::computeNAssignments(unsigned int) const --> int", pybind11::arg("N"));
		cl.def("computeAllAssignments", (int (dialect::Arrangement::*)() const) &dialect::Arrangement::computeAllAssignments, "Compute all possible Assignments.\n\n \n  vector of Assignment_SPs. The ordering is such that any and\n          all 4-assignments come first, in order of ascending cost,\n          followed by any and all 3-assignments, again in order of\n          ascending cost, then likewise for 2- and 1-assignments.\n\nC++: dialect::Arrangement::computeAllAssignments() const --> int");
	}
	// dialect::RouteProcessing file:libdialect/routing.h line:46
	pybind11::enum_<dialect::RouteProcessing>(M("dialect"), "RouteProcessing", "Control how much processing should be done on connector routes by the RoutingAdapter.")
		.value("NONE", dialect::RouteProcessing::NONE)
		.value("RECORD", dialect::RouteProcessing::RECORD)
		.value("REFINE_AND_RECORD", dialect::RouteProcessing::REFINE_AND_RECORD);

;

	{ // dialect::RoutingAdapter file:libdialect/routing.h line:57
		pybind11::class_<dialect::RoutingAdapter, std::shared_ptr<dialect::RoutingAdapter>> cl(M("dialect"), "RoutingAdapter", "Adapter to easily apply libavoid::Routers to libdialect::Graphs.");
		cl.def( pybind11::init( [](){ return new dialect::RoutingAdapter(); } ) );
		cl.def( pybind11::init<int>(), pybind11::arg("flag") );

		cl.def_readwrite("router", &dialect::RoutingAdapter::router);
		cl.def_readwrite("edges", &dialect::RoutingAdapter::edges);
		cl.def_readwrite("edgeIdToConnRef", &dialect::RoutingAdapter::edgeIdToConnRef);
		cl.def_readwrite("nodeIdToShapeRef", &dialect::RoutingAdapter::nodeIdToShapeRef);
		cl.def("addNodes", (void (dialect::RoutingAdapter::*)(const int &)) &dialect::RoutingAdapter::addNodes, "Add nodes.\n \n\n  The Nodes to be added, given by a NodesById mapping.\n\nC++: dialect::RoutingAdapter::addNodes(const int &) --> void", pybind11::arg("nodes"));
		cl.def("addEdges", [](dialect::RoutingAdapter &o, const int & a0) -> void { return o.addEdges(a0); }, "", pybind11::arg("edges"));
		cl.def("addEdges", (void (dialect::RoutingAdapter::*)(const int &, const int *)) &dialect::RoutingAdapter::addEdges, "Add edges.\n \n\n  The Edges to be added, given by an EdgesById mapping.\n \n\n  Optional specification of the allowed connection directions at the source and\n                      target ends of the Edges. Specifically, an Edge's ID should map to a pair\n                      (srcConnDirs, tgtConnDirs) giving the allowed directions for source and target\n                      respectively. For any Edge whose ID is not present in the mapping, all connection\n                      directions are allowed at both ends.\n\nC++: dialect::RoutingAdapter::addEdges(const int &, const int *) --> void", pybind11::arg("edges"), pybind11::arg("connDirs"));
		cl.def("route", [](dialect::RoutingAdapter &o) -> void { return o.route(); }, "");
		cl.def("route", (void (dialect::RoutingAdapter::*)(enum dialect::RouteProcessing)) &dialect::RoutingAdapter::route, "Do the routing.\n \n\n  Set to the desired level of route processing. Default: routes are\n                        recorded in Edges, without any post-processing.\n \n\n RouteProcessing enum.\n\nC++: dialect::RoutingAdapter::route(enum dialect::RouteProcessing) --> void", pybind11::arg("processing"));
		cl.def("recordRoutes", [](dialect::RoutingAdapter &o) -> void { return o.recordRoutes(); }, "");
		cl.def("recordRoutes", (void (dialect::RoutingAdapter::*)(bool)) &dialect::RoutingAdapter::recordRoutes, "Record the routes in the Edges.\n \n\n  Say whether the routes should be refined before recording.\n\nC++: dialect::RoutingAdapter::recordRoutes(bool) --> void", pybind11::arg("refine"));
	}
	{ // dialect::LeaflessOrthoRouter file:libdialect/routing.h line:102
		pybind11::class_<dialect::LeaflessOrthoRouter, std::shared_ptr<dialect::LeaflessOrthoRouter>> cl(M("dialect"), "LeaflessOrthoRouter", "Does a special orthogonal routing in a graph having no leaves,\n         ensuring that at least two distinct sides of every node are\n         used as connection points. This is useful if we later wish to\n         planarise the layout, since it ensures that no node will become\n         a leaf in that process.");
		cl.def( pybind11::init<int, const struct dialect::HolaOpts &>(), pybind11::arg("G"), pybind11::arg("opts") );

		cl.def_readwrite("recordEachAttempt", &dialect::LeaflessOrthoRouter::recordEachAttempt);
		cl.def_readwrite("routingAttemptTglf", &dialect::LeaflessOrthoRouter::routingAttemptTglf);
		cl.def("route", [](dialect::LeaflessOrthoRouter &o) -> void { return o.route(); }, "");
		cl.def("route", (void (dialect::LeaflessOrthoRouter::*)(struct dialect::Logger *)) &dialect::LeaflessOrthoRouter::route, "Do the routing.\n\nC++: dialect::LeaflessOrthoRouter::route(struct dialect::Logger *) --> void", pybind11::arg("logger"));
		cl.def("setShapeBufferDistanceIELScalar", (void (dialect::LeaflessOrthoRouter::*)(double)) &dialect::LeaflessOrthoRouter::setShapeBufferDistanceIELScalar, "Set the Router's shapeBufferDistance parameter as a scalar multiple of the\n         ideal edge length read from the Graph.\n \n\n  This is provided only as a convenience for testing. In the HOLA algorithm\n           for which this is designed, shapeBufferDistance should always be zero.\n           Positive values there may result in failures to route.\n           HOLA uses its own node padding instead, for this purpose.\n\nC++: dialect::LeaflessOrthoRouter::setShapeBufferDistanceIELScalar(double) --> void", pybind11::arg("a"));
	}
	// dialect::reattachTrees(int, int, struct dialect::HolaOpts, struct dialect::Logger *) file:libdialect/treeplacement.h line:50
	M("dialect").def("reattachTrees", [](int const & a0, int const & a1, struct dialect::HolaOpts const & a2) -> int { return dialect::reattachTrees(a0, a1, a2); }, "", pybind11::arg("core"), pybind11::arg("trees"), pybind11::arg("opts"));
	M("dialect").def("reattachTrees", (int (*)(int, int, struct dialect::HolaOpts, struct dialect::Logger *)) &dialect::reattachTrees, "Given a planar orthogonal core, and the corresponding Trees (as resulting\n         from the peeling process), choose Faces of the core in which to place the\n         Trees, generate constraints to expand those Faces, and insert large Nodes\n         to represent the bounding boxes of the Trees.\n\nC++: dialect::reattachTrees(int, int, struct dialect::HolaOpts, struct dialect::Logger *) --> int", pybind11::arg("core"), pybind11::arg("trees"), pybind11::arg("opts"), pybind11::arg("logger"));

	// dialect::chooseBestPlacement(int, struct dialect::HolaOpts) file:libdialect/treeplacement.h line:53
	M("dialect").def("chooseBestPlacement", (int (*)(int, struct dialect::HolaOpts)) &dialect::chooseBestPlacement, "Choose the best TreePlacement from among a list of alternatives.\n\nC++: dialect::chooseBestPlacement(int, struct dialect::HolaOpts) --> int", pybind11::arg("tps"), pybind11::arg("opts"));

	{ // dialect::TreePlacement file:libdialect/treeplacement.h line:57
		pybind11::class_<dialect::TreePlacement, std::shared_ptr<dialect::TreePlacement>> cl(M("dialect"), "TreePlacement", "A TreePlacement represents a way of placing a tree into the faces of\n a 4-planar, orthogonal layout.");
		cl.def( pybind11::init( [](int const & a0, class dialect::Face & a1, int const & a2, enum dialect::CompassDir const & a3, enum dialect::CardinalDir const & a4){ return new dialect::TreePlacement(a0, a1, a2, a3, a4); } ), "doc" , pybind11::arg("tree"), pybind11::arg("face"), pybind11::arg("faceRoot"), pybind11::arg("dp"), pybind11::arg("dg"));
		cl.def( pybind11::init<int, class dialect::Face &, int, enum dialect::CompassDir, enum dialect::CardinalDir, bool>(), pybind11::arg("tree"), pybind11::arg("face"), pybind11::arg("faceRoot"), pybind11::arg("dp"), pybind11::arg("dg"), pybind11::arg("flip") );

		cl.def_readwrite("m_boxNode", &dialect::TreePlacement::m_boxNode);
		cl.def("getPlacementDir", (enum dialect::CompassDir (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getPlacementDir, "Get the placement direction.\n\nC++: dialect::TreePlacement::getPlacementDir() const --> enum dialect::CompassDir");
		cl.def("getGrowthDir", (enum dialect::CardinalDir (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getGrowthDir, "Get the growth direction.\n\nC++: dialect::TreePlacement::getGrowthDir() const --> enum dialect::CardinalDir");
		cl.def("isExternal", (bool (dialect::TreePlacement::*)() const) &dialect::TreePlacement::isExternal, "Check whether the placement is into the external face.\n\nC++: dialect::TreePlacement::isExternal() const --> bool");
		cl.def("id", (unsigned int (dialect::TreePlacement::*)() const) &dialect::TreePlacement::id, "Get the unique ID of this instance.\n\nC++: dialect::TreePlacement::id() const --> unsigned int");
		cl.def("getNumPotentialNbrs", (unsigned long (dialect::TreePlacement::*)()) &dialect::TreePlacement::getNumPotentialNbrs, "Check the number of \"potential neighbours\" of this tree, if placed\n         according to this placement. This is equal to the number of other\n         root nodes on the relevant Sides to which the root node of this\n         placement belongs.\n\nC++: dialect::TreePlacement::getNumPotentialNbrs() --> unsigned long");
		cl.def("estimateCost", (double (dialect::TreePlacement::*)()) &dialect::TreePlacement::estimateCost, "Estimate the cost of this placement.\n\nC++: dialect::TreePlacement::estimateCost() --> double");
		cl.def("getRootNode", (int (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getRootNode, "Get the Node at which the Tree would be rooted:\n\nC++: dialect::TreePlacement::getRootNode() const --> int");
		cl.def("getFace", (class dialect::Face & (dialect::TreePlacement::*)()) &dialect::TreePlacement::getFace, "Access the Face to which this placement belongs.\n\nC++: dialect::TreePlacement::getFace() --> class dialect::Face &", pybind11::return_value_policy::automatic);
		cl.def("insertTreeNode", [](dialect::TreePlacement &o) -> void { return o.insertTreeNode(); }, "");
		cl.def("insertTreeNode", (void (dialect::TreePlacement::*)(double)) &dialect::TreePlacement::insertTreeNode, "Insert a node representing the Tree into the Face to which this\n         placement belongs.\n \n\n  Optional padding to be added to the tree box.\n \n\n TreePlacement::getTreeBox for interpretation of the padding.\n\nC++: dialect::TreePlacement::insertTreeNode(double) --> void", pybind11::arg("padding"));
		cl.def("toString", (int (dialect::TreePlacement::*)() const) &dialect::TreePlacement::toString, "Get a string representation.\n\nC++: dialect::TreePlacement::toString() const --> int");
		cl.def("buildTreeBox", [](dialect::TreePlacement const &o) -> int { return o.buildTreeBox(); }, "");
		cl.def("buildTreeBox", (int (dialect::TreePlacement::*)(double) const) &dialect::TreePlacement::buildTreeBox, "Determine the size of the tree minus the root node, and the position\n         relative to the root node.\n\n \n  Optionally, you may request padding be added to the /outside/\n                     sides of the box, i.e. all those except the side facing the\n                     root node. For example, for a north-growing tree, the padding\n                     will be added only to the north, east, and west sides.\n                     Recommended value for padding is one quarter of the Graph's\n                     ideal edge length (iel/4.0).\n\n \n  A Node whose dimensions w x h gives the dimensions of the bounding box\n          of the tree, minus the root node, and whose position (x, y) gives the\n          vector from the centre of the root node to the centre of this box.\n\n \n  The dimensions are in respect of the growth direction of this TreePlacement,\n        and the position vector is in respect of its placement direction and flip bit.\n\nC++: dialect::TreePlacement::buildTreeBox(double) const --> int", pybind11::arg("padding"));
		cl.def("recordBoxNode", (void (dialect::TreePlacement::*)(int &)) &dialect::TreePlacement::recordBoxNode, "Record the Node representing the box for the Tree.\n\nC++: dialect::TreePlacement::recordBoxNode(int &) --> void", pybind11::arg("boxNode"));
		cl.def("hasBoxNode", (bool (dialect::TreePlacement::*)()) &dialect::TreePlacement::hasBoxNode, "Check whether this TreePlacement has a box node yet.\n\nC++: dialect::TreePlacement::hasBoxNode() --> bool");
		cl.def("getBoxNode", (int (dialect::TreePlacement::*)()) &dialect::TreePlacement::getBoxNode, "Get the box node.\n\nC++: dialect::TreePlacement::getBoxNode() --> int");
		cl.def("buildBestProjSeq", [](dialect::TreePlacement &o) -> int { return o.buildBestProjSeq(); }, "");
		cl.def("buildBestProjSeq", [](dialect::TreePlacement &o, double const & a0) -> int { return o.buildBestProjSeq(a0); }, "", pybind11::arg("padding"));
		cl.def("buildBestProjSeq", [](dialect::TreePlacement &o, double const & a0, bool const & a1) -> int { return o.buildBestProjSeq(a0, a1); }, "", pybind11::arg("padding"), pybind11::arg("doCostlierDimensionFirst"));
		cl.def("buildBestProjSeq", (int (dialect::TreePlacement::*)(double, bool, enum dialect::ExpansionEstimateMethod)) &dialect::TreePlacement::buildBestProjSeq, "Build the best projection sequence for this tree placement.\n \n\n  Optional padding for the new tree box.\n \n\n  Set true to do the more expensive dimension first,\n             in hopes that this will obviate expansion in the other dimension altogether.\n \n\n  See defn of ExpansionEstimateMethod enum class.\n \n\n  A ProjSeq representing the computed projection sequence.\n\nC++: dialect::TreePlacement::buildBestProjSeq(double, bool, enum dialect::ExpansionEstimateMethod) --> int", pybind11::arg("padding"), pybind11::arg("doCostlierDimensionFirst"), pybind11::arg("estimateMethod"));
		cl.def("somePointOppositeSegment", [](dialect::TreePlacement &o, struct dialect::LineSegment & a0, int & a1) -> bool { return o.somePointOppositeSegment(a0, a1); }, "", pybind11::arg("seg"), pybind11::arg("pt"));
		cl.def("somePointOppositeSegment", [](dialect::TreePlacement &o, struct dialect::LineSegment & a0, int & a1, double const & a2) -> bool { return o.somePointOppositeSegment(a0, a1, a2); }, "", pybind11::arg("seg"), pybind11::arg("pt"), pybind11::arg("padding"));
		cl.def("somePointOppositeSegment", (bool (dialect::TreePlacement::*)(struct dialect::LineSegment &, int &, double, bool)) &dialect::TreePlacement::somePointOppositeSegment, "Compute some point belonging to the tree box and lying opposite a given\n         line segment.\n \n\n  The LineSegment in question.\n \n\n  The point whose coordinates are to be set.\n \n\n  Padding for the tree box.\n \n\n  Set true if you want to use the open interval of the line\n                          segment instead of closed (the default).\n \n\n boolean saying whether the tree box indeed lies opposite the given line segment.\n\n \n  We compute the interval I of the tree box in the dimension parallel to the segment.\n Let J be the interval of the segment -- open if the openInterval argument is true; closed\n otherwise. Let K be the intersection of I and J. If K is empty then we return false.\n Otherwise we pick a value w in K and return a point having w as one of its coordinates and\n a centre coordinate of the tree box as the other coordinate.\n\nC++: dialect::TreePlacement::somePointOppositeSegment(struct dialect::LineSegment &, int &, double, bool) --> bool", pybind11::arg("seg"), pybind11::arg("pt"), pybind11::arg("padding"), pybind11::arg("openInterval"));
		cl.def("applyGeometryToTree", (void (dialect::TreePlacement::*)()) &dialect::TreePlacement::applyGeometryToTree, "Rotate, flip, and translate the tree as necessary to match this placement.\n\nC++: dialect::TreePlacement::applyGeometryToTree() --> void");
		cl.def("insertTreeIntoGraph", (void (dialect::TreePlacement::*)(class dialect::Graph &, int &, int &, int &)) &dialect::TreePlacement::insertTreeIntoGraph, "Insert the tree into a given Graph.\n \n\n  The Graph into which the tree is to be inserted.\n \n\n  A place to record the tree nodes that are constructred.\n \n\n  A place to record the buffer nodes that are constructred.\n \n\n  A place to record the tree edges that are added.\n\nC++: dialect::TreePlacement::insertTreeIntoGraph(class dialect::Graph &, int &, int &, int &) --> void", pybind11::arg("G"), pybind11::arg("treeNodes"), pybind11::arg("bufferNodes"), pybind11::arg("treeEdges"));
		cl.def("size", (unsigned long (dialect::TreePlacement::*)() const) &dialect::TreePlacement::size, "Check the size (i.e. number of nodes in) the Tree.\n\nC++: dialect::TreePlacement::size() const --> unsigned long");
		cl.def("setRootAligns", (void (dialect::TreePlacement::*)(int, int &)) &dialect::TreePlacement::setRootAligns, "Tell the TreePlacement which Nodes are aligned with its root node in a given dimension.\n \n\n  The alignment dimension.\n \n\n  The set of IDs of nodes that are aligned in this dimension with the root node.\n\nC++: dialect::TreePlacement::setRootAligns(int, int &) --> void", pybind11::arg("dim"), pybind11::arg("idSet"));
		cl.def("rootIsAlignedWith", (bool (dialect::TreePlacement::*)(int, unsigned int)) &dialect::TreePlacement::rootIsAlignedWith, "Check whether the root node is aligned with a given node, in a given dimension.\n \n\n  The dimension of interest.\n \n\n  The ID of the node in question.\n\nC++: dialect::TreePlacement::rootIsAlignedWith(int, unsigned int) --> bool", pybind11::arg("dim"), pybind11::arg("id"));
	}
}
