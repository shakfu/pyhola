#include <__memory/shared_ptr.h>
#include <libavoid/geomtypes.h>
#include <libdialect/chains.h>
#include <libdialect/constraints.h>
#include <libdialect/faces.h>
#include <libdialect/graphs.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/treeplacement.h>
#include <libdialect/trees.h>
#include <libvpsc/rectangle.h>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <utility>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_libdialect_chains(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::LinkShape file:libdialect/chains.h line:47
	pybind11::enum_<dialect::LinkShape>(M("dialect"), "LinkShape", "In a 4-planar orthogonal layout, a link has one of six possible shapes, depending\n on which two of its four sides are the ones where its edges meet it.\n For example, if one edge enters from the south, and the other from the east, then\n this link is shaped like the top-left corner of a box.\n This enum names the six possible configurations.")
		.value("TLC", dialect::LinkShape::TLC)
		.value("H", dialect::LinkShape::H)
		.value("BLC", dialect::LinkShape::BLC)
		.value("TRC", dialect::LinkShape::TRC)
		.value("V", dialect::LinkShape::V)
		.value("BRC", dialect::LinkShape::BRC);

;

	// dialect::bentLinkShapeCwFromStartingPt(enum dialect::LinkShape) file:libdialect/chains.h line:62
	M("dialect").def("bentLinkShapeCwFromStartingPt", (int (*)(enum dialect::LinkShape)) &dialect::bentLinkShapeCwFromStartingPt, "Get the bent LinkShapes, in clockwise order, starting from a given one.\n\nC++: dialect::bentLinkShapeCwFromStartingPt(enum dialect::LinkShape) --> int", pybind11::arg("start"));

	{ // dialect::BendSequence file:libdialect/chains.h line:115
		pybind11::class_<dialect::BendSequence, std::shared_ptr<dialect::BendSequence>> cl(M("dialect"), "BendSequence", "A data structure for managing sequences of bend types, points at which these\n bends should occur (in a given Chain), cost of such a sequence of bends\n (for a given Chain), and incoming and outgoing Compass directions, for non-cycles.");
		cl.def( pybind11::init<int &>(), pybind11::arg("shapes") );

		cl.def( pybind11::init<int &, enum dialect::CardinalDir, enum dialect::CardinalDir>(), pybind11::arg("shapes"), pybind11::arg("inDir"), pybind11::arg("outDir") );

		cl.def_readwrite("bendTypes", &dialect::BendSequence::bendTypes);
		cl.def_readwrite("bendPoints", &dialect::BendSequence::bendPoints);
		cl.def_readwrite("cost", &dialect::BendSequence::cost);
		cl.def_readwrite("incomingDirec", &dialect::BendSequence::incomingDirec);
		cl.def_readwrite("outgoingDirec", &dialect::BendSequence::outgoingDirec);
		cl.def("size", (unsigned long (dialect::BendSequence::*)() const) &dialect::BendSequence::size, "Report the number of bends in the sequence.\n\nC++: dialect::BendSequence::size() const --> unsigned long");
	}
	{ // dialect::AestheticBend file:libdialect/chains.h line:149
		pybind11::class_<dialect::AestheticBend, std::shared_ptr<dialect::AestheticBend>> cl(M("dialect"), "AestheticBend", "A bend point deliberately added to a connector route, for aesthetic reasons.");
		cl.def_readwrite("edge", &dialect::AestheticBend::edge);
		cl.def_readwrite("bendNode", &dialect::AestheticBend::bendNode);
		cl.def_readwrite("nbrNode1", &dialect::AestheticBend::nbrNode1);
		cl.def_readwrite("nbrNode2", &dialect::AestheticBend::nbrNode2);
		cl.def("addBendToEdge", (void (dialect::AestheticBend::*)()) &dialect::AestheticBend::addBendToEdge, "Add the bend node to the edge.\n\nC++: dialect::AestheticBend::addBendToEdge() --> void");
	}
	{ // dialect::Chain file:libdialect/chains.h line:173
		pybind11::class_<dialect::Chain, std::shared_ptr<dialect::Chain>> cl(M("dialect"), "Chain", "A Chain is a sequence of degree-2 Nodes, possibly forming a cycle.\n\n This class, like everything defined in this header, is intended for use only with\n 4-planar orthogonal layouts.");
		cl.def( pybind11::init( [](){ return new dialect::Chain(); } ) );
		cl.def("bendCost", (double (dialect::Chain::*)(enum dialect::LinkShape, unsigned long) const) &dialect::Chain::bendCost, "Compute the cost of making a given bend shape at a given position in the chain,\n         given the current geometry.\n\n         If this chain is a cycle, the cost takes into account that the nodes are in\n         clockwise order.\n\n \n  A bent LinkShape.\n \n\n  A position in the chain from 0 to 2n-2 -- evens for nodes, odds for edges --\n                where n is the number of nodes in this chain.\n\nC++: dialect::Chain::bendCost(enum dialect::LinkShape, unsigned long) const --> double", pybind11::arg("bendType"), pybind11::arg("i0"));
		cl.def("size", (unsigned long (dialect::Chain::*)() const) &dialect::Chain::size, "Check how many nodes are in the chain.\n\nC++: dialect::Chain::size() const --> unsigned long");
		cl.def("computePossibleBendSequences", (int (dialect::Chain::*)() const) &dialect::Chain::computePossibleBendSequences, "Compute the possible bend sequences that this chain could have.\n\n         If \"no bends\" is a possibility, then we return a single BendSequence with\n         empty list of bend types.\n \n\n Vector of BendSequences indicating all the possibilites.\n\nC++: dialect::Chain::computePossibleBendSequences() const --> int");
		cl.def("takeShapeBasedConfiguration", (void (dialect::Chain::*)()) &dialect::Chain::takeShapeBasedConfiguration, "Give this chain an orthogonal configuration best fitting its present geometric shape.\n\n         This means we put the bend points in the most natural places, including the possibility\n         that they go where edges are (meaning a new bend point is constructed).\n\n         Thus, constraints at least are added to the underlying Graph's SepMatrix.\n         New Nodes (bend points) may also be added.\n\nC++: dialect::Chain::takeShapeBasedConfiguration() --> void");
		cl.def("addAestheticBendsToEdges", (void (dialect::Chain::*)()) &dialect::Chain::addAestheticBendsToEdges, "Add any aesthetic bends that were chosen during shape-based configuration, to the\n         Edges to which they belong.\n\nC++: dialect::Chain::addAestheticBendsToEdges() --> void");
	}
	{ // dialect::Side file:libdialect/faces.h line:43
		pybind11::class_<dialect::Side, std::shared_ptr<dialect::Side>> cl(M("dialect"), "Side", "A side of a Face. E.g. a rectangular Face has four Sides: north, south, east, and west.");
		cl.def( pybind11::init<int, enum dialect::CardinalDir>(), pybind11::arg("nodeSeq"), pybind11::arg("direc") );

		cl.def("getNodeSeq", (int (dialect::Side::*)() const) &dialect::Side::getNodeSeq, "Get a copy of the node sequence.\n\nC++: dialect::Side::getNodeSeq() const --> int");
		cl.def("containsNode", (bool (dialect::Side::*)(unsigned int) const) &dialect::Side::containsNode, "Check whether this Side contains a Node of the given ID.\n\nC++: dialect::Side::containsNode(unsigned int) const --> bool", pybind11::arg("id"));
		cl.def("findNodeIndex", (unsigned long (dialect::Side::*)(unsigned int) const) &dialect::Side::findNodeIndex, "Get the index of a Node in this Side's node sequence.\n \n\n  The ID of the Node to be found.\n \n\n  The index where the given ID occurs, or -1 if not found.\n\nC++: dialect::Side::findNodeIndex(unsigned int) const --> unsigned long", pybind11::arg("id"));
		cl.def("getForwardDirec", (enum dialect::CardinalDir (dialect::Side::*)() const) &dialect::Side::getForwardDirec, "Check the forward direction of this Side.\n\nC++: dialect::Side::getForwardDirec() const --> enum dialect::CardinalDir");
		cl.def("getAlignmentDimension", (enum vpsc::Dim (dialect::Side::*)() const) &dialect::Side::getAlignmentDimension, "Check the dimension in which this Side is aligned.\n\nC++: dialect::Side::getAlignmentDimension() const --> enum vpsc::Dim");
		cl.def("getCentreCoord", (double (dialect::Side::*)() const) &dialect::Side::getCentreCoord, "Check the centre coordinate of this Side.\n \n\n  We are working under the assumption that all Nodes belonging to a given\n        Side are centre-aligned!\n\nC++: dialect::Side::getCentreCoord() const --> double");
		cl.def("getNumRootNodes", (unsigned long (dialect::Side::*)() const) &dialect::Side::getNumRootNodes, "Check how many of the Nodes on this Side are marked as root nodes.\n\nC++: dialect::Side::getNumRootNodes() const --> unsigned long");
		cl.def("liesOppositeSegment", [](dialect::Side const &o, struct dialect::LineSegment & a0) -> bool { return o.liesOppositeSegment(a0); }, "", pybind11::arg("seg"));
		cl.def("liesOppositeSegment", (bool (dialect::Side::*)(struct dialect::LineSegment &, bool) const) &dialect::Side::liesOppositeSegment, "Check whether the closed interval spanned by this Side runs in the same\n         dimension as a given line segment, and overlaps it in projection onto\n         that dimension.\n \n\n  The LineSegment in question.\n \n\n  Set true if you want to instead intersect this Side's closed\n                          interval with the LineSegment's open interval.\n \n\n boolean\n\nC++: dialect::Side::liesOppositeSegment(struct dialect::LineSegment &, bool) const --> bool", pybind11::arg("seg"), pybind11::arg("openInterval"));
		cl.def("getFirstPtOppositeSegment", (class Avoid::Point (dialect::Side::*)(struct dialect::LineSegment &) const) &dialect::Side::getFirstPtOppositeSegment, "Compute the first point of the interval of this Side that lies opposite\n         a given line segment.\n \n\n  The LineSegment in question.\n \n\n  The Point.\n \n\n  Runtime error if this Side does not lie opposite the given segment.\n \n\n Side::liesOppositeSegment\n\nC++: dialect::Side::getFirstPtOppositeSegment(struct dialect::LineSegment &) const --> class Avoid::Point", pybind11::arg("seg"));
		cl.def("halfWidthOppositeSegment", (double (dialect::Side::*)(struct dialect::LineSegment &) const) &dialect::Side::halfWidthOppositeSegment, "Given a LineSegment, find that portion of this Side that lies opposite it,\n         (if any) and report the maximum half-width of the near half.\n \n\n  The LineSegment in question.\n \n\n  The desired half-width. Will be equal to -1 if the Side's interval does not intersect\n          that of the segment, or if it does but the two are in-line with one another.\n \n\n  The Edges of the Side are given the thickness value set for aligned edges in the underlying Graph.\n\nC++: dialect::Side::halfWidthOppositeSegment(struct dialect::LineSegment &) const --> double", pybind11::arg("seg"));
		cl.def("getTreePlacements", (const int & (dialect::Side::*)() const) &dialect::Side::getTreePlacements, "Read-only access to the set of TreePlacements that have been attached to this Side.\n\nC++: dialect::Side::getTreePlacements() const --> const int &", pybind11::return_value_policy::automatic);
	}
	// dialect::NexusPolarity file:libdialect/faces.h line:164
	pybind11::enum_<dialect::NexusPolarity>(M("dialect"), "NexusPolarity", "")
		.value("ENTER_FROM", dialect::NexusPolarity::ENTER_FROM)
		.value("EXIT_TO", dialect::NexusPolarity::EXIT_TO);

;

	{ // dialect::Nexus file:libdialect/faces.h line:182
		pybind11::class_<dialect::Nexus, std::shared_ptr<dialect::Nexus>> cl(M("dialect"), "Nexus", "Regarded as a member of a Face F, a Node u belongs to certain Sides si\n of F. As we traverse the face in the clockwise direction (i.e. so that the\n interior of the face is always to the /right/), each Side si gets a direction,\n and therefore may stand in one of eight relations to Node u: it may be /entering/\n or /exiting/, and this may be from or to any of the four cardinal compass directions.\n\n A single Side may stand in two such relations, as when the Node lies along\n the middle of the Side, or else in just one such relation, as when a Node\n lies at one end or the other.\n\n A Nexus represents a Node in this capacity as a \"joining point\" of several\n Sides of a Face. It stores eight \"slots\" that are either empty or else occupied by\n a Side object.");
		cl.def("getNeighboursOfADirection", (int (dialect::Nexus::*)(enum dialect::CompassDir)) &dialect::Nexus::getNeighboursOfADirection, "Find out what are the first objects you hit as you try sweeping both\n         clockwise and anticlockwise, starting from a given direction.\n \n\n  The given direction.\n \n\n  Set of Sides.\n \n\n  The size of the returned set will be either 0, 1, or 2, according to whether\n        the number of filled slots in this Nexus is 0, 1, or more, respectively.\n\nC++: dialect::Nexus::getNeighboursOfADirection(enum dialect::CompassDir) --> int", pybind11::arg("direc"));
	}
	{ // dialect::FaceSet file:libdialect/faces.h line:251
		pybind11::class_<dialect::FaceSet, std::shared_ptr<dialect::FaceSet>> cl(M("dialect"), "FaceSet", "Holds all the Face objects for a given 4-planar, orthogonal layout,\n and provides methods to use and manage them.");
		cl.def("getNumFaces", (unsigned long (dialect::FaceSet::*)()) &dialect::FaceSet::getNumFaces, "Check how many faces there are.\n\nC++: dialect::FaceSet::getNumFaces() --> unsigned long");
		cl.def("getAllTreePlacements", (int (dialect::FaceSet::*)()) &dialect::FaceSet::getAllTreePlacements, "After tree placements have actually been chosen and performed (i.e. trees have\n         been placed into faces), obtain a vector of all those TreePlacements that were\n         actually chosen.\n\nC++: dialect::FaceSet::getAllTreePlacements() --> int");
		cl.def("getFaces", (int (dialect::FaceSet::*)()) &dialect::FaceSet::getFaces, "Get a copy of the vector of Faces_SP's.\n\nC++: dialect::FaceSet::getFaces() --> int");
		cl.def("getNumTreesByGrowthDir", [](dialect::FaceSet const &o) -> int { return o.getNumTreesByGrowthDir(); }, "");
		cl.def("getNumTreesByGrowthDir", (int (dialect::FaceSet::*)(bool) const) &dialect::FaceSet::getNumTreesByGrowthDir, "After tree placements have been chosen and performed, get a count of trees\n         by growth direction.\n \n\n  Set true if for each tree you actually want to count its number\n                         of nodes. In other words, the final counts you get actually indicate\n                         the number of nodes in trees that grow in the given directions.\n\nC++: dialect::FaceSet::getNumTreesByGrowthDir(bool) const --> int", pybind11::arg("scaleBySize"));
	}
	{ // dialect::Face file:libdialect/faces.h line:306
		pybind11::class_<dialect::Face, std::shared_ptr<dialect::Face>> cl(M("dialect"), "Face", "Represents a single face of a 4-planar, orthogonal layout.");
		cl.def("initWithEdgeSeq", (void (dialect::Face::*)(const int &)) &dialect::Face::initWithEdgeSeq, "A method to build the Face, based on the clockwise sequence of \"edges\"\n         of which it is made up; here an \"edge\" is a mere IdPair.\n\nC++: dialect::Face::initWithEdgeSeq(const int &) --> void", pybind11::arg("edges"));
		cl.def("getNodeSeq", (int (dialect::Face::*)()) &dialect::Face::getNodeSeq, "Access the sequence (vector) of Nodes belonging to the Face,\n         in clockwise order.\n\nC++: dialect::Face::getNodeSeq() --> int");
		cl.def("getSides", (int (dialect::Face::*)()) &dialect::Face::getSides, "Get a copy of the vector of Sides.\n\nC++: dialect::Face::getSides() --> int");
		cl.def("getNexusLookup", (int (dialect::Face::*)()) &dialect::Face::getNexusLookup, "Get a copy of the Nexus lookup.\n\nC++: dialect::Face::getNexusLookup() --> int");
		cl.def("containsNodeIdSeq", (bool (dialect::Face::*)(int) const) &dialect::Face::containsNodeIdSeq, "Utility method, to test whether the Face contains a given sequence\n         of Node IDs, in clockwise cyclic order.\n\nC++: dialect::Face::containsNodeIdSeq(int) const --> bool", pybind11::arg("idSeq"));
		cl.def("id", (unsigned int (dialect::Face::*)() const) &dialect::Face::id, "Access the unique ID of a given instance.\n\n \n  The ID.\n\nC++: dialect::Face::id() const --> unsigned int");
		cl.def("isExternal", (bool (dialect::Face::*)() const) &dialect::Face::isExternal, "Check whether this is the external face or not.\n\nC++: dialect::Face::isExternal() const --> bool");
		cl.def("getNbrPairs", (int (dialect::Face::*)()) &dialect::Face::getNbrPairs, "Access the neighbour pairs.\n\nC++: dialect::Face::getNbrPairs() --> int");
		cl.def("applyProjSeq", (bool (dialect::Face::*)(class dialect::ProjSeq &)) &dialect::Face::applyProjSeq, "Convenience function for applying a ProjSeq with all the appropriate options.\n \n\n  The ProjSeq to be applied.\n \n\n boolean, saying whether all the projections were successful.\n\nC++: dialect::Face::applyProjSeq(class dialect::ProjSeq &) --> bool", pybind11::arg("ps"));
		cl.def("getAllSidesOppositeSegment", [](dialect::Face const &o, struct dialect::LineSegment & a0) -> int { return o.getAllSidesOppositeSegment(a0); }, "", pybind11::arg("seg"));
		cl.def("getAllSidesOppositeSegment", (int (dialect::Face::*)(struct dialect::LineSegment &, bool) const) &dialect::Face::getAllSidesOppositeSegment, "Get all the Sides of this Face that lie opposite a given LineSegment.\n \n\n  The LineSegment in question.\n \n\n  Set true if you want to consider the overlap with the LineSegment's\n                          open interval instead of closed (the default).\n \n\n  Vector of Sides.\n\nC++: dialect::Face::getAllSidesOppositeSegment(struct dialect::LineSegment &, bool) const --> int", pybind11::arg("seg"), pybind11::arg("openInterval"));
		cl.def("getAllTreePlacements", (int (dialect::Face::*)() const) &dialect::Face::getAllTreePlacements, "Get all TreePlacements that have been added to this Face.\n \n\n  Vector of TreePlacements.\n\nC++: dialect::Face::getAllTreePlacements() const --> int");
		cl.def("getSetOfAllTreePlacements", (int (dialect::Face::*)() const) &dialect::Face::getSetOfAllTreePlacements, "Get the set of all TreePlacements that have been added to this Face.\n \n\n  Set of TreePlacements.\n\nC++: dialect::Face::getSetOfAllTreePlacements() const --> int");
		cl.def("getAllTreePlacements", (void (dialect::Face::*)(int &) const) &dialect::Face::getAllTreePlacements, "Get all TreePlacements that have been added to this Face.\n \n\n  Vector of TreePlacements to which those belonging to this\n                  Face should be added.\n\nC++: dialect::Face::getAllTreePlacements(int &) const --> void", pybind11::arg("tps"));
		cl.def("getNumTreesByGrowthDir", [](dialect::Face const &o, int & a0) -> void { return o.getNumTreesByGrowthDir(a0); }, "", pybind11::arg("counts"));
		cl.def("getNumTreesByGrowthDir", (void (dialect::Face::*)(int &, bool) const) &dialect::Face::getNumTreesByGrowthDir, "After tree placements have been chosen and performed, get a count of trees\n         by growth direction.\n \n\n  Map into which the counts should be added.\n \n\n  Set true if for each tree you actually want to count its number\n                         of nodes. In other words, the final counts you get actually indicate\n                         the number of nodes in trees that grow in the given directions.\n\nC++: dialect::Face::getNumTreesByGrowthDir(int &, bool) const --> void", pybind11::arg("counts"), pybind11::arg("scaleBySize"));
	}
}
