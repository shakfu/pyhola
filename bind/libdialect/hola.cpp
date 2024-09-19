#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/hola.h>
#include <libdialect/io.h>
#include <libdialect/logging.h>
#include <libdialect/nearalign.h>
#include <libdialect/nodeconfig.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
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

void bind_libdialect_hola(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::doHOLA(class dialect::Graph &, const int &, int *) file:libdialect/hola.h line:46
	M("dialect").def("doHOLA", [](class dialect::Graph & a0, const int & a1) -> void { return dialect::doHOLA(a0, a1); }, "", pybind11::arg("G"), pybind11::arg("holaOpts"));
	M("dialect").def("doHOLA", (void (*)(class dialect::Graph &, const int &, int *)) &dialect::doHOLA, "Apply the HOLA layout algorithm to the given Graph.\n         See Steve Kieffer, Tim Dwyer, Kim Marriott, and Michael Wybrow.\n         HOLA: Human-like Orthogonal Network Layout.\n         IEEE Transactions on Visualization and Computer Graphics 22, no. 1 (2016): 349-358.\n \n\n  The Graph to be laid out. Node positions are updated in-place. Constraints\n                    are set in the Graph's SepMatrix.\n \n\n  Options controlling the layout.\n \n\n  Optional pointer to a Logger in which to record TGLF for various stages\n                     of the layout process. Useful for debugging.\n\nC++: dialect::doHOLA(class dialect::Graph &, const int &, int *) --> void", pybind11::arg("G"), pybind11::arg("holaOpts"), pybind11::arg("logger"));

	// dialect::doHOLA(class dialect::Graph &) file:libdialect/hola.h line:51
	M("dialect").def("doHOLA", (void (*)(class dialect::Graph &)) &dialect::doHOLA, "Convenience function to do HOLA layout with default options.\n \n\n  The Graph to be laid out. Node positions are updated in-place. Constraints\n                    are set in the Graph's SepMatrix.\n\nC++: dialect::doHOLA(class dialect::Graph &) --> void", pybind11::arg("G"));

	// dialect::buildGraphFromTglf(int &) file:libdialect/io.h line:107
	M("dialect").def("buildGraphFromTglf", (int (*)(int &)) &dialect::buildGraphFromTglf, "Build a Graph object from TGLF.\n\n \n  An istream containing TGLF.\n\n \n  A Graph built on the given TGLF.\n\nC++: dialect::buildGraphFromTglf(int &) --> int", pybind11::arg("in"));

	// dialect::buildGraphFromTglfFile(const int &) file:libdialect/io.h line:121
	M("dialect").def("buildGraphFromTglfFile", (int (*)(const int &)) &dialect::buildGraphFromTglfFile, "Build a Graph object from a file containing TGLF.\n\n \n  Full filesystem path to a file containing TGLF.\n\n \n  A Graph built on the given TGLF.\n\nC++: dialect::buildGraphFromTglfFile(const int &) --> int", pybind11::arg("filepath"));

	// dialect::writeStringToFile(const int &, const int &) file:libdialect/io.h line:127
	M("dialect").def("writeStringToFile", (void (*)(const int &, const int &)) &dialect::writeStringToFile, "Write a string to a file.\n\n \n  the string to be written\n \n\n  full filesystem path to the file to be written\n\nC++: dialect::writeStringToFile(const int &, const int &) --> void", pybind11::arg("s"), pybind11::arg("filepath"));

	{ // dialect::Logger file:libdialect/logging.h line:35
		pybind11::class_<dialect::Logger, std::shared_ptr<dialect::Logger>> cl(M("dialect"), "Logger", "");
		cl.def( pybind11::init( [](){ return new dialect::Logger(); } ), "doc" );
		cl.def( pybind11::init( [](int const & a0){ return new dialect::Logger(a0); } ), "doc" , pybind11::arg("outputDir"));
		cl.def( pybind11::init( [](int const & a0, int const & a1){ return new dialect::Logger(a0, a1); } ), "doc" , pybind11::arg("outputDir"), pybind11::arg("prefix"));
		cl.def( pybind11::init( [](int const & a0, int const & a1, bool const & a2){ return new dialect::Logger(a0, a1, a2); } ), "doc" , pybind11::arg("outputDir"), pybind11::arg("prefix"), pybind11::arg("verbose"));
		cl.def( pybind11::init<int, int, bool, bool>(), pybind11::arg("outputDir"), pybind11::arg("prefix"), pybind11::arg("verbose"), pybind11::arg("addSVG") );

		cl.def_readwrite("outputDir", &dialect::Logger::outputDir);
		cl.def_readwrite("prefix", &dialect::Logger::prefix);
		cl.def_readwrite("contents", &dialect::Logger::contents);
		cl.def_readwrite("names", &dialect::Logger::names);
		cl.def_readwrite("hasOutputDir", &dialect::Logger::hasOutputDir);
		cl.def_readwrite("hasPrefix", &dialect::Logger::hasPrefix);
		cl.def_readwrite("verbose", &dialect::Logger::verbose);
		cl.def_readwrite("addSVG", &dialect::Logger::addSVG);
		cl.def_readwrite("nextLoggingIndex", &dialect::Logger::nextLoggingIndex);
		cl.def("log", [](dialect::Logger &o, int const & a0) -> void { return o.log(a0); }, "", pybind11::arg("content"));
		cl.def("log", (void (dialect::Logger::*)(int, int)) &dialect::Logger::log, "Record a string, optionally to a named file in the output dir.\n \n\n  The string to be recorded.\n \n\n  The name under which to record it.\n\nC++: dialect::Logger::log(int, int) --> void", pybind11::arg("content"), pybind11::arg("name"));
		cl.def("log", [](dialect::Logger &o, class dialect::Graph & a0) -> void { return o.log(a0); }, "", pybind11::arg("G"));
		cl.def("log", (void (dialect::Logger::*)(class dialect::Graph &, int)) &dialect::Logger::log, "Convenience method to log the TGLF for a Graph.\n \n\n  The Graph whose TGLF is to be logged.\n \n\n  The filename for the TGLF file WITHOUT the \".tglf\" suffix. The suffix\n                  is automatically added for you.\n\nC++: dialect::Logger::log(class dialect::Graph &, int) --> void", pybind11::arg("G"), pybind11::arg("name"));
		cl.def("writeFullPathForFilename", (int (dialect::Logger::*)(int)) &dialect::Logger::writeFullPathForFilename, "Given a filename, prepend the output directory and prefix (if given) in order\n         to write the full path.\n \n\n The full path.\n\nC++: dialect::Logger::writeFullPathForFilename(int) --> int", pybind11::arg("name"));
	}
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
		cl.def( pybind11::init<class dialect::Graph &, const int &>(), pybind11::arg("graph"), pybind11::arg("ignore") );

		cl.def( pybind11::init<class dialect::Graph &, const int &>(), pybind11::arg("graph"), pybind11::arg("ignore") );

		cl.def_readwrite("state", &dialect::AlignmentTable::state);
		cl.def("areAligned", (bool (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::areAligned, "Check whether two nodes are aligned.\n \n\n  The id of one of the ndoes.\n \n\n  The id of the other node.\n \n\n  The type of alignment to check for.\n \n\n true iff the nodes are aligned according to the given flag.\n\nC++: dialect::AlignmentTable::areAligned(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> bool", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("addAlignment", (void (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::addAlignment, "Add an alignment with transitive closure.\n \n\n  The id of one of the nodes to be aligned.\n \n\n  The id of the other node to be aligned.\n \n\n  The type of alignment to be recorded.\n\nC++: dialect::AlignmentTable::addAlignment(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> void", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("addAlignments", (void (dialect::AlignmentTable::*)(const int &, const class dialect::SepMatrix &)) &dialect::AlignmentTable::addAlignments, "Add all existing alignments for a set of Nodes, based on a given SepMatrix.\n \n\n  The set of nodes.\n \n\n  The SepMatrix.\n\nC++: dialect::AlignmentTable::addAlignments(const int &, const class dialect::SepMatrix &) --> void", pybind11::arg("nodes"), pybind11::arg("matrix"));
		cl.def("getAlignedIds", (int (dialect::AlignmentTable::*)(unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::getAlignedIds, "Get all IDs that are aligned with a given one.\n \n\n  The given ID.\n \n\n  The type of alignment you are interested in.\n \n\n  Vector of IDs of all nodes -- including this one -- that are aligned with this one.\n\nC++: dialect::AlignmentTable::getAlignedIds(unsigned int, enum dialect::AlignmentFlag) --> int", pybind11::arg("uid"), pybind11::arg("flag"));
		cl.def("noteInfeasibility", (void (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::noteInfeasibility, "Note that a particular alignment type is infeasible.\n \n\n  The id of one of the nodes that cannot be aligned.\n \n\n  The id of the other node that cannot be aligned.\n \n\n  The type of alignment whose infeasibility is to be recorded.\n\n \n  Client should pass HALIGN or VALIGN, i.e. the type of alignment that is infeasible,\n         NOT one of the _INFEAS flags itself.\n\nC++: dialect::AlignmentTable::noteInfeasibility(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> void", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
		cl.def("isMarkedInfeasible", (bool (dialect::AlignmentTable::*)(unsigned int, unsigned int, enum dialect::AlignmentFlag)) &dialect::AlignmentTable::isMarkedInfeasible, "Check whether a given type of alignemnt has been marked infeasible.\n \n\n  The id of one of the nodes in question.\n \n\n  The id of the other node in question.\n \n\n  The type of alignment in question.\n \n\n  true iff the alignment in question has been marked infeasible.\n\nC++: dialect::AlignmentTable::isMarkedInfeasible(unsigned int, unsigned int, enum dialect::AlignmentFlag) --> bool", pybind11::arg("uid"), pybind11::arg("vid"), pybind11::arg("flag"));
	}
	// dialect::manhattan(int, int) file:libdialect/nearalign.h line:105
	M("dialect").def("manhattan", (double (*)(int, int)) &dialect::manhattan, "Report the \"Manhattan distance\" between two nodes.\n\nC++: dialect::manhattan(int, int) --> double", pybind11::arg("u"), pybind11::arg("v"));

	{ // dialect::PotentialAlignment file:libdialect/nearalign.h line:108
		pybind11::class_<dialect::PotentialAlignment, std::shared_ptr<dialect::PotentialAlignment>> cl(M("dialect"), "PotentialAlignment", "");
		cl.def( pybind11::init<int, int, enum dialect::AlignmentFlag>(), pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("flag") );

		cl.def_readwrite("u", &dialect::PotentialAlignment::u);
		cl.def_readwrite("v", &dialect::PotentialAlignment::v);
		cl.def_readwrite("flag", &dialect::PotentialAlignment::flag);
		cl.def_readwrite("cost", &dialect::PotentialAlignment::cost);
		cl.def_readwrite("removed", &dialect::PotentialAlignment::removed);
		cl.def("remove", (void (dialect::PotentialAlignment::*)()) &dialect::PotentialAlignment::remove, "Remove from linked list.\n\nC++: dialect::PotentialAlignment::remove() --> void");
		cl.def("addToTable", (void (dialect::PotentialAlignment::*)(struct dialect::AlignmentTable &)) &dialect::PotentialAlignment::addToTable, "Add this alignment to an AlignmentTable.\n\nC++: dialect::PotentialAlignment::addToTable(struct dialect::AlignmentTable &) --> void", pybind11::arg("table"));
		cl.def("noteInfeasibility", (void (dialect::PotentialAlignment::*)(struct dialect::AlignmentTable &)) &dialect::PotentialAlignment::noteInfeasibility, "Note infeasibility of this alignment in in AlignmentTable.\n\nC++: dialect::PotentialAlignment::noteInfeasibility(struct dialect::AlignmentTable &) --> void", pybind11::arg("table"));
		cl.def("writeSepCo", (int (dialect::PotentialAlignment::*)()) &dialect::PotentialAlignment::writeSepCo, "Write a SepCo to represent this alignment.\n\nC++: dialect::PotentialAlignment::writeSepCo() --> int");
		cl.def("addToGraph", (void (dialect::PotentialAlignment::*)(class dialect::Graph &)) &dialect::PotentialAlignment::addToGraph, "Add this alignment to a Graph.\n\nC++: dialect::PotentialAlignment::addToGraph(class dialect::Graph &) --> void", pybind11::arg("G"));
	}
	// dialect::doNearAlignments(class dialect::Graph &, struct dialect::AlignmentTable &, int &, const int &, bool) file:libdialect/nearalign.h line:154
	M("dialect").def("doNearAlignments", [](class dialect::Graph & a0, struct dialect::AlignmentTable & a1, int & a2, const int & a3) -> unsigned long { return dialect::doNearAlignments(a0, a1, a2, a3); }, "", pybind11::arg("graph"), pybind11::arg("atab"), pybind11::arg("ignore"), pybind11::arg("opts"));
	M("dialect").def("doNearAlignments", (unsigned long (*)(class dialect::Graph &, struct dialect::AlignmentTable &, int &, const int &, bool)) &dialect::doNearAlignments, "Look for nodes that are nearly aligned, and try to align them.\n\n \n  The Graph whose nodes are to be aligned, and in whose SepMatrix alignments\n                        should be recorded when made.\n \n\n  An AlignmentTable for the given Graph.\n \n\n  HolaOpts object to set parameters for the process.\n \n\n  Set true for a more aggressive process that reattempts alignments even after\n                       they have been marked infeasible (in case other changes in the meantime might\n                       have made them now feasible). Default: false.\n \n\n  Number of successful alignments.\n\nC++: dialect::doNearAlignments(class dialect::Graph &, struct dialect::AlignmentTable &, int &, const int &, bool) --> unsigned long", pybind11::arg("graph"), pybind11::arg("atab"), pybind11::arg("ignore"), pybind11::arg("opts"), pybind11::arg("reattempt"));

	{ // dialect::OrthoHubLayoutOptions file:libdialect/nodeconfig.h line:38
		pybind11::class_<dialect::OrthoHubLayoutOptions, std::shared_ptr<dialect::OrthoHubLayoutOptions>> cl(M("dialect"), "OrthoHubLayoutOptions", "Options to control OrthoHubLayout");
		cl.def( pybind11::init( [](){ return new dialect::OrthoHubLayoutOptions(); } ) );
		cl.def_readwrite("avoidFlatTriangles", &dialect::OrthoHubLayoutOptions::avoidFlatTriangles);
		cl.def_readwrite("includeLinks", &dialect::OrthoHubLayoutOptions::includeLinks);
	}
	{ // dialect::OrthoHubLayout file:libdialect/nodeconfig.h line:62
		pybind11::class_<dialect::OrthoHubLayout, std::shared_ptr<dialect::OrthoHubLayout>> cl(M("dialect"), "OrthoHubLayout", "A layout object that tries to orthogonalise hubs.\n         This means it visits nodes of degrees 3 or higher, and\n         tries to set their neighbours in cardinal compass directions\n         from it.");
		cl.def( pybind11::init<int, struct dialect::OrthoHubLayoutOptions>(), pybind11::arg("G"), pybind11::arg("opts") );

		cl.def("layout", [](dialect::OrthoHubLayout &o) -> void { return o.layout(); }, "");
		cl.def("layout", (void (dialect::OrthoHubLayout::*)(struct dialect::Logger *)) &dialect::OrthoHubLayout::layout, "Try to orthogonalise hubs.\n\n \n  Optional logger to record the individual layout steps.\n\nC++: dialect::OrthoHubLayout::layout(struct dialect::Logger *) --> void", pybind11::arg("logger"));
	}
	// dialect::AspectRatioClass file:libdialect/opts.h line:32
	pybind11::enum_<dialect::AspectRatioClass>(M("dialect"), "AspectRatioClass", "")
		.value("NONE", dialect::AspectRatioClass::NONE)
		.value("PORTRAIT", dialect::AspectRatioClass::PORTRAIT)
		.value("LANDSCAPE", dialect::AspectRatioClass::LANDSCAPE);

;

	// dialect::TreeRoutingType file:libdialect/opts.h line:50
	pybind11::enum_<dialect::TreeRoutingType>(M("dialect"), "TreeRoutingType", "When routing connectors for Trees, the set of allowed connection directions\n depends on the application.\n\n In, for example, a NORTH-growing tree, an edge between ranks i and i + 1\n will always be allowed to connect only to the south (S) port of a node in\n rank i + 1.\n\n The TreeRoutingType controls the directions allowed for connection to nodes in\n rank i, as follows:\n\n STRICT:  only N is allowed.\n CORE_ATTACHMENT:  N, E, W are allowed for the root node if it has exactly one child and\n                   is transversely displaced from its one child; otherwise only N.\n MONOTONIC:  N, E, W are allowed for all nodes on rank i.")
		.value("STRICT", dialect::TreeRoutingType::STRICT)
		.value("CORE_ATTACHMENT", dialect::TreeRoutingType::CORE_ATTACHMENT)
		.value("MONOTONIC", dialect::TreeRoutingType::MONOTONIC);

;

	// dialect::ExpansionEstimateMethod file:libdialect/opts.h line:62
	pybind11::enum_<dialect::ExpansionEstimateMethod>(M("dialect"), "ExpansionEstimateMethod", "When expanding faces in order to make room to place the trees, there are different\n ways to estimate which is the best dimension in which to operate first.\n\n SPACE: Look at the available space in each dimension.\n CONSTRAINTS: Compute the separation constraints you would use in each dimension, and\n              sum their violations.")
		.value("SPACE", dialect::ExpansionEstimateMethod::SPACE)
		.value("CONSTRAINTS", dialect::ExpansionEstimateMethod::CONSTRAINTS);

;

}
