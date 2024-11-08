#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/geomtypes.h>
#include <libcola/cluster.h>
#include <libcola/cola.h>
#include <libcola/compound_constraints.h>
#include <libdialect/aca.h>
#include <libdialect/chains.h>
#include <libdialect/constraints.h>
#include <libdialect/faces.h>
#include <libdialect/graphs.h>
#include <libdialect/ortho.h>
#include <libdialect/treeplacement.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
#include <utility>
#include <valarray>
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

void bind_libdialect_aca(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::ACALayout file:libdialect/aca.h line:124
		pybind11::class_<dialect::ACALayout, std::shared_ptr<dialect::ACALayout>> cl(M("dialect"), "ACALayout", "Implements the Adaptive Constrained Alignment (ACA) algorithm.\n\n See\n Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.\n \"Incremental grid-like layout using soft and hard constraints.\" In Graph\n Drawing 2013, pp. 448-459. Springer International Publishing, 2013.");
		cl.def( pybind11::init( [](dialect::ACALayout const &o){ return new dialect::ACALayout(o); } ) );
		cl.def_readwrite("aStateBeforeChop", &dialect::ACALayout::aStateBeforeChop);
		cl.def("createAlignments", (void (dialect::ACALayout::*)()) &dialect::ACALayout::createAlignments, "Creates alignments.\n\n This is the main functionality of ACA. This function should be called\n on an existing layout in order to greedily align edges until any further\n alignments would create edge overlaps.\n\n If the graph does not have an initial layout already, then the 'layout'\n function may be called instead.\n\nC++: dialect::ACALayout::createAlignments() --> void");
		cl.def("createOneAlignment", (bool (dialect::ACALayout::*)()) &dialect::ACALayout::createOneAlignment, "Creates one alignment.\n\n Call this function instead of createAlignments in order to create just\n one alignment and then stop. The return value is true if and only if a\n new alignment was actually created.\n\n Thus, repeatedly calling this function until it returns false achieves\n the exact same result as simply calling createAlignments.\n\nC++: dialect::ACALayout::createOneAlignment() --> bool");
		cl.def("layout", (void (dialect::ACALayout::*)()) &dialect::ACALayout::layout, "Do an initial stress-minimising layout, and then create alignments.\n\n This is a convenience function which first does a constrained force-directed\n layout of the given graph, and then calls the 'createAlignments' function.\n\nC++: dialect::ACALayout::layout() --> void");
		cl.def("removeOverlaps", (void (dialect::ACALayout::*)()) &dialect::ACALayout::removeOverlaps, "Do an FD layout with overlap prevention, then stop.\n\nC++: dialect::ACALayout::removeOverlaps() --> void");
		cl.def("layoutWithCurrentConstraints", (void (dialect::ACALayout::*)()) &dialect::ACALayout::layoutWithCurrentConstraints, "Run layout with current constraints, and with or without overlap\n prevention, as per the current settings.\n\nC++: dialect::ACALayout::layoutWithCurrentConstraints() --> void");
		cl.def("updateGraph", (void (dialect::ACALayout::*)()) &dialect::ACALayout::updateGraph, "For forward compatibility (i.e. with Graphs), we offer a convenience method\n        to update the Graph (when we have one) with the positions and constraints chosen\n        by this object.\n\nC++: dialect::ACALayout::updateGraph() --> void");
		cl.def("updateSepMatrix", (void (dialect::ACALayout::*)()) &dialect::ACALayout::updateSepMatrix, "Update the SepMatrix of the Graph on which this ACALayout was built (if any).\n\nC++: dialect::ACALayout::updateSepMatrix() --> void");
		cl.def("getFDLayout", (class cola::ConstrainedFDLayout * (dialect::ACALayout::*)()) &dialect::ACALayout::getFDLayout, "C++: dialect::ACALayout::getFDLayout() --> class cola::ConstrainedFDLayout *", pybind11::return_value_policy::automatic);
		cl.def("addBendPointPenalty", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::addBendPointPenalty, "Control whether we avoid making bend points.\n\n We refer to a node of degree 2 as a \"bend point\" when one of its\n edges has been aligned horizontally and the other vertically.\n\n The default value of addBendPointPenalty is true. In this case a penalty\n score is added when choosing the next alignment in order to postpone\n creating bend points until no other choices remain.\n\n If set to false then there is no penalty score to postpone the creation\n of bend points.\n\n When there is both bend point penalty and leaf penalty (see below), then\n bend points will be created before leaf edges are aligned. This can be\n reversed by altering the BP_PENALTY and LEAF_PENALTY constants.\n\nC++: dialect::ACALayout::addBendPointPenalty(bool) --> void", pybind11::arg("b"));
		cl.def("favourLongEdges", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::favourLongEdges, "Prefer long edges instead of ones that are close to aligned.\n\n This defaults to 'false', in which case ACA prefers to align edges that\n are almost aligned already. When set to 'true' it will instead choose\n the longest edges first.\n\nC++: dialect::ACALayout::favourLongEdges(bool) --> void", pybind11::arg("b"));
		cl.def("postponeLeaves", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::postponeLeaves, "Say whether alignment of leaf edges should be saved for last.\n\n The default value is true.\n\nC++: dialect::ACALayout::postponeLeaves(bool) --> void", pybind11::arg("b"));
		cl.def("useNonLeafDegree", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::useNonLeafDegree, "Say whether leaves should be counted when computing node degrees.\n\n The default value is true.\n\n This setting matters only if addBendPointPenalty is set to true.\n In that case, if useNonLeafDegree is also true then the nodes identified\n as potential bend points will be those having exactly 2 /non-leaf/ neighbours.\n\n When there is both leaf penalty and bend point penalty (see above), then\n bend points will be created before leaf edges are aligned. This can be\n reversed by altering the BP_PENALTY and LEAF_PENALTY constants.\n\nC++: dialect::ACALayout::useNonLeafDegree(bool) --> void", pybind11::arg("b"));
		cl.def("allAtOnce", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::allAtOnce, "Say whether alignment choices should alternate with stress\n        minimisation steps.\n\n The default value of allAtOnce is false. In this case, after each new\n alignment is chosen, stress is again minimised before choosing the\n next one.\n\n If you set allAtOnce to true, then all the alignments will be chosen based\n on the initial layout, and then they will all be applied at once.\n\nC++: dialect::ACALayout::allAtOnce(bool) --> void", pybind11::arg("b"));
		cl.def("aggressiveOrdering", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::aggressiveOrdering, "Say whether to consider changing orthogonal ordering of nodes.\n\n The default value is false. In that case, consider a pair of nodes\n u, v where v currently lies to the southeast of u. Then when ACA\n considers aligning u and v it will only consider putting v east or\n south of u; it will not consider reversing their current ordering in\n either dimension.\n\n In the same example, if you set aggressiveOrdering to true, then ACA\n will also consider putting v north and west of u.\n\n In the exceptional case of a node v lying, say, precisely east of a node\n u despite not being constrained to that alignment, then ACA will consider\n placing v east, north, and south of u even with aggressiveOrdering set\n to false. (But it will consider west only with it set to true.)\n\nC++: dialect::ACALayout::aggressiveOrdering(bool) --> void", pybind11::arg("b"));
		cl.def("setAvoidNodeOverlaps", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::setAvoidNodeOverlaps, "Specifies whether non-overlap constraints should be\n         automatically generated between all nodes.\n\n \n     New boolean value for this option.\n\nC++: dialect::ACALayout::setAvoidNodeOverlaps(bool) --> void", pybind11::arg("avoidOverlaps"));
		cl.def("setClusterHierarchy", (void (dialect::ACALayout::*)(class cola::RootCluster *)) &dialect::ACALayout::setClusterHierarchy, "sets the cluster hierarchy of the underlying FDLayout.\n\nC++: dialect::ACALayout::setClusterHierarchy(class cola::RootCluster *) --> void", pybind11::arg("rc"));
		cl.def("edgeIsAligned", (bool (dialect::ACALayout::*)(int) const) &dialect::ACALayout::edgeIsAligned, "Check whether an edge is aligned.\n\n Pass the index of the edge. The returned boolean says whether ACA aligned this edge.\n\nC++: dialect::ACALayout::edgeIsAligned(int) const --> bool", pybind11::arg("j"));
		cl.def("nodesAreAligned", (bool (dialect::ACALayout::*)(int, int) const) &dialect::ACALayout::nodesAreAligned, "C++: dialect::ACALayout::nodesAreAligned(int, int) const --> bool", pybind11::arg("i"), pybind11::arg("j"));
		cl.def("layoutPeriod", (void (dialect::ACALayout::*)(unsigned int)) &dialect::ACALayout::layoutPeriod, "C++: dialect::ACALayout::layoutPeriod(unsigned int) --> void", pybind11::arg("p"));
		cl.def("doFinalLayout", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::doFinalLayout, "C++: dialect::ACALayout::doFinalLayout(bool) --> void", pybind11::arg("b"));
		cl.def("initOrdAlign", (struct dialect::OrderedAlignment * (dialect::ACALayout::*)(int, enum dialect::ACASepFlag) const) &dialect::ACALayout::initOrdAlign, "C++: dialect::ACALayout::initOrdAlign(int, enum dialect::ACASepFlag) const --> struct dialect::OrderedAlignment *", pybind11::return_value_policy::automatic, pybind11::arg("j"), pybind11::arg("sf"));
		cl.def("initOrdAlign", [](dialect::ACALayout const &o, int const & a0, int const & a1, enum dialect::ACASepFlag const & a2) -> dialect::OrderedAlignment * { return o.initOrdAlign(a0, a1, a2); }, "", pybind11::return_value_policy::automatic, pybind11::arg("s"), pybind11::arg("t"), pybind11::arg("sf"));
		cl.def("initOrdAlign", (struct dialect::OrderedAlignment * (dialect::ACALayout::*)(int, int, enum dialect::ACASepFlag, int) const) &dialect::ACALayout::initOrdAlign, "C++: dialect::ACALayout::initOrdAlign(int, int, enum dialect::ACASepFlag, int) const --> struct dialect::OrderedAlignment *", pybind11::return_value_policy::automatic, pybind11::arg("s"), pybind11::arg("t"), pybind11::arg("sf"), pybind11::arg("edgeIndex"));
		cl.def("mostRecentOA", (struct dialect::OrderedAlignment * (dialect::ACALayout::*)()) &dialect::ACALayout::mostRecentOA, "C++: dialect::ACALayout::mostRecentOA() --> struct dialect::OrderedAlignment *", pybind11::return_value_policy::automatic);
	}
	// dialect::LinkShape file:libdialect/chains.h line:47
	pybind11::enum_<dialect::LinkShape>(M("dialect"), "LinkShape", "In a 4-planar orthogonal layout, a link has one of six possible shapes, depending\n on which two of its four sides are the ones where its edges meet it.\n For example, if one edge enters from the south, and the other from the east, then\n this link is shaped like the top-left corner of a box.\n This enum names the six possible configurations.")
		.value("TLC", dialect::LinkShape::TLC)
		.value("H", dialect::LinkShape::H)
		.value("BLC", dialect::LinkShape::BLC)
		.value("TRC", dialect::LinkShape::TRC)
		.value("V", dialect::LinkShape::V)
		.value("BRC", dialect::LinkShape::BRC);

;

	{ // dialect::BendSequence file:libdialect/chains.h line:115
		pybind11::class_<dialect::BendSequence, std::shared_ptr<dialect::BendSequence>> cl(M("dialect"), "BendSequence", "A data structure for managing sequences of bend types, points at which these\n bends should occur (in a given Chain), cost of such a sequence of bends\n (for a given Chain), and incoming and outgoing Compass directions, for non-cycles.");
		cl.def( pybind11::init( [](dialect::BendSequence const &o){ return new dialect::BendSequence(o); } ) );
		cl.def_readwrite("bendTypes", &dialect::BendSequence::bendTypes);
		cl.def_readwrite("bendPoints", &dialect::BendSequence::bendPoints);
		cl.def_readwrite("cost", &dialect::BendSequence::cost);
		cl.def_readwrite("incomingDirec", &dialect::BendSequence::incomingDirec);
		cl.def_readwrite("outgoingDirec", &dialect::BendSequence::outgoingDirec);
		cl.def("size", (unsigned long (dialect::BendSequence::*)() const) &dialect::BendSequence::size, "Report the number of bends in the sequence.\n\nC++: dialect::BendSequence::size() const --> unsigned long");
	}
	{ // dialect::AestheticBend file:libdialect/chains.h line:149
		pybind11::class_<dialect::AestheticBend, std::shared_ptr<dialect::AestheticBend>> cl(M("dialect"), "AestheticBend", "A bend point deliberately added to a connector route, for aesthetic reasons.");
		cl.def( pybind11::init( [](dialect::AestheticBend const &o){ return new dialect::AestheticBend(o); } ) );
		cl.def_readwrite("edge", &dialect::AestheticBend::edge);
		cl.def_readwrite("bendNode", &dialect::AestheticBend::bendNode);
		cl.def_readwrite("nbrNode1", &dialect::AestheticBend::nbrNode1);
		cl.def_readwrite("nbrNode2", &dialect::AestheticBend::nbrNode2);
		cl.def("addBendToEdge", (void (dialect::AestheticBend::*)()) &dialect::AestheticBend::addBendToEdge, "Add the bend node to the edge.\n\nC++: dialect::AestheticBend::addBendToEdge() --> void");
	}
	{ // dialect::Chain file:libdialect/chains.h line:173
		pybind11::class_<dialect::Chain, std::shared_ptr<dialect::Chain>> cl(M("dialect"), "Chain", "A Chain is a sequence of degree-2 Nodes, possibly forming a cycle.\n\n This class, like everything defined in this header, is intended for use only with\n 4-planar orthogonal layouts.");
		cl.def( pybind11::init( [](dialect::Chain const &o){ return new dialect::Chain(o); } ) );
		cl.def("bendCost", (double (dialect::Chain::*)(enum dialect::LinkShape, unsigned long) const) &dialect::Chain::bendCost, "Compute the cost of making a given bend shape at a given position in the chain,\n         given the current geometry.\n\n         If this chain is a cycle, the cost takes into account that the nodes are in\n         clockwise order.\n\n \n  A bent LinkShape.\n \n\n  A position in the chain from 0 to 2n-2 -- evens for nodes, odds for edges --\n                where n is the number of nodes in this chain.\n\nC++: dialect::Chain::bendCost(enum dialect::LinkShape, unsigned long) const --> double", pybind11::arg("bendType"), pybind11::arg("i0"));
		cl.def("size", (unsigned long (dialect::Chain::*)() const) &dialect::Chain::size, "Check how many nodes are in the chain.\n\nC++: dialect::Chain::size() const --> unsigned long");
		cl.def("takeShapeBasedConfiguration", (void (dialect::Chain::*)()) &dialect::Chain::takeShapeBasedConfiguration, "Give this chain an orthogonal configuration best fitting its present geometric shape.\n\n         This means we put the bend points in the most natural places, including the possibility\n         that they go where edges are (meaning a new bend point is constructed).\n\n         Thus, constraints at least are added to the underlying Graph's SepMatrix.\n         New Nodes (bend points) may also be added.\n\nC++: dialect::Chain::takeShapeBasedConfiguration() --> void");
		cl.def("addAestheticBendsToEdges", (void (dialect::Chain::*)()) &dialect::Chain::addAestheticBendsToEdges, "Add any aesthetic bends that were chosen during shape-based configuration, to the\n         Edges to which they belong.\n\nC++: dialect::Chain::addAestheticBendsToEdges() --> void");
	}
	{ // dialect::Side file:libdialect/faces.h line:43
		pybind11::class_<dialect::Side, std::shared_ptr<dialect::Side>> cl(M("dialect"), "Side", "A side of a Face. E.g. a rectangular Face has four Sides: north, south, east, and west.");
		cl.def( pybind11::init( [](dialect::Side const &o){ return new dialect::Side(o); } ) );
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
	}
}
