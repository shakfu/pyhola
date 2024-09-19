#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/debughandler.h>
#include <libavoid/geomtypes.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedge.h>
#include <libavoid/hyperedgeimprover.h>
#include <libavoid/hyperedgetree.h>
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

void bind_libavoid_hyperedgeimprover(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::HyperedgeImprover file:libavoid/hyperedgeimprover.h line:51
		pybind11::class_<Avoid::HyperedgeImprover, std::shared_ptr<Avoid::HyperedgeImprover>> cl(M("Avoid"), "HyperedgeImprover", "");
		cl.def( pybind11::init( [](){ return new Avoid::HyperedgeImprover(); } ) );
		cl.def( pybind11::init( [](Avoid::HyperedgeImprover const &o){ return new Avoid::HyperedgeImprover(o); } ) );
		cl.def("clear", (void (Avoid::HyperedgeImprover::*)()) &Avoid::HyperedgeImprover::clear, "C++: Avoid::HyperedgeImprover::clear() --> void");
		cl.def("setRouter", (void (Avoid::HyperedgeImprover::*)(class Avoid::Router *)) &Avoid::HyperedgeImprover::setRouter, "C++: Avoid::HyperedgeImprover::setRouter(class Avoid::Router *) --> void", pybind11::arg("router"));
		cl.def("newAndDeletedObjectLists", (struct Avoid::HyperedgeNewAndDeletedObjectLists (Avoid::HyperedgeImprover::*)() const) &Avoid::HyperedgeImprover::newAndDeletedObjectLists, "C++: Avoid::HyperedgeImprover::newAndDeletedObjectLists() const --> struct Avoid::HyperedgeNewAndDeletedObjectLists");
		cl.def("execute", (void (Avoid::HyperedgeImprover::*)(bool)) &Avoid::HyperedgeImprover::execute, "C++: Avoid::HyperedgeImprover::execute(bool) --> void", pybind11::arg("canMakeMajorChanges"));
		cl.def("assign", (class Avoid::HyperedgeImprover & (Avoid::HyperedgeImprover::*)(const class Avoid::HyperedgeImprover &)) &Avoid::HyperedgeImprover::operator=, "C++: Avoid::HyperedgeImprover::operator=(const class Avoid::HyperedgeImprover &) --> class Avoid::HyperedgeImprover &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::HyperedgeTreeNode file:libavoid/hyperedgetree.h line:64
		pybind11::class_<Avoid::HyperedgeTreeNode, std::shared_ptr<Avoid::HyperedgeTreeNode>> cl(M("Avoid"), "HyperedgeTreeNode", "");
		cl.def( pybind11::init( [](){ return new Avoid::HyperedgeTreeNode(); } ) );
		cl.def( pybind11::init( [](Avoid::HyperedgeTreeNode const &o){ return new Avoid::HyperedgeTreeNode(o); } ) );
		cl.def_readwrite("edges", &Avoid::HyperedgeTreeNode::edges);
		cl.def_readwrite("point", &Avoid::HyperedgeTreeNode::point);
		cl.def_readwrite("isConnectorSource", &Avoid::HyperedgeTreeNode::isConnectorSource);
		cl.def_readwrite("isPinDummyEndpoint", &Avoid::HyperedgeTreeNode::isPinDummyEndpoint);
		cl.def_readwrite("visited", &Avoid::HyperedgeTreeNode::visited);
		cl.def("deleteEdgesExcept", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *)) &Avoid::HyperedgeTreeNode::deleteEdgesExcept, "C++: Avoid::HyperedgeTreeNode::deleteEdgesExcept(struct Avoid::HyperedgeTreeEdge *) --> void", pybind11::arg("ignored"));
		cl.def("outputEdgesExcept", (void (Avoid::HyperedgeTreeNode::*)(struct __sFILE *, struct Avoid::HyperedgeTreeEdge *)) &Avoid::HyperedgeTreeNode::outputEdgesExcept, "C++: Avoid::HyperedgeTreeNode::outputEdgesExcept(struct __sFILE *, struct Avoid::HyperedgeTreeEdge *) --> void", pybind11::arg("fp"), pybind11::arg("ignored"));
		cl.def("disconnectEdge", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *)) &Avoid::HyperedgeTreeNode::disconnectEdge, "C++: Avoid::HyperedgeTreeNode::disconnectEdge(struct Avoid::HyperedgeTreeEdge *) --> void", pybind11::arg("edge"));
		cl.def("spliceEdgesFrom", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeNode::spliceEdgesFrom, "C++: Avoid::HyperedgeTreeNode::spliceEdgesFrom(struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("oldNode"));
		cl.def("writeEdgesToConns", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *, unsigned long)) &Avoid::HyperedgeTreeNode::writeEdgesToConns, "C++: Avoid::HyperedgeTreeNode::writeEdgesToConns(struct Avoid::HyperedgeTreeEdge *, unsigned long) --> void", pybind11::arg("ignored"), pybind11::arg("pass"));
		cl.def("isImmovable", (bool (Avoid::HyperedgeTreeNode::*)() const) &Avoid::HyperedgeTreeNode::isImmovable, "C++: Avoid::HyperedgeTreeNode::isImmovable() const --> bool");
		cl.def("validateHyperedge", (void (Avoid::HyperedgeTreeNode::*)(const struct Avoid::HyperedgeTreeEdge *, const unsigned long) const) &Avoid::HyperedgeTreeNode::validateHyperedge, "C++: Avoid::HyperedgeTreeNode::validateHyperedge(const struct Avoid::HyperedgeTreeEdge *, const unsigned long) const --> void", pybind11::arg("ignored"), pybind11::arg("dist"));
	}
	{ // Avoid::HyperedgeTreeEdge file:libavoid/hyperedgetree.h line:96
		pybind11::class_<Avoid::HyperedgeTreeEdge, std::shared_ptr<Avoid::HyperedgeTreeEdge>> cl(M("Avoid"), "HyperedgeTreeEdge", "");
		cl.def( pybind11::init<struct Avoid::HyperedgeTreeNode *, struct Avoid::HyperedgeTreeNode *, class Avoid::ConnRef *>(), pybind11::arg("node1"), pybind11::arg("node2"), pybind11::arg("conn") );

		cl.def( pybind11::init( [](Avoid::HyperedgeTreeEdge const &o){ return new Avoid::HyperedgeTreeEdge(o); } ) );
		cl.def_readwrite("ends", &Avoid::HyperedgeTreeEdge::ends);
		cl.def_readwrite("hasFixedRoute", &Avoid::HyperedgeTreeEdge::hasFixedRoute);
		cl.def("followFrom", (struct Avoid::HyperedgeTreeNode * (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *) const) &Avoid::HyperedgeTreeEdge::followFrom, "C++: Avoid::HyperedgeTreeEdge::followFrom(struct Avoid::HyperedgeTreeNode *) const --> struct Avoid::HyperedgeTreeNode *", pybind11::return_value_policy::automatic, pybind11::arg("from"));
		cl.def("zeroLength", (bool (Avoid::HyperedgeTreeEdge::*)() const) &Avoid::HyperedgeTreeEdge::zeroLength, "C++: Avoid::HyperedgeTreeEdge::zeroLength() const --> bool");
		cl.def("splitFromNodeAtPoint", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, const class Avoid::Point &)) &Avoid::HyperedgeTreeEdge::splitFromNodeAtPoint, "C++: Avoid::HyperedgeTreeEdge::splitFromNodeAtPoint(struct Avoid::HyperedgeTreeNode *, const class Avoid::Point &) --> void", pybind11::arg("source"), pybind11::arg("point"));
		cl.def("hasOrientation", (bool (Avoid::HyperedgeTreeEdge::*)(const unsigned long) const) &Avoid::HyperedgeTreeEdge::hasOrientation, "C++: Avoid::HyperedgeTreeEdge::hasOrientation(const unsigned long) const --> bool", pybind11::arg("dimension"));
		cl.def("outputNodesExcept", (void (Avoid::HyperedgeTreeEdge::*)(struct __sFILE *, struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeEdge::outputNodesExcept, "C++: Avoid::HyperedgeTreeEdge::outputNodesExcept(struct __sFILE *, struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("file"), pybind11::arg("ignored"));
		cl.def("deleteNodesExcept", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeEdge::deleteNodesExcept, "C++: Avoid::HyperedgeTreeEdge::deleteNodesExcept(struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("ignored"));
		cl.def("writeEdgesToConns", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, unsigned long)) &Avoid::HyperedgeTreeEdge::writeEdgesToConns, "C++: Avoid::HyperedgeTreeEdge::writeEdgesToConns(struct Avoid::HyperedgeTreeNode *, unsigned long) --> void", pybind11::arg("ignored"), pybind11::arg("pass"));
		cl.def("disconnectEdge", (void (Avoid::HyperedgeTreeEdge::*)()) &Avoid::HyperedgeTreeEdge::disconnectEdge, "C++: Avoid::HyperedgeTreeEdge::disconnectEdge() --> void");
		cl.def("replaceNode", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeEdge::replaceNode, "C++: Avoid::HyperedgeTreeEdge::replaceNode(struct Avoid::HyperedgeTreeNode *, struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("oldNode"), pybind11::arg("newNode"));
		cl.def("validateHyperedge", (void (Avoid::HyperedgeTreeEdge::*)(const struct Avoid::HyperedgeTreeNode *, const unsigned long) const) &Avoid::HyperedgeTreeEdge::validateHyperedge, "C++: Avoid::HyperedgeTreeEdge::validateHyperedge(const struct Avoid::HyperedgeTreeNode *, const unsigned long) const --> void", pybind11::arg("ignored"), pybind11::arg("dist"));
	}
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

}
