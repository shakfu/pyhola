#include <libcola/straightener.h>
#include <libtopology/topology_constraints.h>
#include <libtopology/topology_graph.h>
#include <libvpsc/variable.h>
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

void bind_libtopology_topology_graph(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// topology::setNodeVariables(int &, int &) file:libtopology/topology_graph.h line:87
	M("topology").def("setNodeVariables", (void (*)(int &, int &)) &topology::setNodeVariables, "C++: topology::setNodeVariables(int &, int &) --> void", pybind11::arg("ns"), pybind11::arg("vs"));

	{ // topology::EdgePoint file:libtopology/topology_graph.h line:93
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
		cl.def("getBendConstraint", (void (topology::EdgePoint::*)(int *)) &topology::EdgePoint::getBendConstraint, "C++: topology::EdgePoint::getBendConstraint(int *) --> void", pybind11::arg("ts"));
		cl.def("createBendConstraint", (bool (topology::EdgePoint::*)(int)) &topology::EdgePoint::createBendConstraint, "C++: topology::EdgePoint::createBendConstraint(int) --> bool", pybind11::arg("scanDim"));
		cl.def("deleteBendConstraint", (void (topology::EdgePoint::*)()) &topology::EdgePoint::deleteBendConstraint, "C++: topology::EdgePoint::deleteBendConstraint() --> void");
		cl.def("pos", (double (topology::EdgePoint::*)(int) const) &topology::EdgePoint::pos, "C++: topology::EdgePoint::pos(int) const --> double", pybind11::arg("dim"));
		cl.def("posX", (double (topology::EdgePoint::*)() const) &topology::EdgePoint::posX, "C++: topology::EdgePoint::posX() const --> double");
		cl.def("posY", (double (topology::EdgePoint::*)() const) &topology::EdgePoint::posY, "C++: topology::EdgePoint::posY() const --> double");
		cl.def("rectIntersectAsVertexNumber", (unsigned short (topology::EdgePoint::*)() const) &topology::EdgePoint::rectIntersectAsVertexNumber, "C++: topology::EdgePoint::rectIntersectAsVertexNumber() const --> unsigned short");
		cl.def("uniqueCheck", (bool (topology::EdgePoint::*)(const class topology::EdgePoint *) const) &topology::EdgePoint::uniqueCheck, "C++: topology::EdgePoint::uniqueCheck(const class topology::EdgePoint *) const --> bool", pybind11::arg("e"));
		cl.def("isEnd", (bool (topology::EdgePoint::*)() const) &topology::EdgePoint::isEnd, "C++: topology::EdgePoint::isEnd() const --> bool");
		cl.def("assertConvexBend", (bool (topology::EdgePoint::*)() const) &topology::EdgePoint::assertConvexBend, "C++: topology::EdgePoint::assertConvexBend() const --> bool");
		cl.def("offset", (double (topology::EdgePoint::*)(int) const) &topology::EdgePoint::offset, "C++: topology::EdgePoint::offset(int) const --> double", pybind11::arg("scanDim"));
		cl.def("prune", (class topology::Segment * (topology::EdgePoint::*)(int)) &topology::EdgePoint::prune, "C++: topology::EdgePoint::prune(int) --> class topology::Segment *", pybind11::return_value_policy::automatic, pybind11::arg("scanDim"));
	}
	{ // topology::Segment file:libtopology/topology_graph.h line:203
		pybind11::class_<topology::Segment, std::shared_ptr<topology::Segment>> cl(M("topology"), "Segment", "");
		cl.def( pybind11::init<class topology::Edge *, class topology::EdgePoint *, class topology::EdgePoint *>(), pybind11::arg("edge"), pybind11::arg("start"), pybind11::arg("end") );

		cl.def("createStraightConstraint", (bool (topology::Segment::*)(int, class topology::Node *, double)) &topology::Segment::createStraightConstraint, "C++: topology::Segment::createStraightConstraint(int, class topology::Node *, double) --> bool", pybind11::arg("dim"), pybind11::arg("node"), pybind11::arg("pos"));
		cl.def("transferStraightConstraint", (void (topology::Segment::*)(class topology::StraightConstraint *)) &topology::Segment::transferStraightConstraint, "C++: topology::Segment::transferStraightConstraint(class topology::StraightConstraint *) --> void", pybind11::arg("s"));
		cl.def("getStraightConstraints", (void (topology::Segment::*)(int *) const) &topology::Segment::getStraightConstraints, "C++: topology::Segment::getStraightConstraints(int *) const --> void", pybind11::arg("ts"));
		cl.def("deleteStraightConstraints", (void (topology::Segment::*)()) &topology::Segment::deleteStraightConstraints, "C++: topology::Segment::deleteStraightConstraints() --> void");
		cl.def("getMin", (class topology::EdgePoint * (topology::Segment::*)(int) const) &topology::Segment::getMin, "C++: topology::Segment::getMin(int) const --> class topology::EdgePoint *", pybind11::return_value_policy::automatic, pybind11::arg("scanDim"));
		cl.def("getMax", (class topology::EdgePoint * (topology::Segment::*)(int) const) &topology::Segment::getMax, "C++: topology::Segment::getMax(int) const --> class topology::EdgePoint *", pybind11::return_value_policy::automatic, pybind11::arg("scanDim"));
		cl.def("forwardIntersection", (double (topology::Segment::*)(int, double, double &) const) &topology::Segment::forwardIntersection, "C++: topology::Segment::forwardIntersection(int, double, double &) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"), pybind11::arg("p"));
		cl.def("reverseIntersection", (double (topology::Segment::*)(int, double, double &) const) &topology::Segment::reverseIntersection, "C++: topology::Segment::reverseIntersection(int, double, double &) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"), pybind11::arg("p"));
		cl.def("forwardIntersection", (double (topology::Segment::*)(int, double) const) &topology::Segment::forwardIntersection, "C++: topology::Segment::forwardIntersection(int, double) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"));
		cl.def("intersection", (double (topology::Segment::*)(int, const double, const class topology::EdgePoint *, const class topology::EdgePoint *, double &) const) &topology::Segment::intersection, "C++: topology::Segment::intersection(int, const double, const class topology::EdgePoint *, const class topology::EdgePoint *, double &) const --> double", pybind11::arg("scanDim"), pybind11::arg("pos"), pybind11::arg("s"), pybind11::arg("e"), pybind11::arg("p"));
		cl.def("toString", (int (topology::Segment::*)() const) &topology::Segment::toString, "C++: topology::Segment::toString() const --> int");
		cl.def("length", (double (topology::Segment::*)(int) const) &topology::Segment::length, "C++: topology::Segment::length(int) const --> double", pybind11::arg("dim"));
		cl.def("length", (double (topology::Segment::*)() const) &topology::Segment::length, "C++: topology::Segment::length() const --> double");
		cl.def("assertNonZeroLength", (void (topology::Segment::*)() const) &topology::Segment::assertNonZeroLength, "C++: topology::Segment::assertNonZeroLength() const --> void");
		cl.def("connectedToNode", (bool (topology::Segment::*)(const class topology::Node *) const) &topology::Segment::connectedToNode, "C++: topology::Segment::connectedToNode(const class topology::Node *) const --> bool", pybind11::arg("v"));
	}
	{ // topology::Edge file:libtopology/topology_graph.h line:394
		pybind11::class_<topology::Edge, std::shared_ptr<topology::Edge>> cl(M("topology"), "Edge", "Topology representation of an edge.\n\n An edge provides a doubly linked list of segments, each involving a pair\n of EdgePoints.  \n\n \n You shouldn't need to create these yourself, but you may\n       extract them from an existing ColaTopologyAddon and construct\n       a new ColaTopologyAddon with that same topology information.");
		cl.def( pybind11::init<unsigned int, double, int &>(), pybind11::arg("id"), pybind11::arg("idealLength"), pybind11::arg("vs") );

		cl.def_readwrite("id", &topology::Edge::id);
		cl.def_readwrite("idealLength", &topology::Edge::idealLength);
		cl.def_readwrite("nSegments", &topology::Edge::nSegments);
		cl.def("pathLength", (double (topology::Edge::*)() const) &topology::Edge::pathLength, "C++: topology::Edge::pathLength() const --> double");
		cl.def("getPath", (void (topology::Edge::*)(int &) const) &topology::Edge::getPath, "C++: topology::Edge::getPath(int &) const --> void", pybind11::arg("vs"));
		cl.def("getRoute", (struct straightener::Route * (topology::Edge::*)() const) &topology::Edge::getRoute, "C++: topology::Edge::getRoute() const --> struct straightener::Route *", pybind11::return_value_policy::automatic);
		cl.def("getTopologyConstraints", (void (topology::Edge::*)(int *) const) &topology::Edge::getTopologyConstraints, "C++: topology::Edge::getTopologyConstraints(int *) const --> void", pybind11::arg("ts"));
		cl.def("assertConvexBends", (bool (topology::Edge::*)() const) &topology::Edge::assertConvexBends, "C++: topology::Edge::assertConvexBends() const --> bool");
		cl.def("cycle", (bool (topology::Edge::*)() const) &topology::Edge::cycle, "C++: topology::Edge::cycle() const --> bool");
		cl.def("toString", (int (topology::Edge::*)() const) &topology::Edge::toString, "C++: topology::Edge::toString() const --> int");
	}
	// topology::compute_stress(const int &) file:libtopology/topology_graph.h line:532
	M("topology").def("compute_stress", (double (*)(const int &)) &topology::compute_stress, "C++: topology::compute_stress(const int &) --> double", pybind11::arg(""));

	// topology::printEdges(const int &) file:libtopology/topology_graph.h line:533
	M("topology").def("printEdges", (void (*)(const int &)) &topology::printEdges, "C++: topology::printEdges(const int &) --> void", pybind11::arg(""));

	// topology::crossProduct(double, double, double, double, double, double) file:libtopology/topology_graph.h line:539
	M("topology").def("crossProduct", (double (*)(double, double, double, double, double, double)) &topology::crossProduct, "C++: topology::crossProduct(double, double, double, double, double, double) --> double", pybind11::arg("x0"), pybind11::arg("y0"), pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2"));

}
