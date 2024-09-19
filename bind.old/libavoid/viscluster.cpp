#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/debughandler.h>
#include <libavoid/geomtypes.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedge.h>
#include <libavoid/hyperedgetree.h>
#include <libavoid/junction.h>
#include <libavoid/makepath.h>
#include <libavoid/mtst.h>
#include <libavoid/obstacle.h>
#include <libavoid/orthogonal.h>
#include <libavoid/router.h>
#include <libavoid/scanline.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <libavoid/viscluster.h>
#include <list>
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

void bind_libavoid_viscluster(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::ClusterRef file:libavoid/viscluster.h line:55
		pybind11::class_<Avoid::ClusterRef, std::shared_ptr<Avoid::ClusterRef>> cl(M("Avoid"), "ClusterRef", "The ClusterRef class represents a cluster object.\n\n Cluster are boundaries around groups of shape objects.  Ideally, only\n connectors with one endpoint inside the cluster and one endpoint outside\n the cluster will cross the cluster boundary. Connectors that begin and \n end inside a cluster will not route outside it, and connectors that begin \n and end outside the cluster will not enter the cluster.\n\n \n   While the functionality of this class works, it is currently \n         experimental you will likely suffer a large performance hit\n         when using it.");
		cl.def( pybind11::init( [](class Avoid::Router * a0, class Avoid::Polygon & a1){ return new Avoid::ClusterRef(a0, a1); } ), "doc" , pybind11::arg("router"), pybind11::arg("poly"));
		cl.def( pybind11::init<class Avoid::Router *, class Avoid::Polygon &, const unsigned int>(), pybind11::arg("router"), pybind11::arg("poly"), pybind11::arg("id") );

		cl.def("setNewPoly", (void (Avoid::ClusterRef::*)(class Avoid::Polygon &)) &Avoid::ClusterRef::setNewPoly, "Update the polygon boundary for this cluster.\n\n You should specify a polygon boundary.  The rectangular one will\n be generated automatically from this.\n\n \n    A Polygon representing the boundary of the \n                     cluster.\n\nC++: Avoid::ClusterRef::setNewPoly(class Avoid::Polygon &) --> void", pybind11::arg("poly"));
		cl.def("id", (unsigned int (Avoid::ClusterRef::*)() const) &Avoid::ClusterRef::id, "Returns the ID of this cluster.\n \n\n The ID of the cluster. \n\nC++: Avoid::ClusterRef::id() const --> unsigned int");
		cl.def("polygon", (class Avoid::ReferencingPolygon & (Avoid::ClusterRef::*)()) &Avoid::ClusterRef::polygon, "Returns a reference to the polygon boundary of this \n          cluster.\n \n\n A reference to the polygon boundary of the cluster.\n\nC++: Avoid::ClusterRef::polygon() --> class Avoid::ReferencingPolygon &", pybind11::return_value_policy::automatic);
		cl.def("rectangularPolygon", (class Avoid::Polygon & (Avoid::ClusterRef::*)()) &Avoid::ClusterRef::rectangularPolygon, "Returns a reference to the rectangular boundary of this \n          cluster.\n \n\n A reference to the rectangular boundary of the cluster.\n\nC++: Avoid::ClusterRef::rectangularPolygon() --> class Avoid::Polygon &", pybind11::return_value_policy::automatic);
		cl.def("router", (class Avoid::Router * (Avoid::ClusterRef::*)() const) &Avoid::ClusterRef::router, "Returns a pointer to the router scene this cluster is in.\n \n\n A pointer to the router scene for this cluster.\n\nC++: Avoid::ClusterRef::router() const --> class Avoid::Router *", pybind11::return_value_policy::automatic);
		cl.def("makeActive", (void (Avoid::ClusterRef::*)()) &Avoid::ClusterRef::makeActive, "C++: Avoid::ClusterRef::makeActive() --> void");
		cl.def("makeInactive", (void (Avoid::ClusterRef::*)()) &Avoid::ClusterRef::makeInactive, "C++: Avoid::ClusterRef::makeInactive() --> void");
	}
	{ // Avoid::AStarPath file:libavoid/makepath.h line:37
		pybind11::class_<Avoid::AStarPath, std::shared_ptr<Avoid::AStarPath>> cl(M("Avoid"), "AStarPath", "");
		cl.def( pybind11::init( [](){ return new Avoid::AStarPath(); } ) );
		cl.def("search", (void (Avoid::AStarPath::*)(class Avoid::ConnRef *, class Avoid::VertInf *, class Avoid::VertInf *, class Avoid::VertInf *)) &Avoid::AStarPath::search, "C++: Avoid::AStarPath::search(class Avoid::ConnRef *, class Avoid::VertInf *, class Avoid::VertInf *, class Avoid::VertInf *) --> void", pybind11::arg("lineRef"), pybind11::arg("src"), pybind11::arg("tar"), pybind11::arg("start"));
	}
	{ // Avoid::HeapCmpVertInf file:libavoid/mtst.h line:50
		pybind11::class_<Avoid::HeapCmpVertInf, std::shared_ptr<Avoid::HeapCmpVertInf>> cl(M("Avoid"), "HeapCmpVertInf", "");
		cl.def( pybind11::init( [](){ return new Avoid::HeapCmpVertInf(); } ) );
		cl.def( pybind11::init( [](Avoid::HeapCmpVertInf const &o){ return new Avoid::HeapCmpVertInf(o); } ) );
		cl.def("__call__", (bool (Avoid::HeapCmpVertInf::*)(const class Avoid::VertInf *, const class Avoid::VertInf *) const) &Avoid::HeapCmpVertInf::operator(), "C++: Avoid::HeapCmpVertInf::operator()(const class Avoid::VertInf *, const class Avoid::VertInf *) const --> bool", pybind11::arg("a"), pybind11::arg("b"));
	}
	{ // Avoid::CmpEdgeInf file:libavoid/mtst.h line:57
		pybind11::class_<Avoid::CmpEdgeInf, std::shared_ptr<Avoid::CmpEdgeInf>> cl(M("Avoid"), "CmpEdgeInf", "");
		cl.def( pybind11::init( [](){ return new Avoid::CmpEdgeInf(); } ) );
		cl.def( pybind11::init( [](Avoid::CmpEdgeInf const &o){ return new Avoid::CmpEdgeInf(o); } ) );
		cl.def("__call__", (bool (Avoid::CmpEdgeInf::*)(const class Avoid::EdgeInf *, const class Avoid::EdgeInf *) const) &Avoid::CmpEdgeInf::operator(), "C++: Avoid::CmpEdgeInf::operator()(const class Avoid::EdgeInf *, const class Avoid::EdgeInf *) const --> bool", pybind11::arg("a"), pybind11::arg("b"));
	}
	{ // Avoid::MinimumTerminalSpanningTree file:libavoid/mtst.h line:66
		pybind11::class_<Avoid::MinimumTerminalSpanningTree, std::shared_ptr<Avoid::MinimumTerminalSpanningTree>> cl(M("Avoid"), "MinimumTerminalSpanningTree", "");
		cl.def( pybind11::init( [](Avoid::MinimumTerminalSpanningTree const &o){ return new Avoid::MinimumTerminalSpanningTree(o); } ) );
		cl.def("constructInterleaved", (void (Avoid::MinimumTerminalSpanningTree::*)()) &Avoid::MinimumTerminalSpanningTree::constructInterleaved, "C++: Avoid::MinimumTerminalSpanningTree::constructInterleaved() --> void");
		cl.def("constructSequential", (void (Avoid::MinimumTerminalSpanningTree::*)()) &Avoid::MinimumTerminalSpanningTree::constructSequential, "C++: Avoid::MinimumTerminalSpanningTree::constructSequential() --> void");
		// cl.def("setDebuggingOutput", (void (Avoid::MinimumTerminalSpanningTree::*)(struct __sFILE *, unsigned int)) &Avoid::MinimumTerminalSpanningTree::setDebuggingOutput, "C++: Avoid::MinimumTerminalSpanningTree::setDebuggingOutput(struct __sFILE *, unsigned int) --> void", pybind11::arg("fp"), pybind11::arg("counter"));
		cl.def("rootJunction", (struct Avoid::HyperedgeTreeNode * (Avoid::MinimumTerminalSpanningTree::*)() const) &Avoid::MinimumTerminalSpanningTree::rootJunction, "C++: Avoid::MinimumTerminalSpanningTree::rootJunction() const --> struct Avoid::HyperedgeTreeNode *", pybind11::return_value_policy::automatic);
	}
	// Avoid::generateStaticOrthogonalVisGraph(class Avoid::Router *) file:libavoid/orthogonal.h line:33
	M("Avoid").def("generateStaticOrthogonalVisGraph", (void (*)(class Avoid::Router *)) &Avoid::generateStaticOrthogonalVisGraph, "C++: Avoid::generateStaticOrthogonalVisGraph(class Avoid::Router *) --> void", pybind11::arg("router"));

	// Avoid::improveOrthogonalRoutes(class Avoid::Router *) file:libavoid/orthogonal.h line:34
	M("Avoid").def("improveOrthogonalRoutes", (void (*)(class Avoid::Router *)) &Avoid::improveOrthogonalRoutes, "C++: Avoid::improveOrthogonalRoutes(class Avoid::Router *) --> void", pybind11::arg("router"));

	{ // Avoid::ShiftSegment file:libavoid/scanline.h line:44
		pybind11::class_<Avoid::ShiftSegment, std::shared_ptr<Avoid::ShiftSegment>> cl(M("Avoid"), "ShiftSegment", "");
		cl.def_readwrite("dimension", &Avoid::ShiftSegment::dimension);
		cl.def_readwrite("minSpaceLimit", &Avoid::ShiftSegment::minSpaceLimit);
		cl.def_readwrite("maxSpaceLimit", &Avoid::ShiftSegment::maxSpaceLimit);
		cl.def("lowPoint", (class Avoid::Point & (Avoid::ShiftSegment::*)()) &Avoid::ShiftSegment::lowPoint, "C++: Avoid::ShiftSegment::lowPoint() --> class Avoid::Point &", pybind11::return_value_policy::automatic);
		cl.def("highPoint", (class Avoid::Point & (Avoid::ShiftSegment::*)()) &Avoid::ShiftSegment::highPoint, "C++: Avoid::ShiftSegment::highPoint() --> class Avoid::Point &", pybind11::return_value_policy::automatic);
		cl.def("overlapsWith", (bool (Avoid::ShiftSegment::*)(const class Avoid::ShiftSegment *, const unsigned long) const) &Avoid::ShiftSegment::overlapsWith, "C++: Avoid::ShiftSegment::overlapsWith(const class Avoid::ShiftSegment *, const unsigned long) const --> bool", pybind11::arg("rhs"), pybind11::arg("dim"));
		cl.def("immovable", (bool (Avoid::ShiftSegment::*)() const) &Avoid::ShiftSegment::immovable, "C++: Avoid::ShiftSegment::immovable() const --> bool");
		cl.def("assign", (class Avoid::ShiftSegment & (Avoid::ShiftSegment::*)(const class Avoid::ShiftSegment &)) &Avoid::ShiftSegment::operator=, "C++: Avoid::ShiftSegment::operator=(const class Avoid::ShiftSegment &) --> class Avoid::ShiftSegment &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::CmpNodePos file:libavoid/scanline.h line:70
		pybind11::class_<Avoid::CmpNodePos, std::shared_ptr<Avoid::CmpNodePos>> cl(M("Avoid"), "CmpNodePos", "");
		cl.def( pybind11::init( [](){ return new Avoid::CmpNodePos(); } ) );
		cl.def("__call__", (bool (Avoid::CmpNodePos::*)(const class Avoid::Node *, const class Avoid::Node *) const) &Avoid::CmpNodePos::operator(), "C++: Avoid::CmpNodePos::operator()(const class Avoid::Node *, const class Avoid::Node *) const --> bool", pybind11::arg("u"), pybind11::arg("v"));
	}
	{ // Avoid::Node file:libavoid/scanline.h line:78
		pybind11::class_<Avoid::Node, std::shared_ptr<Avoid::Node>> cl(M("Avoid"), "Node", "");
		cl.def( pybind11::init<class Avoid::Obstacle *, const double>(), pybind11::arg("v"), pybind11::arg("p") );

		cl.def( pybind11::init<class Avoid::VertInf *, const double>(), pybind11::arg("c"), pybind11::arg("p") );

		cl.def( pybind11::init<class Avoid::ShiftSegment *, const double>(), pybind11::arg("ss"), pybind11::arg("p") );

		cl.def_readwrite("pos", &Avoid::Node::pos);
		cl.def("firstObstacleAbove", (double (Avoid::Node::*)(unsigned long)) &Avoid::Node::firstObstacleAbove, "C++: Avoid::Node::firstObstacleAbove(unsigned long) --> double", pybind11::arg("dim"));
		cl.def("firstObstacleBelow", (double (Avoid::Node::*)(unsigned long)) &Avoid::Node::firstObstacleBelow, "C++: Avoid::Node::firstObstacleBelow(unsigned long) --> double", pybind11::arg("dim"));
		cl.def("markShiftSegmentsAbove", (void (Avoid::Node::*)(unsigned long)) &Avoid::Node::markShiftSegmentsAbove, "C++: Avoid::Node::markShiftSegmentsAbove(unsigned long) --> void", pybind11::arg("dim"));
		cl.def("markShiftSegmentsBelow", (void (Avoid::Node::*)(unsigned long)) &Avoid::Node::markShiftSegmentsBelow, "C++: Avoid::Node::markShiftSegmentsBelow(unsigned long) --> void", pybind11::arg("dim"));
		cl.def("findFirstPointAboveAndBelow", (void (Avoid::Node::*)(const unsigned long, const double, double &, double &, double &, double &)) &Avoid::Node::findFirstPointAboveAndBelow, "C++: Avoid::Node::findFirstPointAboveAndBelow(const unsigned long, const double, double &, double &, double &, double &) --> void", pybind11::arg("dim"), pybind11::arg("linePos"), pybind11::arg("firstAbovePos"), pybind11::arg("firstBelowPos"), pybind11::arg("lastAbovePos"), pybind11::arg("lastBelowPos"));
		cl.def("firstPointAbove", (double (Avoid::Node::*)(unsigned long)) &Avoid::Node::firstPointAbove, "C++: Avoid::Node::firstPointAbove(unsigned long) --> double", pybind11::arg("dim"));
		cl.def("firstPointBelow", (double (Avoid::Node::*)(unsigned long)) &Avoid::Node::firstPointBelow, "C++: Avoid::Node::firstPointBelow(unsigned long) --> double", pybind11::arg("dim"));
		cl.def("isInsideShape", (bool (Avoid::Node::*)(unsigned long)) &Avoid::Node::isInsideShape, "C++: Avoid::Node::isInsideShape(unsigned long) --> bool", pybind11::arg("dimension"));
		cl.def("assign", (class Avoid::Node & (Avoid::Node::*)(const class Avoid::Node &)) &Avoid::Node::operator=, "C++: Avoid::Node::operator=(const class Avoid::Node &) --> class Avoid::Node &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
