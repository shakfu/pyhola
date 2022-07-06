#include <functional>
#include <iterator>
#include <libavoid/geomtypes.h>
#include <libavoid/router.h>
#include <libcola/cluster.h>
#include <libdialect/constraints.h>
#include <libdialect/expansion.h>
#include <libdialect/faces.h>
#include <libdialect/graphs.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/routing.h>
#include <libdialect/treeplacement.h>
#include <libdialect/trees.h>
#include <libvpsc/rectangle.h>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_libdialect_treeplacement(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::TreePlacement file:libdialect/treeplacement.h line:57
		pybind11::class_<dialect::TreePlacement, std::shared_ptr<dialect::TreePlacement>> cl(M("dialect"), "TreePlacement", "A TreePlacement represents a way of placing a tree into the faces of\n a 4-planar, orthogonal layout.");
		cl.def( pybind11::init( [](class std::shared_ptr<class dialect::Tree> const & a0, class dialect::Face & a1, class std::shared_ptr<class dialect::Node> const & a2, enum dialect::CompassDir const & a3, enum dialect::CardinalDir const & a4){ return new dialect::TreePlacement(a0, a1, a2, a3, a4); } ), "doc" , pybind11::arg("tree"), pybind11::arg("face"), pybind11::arg("faceRoot"), pybind11::arg("dp"), pybind11::arg("dg"));
		cl.def( pybind11::init<class std::shared_ptr<class dialect::Tree>, class dialect::Face &, class std::shared_ptr<class dialect::Node>, enum dialect::CompassDir, enum dialect::CardinalDir, bool>(), pybind11::arg("tree"), pybind11::arg("face"), pybind11::arg("faceRoot"), pybind11::arg("dp"), pybind11::arg("dg"), pybind11::arg("flip") );

		cl.def( pybind11::init( [](dialect::TreePlacement const &o){ return new dialect::TreePlacement(o); } ) );
		cl.def("getPlacementDir", (enum dialect::CompassDir (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getPlacementDir, "Get the placement direction.\n\nC++: dialect::TreePlacement::getPlacementDir() const --> enum dialect::CompassDir");
		cl.def("getGrowthDir", (enum dialect::CardinalDir (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getGrowthDir, "Get the growth direction.\n\nC++: dialect::TreePlacement::getGrowthDir() const --> enum dialect::CardinalDir");
		cl.def("isExternal", (bool (dialect::TreePlacement::*)() const) &dialect::TreePlacement::isExternal, "Check whether the placement is into the external face.\n\nC++: dialect::TreePlacement::isExternal() const --> bool");
		cl.def("id", (unsigned int (dialect::TreePlacement::*)() const) &dialect::TreePlacement::id, "Get the unique ID of this instance.\n\nC++: dialect::TreePlacement::id() const --> unsigned int");
		cl.def("getNumPotentialNbrs", (unsigned long (dialect::TreePlacement::*)()) &dialect::TreePlacement::getNumPotentialNbrs, "Check the number of \"potential neighbours\" of this tree, if placed\n         according to this placement. This is equal to the number of other\n         root nodes on the relevant Sides to which the root node of this\n         placement belongs.\n\nC++: dialect::TreePlacement::getNumPotentialNbrs() --> unsigned long");
		cl.def("estimateCost", (double (dialect::TreePlacement::*)()) &dialect::TreePlacement::estimateCost, "Estimate the cost of this placement.\n\nC++: dialect::TreePlacement::estimateCost() --> double");
		cl.def("getRootNode", (class std::shared_ptr<class dialect::Node> (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getRootNode, "Get the Node at which the Tree would be rooted:\n\nC++: dialect::TreePlacement::getRootNode() const --> class std::shared_ptr<class dialect::Node>");
		cl.def("getFace", (class dialect::Face & (dialect::TreePlacement::*)()) &dialect::TreePlacement::getFace, "Access the Face to which this placement belongs.\n\nC++: dialect::TreePlacement::getFace() --> class dialect::Face &", pybind11::return_value_policy::automatic);
		cl.def("insertTreeNode", [](dialect::TreePlacement &o) -> void { return o.insertTreeNode(); }, "");
		cl.def("insertTreeNode", (void (dialect::TreePlacement::*)(double)) &dialect::TreePlacement::insertTreeNode, "Insert a node representing the Tree into the Face to which this\n         placement belongs.\n \n\n  Optional padding to be added to the tree box.\n \n\n TreePlacement::getTreeBox for interpretation of the padding.\n\nC++: dialect::TreePlacement::insertTreeNode(double) --> void", pybind11::arg("padding"));
		cl.def("toString", (std::string (dialect::TreePlacement::*)() const) &dialect::TreePlacement::toString, "Get a string representation.\n\nC++: dialect::TreePlacement::toString() const --> std::string");
		cl.def("buildTreeBox", [](dialect::TreePlacement const &o) -> std::shared_ptr<class dialect::Node> { return o.buildTreeBox(); }, "");
		cl.def("buildTreeBox", (class std::shared_ptr<class dialect::Node> (dialect::TreePlacement::*)(double) const) &dialect::TreePlacement::buildTreeBox, "Determine the size of the tree minus the root node, and the position\n         relative to the root node.\n\n \n  Optionally, you may request padding be added to the /outside/\n                     sides of the box, i.e. all those except the side facing the\n                     root node. For example, for a north-growing tree, the padding\n                     will be added only to the north, east, and west sides.\n                     Recommended value for padding is one quarter of the Graph's\n                     ideal edge length (iel/4.0).\n\n \n  A Node whose dimensions w x h gives the dimensions of the bounding box\n          of the tree, minus the root node, and whose position (x, y) gives the\n          vector from the centre of the root node to the centre of this box.\n\n \n  The dimensions are in respect of the growth direction of this TreePlacement,\n        and the position vector is in respect of its placement direction and flip bit.\n\nC++: dialect::TreePlacement::buildTreeBox(double) const --> class std::shared_ptr<class dialect::Node>", pybind11::arg("padding"));
		cl.def("recordBoxNode", (void (dialect::TreePlacement::*)(class std::shared_ptr<class dialect::Node> &)) &dialect::TreePlacement::recordBoxNode, "Record the Node representing the box for the Tree.\n\nC++: dialect::TreePlacement::recordBoxNode(class std::shared_ptr<class dialect::Node> &) --> void", pybind11::arg("boxNode"));
		cl.def("hasBoxNode", (bool (dialect::TreePlacement::*)()) &dialect::TreePlacement::hasBoxNode, "Check whether this TreePlacement has a box node yet.\n\nC++: dialect::TreePlacement::hasBoxNode() --> bool");
		cl.def("getBoxNode", (class std::shared_ptr<class dialect::Node> (dialect::TreePlacement::*)()) &dialect::TreePlacement::getBoxNode, "Get the box node.\n\nC++: dialect::TreePlacement::getBoxNode() --> class std::shared_ptr<class dialect::Node>");
		cl.def("buildBestProjSeq", [](dialect::TreePlacement &o) -> std::shared_ptr<class dialect::ProjSeq> { return o.buildBestProjSeq(); }, "");
		cl.def("buildBestProjSeq", [](dialect::TreePlacement &o, double const & a0) -> std::shared_ptr<class dialect::ProjSeq> { return o.buildBestProjSeq(a0); }, "", pybind11::arg("padding"));
		cl.def("buildBestProjSeq", [](dialect::TreePlacement &o, double const & a0, bool const & a1) -> std::shared_ptr<class dialect::ProjSeq> { return o.buildBestProjSeq(a0, a1); }, "", pybind11::arg("padding"), pybind11::arg("doCostlierDimensionFirst"));
		cl.def("buildBestProjSeq", (class std::shared_ptr<class dialect::ProjSeq> (dialect::TreePlacement::*)(double, bool, enum dialect::ExpansionEstimateMethod)) &dialect::TreePlacement::buildBestProjSeq, "Build the best projection sequence for this tree placement.\n \n\n  Optional padding for the new tree box.\n \n\n  Set true to do the more expensive dimension first,\n             in hopes that this will obviate expansion in the other dimension altogether.\n \n\n  See defn of ExpansionEstimateMethod enum class.\n \n\n  A ProjSeq representing the computed projection sequence.\n\nC++: dialect::TreePlacement::buildBestProjSeq(double, bool, enum dialect::ExpansionEstimateMethod) --> class std::shared_ptr<class dialect::ProjSeq>", pybind11::arg("padding"), pybind11::arg("doCostlierDimensionFirst"), pybind11::arg("expansionMethod"));
		cl.def("somePointOppositeSegment", [](dialect::TreePlacement &o, struct dialect::LineSegment & a0, class Avoid::Point & a1) -> bool { return o.somePointOppositeSegment(a0, a1); }, "", pybind11::arg("seg"), pybind11::arg("pt"));
		cl.def("somePointOppositeSegment", [](dialect::TreePlacement &o, struct dialect::LineSegment & a0, class Avoid::Point & a1, double const & a2) -> bool { return o.somePointOppositeSegment(a0, a1, a2); }, "", pybind11::arg("seg"), pybind11::arg("pt"), pybind11::arg("padding"));
		cl.def("somePointOppositeSegment", (bool (dialect::TreePlacement::*)(struct dialect::LineSegment &, class Avoid::Point &, double, bool)) &dialect::TreePlacement::somePointOppositeSegment, "Compute some point belonging to the tree box and lying opposite a given\n         line segment.\n \n\n  The LineSegment in question.\n \n\n  The point whose coordinates are to be set.\n \n\n  Padding for the tree box.\n \n\n  Set true if you want to use the open interval of the line\n                          segment instead of closed (the default).\n \n\n boolean saying whether the tree box indeed lies opposite the given line segment.\n\n \n  We compute the interval I of the tree box in the dimension parallel to the segment.\n Let J be the interval of the segment -- open if the openInterval argument is true; closed\n otherwise. Let K be the intersection of I and J. If K is empty then we return false.\n Otherwise we pick a value w in K and return a point having w as one of its coordinates and\n a centre coordinate of the tree box as the other coordinate.\n\nC++: dialect::TreePlacement::somePointOppositeSegment(struct dialect::LineSegment &, class Avoid::Point &, double, bool) --> bool", pybind11::arg("seg"), pybind11::arg("pt"), pybind11::arg("padding"), pybind11::arg("openInterval"));
		cl.def("applyGeometryToTree", (void (dialect::TreePlacement::*)()) &dialect::TreePlacement::applyGeometryToTree, "Rotate, flip, and translate the tree as necessary to match this placement.\n\nC++: dialect::TreePlacement::applyGeometryToTree() --> void");
		cl.def("insertTreeIntoGraph", (void (dialect::TreePlacement::*)(class dialect::Graph &, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, class std::map<unsigned int, class std::shared_ptr<class dialect::Edge>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Edge> > > > &)) &dialect::TreePlacement::insertTreeIntoGraph, "Insert the tree into a given Graph.\n \n\n  The Graph into which the tree is to be inserted.\n \n\n  A place to record the tree nodes that are constructred.\n \n\n  A place to record the buffer nodes that are constructred.\n \n\n  A place to record the tree edges that are added.\n\nC++: dialect::TreePlacement::insertTreeIntoGraph(class dialect::Graph &, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, class std::map<unsigned int, class std::shared_ptr<class dialect::Edge>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Edge> > > > &) --> void", pybind11::arg("G"), pybind11::arg("treeNodes"), pybind11::arg("bufferNodes"), pybind11::arg("treeEdges"));
		cl.def("size", (unsigned long (dialect::TreePlacement::*)() const) &dialect::TreePlacement::size, "Check the size (i.e. number of nodes in) the Tree.\n\nC++: dialect::TreePlacement::size() const --> unsigned long");
		cl.def("setRootAligns", (void (dialect::TreePlacement::*)(enum vpsc::Dim, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &)) &dialect::TreePlacement::setRootAligns, "Tell the TreePlacement which Nodes are aligned with its root node in a given dimension.\n \n\n  The alignment dimension.\n \n\n  The set of IDs of nodes that are aligned in this dimension with the root node.\n\nC++: dialect::TreePlacement::setRootAligns(enum vpsc::Dim, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &) --> void", pybind11::arg("dim"), pybind11::arg("idSet"));
		cl.def("rootIsAlignedWith", (bool (dialect::TreePlacement::*)(enum vpsc::Dim, unsigned int)) &dialect::TreePlacement::rootIsAlignedWith, "Check whether the root node is aligned with a given node, in a given dimension.\n \n\n  The dimension of interest.\n \n\n  The ID of the node in question.\n\nC++: dialect::TreePlacement::rootIsAlignedWith(enum vpsc::Dim, unsigned int) --> bool", pybind11::arg("dim"), pybind11::arg("id"));
	}
	{ // dialect::ExpansionManager file:libdialect/expansion.h line:98
		pybind11::class_<dialect::ExpansionManager, std::shared_ptr<dialect::ExpansionManager>> cl(M("dialect"), "ExpansionManager", "The ExpansionManager class\n\n    An instance of this class is meant to manage the generation of nonoverlap\n    constraints, when making room for a TreePlacement in a Face of a planar\n    orthogonal layout.\n\n    The idea is that we choose strategic \"goal points\" in the face, and compute\n    the line segments from the tree's attachment point to these goal points.\n    We can then use these line segments to determine the nonoverlap constraints\n    by pushing everything on one side of the line to one side, and everything\n    on the other side of the line to the other side.\n\n    A TreePlacement has both a \"placement direction\" dp, and a \"growth\n    direction\" dg. The former is any compass point, cardinal or ordinal, while\n    the latter must be cardinal. Expansion constraints are said to be \"axial\"\n    when they operate in the dimension to which dg belongs, and to be\n    \"transverse\" when they operate in the complementary dimension.\n    For example if dg is NORTH, then SepCo's in the y-dim are axial,\n    while those in the x-dim are transverse.\n\n    Similarly, goal points are called axial or transverse according to the type\n    of constraints they generate. If the placement direction dp is cardinal, then\n    there is one transverse goal point, and there are two axial goal poitns.\n    If the placement direction dp is ordinal, there there is one transverse and\n    one axial goal point.\n\n    For example, for a north-growing tree that was also placed north, see the\n    figure on the left, below. Rooted at the \"o\", the three goal points are marked\n    by \"a\", \"b\", \"c\". Goal point \"a\" is the one transverse goal point, since it will\n    generate expansion constraints operating left and right, i.e. in the x-dimension.\n    Meanwhile points \"b\" and \"c\" are the two axial goal points, since they will\n    generate expansion constraints operating up and down, i.e. in the y-dimension.\n\n                ---a---         a-------\n               |      |         |      |\n               |      |         |      |\n               c---o--b         o------b\n\n    The figure on the right shows the two goal points for a north-growing tree that\n    was placed north-east. Here there is one transverse goal point (\"a\"), and one\n    axial (\"b\").\n\n    For each goal point the ExpansionManager constructs an ExpansionGoal object,\n    which in turn uses the ContainedSegment class to generate expansion constraints.\n\n    Note: In an earlier version of HOLA (the Python version from 2015), this process\n    was much more complex, potentially considering many more goal points, spanning\n    face concavities. In those caes libavoid was used to find an orthogonal route\n    to the goal point, and the segments of the route were used to select the expansion\n    constraints. That system allowed us to consider all possible ways of expanding\n    a face. The present system is faster and simpler, and is deemed to produce\n    results of equal quality.");
		cl.def( pybind11::init( [](class std::shared_ptr<class dialect::TreePlacement> const & a0){ return new dialect::ExpansionManager(a0); } ), "doc" , pybind11::arg("tp"));
		cl.def( pybind11::init( [](class std::shared_ptr<class dialect::TreePlacement> const & a0, enum vpsc::Dim const & a1){ return new dialect::ExpansionManager(a0, a1); } ), "doc" , pybind11::arg("tp"), pybind11::arg("primaryDim"));
		cl.def( pybind11::init<class std::shared_ptr<class dialect::TreePlacement>, enum vpsc::Dim, double>(), pybind11::arg("tp"), pybind11::arg("primaryDim"), pybind11::arg("padding") );

		cl.def( pybind11::init( [](dialect::ExpansionManager const &o){ return new dialect::ExpansionManager(o); } ) );
		cl.def("isAxial", (bool (dialect::ExpansionManager::*)(enum vpsc::Dim)) &dialect::ExpansionManager::isAxial, "Check whether a given dimension is axial w.r.t. this manager's placement.\n\nC++: dialect::ExpansionManager::isAxial(enum vpsc::Dim) --> bool", pybind11::arg("dim"));
		cl.def("isTransverse", (bool (dialect::ExpansionManager::*)(enum vpsc::Dim)) &dialect::ExpansionManager::isTransverse, "Check whether a given dimension is transverse w.r.t. this manager's placement.\n\nC++: dialect::ExpansionManager::isTransverse(enum vpsc::Dim) --> bool", pybind11::arg("dim"));
		cl.def("estimateCost", (double (dialect::ExpansionManager::*)() const) &dialect::ExpansionManager::estimateCost, "Estimate the cost of expanding.\n\nC++: dialect::ExpansionManager::estimateCost() const --> double");
		cl.def("extendProjSeq", (class std::shared_ptr<class dialect::ProjSeq> (dialect::ExpansionManager::*)(class std::shared_ptr<class dialect::ProjSeq>)) &dialect::ExpansionManager::extendProjSeq, "Extend a given projection sequence with those projections necessary\n         to achieve all expansion goals of this manager.\n \n\n  The given ProjSeq.\n \n\n A new ProjSeq that extends the given one.\n \n\n  Runtime error if any attempted projection is impossible.\n\nC++: dialect::ExpansionManager::extendProjSeq(class std::shared_ptr<class dialect::ProjSeq>) --> class std::shared_ptr<class dialect::ProjSeq>", pybind11::arg("ps0"));
	}
}