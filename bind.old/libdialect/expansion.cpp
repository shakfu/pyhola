#include <_stdio.h>
#include <functional>
#include <ios>
#include <istream>
#include <iterator>
#include <libavoid/connend.h>
#include <libavoid/geomtypes.h>
#include <libavoid/router.h>
#include <libcola/cluster.h>
#include <libdialect/constraints.h>
#include <libdialect/expansion.h>
#include <libdialect/graphs.h>
#include <libdialect/hola.h>
#include <libdialect/io.h>
#include <libdialect/logging.h>
#include <libdialect/nearalign.h>
#include <libdialect/nodeconfig.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/peeling.h>
#include <libdialect/quadaction.h>
#include <libdialect/routing.h>
#include <libdialect/treeplacement.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <locale>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <streambuf>
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

// dialect::PeeledNode file:libdialect/peeling.h line:50
struct PyCallBack_dialect_PeeledNode : public dialect::PeeledNode {
	using dialect::PeeledNode::PeeledNode;

	unsigned int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::PeeledNode *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		return GhostNode::id();
	}
};

void bind_libdialect_expansion(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::ExpansionGoal file:libdialect/expansion.h line:170
		pybind11::class_<dialect::ExpansionGoal, std::shared_ptr<dialect::ExpansionGoal>> cl(M("dialect"), "ExpansionGoal", "The ExpansionGoal class\n\n Manages a single expansion goal point, as utilised by the ExpansionManager class.\n\n ");
		cl.def( pybind11::init( [](dialect::ExpansionGoal const &o){ return new dialect::ExpansionGoal(o); } ) );
		cl.def("getDirec", (enum dialect::CardinalDir (dialect::ExpansionGoal::*)() const) &dialect::ExpansionGoal::getDirec, "Get the direction of the goal.\n\nC++: dialect::ExpansionGoal::getDirec() const --> enum dialect::CardinalDir");
	}
	{ // dialect::ContainedSegment file:libdialect/expansion.h line:221
		pybind11::class_<dialect::ContainedSegment, std::shared_ptr<dialect::ContainedSegment>> cl(M("dialect"), "ContainedSegment", "");
		cl.def( pybind11::init( [](dialect::ContainedSegment const &o){ return new dialect::ContainedSegment(o); } ) );
		cl.def_readwrite("goalID", &dialect::ContainedSegment::goalID);
		cl.def_readwrite("basept", &dialect::ContainedSegment::basept);
		cl.def_readwrite("localGoalPt", &dialect::ContainedSegment::localGoalPt);
		cl.def_readwrite("globalGoalPt", &dialect::ContainedSegment::globalGoalPt);
		cl.def_readwrite("padding", &dialect::ContainedSegment::padding);
		cl.def_readwrite("tp", &dialect::ContainedSegment::tp);
		cl.def_readwrite("sepDim", &dialect::ContainedSegment::sepDim);
		cl.def_readwrite("localGoalSeg", &dialect::ContainedSegment::localGoalSeg);
		cl.def_readwrite("globalGoalSeg", &dialect::ContainedSegment::globalGoalSeg);
		cl.def("measureShortage", (double (dialect::ContainedSegment::*)() const) &dialect::ContainedSegment::measureShortage, "Report the \"shortage\", i.e. the extent to which the global goal\n         segment exceeds the local in length. Returns zero if this value\n         would be negative.\n\nC++: dialect::ContainedSegment::measureShortage() const --> double");
	}
	// dialect::doHOLA(class dialect::Graph &, const struct dialect::HolaOpts &, struct dialect::Logger *) file:libdialect/hola.h line:46
	M("dialect").def("doHOLA", [](class dialect::Graph & a0, const struct dialect::HolaOpts & a1) -> void { return dialect::doHOLA(a0, a1); }, "", pybind11::arg("G"), pybind11::arg("holaOpts"));
	M("dialect").def("doHOLA", (void (*)(class dialect::Graph &, const struct dialect::HolaOpts &, struct dialect::Logger *)) &dialect::doHOLA, "Apply the HOLA layout algorithm to the given Graph.\n         See Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.\n         HOLA: Human-like Orthogonal Network Layout.\n         IEEE Transactions on Visualization and Computer Graphics 22, no. 1 (2016): 349-358.\n \n\n  The Graph to be laid out. Node positions are updated in-place. Constraints\n                    are set in the Graph's SepMatrix.\n \n\n  Options controlling the layout.\n \n\n  Optional pointer to a Logger in which to record TGLF for various stages\n                     of the layout process. Useful for debugging.\n\nC++: dialect::doHOLA(class dialect::Graph &, const struct dialect::HolaOpts &, struct dialect::Logger *) --> void", pybind11::arg("G"), pybind11::arg("holaOpts"), pybind11::arg("logger"));

	// dialect::doHOLA(class dialect::Graph &) file:libdialect/hola.h line:51
	M("dialect").def("doHOLA", (void (*)(class dialect::Graph &)) &dialect::doHOLA, "Convenience function to do HOLA layout with default options.\n \n\n  The Graph to be laid out. Node positions are updated in-place. Constraints\n                    are set in the Graph's SepMatrix.\n\nC++: dialect::doHOLA(class dialect::Graph &) --> void", pybind11::arg("G"));

	// dialect::AlignmentFlag file:libdialect/nearalign.h line:37
	pybind11::enum_<dialect::AlignmentFlag>(M("dialect"), "AlignmentFlag", "")
		.value("NONE", dialect::AlignmentFlag::NONE)
		.value("HALIGN", dialect::AlignmentFlag::HALIGN)
		.value("VALIGN", dialect::AlignmentFlag::VALIGN)
		.value("HINFEAS", dialect::AlignmentFlag::HINFEAS)
		.value("VINFEAS", dialect::AlignmentFlag::VINFEAS);

;

	{ // dialect::AlignmentTable file:libdialect/nearalign.h line:51
		pybind11::class_<dialect::AlignmentTable, std::shared_ptr<dialect::AlignmentTable>> cl(M("dialect"), "AlignmentTable", "");
		cl.def( pybind11::init( [](dialect::AlignmentTable const &o){ return new dialect::AlignmentTable(o); } ) );
		cl.def_readwrite("state", &dialect::AlignmentTable::state);
		cl.def("areAligned", (bool (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::areAligned, "Check whether two nodes are aligned.\n \n\n  The id of one of the ndoes.\n \n\n  The id of the other node.\n \n\n  The type of alignment to check for.\n \n\n true iff the nodes are aligned according to the given flag.\n\nC++: dialect::AlignmentTable::areAligned(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> bool", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("addAlignment", (void (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::addAlignment, "Add an alignment with transitive closure.\n \n\n  The id of one of the nodes to be aligned.\n \n\n  The id of the other node to be aligned.\n \n\n  The type of alignment to be recorded.\n\nC++: dialect::AlignmentTable::addAlignment(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> void", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("noteInfeasibility", (void (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::noteInfeasibility, "Note that a particular alignment type is infeasible.\n \n\n  The id of one of the nodes that cannot be aligned.\n \n\n  The id of the other node that cannot be aligned.\n \n\n  The type of alignment whose infeasibility is to be recorded.\n\n \n  Client should pass HALIGN or VALIGN, i.e. the type of alignment that is infeasible,\n         NOT one of the _INFEAS flags itself.\n\nC++: dialect::AlignmentTable::noteInfeasibility(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> void", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("isMarkedInfeasible", (bool (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::isMarkedInfeasible, "Check whether a given type of alignemnt has been marked infeasible.\n \n\n  The id of one of the nodes in question.\n \n\n  The id of the other node in question.\n \n\n  The type of alignment in question.\n \n\n  true iff the alignment in question has been marked infeasible.\n\nC++: dialect::AlignmentTable::isMarkedInfeasible(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> bool", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
	}
	{ // dialect::PotentialAlignment file:libdialect/nearalign.h line:108
		pybind11::class_<dialect::PotentialAlignment, std::shared_ptr<dialect::PotentialAlignment>> cl(M("dialect"), "PotentialAlignment", "");
		cl.def( pybind11::init( [](dialect::PotentialAlignment const &o){ return new dialect::PotentialAlignment(o); } ) );
		cl.def_readwrite("u", &dialect::PotentialAlignment::u);
		cl.def_readwrite("v", &dialect::PotentialAlignment::v);
		cl.def_readwrite("flag", &dialect::PotentialAlignment::flag);
		cl.def_readwrite("cost", &dialect::PotentialAlignment::cost);
		cl.def_readwrite("removed", &dialect::PotentialAlignment::removed);
		cl.def("remove", (void (dialect::PotentialAlignment::*)()) &dialect::PotentialAlignment::remove, "Remove from linked list.\n\nC++: dialect::PotentialAlignment::remove() --> void");
		cl.def("addToTable", (void (dialect::PotentialAlignment::*)(struct dialect::AlignmentTable &)) &dialect::PotentialAlignment::addToTable, "Add this alignment to an AlignmentTable.\n\nC++: dialect::PotentialAlignment::addToTable(struct dialect::AlignmentTable &) --> void", pybind11::arg("table"));
		cl.def("noteInfeasibility", (void (dialect::PotentialAlignment::*)(struct dialect::AlignmentTable &)) &dialect::PotentialAlignment::noteInfeasibility, "Note infeasibility of this alignment in in AlignmentTable.\n\nC++: dialect::PotentialAlignment::noteInfeasibility(struct dialect::AlignmentTable &) --> void", pybind11::arg("table"));
		cl.def("addToGraph", (void (dialect::PotentialAlignment::*)(class dialect::Graph &)) &dialect::PotentialAlignment::addToGraph, "Add this alignment to a Graph.\n\nC++: dialect::PotentialAlignment::addToGraph(class dialect::Graph &) --> void", pybind11::arg("G"));
	}
	{ // dialect::Nbr file:libdialect/quadaction.h line:65
		pybind11::class_<dialect::Nbr, std::shared_ptr<dialect::Nbr>> cl(M("dialect"), "Nbr", "Represents a neighbouring node to a central node.");
		cl.def( pybind11::init<unsigned int, double, double>(), pybind11::arg("id"), pybind11::arg("dx"), pybind11::arg("dy") );

		cl.def_readwrite("id", &dialect::Nbr::id);
		cl.def_readwrite("x", &dialect::Nbr::x);
		cl.def_readwrite("y", &dialect::Nbr::y);
		cl.def("octalCode", (unsigned int (dialect::Nbr::*)() const) &dialect::Nbr::octalCode, "A code number from 0 to 7, indicating where this neighbour\n         lies relative to the central node:\n             Semiaxes 0,1,2,3 get octal codes 0,2,4,6;\n             Quadrants 0,1,2,3 get octal codes 1,3,5,7.\n\nC++: dialect::Nbr::octalCode() const --> unsigned int");
		cl.def("deflection", (double (dialect::Nbr::*)() const) &dialect::Nbr::deflection, "A measure of how far into its quadrant this nbr lies, in the\n         clockwise direction.\n\n \n If this nbr lies in quadrant n or on semiaxis n, then return\n         the squared sine of the angle that this nbr makes with semiaxis n.\n\nC++: dialect::Nbr::deflection() const --> double");
	}
	{ // dialect::Assignment file:libdialect/quadaction.h line:95
		pybind11::class_<dialect::Assignment, std::shared_ptr<dialect::Assignment>> cl(M("dialect"), "Assignment", "Represents an assignment of nbrs to semiaxes, and records the\n         cost of this assignment.");
		cl.def( pybind11::init( [](){ return new dialect::Assignment(); } ) );
		cl.def( pybind11::init( [](dialect::Assignment const &o){ return new dialect::Assignment(o); } ) );
		cl.def_readwrite("semis", &dialect::Assignment::semis);
		cl.def_readwrite("cost", &dialect::Assignment::cost);
		cl.def("cardinality", (unsigned long (dialect::Assignment::*)() const) &dialect::Assignment::cardinality, "Return the \"cardinality\" of this Assignment, i.e. the number\n         of Nbrs assigned to semiaxes.\n\nC++: dialect::Assignment::cardinality() const --> unsigned long");
		cl.def("makeUnion", (struct dialect::Assignment (dialect::Assignment::*)(const struct dialect::Assignment &) const) &dialect::Assignment::makeUnion, "Create union of two Assignments.\n\n \n  A new Assignment representing the union of this one with\n          the other.\n\n \n  This function assumes you never try to put more than one\n        Nbr on a given semiaxis. If you do, you will get an incorrect\n        result; an exception will not be raised.\n\nC++: dialect::Assignment::makeUnion(const struct dialect::Assignment &) const --> struct dialect::Assignment", pybind11::arg("other"));
	}
	{ // dialect::Quad file:libdialect/quadaction.h line:139
		pybind11::class_<dialect::Quad, std::shared_ptr<dialect::Quad>> cl(M("dialect"), "Quad", "Represents a quadrant, relative to a central node.");
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("num") );

		cl.def( pybind11::init( [](dialect::Quad const &o){ return new dialect::Quad(o); } ) );
		cl.def_readwrite("num", &dialect::Quad::num);
		cl.def_readwrite("nbrs", &dialect::Quad::nbrs);
		cl.def_readwrite("ACost", &dialect::Quad::ACost);
		cl.def_readwrite("CCost", &dialect::Quad::CCost);
		cl.def("size", (unsigned long (dialect::Quad::*)() const) &dialect::Quad::size, "Say how many Nbrs are in this quadrant.\n\nC++: dialect::Quad::size() const --> unsigned long");
		cl.def("sortAndComputeCosts", (void (dialect::Quad::*)()) &dialect::Quad::sortAndComputeCosts, "To be called after all nbrs have been added.\n         Sorts the nbrs into clockwise order, and then computes\n         and stores the costs associated with the clockwise and\n         anticlockwise actions.\n\nC++: dialect::Quad::sortAndComputeCosts() --> void");
		cl.def("constructAssignmentForAction", (struct dialect::Assignment (dialect::Quad::*)(char) const) &dialect::Quad::constructAssignmentForAction, "Construct an Assignment indicating which Nbr(s) were assigned\n         to which semiaxes, and representing the cost.\n\n \n  an action code letter, in {A, B, C, D}:\n                         A: Anticlockwise\n                         B: Both\n                         C: Clockwise\n                         D: Do nothing\n\n \n  the Assignment\n\nC++: dialect::Quad::constructAssignmentForAction(char) const --> struct dialect::Assignment", pybind11::arg("action"));
	}
	{ // dialect::Arrangement file:libdialect/quadaction.h line:181
		pybind11::class_<dialect::Arrangement, std::shared_ptr<dialect::Arrangement>> cl(M("dialect"), "Arrangement", "Represents the arrangement of all Nbrs around a centre node.");
		cl.def( pybind11::init( [](dialect::Arrangement const &o){ return new dialect::Arrangement(o); } ) );
		cl.def_readwrite("nbrs", &dialect::Arrangement::nbrs);
		cl.def_readwrite("semis", &dialect::Arrangement::semis);
		cl.def_readwrite("quads", &dialect::Arrangement::quads);
	}
	{ // dialect::OrthoHubLayoutOptions file:libdialect/nodeconfig.h line:38
		pybind11::class_<dialect::OrthoHubLayoutOptions, std::shared_ptr<dialect::OrthoHubLayoutOptions>> cl(M("dialect"), "OrthoHubLayoutOptions", "Options to control OrthoHubLayout");
		cl.def( pybind11::init( [](){ return new dialect::OrthoHubLayoutOptions(); } ) );
		cl.def( pybind11::init( [](dialect::OrthoHubLayoutOptions const &o){ return new dialect::OrthoHubLayoutOptions(o); } ) );
		cl.def_readwrite("avoidFlatTriangles", &dialect::OrthoHubLayoutOptions::avoidFlatTriangles);
		cl.def_readwrite("includeLinks", &dialect::OrthoHubLayoutOptions::includeLinks);
		cl.def("assign", (struct dialect::OrthoHubLayoutOptions & (dialect::OrthoHubLayoutOptions::*)(const struct dialect::OrthoHubLayoutOptions &)) &dialect::OrthoHubLayoutOptions::operator=, "C++: dialect::OrthoHubLayoutOptions::operator=(const struct dialect::OrthoHubLayoutOptions &) --> struct dialect::OrthoHubLayoutOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::OrthoHubLayout file:libdialect/nodeconfig.h line:62
		pybind11::class_<dialect::OrthoHubLayout, std::shared_ptr<dialect::OrthoHubLayout>> cl(M("dialect"), "OrthoHubLayout", "A layout object that tries to orthogonalise hubs.\n         This means it visits nodes of degrees 3 or higher, and\n         tries to set their neighbours in cardinal compass directions\n         from it.");
		cl.def( pybind11::init( [](dialect::OrthoHubLayout const &o){ return new dialect::OrthoHubLayout(o); } ) );
		cl.def("layout", [](dialect::OrthoHubLayout &o) -> void { return o.layout(); }, "");
		cl.def("layout", (void (dialect::OrthoHubLayout::*)(struct dialect::Logger *)) &dialect::OrthoHubLayout::layout, "Try to orthogonalise hubs.\n\n \n  Optional logger to record the individual layout steps.\n\nC++: dialect::OrthoHubLayout::layout(struct dialect::Logger *) --> void", pybind11::arg("logger"));
	}
	{ // dialect::PeeledNode file:libdialect/peeling.h line:50
		pybind11::class_<dialect::PeeledNode, std::shared_ptr<dialect::PeeledNode>, PyCallBack_dialect_PeeledNode, dialect::GhostNode> cl(M("dialect"), "PeeledNode", "A PeeledNode is a type of GhostNode, used in the peeling process.");
	}
	{ // dialect::Stem file:libdialect/peeling.h line:87
		pybind11::class_<dialect::Stem, std::shared_ptr<dialect::Stem>> cl(M("dialect"), "Stem", "Represents a leaf node, along with its one edge and neighbour.");
		cl.def( pybind11::init( [](dialect::Stem const &o){ return new dialect::Stem(o); } ) );
		cl.def_readwrite("m_plain_leaf", &dialect::Stem::m_plain_leaf);
		cl.def_readwrite("m_plain_root", &dialect::Stem::m_plain_root);
		cl.def("addSelfToGraph", (void (dialect::Stem::*)(class dialect::Graph &)) &dialect::Stem::addSelfToGraph, "C++: dialect::Stem::addSelfToGraph(class dialect::Graph &) --> void", pybind11::arg("H"));
	}
	{ // dialect::NodeBuckets file:libdialect/peeling.h line:101
		pybind11::class_<dialect::NodeBuckets, std::shared_ptr<dialect::NodeBuckets>> cl(M("dialect"), "NodeBuckets", "For sorting all the nodes of a graph into \"buckets\" according\n to their degree.\n You can take all the leaves (degree-1 nodes) and you can move\n a node from one bucket to another.");
		cl.def( pybind11::init<class dialect::Graph &>(), pybind11::arg("graph") );

		cl.def( pybind11::init( [](dialect::NodeBuckets const &o){ return new dialect::NodeBuckets(o); } ) );
		cl.def_readwrite("m_maxDegree", &dialect::NodeBuckets::m_maxDegree);
		cl.def_readwrite("m_buckets", &dialect::NodeBuckets::m_buckets);
		cl.def("moveNode", (bool (dialect::NodeBuckets::*)(unsigned int, unsigned int, unsigned int)) &dialect::NodeBuckets::moveNode, "Move a node from one bucket to another.\n\n \n  The ID of the Node to be moved.\n \n\n  The bucket in which the Node should be found.\n \n\n  The bucket to which the Node should be moved.\n\n \n  boolean saying whether the Node was found and moved.\n\nC++: dialect::NodeBuckets::moveNode(unsigned int, unsigned int, unsigned int) --> bool", pybind11::arg("id"), pybind11::arg("oldDegree"), pybind11::arg("newDegree"));
	}
}
