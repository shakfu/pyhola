#include <_stdio.h>
#include <functional>
#include <libtopology/cola_topology_addon.h>
#include <libtopology/topology_constraints.h>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <string_view>
#include <valarray>
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

// topology::ColaTopologyAddon file:libtopology/cola_topology_addon.h line:44
struct PyCallBack_topology_ColaTopologyAddon : public topology::ColaTopologyAddon {
	using topology::ColaTopologyAddon::ColaTopologyAddon;

	class cola::TopologyAddonInterface * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::TopologyAddonInterface *>::value) {
				static pybind11::detail::override_caster_t<class cola::TopologyAddonInterface *> caster;
				return pybind11::detail::cast_ref<class cola::TopologyAddonInterface *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::TopologyAddonInterface *>(std::move(o));
		}
		return ColaTopologyAddon::clone();
	}
	void freeAssociatedObjects() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "freeAssociatedObjects");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return ColaTopologyAddon::freeAssociatedObjects();
	}
	double computeStress() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "computeStress");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<double>::value) {
				static pybind11::detail::override_caster_t<double> caster;
				return pybind11::detail::cast_ref<double>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<double>(std::move(o));
		}
		return ColaTopologyAddon::computeStress();
	}
	bool useTopologySolver() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "useTopologySolver");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ColaTopologyAddon::useTopologySolver();
	}
};

void bind_unknown_unknown_22(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // topology::delete_object file: line:26
		pybind11::class_<topology::delete_object, std::shared_ptr<topology::delete_object>> cl(M("topology"), "delete_object", "");
		cl.def( pybind11::init( [](){ return new topology::delete_object(); } ) );
		cl.def( pybind11::init( [](topology::delete_object const &o){ return new topology::delete_object(o); } ) );
		cl.def("__call__", (void (topology::delete_object::*)(class topology::EdgePoint *)) &topology::delete_object::operator()<topology::EdgePoint>, "C++: topology::delete_object::operator()(class topology::EdgePoint *) --> void", pybind11::arg("ptr"));
		cl.def("__call__", (void (topology::delete_object::*)(class topology::Segment *)) &topology::delete_object::operator()<topology::Segment>, "C++: topology::delete_object::operator()(class topology::Segment *) --> void", pybind11::arg("ptr"));
	}
	{ // topology::Node file: line:58
		pybind11::class_<topology::Node, std::shared_ptr<topology::Node>> cl(M("topology"), "Node", "Topology representation for a node.\n\n Each node is associated with a rectangle and solver variables\n for the x and y axes.\n\n \n You shouldn't need to create these yourself, but you may\n       extract them from an existing ColaTopologyAddon and construct\n       a new ColaTopologyAddon with that same topology information.");
		cl.def( pybind11::init( [](unsigned int const & a0, class vpsc::Rectangle * a1){ return new topology::Node(a0, a1); } ), "doc" , pybind11::arg("id"), pybind11::arg("r"));
		cl.def( pybind11::init<unsigned int, class vpsc::Rectangle *, class vpsc::Variable *>(), pybind11::arg("id"), pybind11::arg("r"), pybind11::arg("v") );

		cl.def_readonly("id", &topology::Node::id);
		cl.def("setDesiredPos", [](topology::Node &o, double const & a0) -> void { return o.setDesiredPos(a0); }, "", pybind11::arg("d"));
		cl.def("setDesiredPos", (void (topology::Node::*)(double, double)) &topology::Node::setDesiredPos, "C++: topology::Node::setDesiredPos(double, double) --> void", pybind11::arg("d"), pybind11::arg("weight"));
		cl.def("initialPos", (double (topology::Node::*)(enum vpsc::Dim) const) &topology::Node::initialPos, "C++: topology::Node::initialPos(enum vpsc::Dim) const --> double", pybind11::arg("scanDim"));
		cl.def("finalPos", (double (topology::Node::*)() const) &topology::Node::finalPos, "C++: topology::Node::finalPos() const --> double");
		cl.def("posOnLine", (double (topology::Node::*)(enum vpsc::Dim, double) const) &topology::Node::posOnLine, "C++: topology::Node::posOnLine(enum vpsc::Dim, double) const --> double", pybind11::arg("scanDim"), pybind11::arg("alpha"));
		cl.def("getVar", (class vpsc::Variable * (topology::Node::*)() const) &topology::Node::getVar, "C++: topology::Node::getVar() const --> class vpsc::Variable *", pybind11::return_value_policy::automatic);
	}
	{ // topology::EdgePoint file: line:93
		pybind11::class_<topology::EdgePoint, std::shared_ptr<topology::EdgePoint>> cl(M("topology"), "EdgePoint", "");
		cl.def( pybind11::init<class topology::Node *, enum topology::EdgePoint::RectIntersect>(), pybind11::arg("n"), pybind11::arg("i") );


		pybind11::enum_<topology::EdgePoint::RectIntersect>(cl, "RectIntersect", pybind11::arithmetic(), "")
			.value("TR", topology::EdgePoint::TR)
			.value("BR", topology::EdgePoint::BR)
			.value("BL", topology::EdgePoint::BL)
			.value("TL", topology::EdgePoint::TL)
			.value("CENTRE", topology::EdgePoint::CENTRE)
			.export_values();

		cl.def_readwrite("rectIntersect", &topology::EdgePoint::rectIntersect);
		cl.def("createBendConstraint", (bool (topology::EdgePoint::*)(enum vpsc::Dim)) &topology::EdgePoint::createBendConstraint, "C++: topology::EdgePoint::createBendConstraint(enum vpsc::Dim) --> bool", pybind11::arg("scanDim"));
		cl.def("deleteBendConstraint", (void (topology::EdgePoint::*)()) &topology::EdgePoint::deleteBendConstraint, "C++: topology::EdgePoint::deleteBendConstraint() --> void");
		cl.def("pos", (double (topology::EdgePoint::*)(enum vpsc::Dim) const) &topology::EdgePoint::pos, "C++: topology::EdgePoint::pos(enum vpsc::Dim) const --> double", pybind11::arg("dim"));
		cl.def("posX", (double (topology::EdgePoint::*)() const) &topology::EdgePoint::posX, "C++: topology::EdgePoint::posX() const --> double");
		cl.def("posY", (double (topology::EdgePoint::*)() const) &topology::EdgePoint::posY, "C++: topology::EdgePoint::posY() const --> double");
		cl.def("rectIntersectAsVertexNumber", (unsigned short (topology::EdgePoint::*)() const) &topology::EdgePoint::rectIntersectAsVertexNumber, "C++: topology::EdgePoint::rectIntersectAsVertexNumber() const --> unsigned short");
		cl.def("uniqueCheck", (bool (topology::EdgePoint::*)(const class topology::EdgePoint *) const) &topology::EdgePoint::uniqueCheck, "C++: topology::EdgePoint::uniqueCheck(const class topology::EdgePoint *) const --> bool", pybind11::arg("e"));
		cl.def("isEnd", (bool (topology::EdgePoint::*)() const) &topology::EdgePoint::isEnd, "C++: topology::EdgePoint::isEnd() const --> bool");
		cl.def("assertConvexBend", (bool (topology::EdgePoint::*)() const) &topology::EdgePoint::assertConvexBend, "C++: topology::EdgePoint::assertConvexBend() const --> bool");
		cl.def("offset", (double (topology::EdgePoint::*)(enum vpsc::Dim) const) &topology::EdgePoint::offset, "C++: topology::EdgePoint::offset(enum vpsc::Dim) const --> double", pybind11::arg("scanDim"));
		cl.def("prune", (class topology::Segment * (topology::EdgePoint::*)(enum vpsc::Dim)) &topology::EdgePoint::prune, "C++: topology::EdgePoint::prune(enum vpsc::Dim) --> class topology::Segment *", pybind11::return_value_policy::automatic, pybind11::arg("scanDim"));
	}
	{ // topology::Segment file: line:203
		pybind11::class_<topology::Segment, std::shared_ptr<topology::Segment>> cl(M("topology"), "Segment", "");
		cl.def( pybind11::init<class topology::Edge *, class topology::EdgePoint *, class topology::EdgePoint *>(), pybind11::arg("edge"), pybind11::arg("start"), pybind11::arg("end") );

		cl.def( pybind11::init( [](topology::Segment const &o){ return new topology::Segment(o); } ) );
		cl.def("createStraightConstraint", (bool (topology::Segment::*)(enum vpsc::Dim, class topology::Node *, double)) &topology::Segment::createStraightConstraint, "C++: topology::Segment::createStraightConstraint(enum vpsc::Dim, class topology::Node *, double) --> bool", pybind11::arg("dim"), pybind11::arg("node"), pybind11::arg("pos"));
		cl.def("transferStraightConstraint", (void (topology::Segment::*)(class topology::StraightConstraint *)) &topology::Segment::transferStraightConstraint, "C++: topology::Segment::transferStraightConstraint(class topology::StraightConstraint *) --> void", pybind11::arg("s"));
		cl.def("deleteStraightConstraints", (void (topology::Segment::*)()) &topology::Segment::deleteStraightConstraints, "C++: topology::Segment::deleteStraightConstraints() --> void");
		cl.def("getMin", (class topology::EdgePoint * (topology::Segment::*)(enum vpsc::Dim) const) &topology::Segment::getMin, "C++: topology::Segment::getMin(enum vpsc::Dim) const --> class topology::EdgePoint *", pybind11::return_value_policy::automatic, pybind11::arg("scanDim"));
		cl.def("getMax", (class topology::EdgePoint * (topology::Segment::*)(enum vpsc::Dim) const) &topology::Segment::getMax, "C++: topology::Segment::getMax(enum vpsc::Dim) const --> class topology::EdgePoint *", pybind11::return_value_policy::automatic, pybind11::arg("scanDim"));
		cl.def("forwardIntersection", (double (topology::Segment::*)(enum vpsc::Dim, double, double &) const) &topology::Segment::forwardIntersection, "C++: topology::Segment::forwardIntersection(enum vpsc::Dim, double, double &) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"), pybind11::arg("p"));
		cl.def("reverseIntersection", (double (topology::Segment::*)(enum vpsc::Dim, double, double &) const) &topology::Segment::reverseIntersection, "C++: topology::Segment::reverseIntersection(enum vpsc::Dim, double, double &) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"), pybind11::arg("p"));
		cl.def("forwardIntersection", (double (topology::Segment::*)(enum vpsc::Dim, double) const) &topology::Segment::forwardIntersection, "C++: topology::Segment::forwardIntersection(enum vpsc::Dim, double) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"));
		cl.def("intersection", (double (topology::Segment::*)(enum vpsc::Dim, const double, const class topology::EdgePoint *, const class topology::EdgePoint *, double &) const) &topology::Segment::intersection, "C++: topology::Segment::intersection(enum vpsc::Dim, const double, const class topology::EdgePoint *, const class topology::EdgePoint *, double &) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"), pybind11::arg("s"), pybind11::arg("e"), pybind11::arg("p"));
		cl.def("toString", (std::string (topology::Segment::*)() const) &topology::Segment::toString, "C++: topology::Segment::toString() const --> std::string");
		cl.def("length", (double (topology::Segment::*)(enum vpsc::Dim) const) &topology::Segment::length, "C++: topology::Segment::length(enum vpsc::Dim) const --> double", pybind11::arg("dim"));
		cl.def("length", (double (topology::Segment::*)() const) &topology::Segment::length, "C++: topology::Segment::length() const --> double");
		cl.def("assertNonZeroLength", (void (topology::Segment::*)() const) &topology::Segment::assertNonZeroLength, "C++: topology::Segment::assertNonZeroLength() const --> void");
		cl.def("connectedToNode", (bool (topology::Segment::*)(const class topology::Node *) const) &topology::Segment::connectedToNode, "C++: topology::Segment::connectedToNode(const class topology::Node *) const --> bool", pybind11::arg("v"));
	}
	// topology::ForEach(class topology::Edge *, struct topology::delete_object, struct topology::delete_object, bool) file: line:369
	M("topology").def("ForEach", [](class topology::Edge * a0, struct topology::delete_object const & a1, struct topology::delete_object const & a2) -> void { return topology::ForEach(a0, a1, a2); }, "", pybind11::arg("e"), pybind11::arg("po"), pybind11::arg("so"));
	M("topology").def("ForEach", (void (*)(class topology::Edge *, struct topology::delete_object, struct topology::delete_object, bool)) &topology::ForEach<topology::Edge *,topology::delete_object,topology::delete_object>, "C++: topology::ForEach(class topology::Edge *, struct topology::delete_object, struct topology::delete_object, bool) --> void", pybind11::arg("e"), pybind11::arg("po"), pybind11::arg("so"), pybind11::arg("noCycle"));

	{ // topology::Edge file: line:396
		pybind11::class_<topology::Edge, std::shared_ptr<topology::Edge>> cl(M("topology"), "Edge", "Topology representation of an edge.\n\n An edge provides a doubly linked list of segments, each involving a pair\n of EdgePoints.  \n\n \n You shouldn't need to create these yourself, but you may\n       extract them from an existing ColaTopologyAddon and construct\n       a new ColaTopologyAddon with that same topology information.");
		cl.def_readwrite("id", &topology::Edge::id);
		cl.def_readwrite("idealLength", &topology::Edge::idealLength);
		cl.def_readwrite("nSegments", &topology::Edge::nSegments);
		cl.def("forEach", [](topology::Edge &o, struct topology::delete_object const & a0, struct topology::delete_object const & a1) -> void { return o.forEach(a0, a1); }, "", pybind11::arg("po"), pybind11::arg("so"));
		cl.def("forEach", (void (topology::Edge::*)(struct topology::delete_object, struct topology::delete_object, bool)) &topology::Edge::forEach<topology::delete_object,topology::delete_object>, "C++: topology::Edge::forEach(struct topology::delete_object, struct topology::delete_object, bool) --> void", pybind11::arg("po"), pybind11::arg("so"), pybind11::arg("noCycle"));
		cl.def("forEach", [](topology::Edge const &o, struct topology::delete_object const & a0, struct topology::delete_object const & a1) -> void { return o.forEach(a0, a1); }, "", pybind11::arg("po"), pybind11::arg("so"));
		cl.def("forEach", (void (topology::Edge::*)(struct topology::delete_object, struct topology::delete_object, bool) const) &topology::Edge::forEach<topology::delete_object,topology::delete_object>, "C++: topology::Edge::forEach(struct topology::delete_object, struct topology::delete_object, bool) const --> void", pybind11::arg("po"), pybind11::arg("so"), pybind11::arg("noCycle"));
		cl.def("pathLength", (double (topology::Edge::*)() const) &topology::Edge::pathLength, "C++: topology::Edge::pathLength() const --> double");
		cl.def("getRoute", (struct straightener::Route * (topology::Edge::*)() const) &topology::Edge::getRoute, "C++: topology::Edge::getRoute() const --> struct straightener::Route *", pybind11::return_value_policy::automatic);
		cl.def("assertConvexBends", (bool (topology::Edge::*)() const) &topology::Edge::assertConvexBends, "C++: topology::Edge::assertConvexBends() const --> bool");
		cl.def("cycle", (bool (topology::Edge::*)() const) &topology::Edge::cycle, "C++: topology::Edge::cycle() const --> bool");
		cl.def("toString", (std::string (topology::Edge::*)() const) &topology::Edge::toString, "C++: topology::Edge::toString() const --> std::string");
	}
	// topology::crossProduct(double, double, double, double, double, double) file: line:541
	M("topology").def("crossProduct", (double (*)(double, double, double, double, double, double)) &topology::crossProduct, "C++: topology::crossProduct(double, double, double, double, double, double) --> double", pybind11::arg("x0"), pybind11::arg("y0"), pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2"));

	{ // topology::ColaTopologyAddon file:libtopology/cola_topology_addon.h line:44
		pybind11::class_<topology::ColaTopologyAddon, std::shared_ptr<topology::ColaTopologyAddon>, PyCallBack_topology_ColaTopologyAddon, cola::TopologyAddonInterface> cl(M("topology"), "ColaTopologyAddon", "This class can be passed to libcola to replace some functionality\n          to provide topology preserving layout.\n\n  You should instantiate this class with a given set of nodes and edges to\n  preserve and pass it to cola::ConstrainedFDLayout::setTopology().");
		cl.def( pybind11::init( [](){ return new topology::ColaTopologyAddon(); }, [](){ return new PyCallBack_topology_ColaTopologyAddon(); } ) );
		cl.def( pybind11::init( [](PyCallBack_topology_ColaTopologyAddon const &o){ return new PyCallBack_topology_ColaTopologyAddon(o); } ) );
		cl.def( pybind11::init( [](topology::ColaTopologyAddon const &o){ return new topology::ColaTopologyAddon(o); } ) );
		cl.def_readwrite("topologyNodes", &topology::ColaTopologyAddon::topologyNodes);
		cl.def_readwrite("topologyRoutes", &topology::ColaTopologyAddon::topologyRoutes);
		cl.def("writeSVGFile", [](topology::ColaTopologyAddon &o) -> void { return o.writeSVGFile(); }, "");
		cl.def("writeSVGFile", (void (topology::ColaTopologyAddon::*)(std::string)) &topology::ColaTopologyAddon::writeSVGFile, "Writes an SVG file displaying the current topology of \n         the nodes and edges.\n\n \n  A string indicating the filename (without \n                      extension) for the output file.  Defaults to\n                      \"libtopology-cola.svg\" if no filename is given.\n\nC++: topology::ColaTopologyAddon::writeSVGFile(std::string) --> void", pybind11::arg("filename"));
		cl.def("clone", (class cola::TopologyAddonInterface * (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::clone, "C++: topology::ColaTopologyAddon::clone() const --> class cola::TopologyAddonInterface *", pybind11::return_value_policy::automatic);
		cl.def("freeAssociatedObjects", (void (topology::ColaTopologyAddon::*)()) &topology::ColaTopologyAddon::freeAssociatedObjects, "C++: topology::ColaTopologyAddon::freeAssociatedObjects() --> void");
		cl.def("computeStress", (double (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::computeStress, "C++: topology::ColaTopologyAddon::computeStress() const --> double");
		cl.def("useTopologySolver", (bool (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::useTopologySolver, "C++: topology::ColaTopologyAddon::useTopologySolver() const --> bool");
		cl.def("assign", (class topology::ColaTopologyAddon & (topology::ColaTopologyAddon::*)(const class topology::ColaTopologyAddon &)) &topology::ColaTopologyAddon::operator=, "C++: topology::ColaTopologyAddon::operator=(const class topology::ColaTopologyAddon &) --> class topology::ColaTopologyAddon &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
