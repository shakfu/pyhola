#include <functional>
#include <iterator>
#include <libdialect/chains.h>
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

	// dialect::shapeOfLink(class std::shared_ptr<class dialect::Node>) file:libdialect/chains.h line:109
	M("dialect").def("shapeOfLink", (enum dialect::LinkShape (*)(class std::shared_ptr<class dialect::Node>)) &dialect::shapeOfLink, "Determine the LinkShape for a given Node of degree 2.\n \n\n  The link whose shape is to be determined.\n \n\n  The LinkShape for the given node.\n \n\n  Runtime error if the given node is not of degree 2.\n\nC++: dialect::shapeOfLink(class std::shared_ptr<class dialect::Node>) --> enum dialect::LinkShape", pybind11::arg("link"));

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
		cl.def( pybind11::init<class std::shared_ptr<class dialect::Edge>, class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>>(), pybind11::arg("edge"), pybind11::arg("bendNode"), pybind11::arg("nbrNode1"), pybind11::arg("nbrNode2") );

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
		cl.def("getNode", (class std::shared_ptr<class dialect::Node> (dialect::Chain::*)(int) const) &dialect::Chain::getNode, "Get a Node according to its \"place\" in the Chain.\n\n Together with the getEdge function, this function allows us to have the indices\n 0, 1, 2, 3, ... refer to the first node in the chain, then the first edge, next node,\n next edge, and so on. Negative integers refer to left anchors.\n \n\n  An even integer from -2 to 2n, where n is the number of nodes in this chain.\n \n\n  Left anchor node for i == -2, self.nodes[i/2] for i from 0 to 2n-2, and right\n          anchor node for i == 2n.\n\nC++: dialect::Chain::getNode(int) const --> class std::shared_ptr<class dialect::Node>", pybind11::arg("i"));
		cl.def("getEdge", (class std::shared_ptr<class dialect::Edge> (dialect::Chain::*)(int) const) &dialect::Chain::getEdge, "Get an Edge according to its \"place\" in the Chain.\n\n Together with the getNode function, this function allows us to have the indices\n 0, 1, 2, 3, ... refer to the first node in the chain, then the first edge, next node,\n next edge, and so on. Negative integers refer to left anchors.\n \n\n  An odd integer from -1 to 2n-1, where n is the number of nodes in this chain.\n \n\n  Left anchor edge for i == -1, self.edges[(i-1)/2] for i from 1 to 2n-3, and right\n          anchor edge for i == 2n-1.\n\nC++: dialect::Chain::getEdge(int) const --> class std::shared_ptr<class dialect::Edge>", pybind11::arg("i"));
		cl.def("bendCost", (double (dialect::Chain::*)(enum dialect::LinkShape, unsigned long) const) &dialect::Chain::bendCost, "Compute the cost of making a given bend shape at a given position in the chain,\n         given the current geometry.\n\n         If this chain is a cycle, the cost takes into account that the nodes are in\n         clockwise order.\n\n \n  A bent LinkShape.\n \n\n  A position in the chain from 0 to 2n-2 -- evens for nodes, odds for edges --\n                where n is the number of nodes in this chain.\n\nC++: dialect::Chain::bendCost(enum dialect::LinkShape, unsigned long) const --> double", pybind11::arg("bendType"), pybind11::arg("i0"));
		cl.def("size", (unsigned long (dialect::Chain::*)() const) &dialect::Chain::size, "Check how many nodes are in the chain.\n\nC++: dialect::Chain::size() const --> unsigned long");
		cl.def("evaluateBendSequence", (void (dialect::Chain::*)(class std::shared_ptr<struct dialect::BendSequence>) const) &dialect::Chain::evaluateBendSequence, "For a given BendSequence, determine the best places for those bends to occur\n         in this Chain, and the costs of applying those constraints.\n \n\n  The BendSequence to be considered.\n                          Sequence of best places to make the bends is recorded in here,\n                          along with the total cost.\n\nC++: dialect::Chain::evaluateBendSequence(class std::shared_ptr<struct dialect::BendSequence>) const --> void", pybind11::arg("bendSeq"));
		cl.def("takeShapeBasedConfiguration", (void (dialect::Chain::*)()) &dialect::Chain::takeShapeBasedConfiguration, "Give this chain an orthogonal configuration best fitting its present geometric shape.\n\n         This means we put the bend points in the most natural places, including the possibility\n         that they go where edges are (meaning a new bend point is constructed).\n\n         Thus, constraints at least are added to the underlying Graph's SepMatrix.\n         New Nodes (bend points) may also be added.\n\nC++: dialect::Chain::takeShapeBasedConfiguration() --> void");
		cl.def("addAestheticBendsToEdges", (void (dialect::Chain::*)()) &dialect::Chain::addAestheticBendsToEdges, "Add any aesthetic bends that were chosen during shape-based configuration, to the\n         Edges to which they belong.\n\nC++: dialect::Chain::addAestheticBendsToEdges() --> void");
	}
	{ // dialect::Side file: line:43
		pybind11::class_<dialect::Side, std::shared_ptr<dialect::Side>> cl(M("dialect"), "Side", "A side of a Face. E.g. a rectangular Face has four Sides: north, south, east, and west.");
		cl.def( pybind11::init( [](dialect::Side const &o){ return new dialect::Side(o); } ) );
		cl.def("containsNode", (bool (dialect::Side::*)(unsigned int) const) &dialect::Side::containsNode, "Check whether this Side contains a Node of the given ID.\n\nC++: dialect::Side::containsNode(unsigned int) const --> bool", pybind11::arg("id"));
		cl.def("findNodeIndex", (unsigned long (dialect::Side::*)(unsigned int) const) &dialect::Side::findNodeIndex, "Get the index of a Node in this Side's node sequence.\n \n\n  The ID of the Node to be found.\n \n\n  The index where the given ID occurs, or -1 if not found.\n\nC++: dialect::Side::findNodeIndex(unsigned int) const --> unsigned long", pybind11::arg("id"));
		cl.def("getForwardDirec", (enum dialect::CardinalDir (dialect::Side::*)() const) &dialect::Side::getForwardDirec, "Check the forward direction of this Side.\n\nC++: dialect::Side::getForwardDirec() const --> enum dialect::CardinalDir");
		cl.def("getAlignmentDimension", (enum vpsc::Dim (dialect::Side::*)() const) &dialect::Side::getAlignmentDimension, "Check the dimension in which this Side is aligned.\n\nC++: dialect::Side::getAlignmentDimension() const --> enum vpsc::Dim");
		cl.def("firstNode", (class std::shared_ptr<class dialect::Node> (dialect::Side::*)() const) &dialect::Side::firstNode, "Get a pointer to the first Node on this Side.\n\nC++: dialect::Side::firstNode() const --> class std::shared_ptr<class dialect::Node>");
		cl.def("lastNode", (class std::shared_ptr<class dialect::Node> (dialect::Side::*)() const) &dialect::Side::lastNode, "Get a pointer to the last Node on this Side.\n\nC++: dialect::Side::lastNode() const --> class std::shared_ptr<class dialect::Node>");
		cl.def("toString", (std::string (dialect::Side::*)() const) &dialect::Side::toString, "Write a string representation.\n\nC++: dialect::Side::toString() const --> std::string");
		cl.def("getCentreCoord", (double (dialect::Side::*)() const) &dialect::Side::getCentreCoord, "Check the centre coordinate of this Side.\n \n\n  We are working under the assumption that all Nodes belonging to a given\n        Side are centre-aligned!\n\nC++: dialect::Side::getCentreCoord() const --> double");
		cl.def("getNumRootNodes", (unsigned long (dialect::Side::*)() const) &dialect::Side::getNumRootNodes, "Check how many of the Nodes on this Side are marked as root nodes.\n\nC++: dialect::Side::getNumRootNodes() const --> unsigned long");
		cl.def("addTreePlacement", (void (dialect::Side::*)(class std::shared_ptr<class dialect::TreePlacement>)) &dialect::Side::addTreePlacement, "Record a TreePlacement as having been placed on this Side.\n\nC++: dialect::Side::addTreePlacement(class std::shared_ptr<class dialect::TreePlacement>) --> void", pybind11::arg("tp"));
		cl.def("computeCollateralProjSeq", [](dialect::Side &o, class std::shared_ptr<class dialect::TreePlacement> const & a0) -> std::shared_ptr<class dialect::ProjSeq> { return o.computeCollateralProjSeq(a0); }, "", pybind11::arg("tp"));
		cl.def("computeCollateralProjSeq", (class std::shared_ptr<class dialect::ProjSeq> (dialect::Side::*)(class std::shared_ptr<class dialect::TreePlacement>, double)) &dialect::Side::computeCollateralProjSeq, "Compute a projection sequence to remove/prevent overlaps between the given\n         TreePlacement's tree box, and any existing tree boxes already on this Side,\n         as well as ordinary perimeter nodes on this Side.\n \n\n  The TreePlacement to be added to this Side.\n \n\n  Optional padding for the new tree box.\n \n\n  A ProjSeq representing the computed projection sequence.\n\nC++: dialect::Side::computeCollateralProjSeq(class std::shared_ptr<class dialect::TreePlacement>, double) --> class std::shared_ptr<class dialect::ProjSeq>", pybind11::arg("tp"), pybind11::arg("padding"));
		cl.def("closedInterval", (struct std::pair<double, double> (dialect::Side::*)() const) &dialect::Side::closedInterval, "Compute the closed interval [a, b], where a and b are the extreme coordinates\n         covered by this Side, up to the extremes of the boxes of the extreme Nodes.\n \n\n The closed interval covered by the Side.\n\nC++: dialect::Side::closedInterval() const --> struct std::pair<double, double>");
		cl.def("getIntervalOppositeSegment", [](dialect::Side const &o, struct dialect::LineSegment & a0) -> std::pair<double, double> { return o.getIntervalOppositeSegment(a0); }, "", pybind11::arg("seg"));
		cl.def("getIntervalOppositeSegment", (struct std::pair<double, double> (dialect::Side::*)(struct dialect::LineSegment &, bool) const) &dialect::Side::getIntervalOppositeSegment, "Compute the closed interval [a, b] that is the intersection of this Side's\n         closed interval with that of a given Segment.\n \n\n  The LineSegment in question.\n \n\n  Set true if you want to instead intersect this Side's closed\n                          interval with the LineSegment's open interval.\n \n\n  An interval representing the intersection.\n \n\n  Returns an empty interval (b < a) if the two intervals do not intersect, or\n        if the Side and the LineSegment are not aligned in the same dimension.\n\nC++: dialect::Side::getIntervalOppositeSegment(struct dialect::LineSegment &, bool) const --> struct std::pair<double, double>", pybind11::arg("seg"), pybind11::arg("openInterval"));
		cl.def("liesOppositeSegment", [](dialect::Side const &o, struct dialect::LineSegment & a0) -> bool { return o.liesOppositeSegment(a0); }, "", pybind11::arg("seg"));
		cl.def("liesOppositeSegment", (bool (dialect::Side::*)(struct dialect::LineSegment &, bool) const) &dialect::Side::liesOppositeSegment, "Check whether the closed interval spanned by this Side runs in the same\n         dimension as a given line segment, and overlaps it in projection onto\n         that dimension.\n \n\n  The LineSegment in question.\n \n\n  Set true if you want to instead intersect this Side's closed\n                          interval with the LineSegment's open interval.\n \n\n boolean\n\nC++: dialect::Side::liesOppositeSegment(struct dialect::LineSegment &, bool) const --> bool", pybind11::arg("seg"), pybind11::arg("openInterval"));
		cl.def("getFirstPtOppositeSegment", (class Avoid::Point (dialect::Side::*)(struct dialect::LineSegment &) const) &dialect::Side::getFirstPtOppositeSegment, "Compute the first point of the interval of this Side that lies opposite\n         a given line segment.\n \n\n  The LineSegment in question.\n \n\n  The Point.\n \n\n  Runtime error if this Side does not lie opposite the given segment.\n \n\n Side::liesOppositeSegment\n\nC++: dialect::Side::getFirstPtOppositeSegment(struct dialect::LineSegment &) const --> class Avoid::Point", pybind11::arg("seg"));
		cl.def("halfWidthOppositeSegment", (double (dialect::Side::*)(struct dialect::LineSegment &) const) &dialect::Side::halfWidthOppositeSegment, "Given a LineSegment, find that portion of this Side that lies opposite it,\n         (if any) and report the maximum half-width of the near half.\n \n\n  The LineSegment in question.\n \n\n  The desired half-width. Will be equal to -1 if the Side's interval does not intersect\n          that of the segment, or if it does but the two are in-line with one another.\n \n\n  The Edges of the Side are given the thickness value set for aligned edges in the underlying Graph.\n\nC++: dialect::Side::halfWidthOppositeSegment(struct dialect::LineSegment &) const --> double", pybind11::arg("seg"));
		cl.def("getTreePlacements", (const class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > & (dialect::Side::*)() const) &dialect::Side::getTreePlacements, "Read-only access to the set of TreePlacements that have been attached to this Side.\n\nC++: dialect::Side::getTreePlacements() const --> const class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > &", pybind11::return_value_policy::automatic);
	}
	// dialect::NexusPolarity file: line:164
	pybind11::enum_<dialect::NexusPolarity>(M("dialect"), "NexusPolarity", "")
		.value("ENTER_FROM", dialect::NexusPolarity::ENTER_FROM)
		.value("EXIT_TO", dialect::NexusPolarity::EXIT_TO);

;

}
