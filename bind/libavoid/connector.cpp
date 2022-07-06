#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/debug.h>
#include <libavoid/debughandler.h>
#include <libavoid/geomtypes.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedge.h>
#include <libavoid/junction.h>
#include <libavoid/obstacle.h>
#include <libavoid/router.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <libavoid/viscluster.h>
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

// Avoid::DebugHandler file:libavoid/debughandler.h line:46
struct PyCallBack_Avoid_DebugHandler : public Avoid::DebugHandler {
	using Avoid::DebugHandler::DebugHandler;

	void updateConnectorRoute(class Avoid::ConnRef * a0, int a1, int a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::DebugHandler *>(this), "updateConnectorRoute");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return DebugHandler::updateConnectorRoute(a0, a1, a2);
	}
	void beginningSearchWithEndpoints(class Avoid::VertInf * a0, class Avoid::VertInf * a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::DebugHandler *>(this), "beginningSearchWithEndpoints");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return DebugHandler::beginningSearchWithEndpoints(a0, a1);
	}
	void updateCurrentSearchPath(class Avoid::Polygon a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::DebugHandler *>(this), "updateCurrentSearchPath");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return DebugHandler::updateCurrentSearchPath(a0);
	}
	void mtstGrowForestWithEdge(class Avoid::VertInf * a0, class Avoid::VertInf * a1, bool a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::DebugHandler *>(this), "mtstGrowForestWithEdge");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return DebugHandler::mtstGrowForestWithEdge(a0, a1, a2);
	}
	void mtstPotentialBridgingEdge(class Avoid::VertInf * a0, class Avoid::VertInf * a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::DebugHandler *>(this), "mtstPotentialBridgingEdge");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return DebugHandler::mtstPotentialBridgingEdge(a0, a1);
	}
	void mtstCommitToEdge(class Avoid::VertInf * a0, class Avoid::VertInf * a1, bool a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::DebugHandler *>(this), "mtstCommitToEdge");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return DebugHandler::mtstCommitToEdge(a0, a1, a2);
	}
};

void bind_libavoid_connector(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::PtOrder file:libavoid/connector.h line:475
		pybind11::class_<Avoid::PtOrder, std::shared_ptr<Avoid::PtOrder>> cl(M("Avoid"), "PtOrder", "");
		cl.def( pybind11::init( [](){ return new Avoid::PtOrder(); } ) );
		cl.def( pybind11::init( [](Avoid::PtOrder const &o){ return new Avoid::PtOrder(o); } ) );
		cl.def("positionFor", (int (Avoid::PtOrder::*)(const unsigned long, const class Avoid::ConnRef *)) &Avoid::PtOrder::positionFor, "C++: Avoid::PtOrder::positionFor(const unsigned long, const class Avoid::ConnRef *) --> int", pybind11::arg("dim"), pybind11::arg("conn"));
	}
	{ // Avoid::ConnectorCrossings file:libavoid/connector.h line:512
		pybind11::class_<Avoid::ConnectorCrossings, std::shared_ptr<Avoid::ConnectorCrossings>> cl(M("Avoid"), "ConnectorCrossings", "");
		cl.def( pybind11::init( [](class Avoid::Polygon & a0, bool const & a1, class Avoid::Polygon & a2){ return new Avoid::ConnectorCrossings(a0, a1, a2); } ), "doc" , pybind11::arg("poly"), pybind11::arg("polyIsConn"), pybind11::arg("conn"));
		cl.def( pybind11::init( [](class Avoid::Polygon & a0, bool const & a1, class Avoid::Polygon & a2, class Avoid::ConnRef * a3){ return new Avoid::ConnectorCrossings(a0, a1, a2, a3); } ), "doc" , pybind11::arg("poly"), pybind11::arg("polyIsConn"), pybind11::arg("conn"), pybind11::arg("polyConnRef"));
		cl.def( pybind11::init<class Avoid::Polygon &, bool, class Avoid::Polygon &, class Avoid::ConnRef *, class Avoid::ConnRef *>(), pybind11::arg("poly"), pybind11::arg("polyIsConn"), pybind11::arg("conn"), pybind11::arg("polyConnRef"), pybind11::arg("connConnRef") );

		cl.def_readwrite("polyIsConn", &Avoid::ConnectorCrossings::polyIsConn);
		cl.def_readwrite("checkForBranchingSegments", &Avoid::ConnectorCrossings::checkForBranchingSegments);
		cl.def_readwrite("crossingCount", &Avoid::ConnectorCrossings::crossingCount);
		cl.def_readwrite("crossingFlags", &Avoid::ConnectorCrossings::crossingFlags);
		cl.def_readwrite("firstSharedPathAtEndLength", &Avoid::ConnectorCrossings::firstSharedPathAtEndLength);
		cl.def_readwrite("secondSharedPathAtEndLength", &Avoid::ConnectorCrossings::secondSharedPathAtEndLength);
		cl.def("clear", (void (Avoid::ConnectorCrossings::*)()) &Avoid::ConnectorCrossings::clear, "C++: Avoid::ConnectorCrossings::clear() --> void");
		cl.def("countForSegment", (void (Avoid::ConnectorCrossings::*)(unsigned long, const bool)) &Avoid::ConnectorCrossings::countForSegment, "C++: Avoid::ConnectorCrossings::countForSegment(unsigned long, const bool) --> void", pybind11::arg("cIndex"), pybind11::arg("finalSegment"));
	}
	// Avoid::splitBranchingSegments(class Avoid::Polygon &, bool, class Avoid::Polygon &, const double) file:libavoid/connector.h line:538
	M("Avoid").def("splitBranchingSegments", [](class Avoid::Polygon & a0, bool const & a1, class Avoid::Polygon & a2) -> void { return Avoid::splitBranchingSegments(a0, a1, a2); }, "", pybind11::arg("poly"), pybind11::arg("polyIsConn"), pybind11::arg("conn"));
	M("Avoid").def("splitBranchingSegments", (void (*)(class Avoid::Polygon &, bool, class Avoid::Polygon &, const double)) &Avoid::splitBranchingSegments, "C++: Avoid::splitBranchingSegments(class Avoid::Polygon &, bool, class Avoid::Polygon &, const double) --> void", pybind11::arg("poly"), pybind11::arg("polyIsConn"), pybind11::arg("conn"), pybind11::arg("tolerance"));

	// Avoid::validateBendPoint(class Avoid::VertInf *, class Avoid::VertInf *, class Avoid::VertInf *) file:libavoid/connector.h line:540
	M("Avoid").def("validateBendPoint", (bool (*)(class Avoid::VertInf *, class Avoid::VertInf *, class Avoid::VertInf *)) &Avoid::validateBendPoint, "C++: Avoid::validateBendPoint(class Avoid::VertInf *, class Avoid::VertInf *, class Avoid::VertInf *) --> bool", pybind11::arg("aInf"), pybind11::arg("bInf"), pybind11::arg("cInf"));

	// Avoid::db_printf(const char *) file:libavoid/debug.h line:64
	M("Avoid").def("db_printf", [](const char * a0) -> void { return Avoid::db_printf(a0); }, "", pybind11::arg(""));

	// Avoid::err_printf(const char *) file:libavoid/debug.h line:78
	M("Avoid").def("err_printf", [](const char * a0) -> void { return Avoid::err_printf(a0); }, "", pybind11::arg("fmt"));

	{ // Avoid::DebugHandler file:libavoid/debughandler.h line:46
		pybind11::class_<Avoid::DebugHandler, std::shared_ptr<Avoid::DebugHandler>, PyCallBack_Avoid_DebugHandler> cl(M("Avoid"), "DebugHandler", "");
		cl.def( pybind11::init( [](){ return new Avoid::DebugHandler(); }, [](){ return new PyCallBack_Avoid_DebugHandler(); } ) );
		cl.def("updateConnectorRoute", (void (Avoid::DebugHandler::*)(class Avoid::ConnRef *, int, int)) &Avoid::DebugHandler::updateConnectorRoute, "C++: Avoid::DebugHandler::updateConnectorRoute(class Avoid::ConnRef *, int, int) --> void", pybind11::arg("conn"), pybind11::arg("index1"), pybind11::arg("index2"));
		cl.def("beginningSearchWithEndpoints", (void (Avoid::DebugHandler::*)(class Avoid::VertInf *, class Avoid::VertInf *)) &Avoid::DebugHandler::beginningSearchWithEndpoints, "C++: Avoid::DebugHandler::beginningSearchWithEndpoints(class Avoid::VertInf *, class Avoid::VertInf *) --> void", pybind11::arg("src"), pybind11::arg("tar"));
		cl.def("updateCurrentSearchPath", (void (Avoid::DebugHandler::*)(class Avoid::Polygon)) &Avoid::DebugHandler::updateCurrentSearchPath, "C++: Avoid::DebugHandler::updateCurrentSearchPath(class Avoid::Polygon) --> void", pybind11::arg("currentPath"));
		cl.def("mtstGrowForestWithEdge", (void (Avoid::DebugHandler::*)(class Avoid::VertInf *, class Avoid::VertInf *, bool)) &Avoid::DebugHandler::mtstGrowForestWithEdge, "C++: Avoid::DebugHandler::mtstGrowForestWithEdge(class Avoid::VertInf *, class Avoid::VertInf *, bool) --> void", pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("shouldWait"));
		cl.def("mtstPotentialBridgingEdge", (void (Avoid::DebugHandler::*)(class Avoid::VertInf *, class Avoid::VertInf *)) &Avoid::DebugHandler::mtstPotentialBridgingEdge, "C++: Avoid::DebugHandler::mtstPotentialBridgingEdge(class Avoid::VertInf *, class Avoid::VertInf *) --> void", pybind11::arg("u"), pybind11::arg("v"));
		cl.def("mtstCommitToEdge", (void (Avoid::DebugHandler::*)(class Avoid::VertInf *, class Avoid::VertInf *, bool)) &Avoid::DebugHandler::mtstCommitToEdge, "C++: Avoid::DebugHandler::mtstCommitToEdge(class Avoid::VertInf *, class Avoid::VertInf *, bool) --> void", pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("isBridge"));
		cl.def("assign", (class Avoid::DebugHandler & (Avoid::DebugHandler::*)(const class Avoid::DebugHandler &)) &Avoid::DebugHandler::operator=, "C++: Avoid::DebugHandler::operator=(const class Avoid::DebugHandler &) --> class Avoid::DebugHandler &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::EdgeInf file:libavoid/graph.h line:46
		pybind11::class_<Avoid::EdgeInf, std::shared_ptr<Avoid::EdgeInf>> cl(M("Avoid"), "EdgeInf", "");
		cl.def( pybind11::init( [](class Avoid::VertInf * a0, class Avoid::VertInf * a1){ return new Avoid::EdgeInf(a0, a1); } ), "doc" , pybind11::arg("v1"), pybind11::arg("v2"));
		cl.def( pybind11::init<class Avoid::VertInf *, class Avoid::VertInf *, const bool>(), pybind11::arg("v1"), pybind11::arg("v2"), pybind11::arg("orthogonal") );

		cl.def( pybind11::init( [](Avoid::EdgeInf const &o){ return new Avoid::EdgeInf(o); } ) );
		cl.def("getDist", (double (Avoid::EdgeInf::*)()) &Avoid::EdgeInf::getDist, "C++: Avoid::EdgeInf::getDist() --> double");
		cl.def("setDist", (void (Avoid::EdgeInf::*)(double)) &Avoid::EdgeInf::setDist, "C++: Avoid::EdgeInf::setDist(double) --> void", pybind11::arg("dist"));
		cl.def("alertConns", (void (Avoid::EdgeInf::*)()) &Avoid::EdgeInf::alertConns, "C++: Avoid::EdgeInf::alertConns() --> void");
		cl.def("addConn", (void (Avoid::EdgeInf::*)(bool *)) &Avoid::EdgeInf::addConn, "C++: Avoid::EdgeInf::addConn(bool *) --> void", pybind11::arg("flag"));
		cl.def("addCycleBlocker", (void (Avoid::EdgeInf::*)()) &Avoid::EdgeInf::addCycleBlocker, "C++: Avoid::EdgeInf::addCycleBlocker() --> void");
		cl.def("addBlocker", (void (Avoid::EdgeInf::*)(int)) &Avoid::EdgeInf::addBlocker, "C++: Avoid::EdgeInf::addBlocker(int) --> void", pybind11::arg("b"));
		cl.def("added", (bool (Avoid::EdgeInf::*)()) &Avoid::EdgeInf::added, "C++: Avoid::EdgeInf::added() --> bool");
		cl.def("isOrthogonal", (bool (Avoid::EdgeInf::*)() const) &Avoid::EdgeInf::isOrthogonal, "C++: Avoid::EdgeInf::isOrthogonal() const --> bool");
		cl.def("isDummyConnection", (bool (Avoid::EdgeInf::*)() const) &Avoid::EdgeInf::isDummyConnection, "C++: Avoid::EdgeInf::isDummyConnection() const --> bool");
		cl.def("isDisabled", (bool (Avoid::EdgeInf::*)() const) &Avoid::EdgeInf::isDisabled, "C++: Avoid::EdgeInf::isDisabled() const --> bool");
		cl.def("setDisabled", (void (Avoid::EdgeInf::*)(const bool)) &Avoid::EdgeInf::setDisabled, "C++: Avoid::EdgeInf::setDisabled(const bool) --> void", pybind11::arg("disabled"));
		cl.def("rotationLessThan", (bool (Avoid::EdgeInf::*)(const class Avoid::VertInf *, const class Avoid::EdgeInf *) const) &Avoid::EdgeInf::rotationLessThan, "C++: Avoid::EdgeInf::rotationLessThan(const class Avoid::VertInf *, const class Avoid::EdgeInf *) const --> bool", pybind11::arg("last"), pybind11::arg("rhs"));
		cl.def("db_print", (void (Avoid::EdgeInf::*)()) &Avoid::EdgeInf::db_print, "C++: Avoid::EdgeInf::db_print() --> void");
		cl.def("checkVis", (void (Avoid::EdgeInf::*)()) &Avoid::EdgeInf::checkVis, "C++: Avoid::EdgeInf::checkVis() --> void");
		cl.def("otherVert", (class Avoid::VertInf * (Avoid::EdgeInf::*)(const class Avoid::VertInf *) const) &Avoid::EdgeInf::otherVert, "C++: Avoid::EdgeInf::otherVert(const class Avoid::VertInf *) const --> class Avoid::VertInf *", pybind11::return_value_policy::automatic, pybind11::arg("vert"));
		cl.def_static("checkEdgeVisibility", [](class Avoid::VertInf * a0, class Avoid::VertInf * a1) -> Avoid::EdgeInf * { return Avoid::EdgeInf::checkEdgeVisibility(a0, a1); }, "", pybind11::return_value_policy::automatic, pybind11::arg("i"), pybind11::arg("j"));
		cl.def_static("checkEdgeVisibility", (class Avoid::EdgeInf * (*)(class Avoid::VertInf *, class Avoid::VertInf *, bool)) &Avoid::EdgeInf::checkEdgeVisibility, "C++: Avoid::EdgeInf::checkEdgeVisibility(class Avoid::VertInf *, class Avoid::VertInf *, bool) --> class Avoid::EdgeInf *", pybind11::return_value_policy::automatic, pybind11::arg("i"), pybind11::arg("j"), pybind11::arg("knownNew"));
		cl.def_static("existingEdge", (class Avoid::EdgeInf * (*)(class Avoid::VertInf *, class Avoid::VertInf *)) &Avoid::EdgeInf::existingEdge, "C++: Avoid::EdgeInf::existingEdge(class Avoid::VertInf *, class Avoid::VertInf *) --> class Avoid::EdgeInf *", pybind11::return_value_policy::automatic, pybind11::arg("i"), pybind11::arg("j"));
		cl.def("blocker", (int (Avoid::EdgeInf::*)() const) &Avoid::EdgeInf::blocker, "C++: Avoid::EdgeInf::blocker() const --> int");
		cl.def("isHyperedgeSegment", (bool (Avoid::EdgeInf::*)() const) &Avoid::EdgeInf::isHyperedgeSegment, "C++: Avoid::EdgeInf::isHyperedgeSegment() const --> bool");
		cl.def("setHyperedgeSegment", (void (Avoid::EdgeInf::*)(const bool)) &Avoid::EdgeInf::setHyperedgeSegment, "C++: Avoid::EdgeInf::setHyperedgeSegment(const bool) --> void", pybind11::arg("hyperedge"));
		cl.def("mtstDist", (double (Avoid::EdgeInf::*)() const) &Avoid::EdgeInf::mtstDist, "C++: Avoid::EdgeInf::mtstDist() const --> double");
		cl.def("setMtstDist", (void (Avoid::EdgeInf::*)(const double)) &Avoid::EdgeInf::setMtstDist, "C++: Avoid::EdgeInf::setMtstDist(const double) --> void", pybind11::arg("joinCost"));
	}
	{ // Avoid::EdgeList file:libavoid/graph.h line:109
		pybind11::class_<Avoid::EdgeList, std::shared_ptr<Avoid::EdgeList>> cl(M("Avoid"), "EdgeList", "");
		cl.def( pybind11::init( [](){ return new Avoid::EdgeList(); } ), "doc" );
		cl.def( pybind11::init<bool>(), pybind11::arg("orthogonal") );

		cl.def( pybind11::init( [](Avoid::EdgeList const &o){ return new Avoid::EdgeList(o); } ) );
		cl.def("clear", (void (Avoid::EdgeList::*)()) &Avoid::EdgeList::clear, "C++: Avoid::EdgeList::clear() --> void");
		cl.def("begin", (class Avoid::EdgeInf * (Avoid::EdgeList::*)()) &Avoid::EdgeList::begin, "C++: Avoid::EdgeList::begin() --> class Avoid::EdgeInf *", pybind11::return_value_policy::automatic);
		cl.def("end", (class Avoid::EdgeInf * (Avoid::EdgeList::*)()) &Avoid::EdgeList::end, "C++: Avoid::EdgeList::end() --> class Avoid::EdgeInf *", pybind11::return_value_policy::automatic);
		cl.def("size", (int (Avoid::EdgeList::*)() const) &Avoid::EdgeList::size, "C++: Avoid::EdgeList::size() const --> int");
		cl.def("assign", (class Avoid::EdgeList & (Avoid::EdgeList::*)(const class Avoid::EdgeList &)) &Avoid::EdgeList::operator=, "C++: Avoid::EdgeList::operator=(const class Avoid::EdgeList &) --> class Avoid::EdgeList &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::HyperedgeNewAndDeletedObjectLists file:libavoid/hyperedge.h line:79
		pybind11::class_<Avoid::HyperedgeNewAndDeletedObjectLists, std::shared_ptr<Avoid::HyperedgeNewAndDeletedObjectLists>> cl(M("Avoid"), "HyperedgeNewAndDeletedObjectLists", "The HyperedgeNewAndDeletedObjectLists class stores lists of \n          objects created and deleted during hyperedge improvement.\n\n After hyperedge improvement, this information can be produced by calling\n the Router::newAndDeletedObjectListsFromHyperedgeImprovement() method.\n\n After hyperedge rerouting, this information can be produced by calling \n the HyperedgeRerouter::newAndDeletedObjectLists() method for each \n hyperedge being fully rerouted.\n\n The HyperedgeNewAndDeletedObjectLists::changedConnectorList attribute \n will only be used for hyperedge improvement and will always be empty \n for hyperedge rerouting.");
		cl.def( pybind11::init( [](){ return new Avoid::HyperedgeNewAndDeletedObjectLists(); } ) );
		cl.def( pybind11::init( [](Avoid::HyperedgeNewAndDeletedObjectLists const &o){ return new Avoid::HyperedgeNewAndDeletedObjectLists(o); } ) );
		cl.def_readwrite("newJunctionList", &Avoid::HyperedgeNewAndDeletedObjectLists::newJunctionList);
		cl.def_readwrite("newConnectorList", &Avoid::HyperedgeNewAndDeletedObjectLists::newConnectorList);
		cl.def_readwrite("deletedJunctionList", &Avoid::HyperedgeNewAndDeletedObjectLists::deletedJunctionList);
		cl.def_readwrite("deletedConnectorList", &Avoid::HyperedgeNewAndDeletedObjectLists::deletedConnectorList);
		cl.def_readwrite("changedConnectorList", &Avoid::HyperedgeNewAndDeletedObjectLists::changedConnectorList);
	}
	{ // Avoid::HyperedgeRerouter file:libavoid/hyperedge.h line:129
		pybind11::class_<Avoid::HyperedgeRerouter, std::shared_ptr<Avoid::HyperedgeRerouter>> cl(M("Avoid"), "HyperedgeRerouter", "The HyperedgeRerouter class is a convenience object that can be\n          used to register hyperedges to be rerouted, improving the\n          placement of their junctions and connector paths.\n\n To work with this class, you should get a copy from the router instance\n via a call to Router::hyperedgeRerouter().\n\n If you would like a particular hyperedge to be completely rerouted with\n new junction positions then you should register it with this class via a\n call to registerHyperedgeForRerouting.  A hyperedge can either be\n specified as a set of terminal vertices, or as a single JunctionRef.\n Passing a JunctionRef will cause HyperedgeRerouter to follow the attached\n connectors and junctions to determine the hyperedge.  When you register\n a hyperedge you get an index number that can be used to later find\n information about it.\n\n The rerouting will actually occur the next time the Router processes a\n transaction, see Router::processTransaction().  The rerouting will\n effectively create new junctions (JunctionRefs) and connectors (ConnRefs)\n for the hyperedge.  \n\n Since hyperedges are composed of multiple connections and junction objects,\n rerouting a hyperedge can cause creation of new or deletion of existing \n connectors and/or junctions.  Thus once the transaction has been completed\n you should call the newAndDeletedObjectLists() to get an object containing\n the lists of created and deleted junctions and connectors.  After the\n transaction You should not use references to these deleted objects any \n more from your own code (since the router will free their memory at its\n convenience) and you should refer only to the unaffected objects and the \n new connectors and junctions.");
		cl.def( pybind11::init( [](){ return new Avoid::HyperedgeRerouter(); } ) );
		cl.def( pybind11::init( [](Avoid::HyperedgeRerouter const &o){ return new Avoid::HyperedgeRerouter(o); } ) );
		cl.def("registerHyperedgeForRerouting", (unsigned long (Avoid::HyperedgeRerouter::*)(class Avoid::JunctionRef *)) &Avoid::HyperedgeRerouter::registerHyperedgeForRerouting, "Registers a hyperedge to be fully rerouted the next time\n         the router processes a transaction.\n\n In this case the connectors and junctions attached to the given\n junction will be traversed to determine the endpoints of the\n hyperedge.  These endpoints will then be used for the rerouting.\n The junctions and connectors forming the old route will be\n deleted.\n\n \n  One of the junctions that forms the\n                      hyperedge.\n \n\n An index that can be used to request information on the\n         resulting routing of the hyperedge.\n\nC++: Avoid::HyperedgeRerouter::registerHyperedgeForRerouting(class Avoid::JunctionRef *) --> unsigned long", pybind11::arg("junction"));
		cl.def("newAndDeletedObjectLists", (struct Avoid::HyperedgeNewAndDeletedObjectLists (Avoid::HyperedgeRerouter::*)(unsigned long) const) &Avoid::HyperedgeRerouter::newAndDeletedObjectLists, "Returns a HyperedgeNewAndDeletedObjectLists detailing the\n         lists of junctions and connectors created and deleted\n         during hyperedge improvement.\n\n This method will only return information once the router has\n processed the transaction.  You should read this information \n before processTransaction() is called again.\n\n After calling this you should no longer refer to any of the\n objects in the \"deleted\" lists --- the router will delete these \n and free their memory at its convenience.\n\n \n  The index of the hyperedge to return junctions for.\n \n\n A HyperedgeNewAndDeletedObjectLists containing lists of \n         junctions and connectors created and deleted.\n\nC++: Avoid::HyperedgeRerouter::newAndDeletedObjectLists(unsigned long) const --> struct Avoid::HyperedgeNewAndDeletedObjectLists", pybind11::arg("index"));
		cl.def("count", (unsigned long (Avoid::HyperedgeRerouter::*)() const) &Avoid::HyperedgeRerouter::count, "C++: Avoid::HyperedgeRerouter::count() const --> unsigned long");
		cl.def("assign", (class Avoid::HyperedgeRerouter & (Avoid::HyperedgeRerouter::*)(const class Avoid::HyperedgeRerouter &)) &Avoid::HyperedgeRerouter::operator=, "C++: Avoid::HyperedgeRerouter::operator=(const class Avoid::HyperedgeRerouter &) --> class Avoid::HyperedgeRerouter &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
