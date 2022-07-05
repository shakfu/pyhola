#include <_stdio.h>
#include <ios>
#include <libavoid/connector.h>
#include <libavoid/debughandler.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedge.h>
#include <libavoid/junction.h>
#include <locale>
#include <memory>
#include <ostream>
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

void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::VertID file: line:51
		pybind11::class_<Avoid::VertID, std::shared_ptr<Avoid::VertID>> cl(M("Avoid"), "VertID", "");
		cl.def( pybind11::init( [](){ return new Avoid::VertID(); } ) );
		cl.def( pybind11::init( [](unsigned int const & a0, unsigned short const & a1){ return new Avoid::VertID(a0, a1); } ), "doc" , pybind11::arg("id"), pybind11::arg("n"));
		cl.def( pybind11::init<unsigned int, unsigned short, unsigned short>(), pybind11::arg("id"), pybind11::arg("n"), pybind11::arg("p") );

		cl.def( pybind11::init( [](Avoid::VertID const &o){ return new Avoid::VertID(o); } ) );
		cl.def_readwrite("objID", &Avoid::VertID::objID);
		cl.def_readwrite("vn", &Avoid::VertID::vn);
		cl.def_readwrite("props", &Avoid::VertID::props);
		cl.def("assign", (class Avoid::VertID & (Avoid::VertID::*)(const class Avoid::VertID &)) &Avoid::VertID::operator=, "C++: Avoid::VertID::operator=(const class Avoid::VertID &) --> class Avoid::VertID &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"));
		cl.def("__eq__", (bool (Avoid::VertID::*)(const class Avoid::VertID &) const) &Avoid::VertID::operator==, "C++: Avoid::VertID::operator==(const class Avoid::VertID &) const --> bool", pybind11::arg("rhs"));
		cl.def("__ne__", (bool (Avoid::VertID::*)(const class Avoid::VertID &) const) &Avoid::VertID::operator!=, "C++: Avoid::VertID::operator!=(const class Avoid::VertID &) const --> bool", pybind11::arg("rhs"));
		cl.def("__add__", (class Avoid::VertID (Avoid::VertID::*)(const int &) const) &Avoid::VertID::operator+, "C++: Avoid::VertID::operator+(const int &) const --> class Avoid::VertID", pybind11::arg("rhs"));
		cl.def("__sub__", (class Avoid::VertID (Avoid::VertID::*)(const int &) const) &Avoid::VertID::operator-, "C++: Avoid::VertID::operator-(const int &) const --> class Avoid::VertID", pybind11::arg("rhs"));
		cl.def("plus_plus", (class Avoid::VertID & (Avoid::VertID::*)(int)) &Avoid::VertID::operator++, "C++: Avoid::VertID::operator++(int) --> class Avoid::VertID &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("print", [](Avoid::VertID const &o) -> void { return o.print(); }, "");
		cl.def("print", (void (Avoid::VertID::*)(struct __sFILE *) const) &Avoid::VertID::print, "C++: Avoid::VertID::print(struct __sFILE *) const --> void", pybind11::arg("file"));
		cl.def("db_print", (void (Avoid::VertID::*)() const) &Avoid::VertID::db_print, "C++: Avoid::VertID::db_print() const --> void");
		cl.def("isOrthShapeEdge", (bool (Avoid::VertID::*)() const) &Avoid::VertID::isOrthShapeEdge, "C++: Avoid::VertID::isOrthShapeEdge() const --> bool");
		cl.def("isConnPt", (bool (Avoid::VertID::*)() const) &Avoid::VertID::isConnPt, "C++: Avoid::VertID::isConnPt() const --> bool");
		cl.def("isConnectionPin", (bool (Avoid::VertID::*)() const) &Avoid::VertID::isConnectionPin, "C++: Avoid::VertID::isConnectionPin() const --> bool");
		cl.def("isConnCheckpoint", (bool (Avoid::VertID::*)() const) &Avoid::VertID::isConnCheckpoint, "C++: Avoid::VertID::isConnCheckpoint() const --> bool");
		cl.def("isDummyPinHelper", (bool (Avoid::VertID::*)() const) &Avoid::VertID::isDummyPinHelper, "C++: Avoid::VertID::isDummyPinHelper() const --> bool");

		cl.def("__str__", [](Avoid::VertID const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // Avoid::VertInf file: line:115
		pybind11::class_<Avoid::VertInf, std::shared_ptr<Avoid::VertInf>> cl(M("Avoid"), "VertInf", "");
		cl.def( pybind11::init( [](class Avoid::Router * a0, const class Avoid::VertID & a1, const class Avoid::Point & a2){ return new Avoid::VertInf(a0, a1, a2); } ), "doc" , pybind11::arg("router"), pybind11::arg("vid"), pybind11::arg("vpoint"));
		cl.def( pybind11::init<class Avoid::Router *, const class Avoid::VertID &, const class Avoid::Point &, const bool>(), pybind11::arg("router"), pybind11::arg("vid"), pybind11::arg("vpoint"), pybind11::arg("addToRouter") );

		cl.def( pybind11::init( [](Avoid::VertInf const &o){ return new Avoid::VertInf(o); } ) );
		cl.def_readwrite("id", &Avoid::VertInf::id);
		cl.def_readwrite("point", &Avoid::VertInf::point);
		cl.def_readwrite("visList", &Avoid::VertInf::visList);
		cl.def_readwrite("visListSize", &Avoid::VertInf::visListSize);
		cl.def_readwrite("orthogVisList", &Avoid::VertInf::orthogVisList);
		cl.def_readwrite("orthogVisListSize", &Avoid::VertInf::orthogVisListSize);
		cl.def_readwrite("invisList", &Avoid::VertInf::invisList);
		cl.def_readwrite("invisListSize", &Avoid::VertInf::invisListSize);
		cl.def_readwrite("sptfDist", &Avoid::VertInf::sptfDist);
		cl.def_readwrite("visDirections", &Avoid::VertInf::visDirections);
		cl.def_readwrite("aStarDoneNodes", &Avoid::VertInf::aStarDoneNodes);
		cl.def_readwrite("aStarPendingNodes", &Avoid::VertInf::aStarPendingNodes);
		cl.def_readwrite("orthogVisPropFlags", &Avoid::VertInf::orthogVisPropFlags);
		cl.def("Reset", (void (Avoid::VertInf::*)(const class Avoid::VertID &, const class Avoid::Point &)) &Avoid::VertInf::Reset, "C++: Avoid::VertInf::Reset(const class Avoid::VertID &, const class Avoid::Point &) --> void", pybind11::arg("vid"), pybind11::arg("vpoint"));
		cl.def("Reset", (void (Avoid::VertInf::*)(const class Avoid::Point &)) &Avoid::VertInf::Reset, "C++: Avoid::VertInf::Reset(const class Avoid::Point &) --> void", pybind11::arg("vpoint"));
		cl.def("removeFromGraph", [](Avoid::VertInf &o) -> void { return o.removeFromGraph(); }, "");
		cl.def("removeFromGraph", (void (Avoid::VertInf::*)(const bool)) &Avoid::VertInf::removeFromGraph, "C++: Avoid::VertInf::removeFromGraph(const bool) --> void", pybind11::arg("isConnVert"));
		cl.def("orphaned", (bool (Avoid::VertInf::*)()) &Avoid::VertInf::orphaned, "C++: Avoid::VertInf::orphaned() --> bool");
		cl.def("pathLeadsBackTo", (unsigned int (Avoid::VertInf::*)(const class Avoid::VertInf *) const) &Avoid::VertInf::pathLeadsBackTo, "C++: Avoid::VertInf::pathLeadsBackTo(const class Avoid::VertInf *) const --> unsigned int", pybind11::arg("start"));
		cl.def("setVisibleDirections", (void (Avoid::VertInf::*)(const unsigned int)) &Avoid::VertInf::setVisibleDirections, "C++: Avoid::VertInf::setVisibleDirections(const unsigned int) --> void", pybind11::arg("directions"));
		cl.def("directionFrom", (unsigned int (Avoid::VertInf::*)(const class Avoid::VertInf *) const) &Avoid::VertInf::directionFrom, "C++: Avoid::VertInf::directionFrom(const class Avoid::VertInf *) const --> unsigned int", pybind11::arg("other"));
		cl.def("hasNeighbour", (class Avoid::EdgeInf * (Avoid::VertInf::*)(class Avoid::VertInf *, bool) const) &Avoid::VertInf::hasNeighbour, "C++: Avoid::VertInf::hasNeighbour(class Avoid::VertInf *, bool) const --> class Avoid::EdgeInf *", pybind11::return_value_policy::automatic, pybind11::arg("target"), pybind11::arg("orthogonal"));
		cl.def("orphan", (void (Avoid::VertInf::*)()) &Avoid::VertInf::orphan, "C++: Avoid::VertInf::orphan() --> void");
		cl.def("treeRoot", (class Avoid::VertInf * (Avoid::VertInf::*)() const) &Avoid::VertInf::treeRoot, "C++: Avoid::VertInf::treeRoot() const --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("clearTreeRootPointer", (void (Avoid::VertInf::*)()) &Avoid::VertInf::clearTreeRootPointer, "C++: Avoid::VertInf::clearTreeRootPointer() --> void");
		cl.def("setSPTFRoot", (void (Avoid::VertInf::*)(class Avoid::VertInf *)) &Avoid::VertInf::setSPTFRoot, "C++: Avoid::VertInf::setSPTFRoot(class Avoid::VertInf *) --> void", pybind11::arg("root"));
		cl.def("sptfRoot", (class Avoid::VertInf * (Avoid::VertInf::*)() const) &Avoid::VertInf::sptfRoot, "C++: Avoid::VertInf::sptfRoot() const --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
	}
	// Avoid::directVis(class Avoid::VertInf *, class Avoid::VertInf *) file: line:186
	M("Avoid").def("directVis", (bool (*)(class Avoid::VertInf *, class Avoid::VertInf *)) &Avoid::directVis, "C++: Avoid::directVis(class Avoid::VertInf *, class Avoid::VertInf *) --> bool", pybind11::arg("src"), pybind11::arg("dst"));

	{ // Avoid::VertInfList file: line:194
		pybind11::class_<Avoid::VertInfList, std::shared_ptr<Avoid::VertInfList>> cl(M("Avoid"), "VertInfList", "");
		cl.def( pybind11::init( [](){ return new Avoid::VertInfList(); } ) );
		cl.def( pybind11::init( [](Avoid::VertInfList const &o){ return new Avoid::VertInfList(o); } ) );
		cl.def("addVertex", (void (Avoid::VertInfList::*)(class Avoid::VertInf *)) &Avoid::VertInfList::addVertex, "C++: Avoid::VertInfList::addVertex(class Avoid::VertInf *) --> void", pybind11::arg("vert"));
		cl.def("removeVertex", (class Avoid::VertInf * (Avoid::VertInfList::*)(class Avoid::VertInf *)) &Avoid::VertInfList::removeVertex, "C++: Avoid::VertInfList::removeVertex(class Avoid::VertInf *) --> class Avoid::VertInf *", pybind11::return_value_policy::automatic, pybind11::arg("vert"));
		cl.def("getVertexByID", (class Avoid::VertInf * (Avoid::VertInfList::*)(const class Avoid::VertID &)) &Avoid::VertInfList::getVertexByID, "C++: Avoid::VertInfList::getVertexByID(const class Avoid::VertID &) --> class Avoid::VertInf *", pybind11::return_value_policy::automatic, pybind11::arg("id"));
		cl.def("getVertexByPos", (class Avoid::VertInf * (Avoid::VertInfList::*)(const class Avoid::Point &)) &Avoid::VertInfList::getVertexByPos, "C++: Avoid::VertInfList::getVertexByPos(const class Avoid::Point &) --> class Avoid::VertInf *", pybind11::return_value_policy::automatic, pybind11::arg("p"));
		cl.def("shapesBegin", (class Avoid::VertInf * (Avoid::VertInfList::*)()) &Avoid::VertInfList::shapesBegin, "C++: Avoid::VertInfList::shapesBegin() --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("connsBegin", (class Avoid::VertInf * (Avoid::VertInfList::*)()) &Avoid::VertInfList::connsBegin, "C++: Avoid::VertInfList::connsBegin() --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("end", (class Avoid::VertInf * (Avoid::VertInfList::*)()) &Avoid::VertInfList::end, "C++: Avoid::VertInfList::end() --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("connsSize", (unsigned int (Avoid::VertInfList::*)() const) &Avoid::VertInfList::connsSize, "C++: Avoid::VertInfList::connsSize() const --> unsigned int");
		cl.def("shapesSize", (unsigned int (Avoid::VertInfList::*)() const) &Avoid::VertInfList::shapesSize, "C++: Avoid::VertInfList::shapesSize() const --> unsigned int");
		cl.def("assign", (class Avoid::VertInfList & (Avoid::VertInfList::*)(const class Avoid::VertInfList &)) &Avoid::VertInfList::operator=, "C++: Avoid::VertInfList::operator=(const class Avoid::VertInfList &) --> class Avoid::VertInfList &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// Avoid::ConnType file:libavoid/connector.h line:53
	pybind11::enum_<Avoid::ConnType>(M("Avoid"), "ConnType", pybind11::arithmetic(), "Describes the type of routing that is performed for each \n         connector.")
		.value("ConnType_None", Avoid::ConnType_None)
		.value("ConnType_PolyLine", Avoid::ConnType_PolyLine)
		.value("ConnType_Orthogonal", Avoid::ConnType_Orthogonal)
		.export_values();

;

	{ // Avoid::Checkpoint file:libavoid/connector.h line:68
		pybind11::class_<Avoid::Checkpoint, std::shared_ptr<Avoid::Checkpoint>> cl(M("Avoid"), "Checkpoint", "A checkpoint is a point that the route for a particular connector\n         must visit.  They may optionally be given an arrival/departure\n         direction.");
		cl.def( pybind11::init<const class Avoid::Point &>(), pybind11::arg("p") );

		cl.def( pybind11::init<const class Avoid::Point &, unsigned int, unsigned int>(), pybind11::arg("p"), pybind11::arg("ad"), pybind11::arg("dd") );

		cl.def( pybind11::init( [](){ return new Avoid::Checkpoint(); } ) );
		cl.def_readwrite("point", &Avoid::Checkpoint::point);
		cl.def_readwrite("arrivalDirections", &Avoid::Checkpoint::arrivalDirections);
		cl.def_readwrite("departureDirections", &Avoid::Checkpoint::departureDirections);
	}
	{ // Avoid::ConnRef file:libavoid/connector.h line:131
		pybind11::class_<Avoid::ConnRef, std::shared_ptr<Avoid::ConnRef>> cl(M("Avoid"), "ConnRef", "The ConnRef class represents a connector object.\n\n Connectors are a (possible multi-segment) line between two points.\n They are routed intelligently so as not to overlap any of the shape\n objects in the Router scene.\n\n Routing penalties can be applied, resulting in more aesthetically pleasing\n connector paths with fewer segments or less severe bend-points.\n\n You can set a function to be called when the connector has been rerouted\n and needs to be redrawn.  Alternatively, you can query the connector's\n needsRepaint() function to determine this manually.\n\n Usually, it is expected that you would create a ConnRef for each connector \n in your diagram and keep that reference in your own connector class.");
		cl.def( pybind11::init( [](class Avoid::Router * a0){ return new Avoid::ConnRef(a0); } ), "doc" , pybind11::arg("router"));
		cl.def( pybind11::init<class Avoid::Router *, const unsigned int>(), pybind11::arg("router"), pybind11::arg("id") );

		cl.def( pybind11::init( [](class Avoid::Router * a0, const class Avoid::ConnEnd & a1, const class Avoid::ConnEnd & a2){ return new Avoid::ConnRef(a0, a1, a2); } ), "doc" , pybind11::arg("router"), pybind11::arg("src"), pybind11::arg("dst"));
		cl.def( pybind11::init<class Avoid::Router *, const class Avoid::ConnEnd &, const class Avoid::ConnEnd &, const unsigned int>(), pybind11::arg("router"), pybind11::arg("src"), pybind11::arg("dst"), pybind11::arg("id") );

		cl.def( pybind11::init( [](Avoid::ConnRef const &o){ return new Avoid::ConnRef(o); } ) );
		cl.def("setEndpoints", (void (Avoid::ConnRef::*)(const class Avoid::ConnEnd &, const class Avoid::ConnEnd &)) &Avoid::ConnRef::setEndpoints, "Sets both a new source and destination endpoint for this \n         connector.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n \n  New source endpoint for the connector.\n \n\n  New destination endpoint for the connector.\n\nC++: Avoid::ConnRef::setEndpoints(const class Avoid::ConnEnd &, const class Avoid::ConnEnd &) --> void", pybind11::arg("srcPoint"), pybind11::arg("dstPoint"));
		cl.def("setSourceEndpoint", (void (Avoid::ConnRef::*)(const class Avoid::ConnEnd &)) &Avoid::ConnRef::setSourceEndpoint, "Sets just a new source endpoint for this connector.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n \n  New source endpoint for the connector.\n\nC++: Avoid::ConnRef::setSourceEndpoint(const class Avoid::ConnEnd &) --> void", pybind11::arg("srcPoint"));
		cl.def("setDestEndpoint", (void (Avoid::ConnRef::*)(const class Avoid::ConnEnd &)) &Avoid::ConnRef::setDestEndpoint, "Sets just a new destination endpoint for this connector.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n \n  New destination endpoint for the connector.\n\nC++: Avoid::ConnRef::setDestEndpoint(const class Avoid::ConnEnd &) --> void", pybind11::arg("dstPoint"));
		cl.def("id", (unsigned int (Avoid::ConnRef::*)() const) &Avoid::ConnRef::id, "Returns the ID of this connector.\n \n\n The ID of the connector. \n\nC++: Avoid::ConnRef::id() const --> unsigned int");
		cl.def("router", (class Avoid::Router * (Avoid::ConnRef::*)() const) &Avoid::ConnRef::router, "Returns a pointer to the router scene this connector is in.\n \n\n A pointer to the router scene for this connector.\n\nC++: Avoid::ConnRef::router() const --> class Avoid::Router *", pybind11::return_value_policy::automatic);
		cl.def("needsRepaint", (bool (Avoid::ConnRef::*)() const) &Avoid::ConnRef::needsRepaint, "Returns an indication of whether this connector has a \n          new route and thus needs to be repainted.\n\n If the connector has been rerouted and need repainting, the  \n displayRoute() method can be called to get a reference to the \n new route.\n\n \n Returns true if the connector requires repainting, or \n          false if it does not.\n\nC++: Avoid::ConnRef::needsRepaint() const --> bool");
		cl.def("route", (const class Avoid::Polygon & (Avoid::ConnRef::*)() const) &Avoid::ConnRef::route, "Returns a reference to the current raw \"debug\" route for \n          the connector.\n\n This is a raw \"debug\" shortest path version of the route, where \n each line segment in the route may be made up of multiple collinear\n line segments.  It also has no post-processing (i.e., centering,\n nudging apart of overlapping paths, or curving of corners) applied \n to it.  A route to display to the user can be obtained by calling\n displayRoute().\n\n \n The PolyLine route for the connector.\n\nC++: Avoid::ConnRef::route() const --> const class Avoid::Polygon &", pybind11::return_value_policy::automatic);
		cl.def("displayRoute", (class Avoid::Polygon & (Avoid::ConnRef::*)()) &Avoid::ConnRef::displayRoute, "Returns a reference to the current display version of the\n          route for the connector.\n\n The display version of a route has been simplified to collapse all\n collinear line segments into single segments.  It also has all\n post-processing applied to the route, including centering, curved\n corners and nudging apart of overlapping segments.\n\n \n The PolyLine display route for the connector.\n\nC++: Avoid::ConnRef::displayRoute() --> class Avoid::Polygon &", pybind11::return_value_policy::automatic);
		cl.def("routingType", (enum Avoid::ConnType (Avoid::ConnRef::*)() const) &Avoid::ConnRef::routingType, "Returns the type of routing performed for this connector.\n \n\n  The type of routing performed.\n\nC++: Avoid::ConnRef::routingType() const --> enum Avoid::ConnType");
		cl.def("setRoutingType", (void (Avoid::ConnRef::*)(enum Avoid::ConnType)) &Avoid::ConnRef::setRoutingType, "Sets the type of routing to be performed for this \n              connector.\n\n If a call to this method changes the current type of routing \n being used for the connector, then it will get rerouted during\n the next processTransaction() call, or immediately if \n transactions are not being used.\n\n \n  The type of routing to be performed.\n\nC++: Avoid::ConnRef::setRoutingType(enum Avoid::ConnType) --> void", pybind11::arg("type"));
		cl.def("splitAtSegment", (struct std::pair<class Avoid::JunctionRef *, class Avoid::ConnRef *> (Avoid::ConnRef::*)(const unsigned long)) &Avoid::ConnRef::splitAtSegment, "Splits a connector in the centre of the segmentNth \n          segment and creates a junction point there as well \n          as a second connector.\n\n The new junction and connector will be automatically added to \n the router scene.  A slight preference will be given to the \n connectors connecting to the junction in the same orientation\n the line segment already existed in.\n\n \n  A pair containing pointers to the new JunctionRef and \n          ConnRef.\n\nC++: Avoid::ConnRef::splitAtSegment(const unsigned long) --> struct std::pair<class Avoid::JunctionRef *, class Avoid::ConnRef *>", pybind11::arg("segmentN"));
		cl.def("endpointConnEnds", (struct std::pair<class Avoid::ConnEnd, class Avoid::ConnEnd> (Avoid::ConnRef::*)() const) &Avoid::ConnRef::endpointConnEnds, "Returns ConnEnds specifying what this connector is \n          attached to.\n\n This may be useful during hyperedge rerouting.  You can check the \n type and properties of the ConnEnd objects to find out what this \n connector is attached to.  The ConnEnd::type() will be ConnEndEmpty\n if the connector has not had its endpoints initialised.\n\n \n  If the router is using transactions, you might get \n        unexpected results if you call this after changing objects\n        but before calling Router::processTransaction().  In this\n        case changes to ConnEnds for the connector may be queued \n        and not yet applied, so you will get old (or empty) values.\n\n \n A pair of ConnEnd objects specifying what the connector\n          is attached to.\n\nC++: Avoid::ConnRef::endpointConnEnds() const --> struct std::pair<class Avoid::ConnEnd, class Avoid::ConnEnd>");
		cl.def("src", (class Avoid::VertInf * (Avoid::ConnRef::*)() const) &Avoid::ConnRef::src, "C++: Avoid::ConnRef::src() const --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("dst", (class Avoid::VertInf * (Avoid::ConnRef::*)() const) &Avoid::ConnRef::dst, "C++: Avoid::ConnRef::dst() const --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("setFixedRoute", (void (Avoid::ConnRef::*)(const class Avoid::Polygon &)) &Avoid::ConnRef::setFixedRoute, "Sets a fixed user-specified route for this connector.\n\n libavoid will no longer calculate object-avoiding paths for this\n connector but instead just return the specified route.  The path\n of this connector will still be considered for the purpose of \n nudging and routing other non-fixed connectors.\n\n \n  This will reset the endpoints of the connector to the two\n        ends of the given route, which may cause it to become \n        dettached from any shapes or junctions.  You can\n        alternatively call setFixedExistingRoute() for connectors\n        with valid routes in hyperedges that you would like to\n        remain attached.\n\n \n  The new fixed route for the connector.\n \n\n  setFixedExistingRoute()\n \n\n  clearFixedRoute()\n\nC++: Avoid::ConnRef::setFixedRoute(const class Avoid::Polygon &) --> void", pybind11::arg("route"));
		cl.def("setFixedExistingRoute", (void (Avoid::ConnRef::*)()) &Avoid::ConnRef::setFixedExistingRoute, "Sets a fixed existing route for this connector.\n\n libavoid will no longer calculate object-avoiding paths for this\n connector but instead just return the current exisitng route.  \n The path of this connector will still be considered for the \n purpose of nudging and routing other non-fixed connectors.\n\n \n  The endpoints of this connector will remain at their current\n        positions, even while remaining 'attached' to shapes \n        or junctions that move.\n\n \n  setFixedRoute()\n \n\n  clearFixedRoute()\n\nC++: Avoid::ConnRef::setFixedExistingRoute() --> void");
		cl.def("hasFixedRoute", (bool (Avoid::ConnRef::*)() const) &Avoid::ConnRef::hasFixedRoute, "Returns whether the connector route is marked as fixed.\n\n \n True if the connector route is fixed, false otherwise.\n\nC++: Avoid::ConnRef::hasFixedRoute() const --> bool");
		cl.def("clearFixedRoute", (void (Avoid::ConnRef::*)()) &Avoid::ConnRef::clearFixedRoute, "Returns the connector to being automatically routed if it\n         was marked as fixed.\n\n \n  setFixedRoute()\n\nC++: Avoid::ConnRef::clearFixedRoute() --> void");
		cl.def("set_route", (void (Avoid::ConnRef::*)(const class Avoid::Polygon &)) &Avoid::ConnRef::set_route, "C++: Avoid::ConnRef::set_route(const class Avoid::Polygon &) --> void", pybind11::arg("route"));
		cl.def("calcRouteDist", (void (Avoid::ConnRef::*)()) &Avoid::ConnRef::calcRouteDist, "C++: Avoid::ConnRef::calcRouteDist() --> void");
		cl.def("makeActive", (void (Avoid::ConnRef::*)()) &Avoid::ConnRef::makeActive, "C++: Avoid::ConnRef::makeActive() --> void");
		cl.def("makeInactive", (void (Avoid::ConnRef::*)()) &Avoid::ConnRef::makeInactive, "C++: Avoid::ConnRef::makeInactive() --> void");
		cl.def("start", (class Avoid::VertInf * (Avoid::ConnRef::*)()) &Avoid::ConnRef::start, "C++: Avoid::ConnRef::start() --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("removeFromGraph", (void (Avoid::ConnRef::*)()) &Avoid::ConnRef::removeFromGraph, "C++: Avoid::ConnRef::removeFromGraph() --> void");
		cl.def("isInitialised", (bool (Avoid::ConnRef::*)() const) &Avoid::ConnRef::isInitialised, "C++: Avoid::ConnRef::isInitialised() const --> bool");
		cl.def("makePathInvalid", (void (Avoid::ConnRef::*)()) &Avoid::ConnRef::makePathInvalid, "C++: Avoid::ConnRef::makePathInvalid() --> void");
		cl.def("setHateCrossings", (void (Avoid::ConnRef::*)(bool)) &Avoid::ConnRef::setHateCrossings, "C++: Avoid::ConnRef::setHateCrossings(bool) --> void", pybind11::arg("value"));
		cl.def("doesHateCrossings", (bool (Avoid::ConnRef::*)() const) &Avoid::ConnRef::doesHateCrossings, "C++: Avoid::ConnRef::doesHateCrossings() const --> bool");
		cl.def("setEndpoint", (void (Avoid::ConnRef::*)(const unsigned int, const class Avoid::ConnEnd &)) &Avoid::ConnRef::setEndpoint, "C++: Avoid::ConnRef::setEndpoint(const unsigned int, const class Avoid::ConnEnd &) --> void", pybind11::arg("type"), pybind11::arg("connEnd"));
		cl.def("setEndpoint", [](Avoid::ConnRef &o, const unsigned int & a0, const class Avoid::VertID & a1) -> bool { return o.setEndpoint(a0, a1); }, "", pybind11::arg("type"), pybind11::arg("pointID"));
		cl.def("setEndpoint", (bool (Avoid::ConnRef::*)(const unsigned int, const class Avoid::VertID &, class Avoid::Point *)) &Avoid::ConnRef::setEndpoint, "C++: Avoid::ConnRef::setEndpoint(const unsigned int, const class Avoid::VertID &, class Avoid::Point *) --> bool", pybind11::arg("type"), pybind11::arg("pointID"), pybind11::arg("pointSuggestion"));
	}
}
