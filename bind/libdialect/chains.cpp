#include <libdialect/chains.h>
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

	// dialect::possibleCardinalDirections(int, int) file:libdialect/chains.h line:102
	M("dialect").def("possibleCardinalDirections", (int (*)(int, int)) &dialect::possibleCardinalDirections, "List the possible cardinal directions from node1 to node2, if they were to be\n         aligned non-aggressively.\n\nC++: dialect::possibleCardinalDirections(int, int) --> int", pybind11::arg("node1"), pybind11::arg("node2"));

	// dialect::shapeOfLink(int) file:libdialect/chains.h line:109
	M("dialect").def("shapeOfLink", (enum dialect::LinkShape (*)(int)) &dialect::shapeOfLink, "Determine the LinkShape for a given Node of degree 2.\n \n\n  The link whose shape is to be determined.\n \n\n  The LinkShape for the given node.\n \n\n  Runtime error if the given node is not of degree 2.\n\nC++: dialect::shapeOfLink(int) --> enum dialect::LinkShape", pybind11::arg("link"));

	{ // dialect::BendSequence file:libdialect/chains.h line:115
		pybind11::class_<dialect::BendSequence, std::shared_ptr<dialect::BendSequence>> cl(M("dialect"), "BendSequence", "A data structure for managing sequences of bend types, points at which these\n bends should occur (in a given Chain), cost of such a sequence of bends\n (for a given Chain), and incoming and outgoing Compass directions, for non-cycles.");
		cl.def( pybind11::init<int &>(), pybind11::arg("shapes") );

		cl.def( pybind11::init<int &, int, int>(), pybind11::arg("shapes"), pybind11::arg("inDir"), pybind11::arg("outDir") );

		cl.def_readwrite("bendTypes", &dialect::BendSequence::bendTypes);
		cl.def_readwrite("bendPoints", &dialect::BendSequence::bendPoints);
		cl.def_readwrite("cost", &dialect::BendSequence::cost);
		cl.def_readwrite("incomingDirec", &dialect::BendSequence::incomingDirec);
		cl.def_readwrite("outgoingDirec", &dialect::BendSequence::outgoingDirec);
		cl.def("size", (unsigned long (dialect::BendSequence::*)() const) &dialect::BendSequence::size, "Report the number of bends in the sequence.\n\nC++: dialect::BendSequence::size() const --> unsigned long");
	}
	{ // dialect::AestheticBend file:libdialect/chains.h line:149
		pybind11::class_<dialect::AestheticBend, std::shared_ptr<dialect::AestheticBend>> cl(M("dialect"), "AestheticBend", "A bend point deliberately added to a connector route, for aesthetic reasons.");
		cl.def( pybind11::init( [](){ return new dialect::AestheticBend(); } ) );
		cl.def( pybind11::init<int, int, int, int>(), pybind11::arg("edge"), pybind11::arg("bendNode"), pybind11::arg("nbrNode1"), pybind11::arg("nbrNode2") );

		cl.def_readwrite("edge", &dialect::AestheticBend::edge);
		cl.def_readwrite("bendNode", &dialect::AestheticBend::bendNode);
		cl.def_readwrite("nbrNode1", &dialect::AestheticBend::nbrNode1);
		cl.def_readwrite("nbrNode2", &dialect::AestheticBend::nbrNode2);
		cl.def("addBendToEdge", (void (dialect::AestheticBend::*)()) &dialect::AestheticBend::addBendToEdge, "Add the bend node to the edge.\n\nC++: dialect::AestheticBend::addBendToEdge() --> void");
	}
	{ // dialect::Chain file:libdialect/chains.h line:173
		pybind11::class_<dialect::Chain, std::shared_ptr<dialect::Chain>> cl(M("dialect"), "Chain", "A Chain is a sequence of degree-2 Nodes, possibly forming a cycle.\n\n This class, like everything defined in this header, is intended for use only with\n 4-planar orthogonal layouts.");
		cl.def( pybind11::init( [](){ return new dialect::Chain(); } ) );
		cl.def( pybind11::init( [](int const & a0, int const & a1){ return new dialect::Chain(a0, a1); } ), "doc" , pybind11::arg("G"), pybind11::arg("nodes"));
		cl.def( pybind11::init<int, int, bool>(), pybind11::arg("G"), pybind11::arg("nodes"), pybind11::arg("isCycle") );

		cl.def("getNode", (int (dialect::Chain::*)(int) const) &dialect::Chain::getNode, "Get a Node according to its \"place\" in the Chain.\n\n Together with the getEdge function, this function allows us to have the indices\n 0, 1, 2, 3, ... refer to the first node in the chain, then the first edge, next node,\n next edge, and so on. Negative integers refer to left anchors.\n \n\n  An even integer from -2 to 2n, where n is the number of nodes in this chain.\n \n\n  Left anchor node for i == -2, self.nodes[i/2] for i from 0 to 2n-2, and right\n          anchor node for i == 2n.\n\nC++: dialect::Chain::getNode(int) const --> int", pybind11::arg("i"));
		cl.def("getEdge", (int (dialect::Chain::*)(int) const) &dialect::Chain::getEdge, "Get an Edge according to its \"place\" in the Chain.\n\n Together with the getNode function, this function allows us to have the indices\n 0, 1, 2, 3, ... refer to the first node in the chain, then the first edge, next node,\n next edge, and so on. Negative integers refer to left anchors.\n \n\n  An odd integer from -1 to 2n-1, where n is the number of nodes in this chain.\n \n\n  Left anchor edge for i == -1, self.edges[(i-1)/2] for i from 1 to 2n-3, and right\n          anchor edge for i == 2n-1.\n\nC++: dialect::Chain::getEdge(int) const --> int", pybind11::arg("i"));
		cl.def("bendCost", (double (dialect::Chain::*)(enum dialect::LinkShape, unsigned long) const) &dialect::Chain::bendCost, "Compute the cost of making a given bend shape at a given position in the chain,\n         given the current geometry.\n\n         If this chain is a cycle, the cost takes into account that the nodes are in\n         clockwise order.\n\n \n  A bent LinkShape.\n \n\n  A position in the chain from 0 to 2n-2 -- evens for nodes, odds for edges --\n                where n is the number of nodes in this chain.\n\nC++: dialect::Chain::bendCost(enum dialect::LinkShape, unsigned long) const --> double", pybind11::arg("bendType"), pybind11::arg("i0"));
		cl.def("size", (unsigned long (dialect::Chain::*)() const) &dialect::Chain::size, "Check how many nodes are in the chain.\n\nC++: dialect::Chain::size() const --> unsigned long");
		cl.def("computePossibleBendSequences", (int (dialect::Chain::*)() const) &dialect::Chain::computePossibleBendSequences, "Compute the possible bend sequences that this chain could have.\n\n         If \"no bends\" is a possibility, then we return a single BendSequence with\n         empty list of bend types.\n \n\n Vector of BendSequences indicating all the possibilites.\n\nC++: dialect::Chain::computePossibleBendSequences() const --> int");
		cl.def("evaluateBendSequence", (void (dialect::Chain::*)(int) const) &dialect::Chain::evaluateBendSequence, "For a given BendSequence, determine the best places for those bends to occur\n         in this Chain, and the costs of applying those constraints.\n \n\n  The BendSequence to be considered.\n                          Sequence of best places to make the bends is recorded in here,\n                          along with the total cost.\n\nC++: dialect::Chain::evaluateBendSequence(int) const --> void", pybind11::arg("bendSeq"));
		cl.def("writeConfigSeq", (int (dialect::Chain::*)(int) const) &dialect::Chain::writeConfigSeq, "Determine the direction in which each edge in this chain should be configured,\n         in order to enforce a given bend sequence.\n \n\n  The desired bend sequence. Its bendpoints are indices into this\n Chain's sequence of nodes AND edges -- thus even indices for nodes and odd indices for\n edges. Its corresponding bendtypes are the types of bends that should occur at those indices.\n \n\n  A \"chain configuration sequence,\" which looks like\n                                 [ c0, c1, ..., cm-1 ]\n where m is the number of edges to be configured, which is n - 1 if this is not a cycle,\n and n if it is -- n the number of nodes in the chain -- and each ci is a pair of CardinalDirs.\n\n When ci == [ d, d ], then edge i is simply to be configured in direction d.\n When ci == [d1, d2] with d1 != d2, then edge i is to be replaced by a bend point, which we go\n into in direction d1, and come out of in direction d2.\n\nC++: dialect::Chain::writeConfigSeq(int) const --> int", pybind11::arg("bendSeq"));
		cl.def("takeShapeBasedConfiguration", (void (dialect::Chain::*)()) &dialect::Chain::takeShapeBasedConfiguration, "Give this chain an orthogonal configuration best fitting its present geometric shape.\n\n         This means we put the bend points in the most natural places, including the possibility\n         that they go where edges are (meaning a new bend point is constructed).\n\n         Thus, constraints at least are added to the underlying Graph's SepMatrix.\n         New Nodes (bend points) may also be added.\n\nC++: dialect::Chain::takeShapeBasedConfiguration() --> void");
		cl.def("addAestheticBendsToEdges", (void (dialect::Chain::*)()) &dialect::Chain::addAestheticBendsToEdges, "Add any aesthetic bends that were chosen during shape-based configuration, to the\n         Edges to which they belong.\n\nC++: dialect::Chain::addAestheticBendsToEdges() --> void");
	}
	// dialect::GapType file:libdialect/constraints.h line:48
	pybind11::enum_<dialect::GapType>(M("dialect"), "GapType", "")
		.value("CENTRE", dialect::GapType::CENTRE)
		.value("BDRY", dialect::GapType::BDRY);

;

	// dialect::SepDir file:libdialect/constraints.h line:55
	pybind11::enum_<dialect::SepDir>(M("dialect"), "SepDir", "")
		.value("EAST", dialect::SepDir::EAST)
		.value("SOUTH", dialect::SepDir::SOUTH)
		.value("WEST", dialect::SepDir::WEST)
		.value("NORTH", dialect::SepDir::NORTH)
		.value("RIGHT", dialect::SepDir::RIGHT)
		.value("DOWN", dialect::SepDir::DOWN)
		.value("LEFT", dialect::SepDir::LEFT)
		.value("UP", dialect::SepDir::UP);

;

	// dialect::SepType file:libdialect/constraints.h line:62
	pybind11::enum_<dialect::SepType>(M("dialect"), "SepType", "")
		.value("NONE", dialect::SepType::NONE)
		.value("EQ", dialect::SepType::EQ)
		.value("INEQ", dialect::SepType::INEQ);

;

	// dialect::negateSepDir(enum dialect::SepDir) file:libdialect/constraints.h line:71
	M("dialect").def("negateSepDir", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::negateSepDir, "C++: dialect::negateSepDir(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::sepDirIsCardinal(enum dialect::SepDir) file:libdialect/constraints.h line:73
	M("dialect").def("sepDirIsCardinal", (bool (*)(enum dialect::SepDir)) &dialect::sepDirIsCardinal, "C++: dialect::sepDirIsCardinal(enum dialect::SepDir) --> bool", pybind11::arg("sd"));

	// dialect::sepDirToCardinalDir(enum dialect::SepDir) file:libdialect/constraints.h line:75
	M("dialect").def("sepDirToCardinalDir", (int (*)(enum dialect::SepDir)) &dialect::sepDirToCardinalDir, "C++: dialect::sepDirToCardinalDir(enum dialect::SepDir) --> int", pybind11::arg("sd"));

	// dialect::cardinalDirToSepDir(int) file:libdialect/constraints.h line:77
	M("dialect").def("cardinalDirToSepDir", (enum dialect::SepDir (*)(int)) &dialect::cardinalDirToSepDir, "C++: dialect::cardinalDirToSepDir(int) --> enum dialect::SepDir", pybind11::arg("dir"));

	// dialect::lateralWeakening(enum dialect::SepDir) file:libdialect/constraints.h line:79
	M("dialect").def("lateralWeakening", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::lateralWeakening, "C++: dialect::lateralWeakening(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::cardinalStrengthening(enum dialect::SepDir) file:libdialect/constraints.h line:81
	M("dialect").def("cardinalStrengthening", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::cardinalStrengthening, "C++: dialect::cardinalStrengthening(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::SepTransform file:libdialect/constraints.h line:83
	pybind11::enum_<dialect::SepTransform>(M("dialect"), "SepTransform", "")
		.value("ROTATE90CW", dialect::SepTransform::ROTATE90CW)
		.value("ROTATE90ACW", dialect::SepTransform::ROTATE90ACW)
		.value("ROTATE180", dialect::SepTransform::ROTATE180)
		.value("FLIPV", dialect::SepTransform::FLIPV)
		.value("FLIPH", dialect::SepTransform::FLIPH)
		.value("FLIPMD", dialect::SepTransform::FLIPMD)
		.value("FLIPOD", dialect::SepTransform::FLIPOD);

;

	{ // dialect::SepPair file:libdialect/constraints.h line:104
		pybind11::class_<dialect::SepPair, std::shared_ptr<dialect::SepPair>> cl(M("dialect"), "SepPair", "");
		cl.def( pybind11::init( [](){ return new dialect::SepPair(); } ) );
		cl.def_readwrite("src", &dialect::SepPair::src);
		cl.def_readwrite("tgt", &dialect::SepPair::tgt);
		cl.def_readwrite("xgt", &dialect::SepPair::xgt);
		cl.def_readwrite("ygt", &dialect::SepPair::ygt);
		cl.def_readwrite("xst", &dialect::SepPair::xst);
		cl.def_readwrite("yst", &dialect::SepPair::yst);
		cl.def_readwrite("xgap", &dialect::SepPair::xgap);
		cl.def_readwrite("ygap", &dialect::SepPair::ygap);
		cl.def_readwrite("tglfPrecision", &dialect::SepPair::tglfPrecision);
		cl.def_readwrite("flippedRetrieval", &dialect::SepPair::flippedRetrieval);
		cl.def("addSep", (void (dialect::SepPair::*)(enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double)) &dialect::SepPair::addSep, "Add a constraint.\n \n\n  addSep method of SepMatrix class\n\nC++: dialect::SepPair::addSep(enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double) --> void", pybind11::arg("gt"), pybind11::arg("sd"), pybind11::arg("st"), pybind11::arg("gap"));
		cl.def("transform", (void (dialect::SepPair::*)(enum dialect::SepTransform)) &dialect::SepPair::transform, "Apply a transformation.\n\nC++: dialect::SepPair::transform(enum dialect::SepTransform) --> void", pybind11::arg("tf"));
		cl.def("isVerticalCardinal", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isVerticalCardinal, "Check whether this SepPair represents a separation in a vertical cardinal compass direction.\n\nC++: dialect::SepPair::isVerticalCardinal() const --> bool");
		cl.def("isHorizontalCardinal", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isHorizontalCardinal, "Check whether this SepPair represents a separation in a horizontal cardinal compass direction.\n\nC++: dialect::SepPair::isHorizontalCardinal() const --> bool");
		cl.def("isVAlign", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isVAlign, "Check whether this SepPair represents a vertical alignment.\n\nC++: dialect::SepPair::isVAlign() const --> bool");
		cl.def("isHAlign", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isHAlign, "Check whether this SepPair represents a horizontal alignment.\n\nC++: dialect::SepPair::isHAlign() const --> bool");
		cl.def("isCardinal", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isCardinal, "Check whether this SepPair represents a separation in a cardinal compass direction.\n\nC++: dialect::SepPair::isCardinal() const --> bool");
		cl.def("getCardinalDir", (int (dialect::SepPair::*)() const) &dialect::SepPair::getCardinalDir, "Get the cardinal direction of this separation.\n \n\n  Runtime exception if this separation is not cardinal.\n \n\n The cardinal direction.\n\nC++: dialect::SepPair::getCardinalDir() const --> int");
		cl.def("roundGapsUpAbs", (void (dialect::SepPair::*)()) &dialect::SepPair::roundGapsUpAbs, "Round gaps upward in absolute value. Useful when trying to move nodes to integer coords.\n\n E.g., -2.3 goes to -3.0; 2.3 goes to 3.0.\n\nC++: dialect::SepPair::roundGapsUpAbs() --> void");
		cl.def("writeTglf", (int (dialect::SepPair::*)(int, const class dialect::SepMatrix &) const) &dialect::SepPair::writeTglf, "Write a representation of this constraint in the format of\n         the SEPCO'S section of the TGLF file format.\n \n\n  Mapping from internal Node IDs to external IDs for the TGLF output.\n\nC++: dialect::SepPair::writeTglf(int, const class dialect::SepMatrix &) const --> int", pybind11::arg("id2ext"), pybind11::arg("m"));
		cl.def("hasConstraintInDim", (bool (dialect::SepPair::*)(int) const) &dialect::SepPair::hasConstraintInDim, "Check whether there is a constraint in a given dimension.\n\nC++: dialect::SepPair::hasConstraintInDim(int) const --> bool", pybind11::arg("dim"));
		cl.def("generateSeparationConstraint", (int * (dialect::SepPair::*)(const int, const struct dialect::ColaGraphRep &, class dialect::SepMatrix *, int &)) &dialect::SepPair::generateSeparationConstraint, "Write the VPSC constraint in one dimension.\n\nC++: dialect::SepPair::generateSeparationConstraint(const int, const struct dialect::ColaGraphRep &, class dialect::SepMatrix *, int &) --> int *", pybind11::return_value_policy::automatic, pybind11::arg("dim"), pybind11::arg("cgr"), pybind11::arg("m"), pybind11::arg("vs"));
	}
}
