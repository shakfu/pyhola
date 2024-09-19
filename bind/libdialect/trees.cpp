#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/routing.h>
#include <libdialect/trees.h>
#include <libdialect/util.h>
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

void bind_libdialect_trees(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::Tree file:libdialect/trees.h line:44
		pybind11::class_<dialect::Tree, std::shared_ptr<dialect::Tree>> cl(M("dialect"), "Tree", "");
		cl.def( pybind11::init<int, int>(), pybind11::arg("G"), pybind11::arg("root") );

		cl.def("symmetricLayout", [](dialect::Tree &o, enum dialect::CardinalDir const & a0, double const & a1, double const & a2) -> void { return o.symmetricLayout(a0, a1, a2); }, "", pybind11::arg("growthDir"), pybind11::arg("nodeSep"), pybind11::arg("rankSep"));
		cl.def("symmetricLayout", (void (dialect::Tree::*)(enum dialect::CardinalDir, double, double, bool)) &dialect::Tree::symmetricLayout, "Apply the Symmetric Layout algorithm of Manning & Atallah\n             See Manning, Joseph, and Mikhail J. Atallah.\n             \"Fast detection and display of symmetry in trees.\" (1985).\n\n \n  The direction in which the tree should grow.\n \n\n  Minimal gap between nodes on the same rank.\n \n\n  Minimal separation between ranks.\n \n\n  If true, the broadest and deepest subtrees are\n                             placed near the centre; if false, the opposite.\n\nC++: dialect::Tree::symmetricLayout(enum dialect::CardinalDir, double, double, bool) --> void", pybind11::arg("growthDir"), pybind11::arg("nodeSep"), pybind11::arg("rankSep"), pybind11::arg("convexOrdering"));
		cl.def("flip", (void (dialect::Tree::*)()) &dialect::Tree::flip, "Flip the tree's layout over the axis running through the root node\n         and aligned with the growth direction.\n\nC++: dialect::Tree::flip() --> void");
		cl.def("translate", (void (dialect::Tree::*)(int)) &dialect::Tree::translate, "Translate the tree's layout by a given vector.\n\n \n  The vector by which to translate.\n\nC++: dialect::Tree::translate(int) --> void", pybind11::arg("vect"));
		cl.def("rotate", (void (dialect::Tree::*)(enum dialect::CardinalDir)) &dialect::Tree::rotate, "Rotate the tree's layout to attain a desired growth direction.\n\n \n  The desired growth direction.\n\nC++: dialect::Tree::rotate(enum dialect::CardinalDir) --> void", pybind11::arg("dg"));
		cl.def("rotateGrowthDirCW", (void (dialect::Tree::*)(unsigned int)) &dialect::Tree::rotateGrowthDirCW, "Do not rotate the layout, but simply update the Tree's growth direction by rotating clockwise.\n \n\n  How many quarter turns clockwise to rotate the growth direction.\n\nC++: dialect::Tree::rotateGrowthDirCW(unsigned int) --> void", pybind11::arg("quarterTurns"));
		cl.def("underlyingGraph", (int (dialect::Tree::*)() const) &dialect::Tree::underlyingGraph, "Access the Tree's underlying Graph.\n\nC++: dialect::Tree::underlyingGraph() const --> int");
		cl.def("getRootNode", (int (dialect::Tree::*)() const) &dialect::Tree::getRootNode, "Access the Tree's root Node.\n\nC++: dialect::Tree::getRootNode() const --> int");
		cl.def("repr", (int (dialect::Tree::*)() const) &dialect::Tree::repr, "Write a string representation of this Tree.\n         Useful for debugging.\n\nC++: dialect::Tree::repr() const --> int");
		cl.def("getRootNodeID", (unsigned int (dialect::Tree::*)() const) &dialect::Tree::getRootNodeID, "Check the ID of the root ndoe.\n\nC++: dialect::Tree::getRootNodeID() const --> unsigned int");
		cl.def("isSymmetrical", (bool (dialect::Tree::*)() const) &dialect::Tree::isSymmetrical, "Check whether the layout is symmetrical.\n\n \n  Just because you have called a Tree's symmetricLayout method, does not\n        mean it acutally got a symmetrical layout! That is only possible if the\n        Tree's structure is in fact symmetrical. This method informs you whether\n        the latter is the case.\n\nC++: dialect::Tree::isSymmetrical() const --> bool");
		cl.def("buildRootlessBox", (int (dialect::Tree::*)(enum dialect::CardinalDir) const) &dialect::Tree::buildRootlessBox, "Determine the size of the tree minus the root node, and the position\n         relative to the root node.\n\n \n  Before calling this method, the Tree should have been laid out, so the root\n        node should be centred at (0, 0), and the Tree's growth direction should be set.\n\n \n  The growth direction with respect to which the box should be computed.\n\n \n  A Node whose dimensions w x h gives the dimensions of the bounding box\n          of the tree, minus the root node (but not minus the inter-rank space between\n          the root node and the first rank), and whose position (x, y) gives the\n          vector from the centre of the root node to the centre of this box.\n\nC++: dialect::Tree::buildRootlessBox(enum dialect::CardinalDir) const --> int", pybind11::arg("growthDir"));
		cl.def("size", (unsigned long (dialect::Tree::*)() const) &dialect::Tree::size, "Check how many nodes are in the tree.\n\nC++: dialect::Tree::size() const --> unsigned long");
		cl.def("addNetworkToRoutingAdapter", [](dialect::Tree &o, struct dialect::RoutingAdapter & a0, enum dialect::TreeRoutingType const & a1) -> void { return o.addNetworkToRoutingAdapter(a0, a1); }, "", pybind11::arg("ra"), pybind11::arg("trt"));
		cl.def("addNetworkToRoutingAdapter", (void (dialect::Tree::*)(struct dialect::RoutingAdapter &, enum dialect::TreeRoutingType, int)) &dialect::Tree::addNetworkToRoutingAdapter, "Add the nodes and edges of this Tree to a RoutingAdapter.\n         This is useful either for routing just the Tree itself, or for adding the internal part\n         of the tree (i.e. everything except the root node) to another graph where the tree is\n         rooted.\n \n\n  The RoutingAdapter we are to augment.\n \n\n  Which type of routing you want.\n \n\n  The core Graph in the case that this Tree has been peeled off a core, and is\n                  to be reattched.\n \n\n If a core Graph is given, then the root node of the tree will be omitted from the RoutingAdapter.\n\nC++: dialect::Tree::addNetworkToRoutingAdapter(struct dialect::RoutingAdapter &, enum dialect::TreeRoutingType, int) --> void", pybind11::arg("ra"), pybind11::arg("trt"), pybind11::arg("core"));
		cl.def("addNetwork", (void (dialect::Tree::*)(class dialect::Graph &, int &, int &)) &dialect::Tree::addNetwork, "Add the Nodes and Edges of this tree to a Graph.\n \n\n  The Graph to which the Nodes and Edges are to be added.\n \n\n  A place to record the tree nodes that are constructred.\n \n\n  A place to record the tree edges that are constructred.\n \n\n  Before adding each Node to the given Graph G we check whether G already has a Node that reports\n        the same ID; if it does, we do not add the Node. This is useful so that root nodes are not\n        overwritten when reattaching peeled trees to a core graph.\n\nC++: dialect::Tree::addNetwork(class dialect::Graph &, int &, int &) --> void", pybind11::arg("G"), pybind11::arg("treeNodes"), pybind11::arg("treeEdges"));
		cl.def("addConstraints", (void (dialect::Tree::*)(class dialect::Graph &, bool)) &dialect::Tree::addConstraints, "Set constraints in a given Graph's SepMatrix in order to maintain the layout of the tree.\n \n\n  The Graph to which the constraints are to be added.\n \n\n  Say whether an alignment constraint should be set between the root node and\n                       a centre node (if present) in the first rank. For example, this should be set\n                       false in the case of a peeled tree being reattached with ordinal placement direction.\n \n\n  The given Graph G must have Nodes matching the IDs of those in this Tree.\n\nC++: dialect::Tree::addConstraints(class dialect::Graph &, bool) --> void", pybind11::arg("G"), pybind11::arg("alignRoot"));
		cl.def("addBufferNodesAndConstraints", (void (dialect::Tree::*)(class dialect::Graph &, int &)) &dialect::Tree::addBufferNodesAndConstraints, "Add buffer nodes to help keep separation between the nodes of the tree and the remainder of\n         the given graph G. Set constraints to keep the buffer nodes in place.\n \n\n  The Graph to which the Nodes and constraints are to be added.\n \n\n  A place to record the buffer nodes that are constructred.\n \n\n  This Tree's addNetworkAndConstraints should have been called first, for the same Graph G.\n\nC++: dialect::Tree::addBufferNodesAndConstraints(class dialect::Graph &, int &) --> void", pybind11::arg("G"), pybind11::arg("bufferNodes"));
		cl.def("padCorrespNonRootNodes", (void (dialect::Tree::*)(class dialect::Graph &, double, double)) &dialect::Tree::padCorrespNonRootNodes, "Add padding to nodes of another graph, corresponding to (same ID) non-root nodes in this tree.\n\nC++: dialect::Tree::padCorrespNonRootNodes(class dialect::Graph &, double, double) --> void", pybind11::arg("H"), pybind11::arg("dw"), pybind11::arg("dh"));
	}
	// dialect::logically_equal(double, double, double) file:libdialect/util.h line:49
	M("dialect").def("logically_equal", [](double const & a0, double const & a1) -> bool { return dialect::logically_equal(a0, a1); }, "", pybind11::arg("a"), pybind11::arg("b"));
	M("dialect").def("logically_equal", (bool (*)(double, double, double)) &dialect::logically_equal, "Tolerant equality test for doubles. Generates principled value\n         for tolerance.\n\n \n  Thanks to: https://stackoverflow.com/a/4010279\n\nC++: dialect::logically_equal(double, double, double) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("error_factor"));

	// dialect::approx_equal(double, double, double) file:libdialect/util.h line:55
	M("dialect").def("approx_equal", [](double const & a0, double const & a1) -> bool { return dialect::approx_equal(a0, a1); }, "", pybind11::arg("a"), pybind11::arg("b"));
	M("dialect").def("approx_equal", (bool (*)(double, double, double)) &dialect::approx_equal, "Tolerant equality test for doubles. Uses arbitrary tolerance.\n\nC++: dialect::approx_equal(double, double, double) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("tol"));

}
