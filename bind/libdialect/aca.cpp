#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libcola/cluster.h>
#include <libcola/cola.h>
#include <libcola/compound_constraints.h>
#include <libdialect/aca.h>
#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/ortho.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
#include <string_view>
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
	// dialect::ACAFlag file:libdialect/aca.h line:43
	pybind11::enum_<dialect::ACAFlag>(M("dialect"), "ACAFlag", pybind11::arithmetic(), "")
		.value("ACAHORIZ", dialect::ACAHORIZ)
		.value("ACAVERT", dialect::ACAVERT)
		.value("ACADELIB", dialect::ACADELIB)
		.value("ACACONN", dialect::ACACONN)
		.export_values();

;

	// dialect::ACASepFlag file:libdialect/aca.h line:50
	pybind11::enum_<dialect::ACASepFlag>(M("dialect"), "ACASepFlag", pybind11::arithmetic(), "")
		.value("ACANOSEP", dialect::ACANOSEP)
		.value("ACANORTH", dialect::ACANORTH)
		.value("ACAEAST", dialect::ACAEAST)
		.value("ACASOUTH", dialect::ACASOUTH)
		.value("ACAWEST", dialect::ACAWEST)
		.value("ACANORTHEAST", dialect::ACANORTHEAST)
		.value("ACASOUTHEAST", dialect::ACASOUTHEAST)
		.value("ACANORTHWEST", dialect::ACANORTHWEST)
		.value("ACASOUTHWEST", dialect::ACASOUTHWEST)
		.value("ACANORTHSOUTH", dialect::ACANORTHSOUTH)
		.value("ACAEASTWEST", dialect::ACAEASTWEST)
		.value("ACANOTNORTH", dialect::ACANOTNORTH)
		.value("ACANOTEAST", dialect::ACANOTEAST)
		.value("ACANOTSOUTH", dialect::ACANOTSOUTH)
		.value("ACANOTWEST", dialect::ACANOTWEST)
		.value("ACAALLSEP", dialect::ACAALLSEP)
		.export_values();

;

	// dialect::negateSepFlag(enum dialect::ACASepFlag) file:libdialect/aca.h line:74
	M("dialect").def("negateSepFlag", (enum dialect::ACASepFlag (*)(enum dialect::ACASepFlag)) &dialect::negateSepFlag, "C++: dialect::negateSepFlag(enum dialect::ACASepFlag) --> enum dialect::ACASepFlag", pybind11::arg("sf"));

	// dialect::sepToAlignFlag(enum dialect::ACASepFlag) file:libdialect/aca.h line:75
	M("dialect").def("sepToAlignFlag", (enum dialect::ACAFlag (*)(enum dialect::ACASepFlag)) &dialect::sepToAlignFlag, "C++: dialect::sepToAlignFlag(enum dialect::ACASepFlag) --> enum dialect::ACAFlag", pybind11::arg("sf"));

	// dialect::perpAlignFlag(enum dialect::ACAFlag) file:libdialect/aca.h line:76
	M("dialect").def("perpAlignFlag", (enum dialect::ACAFlag (*)(enum dialect::ACAFlag)) &dialect::perpAlignFlag, "C++: dialect::perpAlignFlag(enum dialect::ACAFlag) --> enum dialect::ACAFlag", pybind11::arg("af"));

	// dialect::vectorToSepFlag(double, double) file:libdialect/aca.h line:77
	M("dialect").def("vectorToSepFlag", (enum dialect::ACASepFlag (*)(double, double)) &dialect::vectorToSepFlag, "C++: dialect::vectorToSepFlag(double, double) --> enum dialect::ACASepFlag", pybind11::arg("dx"), pybind11::arg("dy"));

	// dialect::propsedSepConflictsWithExistingPosition(enum dialect::ACASepFlag, enum dialect::ACASepFlag) file:libdialect/aca.h line:78
	M("dialect").def("propsedSepConflictsWithExistingPosition", (bool (*)(enum dialect::ACASepFlag, enum dialect::ACASepFlag)) &dialect::propsedSepConflictsWithExistingPosition, "C++: dialect::propsedSepConflictsWithExistingPosition(enum dialect::ACASepFlag, enum dialect::ACASepFlag) --> bool", pybind11::arg("pro"), pybind11::arg("ex"));

	{ // dialect::OrderedAlignment file:libdialect/aca.h line:80
		pybind11::class_<dialect::OrderedAlignment, std::shared_ptr<dialect::OrderedAlignment>> cl(M("dialect"), "OrderedAlignment", "");
		cl.def( pybind11::init( [](){ return new dialect::OrderedAlignment(); } ) );
		cl.def_readwrite("af", &dialect::OrderedAlignment::af);
		cl.def_readwrite("sf", &dialect::OrderedAlignment::sf);
		cl.def_readwrite("dim", &dialect::OrderedAlignment::dim);
		cl.def_readwrite("src", &dialect::OrderedAlignment::src);
		cl.def_readwrite("tgt", &dialect::OrderedAlignment::tgt);
		cl.def_readwrite("offsetSrc", &dialect::OrderedAlignment::offsetSrc);
		cl.def_readwrite("offsetTgt", &dialect::OrderedAlignment::offsetTgt);
		cl.def_readwrite("edgeIndex", &dialect::OrderedAlignment::edgeIndex);
		cl.def_readwrite("penalty", &dialect::OrderedAlignment::penalty);
	}
	// dialect::sortOrdAlignsByPenalty(const struct dialect::OrderedAlignment *, const struct dialect::OrderedAlignment *) file:libdialect/aca.h line:109
	M("dialect").def("sortOrdAlignsByPenalty", (bool (*)(const struct dialect::OrderedAlignment *, const struct dialect::OrderedAlignment *)) &dialect::sortOrdAlignsByPenalty, "C++: dialect::sortOrdAlignsByPenalty(const struct dialect::OrderedAlignment *, const struct dialect::OrderedAlignment *) --> bool", pybind11::arg("lhs"), pybind11::arg("rhs"));

	{ // dialect::ACALayout file:libdialect/aca.h line:124
		pybind11::class_<dialect::ACALayout, std::shared_ptr<dialect::ACALayout>> cl(M("dialect"), "ACALayout", "Implements the Adaptive Constrained Alignment (ACA) algorithm.\n\n See\n Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.\n \"Incremental grid-like layout using soft and hard constraints.\" In Graph\n Drawing 2013, pp. 448-459. Springer International Publishing, 2013.");
		cl.def( pybind11::init<class std::shared_ptr<class dialect::Graph>>(), pybind11::arg("G") );

		cl.def( pybind11::init( [](dialect::ACALayout const &o){ return new dialect::ACALayout(o); } ) );
		cl.def_readwrite("aStateBeforeChop", &dialect::ACALayout::aStateBeforeChop);
		cl.def("createAlignments", (void (dialect::ACALayout::*)()) &dialect::ACALayout::createAlignments, "Creates alignments.\n\n This is the main functionality of ACA. This function should be called\n on an existing layout in order to greedily align edges until any further\n alignments would create edge overlaps.\n\n If the graph does not have an initial layout already, then the 'layout'\n function may be called instead.\n\nC++: dialect::ACALayout::createAlignments() --> void");
		cl.def("createOneAlignment", (bool (dialect::ACALayout::*)()) &dialect::ACALayout::createOneAlignment, "Creates one alignment.\n\n Call this function instead of createAlignments in order to create just\n one alignment and then stop. The return value is true if and only if a\n new alignment was actually created.\n\n Thus, repeatedly calling this function until it returns false achieves\n the exact same result as simply calling createAlignments.\n\nC++: dialect::ACALayout::createOneAlignment() --> bool");
		cl.def("layout", (void (dialect::ACALayout::*)()) &dialect::ACALayout::layout, "Do an initial stress-minimising layout, and then create alignments.\n\n This is a convenience function which first does a constrained force-directed\n layout of the given graph, and then calls the 'createAlignments' function.\n\nC++: dialect::ACALayout::layout() --> void");
		cl.def("removeOverlaps", (void (dialect::ACALayout::*)()) &dialect::ACALayout::removeOverlaps, "Do an FD layout with overlap prevention, then stop.\n\nC++: dialect::ACALayout::removeOverlaps() --> void");
		cl.def("layoutWithCurrentConstraints", (void (dialect::ACALayout::*)()) &dialect::ACALayout::layoutWithCurrentConstraints, "Run layout with current constraints, and with or without overlap\n prevention, as per the current settings.\n\nC++: dialect::ACALayout::layoutWithCurrentConstraints() --> void");
		cl.def("updateGraph", (void (dialect::ACALayout::*)()) &dialect::ACALayout::updateGraph, "For forward compatibility (i.e. with Graphs), we offer a convenience method\n        to update the Graph (when we have one) with the positions and constraints chosen\n        by this object.\n\nC++: dialect::ACALayout::updateGraph() --> void");
		cl.def("updateSepMatrix", (void (dialect::ACALayout::*)()) &dialect::ACALayout::updateSepMatrix, "Update the SepMatrix of the Graph on which this ACALayout was built (if any).\n\nC++: dialect::ACALayout::updateSepMatrix() --> void");
		cl.def("updateSepMatrix", (void (dialect::ACALayout::*)(class dialect::SepMatrix &, const class std::map<unsigned long, unsigned int, struct std::less<unsigned long>, class std::allocator<struct std::pair<const unsigned long, unsigned int> > > &)) &dialect::ACALayout::updateSepMatrix, "Update a given SepMatrix with all the ordered alignment constraints generated\n        by this ACA layout.\n\n \n  the SepMatrix to be updated.\n \n\n  a mapping from Rectangle indices back to the IDs of the Nodes they represent.\n\nC++: dialect::ACALayout::updateSepMatrix(class dialect::SepMatrix &, const class std::map<unsigned long, unsigned int, struct std::less<unsigned long>, class std::allocator<struct std::pair<const unsigned long, unsigned int> > > &) --> void", pybind11::arg("M"), pybind11::arg("ix2id"));
		cl.def("outputInstanceToSVG", (void (dialect::ACALayout::*)(std::string)) &dialect::ACALayout::outputInstanceToSVG, "C++: dialect::ACALayout::outputInstanceToSVG(std::string) --> void", pybind11::arg("filename"));
		cl.def("getFDLayout", (class cola::ConstrainedFDLayout * (dialect::ACALayout::*)()) &dialect::ACALayout::getFDLayout, "C++: dialect::ACALayout::getFDLayout() --> class cola::ConstrainedFDLayout *", pybind11::return_value_policy::automatic);
		cl.def("addBendPointPenalty", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::addBendPointPenalty, "Control whether we avoid making bend points.\n\n We refer to a node of degree 2 as a \"bend point\" when one of its\n edges has been aligned horizontally and the other vertically.\n\n The default value of addBendPointPenalty is true. In this case a penalty\n score is added when choosing the next alignment in order to postpone\n creating bend points until no other choices remain.\n\n If set to false then there is no penalty score to postpone the creation\n of bend points.\n\n When there is both bend point penalty and leaf penalty (see below), then\n bend points will be created before leaf edges are aligned. This can be\n reversed by altering the BP_PENALTY and LEAF_PENALTY constants.\n\nC++: dialect::ACALayout::addBendPointPenalty(bool) --> void", pybind11::arg("b"));
		cl.def("favourLongEdges", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::favourLongEdges, "Prefer long edges instead of ones that are close to aligned.\n\n This defaults to 'false', in which case ACA prefers to align edges that\n are almost aligned already. When set to 'true' it will instead choose\n the longest edges first.\n\nC++: dialect::ACALayout::favourLongEdges(bool) --> void", pybind11::arg("b"));
		cl.def("postponeLeaves", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::postponeLeaves, "Say whether alignment of leaf edges should be saved for last.\n\n The default value is true.\n\nC++: dialect::ACALayout::postponeLeaves(bool) --> void", pybind11::arg("b"));
		cl.def("useNonLeafDegree", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::useNonLeafDegree, "Say whether leaves should be counted when computing node degrees.\n\n The default value is true.\n\n This setting matters only if addBendPointPenalty is set to true.\n In that case, if useNonLeafDegree is also true then the nodes identified\n as potential bend points will be those having exactly 2 /non-leaf/ neighbours.\n\n When there is both leaf penalty and bend point penalty (see above), then\n bend points will be created before leaf edges are aligned. This can be\n reversed by altering the BP_PENALTY and LEAF_PENALTY constants.\n\nC++: dialect::ACALayout::useNonLeafDegree(bool) --> void", pybind11::arg("b"));
		cl.def("allAtOnce", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::allAtOnce, "Say whether alignment choices should alternate with stress\n        minimisation steps.\n\n The default value of allAtOnce is false. In this case, after each new\n alignment is chosen, stress is again minimised before choosing the\n next one.\n\n If you set allAtOnce to true, then all the alignments will be chosen based\n on the initial layout, and then they will all be applied at once.\n\nC++: dialect::ACALayout::allAtOnce(bool) --> void", pybind11::arg("b"));
		cl.def("aggressiveOrdering", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::aggressiveOrdering, "Say whether to consider changing orthogonal ordering of nodes.\n\n The default value is false. In that case, consider a pair of nodes\n u, v where v currently lies to the southeast of u. Then when ACA\n considers aligning u and v it will only consider putting v east or\n south of u; it will not consider reversing their current ordering in\n either dimension.\n\n In the same example, if you set aggressiveOrdering to true, then ACA\n will also consider putting v north and west of u.\n\n In the exceptional case of a node v lying, say, precisely east of a node\n u despite not being constrained to that alignment, then ACA will consider\n placing v east, north, and south of u even with aggressiveOrdering set\n to false. (But it will consider west only with it set to true.)\n\nC++: dialect::ACALayout::aggressiveOrdering(bool) --> void", pybind11::arg("b"));
		cl.def("setAvoidNodeOverlaps", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::setAvoidNodeOverlaps, "Specifies whether non-overlap constraints should be\n         automatically generated between all nodes.\n\n \n     New boolean value for this option.\n\nC++: dialect::ACALayout::setAvoidNodeOverlaps(bool) --> void", pybind11::arg("avoidOverlaps"));
		cl.def("setNodeAliases", (void (dialect::ACALayout::*)(class std::map<int, int, struct std::less<int>, class std::allocator<struct std::pair<const int, int> > >)) &dialect::ACALayout::setNodeAliases, "Set certain nodes to be used in place of others.\n\n Pass a map m. Then for each computation that involves a node u, we will check\n whether u is a key in m, and if so will use m(u) instead.\n\nC++: dialect::ACALayout::setNodeAliases(class std::map<int, int, struct std::less<int>, class std::allocator<struct std::pair<const int, int> > >) --> void", pybind11::arg("aliases"));
		cl.def("setClusterHierarchy", (void (dialect::ACALayout::*)(class cola::RootCluster *)) &dialect::ACALayout::setClusterHierarchy, "sets the cluster hierarchy of the underlying FDLayout.\n\nC++: dialect::ACALayout::setClusterHierarchy(class cola::RootCluster *) --> void", pybind11::arg("rc"));
		cl.def("edgeIsAligned", (bool (dialect::ACALayout::*)(int) const) &dialect::ACALayout::edgeIsAligned, "Check whether an edge is aligned.\n\n Pass the index of the edge. The returned boolean says whether ACA aligned this edge.\n\nC++: dialect::ACALayout::edgeIsAligned(int) const --> bool", pybind11::arg("j"));
		cl.def("nodesAreAligned", (bool (dialect::ACALayout::*)(int, int) const) &dialect::ACALayout::nodesAreAligned, "C++: dialect::ACALayout::nodesAreAligned(int, int) const --> bool", pybind11::arg("i"), pybind11::arg("j"));
		cl.def("layoutPeriod", (void (dialect::ACALayout::*)(unsigned int)) &dialect::ACALayout::layoutPeriod, "C++: dialect::ACALayout::layoutPeriod(unsigned int) --> void", pybind11::arg("p"));
		cl.def("doFinalLayout", (void (dialect::ACALayout::*)(bool)) &dialect::ACALayout::doFinalLayout, "C++: dialect::ACALayout::doFinalLayout(bool) --> void", pybind11::arg("b"));
		cl.def("initOrdAlign", (struct dialect::OrderedAlignment * (dialect::ACALayout::*)(int, enum dialect::ACASepFlag) const) &dialect::ACALayout::initOrdAlign, "C++: dialect::ACALayout::initOrdAlign(int, enum dialect::ACASepFlag) const --> struct dialect::OrderedAlignment *", pybind11::return_value_policy::automatic, pybind11::arg("j"), pybind11::arg("sf"));
		cl.def("initOrdAlign", [](dialect::ACALayout const &o, int const & a0, int const & a1, enum dialect::ACASepFlag const & a2) -> dialect::OrderedAlignment * { return o.initOrdAlign(a0, a1, a2); }, "", pybind11::return_value_policy::automatic, pybind11::arg("s"), pybind11::arg("t"), pybind11::arg("sf"));
		cl.def("initOrdAlign", (struct dialect::OrderedAlignment * (dialect::ACALayout::*)(int, int, enum dialect::ACASepFlag, int) const) &dialect::ACALayout::initOrdAlign, "C++: dialect::ACALayout::initOrdAlign(int, int, enum dialect::ACASepFlag, int) const --> struct dialect::OrderedAlignment *", pybind11::return_value_policy::automatic, pybind11::arg("s"), pybind11::arg("t"), pybind11::arg("sf"), pybind11::arg("edgeIndex"));
		cl.def("mostRecentOA", (struct dialect::OrderedAlignment * (dialect::ACALayout::*)()) &dialect::ACALayout::mostRecentOA, "C++: dialect::ACALayout::mostRecentOA() --> struct dialect::OrderedAlignment *", pybind11::return_value_policy::automatic);
		cl.def("writeAlignmentTable", (std::string (dialect::ACALayout::*)() const) &dialect::ACALayout::writeAlignmentTable, "C++: dialect::ACALayout::writeAlignmentTable() const --> std::string");
		cl.def("writeStateForNodeIds", (std::string (dialect::ACALayout::*)(unsigned int, unsigned int)) &dialect::ACALayout::writeStateForNodeIds, "C++: dialect::ACALayout::writeStateForNodeIds(unsigned int, unsigned int) --> std::string", pybind11::arg("id1"), pybind11::arg("id2"));
	}
}
