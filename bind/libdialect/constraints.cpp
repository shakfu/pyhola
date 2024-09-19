#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
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

void bind_libdialect_constraints(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::SepPairSubConstraintInfo file:libdialect/constraints.h line:176
		pybind11::class_<dialect::SepPairSubConstraintInfo, std::shared_ptr<dialect::SepPairSubConstraintInfo>> cl(M("dialect"), "SepPairSubConstraintInfo", "Since each SepPair may represent up to two VPSC constraints (one in each dimension), we need a simple wrapper\n struct to represent each dimension.");
		cl.def( pybind11::init( [](){ return new dialect::SepPairSubConstraintInfo(); } ) );
		cl.def( pybind11::init<int, int>(), pybind11::arg("sp"), pybind11::arg("dim") );

		cl.def_readwrite("sp", &dialect::SepPairSubConstraintInfo::sp);
		cl.def_readwrite("dim", &dialect::SepPairSubConstraintInfo::dim);
	}
	{ // dialect::SepMatrix file:libdialect/constraints.h line:185
		pybind11::class_<dialect::SepMatrix, std::shared_ptr<dialect::SepMatrix>> cl(M("dialect"), "SepMatrix", "");
		cl.def( pybind11::init<class dialect::Graph *>(), pybind11::arg("G") );

		cl.def( pybind11::init( [](dialect::SepMatrix const &o){ return new dialect::SepMatrix(o); } ) );
		cl.def("addSep", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double)) &dialect::SepMatrix::addSep, "Add a constraint.\n\n \n   The specified separation is /added/ to any existing constraints\n         between the two nodes. It overwrites anything with which it is\n         in conflict, but leaves everything else intact. For example, if\n         the second node was already constrained to lie UP and to the LEFT\n         of the first, and then a RIGHT sep is added, then the second node\n         will be constrained to lie UP and to the RIGHT of the first.\n\n \n   You cannot /remove/ a constraint using this method. If NONE is passed\n         as the SepType, nothing happens.\n\n \n  The ID of the first node.\n \n\n  The ID of the second node.\n \n\n  The gap type (centre-to-centre, or between opposing boundaries).\n \n\n  The direction of the separation from the first node\n                 to the second node.\n \n\n  The type of the separation.\n \n\n  The size of the separation.\n\nC++: dialect::SepMatrix::addSep(unsigned int, unsigned int, enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("gt"), pybind11::arg("sd"), pybind11::arg("st"), pybind11::arg("gap"));
		cl.def("setCardinalOP", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, int)) &dialect::SepMatrix::setCardinalOP, "Convenience method, for setting that particular type of cardinal separation that merely\n         prevents overlap in the stated direction.\n \n\n SepMatrix::addSep\n\nC++: dialect::SepMatrix::setCardinalOP(unsigned int, unsigned int, int) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("dir"));
		cl.def("addFixedRelativeSep", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, double, double)) &dialect::SepMatrix::addFixedRelativeSep, "Constrain two Nodes to sit at a fixed separation between their centre coordinates.\n\n \n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n \n\n   The desired fixed value for v.x - u.x (centre coordinates)\n \n\n   The desired fixed value for v.y - u.y (centre coordinates)\n\nC++: dialect::SepMatrix::addFixedRelativeSep(unsigned int, unsigned int, double, double) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("addFixedRelativeSep", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::addFixedRelativeSep, "Constrain two Nodes to sit at their present exact separation.\n\n \n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n\nC++: dialect::SepMatrix::addFixedRelativeSep(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("hAlign", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::hAlign, "Align a pair of nodes horizontally.\n\nC++: dialect::SepMatrix::hAlign(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("vAlign", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::vAlign, "Align a pair of nodes vertically.\n\nC++: dialect::SepMatrix::vAlign(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("alignByEquatedCoord", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, int)) &dialect::SepMatrix::alignByEquatedCoord, "Align a pair of nodes by saying which is the coordinate to be equated.\n \n\n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n \n\n  vpsc::Dim naming the coordinate to be equated. Thus XDIM means x-coords will\n                      be equated, giving a vertical alignment; YDIM means y-coords will be equated,\n                      giving a horizontal alignment.\n\nC++: dialect::SepMatrix::alignByEquatedCoord(unsigned int, unsigned int, int) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("eqCoord"));
		cl.def("free", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::free, "Free a pair of Nodes; i.e. remove the SepPair for these Nodes\n         completely.\n\nC++: dialect::SepMatrix::free(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("clear", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::clear, "Clear all constraints.\n\n \n We do not destroy the SepPairs; we merely erase our pointers to them.\n\nC++: dialect::SepMatrix::clear() --> void");
		cl.def("setCorrespondingConstraints", (void (dialect::SepMatrix::*)(class dialect::SepMatrix &) const) &dialect::SepMatrix::setCorrespondingConstraints, "Set corresponding constraints in another SepMatrix.\n\n         This means that for each constraint between nodes of IDs id1 and id2 in this\n         SepMatrix, we set that constraint in the other SepMatrix if and only if its\n         underlying Graph contains Nodes of IDs id1 and id2.\n \n\n  The other SepMatrix.\n\nC++: dialect::SepMatrix::setCorrespondingConstraints(class dialect::SepMatrix &) const --> void", pybind11::arg("matrix"));
		cl.def("setSepPair", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, int)) &dialect::SepMatrix::setSepPair, "Set a SepPair directly into another SepMatrix.\n \n\n  The primary ID under which the SepPair is to be stored.\n \n\n  The secondary ID under which the SepPair is to be stored.\n \n\n  The SepPair to be stored.\n \n\n  Runtime error if id1 >= id2.\n\nC++: dialect::SepMatrix::setSepPair(unsigned int, unsigned int, int) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("sp"));
		cl.def("transform", (void (dialect::SepMatrix::*)(enum dialect::SepTransform)) &dialect::SepMatrix::transform, "Apply a transformation to all Nodes.\n\nC++: dialect::SepMatrix::transform(enum dialect::SepTransform) --> void", pybind11::arg("tf"));
		cl.def("transformClosedSubset", (void (dialect::SepMatrix::*)(enum dialect::SepTransform, const int &)) &dialect::SepMatrix::transformClosedSubset, "Apply a transformation to a closed subset of all Nodes.\n\n \n  the transformation to be performed\n \n\n  the set of IDs of all Nodes to which the transformation\n                  should be applied. /Both/ Nodes must be in the set.\n \n\n transformOpenSubset\n\nC++: dialect::SepMatrix::transformClosedSubset(enum dialect::SepTransform, const int &) --> void", pybind11::arg("tf"), pybind11::arg("ids"));
		cl.def("transformOpenSubset", (void (dialect::SepMatrix::*)(enum dialect::SepTransform, const int &)) &dialect::SepMatrix::transformOpenSubset, "Apply a transformation to an open subset of all Nodes.\n\n \n  the transformation to be performed\n \n\n  the set of IDs of all Nodes to which the transformation\n                  should be applied. /At least one/ Node must be in the set.\n \n\n transformClosedSubset\n\nC++: dialect::SepMatrix::transformOpenSubset(enum dialect::SepTransform, const int &) --> void", pybind11::arg("tf"), pybind11::arg("ids"));
		cl.def("removeNode", (void (dialect::SepMatrix::*)(unsigned int)) &dialect::SepMatrix::removeNode, "Remove all records for the Node of given ID.\n\nC++: dialect::SepMatrix::removeNode(unsigned int) --> void", pybind11::arg("id"));
		cl.def("removeNodes", (void (dialect::SepMatrix::*)(const int &)) &dialect::SepMatrix::removeNodes, "Remove all records for the given Nodes.\n\nC++: dialect::SepMatrix::removeNodes(const int &) --> void", pybind11::arg("nodes"));
		cl.def("getCardinalDir", (int (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::getCardinalDir, "Get the cardinal direction of the separation between two Nodes.\n \n\n  The ID of one of the Nodes.\n \n\n  The ID of the other Node.\n \n\n  Runtime exception if this separation is not cardinal.\n \n\n The cardinal direction.\n\nC++: dialect::SepMatrix::getCardinalDir(unsigned int, unsigned int) const --> int", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("getAlignedSets", (void (dialect::SepMatrix::*)(int) const) &dialect::SepMatrix::getAlignedSets, "Determine which sets of nodes are aligned with one another.\n \n\n  Will be populated with a lookup from Node ID to set of IDs of\n                    all Nodes that are horizontally aligned with that one.\n \n\n  Like hSets, only for vertical alignment.\n\nC++: dialect::SepMatrix::getAlignedSets(int) const --> void", pybind11::arg(""));
		cl.def("areHAligned", (bool (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::areHAligned, "Check whether two nodes are horizontally aligned.\n\nC++: dialect::SepMatrix::areHAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("areVAligned", (bool (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::areVAligned, "Check whether two nodes are vertically aligned.\n\nC++: dialect::SepMatrix::areVAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("writeTglf", (int (dialect::SepMatrix::*)(int) const) &dialect::SepMatrix::writeTglf, "Write a representation of all constraints in the format of\n         the SEPCO'S section of the TGLF file format.\n \n\n  Mapping from internal Node IDs to external IDs for the TGLF output.\n\nC++: dialect::SepMatrix::writeTglf(int) const --> int", pybind11::arg("id2ext"));
		cl.def("setGraph", (void (dialect::SepMatrix::*)(class dialect::Graph *)) &dialect::SepMatrix::setGraph, "Set the related Graph.\n\nC++: dialect::SepMatrix::setGraph(class dialect::Graph *) --> void", pybind11::arg("G"));
		cl.def("getGraph", (class dialect::Graph * (dialect::SepMatrix::*)()) &dialect::SepMatrix::getGraph, "Get the Graph.\n\nC++: dialect::SepMatrix::getGraph() --> class dialect::Graph *", pybind11::return_value_policy::automatic);
		cl.def("roundGapsUpward", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::roundGapsUpward, "Round gaps up to next largest integer. Useful if desiring to move all nodes to\n         integer coordaintes.\n\nC++: dialect::SepMatrix::roundGapsUpward() --> void");
		cl.def("setExtraBdryGap", (void (dialect::SepMatrix::*)(double)) &dialect::SepMatrix::setExtraBdryGap, "Set a global value to be added onto the gap value for all GapType::BDRY constraints.\n\nC++: dialect::SepMatrix::setExtraBdryGap(double) --> void", pybind11::arg("extraBdryGap"));
		cl.def("getExtraBdryGap", (double (dialect::SepMatrix::*)() const) &dialect::SepMatrix::getExtraBdryGap, "C++: dialect::SepMatrix::getExtraBdryGap() const --> double");
		cl.def("generateVariables", (void (dialect::SepMatrix::*)(const int, int &)) &dialect::SepMatrix::generateVariables, "We implement the interface of a cola::CompoundConstraint\n\nC++: dialect::SepMatrix::generateVariables(const int, int &) --> void", pybind11::arg("dim"), pybind11::arg("vars"));
		cl.def("generateSeparationConstraints", (void (dialect::SepMatrix::*)(const int, int &, int &, int &)) &dialect::SepMatrix::generateSeparationConstraints, "C++: dialect::SepMatrix::generateSeparationConstraints(const int, int &, int &, int &) --> void", pybind11::arg("dim"), pybind11::arg("vs"), pybind11::arg("cs"), pybind11::arg("bbs"));
		cl.def("toString", (int (dialect::SepMatrix::*)() const) &dialect::SepMatrix::toString, "C++: dialect::SepMatrix::toString() const --> int");
		cl.def("markAllSubConstraintsAsInactive", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::markAllSubConstraintsAsInactive, "C++: dialect::SepMatrix::markAllSubConstraintsAsInactive() --> void");
	}
	{ // dialect::SepCo file:libdialect/constraints.h line:422
		pybind11::class_<dialect::SepCo, std::shared_ptr<dialect::SepCo>> cl(M("dialect"), "SepCo", "Simple struct to represent separation constraints in one dimension, in terms\n of Nodes (rather than Rectangle indices).\n\n Also supports separation constraints with negative gaps (unlike VPSC).\n Such constraints are perhaps better called \"containment constraints\". To illustrate,\n in the figure below\n\n             ---\n            | a |  ------|\n             ---         |\n                         |\n             ---         |\n            | b |        |\n             ---         |\n\n the separation constraint b.x - 100 <= a.x might mean that node b is constrained to\n stay to the left of the dashed line (which moves with node a).");
		cl.def( pybind11::init( [](){ return new dialect::SepCo(); } ) );
		cl.def( pybind11::init( [](int const & a0, int const & a1, int const & a2, double const & a3){ return new dialect::SepCo(a0, a1, a2, a3); } ), "doc" , pybind11::arg("dim"), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"));
		cl.def( pybind11::init<int, int, int, double, bool>(), pybind11::arg("dim"), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"), pybind11::arg("exact") );

		cl.def_readwrite("dim", &dialect::SepCo::dim);
		cl.def_readwrite("left", &dialect::SepCo::left);
		cl.def_readwrite("right", &dialect::SepCo::right);
		cl.def_readwrite("gap", &dialect::SepCo::gap);
		cl.def_readwrite("exact", &dialect::SepCo::exact);
		cl.def("generateColaConstraints", (void (dialect::SepCo::*)(const struct dialect::ColaGraphRep &, int &)) &dialect::SepCo::generateColaConstraints, "Allocate cola::CompoundConstraints to represent this SepCo.\n \n\n  A ColaGraphRep so that Node Id's can be mapped to Rectangle indices.\n \n\n  A CompoundConstraints vector to which to add pointers to the allocated\n                  constraints.\n\nC++: dialect::SepCo::generateColaConstraints(const struct dialect::ColaGraphRep &, int &) --> void", pybind11::arg("cgr"), pybind11::arg("ccs"));
		cl.def("getDirecRelativeToNode", (int (dialect::SepCo::*)(int) const) &dialect::SepCo::getDirecRelativeToNode, "Determine the constrained direction from one Node to the other.\n \n\n  The Node relative to which the direction is understood.\n \n\n A CardinalDir giving the direction from baseNode to the other node.\n\nC++: dialect::SepCo::getDirecRelativeToNode(int) const --> int", pybind11::arg("baseNode"));
		cl.def("addToMatrix", (void (dialect::SepCo::*)(class dialect::SepMatrix &) const) &dialect::SepCo::addToMatrix, "Add this constraint to a SepMatrix.\n\nC++: dialect::SepCo::addToMatrix(class dialect::SepMatrix &) const --> void", pybind11::arg("matrix"));
		cl.def("violation", (double (dialect::SepCo::*)() const) &dialect::SepCo::violation, "Determine the extent to which this separation constraint is currently violated.\n\nC++: dialect::SepCo::violation() const --> double");
		cl.def("toString", (int (dialect::SepCo::*)() const) &dialect::SepCo::toString, "Write a string representation.\n\nC++: dialect::SepCo::toString() const --> int");
	}
	{ // dialect::Projection file:libdialect/constraints.h line:466
		pybind11::class_<dialect::Projection, std::shared_ptr<dialect::Projection>> cl(M("dialect"), "Projection", "A Projection represents a set of constraints (given by SepCos), together\n with a dimension in which to project.");
		cl.def( pybind11::init( [](){ return new dialect::Projection(); } ) );
		cl.def( pybind11::init<int, int>(), pybind11::arg("s"), pybind11::arg("d") );

		cl.def_readwrite("sepCoSet", &dialect::Projection::sepCoSet);
		cl.def_readwrite("dim", &dialect::Projection::dim);
		cl.def("size", (unsigned long (dialect::Projection::*)()) &dialect::Projection::size, "Check how many SepCos are in the projection.\n\nC++: dialect::Projection::size() --> unsigned long");
		cl.def("generateColaConstraints", (int (dialect::Projection::*)(const struct dialect::ColaGraphRep &)) &dialect::Projection::generateColaConstraints, "Build a vector of cola CompoundConstraints representing the constraints\n         in this Projection.\n \n\n  A ColaGraphRep so that Node Id's can be mapped to Rectangle indices.\n\nC++: dialect::Projection::generateColaConstraints(const struct dialect::ColaGraphRep &) --> int", pybind11::arg("cgr"));
		cl.def("toString", (int (dialect::Projection::*)() const) &dialect::Projection::toString, "Write a string representation.\n\nC++: dialect::Projection::toString() const --> int");
	}
}
