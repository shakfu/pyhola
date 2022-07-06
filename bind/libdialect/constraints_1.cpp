#include <functional>
#include <iterator>
#include <libavoid/router.h>
#include <libcola/cluster.h>
#include <libcola/compound_constraints.h>
#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/logging.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/routing.h>
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

void bind_libdialect_constraints_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::SepCo file:libdialect/constraints.h line:422
		pybind11::class_<dialect::SepCo, std::shared_ptr<dialect::SepCo>> cl(M("dialect"), "SepCo", "Simple struct to represent separation constraints in one dimension, in terms\n of Nodes (rather than Rectangle indices).\n\n Also supports separation constraints with negative gaps (unlike VPSC).\n Such constraints are perhaps better called \"containment constraints\". To illustrate,\n in the figure below\n\n             ---\n            | a |  ------|\n             ---         |\n                         |\n             ---         |\n            | b |        |\n             ---         |\n\n the separation constraint b.x - 100 <= a.x might mean that node b is constrained to\n stay to the left of the dashed line (which moves with node a).");
		cl.def( pybind11::init( [](enum vpsc::Dim const & a0, class std::shared_ptr<class dialect::Node> const & a1, class std::shared_ptr<class dialect::Node> const & a2, double const & a3){ return new dialect::SepCo(a0, a1, a2, a3); } ), "doc" , pybind11::arg("dim"), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"));
		cl.def( pybind11::init<enum vpsc::Dim, class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>, double, bool>(), pybind11::arg("dim"), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"), pybind11::arg("exact") );

		cl.def( pybind11::init( [](dialect::SepCo const &o){ return new dialect::SepCo(o); } ) );
		cl.def_readwrite("dim", &dialect::SepCo::dim);
		cl.def_readwrite("left", &dialect::SepCo::left);
		cl.def_readwrite("right", &dialect::SepCo::right);
		cl.def_readwrite("gap", &dialect::SepCo::gap);
		cl.def_readwrite("exact", &dialect::SepCo::exact);
		cl.def("getDirecRelativeToNode", (enum dialect::CardinalDir (dialect::SepCo::*)(class std::shared_ptr<class dialect::Node>) const) &dialect::SepCo::getDirecRelativeToNode, "Determine the constrained direction from one Node to the other.\n \n\n  The Node relative to which the direction is understood.\n \n\n A CardinalDir giving the direction from baseNode to the other node.\n\nC++: dialect::SepCo::getDirecRelativeToNode(class std::shared_ptr<class dialect::Node>) const --> enum dialect::CardinalDir", pybind11::arg("baseNode"));
		cl.def("addToMatrix", (void (dialect::SepCo::*)(class dialect::SepMatrix &) const) &dialect::SepCo::addToMatrix, "Add this constraint to a SepMatrix.\n\nC++: dialect::SepCo::addToMatrix(class dialect::SepMatrix &) const --> void", pybind11::arg("matrix"));
		cl.def("violation", (double (dialect::SepCo::*)() const) &dialect::SepCo::violation, "Determine the extent to which this separation constraint is currently violated.\n\nC++: dialect::SepCo::violation() const --> double");
		cl.def("toString", (std::string (dialect::SepCo::*)() const) &dialect::SepCo::toString, "Write a string representation.\n\nC++: dialect::SepCo::toString() const --> std::string");
	}
	{ // dialect::Projection file:libdialect/constraints.h line:466
		pybind11::class_<dialect::Projection, std::shared_ptr<dialect::Projection>> cl(M("dialect"), "Projection", "A Projection represents a set of constraints (given by SepCos), together\n with a dimension in which to project.");
		cl.def( pybind11::init<class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > >, enum vpsc::Dim>(), pybind11::arg("s"), pybind11::arg("d") );

		cl.def( pybind11::init( [](dialect::Projection const &o){ return new dialect::Projection(o); } ) );
		cl.def_readwrite("sepCoSet", &dialect::Projection::sepCoSet);
		cl.def_readwrite("dim", &dialect::Projection::dim);
		cl.def("size", (unsigned long (dialect::Projection::*)()) &dialect::Projection::size, "Check how many SepCos are in the projection.\n\nC++: dialect::Projection::size() --> unsigned long");
		cl.def("toString", (std::string (dialect::Projection::*)() const) &dialect::Projection::toString, "Write a string representation.\n\nC++: dialect::Projection::toString() const --> std::string");
	}
	{ // dialect::ProjSeq file:libdialect/constraints.h line:492
		pybind11::class_<dialect::ProjSeq, std::shared_ptr<dialect::ProjSeq>> cl(M("dialect"), "ProjSeq", "Projection Sequence. Manages a sequence of VPSC projections onto a monotonially\n increasing set of separation constraints.");
		cl.def( pybind11::init( [](){ return new dialect::ProjSeq(); } ) );
		cl.def( pybind11::init( [](dialect::ProjSeq const &o){ return new dialect::ProjSeq(o); } ) );
		cl.def("addProjection", (void (dialect::ProjSeq::*)(class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > >, enum vpsc::Dim)) &dialect::ProjSeq::addProjection, "Add a new set of SepCos, ensuring monotonicity by uniting with\n         the previous set of constraints in the same dimension, if any.\n \n\n  The new set of SepCos to be added.\n \n\n  The dimension in which the new set is to operate.\n\nC++: dialect::ProjSeq::addProjection(class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > >, enum vpsc::Dim) --> void", pybind11::arg("sepCos"), pybind11::arg("dim"));
		cl.def("nextProjection", (class std::shared_ptr<struct dialect::Projection> (dialect::ProjSeq::*)()) &dialect::ProjSeq::nextProjection, "Get the next Projection, if any.\n \n\n  The next Projection if there is another one, else nullptr.\n\nC++: dialect::ProjSeq::nextProjection() --> class std::shared_ptr<struct dialect::Projection>");
		cl.def("noteStresschange", (void (dialect::ProjSeq::*)(double)) &dialect::ProjSeq::noteStresschange, "Note a stress change.\n\nC++: dialect::ProjSeq::noteStresschange(double) --> void", pybind11::arg("dS"));
		cl.def("toString", (std::string (dialect::ProjSeq::*)() const) &dialect::ProjSeq::toString, "Write a string representation.\n\nC++: dialect::ProjSeq::toString() const --> std::string");
		cl.def("__iadd__", (class dialect::ProjSeq & (dialect::ProjSeq::*)(const class dialect::ProjSeq &)) &dialect::ProjSeq::operator+=, "When another ProjSeq is added to this one, we simply add each\n         Projection from the other one to this one, as usual. Thus is\n         monotonicity maintained, and this ProjSeq's pointer is left in place.\n\nC++: dialect::ProjSeq::operator+=(const class dialect::ProjSeq &) --> class dialect::ProjSeq &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"));
		cl.def("getAllConstraints", (class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > (dialect::ProjSeq::*)() const) &dialect::ProjSeq::getAllConstraints, "Get the set of all constraints, in both dimensions.\n\nC++: dialect::ProjSeq::getAllConstraints() const --> class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > >");
		cl.def("reset", (void (dialect::ProjSeq::*)()) &dialect::ProjSeq::reset, "Reset to start of sequence.\n\nC++: dialect::ProjSeq::reset() --> void");
		cl.def("violation", (double (dialect::ProjSeq::*)() const) &dialect::ProjSeq::violation, "Sum the violations of all SepCos in the final sets.\n\nC++: dialect::ProjSeq::violation() const --> double");
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

	{ // dialect::HolaOpts file:libdialect/opts.h line:67
		pybind11::class_<dialect::HolaOpts, std::shared_ptr<dialect::HolaOpts>> cl(M("dialect"), "HolaOpts", "");
		cl.def( pybind11::init( [](){ return new dialect::HolaOpts(); } ) );
		cl.def_readwrite("defaultTreeGrowthDir", &dialect::HolaOpts::defaultTreeGrowthDir);
		cl.def_readwrite("treeLayoutScalar_nodeSep", &dialect::HolaOpts::treeLayoutScalar_nodeSep);
		cl.def_readwrite("treeLayoutScalar_rankSep", &dialect::HolaOpts::treeLayoutScalar_rankSep);
		cl.def_readwrite("preferConvexTrees", &dialect::HolaOpts::preferConvexTrees);
		cl.def_readwrite("peeledTreeRouting", &dialect::HolaOpts::peeledTreeRouting);
		cl.def_readwrite("wholeTreeRouting", &dialect::HolaOpts::wholeTreeRouting);
		cl.def_readwrite("orthoHubAvoidFlatTriangles", &dialect::HolaOpts::orthoHubAvoidFlatTriangles);
		cl.def_readwrite("useACAforLinks", &dialect::HolaOpts::useACAforLinks);
		cl.def_readwrite("routingScalar_crossingPenalty", &dialect::HolaOpts::routingScalar_crossingPenalty);
		cl.def_readwrite("routingScalar_segmentPenalty", &dialect::HolaOpts::routingScalar_segmentPenalty);
		cl.def_readwrite("treePlacement_favourCardinal", &dialect::HolaOpts::treePlacement_favourCardinal);
		cl.def_readwrite("treePlacement_favourExternal", &dialect::HolaOpts::treePlacement_favourExternal);
		cl.def_readwrite("treePlacement_favourIsolation", &dialect::HolaOpts::treePlacement_favourIsolation);
		cl.def_readwrite("expansion_doCostlierDimensionFirst", &dialect::HolaOpts::expansion_doCostlierDimensionFirst);
		cl.def_readwrite("expansion_estimateMethod", &dialect::HolaOpts::expansion_estimateMethod);
		cl.def_readwrite("do_near_align", &dialect::HolaOpts::do_near_align);
		cl.def_readwrite("align_reps", &dialect::HolaOpts::align_reps);
		cl.def_readwrite("nearAlignScalar_kinkWidth", &dialect::HolaOpts::nearAlignScalar_kinkWidth);
		cl.def_readwrite("nearAlignScalar_scope", &dialect::HolaOpts::nearAlignScalar_scope);
		cl.def_readwrite("nodePaddingScalar", &dialect::HolaOpts::nodePaddingScalar);
		cl.def_readwrite("preferredAspectRatio", &dialect::HolaOpts::preferredAspectRatio);
		cl.def_readwrite("preferredTreeGrowthDir", &dialect::HolaOpts::preferredTreeGrowthDir);
		cl.def_readwrite("putUlcAtOrigin", &dialect::HolaOpts::putUlcAtOrigin);
	}
	{ // dialect::Logger file:libdialect/logging.h line:35
		pybind11::class_<dialect::Logger, std::shared_ptr<dialect::Logger>> cl(M("dialect"), "Logger", "");
		cl.def( pybind11::init( [](){ return new dialect::Logger(); } ), "doc" );
		cl.def( pybind11::init( [](std::string const & a0){ return new dialect::Logger(a0); } ), "doc" , pybind11::arg("outputDir"));
		cl.def( pybind11::init( [](std::string const & a0, std::string const & a1){ return new dialect::Logger(a0, a1); } ), "doc" , pybind11::arg("outputDir"), pybind11::arg("prefix"));
		cl.def( pybind11::init<std::string, std::string, bool>(), pybind11::arg("outputDir"), pybind11::arg("prefix"), pybind11::arg("verbose") );

		cl.def( pybind11::init( [](dialect::Logger const &o){ return new dialect::Logger(o); } ) );
		cl.def_readwrite("outputDir", &dialect::Logger::outputDir);
		cl.def_readwrite("prefix", &dialect::Logger::prefix);
		cl.def_readwrite("contents", &dialect::Logger::contents);
		cl.def_readwrite("names", &dialect::Logger::names);
		cl.def_readwrite("hasOutputDir", &dialect::Logger::hasOutputDir);
		cl.def_readwrite("hasPrefix", &dialect::Logger::hasPrefix);
		cl.def_readwrite("verbose", &dialect::Logger::verbose);
		cl.def_readwrite("nextLoggingIndex", &dialect::Logger::nextLoggingIndex);
		cl.def("log", [](dialect::Logger &o, std::string const & a0) -> void { return o.log(a0); }, "", pybind11::arg("content"));
		cl.def("log", (void (dialect::Logger::*)(std::string, std::string)) &dialect::Logger::log, "Record a string, optionally to a named file in the output dir.\n \n\n  The string to be recorded.\n \n\n  The name under which to record it.\n\nC++: dialect::Logger::log(std::string, std::string) --> void", pybind11::arg("content"), pybind11::arg("name"));
		cl.def("log", [](dialect::Logger &o, class dialect::Graph & a0) -> void { return o.log(a0); }, "", pybind11::arg("G"));
		cl.def("log", (void (dialect::Logger::*)(class dialect::Graph &, std::string)) &dialect::Logger::log, "Convenience method to log the TGLF for a Graph.\n \n\n  The Graph whose TGLF is to be logged.\n \n\n  The filename for the TGLF file WITHOUT the \".tglf\" suffix. The suffix\n                  is automatically added for you.\n\nC++: dialect::Logger::log(class dialect::Graph &, std::string) --> void", pybind11::arg("G"), pybind11::arg("name"));
		cl.def("writeFullPathForFilename", (std::string (dialect::Logger::*)(std::string)) &dialect::Logger::writeFullPathForFilename, "Given a filename, prepend the output directory and prefix (if given) in order\n         to write the full path.\n \n\n The full path.\n\nC++: dialect::Logger::writeFullPathForFilename(std::string) --> std::string", pybind11::arg("name"));
	}
	// dialect::RouteProcessing file:libdialect/routing.h line:46
	pybind11::enum_<dialect::RouteProcessing>(M("dialect"), "RouteProcessing", "Control how much processing should be done on connector routes by the RoutingAdapter.")
		.value("NONE", dialect::RouteProcessing::NONE)
		.value("RECORD", dialect::RouteProcessing::RECORD)
		.value("REFINE_AND_RECORD", dialect::RouteProcessing::REFINE_AND_RECORD);

;

	{ // dialect::RoutingAdapter file:libdialect/routing.h line:57
		pybind11::class_<dialect::RoutingAdapter, std::shared_ptr<dialect::RoutingAdapter>> cl(M("dialect"), "RoutingAdapter", "Adapter to easily apply libavoid::Routers to libdialect::Graphs.");
		cl.def( pybind11::init<enum Avoid::RouterFlag>(), pybind11::arg("flag") );

		cl.def( pybind11::init( [](dialect::RoutingAdapter const &o){ return new dialect::RoutingAdapter(o); } ) );
		cl.def_readwrite("router", &dialect::RoutingAdapter::router);
		cl.def_readwrite("edges", &dialect::RoutingAdapter::edges);
		cl.def_readwrite("edgeIdToConnRef", &dialect::RoutingAdapter::edgeIdToConnRef);
		cl.def_readwrite("nodeIdToShapeRef", &dialect::RoutingAdapter::nodeIdToShapeRef);
		cl.def("addNodes", (void (dialect::RoutingAdapter::*)(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &)) &dialect::RoutingAdapter::addNodes, "Add nodes.\n \n\n  The Nodes to be added, given by a NodesById mapping.\n\nC++: dialect::RoutingAdapter::addNodes(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &) --> void", pybind11::arg("nodes"));
		cl.def("route", [](dialect::RoutingAdapter &o) -> void { return o.route(); }, "");
		cl.def("route", (void (dialect::RoutingAdapter::*)(enum dialect::RouteProcessing)) &dialect::RoutingAdapter::route, "Do the routing.\n \n\n  Set to the desired level of route processing. Default: routes are\n                        recorded in Edges, without any post-processing.\n \n\n RouteProcessing enum.\n\nC++: dialect::RoutingAdapter::route(enum dialect::RouteProcessing) --> void", pybind11::arg("processing"));
		cl.def("recordRoutes", [](dialect::RoutingAdapter &o) -> void { return o.recordRoutes(); }, "");
		cl.def("recordRoutes", (void (dialect::RoutingAdapter::*)(bool)) &dialect::RoutingAdapter::recordRoutes, "Record the routes in the Edges.\n \n\n  Say whether the routes should be refined before recording.\n\nC++: dialect::RoutingAdapter::recordRoutes(bool) --> void", pybind11::arg("refine"));
	}
}
