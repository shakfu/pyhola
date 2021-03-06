#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/connend.h>
#include <libavoid/geomtypes.h>
#include <libavoid/router.h>
#include <libcola/cluster.h>
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

void bind_libdialect_logging(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::Logger file:libdialect/logging.h line:35
		pybind11::class_<dialect::Logger, std::shared_ptr<dialect::Logger>> cl(M("dialect"), "Logger", "");
		cl.def( pybind11::init( [](dialect::Logger const &o){ return new dialect::Logger(o); } ) );
		cl.def_readwrite("outputDir", &dialect::Logger::outputDir);
		cl.def_readwrite("prefix", &dialect::Logger::prefix);
		cl.def_readwrite("contents", &dialect::Logger::contents);
		cl.def_readwrite("names", &dialect::Logger::names);
		cl.def_readwrite("hasOutputDir", &dialect::Logger::hasOutputDir);
		cl.def_readwrite("hasPrefix", &dialect::Logger::hasPrefix);
		cl.def_readwrite("verbose", &dialect::Logger::verbose);
		cl.def_readwrite("nextLoggingIndex", &dialect::Logger::nextLoggingIndex);
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
		cl.def("route", [](dialect::RoutingAdapter &o) -> void { return o.route(); }, "");
		cl.def("route", (void (dialect::RoutingAdapter::*)(enum dialect::RouteProcessing)) &dialect::RoutingAdapter::route, "Do the routing.\n \n\n  Set to the desired level of route processing. Default: routes are\n                        recorded in Edges, without any post-processing.\n \n\n RouteProcessing enum.\n\nC++: dialect::RoutingAdapter::route(enum dialect::RouteProcessing) --> void", pybind11::arg("processing"));
		cl.def("recordRoutes", [](dialect::RoutingAdapter &o) -> void { return o.recordRoutes(); }, "");
		cl.def("recordRoutes", (void (dialect::RoutingAdapter::*)(bool)) &dialect::RoutingAdapter::recordRoutes, "Record the routes in the Edges.\n \n\n  Say whether the routes should be refined before recording.\n\nC++: dialect::RoutingAdapter::recordRoutes(bool) --> void", pybind11::arg("refine"));
	}
	{ // dialect::LeaflessOrthoRouter file:libdialect/routing.h line:102
		pybind11::class_<dialect::LeaflessOrthoRouter, std::shared_ptr<dialect::LeaflessOrthoRouter>> cl(M("dialect"), "LeaflessOrthoRouter", "Does a special orthogonal routing in a graph having no leaves,\n         ensuring that at least two distinct sides of every node are\n         used as connection points. This is useful if we later wish to\n         planarise the layout, since it ensures that no node will become\n         a leaf in that process.");
		cl.def( pybind11::init( [](dialect::LeaflessOrthoRouter const &o){ return new dialect::LeaflessOrthoRouter(o); } ) );
		cl.def_readwrite("recordEachAttempt", &dialect::LeaflessOrthoRouter::recordEachAttempt);
		cl.def_readwrite("routingAttemptTglf", &dialect::LeaflessOrthoRouter::routingAttemptTglf);
		cl.def("route", [](dialect::LeaflessOrthoRouter &o) -> void { return o.route(); }, "");
		cl.def("route", (void (dialect::LeaflessOrthoRouter::*)(struct dialect::Logger *)) &dialect::LeaflessOrthoRouter::route, "Do the routing.\n\nC++: dialect::LeaflessOrthoRouter::route(struct dialect::Logger *) --> void", pybind11::arg("logger"));
		cl.def("setShapeBufferDistanceIELScalar", (void (dialect::LeaflessOrthoRouter::*)(double)) &dialect::LeaflessOrthoRouter::setShapeBufferDistanceIELScalar, "Set the Router's shapeBufferDistance parameter as a scalar multiple of the\n         ideal edge length read from the Graph.\n \n\n  This is provided only as a convenience for testing. In the HOLA algorithm\n           for which this is designed, shapeBufferDistance should always be zero.\n           Positive values there may result in failures to route.\n           HOLA uses its own node padding instead, for this purpose.\n\nC++: dialect::LeaflessOrthoRouter::setShapeBufferDistanceIELScalar(double) --> void", pybind11::arg("a"));
	}
	{ // dialect::BoundingBox file:libdialect/graphs.h line:52
		pybind11::class_<dialect::BoundingBox, std::shared_ptr<dialect::BoundingBox>> cl(M("dialect"), "BoundingBox", "A bounding box, given by the extreme coordinates.");
		cl.def( pybind11::init<double, double, double, double>(), pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y") );

		cl.def( pybind11::init( [](){ return new dialect::BoundingBox(); } ) );
		cl.def( pybind11::init( [](dialect::BoundingBox const &o){ return new dialect::BoundingBox(o); } ) );
		cl.def_readwrite("x", &dialect::BoundingBox::x);
		cl.def_readwrite("X", &dialect::BoundingBox::X);
		cl.def_readwrite("y", &dialect::BoundingBox::y);
		cl.def_readwrite("Y", &dialect::BoundingBox::Y);
		cl.def("__iadd__", (struct dialect::BoundingBox & (dialect::BoundingBox::*)(const struct dialect::BoundingBox &)) &dialect::BoundingBox::operator+=, "Adding two bounding boxes returns the bounding box of their union.\n\nC++: dialect::BoundingBox::operator+=(const struct dialect::BoundingBox &) --> struct dialect::BoundingBox &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"));
		cl.def("w", (double (dialect::BoundingBox::*)() const) &dialect::BoundingBox::w, "Get the width of the box.\n\nC++: dialect::BoundingBox::w() const --> double");
		cl.def("h", (double (dialect::BoundingBox::*)() const) &dialect::BoundingBox::h, "Get the height of the box.\n\nC++: dialect::BoundingBox::h() const --> double");
		cl.def("centre", (class Avoid::Point (dialect::BoundingBox::*)() const) &dialect::BoundingBox::centre, "Get the centre of the box.\n\nC++: dialect::BoundingBox::centre() const --> class Avoid::Point");
		cl.def("perimeter", (double (dialect::BoundingBox::*)() const) &dialect::BoundingBox::perimeter, "Compute the perimeter of the box.\n\nC++: dialect::BoundingBox::perimeter() const --> double");
	}
	{ // dialect::ColaOptions file:libdialect/graphs.h line:105
		pybind11::class_<dialect::ColaOptions, std::shared_ptr<dialect::ColaOptions>> cl(M("dialect"), "ColaOptions", "Provides a simple way to set any or all of the various\n         optional arguments to libcola layout methods.");
		cl.def( pybind11::init( [](){ return new dialect::ColaOptions(); } ) );
		cl.def( pybind11::init( [](dialect::ColaOptions const &o){ return new dialect::ColaOptions(o); } ) );
		cl.def_readwrite("idealEdgeLength", &dialect::ColaOptions::idealEdgeLength);
		cl.def_readwrite("preventOverlaps", &dialect::ColaOptions::preventOverlaps);
		cl.def_readwrite("solidifyAlignedEdges", &dialect::ColaOptions::solidifyAlignedEdges);
		cl.def_readwrite("solidEdgeExemptions", &dialect::ColaOptions::solidEdgeExemptions);
		cl.def_readwrite("xAxis", &dialect::ColaOptions::xAxis);
		cl.def_readwrite("yAxis", &dialect::ColaOptions::yAxis);
		cl.def_readwrite("makeFeasible", &dialect::ColaOptions::makeFeasible);
		cl.def_readwrite("makeFeasible_xBorder", &dialect::ColaOptions::makeFeasible_xBorder);
		cl.def_readwrite("makeFeasible_yBorder", &dialect::ColaOptions::makeFeasible_yBorder);
		cl.def_readwrite("useNeighbourStress", &dialect::ColaOptions::useNeighbourStress);
		cl.def_readwrite("nbrStressIELScalar", &dialect::ColaOptions::nbrStressIELScalar);
		cl.def_readwrite("useMajorization", &dialect::ColaOptions::useMajorization);
		cl.def_readwrite("useScaling", &dialect::ColaOptions::useScaling);
		cl.def_readwrite("ccs", &dialect::ColaOptions::ccs);
		cl.def_readwrite("nodeClusters", &dialect::ColaOptions::nodeClusters);
		cl.def_readwrite("eLengths", &dialect::ColaOptions::eLengths);
	}
	{ // dialect::ColaGraphRep file:libdialect/graphs.h line:157
		pybind11::class_<dialect::ColaGraphRep, std::shared_ptr<dialect::ColaGraphRep>> cl(M("dialect"), "ColaGraphRep", "Bundles those data structures required in order to represent\n         a Graph in libcola, and to map infomration between the libcola\n         and libdialect representations.");
		cl.def( pybind11::init( [](dialect::ColaGraphRep const &o){ return new dialect::ColaGraphRep(o); } ) );
		cl.def( pybind11::init( [](){ return new dialect::ColaGraphRep(); } ) );
		cl.def_readwrite("rs", &dialect::ColaGraphRep::rs);
		cl.def_readwrite("es", &dialect::ColaGraphRep::es);
		cl.def_readwrite("id2ix", &dialect::ColaGraphRep::id2ix);
		cl.def_readwrite("ix2id", &dialect::ColaGraphRep::ix2id);
		cl.def("assign", (struct dialect::ColaGraphRep & (dialect::ColaGraphRep::*)(const struct dialect::ColaGraphRep &)) &dialect::ColaGraphRep::operator=, "C++: dialect::ColaGraphRep::operator=(const struct dialect::ColaGraphRep &) --> struct dialect::ColaGraphRep &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::NodeIdCmp file:libdialect/graphs.h line:169
		pybind11::class_<dialect::NodeIdCmp, std::shared_ptr<dialect::NodeIdCmp>> cl(M("dialect"), "NodeIdCmp", "Useful for set operations on Node lookups.\n \n\n  Thanks to https://stackoverflow.com/a/15579928");
		cl.def( pybind11::init( [](){ return new dialect::NodeIdCmp(); } ) );
	}
	{ // dialect::Graph file:libdialect/graphs.h line:180
		pybind11::class_<dialect::Graph, std::shared_ptr<dialect::Graph>> cl(M("dialect"), "Graph", "The Graph class represents graphs consisting of nodes and edges.");
		cl.def( pybind11::init( [](){ return new dialect::Graph(); } ) );
		cl.def( pybind11::init( [](dialect::Graph const &o){ return new dialect::Graph(o); } ) );
		cl.def_readwrite("m_debugOutputPath", &dialect::Graph::m_debugOutputPath);
		cl.def_readwrite("m_projectionDebugLevel", &dialect::Graph::m_projectionDebugLevel);
		cl.def("assign", (class dialect::Graph & (dialect::Graph::*)(const class dialect::Graph)) &dialect::Graph::operator=, "Copy-assignment operator.\n \n\n  Pass-by-value is deliberate. See https://stackoverflow.com/a/3279550\n\nC++: dialect::Graph::operator=(const class dialect::Graph) --> class dialect::Graph &", pybind11::return_value_policy::automatic, pybind11::arg("other"));
		cl.def("getMaxDegree", (unsigned int (dialect::Graph::*)() const) &dialect::Graph::getMaxDegree, "Reports the maximum degree of any Node in this Graph.\n\n The value is automatically maintained as you add or remove Nodes\n from the Graph.\n\n \n  Maximum degree of any Node in the Graph.\n\nC++: dialect::Graph::getMaxDegree() const --> unsigned int");
		cl.def("hasNode", (bool (dialect::Graph::*)(const unsigned int &) const) &dialect::Graph::hasNode, "Say whether this Graph has a Node of the given ID.\n\n \n  boolean\n\nC++: dialect::Graph::hasNode(const unsigned int &) const --> bool", pybind11::arg("id"));
		cl.def("hasEdge", (bool (dialect::Graph::*)(const unsigned int &) const) &dialect::Graph::hasEdge, "Say whether this Graph has an Edge of the given ID.\n\n \n  boolean\n\nC++: dialect::Graph::hasEdge(const unsigned int &) const --> bool", pybind11::arg("id"));
		cl.def("severEdge", (void (dialect::Graph::*)(class dialect::Edge &)) &dialect::Graph::severEdge, "Sever an Edge in this Graph.\n\n The Edge is removed from the Graph, and from both of its endpoint\n Nodes as well.\n\n \n  The Edge to be severed from the Graph.\n\nC++: dialect::Graph::severEdge(class dialect::Edge &) --> void", pybind11::arg("edge"));
		cl.def("severNode", (void (dialect::Graph::*)(const class dialect::Node &)) &dialect::Graph::severNode, "Sever all the Edges incident to a Node in this Graph.\n\n \n  This method only cuts the incident Edges; it does /not/ also\n        remove the Node itself from the Graph.\n\n \n  The Node whose Edges are to be severed.\n\n \n severAndRemoveNode\n\nC++: dialect::Graph::severNode(const class dialect::Node &) --> void", pybind11::arg("node"));
		cl.def("removeNode", (void (dialect::Graph::*)(const class dialect::Node &)) &dialect::Graph::removeNode, "Remove a Node from this Graph.\n\n \n  This method only removes the Node itself; it does not also\n        sever the incident Edges.\n\n \n  The Node to be removed from the Graph.\n\n \n severAndRemoveNode\n\nC++: dialect::Graph::removeNode(const class dialect::Node &) --> void", pybind11::arg("node"));
		cl.def("severAndRemoveNode", (void (dialect::Graph::*)(const class dialect::Node &)) &dialect::Graph::severAndRemoveNode, "Convenience method to completely remove a Node from the Graph.\n\n \n severNode\n \n\n removeNode\n\nC++: dialect::Graph::severAndRemoveNode(const class dialect::Node &) --> void", pybind11::arg("node"));
		cl.def("severAndRemoveNode", (void (dialect::Graph::*)(unsigned int)) &dialect::Graph::severAndRemoveNode, "Convenience method to completely remove a Node from the Graph.\n\n \n severNode\n \n\n removeNode\n\nC++: dialect::Graph::severAndRemoveNode(unsigned int) --> void", pybind11::arg("nodeID"));
		cl.def("getNumNodes", (unsigned long (dialect::Graph::*)() const) &dialect::Graph::getNumNodes, "Say how many Nodes there are in this Graph.\n\nC++: dialect::Graph::getNumNodes() const --> unsigned long");
		cl.def("getNumEdges", (unsigned long (dialect::Graph::*)() const) &dialect::Graph::getNumEdges, "Say how many Edges there are in this Graph.\n\nC++: dialect::Graph::getNumEdges() const --> unsigned long");
		cl.def("isEmpty", (bool (dialect::Graph::*)() const) &dialect::Graph::isEmpty, "Say whether the Graph is empty, meaning that it has no Nodes.\n\nC++: dialect::Graph::isEmpty() const --> bool");
		cl.def("isTree", (bool (dialect::Graph::*)() const) &dialect::Graph::isTree, "Say whether the Graph is a tree.\n\nC++: dialect::Graph::isTree() const --> bool");
		cl.def("computeAvgNodeDim", (double (dialect::Graph::*)() const) &dialect::Graph::computeAvgNodeDim, "Compute the average of all heights and widths of Nodes\n         in this Graph.\n\n \n  The average.\n\nC++: dialect::Graph::computeAvgNodeDim() const --> double");
		cl.def("getIEL", (double (dialect::Graph::*)()) &dialect::Graph::getIEL, "Read the ideal edge length of this Graph.\n\n \n  If the current value is zero (which is true of all new Graphs), the Graph\n        will first auto-infer an ideal edge length equal to twice the average node\n        dimension, store that value, and return it.\n\n \n  Once this method has been called, the Graph will NOT recompute its IEL\n           on subsequent calls, even if Nodes have been added or taken away.\n\n \n Graph::recomputeIEL\n\nC++: dialect::Graph::getIEL() --> double");
		cl.def("recomputeIEL", (double (dialect::Graph::*)()) &dialect::Graph::recomputeIEL, "Recompute, store, and return the Graph's ideal edge length.\n\n \n  As in the getIEL method, the value will be twice the average dimension\n        of Nodes currently in the Graph.\n\n \n Graph::getIEL\n\nC++: dialect::Graph::recomputeIEL() --> double");
		cl.def("rotate90cw", [](dialect::Graph &o) -> void { return o.rotate90cw(); }, "");
		cl.def("rotate90cw", (void (dialect::Graph::*)(struct dialect::ColaOptions *)) &dialect::Graph::rotate90cw, "Rotate the layout -- and the constraints -- 90 degrees clockwise.\n \n\n  ColaOptions to control destressing operation after rotation.\n                  This is optional; pass nullptr if you do not want to destress.\n \n\n If any nodes are non-square, i.e. have aspect ratio different from 1:1, then destressing\n       is recommended after a 90-degree rotation. The relationships between oblong nodes can\n       change dramatically when rotating 90 degrees.\n \n\n Graph::rotate90acw\n \n\n Graph::rotate180\n\nC++: dialect::Graph::rotate90cw(struct dialect::ColaOptions *) --> void", pybind11::arg("opts"));
		cl.def("rotate90acw", [](dialect::Graph &o) -> void { return o.rotate90acw(); }, "");
		cl.def("rotate90acw", (void (dialect::Graph::*)(struct dialect::ColaOptions *)) &dialect::Graph::rotate90acw, "Rotate the layout -- and the constraints -- 90 degrees anticlockwise.\n \n\n  ColaOptions to control destressing operation after rotation.\n                  This is optional; pass nullptr if you do not want to destress.\n \n\n If any nodes are non-square, i.e. have aspect ratio different from 1:1, then destressing\n       is recommended after a 90-degree rotation. The relationships between oblong nodes can\n       change dramatically when rotating 90 degrees.\n \n\n Graph::rotate90cw\n \n\n Graph::rotate180\n\nC++: dialect::Graph::rotate90acw(struct dialect::ColaOptions *) --> void", pybind11::arg("opts"));
		cl.def("rotate180", (void (dialect::Graph::*)()) &dialect::Graph::rotate180, "Rotate the layout -- and the constraints -- 180 degrees.\n \n\n Unlinke the 90-degree rotations, rotating 180 degrees can be viewed as a simple rigid\n       transformation, and there is no reason to destress afterward.\n \n\n Graph::rotate90cw\n \n\n Graph::rotate90acw\n\nC++: dialect::Graph::rotate180() --> void");
		cl.def("translate", (void (dialect::Graph::*)(double, double)) &dialect::Graph::translate, "Translate the entire layout by a given amount in each dimension.\n \n\n  The amount by which to translate in the x-dimension.\n \n\n  The amount by which to translate in the y-dimension.\n\nC++: dialect::Graph::translate(double, double) --> void", pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("putInBasePosition", (void (dialect::Graph::*)()) &dialect::Graph::putInBasePosition, "Put the Graph into a basic position useful for making unit test inputs.\n         The Nodes are put in a row, all Edge routes are cleared, and all constraints\n         are cleared.\n\n         The criteria are: (1) all nodes have distinct positions, and (2) the\n         layout is a bad one. Condition (1) is needed so that Cola doesn't generate\n         random starting positions.\n\nC++: dialect::Graph::putInBasePosition() --> void");
		cl.def("destress", (void (dialect::Graph::*)(const struct dialect::ColaOptions &)) &dialect::Graph::destress, "Reduce stress via libcola's gradient-descent procedures.\n\n \n  options to control the layout.\n\n \n  In opts, set the idealEdgeLength to 0 if you want the Graph to automatically\n        supply a reasonable ideal edge length.\n\nC++: dialect::Graph::destress(const struct dialect::ColaOptions &) --> void", pybind11::arg("opts"));
		cl.def("destress", (void (dialect::Graph::*)()) &dialect::Graph::destress, "Convenience method to destress with default options.\n\nC++: dialect::Graph::destress() --> void");
		cl.def("solidifyAlignedEdges", (void (dialect::Graph::*)(enum vpsc::Dim, const struct dialect::ColaOptions &)) &dialect::Graph::solidifyAlignedEdges, "Add Nodes to represent aligned Edges in one dimension, constraining them to stay aligned.\n \n\n  Solidify only those aligned Edges whose variable coordinate is in this dimension.\n                 Thus, horizontally aligned edges for XDIM; vertically aligned for YDIM.\n \n\n  Here you can set Edge exemptions, i.e. a set of Edges that should not be solidified.\n\nC++: dialect::Graph::solidifyAlignedEdges(enum vpsc::Dim, const struct dialect::ColaOptions &) --> void", pybind11::arg("dim"), pybind11::arg("opts"));
		cl.def("makeFeasible", (void (dialect::Graph::*)(const struct dialect::ColaOptions &)) &dialect::Graph::makeFeasible, "Make feasible. This means that, among those constraints that offer alternatives,\n         we look for satisfiable alternatives in order of increasing cost (cost = separation violation).\n This is useful with nonoverlap constraints.\n\n \n  The usual ColaOptions.\n \n\n  Simply uses the method by the same name in the cola::ConstrainedFDLayout class.\n\nC++: dialect::Graph::makeFeasible(const struct dialect::ColaOptions &) --> void", pybind11::arg("opts"));
		cl.def("project", [](dialect::Graph &o, const struct dialect::ColaOptions & a0, enum vpsc::Dim const & a1) -> int { return o.project(a0, a1); }, "", pybind11::arg("opts"), pybind11::arg("dim"));
		cl.def("project", (int (dialect::Graph::*)(const struct dialect::ColaOptions &, enum vpsc::Dim, int)) &dialect::Graph::project, "Project onto cola constraints.\n \n\n  Options, including any additional constraints onto which to project\n                  (in addition to the Graph's existing SepMatrix).\n \n\n            All options relating to edge length are ignored, since this is only a projection.\n \n\n  The dimension in which to project.\n \n\n  Acceptance level. See doctext for cola::projectOntoCCs.\n \n\n  Error level. See cola::projectOntoCCs.\n\nC++: dialect::Graph::project(const struct dialect::ColaOptions &, enum vpsc::Dim, int) --> int", pybind11::arg("opts"), pybind11::arg("dim"), pybind11::arg("accept"));
		cl.def("applyProjSeq", [](dialect::Graph &o, const struct dialect::ColaOptions & a0, class dialect::ProjSeq & a1) -> bool { return o.applyProjSeq(a0, a1); }, "", pybind11::arg("opts"), pybind11::arg("ps"));
		cl.def("applyProjSeq", (bool (dialect::Graph::*)(const struct dialect::ColaOptions &, class dialect::ProjSeq &, int)) &dialect::Graph::applyProjSeq, "Attempt to apply the projections given by a ProjSeq object.\n         Give up as soon as any of them fails.\n \n\n  Options.\n \n\n  The ProjSeq to be applied.\n \n\n  Acceptance level. See doctext for cola::projectOntoCCs.\n\n \n  In addition to the zero idealEdgeLength convention employed by the destress\n        method, here a negative idealEdgeLength in the opts parameter may be used\n        to indicate that you do not want the stress changes induced by the projections\n        to be evaluated. Otherwise they will be.\n \n\n boolean, saying whether all the projections were successful, at the given\n         acceptance level.\n\nC++: dialect::Graph::applyProjSeq(const struct dialect::ColaOptions &, class dialect::ProjSeq &, int) --> bool", pybind11::arg("opts"), pybind11::arg("ps"), pybind11::arg("accept"));
		cl.def("updateNodesFromRects", [](dialect::Graph &o) -> void { return o.updateNodesFromRects(); }, "");
		cl.def("updateNodesFromRects", [](dialect::Graph &o, bool const & a0) -> void { return o.updateNodesFromRects(a0); }, "", pybind11::arg("xAxis"));
		cl.def("updateNodesFromRects", (void (dialect::Graph::*)(bool, bool)) &dialect::Graph::updateNodesFromRects, "For use with various layout actions, this method asks the Graph\n         to update Node positions based on its internal vpsc Rectangles that\n         were used in the layout operation.\n \n\n  Set true iff the x-coordinates of the nodes should be updated.\n \n\n  Set true iff the y-coordinates of the nodes should be updated.\n\nC++: dialect::Graph::updateNodesFromRects(bool, bool) --> void", pybind11::arg("xAxis"), pybind11::arg("yAxis"));
		cl.def("updateColaGraphRep", (struct dialect::ColaGraphRep & (dialect::Graph::*)()) &dialect::Graph::updateColaGraphRep, "Refresh, as needed, the data structures necessary for applying the\n         methods of libcola to this Graph.\n\n \n  If Nodes have been added to or removed from the Graph since the\n           last time this method was called, the old Rectangles will be\n           deleted.\n\n           Clients are therefore advised to utilise methods like Graph::destress\n           instead of creating their own instances of ConstrainedFDLayout. At the\n           least, they must not reuse layout objects that were created before\n           adding or removing Nodes from the Graph (which makes sense anyway).\n\n \n  A reference to the (updated) ColaGraphRep.\n\nC++: dialect::Graph::updateColaGraphRep() --> struct dialect::ColaGraphRep &", pybind11::return_value_policy::automatic);
		cl.def("buildRootCluster", (class cola::RootCluster * (dialect::Graph::*)(const struct dialect::ColaOptions &)) &dialect::Graph::buildRootCluster, "Build a cola::RootCluster based on the node clusters specified in a ColaOptions\n         object.\n \n\n  The RootCluster will also be stored in the Graph's ColaGraphRep.\n \n\n The old RootCluster stored in the Graph's ColaGraphRep (if any) will be deleted.\n \n\n The RootCluster.\n\nC++: dialect::Graph::buildRootCluster(const struct dialect::ColaOptions &) --> class cola::RootCluster *", pybind11::return_value_policy::automatic, pybind11::arg("opts"));
		cl.def("getColaGraphRep", (struct dialect::ColaGraphRep & (dialect::Graph::*)()) &dialect::Graph::getColaGraphRep, "Access the cola graph rep for this Graph.\n\nC++: dialect::Graph::getColaGraphRep() --> struct dialect::ColaGraphRep &", pybind11::return_value_policy::automatic);
		cl.def("getSepMatrix", (class dialect::SepMatrix & (dialect::Graph::*)()) &dialect::Graph::getSepMatrix, "Access the separation matrix for this Graph.\n\nC++: dialect::Graph::getSepMatrix() --> class dialect::SepMatrix &", pybind11::return_value_policy::automatic);
		cl.def("pushNodePositions", (void (dialect::Graph::*)()) &dialect::Graph::pushNodePositions, "Save node positions on internal stack.\n\nC++: dialect::Graph::pushNodePositions() --> void");
		cl.def("popNodePositions", (bool (dialect::Graph::*)()) &dialect::Graph::popNodePositions, "Restore node positions from internal stack.\n \n\n  true if positions were restored; false if stack was empty\n\nC++: dialect::Graph::popNodePositions() --> bool");
		cl.def("setEdgeThickness", (void (dialect::Graph::*)(double)) &dialect::Graph::setEdgeThickness, "Set the edge thickness.\n\nC++: dialect::Graph::setEdgeThickness(double) --> void", pybind11::arg("t"));
		cl.def("getEdgeThickness", (double (dialect::Graph::*)()) &dialect::Graph::getEdgeThickness, "Get the edge thickness.\n\nC++: dialect::Graph::getEdgeThickness() --> double");
		cl.def("padAllNodes", (void (dialect::Graph::*)(double, double)) &dialect::Graph::padAllNodes, "Add padding to all ndoes.\n\nC++: dialect::Graph::padAllNodes(double, double) --> void", pybind11::arg("dw"), pybind11::arg("dh"));
		cl.def("setPosesInCorrespNodes", (void (dialect::Graph::*)(class dialect::Graph &)) &dialect::Graph::setPosesInCorrespNodes, "Update positions of Nodes in a given Graph to equal those of the\n         corresponding Nodes (same ID) in this Graph.\n \n\n  The Graph whose Node positions are to be updated.\n\nC++: dialect::Graph::setPosesInCorrespNodes(class dialect::Graph &) --> void", pybind11::arg("H"));
		cl.def("setRoutesInCorrespEdges", [](dialect::Graph &o, class dialect::Graph & a0) -> void { return o.setRoutesInCorrespEdges(a0); }, "", pybind11::arg("H"));
		cl.def("setRoutesInCorrespEdges", (void (dialect::Graph::*)(class dialect::Graph &, bool)) &dialect::Graph::setRoutesInCorrespEdges, "Update routes of Edges in a given Graph to equal those of the\n         corresponding Edges (same source and target) in this Graph.\n \n\n  The Graph whose Edge routes are to be updated.\n \n\n  Set true if Edges are to be understood as directed, i.e. if\n                      in order to match the Edges have to have the same source and\n                      the same target. Otherwise only the set {source ID, target ID}\n                      has to be the same. Default: false (i.e. undirected edges).\n\nC++: dialect::Graph::setRoutesInCorrespEdges(class dialect::Graph &, bool) --> void", pybind11::arg("H"), pybind11::arg("directed"));
		cl.def("route", (void (dialect::Graph::*)(enum Avoid::RouterFlag)) &dialect::Graph::route, "Do a libavoid connector routing on all Edges in the Graph.\n \n\n  The type of routing you want (orthogonal or polyline).\n\nC++: dialect::Graph::route(enum Avoid::RouterFlag) --> void", pybind11::arg("routingType"));
		cl.def("clearAllRoutes", (void (dialect::Graph::*)()) &dialect::Graph::clearAllRoutes, "Clear all Edge routes.\n\nC++: dialect::Graph::clearAllRoutes() --> void");
		cl.def("buildRoutes", (void (dialect::Graph::*)()) &dialect::Graph::buildRoutes, "Ask all Edges to build their routes based on their bend nodes.\n\nC++: dialect::Graph::buildRoutes() --> void");
		cl.def("addBendlessSubnetworkToRoutingAdapter", (void (dialect::Graph::*)(struct dialect::RoutingAdapter &)) &dialect::Graph::addBendlessSubnetworkToRoutingAdapter, "Add all Nodes, and all those Edges having no bend nodes within them, to a given\n        RoutingAdapter. This is useful when precisely those Edges are viewed as needing\n        a route which do not already have any bend nodes.\n \n\n  The RoutingAdapter to which the Nodes and Edges are to be added.\n\nC++: dialect::Graph::addBendlessSubnetworkToRoutingAdapter(struct dialect::RoutingAdapter &) --> void", pybind11::arg("ra"));
		cl.def("clearAllConstraints", (void (dialect::Graph::*)()) &dialect::Graph::clearAllConstraints, "Clear all constraints in this Graph's SepMatrix.\n\nC++: dialect::Graph::clearAllConstraints() --> void");
		cl.def("setCorrespondingConstraints", (void (dialect::Graph::*)(class dialect::Graph &)) &dialect::Graph::setCorrespondingConstraints, "Set corresponding constraints in another Graph.\n         This means that for each constraint between nodes of IDs id1 and id2 in this\n         Graph's SepMatrix, we set that constraint in the other Graph if and only if it too\n         contains Nodes of IDs id1 and id2.\n \n\n  The other Graph.\n\nC++: dialect::Graph::setCorrespondingConstraints(class dialect::Graph &) --> void", pybind11::arg("H"));
	}
}
