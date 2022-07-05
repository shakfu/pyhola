#include <_stdio.h>
#include <functional>
#include <ios>
#include <istream>
#include <iterator>
#include <libdialect/expansion.h>
#include <libdialect/hola.h>
#include <libdialect/io.h>
#include <libdialect/nearalign.h>
#include <locale>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <streambuf>
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

void bind_libdialect_expansion(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::ExpansionGoal file:libdialect/expansion.h line:170
		pybind11::class_<dialect::ExpansionGoal, std::shared_ptr<dialect::ExpansionGoal>> cl(M("dialect"), "ExpansionGoal", "The ExpansionGoal class\n\n Manages a single expansion goal point, as utilised by the ExpansionManager class.\n\n ");
		cl.def( pybind11::init<unsigned int, class std::shared_ptr<class dialect::TreePlacement>, enum dialect::CardinalDir, double>(), pybind11::arg("id"), pybind11::arg("tp"), pybind11::arg("direc"), pybind11::arg("padding") );

		cl.def( pybind11::init( [](dialect::ExpansionGoal const &o){ return new dialect::ExpansionGoal(o); } ) );
		cl.def("computeContainedSegment", [](dialect::ExpansionGoal &o) -> std::shared_ptr<struct dialect::ContainedSegment> { return o.computeContainedSegment(); }, "");
		cl.def("computeContainedSegment", (class std::shared_ptr<struct dialect::ContainedSegment> (dialect::ExpansionGoal::*)(bool)) &dialect::ExpansionGoal::computeContainedSegment, "Compute the contained segment for this goal.\n\n \n  This is useful when we are interested in\n computing estimates of expansion costs. At such times, we want to guess how long\n the contained segment might be once any collateral tree boxes have been moved away\n (but without actually doing the moving).\n\nC++: dialect::ExpansionGoal::computeContainedSegment(bool) --> class std::shared_ptr<struct dialect::ContainedSegment>", pybind11::arg("ignoreCollateralTreeBoxes"));
		cl.def("getDirec", (enum dialect::CardinalDir (dialect::ExpansionGoal::*)() const) &dialect::ExpansionGoal::getDirec, "Get the direction of the goal.\n\nC++: dialect::ExpansionGoal::getDirec() const --> enum dialect::CardinalDir");
	}
	{ // dialect::ContainedSegment file:libdialect/expansion.h line:221
		pybind11::class_<dialect::ContainedSegment, std::shared_ptr<dialect::ContainedSegment>> cl(M("dialect"), "ContainedSegment", "");
		cl.def( pybind11::init<unsigned int, class Avoid::Point, class Avoid::Point, class Avoid::Point, double, class std::shared_ptr<class dialect::TreePlacement>, enum vpsc::Dim>(), pybind11::arg("goalID"), pybind11::arg("basept"), pybind11::arg("localGoalPt"), pybind11::arg("globalGoalPt"), pybind11::arg("padding"), pybind11::arg("tp"), pybind11::arg("sepDim") );

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
		cl.def("toString", (std::string (dialect::ContainedSegment::*)() const) &dialect::ContainedSegment::toString, "Write a string representation.\n\nC++: dialect::ContainedSegment::toString() const --> std::string");
		cl.def("makeRoomForTreeNode", [](dialect::ContainedSegment &o, class std::shared_ptr<class dialect::ProjSeq> const & a0) -> void { return o.makeRoomForTreeNode(a0); }, "", pybind11::arg("ps0"));
		cl.def("makeRoomForTreeNode", (void (dialect::ContainedSegment::*)(class std::shared_ptr<class dialect::ProjSeq>, bool)) &dialect::ContainedSegment::makeRoomForTreeNode, "Perform expansion, to make room for the tree node, extending a given\n         projection sequence with the projections performed.\n \n\n  The ProjSeq to be extended.\n \n\n  Set false in order to do a 'trial' in which you only extend the given\n                       ProjSeq, but do not actually project.\n \n\n  Runtime error if any attempted projection is impossible.\n\nC++: dialect::ContainedSegment::makeRoomForTreeNode(class std::shared_ptr<class dialect::ProjSeq>, bool) --> void", pybind11::arg("ps0"), pybind11::arg("doProject"));
	}
	// dialect::doHOLA(class dialect::Graph &, const struct dialect::HolaOpts &, struct dialect::Logger *) file:libdialect/hola.h line:46
	M("dialect").def("doHOLA", [](class dialect::Graph & a0, const struct dialect::HolaOpts & a1) -> void { return dialect::doHOLA(a0, a1); }, "", pybind11::arg("G"), pybind11::arg("holaOpts"));
	M("dialect").def("doHOLA", (void (*)(class dialect::Graph &, const struct dialect::HolaOpts &, struct dialect::Logger *)) &dialect::doHOLA, "Apply the HOLA layout algorithm to the given Graph.\n         See Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.\n         HOLA: Human-like Orthogonal Network Layout.\n         IEEE Transactions on Visualization and Computer Graphics 22, no. 1 (2016): 349-358.\n \n\n  The Graph to be laid out. Node positions are updated in-place. Constraints\n                    are set in the Graph's SepMatrix.\n \n\n  Options controlling the layout.\n \n\n  Optional pointer to a Logger in which to record TGLF for various stages\n                     of the layout process. Useful for debugging.\n\nC++: dialect::doHOLA(class dialect::Graph &, const struct dialect::HolaOpts &, struct dialect::Logger *) --> void", pybind11::arg("G"), pybind11::arg("holaOpts"), pybind11::arg("logger"));

	// dialect::doHOLA(class dialect::Graph &) file:libdialect/hola.h line:51
	M("dialect").def("doHOLA", (void (*)(class dialect::Graph &)) &dialect::doHOLA, "Convenience function to do HOLA layout with default options.\n \n\n  The Graph to be laid out. Node positions are updated in-place. Constraints\n                    are set in the Graph's SepMatrix.\n\nC++: dialect::doHOLA(class dialect::Graph &) --> void", pybind11::arg("G"));

	// dialect::buildGraphFromTglf(std::istream &) file:libdialect/io.h line:95
	M("dialect").def("buildGraphFromTglf", (class std::shared_ptr<class dialect::Graph> (*)(std::istream &)) &dialect::buildGraphFromTglf, "Build a Graph object from TGLF.\n\n \n  An istream containing TGLF.\n\n \n  A Graph built on the given TGLF.\n\nC++: dialect::buildGraphFromTglf(std::istream &) --> class std::shared_ptr<class dialect::Graph>", pybind11::arg("in"));

	// dialect::buildGraphFromTglf(std::string &) file:libdialect/io.h line:102
	M("dialect").def("buildGraphFromTglf", (class std::shared_ptr<class dialect::Graph> (*)(std::string &)) &dialect::buildGraphFromTglf, "Build a Graph object from TGLF.\n\n \n  A string containing TGLF.\n\n \n  A Graph built on the given TGLF.\n\nC++: dialect::buildGraphFromTglf(std::string &) --> class std::shared_ptr<class dialect::Graph>", pybind11::arg("s"));

	// dialect::buildGraphFromTglfFile(const std::string &) file:libdialect/io.h line:109
	M("dialect").def("buildGraphFromTglfFile", (class std::shared_ptr<class dialect::Graph> (*)(const std::string &)) &dialect::buildGraphFromTglfFile, "Build a Graph object from a file containing TGLF.\n\n \n  Full filesystem path to a file containing TGLF.\n\n \n  A Graph built on the given TGLF.\n\nC++: dialect::buildGraphFromTglfFile(const std::string &) --> class std::shared_ptr<class dialect::Graph>", pybind11::arg("filepath"));

	// dialect::writeStringToFile(const std::string &, const std::string &) file:libdialect/io.h line:115
	M("dialect").def("writeStringToFile", (void (*)(const std::string &, const std::string &)) &dialect::writeStringToFile, "Write a string to a file.\n\n \n  the string to be written\n \n\n  full filesystem path to the file to be written\n\nC++: dialect::writeStringToFile(const std::string &, const std::string &) --> void", pybind11::arg("s"), pybind11::arg("filepath"));

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
		cl.def( pybind11::init<class dialect::Graph &, const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &>(), pybind11::arg("graph"), pybind11::arg("ignore") );

		cl.def( pybind11::init( [](dialect::AlignmentTable const &o){ return new dialect::AlignmentTable(o); } ) );
		cl.def_readwrite("state", &dialect::AlignmentTable::state);
		cl.def("areAligned", (bool (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::areAligned, "Check whether two nodes are aligned.\n \n\n  The id of one of the ndoes.\n \n\n  The id of the other node.\n \n\n  The type of alignment to check for.\n \n\n true iff the nodes are aligned according to the given flag.\n\nC++: dialect::AlignmentTable::areAligned(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> bool", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("addAlignment", (void (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::addAlignment, "Add an alignment with transitive closure.\n \n\n  The id of one of the nodes to be aligned.\n \n\n  The id of the other node to be aligned.\n \n\n  The type of alignment to be recorded.\n\nC++: dialect::AlignmentTable::addAlignment(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> void", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("addAlignments", (void (dialect::AlignmentTable::*)(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, const class dialect::SepMatrix &)) &dialect::AlignmentTable::addAlignments, "Add all existing alignments for a set of Nodes, based on a given SepMatrix.\n \n\n  The set of nodes.\n \n\n  The SepMatrix.\n\nC++: dialect::AlignmentTable::addAlignments(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, const class dialect::SepMatrix &) --> void", pybind11::arg("nodes"), pybind11::arg("matrix"));
		cl.def("noteInfeasibility", (void (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::noteInfeasibility, "Note that a particular alignment type is infeasible.\n \n\n  The id of one of the nodes that cannot be aligned.\n \n\n  The id of the other node that cannot be aligned.\n \n\n  The type of alignment whose infeasibility is to be recorded.\n\n \n  Client should pass HALIGN or VALIGN, i.e. the type of alignment that is infeasible,\n         NOT one of the _INFEAS flags itself.\n\nC++: dialect::AlignmentTable::noteInfeasibility(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> void", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("isMarkedInfeasible", (bool (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::isMarkedInfeasible, "Check whether a given type of alignemnt has been marked infeasible.\n \n\n  The id of one of the nodes in question.\n \n\n  The id of the other node in question.\n \n\n  The type of alignment in question.\n \n\n  true iff the alignment in question has been marked infeasible.\n\nC++: dialect::AlignmentTable::isMarkedInfeasible(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> bool", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
	}
	// dialect::manhattan(class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>) file:libdialect/nearalign.h line:105
	M("dialect").def("manhattan", (double (*)(class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>)) &dialect::manhattan, "Report the \"Manhattan distance\" between two nodes.\n\nC++: dialect::manhattan(class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>) --> double", pybind11::arg("u"), pybind11::arg("v"));

	{ // dialect::PotentialAlignment file:libdialect/nearalign.h line:108
		pybind11::class_<dialect::PotentialAlignment, std::shared_ptr<dialect::PotentialAlignment>> cl(M("dialect"), "PotentialAlignment", "");
		cl.def( pybind11::init<class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>, enum dialect::AlignmentFlag>(), pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("flag") );

		cl.def( pybind11::init( [](dialect::PotentialAlignment const &o){ return new dialect::PotentialAlignment(o); } ) );
		cl.def_readwrite("u", &dialect::PotentialAlignment::u);
		cl.def_readwrite("v", &dialect::PotentialAlignment::v);
		cl.def_readwrite("flag", &dialect::PotentialAlignment::flag);
		cl.def_readwrite("cost", &dialect::PotentialAlignment::cost);
		cl.def_readwrite("removed", &dialect::PotentialAlignment::removed);
		cl.def("remove", (void (dialect::PotentialAlignment::*)()) &dialect::PotentialAlignment::remove, "Remove from linked list.\n\nC++: dialect::PotentialAlignment::remove() --> void");
		cl.def("addToTable", (void (dialect::PotentialAlignment::*)(struct dialect::AlignmentTable &)) &dialect::PotentialAlignment::addToTable, "Add this alignment to an AlignmentTable.\n\nC++: dialect::PotentialAlignment::addToTable(struct dialect::AlignmentTable &) --> void", pybind11::arg("table"));
		cl.def("noteInfeasibility", (void (dialect::PotentialAlignment::*)(struct dialect::AlignmentTable &)) &dialect::PotentialAlignment::noteInfeasibility, "Note infeasibility of this alignment in in AlignmentTable.\n\nC++: dialect::PotentialAlignment::noteInfeasibility(struct dialect::AlignmentTable &) --> void", pybind11::arg("table"));
		cl.def("writeSepCo", (class std::shared_ptr<struct dialect::SepCo> (dialect::PotentialAlignment::*)()) &dialect::PotentialAlignment::writeSepCo, "Write a SepCo to represent this alignment.\n\nC++: dialect::PotentialAlignment::writeSepCo() --> class std::shared_ptr<struct dialect::SepCo>");
		cl.def("addToGraph", (void (dialect::PotentialAlignment::*)(class dialect::Graph &)) &dialect::PotentialAlignment::addToGraph, "Add this alignment to a Graph.\n\nC++: dialect::PotentialAlignment::addToGraph(class dialect::Graph &) --> void", pybind11::arg("G"));
	}
	// dialect::doNearAlignments(class dialect::Graph &, struct dialect::AlignmentTable &, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, const struct dialect::HolaOpts &, bool) file:libdialect/nearalign.h line:154
	M("dialect").def("doNearAlignments", [](class dialect::Graph & a0, struct dialect::AlignmentTable & a1, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > & a2, const struct dialect::HolaOpts & a3) -> unsigned long { return dialect::doNearAlignments(a0, a1, a2, a3); }, "", pybind11::arg("graph"), pybind11::arg("atab"), pybind11::arg("ignore"), pybind11::arg("opts"));
	M("dialect").def("doNearAlignments", (unsigned long (*)(class dialect::Graph &, struct dialect::AlignmentTable &, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, const struct dialect::HolaOpts &, bool)) &dialect::doNearAlignments, "Look for nodes that are nearly aligned, and try to align them.\n\n \n  The Graph whose nodes are to be aligned, and in whose SepMatrix alignments\n                        should be recorded when made.\n \n\n  An AlignmentTable for the given Graph.\n \n\n  HolaOpts object to set parameters for the process.\n \n\n  Set true for a more aggressive process that reattempts alignments even after\n                       they have been marked infeasible (in case other changes in the meantime might\n                       have made them now feasible). Default: false.\n \n\n  Number of successful alignments.\n\nC++: dialect::doNearAlignments(class dialect::Graph &, struct dialect::AlignmentTable &, class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, const struct dialect::HolaOpts &, bool) --> unsigned long", pybind11::arg("graph"), pybind11::arg("atab"), pybind11::arg("ignore"), pybind11::arg("opts"), pybind11::arg("reattempt"));

}
