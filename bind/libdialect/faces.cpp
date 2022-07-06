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

void bind_libdialect_faces(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::NexusPolarity file:libdialect/faces.h line:164
	pybind11::enum_<dialect::NexusPolarity>(M("dialect"), "NexusPolarity", "")
		.value("ENTER_FROM", dialect::NexusPolarity::ENTER_FROM)
		.value("EXIT_TO", dialect::NexusPolarity::EXIT_TO);

;

	{ // dialect::Nexus file:libdialect/faces.h line:182
		pybind11::class_<dialect::Nexus, std::shared_ptr<dialect::Nexus>> cl(M("dialect"), "Nexus", "Regarded as a member of a Face F, a Node u belongs to certain Sides si\n of F. As we traverse the face in the clockwise direction (i.e. so that the\n interior of the face is always to the /right/), each Side si gets a direction,\n and therefore may stand in one of eight relations to Node u: it may be /entering/\n or /exiting/, and this may be from or to any of the four cardinal compass directions.\n\n A single Side may stand in two such relations, as when the Node lies along\n the middle of the Side, or else in just one such relation, as when a Node\n lies at one end or the other.\n\n A Nexus represents a Node in this capacity as a \"joining point\" of several\n Sides of a Face. It stores eight \"slots\" that are either empty or else occupied by\n a Side object.");
		cl.def( pybind11::init( [](dialect::Nexus const &o){ return new dialect::Nexus(o); } ) );
	}
	{ // dialect::FaceSet file:libdialect/faces.h line:251
		pybind11::class_<dialect::FaceSet, std::shared_ptr<dialect::FaceSet>> cl(M("dialect"), "FaceSet", "Holds all the Face objects for a given 4-planar, orthogonal layout,\n and provides methods to use and manage them.");
		cl.def( pybind11::init( [](dialect::FaceSet const &o){ return new dialect::FaceSet(o); } ) );
		cl.def("getNumFaces", (unsigned long (dialect::FaceSet::*)()) &dialect::FaceSet::getNumFaces, "Check how many faces there are.\n\nC++: dialect::FaceSet::getNumFaces() --> unsigned long");
	}
	{ // dialect::Face file:libdialect/faces.h line:306
		pybind11::class_<dialect::Face, std::shared_ptr<dialect::Face>> cl(M("dialect"), "Face", "Represents a single face of a 4-planar, orthogonal layout.");
		cl.def( pybind11::init( [](dialect::Face const &o){ return new dialect::Face(o); } ) );
		cl.def("id", (unsigned int (dialect::Face::*)() const) &dialect::Face::id, "Access the unique ID of a given instance.\n\n \n  The ID.\n\nC++: dialect::Face::id() const --> unsigned int");
		cl.def("isExternal", (bool (dialect::Face::*)() const) &dialect::Face::isExternal, "Check whether this is the external face or not.\n\nC++: dialect::Face::isExternal() const --> bool");
		cl.def("applyProjSeq", (bool (dialect::Face::*)(class dialect::ProjSeq &)) &dialect::Face::applyProjSeq, "Convenience function for applying a ProjSeq with all the appropriate options.\n \n\n  The ProjSeq to be applied.\n \n\n boolean, saying whether all the projections were successful.\n\nC++: dialect::Face::applyProjSeq(class dialect::ProjSeq &) --> bool", pybind11::arg("ps"));
	}
	{ // dialect::Tree file:libdialect/trees.h line:44
		pybind11::class_<dialect::Tree, std::shared_ptr<dialect::Tree>> cl(M("dialect"), "Tree", "");
		cl.def( pybind11::init( [](dialect::Tree const &o){ return new dialect::Tree(o); } ) );
		cl.def("symmetricLayout", [](dialect::Tree &o, enum dialect::CardinalDir const & a0, double const & a1, double const & a2) -> void { return o.symmetricLayout(a0, a1, a2); }, "", pybind11::arg("growthDir"), pybind11::arg("nodeSep"), pybind11::arg("rankSep"));
		cl.def("symmetricLayout", (void (dialect::Tree::*)(enum dialect::CardinalDir, double, double, bool)) &dialect::Tree::symmetricLayout, "Apply the Symmetric Layout algorithm of Manning & Atallah\n             See Manning, Joseph, and Mikhail J. Atallah.\n             \"Fast detection and display of symmetry in trees.\" (1985).\n\n \n  The direction in which the tree should grow.\n \n\n  Minimal gap between nodes on the same rank.\n \n\n  Minimal separation between ranks.\n \n\n  If true, the broadest and deepest subtrees are\n                             placed near the centre; if false, the opposite.\n\nC++: dialect::Tree::symmetricLayout(enum dialect::CardinalDir, double, double, bool) --> void", pybind11::arg("growthDir"), pybind11::arg("nodeSep"), pybind11::arg("rankSep"), pybind11::arg("convexOrdering"));
		cl.def("flip", (void (dialect::Tree::*)()) &dialect::Tree::flip, "Flip the tree's layout over the axis running through the root node\n         and aligned with the growth direction.\n\nC++: dialect::Tree::flip() --> void");
		cl.def("translate", (void (dialect::Tree::*)(class Avoid::Point)) &dialect::Tree::translate, "Translate the tree's layout by a given vector.\n\n \n  The vector by which to translate.\n\nC++: dialect::Tree::translate(class Avoid::Point) --> void", pybind11::arg("vect"));
		cl.def("rotate", (void (dialect::Tree::*)(enum dialect::CardinalDir)) &dialect::Tree::rotate, "Rotate the tree's layout to attain a desired growth direction.\n\n \n  The desired growth direction.\n\nC++: dialect::Tree::rotate(enum dialect::CardinalDir) --> void", pybind11::arg("dg"));
		cl.def("rotateGrowthDirCW", (void (dialect::Tree::*)(unsigned int)) &dialect::Tree::rotateGrowthDirCW, "Do not rotate the layout, but simply update the Tree's growth direction by rotating clockwise.\n \n\n  How many quarter turns clockwise to rotate the growth direction.\n\nC++: dialect::Tree::rotateGrowthDirCW(unsigned int) --> void", pybind11::arg("quarterTurns"));
		cl.def("getRootNodeID", (unsigned int (dialect::Tree::*)() const) &dialect::Tree::getRootNodeID, "Check the ID of the root ndoe.\n\nC++: dialect::Tree::getRootNodeID() const --> unsigned int");
		cl.def("isSymmetrical", (bool (dialect::Tree::*)() const) &dialect::Tree::isSymmetrical, "Check whether the layout is symmetrical.\n\n \n  Just because you have called a Tree's symmetricLayout method, does not\n        mean it acutally got a symmetrical layout! That is only possible if the\n        Tree's structure is in fact symmetrical. This method informs you whether\n        the latter is the case.\n\nC++: dialect::Tree::isSymmetrical() const --> bool");
		cl.def("size", (unsigned long (dialect::Tree::*)() const) &dialect::Tree::size, "Check how many nodes are in the tree.\n\nC++: dialect::Tree::size() const --> unsigned long");
		cl.def("addConstraints", (void (dialect::Tree::*)(class dialect::Graph &, bool)) &dialect::Tree::addConstraints, "Set constraints in a given Graph's SepMatrix in order to maintain the layout of the tree.\n \n\n  The Graph to which the constraints are to be added.\n \n\n  Say whether an alignment constraint should be set between the root node and\n                       a centre node (if present) in the first rank. For example, this should be set\n                       false in the case of a peeled tree being reattached with ordinal placement direction.\n \n\n  The given Graph G must have Nodes matching the IDs of those in this Tree.\n\nC++: dialect::Tree::addConstraints(class dialect::Graph &, bool) --> void", pybind11::arg("G"), pybind11::arg("alignRoot"));
	}
	{ // dialect::TreePlacement file:libdialect/treeplacement.h line:57
		pybind11::class_<dialect::TreePlacement, std::shared_ptr<dialect::TreePlacement>> cl(M("dialect"), "TreePlacement", "A TreePlacement represents a way of placing a tree into the faces of\n a 4-planar, orthogonal layout.");
		cl.def( pybind11::init( [](dialect::TreePlacement const &o){ return new dialect::TreePlacement(o); } ) );
		cl.def("getPlacementDir", (enum dialect::CompassDir (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getPlacementDir, "Get the placement direction.\n\nC++: dialect::TreePlacement::getPlacementDir() const --> enum dialect::CompassDir");
		cl.def("getGrowthDir", (enum dialect::CardinalDir (dialect::TreePlacement::*)() const) &dialect::TreePlacement::getGrowthDir, "Get the growth direction.\n\nC++: dialect::TreePlacement::getGrowthDir() const --> enum dialect::CardinalDir");
		cl.def("isExternal", (bool (dialect::TreePlacement::*)() const) &dialect::TreePlacement::isExternal, "Check whether the placement is into the external face.\n\nC++: dialect::TreePlacement::isExternal() const --> bool");
		cl.def("id", (unsigned int (dialect::TreePlacement::*)() const) &dialect::TreePlacement::id, "Get the unique ID of this instance.\n\nC++: dialect::TreePlacement::id() const --> unsigned int");
		cl.def("getNumPotentialNbrs", (unsigned long (dialect::TreePlacement::*)()) &dialect::TreePlacement::getNumPotentialNbrs, "Check the number of \"potential neighbours\" of this tree, if placed\n         according to this placement. This is equal to the number of other\n         root nodes on the relevant Sides to which the root node of this\n         placement belongs.\n\nC++: dialect::TreePlacement::getNumPotentialNbrs() --> unsigned long");
		cl.def("estimateCost", (double (dialect::TreePlacement::*)()) &dialect::TreePlacement::estimateCost, "Estimate the cost of this placement.\n\nC++: dialect::TreePlacement::estimateCost() --> double");
		cl.def("getFace", (class dialect::Face & (dialect::TreePlacement::*)()) &dialect::TreePlacement::getFace, "Access the Face to which this placement belongs.\n\nC++: dialect::TreePlacement::getFace() --> class dialect::Face &", pybind11::return_value_policy::automatic);
		cl.def("insertTreeNode", [](dialect::TreePlacement &o) -> void { return o.insertTreeNode(); }, "");
		cl.def("insertTreeNode", (void (dialect::TreePlacement::*)(double)) &dialect::TreePlacement::insertTreeNode, "Insert a node representing the Tree into the Face to which this\n         placement belongs.\n \n\n  Optional padding to be added to the tree box.\n \n\n TreePlacement::getTreeBox for interpretation of the padding.\n\nC++: dialect::TreePlacement::insertTreeNode(double) --> void", pybind11::arg("padding"));
		cl.def("hasBoxNode", (bool (dialect::TreePlacement::*)()) &dialect::TreePlacement::hasBoxNode, "Check whether this TreePlacement has a box node yet.\n\nC++: dialect::TreePlacement::hasBoxNode() --> bool");
		cl.def("somePointOppositeSegment", [](dialect::TreePlacement &o, struct dialect::LineSegment & a0, class Avoid::Point & a1) -> bool { return o.somePointOppositeSegment(a0, a1); }, "", pybind11::arg("seg"), pybind11::arg("pt"));
		cl.def("somePointOppositeSegment", [](dialect::TreePlacement &o, struct dialect::LineSegment & a0, class Avoid::Point & a1, double const & a2) -> bool { return o.somePointOppositeSegment(a0, a1, a2); }, "", pybind11::arg("seg"), pybind11::arg("pt"), pybind11::arg("padding"));
		cl.def("somePointOppositeSegment", (bool (dialect::TreePlacement::*)(struct dialect::LineSegment &, class Avoid::Point &, double, bool)) &dialect::TreePlacement::somePointOppositeSegment, "Compute some point belonging to the tree box and lying opposite a given\n         line segment.\n \n\n  The LineSegment in question.\n \n\n  The point whose coordinates are to be set.\n \n\n  Padding for the tree box.\n \n\n  Set true if you want to use the open interval of the line\n                          segment instead of closed (the default).\n \n\n boolean saying whether the tree box indeed lies opposite the given line segment.\n\n \n  We compute the interval I of the tree box in the dimension parallel to the segment.\n Let J be the interval of the segment -- open if the openInterval argument is true; closed\n otherwise. Let K be the intersection of I and J. If K is empty then we return false.\n Otherwise we pick a value w in K and return a point having w as one of its coordinates and\n a centre coordinate of the tree box as the other coordinate.\n\nC++: dialect::TreePlacement::somePointOppositeSegment(struct dialect::LineSegment &, class Avoid::Point &, double, bool) --> bool", pybind11::arg("seg"), pybind11::arg("pt"), pybind11::arg("padding"), pybind11::arg("openInterval"));
		cl.def("applyGeometryToTree", (void (dialect::TreePlacement::*)()) &dialect::TreePlacement::applyGeometryToTree, "Rotate, flip, and translate the tree as necessary to match this placement.\n\nC++: dialect::TreePlacement::applyGeometryToTree() --> void");
		cl.def("size", (unsigned long (dialect::TreePlacement::*)() const) &dialect::TreePlacement::size, "Check the size (i.e. number of nodes in) the Tree.\n\nC++: dialect::TreePlacement::size() const --> unsigned long");
		cl.def("rootIsAlignedWith", (bool (dialect::TreePlacement::*)(enum vpsc::Dim, unsigned int)) &dialect::TreePlacement::rootIsAlignedWith, "Check whether the root node is aligned with a given node, in a given dimension.\n \n\n  The dimension of interest.\n \n\n  The ID of the node in question.\n\nC++: dialect::TreePlacement::rootIsAlignedWith(enum vpsc::Dim, unsigned int) --> bool", pybind11::arg("dim"), pybind11::arg("id"));
	}
	{ // dialect::ExpansionManager file:libdialect/expansion.h line:98
		pybind11::class_<dialect::ExpansionManager, std::shared_ptr<dialect::ExpansionManager>> cl(M("dialect"), "ExpansionManager", "The ExpansionManager class\n\n    An instance of this class is meant to manage the generation of nonoverlap\n    constraints, when making room for a TreePlacement in a Face of a planar\n    orthogonal layout.\n\n    The idea is that we choose strategic \"goal points\" in the face, and compute\n    the line segments from the tree's attachment point to these goal points.\n    We can then use these line segments to determine the nonoverlap constraints\n    by pushing everything on one side of the line to one side, and everything\n    on the other side of the line to the other side.\n\n    A TreePlacement has both a \"placement direction\" dp, and a \"growth\n    direction\" dg. The former is any compass point, cardinal or ordinal, while\n    the latter must be cardinal. Expansion constraints are said to be \"axial\"\n    when they operate in the dimension to which dg belongs, and to be\n    \"transverse\" when they operate in the complementary dimension.\n    For example if dg is NORTH, then SepCo's in the y-dim are axial,\n    while those in the x-dim are transverse.\n\n    Similarly, goal points are called axial or transverse according to the type\n    of constraints they generate. If the placement direction dp is cardinal, then\n    there is one transverse goal point, and there are two axial goal poitns.\n    If the placement direction dp is ordinal, there there is one transverse and\n    one axial goal point.\n\n    For example, for a north-growing tree that was also placed north, see the\n    figure on the left, below. Rooted at the \"o\", the three goal points are marked\n    by \"a\", \"b\", \"c\". Goal point \"a\" is the one transverse goal point, since it will\n    generate expansion constraints operating left and right, i.e. in the x-dimension.\n    Meanwhile points \"b\" and \"c\" are the two axial goal points, since they will\n    generate expansion constraints operating up and down, i.e. in the y-dimension.\n\n                ---a---         a-------\n               |      |         |      |\n               |      |         |      |\n               c---o--b         o------b\n\n    The figure on the right shows the two goal points for a north-growing tree that\n    was placed north-east. Here there is one transverse goal point (\"a\"), and one\n    axial (\"b\").\n\n    For each goal point the ExpansionManager constructs an ExpansionGoal object,\n    which in turn uses the ContainedSegment class to generate expansion constraints.\n\n    Note: In an earlier version of HOLA (the Python version from 2015), this process\n    was much more complex, potentially considering many more goal points, spanning\n    face concavities. In those caes libavoid was used to find an orthogonal route\n    to the goal point, and the segments of the route were used to select the expansion\n    constraints. That system allowed us to consider all possible ways of expanding\n    a face. The present system is faster and simpler, and is deemed to produce\n    results of equal quality.");
		cl.def( pybind11::init( [](dialect::ExpansionManager const &o){ return new dialect::ExpansionManager(o); } ) );
		cl.def("isAxial", (bool (dialect::ExpansionManager::*)(enum vpsc::Dim)) &dialect::ExpansionManager::isAxial, "Check whether a given dimension is axial w.r.t. this manager's placement.\n\nC++: dialect::ExpansionManager::isAxial(enum vpsc::Dim) --> bool", pybind11::arg("dim"));
		cl.def("isTransverse", (bool (dialect::ExpansionManager::*)(enum vpsc::Dim)) &dialect::ExpansionManager::isTransverse, "Check whether a given dimension is transverse w.r.t. this manager's placement.\n\nC++: dialect::ExpansionManager::isTransverse(enum vpsc::Dim) --> bool", pybind11::arg("dim"));
		cl.def("estimateCost", (double (dialect::ExpansionManager::*)() const) &dialect::ExpansionManager::estimateCost, "Estimate the cost of expanding.\n\nC++: dialect::ExpansionManager::estimateCost() const --> double");
	}
}
