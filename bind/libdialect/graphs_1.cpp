#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
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

// dialect::Node file:libdialect/graphs.h line:737
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
	int getChildren() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::Node *>(this), "getChildren");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return Node::getChildren();
	}
};

// dialect::GhostNode file:libdialect/graphs.h line:963
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
	int getChildren() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::GhostNode *>(this), "getChildren");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return GhostNode::getChildren();
	}
};

void bind_libdialect_graphs_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::swap(class dialect::Graph &, class dialect::Graph &) file:libdialect/graphs.h line:192
	M("dialect").def("swap", (void (*)(class dialect::Graph &, class dialect::Graph &)) &dialect::swap, "Swap operator.\n\nC++: dialect::swap(class dialect::Graph &, class dialect::Graph &) --> void", pybind11::arg("first"), pybind11::arg("second"));

	{ // dialect::Node file:libdialect/graphs.h line:737
		pybind11::class_<dialect::Node, std::shared_ptr<dialect::Node>, PyCallBack_dialect_Node> cl(M("dialect"), "Node", "The Node class represents nodes in a graph.");
		cl.def_static("allocate", (int (*)()) &dialect::Node::allocate, "Factory function, to get a shared pointer to a Node\n         allocated on the heap. We make the constructors protected,\n         in order to ensure that Nodes always come with a control block.\n \n\n  A shared_ptr to Node (Node_SP).\n\nC++: dialect::Node::allocate() --> int");
		cl.def_static("allocate", (int (*)(double, double)) &dialect::Node::allocate, "Convenience factory function to set dimensions.\n\nC++: dialect::Node::allocate(double, double) --> int", pybind11::arg("w"), pybind11::arg("h"));
		cl.def_static("allocate", (int (*)(double, double, double, double)) &dialect::Node::allocate, "Convenience factory function to set position and dimensions.\n\nC++: dialect::Node::allocate(double, double, double, double) --> int", pybind11::arg("cx"), pybind11::arg("dy"), pybind11::arg("w"), pybind11::arg("h"));
		cl.def("makeGhost", (int (dialect::Node::*)() const) &dialect::Node::makeGhost, "Allocate a GhostNode of this Node.\n\nC++: dialect::Node::makeGhost() const --> int");
		cl.def("id", (unsigned int (dialect::Node::*)() const) &dialect::Node::id, "Access the unique ID of a given instance.\n\n \n  The ID.\n\nC++: dialect::Node::id() const --> unsigned int");
		cl.def("getDegree", (unsigned int (dialect::Node::*)() const) &dialect::Node::getDegree, "Check the degree (number of incident Edges) of the Node.\n\n \n  The degree of the Node\n\nC++: dialect::Node::getDegree() const --> unsigned int");
		cl.def("setGraph", (void (dialect::Node::*)(class dialect::Graph &)) &dialect::Node::setGraph, "Tell the Node which Graph it belongs to.\n\n \n  The Graph to which the Node is to belong.\n\nC++: dialect::Node::setGraph(class dialect::Graph &) --> void", pybind11::arg("graph"));
		cl.def("getGraph", (class dialect::Graph * (dialect::Node::*)()) &dialect::Node::getGraph, "Access the Graph to which the Node belongs.\n\nC++: dialect::Node::getGraph() --> class dialect::Graph *", pybind11::return_value_policy::automatic);
		cl.def("addEdge", (void (dialect::Node::*)(const int &)) &dialect::Node::addEdge, "Add an incident Edge.\n\nC++: dialect::Node::addEdge(const int &) --> void", pybind11::arg("edge"));
		cl.def("removeEdge", (void (dialect::Node::*)(const class dialect::Edge &)) &dialect::Node::removeEdge, "Remove an incident Edge.\n\nC++: dialect::Node::removeEdge(const class dialect::Edge &) --> void", pybind11::arg("edge"));
		cl.def("getEdgeLookup", (const int & (dialect::Node::*)() const) &dialect::Node::getEdgeLookup, "Read-only access to this Node's lookup map for Edges by their ID.\n\nC++: dialect::Node::getEdgeLookup() const --> const int &", pybind11::return_value_policy::automatic);
		cl.def("getCopyOfEdgeLookup", (int (dialect::Node::*)() const) &dialect::Node::getCopyOfEdgeLookup, "Get a copy of this Node's lookup map for Edges by their ID.\n\nC++: dialect::Node::getCopyOfEdgeLookup() const --> int");
		cl.def("copyGeometry", (void (dialect::Node::*)(const class dialect::Node &)) &dialect::Node::copyGeometry, "Give this Node the same coordinates and dimensions as another.\n\nC++: dialect::Node::copyGeometry(const class dialect::Node &) --> void", pybind11::arg("other"));
		cl.def("copyOtherGhostProperties", (void (dialect::Node::*)(const class dialect::Node &)) &dialect::Node::copyOtherGhostProperties, "Besides copying geometry, there may be other properties we wish\n         to copy; in particular, properties that are suitable to be copied\n         by a GhostNode.\n\nC++: dialect::Node::copyOtherGhostProperties(const class dialect::Node &) --> void", pybind11::arg("other"));
		cl.def("getHalfDimensions", (int (dialect::Node::*)() const) &dialect::Node::getHalfDimensions, "Get an ordered pair (half-width, half-height) for this Node.\n\nC++: dialect::Node::getHalfDimensions() const --> int");
		cl.def("getDimensions", (int (dialect::Node::*)() const) &dialect::Node::getDimensions, "Get an ordered pair (width, height) for this Node.\n\nC++: dialect::Node::getDimensions() const --> int");
		cl.def("getBoundingBox", (struct dialect::BoundingBox (dialect::Node::*)() const) &dialect::Node::getBoundingBox, "Get the bounding box for this Node.\n\nC++: dialect::Node::getBoundingBox() const --> struct dialect::BoundingBox");
		cl.def("getBoundaryCompassPt", (int (dialect::Node::*)(int) const) &dialect::Node::getBoundaryCompassPt, "Get the point on the boundary of this Node in a given direction\n         from its centre.\n\nC++: dialect::Node::getBoundaryCompassPt(int) const --> int", pybind11::arg("dir"));
		cl.def("setCentre", (void (dialect::Node::*)(double, double)) &dialect::Node::setCentre, "Set the position of the node, by setting its centre coordinates.\n\nC++: dialect::Node::setCentre(double, double) --> void", pybind11::arg("cx"), pybind11::arg("cy"));
		cl.def("translate", (void (dialect::Node::*)(double, double)) &dialect::Node::translate, "Update the position of the node, by adding to its centre coordinates.\n\nC++: dialect::Node::translate(double, double) --> void", pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("applyPlaneMap", (void (dialect::Node::*)(int)) &dialect::Node::applyPlaneMap, "Apply a mapping from libavoid Points to libavoid Points, to this Node's centre.\n\nC++: dialect::Node::applyPlaneMap(int) --> void", pybind11::arg("map"));
		cl.def("getCentre", (int (dialect::Node::*)() const) &dialect::Node::getCentre, "Get the centre coordinates of the node.\n\nC++: dialect::Node::getCentre() const --> int");
		cl.def("setExternalId", (void (dialect::Node::*)(unsigned int)) &dialect::Node::setExternalId, "Set an externally-determined ID. (This is useful for TGLF and other\n         interfacing operations.)\n\nC++: dialect::Node::setExternalId(unsigned int) --> void", pybind11::arg("id"));
		cl.def("getExternalId", (int (dialect::Node::*)()) &dialect::Node::getExternalId, "Get the external ID.\n\nC++: dialect::Node::getExternalId() --> int");
		cl.def("getNeighbours", (int (dialect::Node::*)() const) &dialect::Node::getNeighbours, "Get the neighbours of this Node.\n\nC++: dialect::Node::getNeighbours() const --> int");
		cl.def("getNeighboursCwCyclic", (int (dialect::Node::*)() const) &dialect::Node::getNeighboursCwCyclic, "Get the neighbours of this Node, listed in clockwise cyclic order\n         (assuming the usual graphics convention of x increasing to the right\n         and y increasing downward).\n\nC++: dialect::Node::getNeighboursCwCyclic() const --> int");
		cl.def("getChildren", (int (dialect::Node::*)() const) &dialect::Node::getChildren, "Get the neighbours of this Node that sit as the target\n         end of the connecting Edge.\n\n \n  vector of the children of this Node\n\nC++: dialect::Node::getChildren() const --> int");
		cl.def("setDims", (void (dialect::Node::*)(double, double)) &dialect::Node::setDims, "Set the dimensions of the node.\n\nC++: dialect::Node::setDims(double, double) --> void", pybind11::arg("w"), pybind11::arg("h"));
		cl.def("setBoundingBox", (void (dialect::Node::*)(double, double, double, double)) &dialect::Node::setBoundingBox, "Set the bounding box of the node. This sets both the dimensions and the centre point.\n \n\n  The minimum x-coord of the box.\n \n\n  The maximum x-coord of the box.\n \n\n  The minimum y-coord of the box.\n \n\n  The maximum y-coord of the box.\n\nC++: dialect::Node::setBoundingBox(double, double, double, double) --> void", pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y"));
		cl.def("addPadding", (void (dialect::Node::*)(double, double)) &dialect::Node::addPadding, "Add padding to the node's dimensions.\n \n\n  Amounts can be positive or negative, thus adding or subtracting padding.\n\nC++: dialect::Node::addPadding(double, double) --> void", pybind11::arg("dw"), pybind11::arg("dh"));
		cl.def("updatePosnFromRect", (void (dialect::Node::*)(int *)) &dialect::Node::updatePosnFromRect, "Update the position of this Node to equal that of the given Rectangle.\n\nC++: dialect::Node::updatePosnFromRect(int *) --> void", pybind11::arg("r"));
		cl.def("updateXCoordFromRect", (void (dialect::Node::*)(int *)) &dialect::Node::updateXCoordFromRect, "Update the x-coordinate of this Node to equal that of the given Rectangle.\n\nC++: dialect::Node::updateXCoordFromRect(int *) --> void", pybind11::arg("r"));
		cl.def("updateYCoordFromRect", (void (dialect::Node::*)(int *)) &dialect::Node::updateYCoordFromRect, "Update the y-coordinate of this Node to equal that of the given Rectangle.\n\nC++: dialect::Node::updateYCoordFromRect(int *) --> void", pybind11::arg("r"));
		cl.def("makeLibavoidPolygon", (int (dialect::Node::*)() const) &dialect::Node::makeLibavoidPolygon, "Build and return a Polygon to represent this Node in libavoid.\n\nC++: dialect::Node::makeLibavoidPolygon() const --> int");
		cl.def("isRoot", (bool (dialect::Node::*)() const) &dialect::Node::isRoot, "Check whether this Node has been marked as being a root. This is\n         useful when working with trees, and can be safely ignored when\n         working with other sorts of graphs.\n\nC++: dialect::Node::isRoot() const --> bool");
		cl.def("setIsRoot", (void (dialect::Node::*)(bool)) &dialect::Node::setIsRoot, "Say whether this Node is a root. This is useful when working with\n         trees, and can be safely ignored when working with other sorts of graphs.\n\nC++: dialect::Node::setIsRoot(bool) --> void", pybind11::arg("isRoot"));
		cl.def("liesOppositeSegment", [](dialect::Node &o, const struct dialect::LineSegment & a0) -> bool { return o.liesOppositeSegment(a0); }, "", pybind11::arg("seg"));
		cl.def("liesOppositeSegment", (bool (dialect::Node::*)(const struct dialect::LineSegment &, bool)) &dialect::Node::liesOppositeSegment, "Check whether this Node lies opposite a LineSegment, i.e. whether\n         the sides of the Node lying parallel to the segment intersect its\n         interval.\n \n\n  The LineSegment in question.\n \n\n  Boolean saying whether we should treat the interval\n                      in question as an open one (i.e. not including its\n                      endpoints). Defaults to false, so that the closed\n                      interval is considered by default.\n\nC++: dialect::Node::liesOppositeSegment(const struct dialect::LineSegment &, bool) --> bool", pybind11::arg("seg"), pybind11::arg("openInterval"));
		cl.def("writeSvg", [](dialect::Node const &o) -> int { return o.writeSvg(); }, "");
		cl.def("writeSvg", (int (dialect::Node::*)(bool) const) &dialect::Node::writeSvg, "Write SVG to represent this Node.\n \n\n  If true, write external ID as label; otherwise write\n                           internal unique ID.\n \n\n  A string containing the SVG.\n\nC++: dialect::Node::writeSvg(bool) const --> int", pybind11::arg("useExternalId"));
	}
	{ // dialect::GhostNode file:libdialect/graphs.h line:963
		pybind11::class_<dialect::GhostNode, std::shared_ptr<dialect::GhostNode>, PyCallBack_dialect_GhostNode, dialect::Node> cl(M("dialect"), "GhostNode", "A GhostNode represents another Node.\n\n When working with techniques that involve decomposing a graph into parts,\n and then reassembling those parts, it is often useful to have a node in one\n part represent a node in another part. For example this can be a useful way\n to manage the nodes where the two parts intersect. The GhostNode class\n supports this by representing a given Node.");
		cl.def_static("allocate", (int (*)(const class dialect::Node &)) &dialect::GhostNode::allocate, "Factory function.\n\n \n  A shared_ptr to GhostNode (GhostNode_SP).\n\nC++: dialect::GhostNode::allocate(const class dialect::Node &) --> int", pybind11::arg("node"));
		cl.def("id", (unsigned int (dialect::GhostNode::*)() const) &dialect::GhostNode::id, "Return an appropriate ID number.\n\n Whether the GhostNode's actual ID is returned, or that of the\n Node it represents, depends whether it is set to masquerade.\n\nC++: dialect::GhostNode::id() const --> unsigned int");
		cl.def("trueID", (unsigned int (dialect::GhostNode::*)() const) &dialect::GhostNode::trueID, "Simple way to get the true ID of this GhostNode, even\n         if it is currently set to masquerade as the Node it represents.\n\nC++: dialect::GhostNode::trueID() const --> unsigned int");
		cl.def("getChildren", (int (dialect::GhostNode::*)() const) &dialect::GhostNode::getChildren, "As in the Node class, get the neighbours of this Node\n         that sit as the target end of the connecting Edge.\n\n This method performs the same function as the overriden method\n in the base Node class. It is only reimplemented in order to\n ensure that the GhostNode's id() function is used properly.\n\nC++: dialect::GhostNode::getChildren() const --> int");
		cl.def("setMasquerade", (void (dialect::GhostNode::*)(bool)) &dialect::GhostNode::setMasquerade, "Say whether the GhostNode should masquerade as the original Node.\n\nC++: dialect::GhostNode::setMasquerade(bool) --> void", pybind11::arg("doMasquerade"));
	}
	{ // dialect::Edge file:libdialect/graphs.h line:1030
		pybind11::class_<dialect::Edge, std::shared_ptr<dialect::Edge>> cl(M("dialect"), "Edge", "The Edge class represents edges in a graph.");
		cl.def_static("allocate", (int (*)(const int &, const int &)) &dialect::Edge::allocate, "Factory function.\n\n We make all constructors private and offer a factory function\n instead, in order to ensure that instances are allocated on the\n heap, and always come with a shared ptr control block.\n\n \n  A shared_ptr to Node (Node_SP).\n\nC++: dialect::Edge::allocate(const int &, const int &) --> int", pybind11::arg("src"), pybind11::arg("tgt"));
		cl.def("assign", (class dialect::Edge & (dialect::Edge::*)(const class dialect::Edge &)) &dialect::Edge::operator=, "Copy-assignment operator\n\nC++: dialect::Edge::operator=(const class dialect::Edge &) --> class dialect::Edge &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("id", (unsigned int (dialect::Edge::*)() const) &dialect::Edge::id, "Access the unique ID of this instance.\n\n \n  The ID.\n\nC++: dialect::Edge::id() const --> unsigned int");
		cl.def("getOtherEnd", (int (dialect::Edge::*)(const class dialect::Node &) const) &dialect::Edge::getOtherEnd, "Get the opposite endpt, from a given one\n\n \n  A Node lying at one end of this Edge.\n\n \n  The Node_SP lying at the other end.\n\nC++: dialect::Edge::getOtherEnd(const class dialect::Node &) const --> int", pybind11::arg("end1"));
		cl.def("getSourceEnd", (int (dialect::Edge::*)() const) &dialect::Edge::getSourceEnd, "Get read-only access to the Node at the source end of this Edge.\n\nC++: dialect::Edge::getSourceEnd() const --> int");
		cl.def("getTargetEnd", (int (dialect::Edge::*)() const) &dialect::Edge::getTargetEnd, "Get read-only access to the Node at the target end of this Edge.\n\nC++: dialect::Edge::getTargetEnd() const --> int");
		cl.def("getEndIds", (int (dialect::Edge::*)() const) &dialect::Edge::getEndIds, "Get a pair {srcID, tgtID} giving the IDs of the source and target Nodes.\n\nC++: dialect::Edge::getEndIds() const --> int");
		cl.def("setGraph", (void (dialect::Edge::*)(class dialect::Graph &)) &dialect::Edge::setGraph, "Tell the Edge which Graph it belongs to.\n\n \n  The Graph to which the Edge is to belong.\n\nC++: dialect::Edge::setGraph(class dialect::Graph &) --> void", pybind11::arg("graph"));
		cl.def("sever", (void (dialect::Edge::*)()) &dialect::Edge::sever, "\"Sever\" this Edge, i.e. remove it from the Nodes to which\n         it is attached.\n\nC++: dialect::Edge::sever() --> void");
		cl.def("getBoundingBox", (struct dialect::BoundingBox (dialect::Edge::*)() const) &dialect::Edge::getBoundingBox, "Get the bounding box for the edge,\n         including its end points and route points.\n\nC++: dialect::Edge::getBoundingBox() const --> struct dialect::BoundingBox");
		cl.def("addRoutePoint", (void (dialect::Edge::*)(double, double)) &dialect::Edge::addRoutePoint, "Add a point to the route.\n\nC++: dialect::Edge::addRoutePoint(double, double) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("setRoute", (void (dialect::Edge::*)(int)) &dialect::Edge::setRoute, "Set (overwriting) the entire route.\n\nC++: dialect::Edge::setRoute(int) --> void", pybind11::arg("route"));
		cl.def("getRoute", (int (dialect::Edge::*)() const) &dialect::Edge::getRoute, "Get a copy of the Edge's route member. May be empty.\n \n\n  If you are interested in drawing a connector, see the getRoutePoints method.\n \n\n getRoutePoints\n\nC++: dialect::Edge::getRoute() const --> int");
		cl.def("getRoutePoints", (int (dialect::Edge::*)() const) &dialect::Edge::getRoutePoints, "Get route points.\n \n\n  This method returns the points that form the route you would draw for\n        this edge. If the m_route vector is nonempty, a copy is returned.\n        Otherwise you get a vector of two points: the centre of the source\n        Node, and the centre of the target Node.\n \n\n getRoute\n\nC++: dialect::Edge::getRoutePoints() const --> int");
		cl.def("writeRouteTglf", (int (dialect::Edge::*)() const) &dialect::Edge::writeRouteTglf, "Write TGLF to represent the route for this Edge.\n\n \n  A string containing the TGLF.\n\nC++: dialect::Edge::writeRouteTglf() const --> int");
		cl.def("makeLibavoidConnEnds", [](dialect::Edge &o) -> int { return o.makeLibavoidConnEnds(); }, "");
		cl.def("makeLibavoidConnEnds", [](dialect::Edge &o, int const & a0) -> int { return o.makeLibavoidConnEnds(a0); }, "", pybind11::arg("srcDirs"));
		cl.def("makeLibavoidConnEnds", (int (dialect::Edge::*)(int, int)) &dialect::Edge::makeLibavoidConnEnds, "Build and return a pair of libavoid ConnEnds to represent\n         the endpoints of this Edge.\n\nC++: dialect::Edge::makeLibavoidConnEnds(int, int) --> int", pybind11::arg("srcDirs"), pybind11::arg("tgtDirs"));
		cl.def("setBendNodes", (void (dialect::Edge::*)(int)) &dialect::Edge::setBendNodes, "Set the bend nodes. These should be Nodes representing the bend points\n         in the Edge's route.\n\nC++: dialect::Edge::setBendNodes(int) --> void", pybind11::arg("bends"));
		cl.def("addBendNode", (void (dialect::Edge::*)(int)) &dialect::Edge::addBendNode, "Add a single bend node.\n\nC++: dialect::Edge::addBendNode(int) --> void", pybind11::arg("bn"));
		cl.def("getBendNodes", (int (dialect::Edge::*)()) &dialect::Edge::getBendNodes, "Access the Edge's bend nodes.\n\nC++: dialect::Edge::getBendNodes() --> int");
		cl.def("hasBendNodes", (bool (dialect::Edge::*)()) &dialect::Edge::hasBendNodes, "Check whether this Edge has any bend nodes.\n\nC++: dialect::Edge::hasBendNodes() --> bool");
		cl.def("rotate90cw", (void (dialect::Edge::*)()) &dialect::Edge::rotate90cw, "Rotate the connector route 90 degrees clockwise.\n\nC++: dialect::Edge::rotate90cw() --> void");
		cl.def("rotate90acw", (void (dialect::Edge::*)()) &dialect::Edge::rotate90acw, "Rotate the connector route 90 degrees anticlockwise.\n\nC++: dialect::Edge::rotate90acw() --> void");
		cl.def("rotate180", (void (dialect::Edge::*)()) &dialect::Edge::rotate180, "Rotate the connector route 180 degrees.\n\nC++: dialect::Edge::rotate180() --> void");
		cl.def("translate", (void (dialect::Edge::*)(double, double)) &dialect::Edge::translate, "Translate the connector route by a given amount in each dimension.\n \n\n  The amount by which to translate in the x-dimension.\n \n\n  The amount by which to translate in the y-dimension.\n\nC++: dialect::Edge::translate(double, double) --> void", pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("clearRouteAndBends", (void (dialect::Edge::*)()) &dialect::Edge::clearRouteAndBends, "Clear the connector route and drop all bend nodes.\n\nC++: dialect::Edge::clearRouteAndBends() --> void");
		cl.def("buildRouteFromBends", (void (dialect::Edge::*)()) &dialect::Edge::buildRouteFromBends, "Build a connector route based on the bend nodes.\n\nC++: dialect::Edge::buildRouteFromBends() --> void");
		cl.def("writeSvg", (int (dialect::Edge::*)() const) &dialect::Edge::writeSvg, "Write SVG to represent this Edge.\n \n\n  A string containing the SVG.\n\nC++: dialect::Edge::writeSvg() const --> int");
		cl.def("writePolylineConnectorData", (int (dialect::Edge::*)() const) &dialect::Edge::writePolylineConnectorData, "Write the data for a polyline SVG path for this Edge's connector route.\n\nC++: dialect::Edge::writePolylineConnectorData() const --> int");
		cl.def("writeRoundedOrthoConnectorData", (int (dialect::Edge::*)() const) &dialect::Edge::writeRoundedOrthoConnectorData, "Write the data for an orthogonal SVG path for this Edge's connector route,\n         using rounded bends.\n\nC++: dialect::Edge::writeRoundedOrthoConnectorData() const --> int");
	}
}
