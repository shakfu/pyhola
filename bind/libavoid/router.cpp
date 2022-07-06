#include <_stdio.h>
#include <functional>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
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
#include <list>
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

// Avoid::TopologyAddonInterface file:libavoid/router.h line:350
struct PyCallBack_Avoid_TopologyAddonInterface : public Avoid::TopologyAddonInterface {
	using Avoid::TopologyAddonInterface::TopologyAddonInterface;

	class Avoid::TopologyAddonInterface * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::TopologyAddonInterface *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Avoid::TopologyAddonInterface *>::value) {
				static pybind11::detail::override_caster_t<class Avoid::TopologyAddonInterface *> caster;
				return pybind11::detail::cast_ref<class Avoid::TopologyAddonInterface *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Avoid::TopologyAddonInterface *>(std::move(o));
		}
		return TopologyAddonInterface::clone();
	}
	void improveOrthogonalTopology(class Avoid::Router * a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::TopologyAddonInterface *>(this), "improveOrthogonalTopology");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return TopologyAddonInterface::improveOrthogonalTopology(a0);
	}
	bool outputCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::TopologyAddonInterface *>(this), "outputCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return TopologyAddonInterface::outputCode(a0);
	}
	bool outputDeletionCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::TopologyAddonInterface *>(this), "outputDeletionCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return TopologyAddonInterface::outputDeletionCode(a0);
	}
};

// Avoid::Router file:libavoid/router.h line:386
struct PyCallBack_Avoid_Router : public Avoid::Router {
	using Avoid::Router::Router;

	unsigned int newObjectId() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Router *>(this), "newObjectId");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		return Router::newObjectId();
	}
	bool shouldContinueTransactionWithProgress(unsigned int a0, unsigned int a1, unsigned int a2, double a3) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Router *>(this), "shouldContinueTransactionWithProgress");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2, a3);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Router::shouldContinueTransactionWithProgress(a0, a1, a2, a3);
	}
};

void bind_libavoid_router(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::TopologyAddonInterface file:libavoid/router.h line:350
		pybind11::class_<Avoid::TopologyAddonInterface, std::shared_ptr<Avoid::TopologyAddonInterface>, PyCallBack_Avoid_TopologyAddonInterface> cl(M("Avoid"), "TopologyAddonInterface", "");
		cl.def( pybind11::init( [](){ return new Avoid::TopologyAddonInterface(); }, [](){ return new PyCallBack_Avoid_TopologyAddonInterface(); } ) );
		cl.def( pybind11::init( [](PyCallBack_Avoid_TopologyAddonInterface const &o){ return new PyCallBack_Avoid_TopologyAddonInterface(o); } ) );
		cl.def( pybind11::init( [](Avoid::TopologyAddonInterface const &o){ return new Avoid::TopologyAddonInterface(o); } ) );
		cl.def("clone", (class Avoid::TopologyAddonInterface * (Avoid::TopologyAddonInterface::*)() const) &Avoid::TopologyAddonInterface::clone, "C++: Avoid::TopologyAddonInterface::clone() const --> class Avoid::TopologyAddonInterface *", pybind11::return_value_policy::automatic);
		cl.def("improveOrthogonalTopology", (void (Avoid::TopologyAddonInterface::*)(class Avoid::Router *)) &Avoid::TopologyAddonInterface::improveOrthogonalTopology, "C++: Avoid::TopologyAddonInterface::improveOrthogonalTopology(class Avoid::Router *) --> void", pybind11::arg("router"));
		cl.def("outputCode", (bool (Avoid::TopologyAddonInterface::*)(struct __sFILE *) const) &Avoid::TopologyAddonInterface::outputCode, "C++: Avoid::TopologyAddonInterface::outputCode(struct __sFILE *) const --> bool", pybind11::arg("fp"));
		cl.def("outputDeletionCode", (bool (Avoid::TopologyAddonInterface::*)(struct __sFILE *) const) &Avoid::TopologyAddonInterface::outputDeletionCode, "C++: Avoid::TopologyAddonInterface::outputDeletionCode(struct __sFILE *) const --> bool", pybind11::arg("fp"));
		cl.def("assign", (class Avoid::TopologyAddonInterface & (Avoid::TopologyAddonInterface::*)(const class Avoid::TopologyAddonInterface &)) &Avoid::TopologyAddonInterface::operator=, "C++: Avoid::TopologyAddonInterface::operator=(const class Avoid::TopologyAddonInterface &) --> class Avoid::TopologyAddonInterface &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::Router file:libavoid/router.h line:386
		pybind11::class_<Avoid::Router, std::shared_ptr<Avoid::Router>, PyCallBack_Avoid_Router> cl(M("Avoid"), "Router", "The Router class represents a libavoid router instance.\n\n Usually you would keep a separate Router instance for each diagram\n or layout you have open in your application.");
		cl.def( pybind11::init<const unsigned int>(), pybind11::arg("flags") );

		cl.def( pybind11::init( [](PyCallBack_Avoid_Router const &o){ return new PyCallBack_Avoid_Router(o); } ) );
		cl.def( pybind11::init( [](Avoid::Router const &o){ return new Avoid::Router(o); } ) );
		cl.def_readwrite("m_obstacles", &Avoid::Router::m_obstacles);
		cl.def_readwrite("connRefs", &Avoid::Router::connRefs);
		cl.def_readwrite("clusterRefs", &Avoid::Router::clusterRefs);
		cl.def_readwrite("visGraph", &Avoid::Router::visGraph);
		cl.def_readwrite("invisGraph", &Avoid::Router::invisGraph);
		cl.def_readwrite("visOrthogGraph", &Avoid::Router::visOrthogGraph);
		cl.def_readwrite("contains", &Avoid::Router::contains);
		cl.def_readwrite("vertices", &Avoid::Router::vertices);
		cl.def_readwrite("enclosingClusters", &Avoid::Router::enclosingClusters);
		cl.def_readwrite("PartialTime", &Avoid::Router::PartialTime);
		cl.def_readwrite("SimpleRouting", &Avoid::Router::SimpleRouting);
		cl.def_readwrite("ClusteredRouting", &Avoid::Router::ClusteredRouting);
		cl.def_readwrite("IgnoreRegions", &Avoid::Router::IgnoreRegions);
		cl.def_readwrite("UseLeesAlgorithm", &Avoid::Router::UseLeesAlgorithm);
		cl.def_readwrite("InvisibilityGrph", &Avoid::Router::InvisibilityGrph);
		cl.def_readwrite("SelectiveReroute", &Avoid::Router::SelectiveReroute);
		cl.def_readwrite("PartialFeedback", &Avoid::Router::PartialFeedback);
		cl.def_readwrite("RubberBandRouting", &Avoid::Router::RubberBandRouting);
		cl.def_readwrite("st_checked_edges", &Avoid::Router::st_checked_edges);
		cl.def("setTransactionUse", (void (Avoid::Router::*)(const bool)) &Avoid::Router::setTransactionUse, "Allows setting of the behaviour of the router in regard\n        to transactions.  This controls whether transactions are\n        used to queue changes and process them efficiently at once\n        or they are instead processed immediately.\n\n It is more efficient to perform actions like shape movement,\n addition or deletion as batch tasks, and reroute the necessary\n connectors just once after these actions have been performed.\n For this reason, libavoid allows you to group such actions into\n \"transactions\" that are processed efficiently when the \n processTransaction() method is called.\n\n By default, the router will process all actions as transactions.\n If transactionUse() is set to false, then all actions will get \n processed immediately, and cause immediate routing callbacks to \n all affected connectors after each action.\n\n \n  A boolean value specifying whether to\n                           use transactions.\n\nC++: Avoid::Router::setTransactionUse(const bool) --> void", pybind11::arg("transactions"));
		cl.def("transactionUse", (bool (Avoid::Router::*)() const) &Avoid::Router::transactionUse, "Reports whether the router groups actions into transactions.\n\n \n A boolean value describing whether transactions are in use.\n\n \n setTransactionUse\n \n\n processTransaction\n\nC++: Avoid::Router::transactionUse() const --> bool");
		cl.def("processTransaction", (bool (Avoid::Router::*)()) &Avoid::Router::processTransaction, "Finishes the current transaction and processes all the \n        queued object changes efficiently.\n\n This method will efficiently process all moves, additions and\n deletions that have occurred since processTransaction() was \n last called.\n\n If transactionUse() is false, then all actions will have been \n processed immediately and this method will do nothing.\n\n \n A boolean value describing whether there were any actions\n         to process.\n\n \n setTransactionUse\n\nC++: Avoid::Router::processTransaction() --> bool");
		cl.def("deleteShape", (void (Avoid::Router::*)(class Avoid::ShapeRef *)) &Avoid::Router::deleteShape, "Delete a shape from the router scene.\n\n Connectors that could have a better (usually shorter) path after\n the removal of this shape will be marked as needing to be rerouted.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n You should not use the shape reference again after this call.\n The router will handle freeing of the shape's memory.\n\n \n  Pointer reference to the shape being removed.\n\nC++: Avoid::Router::deleteShape(class Avoid::ShapeRef *) --> void", pybind11::arg("shape"));
		cl.def("moveShape", [](Avoid::Router &o, class Avoid::ShapeRef * a0, const class Avoid::Polygon & a1) -> void { return o.moveShape(a0, a1); }, "", pybind11::arg("shape"), pybind11::arg("newPoly"));
		cl.def("moveShape", (void (Avoid::Router::*)(class Avoid::ShapeRef *, const class Avoid::Polygon &, const bool)) &Avoid::Router::moveShape, "Move or resize an existing shape within the router scene.\n\n A new polygon for the shape can be given to effectively move or \n resize the shape with the scene.  Connectors that intersect the \n new shape polygon, or that could have a better (usually shorter)\n path after the change, will be marked as needing to be rerouted.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n \n       Pointer reference to the shape being \n                         moved/resized.\n \n\n     The new polygon boundary for the shape.\n \n\n  This option is used for some advanced \n                         (currently undocumented) behaviour and \n                         it should be ignored for the moment.\n\nC++: Avoid::Router::moveShape(class Avoid::ShapeRef *, const class Avoid::Polygon &, const bool) --> void", pybind11::arg("shape"), pybind11::arg("newPoly"), pybind11::arg("first_move"));
		cl.def("moveShape", (void (Avoid::Router::*)(class Avoid::ShapeRef *, const double, const double)) &Avoid::Router::moveShape, "Move an existing shape within the router scene by a relative\n        distance.\n\n Connectors that intersect the shape's new position, or that could \n have a better (usually shorter) path after the change, will be \n marked as needing to be rerouted.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n \n       Pointer reference to the shape being moved.\n \n\n       The distance to move the shape in the \n                         x dimension.\n \n\n       The distance to move the shape in the \n                         y dimension.\n\nC++: Avoid::Router::moveShape(class Avoid::ShapeRef *, const double, const double) --> void", pybind11::arg("shape"), pybind11::arg("xDiff"), pybind11::arg("yDiff"));
		cl.def("deleteJunction", (void (Avoid::Router::*)(class Avoid::JunctionRef *)) &Avoid::Router::deleteJunction, "Remove a junction from the router scene.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n You should not use the junction reference again after this call.\n The router will handle freeing of the junction's memory.\n\n \n  Pointer reference to the junction being \n                       removed.\n\nC++: Avoid::Router::deleteJunction(class Avoid::JunctionRef *) --> void", pybind11::arg("junction"));
		cl.def("deleteConnector", (void (Avoid::Router::*)(class Avoid::ConnRef *)) &Avoid::Router::deleteConnector, "Remove a connector from the router scene.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n You should not use the connector reference again after this call.\n The router will handle freeing of the connector's memory.\n\n \n  Pointer reference to the connector being\n                        removed.\n\nC++: Avoid::Router::deleteConnector(class Avoid::ConnRef *) --> void", pybind11::arg("connector"));
		cl.def("moveJunction", (void (Avoid::Router::*)(class Avoid::JunctionRef *, const class Avoid::Point &)) &Avoid::Router::moveJunction, "Move an existing junction within the router scene.\n\n Connectors that are attached to this junction will be rerouted \n as a result of the move.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n \n     Pointer reference to the junction being\n                          moved.\n \n\n  The new position for the junction.\n\nC++: Avoid::Router::moveJunction(class Avoid::JunctionRef *, const class Avoid::Point &) --> void", pybind11::arg("junction"), pybind11::arg("newPosition"));
		cl.def("moveJunction", (void (Avoid::Router::*)(class Avoid::JunctionRef *, const double, const double)) &Avoid::Router::moveJunction, "Move an existing junction within the router scene by a \n        relative distance.\n\n Connectors that are attached to this junction will be rerouted \n as a result of the move.\n\n If the router is using transactions, then this action will occur\n the next time Router::processTransaction() is called.  See\n Router::setTransactionUse() for more information.\n\n \n    Pointer reference to the junction being \n                         moved.\n \n\n       The distance to move the junction in the \n                         x dimension.\n \n\n       The distance to move the junction in the \n                         y dimension.\n\nC++: Avoid::Router::moveJunction(class Avoid::JunctionRef *, const double, const double) --> void", pybind11::arg("junction"), pybind11::arg("xDiff"), pybind11::arg("yDiff"));
		cl.def("setRoutingParameter", [](Avoid::Router &o, const enum Avoid::RoutingParameter & a0) -> void { return o.setRoutingParameter(a0); }, "", pybind11::arg("parameter"));
		cl.def("setRoutingParameter", (void (Avoid::Router::*)(const enum Avoid::RoutingParameter, const double)) &Avoid::Router::setRoutingParameter, "Sets values for routing parameters, including routing \n         penalties.\n\n libavoid uses a set of parameters to allow the user more control\n over routing style and quality.  These different parameters are\n described and explained by the RoutingParameter enum.  All \n parameters have sensible defaults.\n\n Regarding routing penalties, libavoid will by default produce\n shortest path routes between the source and destination points \n for each connector.  There are several penalties that can be \n applied during this stage to penalise certain conditions and\n thus improve the aesthetics of the routes generated.  \n\n If a value of zero or Avoid::zeroParamValue is given then the \n particular parameter value or penalty will be removed.  If no \n parameter value argument (or a negative value) is specified \n when calling this method, then a sensible penalty value will \n be automatically chosen.\n\n This method does not re-trigger processing of connectors. The new\n parameter value will be used the next time rerouting is performed.\n\n \n  The type of penalty, a RoutingParameter.\n \n\n      The value to be set for that parameter.\n\nC++: Avoid::Router::setRoutingParameter(const enum Avoid::RoutingParameter, const double) --> void", pybind11::arg("parameter"), pybind11::arg("value"));
		cl.def("routingParameter", (double (Avoid::Router::*)(const enum Avoid::RoutingParameter) const) &Avoid::Router::routingParameter, "Returns the current value for a particular routing\n         parameter of a given type.\n\n \n  The type of parameter, a RoutingParameter.\n \n\n  The value for the specified routing parameter.\n\nC++: Avoid::Router::routingParameter(const enum Avoid::RoutingParameter) const --> double", pybind11::arg("parameter"));
		cl.def("setRoutingOption", (void (Avoid::Router::*)(const enum Avoid::RoutingOption, const bool)) &Avoid::Router::setRoutingOption, "Turn specific routing options on or off.\n\n \n  The type of routing option, a RoutingOption.\n \n\n   A boolean representing the option state.\n\nC++: Avoid::Router::setRoutingOption(const enum Avoid::RoutingOption, const bool) --> void", pybind11::arg("option"), pybind11::arg("value"));
		cl.def("routingOption", (bool (Avoid::Router::*)(const enum Avoid::RoutingOption) const) &Avoid::Router::routingOption, "Returns the current state for a specific routing option.\n\n \n  The type of routing option, a RoutingOption.\n \n\n  A boolean representing the option state.\n\nC++: Avoid::Router::routingOption(const enum Avoid::RoutingOption) const --> bool", pybind11::arg("option"));
		cl.def("setRoutingPenalty", [](Avoid::Router &o, const enum Avoid::RoutingParameter & a0) -> void { return o.setRoutingPenalty(a0); }, "", pybind11::arg("penType"));
		cl.def("setRoutingPenalty", (void (Avoid::Router::*)(const enum Avoid::RoutingParameter, const double)) &Avoid::Router::setRoutingPenalty, "The type of penalty, a RoutingParameter.\n \n\n   The value to be applied for each occurrence\n                     of the penalty case.  \n\nC++: Avoid::Router::setRoutingPenalty(const enum Avoid::RoutingParameter, const double) --> void", pybind11::arg("penType"), pybind11::arg("penVal"));
		cl.def("hyperedgeRerouter", (class Avoid::HyperedgeRerouter * (Avoid::Router::*)()) &Avoid::Router::hyperedgeRerouter, "Returns a pointer to the hyperedge rerouter for the router.\n\n \n  A HyperedgeRerouter object that can be used to register\n          hyperedges for rerouting.\n\nC++: Avoid::Router::hyperedgeRerouter() --> class Avoid::HyperedgeRerouter *", pybind11::return_value_policy::automatic);
		cl.def("outputInstanceToSVG", [](Avoid::Router &o) -> void { return o.outputInstanceToSVG(); }, "");
		cl.def("outputInstanceToSVG", (void (Avoid::Router::*)(std::string)) &Avoid::Router::outputInstanceToSVG, "Generates an SVG file containing debug output and code that\n         can be used to regenerate the instance.\n\n If transactions are being used, then this method should be called \n after processTransaction() has been called, so that it includes any\n changes being queued by the router.\n\n \n  A string indicating the filename (without \n                      extension) for the output file.  Defaults to\n                      \"libavoid-debug.svg\" if no filename is given.\n\nC++: Avoid::Router::outputInstanceToSVG(std::string) --> void", pybind11::arg("filename"));
		cl.def("newObjectId", (unsigned int (Avoid::Router::*)() const) &Avoid::Router::newObjectId, "Returns the object ID used for automatically generated \n         objects, such as during hyperedge routing.\n\n Reimplement this in a subclass to set specific IDs for new objects.\n\n \n   Your implementation should return a value that does not \n         fail objectIdIsUnused().\n\n \n  The ID for a new object.\n\nC++: Avoid::Router::newObjectId() const --> unsigned int");
		cl.def("objectIdIsUnused", (bool (Avoid::Router::*)(const unsigned int) const) &Avoid::Router::objectIdIsUnused, "Returns whether or not the given ID is already used.\n\n You should only need this if you reimplement newObjectId().\n\n \n  An ID to test.\n \n\n  A boolean denoting that the given ID is unused.\n\nC++: Avoid::Router::objectIdIsUnused(const unsigned int) const --> bool", pybind11::arg("id"));
		cl.def("shouldContinueTransactionWithProgress", (bool (Avoid::Router::*)(unsigned int, unsigned int, unsigned int, double)) &Avoid::Router::shouldContinueTransactionWithProgress, "A method called at regular intervals during transaction \n         processing to report progress and ask if the Router\n         should continue the transaction.\n\n You can subclass the Avoid::Router class to implement your \n own behaviour, such as to show a progress bar or cancel the \n transaction at the user's request.\n\n Note that you can get a sense of progress by looking at the \n phaseNumber divided by the totalPhases and the progress in the \n current phase, but be aware that phases and the intervals and\n proportions at which this method is called will vary, sometime\n unpredictably.\n\n You can return false to request that the Router abort the current\n transaction.  Be aware that it may not abort in some phases. For\n others it may need to clean up some state before it is safe for \n you to interact with it again.  Hence you should wait for a final \n call to this method with the phase Avoid::TransactionPhaseCompleted\n before continuing.\n\n \n  Your implementation of this method should be very fast as\n        it will be called many times.  Also, you should not change\n        or interact with the Router instance at all during these \n        calls.  Wait till you have received a call with the \n        Avoid::TransactionPhaseCompleted phase.\n\n \n  The number of msec spent on the transaction\n                      since it began.\n \n\n  A Router::TransactionPhases representing the\n                      current phase of the transaction.\n \n\n  The total number of phases to be performed \n                      during the transaction.\n \n\n   A double representing the progress in the \n                      current phase.  Value will be between 0--1.\n\n \n  Whether the router should continue the transaction.\n          This is true in the default (empty) implementation.\n\nC++: Avoid::Router::shouldContinueTransactionWithProgress(unsigned int, unsigned int, unsigned int, double) --> bool", pybind11::arg("elapsedTime"), pybind11::arg("phaseNumber"), pybind11::arg("totalPhases"), pybind11::arg("proportion"));
		cl.def("newAndDeletedObjectListsFromHyperedgeImprovement", (struct Avoid::HyperedgeNewAndDeletedObjectLists (Avoid::Router::*)() const) &Avoid::Router::newAndDeletedObjectListsFromHyperedgeImprovement, "Returns a HyperedgeNewAndDeletedObjectLists detailing the\n         lists of junctions and connectors created and deleted\n         during hyperedge improvement.\n\n This method will only return information once the router has\n processed the transaction.  You should read and act on this \n information before processTransaction() is called again.\n\n After calling this you should no longer refer to any of the\n objects in the \"deleted\" lists --- the router will delete these \n and free their memory at its convenience.\n\n \n A HyperedgeNewAndDeletedObjectLists containing lists of \n         junctions and connectors created and deleted.\n\nC++: Avoid::Router::newAndDeletedObjectListsFromHyperedgeImprovement() const --> struct Avoid::HyperedgeNewAndDeletedObjectLists");
		cl.def("setDebugHandler", (void (Avoid::Router::*)(class Avoid::DebugHandler *)) &Avoid::Router::setDebugHandler, "C++: Avoid::Router::setDebugHandler(class Avoid::DebugHandler *) --> void", pybind11::arg("handler"));
		cl.def("debugHandler", (class Avoid::DebugHandler * (Avoid::Router::*)() const) &Avoid::Router::debugHandler, "C++: Avoid::Router::debugHandler() const --> class Avoid::DebugHandler *", pybind11::return_value_policy::automatic);
		cl.def("processActions", (void (Avoid::Router::*)()) &Avoid::Router::processActions, "C++: Avoid::Router::processActions() --> void");
		cl.def("deleteCluster", (void (Avoid::Router::*)(class Avoid::ClusterRef *)) &Avoid::Router::deleteCluster, "C++: Avoid::Router::deleteCluster(class Avoid::ClusterRef *) --> void", pybind11::arg("cluster"));
		cl.def("markPolylineConnectorsNeedingReroutingForDeletedObstacle", (void (Avoid::Router::*)(class Avoid::Obstacle *)) &Avoid::Router::markPolylineConnectorsNeedingReroutingForDeletedObstacle, "C++: Avoid::Router::markPolylineConnectorsNeedingReroutingForDeletedObstacle(class Avoid::Obstacle *) --> void", pybind11::arg("obstacle"));
		cl.def("generateContains", (void (Avoid::Router::*)(class Avoid::VertInf *)) &Avoid::Router::generateContains, "C++: Avoid::Router::generateContains(class Avoid::VertInf *) --> void", pybind11::arg("pt"));
		cl.def("printInfo", (void (Avoid::Router::*)()) &Avoid::Router::printInfo, "C++: Avoid::Router::printInfo() --> void");
		cl.def("regenerateStaticBuiltGraph", (void (Avoid::Router::*)()) &Avoid::Router::regenerateStaticBuiltGraph, "C++: Avoid::Router::regenerateStaticBuiltGraph() --> void");
		cl.def("destroyOrthogonalVisGraph", (void (Avoid::Router::*)()) &Avoid::Router::destroyOrthogonalVisGraph, "C++: Avoid::Router::destroyOrthogonalVisGraph() --> void");
		cl.def("setStaticGraphInvalidated", (void (Avoid::Router::*)(const bool)) &Avoid::Router::setStaticGraphInvalidated, "C++: Avoid::Router::setStaticGraphInvalidated(const bool) --> void", pybind11::arg("invalidated"));
		cl.def("validConnType", [](Avoid::Router const &o) -> Avoid::ConnType { return o.validConnType(); }, "");
		cl.def("validConnType", (enum Avoid::ConnType (Avoid::Router::*)(const enum Avoid::ConnType) const) &Avoid::Router::validConnType, "C++: Avoid::Router::validConnType(const enum Avoid::ConnType) const --> enum Avoid::ConnType", pybind11::arg("select"));
		cl.def("isInCrossingPenaltyReroutingStage", (bool (Avoid::Router::*)() const) &Avoid::Router::isInCrossingPenaltyReroutingStage, "C++: Avoid::Router::isInCrossingPenaltyReroutingStage() const --> bool");
		cl.def("markAllObstaclesAsMoved", (void (Avoid::Router::*)()) &Avoid::Router::markAllObstaclesAsMoved, "C++: Avoid::Router::markAllObstaclesAsMoved() --> void");
		cl.def("shapeContainingPoint", (class Avoid::ShapeRef * (Avoid::Router::*)(const class Avoid::Point &)) &Avoid::Router::shapeContainingPoint, "C++: Avoid::Router::shapeContainingPoint(const class Avoid::Point &) --> class Avoid::ShapeRef *", pybind11::return_value_policy::automatic, pybind11::arg("point"));
		cl.def("performContinuationCheck", (void (Avoid::Router::*)(unsigned int, unsigned long, unsigned long)) &Avoid::Router::performContinuationCheck, "C++: Avoid::Router::performContinuationCheck(unsigned int, unsigned long, unsigned long) --> void", pybind11::arg("phaseNumber"), pybind11::arg("stepNumber"), pybind11::arg("totalSteps"));
		cl.def("registerSettingsChange", (void (Avoid::Router::*)()) &Avoid::Router::registerSettingsChange, "C++: Avoid::Router::registerSettingsChange() --> void");
		cl.def("setTopologyAddon", (void (Avoid::Router::*)(class Avoid::TopologyAddonInterface *)) &Avoid::Router::setTopologyAddon, "Set an addon for doing orthogonal topology improvement.\n\n  It is expected that you would use the topology::AvoidTopologyAddon() \n  from libtopology rather than write your own.  This is done so that \n  libavoid does not have to depend on libtopology.\n\nC++: Avoid::Router::setTopologyAddon(class Avoid::TopologyAddonInterface *) --> void", pybind11::arg("topologyAddon"));
		cl.def("improveOrthogonalTopology", (void (Avoid::Router::*)()) &Avoid::Router::improveOrthogonalTopology, "C++: Avoid::Router::improveOrthogonalTopology() --> void");
		cl.def("existsOrthogonalSegmentOverlap", [](Avoid::Router &o) -> bool { return o.existsOrthogonalSegmentOverlap(); }, "");
		cl.def("existsOrthogonalSegmentOverlap", (bool (Avoid::Router::*)(const bool)) &Avoid::Router::existsOrthogonalSegmentOverlap, "C++: Avoid::Router::existsOrthogonalSegmentOverlap(const bool) --> bool", pybind11::arg("atEnds"));
		cl.def("existsOrthogonalFixedSegmentOverlap", [](Avoid::Router &o) -> bool { return o.existsOrthogonalFixedSegmentOverlap(); }, "");
		cl.def("existsOrthogonalFixedSegmentOverlap", (bool (Avoid::Router::*)(const bool)) &Avoid::Router::existsOrthogonalFixedSegmentOverlap, "C++: Avoid::Router::existsOrthogonalFixedSegmentOverlap(const bool) --> bool", pybind11::arg("atEnds"));
		cl.def("existsOrthogonalTouchingPaths", (bool (Avoid::Router::*)()) &Avoid::Router::existsOrthogonalTouchingPaths, "C++: Avoid::Router::existsOrthogonalTouchingPaths() --> bool");
		cl.def("existsCrossings", [](Avoid::Router &o) -> int { return o.existsCrossings(); }, "");
		cl.def("existsCrossings", (int (Avoid::Router::*)(const bool)) &Avoid::Router::existsCrossings, "C++: Avoid::Router::existsCrossings(const bool) --> int", pybind11::arg("optimisedForConnectorType"));
		cl.def("existsInvalidOrthogonalPaths", (bool (Avoid::Router::*)()) &Avoid::Router::existsInvalidOrthogonalPaths, "C++: Avoid::Router::existsInvalidOrthogonalPaths() --> bool");
		cl.def("outputDiagramText", [](Avoid::Router &o) -> void { return o.outputDiagramText(); }, "");
		cl.def("outputDiagramText", (void (Avoid::Router::*)(std::string)) &Avoid::Router::outputDiagramText, "C++: Avoid::Router::outputDiagramText(std::string) --> void", pybind11::arg("instanceName"));
		cl.def("outputDiagram", [](Avoid::Router &o) -> void { return o.outputDiagram(); }, "");
		cl.def("outputDiagram", (void (Avoid::Router::*)(std::string)) &Avoid::Router::outputDiagram, "C++: Avoid::Router::outputDiagram(std::string) --> void", pybind11::arg("instanceName"));
		cl.def("assign", (class Avoid::Router & (Avoid::Router::*)(const class Avoid::Router &)) &Avoid::Router::operator=, "C++: Avoid::Router::operator=(const class Avoid::Router &) --> class Avoid::Router &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
