#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/connend.h>
#include <libavoid/geomtypes.h>
#include <libavoid/router.h>
#include <libcola/cluster.h>
#include <libdialect/aca.h>
#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
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

// dialect::Node file:libdialect/graphs.h line:713
struct PyCallBack_dialect_Node : public dialect::Node {
	using dialect::Node::Node;

	unsigned int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::Node *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		return Node::id();
	}
};

// dialect::GhostNode file:libdialect/graphs.h line:939
struct PyCallBack_dialect_GhostNode : public dialect::GhostNode {
	using dialect::GhostNode::GhostNode;

	unsigned int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::GhostNode *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		return GhostNode::id();
	}
};

void bind_libdialect_graphs(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::swap(class dialect::Graph &, class dialect::Graph &) file:libdialect/graphs.h line:192
	// M("dialect").def("swap", (void (*)(class dialect::Graph &, class dialect::Graph &)) &dialect::swap, "Swap operator.\n\nC++: dialect::swap(class dialect::Graph &, class dialect::Graph &) --> void", pybind11::arg("first"), pybind11::arg("second"));

	{ // dialect::Node file:libdialect/graphs.h line:713
		pybind11::class_<dialect::Node, std::shared_ptr<dialect::Node>, PyCallBack_dialect_Node> cl(M("dialect"), "Node", "The Node class represents nodes in a graph.");
		cl.def("id", (unsigned int (dialect::Node::*)() const) &dialect::Node::id, "Access the unique ID of a given instance.\n\n \n  The ID.\n\nC++: dialect::Node::id() const --> unsigned int");
		cl.def("getDegree", (unsigned int (dialect::Node::*)() const) &dialect::Node::getDegree, "Check the degree (number of incident Edges) of the Node.\n\n \n  The degree of the Node\n\nC++: dialect::Node::getDegree() const --> unsigned int");
		cl.def("setGraph", (void (dialect::Node::*)(class dialect::Graph &)) &dialect::Node::setGraph, "Tell the Node which Graph it belongs to.\n\n \n  The Graph to which the Node is to belong.\n\nC++: dialect::Node::setGraph(class dialect::Graph &) --> void", pybind11::arg("graph"));
		cl.def("getGraph", (class dialect::Graph * (dialect::Node::*)()) &dialect::Node::getGraph, "Access the Graph to which the Node belongs.\n\nC++: dialect::Node::getGraph() --> class dialect::Graph *", pybind11::return_value_policy::automatic);
		cl.def("removeEdge", (void (dialect::Node::*)(const class dialect::Edge &)) &dialect::Node::removeEdge, "Remove an incident Edge.\n\nC++: dialect::Node::removeEdge(const class dialect::Edge &) --> void", pybind11::arg("edge"));
		cl.def("copyGeometry", (void (dialect::Node::*)(const class dialect::Node &)) &dialect::Node::copyGeometry, "Give this Node the same coordinates and dimensions as another.\n\nC++: dialect::Node::copyGeometry(const class dialect::Node &) --> void", pybind11::arg("other"));
		cl.def("copyOtherGhostProperties", (void (dialect::Node::*)(const class dialect::Node &)) &dialect::Node::copyOtherGhostProperties, "Besides copying geometry, there may be other properties we wish\n         to copy; in particular, properties that are suitable to be copied\n         by a GhostNode.\n\nC++: dialect::Node::copyOtherGhostProperties(const class dialect::Node &) --> void", pybind11::arg("other"));
		cl.def("getBoundingBox", (struct dialect::BoundingBox (dialect::Node::*)() const) &dialect::Node::getBoundingBox, "Get the bounding box for this Node.\n\nC++: dialect::Node::getBoundingBox() const --> struct dialect::BoundingBox");
		cl.def("getBoundaryCompassPt", (class Avoid::Point (dialect::Node::*)(enum dialect::CompassDir) const) &dialect::Node::getBoundaryCompassPt, "Get the point on the boundary of this Node in a given direction\n         from its centre.\n\nC++: dialect::Node::getBoundaryCompassPt(enum dialect::CompassDir) const --> class Avoid::Point", pybind11::arg("dir"));
		cl.def("setCentre", (void (dialect::Node::*)(double, double)) &dialect::Node::setCentre, "Set the position of the node, by setting its centre coordinates.\n\nC++: dialect::Node::setCentre(double, double) --> void", pybind11::arg("cx"), pybind11::arg("cy"));
		cl.def("translate", (void (dialect::Node::*)(double, double)) &dialect::Node::translate, "Update the position of the node, by adding to its centre coordinates.\n\nC++: dialect::Node::translate(double, double) --> void", pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("getCentre", (class Avoid::Point (dialect::Node::*)() const) &dialect::Node::getCentre, "Get the centre coordinates of the node.\n\nC++: dialect::Node::getCentre() const --> class Avoid::Point");
		cl.def("setExternalId", (void (dialect::Node::*)(unsigned int)) &dialect::Node::setExternalId, "Set an externally-determined ID. (This is useful for TGLF and other\n         interfacing operations.)\n\nC++: dialect::Node::setExternalId(unsigned int) --> void", pybind11::arg("id"));
		cl.def("getExternalId", (int (dialect::Node::*)()) &dialect::Node::getExternalId, "Get the external ID.\n\nC++: dialect::Node::getExternalId() --> int");
		cl.def("setDims", (void (dialect::Node::*)(double, double)) &dialect::Node::setDims, "Set the dimensions of the node.\n\nC++: dialect::Node::setDims(double, double) --> void", pybind11::arg("w"), pybind11::arg("h"));
		cl.def("setBoundingBox", (void (dialect::Node::*)(double, double, double, double)) &dialect::Node::setBoundingBox, "Set the bounding box of the node. This sets both the dimensions and the centre point.\n \n\n  The minimum x-coord of the box.\n \n\n  The maximum x-coord of the box.\n \n\n  The minimum y-coord of the box.\n \n\n  The maximum y-coord of the box.\n\nC++: dialect::Node::setBoundingBox(double, double, double, double) --> void", pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y"));
		cl.def("addPadding", (void (dialect::Node::*)(double, double)) &dialect::Node::addPadding, "Add padding to the node's dimensions.\n \n\n  Amounts can be positive or negative, thus adding or subtracting padding.\n\nC++: dialect::Node::addPadding(double, double) --> void", pybind11::arg("dw"), pybind11::arg("dh"));
		cl.def("updatePosnFromRect", (void (dialect::Node::*)(class vpsc::Rectangle *)) &dialect::Node::updatePosnFromRect, "Update the position of this Node to equal that of the given Rectangle.\n\nC++: dialect::Node::updatePosnFromRect(class vpsc::Rectangle *) --> void", pybind11::arg("r"));
		cl.def("updateXCoordFromRect", (void (dialect::Node::*)(class vpsc::Rectangle *)) &dialect::Node::updateXCoordFromRect, "Update the x-coordinate of this Node to equal that of the given Rectangle.\n\nC++: dialect::Node::updateXCoordFromRect(class vpsc::Rectangle *) --> void", pybind11::arg("r"));
		cl.def("updateYCoordFromRect", (void (dialect::Node::*)(class vpsc::Rectangle *)) &dialect::Node::updateYCoordFromRect, "Update the y-coordinate of this Node to equal that of the given Rectangle.\n\nC++: dialect::Node::updateYCoordFromRect(class vpsc::Rectangle *) --> void", pybind11::arg("r"));
		cl.def("makeLibavoidPolygon", (class Avoid::Polygon (dialect::Node::*)() const) &dialect::Node::makeLibavoidPolygon, "Build and return a Polygon to represent this Node in libavoid.\n\nC++: dialect::Node::makeLibavoidPolygon() const --> class Avoid::Polygon");
		cl.def("isRoot", (bool (dialect::Node::*)() const) &dialect::Node::isRoot, "Check whether this Node has been marked as being a root. This is\n         useful when working with trees, and can be safely ignored when\n         working with other sorts of graphs.\n\nC++: dialect::Node::isRoot() const --> bool");
		cl.def("setIsRoot", (void (dialect::Node::*)(bool)) &dialect::Node::setIsRoot, "Say whether this Node is a root. This is useful when working with\n         trees, and can be safely ignored when working with other sorts of graphs.\n\nC++: dialect::Node::setIsRoot(bool) --> void", pybind11::arg("isRoot"));
		cl.def("liesOppositeSegment", [](dialect::Node &o, const struct dialect::LineSegment & a0) -> bool { return o.liesOppositeSegment(a0); }, "", pybind11::arg("seg"));
		cl.def("liesOppositeSegment", (bool (dialect::Node::*)(const struct dialect::LineSegment &, bool)) &dialect::Node::liesOppositeSegment, "Check whether this Node lies opposite a LineSegment, i.e. whether\n         the sides of the Node lying parallel to the segment intersect its\n         interval.\n \n\n  The LineSegment in question.\n \n\n  Boolean saying whether we should treat the interval\n                      in question as an open one (i.e. not including its\n                      endpoints). Defaults to false, so that the closed\n                      interval is considered by default.\n\nC++: dialect::Node::liesOppositeSegment(const struct dialect::LineSegment &, bool) --> bool", pybind11::arg("seg"), pybind11::arg("openInterval"));
	}
	{ // dialect::GhostNode file:libdialect/graphs.h line:939
		pybind11::class_<dialect::GhostNode, std::shared_ptr<dialect::GhostNode>, PyCallBack_dialect_GhostNode, dialect::Node> cl(M("dialect"), "GhostNode", "A GhostNode represents another Node.\n\n When working with techniques that involve decomposing a graph into parts,\n and then reassembling those parts, it is often useful to have a node in one\n part represent a node in another part. For example this can be a useful way\n to manage the nodes where the two parts intersect. The GhostNode class\n supports this by representing a given Node.");
		cl.def("id", (unsigned int (dialect::GhostNode::*)() const) &dialect::GhostNode::id, "Return an appropriate ID number.\n\n Whether the GhostNode's actual ID is returned, or that of the\n Node it represents, depends whether it is set to masquerade.\n\nC++: dialect::GhostNode::id() const --> unsigned int");
		cl.def("trueID", (unsigned int (dialect::GhostNode::*)() const) &dialect::GhostNode::trueID, "Simple way to get the true ID of this GhostNode, even\n         if it is currently set to masquerade as the Node it represents.\n\nC++: dialect::GhostNode::trueID() const --> unsigned int");
		cl.def("setMasquerade", (void (dialect::GhostNode::*)(bool)) &dialect::GhostNode::setMasquerade, "Say whether the GhostNode should masquerade as the original Node.\n\nC++: dialect::GhostNode::setMasquerade(bool) --> void", pybind11::arg("doMasquerade"));
	}
	{ // dialect::Edge file:libdialect/graphs.h line:1006
		pybind11::class_<dialect::Edge, std::shared_ptr<dialect::Edge>> cl(M("dialect"), "Edge", "The Edge class represents edges in a graph.");
		cl.def( pybind11::init( [](dialect::Edge const &o){ return new dialect::Edge(o); } ) );
		cl.def("id", (unsigned int (dialect::Edge::*)() const) &dialect::Edge::id, "Access the unique ID of this instance.\n\n \n  The ID.\n\nC++: dialect::Edge::id() const --> unsigned int");
		cl.def("setGraph", (void (dialect::Edge::*)(class dialect::Graph &)) &dialect::Edge::setGraph, "Tell the Edge which Graph it belongs to.\n\n \n  The Graph to which the Edge is to belong.\n\nC++: dialect::Edge::setGraph(class dialect::Graph &) --> void", pybind11::arg("graph"));
		cl.def("sever", (void (dialect::Edge::*)()) &dialect::Edge::sever, "\"Sever\" this Edge, i.e. remove it from the Nodes to which\n         it is attached.\n\nC++: dialect::Edge::sever() --> void");
		cl.def("getBoundingBox", (struct dialect::BoundingBox (dialect::Edge::*)() const) &dialect::Edge::getBoundingBox, "Get the bounding box for the edge,\n         including its end points and route points.\n\nC++: dialect::Edge::getBoundingBox() const --> struct dialect::BoundingBox");
		cl.def("addRoutePoint", (void (dialect::Edge::*)(double, double)) &dialect::Edge::addRoutePoint, "Add a point to the route.\n\nC++: dialect::Edge::addRoutePoint(double, double) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("hasBendNodes", (bool (dialect::Edge::*)()) &dialect::Edge::hasBendNodes, "Check whether this Edge has any bend nodes.\n\nC++: dialect::Edge::hasBendNodes() --> bool");
		cl.def("rotate90cw", (void (dialect::Edge::*)()) &dialect::Edge::rotate90cw, "Rotate the connector route 90 degrees clockwise.\n\nC++: dialect::Edge::rotate90cw() --> void");
		cl.def("rotate90acw", (void (dialect::Edge::*)()) &dialect::Edge::rotate90acw, "Rotate the connector route 90 degrees anticlockwise.\n\nC++: dialect::Edge::rotate90acw() --> void");
		cl.def("rotate180", (void (dialect::Edge::*)()) &dialect::Edge::rotate180, "Rotate the connector route 180 degrees.\n\nC++: dialect::Edge::rotate180() --> void");
		cl.def("translate", (void (dialect::Edge::*)(double, double)) &dialect::Edge::translate, "Translate the connector route by a given amount in each dimension.\n \n\n  The amount by which to translate in the x-dimension.\n \n\n  The amount by which to translate in the y-dimension.\n\nC++: dialect::Edge::translate(double, double) --> void", pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("clearRouteAndBends", (void (dialect::Edge::*)()) &dialect::Edge::clearRouteAndBends, "Clear the connector route and drop all bend nodes.\n\nC++: dialect::Edge::clearRouteAndBends() --> void");
		cl.def("buildRouteFromBends", (void (dialect::Edge::*)()) &dialect::Edge::buildRouteFromBends, "Build a connector route based on the bend nodes.\n\nC++: dialect::Edge::buildRouteFromBends() --> void");
	}
	// dialect::ACAFlag file:libdialect/aca.h line:43
	pybind11::enum_<dialect::ACAFlag>(M("dialect"), "ACAFlag", pybind11::arithmetic(), "")
		.value("ACAHORIZ", dialect::ACAHORIZ)
		.value("ACAVERT", dialect::ACAVERT)
		.value("ACADELIB", dialect::ACADELIB)
		.value("ACACONN", dialect::ACACONN)
		.export_values();

;

	// dialect::ACASepFlag file:libdialect/aca.h line:50
	pybind11::enum_<dialect::ACASepFlag>(M("dialect"), "ACASepFlag", pybind11::arithmetic(), "")
		.value("ACANOSEP", dialect::ACANOSEP)
		.value("ACANORTH", dialect::ACANORTH)
		.value("ACAEAST", dialect::ACAEAST)
		.value("ACASOUTH", dialect::ACASOUTH)
		.value("ACAWEST", dialect::ACAWEST)
		.value("ACANORTHEAST", dialect::ACANORTHEAST)
		.value("ACASOUTHEAST", dialect::ACASOUTHEAST)
		.value("ACANORTHWEST", dialect::ACANORTHWEST)
		.value("ACASOUTHWEST", dialect::ACASOUTHWEST)
		.value("ACANORTHSOUTH", dialect::ACANORTHSOUTH)
		.value("ACAEASTWEST", dialect::ACAEASTWEST)
		.value("ACANOTNORTH", dialect::ACANOTNORTH)
		.value("ACANOTEAST", dialect::ACANOTEAST)
		.value("ACANOTSOUTH", dialect::ACANOTSOUTH)
		.value("ACANOTWEST", dialect::ACANOTWEST)
		.value("ACAALLSEP", dialect::ACAALLSEP)
		.export_values();

;

	// dialect::negateSepFlag(enum dialect::ACASepFlag) file:libdialect/aca.h line:74
	M("dialect").def("negateSepFlag", (enum dialect::ACASepFlag (*)(enum dialect::ACASepFlag)) &dialect::negateSepFlag, "C++: dialect::negateSepFlag(enum dialect::ACASepFlag) --> enum dialect::ACASepFlag", pybind11::arg("sf"));

	// dialect::sepToAlignFlag(enum dialect::ACASepFlag) file:libdialect/aca.h line:75
	M("dialect").def("sepToAlignFlag", (enum dialect::ACAFlag (*)(enum dialect::ACASepFlag)) &dialect::sepToAlignFlag, "C++: dialect::sepToAlignFlag(enum dialect::ACASepFlag) --> enum dialect::ACAFlag", pybind11::arg("sf"));

	// dialect::perpAlignFlag(enum dialect::ACAFlag) file:libdialect/aca.h line:76
	M("dialect").def("perpAlignFlag", (enum dialect::ACAFlag (*)(enum dialect::ACAFlag)) &dialect::perpAlignFlag, "C++: dialect::perpAlignFlag(enum dialect::ACAFlag) --> enum dialect::ACAFlag", pybind11::arg("af"));

	// dialect::vectorToSepFlag(double, double) file:libdialect/aca.h line:77
	M("dialect").def("vectorToSepFlag", (enum dialect::ACASepFlag (*)(double, double)) &dialect::vectorToSepFlag, "C++: dialect::vectorToSepFlag(double, double) --> enum dialect::ACASepFlag", pybind11::arg("dx"), pybind11::arg("dy"));

	// dialect::propsedSepConflictsWithExistingPosition(enum dialect::ACASepFlag, enum dialect::ACASepFlag) file:libdialect/aca.h line:78
	M("dialect").def("propsedSepConflictsWithExistingPosition", (bool (*)(enum dialect::ACASepFlag, enum dialect::ACASepFlag)) &dialect::propsedSepConflictsWithExistingPosition, "C++: dialect::propsedSepConflictsWithExistingPosition(enum dialect::ACASepFlag, enum dialect::ACASepFlag) --> bool", pybind11::arg("pro"), pybind11::arg("ex"));

	{ // dialect::OrderedAlignment file:libdialect/aca.h line:80
		pybind11::class_<dialect::OrderedAlignment, std::shared_ptr<dialect::OrderedAlignment>> cl(M("dialect"), "OrderedAlignment", "");
		cl.def( pybind11::init( [](){ return new dialect::OrderedAlignment(); } ) );
		cl.def_readwrite("af", &dialect::OrderedAlignment::af);
		cl.def_readwrite("sf", &dialect::OrderedAlignment::sf);
		cl.def_readwrite("dim", &dialect::OrderedAlignment::dim);
		cl.def_readwrite("src", &dialect::OrderedAlignment::src);
		cl.def_readwrite("tgt", &dialect::OrderedAlignment::tgt);
		cl.def_readwrite("offsetSrc", &dialect::OrderedAlignment::offsetSrc);
		cl.def_readwrite("offsetTgt", &dialect::OrderedAlignment::offsetTgt);
		cl.def_readwrite("edgeIndex", &dialect::OrderedAlignment::edgeIndex);
		cl.def_readwrite("penalty", &dialect::OrderedAlignment::penalty);
	}
	// dialect::sortOrdAlignsByPenalty(const struct dialect::OrderedAlignment *, const struct dialect::OrderedAlignment *) file:libdialect/aca.h line:109
	M("dialect").def("sortOrdAlignsByPenalty", (bool (*)(const struct dialect::OrderedAlignment *, const struct dialect::OrderedAlignment *)) &dialect::sortOrdAlignsByPenalty, "C++: dialect::sortOrdAlignsByPenalty(const struct dialect::OrderedAlignment *, const struct dialect::OrderedAlignment *) --> bool", pybind11::arg("lhs"), pybind11::arg("rhs"));

}
