#include <_stdio.h>
#include <functional>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/debughandler.h>
#include <libavoid/geomtypes.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedge.h>
#include <libavoid/hyperedgetree.h>
#include <libavoid/junction.h>
#include <libavoid/obstacle.h>
#include <libavoid/router.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <libavoid/viscluster.h>
#include <libavoid/visibility.h>
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

// Avoid::JunctionRef file:libavoid/junction.h line:57
struct PyCallBack_Avoid_JunctionRef : public Avoid::JunctionRef {
	using Avoid::JunctionRef::JunctionRef;

	class Avoid::Point position() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::JunctionRef *>(this), "position");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Avoid::Point>::value) {
				static pybind11::detail::override_caster_t<class Avoid::Point> caster;
				return pybind11::detail::cast_ref<class Avoid::Point>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Avoid::Point>(std::move(o));
		}
		return JunctionRef::position();
	}
};

// Avoid::ShapeRef file:libavoid/shape.h line:81
struct PyCallBack_Avoid_ShapeRef : public Avoid::ShapeRef {
	using Avoid::ShapeRef::ShapeRef;

	class Avoid::Point position() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::ShapeRef *>(this), "position");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Avoid::Point>::value) {
				static pybind11::detail::override_caster_t<class Avoid::Point> caster;
				return pybind11::detail::cast_ref<class Avoid::Point>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Avoid::Point>(std::move(o));
		}
		return ShapeRef::position();
	}
};

void bind_libavoid_hyperedgetree(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::CmpNodesInDim file:libavoid/hyperedgetree.h line:131
		pybind11::class_<Avoid::CmpNodesInDim, std::shared_ptr<Avoid::CmpNodesInDim>> cl(M("Avoid"), "CmpNodesInDim", "");
		cl.def( pybind11::init<const unsigned long>(), pybind11::arg("dim") );

		cl.def("__call__", (bool (Avoid::CmpNodesInDim::*)(const struct Avoid::HyperedgeTreeNode *, const struct Avoid::HyperedgeTreeNode *) const) &Avoid::CmpNodesInDim::operator(), "C++: Avoid::CmpNodesInDim::operator()(const struct Avoid::HyperedgeTreeNode *, const struct Avoid::HyperedgeTreeNode *) const --> bool", pybind11::arg("lhs"), pybind11::arg("rhs"));
	}
	{ // Avoid::Obstacle file:libavoid/obstacle.h line:56
		pybind11::class_<Avoid::Obstacle, std::shared_ptr<Avoid::Obstacle>> cl(M("Avoid"), "Obstacle", "");
		cl.def("id", (unsigned int (Avoid::Obstacle::*)() const) &Avoid::Obstacle::id, "Returns the ID of this obstacle.\n \n\n The ID of the obstacle.\n\nC++: Avoid::Obstacle::id() const --> unsigned int");
		cl.def("polygon", (const class Avoid::Polygon & (Avoid::Obstacle::*)() const) &Avoid::Obstacle::polygon, "Returns a reference to the polygon boundary of this\n          obstacle.\n \n\n A reference to the polygon boundary of the obstacle.\n\nC++: Avoid::Obstacle::polygon() const --> const class Avoid::Polygon &", pybind11::return_value_policy::automatic);
		cl.def("router", (class Avoid::Router * (Avoid::Obstacle::*)() const) &Avoid::Obstacle::router, "Returns a pointer to the router scene this obstacle\n          is in.\n \n\n A pointer to the router scene for this obstacle.\n\nC++: Avoid::Obstacle::router() const --> class Avoid::Router *", pybind11::return_value_policy::automatic);
		cl.def("position", (class Avoid::Point (Avoid::Obstacle::*)() const) &Avoid::Obstacle::position, "Returns the position of this obstacle.\n \n\n A point representing the position of this obstacle.\n\nC++: Avoid::Obstacle::position() const --> class Avoid::Point");
		cl.def("setNewPoly", (void (Avoid::Obstacle::*)(const class Avoid::Polygon &)) &Avoid::Obstacle::setNewPoly, "C++: Avoid::Obstacle::setNewPoly(const class Avoid::Polygon &) --> void", pybind11::arg("poly"));
		cl.def("firstVert", (class Avoid::VertInf * (Avoid::Obstacle::*)()) &Avoid::Obstacle::firstVert, "C++: Avoid::Obstacle::firstVert() --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("lastVert", (class Avoid::VertInf * (Avoid::Obstacle::*)()) &Avoid::Obstacle::lastVert, "C++: Avoid::Obstacle::lastVert() --> class Avoid::VertInf *", pybind11::return_value_policy::automatic);
		cl.def("routingBox", (class Avoid::Box (Avoid::Obstacle::*)() const) &Avoid::Obstacle::routingBox, "C++: Avoid::Obstacle::routingBox() const --> class Avoid::Box");
		cl.def("routingPolygon", (class Avoid::Polygon (Avoid::Obstacle::*)() const) &Avoid::Obstacle::routingPolygon, "C++: Avoid::Obstacle::routingPolygon() const --> class Avoid::Polygon");
		cl.def("attachedConnectors", (class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > (Avoid::Obstacle::*)() const) &Avoid::Obstacle::attachedConnectors, "C++: Avoid::Obstacle::attachedConnectors() const --> class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> >");
		cl.def("assign", (class Avoid::Obstacle & (Avoid::Obstacle::*)(const class Avoid::Obstacle &)) &Avoid::Obstacle::operator=, "C++: Avoid::Obstacle::operator=(const class Avoid::Obstacle &) --> class Avoid::Obstacle &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::JunctionRef file:libavoid/junction.h line:57
		pybind11::class_<Avoid::JunctionRef, std::shared_ptr<Avoid::JunctionRef>, PyCallBack_Avoid_JunctionRef, Avoid::Obstacle> cl(M("Avoid"), "JunctionRef", "The JunctionRef class represents a fixed or free-floating point that \n         connectors can be attached to.  \n\n A JunctionRef represents a junction between multiple connectors, or could\n be used to specify an intermediate point that a single connector must route\n through.");
		cl.def( pybind11::init( [](class Avoid::Router * a0, class Avoid::Point const & a1){ return new Avoid::JunctionRef(a0, a1); }, [](class Avoid::Router * a0, class Avoid::Point const & a1){ return new PyCallBack_Avoid_JunctionRef(a0, a1); } ), "doc");
		cl.def( pybind11::init<class Avoid::Router *, class Avoid::Point, const unsigned int>(), pybind11::arg("router"), pybind11::arg("position"), pybind11::arg("id") );

		cl.def( pybind11::init( [](PyCallBack_Avoid_JunctionRef const &o){ return new PyCallBack_Avoid_JunctionRef(o); } ) );
		cl.def( pybind11::init( [](Avoid::JunctionRef const &o){ return new Avoid::JunctionRef(o); } ) );
		cl.def("removeJunctionAndMergeConnectors", (class Avoid::ConnRef * (Avoid::JunctionRef::*)()) &Avoid::JunctionRef::removeJunctionAndMergeConnectors, "Removes a junction that has only two connectors attached\n         to it and merges them into a single connector.\n\n The junction and one of the connectors will be removed from the\n router scene and the connector deleted.  A pointer to the \n remaining (merged) connector will be returned by this method.\n\n Currently this method does not delete and free the Junction itself.\n The user needs to do this after the transaction has been \n processed by the router.\n\n If there are more than two connectors attached to the junction\n then nothing will be changed and this method will return nullptr.\n\n \n  The merged connector, or nullptr if the junction was not\n          removed.\n\nC++: Avoid::JunctionRef::removeJunctionAndMergeConnectors() --> class Avoid::ConnRef *", pybind11::return_value_policy::automatic);
		cl.def("position", (class Avoid::Point (Avoid::JunctionRef::*)() const) &Avoid::JunctionRef::position, "Returns the position of this junction.\n \n\n A point representing the position of this junction.\n\nC++: Avoid::JunctionRef::position() const --> class Avoid::Point");
		cl.def("setPositionFixed", (void (Avoid::JunctionRef::*)(bool)) &Avoid::JunctionRef::setPositionFixed, "Sets whether the junction has a fixed position and\n         therefore can't be moved by the Router during routing.\n\n This property is ignored for hyperedge improvement if the option\n improveHyperedgeRoutesMovingAddingAndDeletingJunctions is set and\n when it would lead to confusing hyperedge topology, such as two\n overlapping junctions with a zero length connector between them\n or an unnecessary junction bridging two connectors.\n\n \n  Boolean indicating whether the junction position\n                    should be marked as fixed.\n\nC++: Avoid::JunctionRef::setPositionFixed(bool) --> void", pybind11::arg("fixed"));
		cl.def("positionFixed", (bool (Avoid::JunctionRef::*)() const) &Avoid::JunctionRef::positionFixed, "Returns whether this junction has a fixed position (that \n          can't be moved by the Router during routing).\n \n\n A point representing the position of this junction.\n\nC++: Avoid::JunctionRef::positionFixed() const --> bool");
		cl.def("recommendedPosition", (class Avoid::Point (Avoid::JunctionRef::*)() const) &Avoid::JunctionRef::recommendedPosition, "Returns a recommended position for the junction based on\n          improving hyperedge routes. This value will be set during\n          routing when the improveHyperedgeRoutesMovingJunctions\n          router option is set (the default).\n \n\n A point indicating the ideal position for this junction.\n\nC++: Avoid::JunctionRef::recommendedPosition() const --> class Avoid::Point");
		cl.def("makeRectangle", (class Avoid::Rectangle (Avoid::JunctionRef::*)(class Avoid::Router *, const class Avoid::Point &)) &Avoid::JunctionRef::makeRectangle, "C++: Avoid::JunctionRef::makeRectangle(class Avoid::Router *, const class Avoid::Point &) --> class Avoid::Rectangle", pybind11::arg("router"), pybind11::arg("position"));
		cl.def("preferOrthogonalDimension", (void (Avoid::JunctionRef::*)(const unsigned long)) &Avoid::JunctionRef::preferOrthogonalDimension, "C++: Avoid::JunctionRef::preferOrthogonalDimension(const unsigned long) --> void", pybind11::arg("dim"));
		cl.def("assign", (class Avoid::JunctionRef & (Avoid::JunctionRef::*)(const class Avoid::JunctionRef &)) &Avoid::JunctionRef::operator=, "C++: Avoid::JunctionRef::operator=(const class Avoid::JunctionRef &) --> class Avoid::JunctionRef &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// Avoid::ShapeTransformationType file:libavoid/shape.h line:57
	pybind11::enum_<Avoid::ShapeTransformationType>(M("Avoid"), "ShapeTransformationType", pybind11::arithmetic(), "Describes the type of transformation that has been applied to a\n         shape having its transformConnectionPinPositions() method called.")
		.value("TransformationType_CW90", Avoid::TransformationType_CW90)
		.value("TransformationType_CW180", Avoid::TransformationType_CW180)
		.value("TransformationType_CW270", Avoid::TransformationType_CW270)
		.value("TransformationType_FlipX", Avoid::TransformationType_FlipX)
		.value("TransformationType_FlipY", Avoid::TransformationType_FlipY)
		.export_values();

;

	{ // Avoid::ShapeRef file:libavoid/shape.h line:81
		pybind11::class_<Avoid::ShapeRef, std::shared_ptr<Avoid::ShapeRef>, PyCallBack_Avoid_ShapeRef, Avoid::Obstacle> cl(M("Avoid"), "ShapeRef", "The ShapeRef class represents a shape object.\n\n Shapes are obstacles that connectors must be routed around.  They can be \n placed into a Router scene and can be repositioned or resized (via\n Router::moveShape()).\n\n Usually, it is expected that you would create a ShapeRef for each shape \n in your diagram and keep that reference in your own shape class.");
		cl.def( pybind11::init( [](class Avoid::Router * a0, class Avoid::Polygon & a1){ return new Avoid::ShapeRef(a0, a1); }, [](class Avoid::Router * a0, class Avoid::Polygon & a1){ return new PyCallBack_Avoid_ShapeRef(a0, a1); } ), "doc");
		cl.def( pybind11::init<class Avoid::Router *, class Avoid::Polygon &, const unsigned int>(), pybind11::arg("router"), pybind11::arg("poly"), pybind11::arg("id") );

		cl.def( pybind11::init( [](PyCallBack_Avoid_ShapeRef const &o){ return new PyCallBack_Avoid_ShapeRef(o); } ) );
		cl.def( pybind11::init( [](Avoid::ShapeRef const &o){ return new Avoid::ShapeRef(o); } ) );
		cl.def("polygon", (const class Avoid::Polygon & (Avoid::ShapeRef::*)() const) &Avoid::ShapeRef::polygon, "Returns a reference to the polygon boundary of this shape.\n \n\n A reference to the polygon boundary of the shape.\n\nC++: Avoid::ShapeRef::polygon() const --> const class Avoid::Polygon &", pybind11::return_value_policy::automatic);
		cl.def("transformConnectionPinPositions", (void (Avoid::ShapeRef::*)(enum Avoid::ShapeTransformationType)) &Avoid::ShapeRef::transformConnectionPinPositions, "Adjusts all of the shape's connection pin positions and \n         visibility directions for a given transformation type.\n\n \n  A ShapeTransformationType specifying the \n                        type of transform to be applied to all \n                        connection pins for the shape.\n\nC++: Avoid::ShapeRef::transformConnectionPinPositions(enum Avoid::ShapeTransformationType) --> void", pybind11::arg("transform"));
		cl.def("position", (class Avoid::Point (Avoid::ShapeRef::*)() const) &Avoid::ShapeRef::position, "C++: Avoid::ShapeRef::position() const --> class Avoid::Point");
		cl.def("assign", (class Avoid::ShapeRef & (Avoid::ShapeRef::*)(const class Avoid::ShapeRef &)) &Avoid::ShapeRef::operator=, "C++: Avoid::ShapeRef::operator=(const class Avoid::ShapeRef &) --> class Avoid::ShapeRef &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// Avoid::vertexVisibility(class Avoid::VertInf *, class Avoid::VertInf *, bool, const bool) file:libavoid/visibility.h line:34
	M("Avoid").def("vertexVisibility", [](class Avoid::VertInf * a0, class Avoid::VertInf * a1, bool const & a2) -> void { return Avoid::vertexVisibility(a0, a1, a2); }, "", pybind11::arg("point"), pybind11::arg("partner"), pybind11::arg("knownNew"));
	M("Avoid").def("vertexVisibility", (void (*)(class Avoid::VertInf *, class Avoid::VertInf *, bool, const bool)) &Avoid::vertexVisibility, "C++: Avoid::vertexVisibility(class Avoid::VertInf *, class Avoid::VertInf *, bool, const bool) --> void", pybind11::arg("point"), pybind11::arg("partner"), pybind11::arg("knownNew"), pybind11::arg("gen_contains"));

	{ // Avoid::LineRep file:libavoid/router.h line:50
		pybind11::class_<Avoid::LineRep, std::shared_ptr<Avoid::LineRep>> cl(M("Avoid"), "LineRep", "");
		cl.def( pybind11::init( [](){ return new Avoid::LineRep(); } ) );
		cl.def_readwrite("begin", &Avoid::LineRep::begin);
		cl.def_readwrite("end", &Avoid::LineRep::end);
	}
	// Avoid::RouterFlag file:libavoid/router.h line:70
	pybind11::enum_<Avoid::RouterFlag>(M("Avoid"), "RouterFlag", pybind11::arithmetic(), "Flags that can be passed to the router during initialisation \n         to specify options.")
		.value("PolyLineRouting", Avoid::PolyLineRouting)
		.value("OrthogonalRouting", Avoid::OrthogonalRouting)
		.export_values();

;

	// Avoid::RoutingParameter file:libavoid/router.h line:88
	pybind11::enum_<Avoid::RoutingParameter>(M("Avoid"), "RoutingParameter", pybind11::arithmetic(), "Types of routing parameters and penalties that can be used to \n         tailor the style and improve the quality of the connector \n         routes produced.")
		.value("segmentPenalty", Avoid::segmentPenalty)
		.value("anglePenalty", Avoid::anglePenalty)
		.value("crossingPenalty", Avoid::crossingPenalty)
		.value("clusterCrossingPenalty", Avoid::clusterCrossingPenalty)
		.value("fixedSharedPathPenalty", Avoid::fixedSharedPathPenalty)
		.value("portDirectionPenalty", Avoid::portDirectionPenalty)
		.value("shapeBufferDistance", Avoid::shapeBufferDistance)
		.value("idealNudgingDistance", Avoid::idealNudgingDistance)
		.value("reverseDirectionPenalty", Avoid::reverseDirectionPenalty)
		.value("lastRoutingParameterMarker", Avoid::lastRoutingParameterMarker)
		.export_values();

;

	// Avoid::RoutingOption file:libavoid/router.h line:174
	pybind11::enum_<Avoid::RoutingOption>(M("Avoid"), "RoutingOption", pybind11::arithmetic(), "Types of routing options that can be enabled.")
		.value("nudgeOrthogonalSegmentsConnectedToShapes", Avoid::nudgeOrthogonalSegmentsConnectedToShapes)
		.value("improveHyperedgeRoutesMovingJunctions", Avoid::improveHyperedgeRoutesMovingJunctions)
		.value("penaliseOrthogonalSharedPathsAtConnEnds", Avoid::penaliseOrthogonalSharedPathsAtConnEnds)
		.value("nudgeOrthogonalTouchingColinearSegments", Avoid::nudgeOrthogonalTouchingColinearSegments)
		.value("performUnifyingNudgingPreprocessingStep", Avoid::performUnifyingNudgingPreprocessingStep)
		.value("improveHyperedgeRoutesMovingAddingAndDeletingJunctions", Avoid::improveHyperedgeRoutesMovingAddingAndDeletingJunctions)
		.value("nudgeSharedPathsWithCommonEndPoint", Avoid::nudgeSharedPathsWithCommonEndPoint)
		.value("lastRoutingOptionMarker", Avoid::lastRoutingOptionMarker)
		.export_values();

;

	// Avoid::TransactionPhases file:libavoid/router.h line:299
	pybind11::enum_<Avoid::TransactionPhases>(M("Avoid"), "TransactionPhases", pybind11::arithmetic(), "Types of routing phases reported by \n         Router::shouldContinueTransactionWithProgress().\n\n This phases will occur in the order given here, but each phase may take\n varying amounts of time.")
		.value("TransactionPhaseOrthogonalVisibilityGraphScanX", Avoid::TransactionPhaseOrthogonalVisibilityGraphScanX)
		.value("TransactionPhaseOrthogonalVisibilityGraphScanY", Avoid::TransactionPhaseOrthogonalVisibilityGraphScanY)
		.value("TransactionPhaseRouteSearch", Avoid::TransactionPhaseRouteSearch)
		.value("TransactionPhaseCrossingDetection", Avoid::TransactionPhaseCrossingDetection)
		.value("TransactionPhaseRerouteSearch", Avoid::TransactionPhaseRerouteSearch)
		.value("TransactionPhaseOrthogonalNudgingX", Avoid::TransactionPhaseOrthogonalNudgingX)
		.value("TransactionPhaseOrthogonalNudgingY", Avoid::TransactionPhaseOrthogonalNudgingY)
		.value("TransactionPhaseCompleted", Avoid::TransactionPhaseCompleted)
		.export_values();

;

	{ // Avoid::ConnRerouteFlagDelegate file:libavoid/router.h line:332
		pybind11::class_<Avoid::ConnRerouteFlagDelegate, std::shared_ptr<Avoid::ConnRerouteFlagDelegate>> cl(M("Avoid"), "ConnRerouteFlagDelegate", "");
		cl.def( pybind11::init( [](){ return new Avoid::ConnRerouteFlagDelegate(); } ) );
		cl.def( pybind11::init( [](Avoid::ConnRerouteFlagDelegate const &o){ return new Avoid::ConnRerouteFlagDelegate(o); } ) );
		cl.def("addConn", (bool * (Avoid::ConnRerouteFlagDelegate::*)(class Avoid::ConnRef *)) &Avoid::ConnRerouteFlagDelegate::addConn, "C++: Avoid::ConnRerouteFlagDelegate::addConn(class Avoid::ConnRef *) --> bool *", pybind11::return_value_policy::automatic, pybind11::arg("conn"));
		cl.def("removeConn", (void (Avoid::ConnRerouteFlagDelegate::*)(class Avoid::ConnRef *)) &Avoid::ConnRerouteFlagDelegate::removeConn, "C++: Avoid::ConnRerouteFlagDelegate::removeConn(class Avoid::ConnRef *) --> void", pybind11::arg("conn"));
		cl.def("alertConns", (void (Avoid::ConnRerouteFlagDelegate::*)()) &Avoid::ConnRerouteFlagDelegate::alertConns, "C++: Avoid::ConnRerouteFlagDelegate::alertConns() --> void");
		cl.def("assign", (class Avoid::ConnRerouteFlagDelegate & (Avoid::ConnRerouteFlagDelegate::*)(const class Avoid::ConnRerouteFlagDelegate &)) &Avoid::ConnRerouteFlagDelegate::operator=, "C++: Avoid::ConnRerouteFlagDelegate::operator=(const class Avoid::ConnRerouteFlagDelegate &) --> class Avoid::ConnRerouteFlagDelegate &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
