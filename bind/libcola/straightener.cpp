#include <libcola/sparse_matrix.h>
#include <libcola/straightener.h>
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

void bind_libcola_straightener(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // straightener::Route file:libcola/straightener.h line:39
		pybind11::class_<straightener::Route, std::shared_ptr<straightener::Route>> cl(M("straightener"), "Route", "");
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("n") );

		cl.def( pybind11::init( [](straightener::Route const &o){ return new straightener::Route(o); } ) );
		cl.def_readwrite("n", &straightener::Route::n);
		cl.def("print", (void (straightener::Route::*)()) &straightener::Route::print, "C++: straightener::Route::print() --> void");
		cl.def("boundingBox", (void (straightener::Route::*)(double &, double &, double &, double &)) &straightener::Route::boundingBox, "C++: straightener::Route::boundingBox(double &, double &, double &, double &) --> void", pybind11::arg("xmin"), pybind11::arg("ymin"), pybind11::arg("xmax"), pybind11::arg("ymax"));
		cl.def("routeLength", (double (straightener::Route::*)() const) &straightener::Route::routeLength, "C++: straightener::Route::routeLength() const --> double");
		cl.def("rerouteAround", (void (straightener::Route::*)(int *)) &straightener::Route::rerouteAround, "C++: straightener::Route::rerouteAround(int *) --> void", pybind11::arg("rect"));
	}
	{ // straightener::DebugPoint file:libcola/straightener.h line:77
		pybind11::class_<straightener::DebugPoint, std::shared_ptr<straightener::DebugPoint>> cl(M("straightener"), "DebugPoint", "");
		cl.def( pybind11::init( [](){ return new straightener::DebugPoint(); } ) );
		cl.def_readwrite("x", &straightener::DebugPoint::x);
		cl.def_readwrite("y", &straightener::DebugPoint::y);
	}
	{ // straightener::DebugLine file:libcola/straightener.h line:80
		pybind11::class_<straightener::DebugLine, std::shared_ptr<straightener::DebugLine>> cl(M("straightener"), "DebugLine", "");
		cl.def( pybind11::init<double, double, double, double, unsigned int>(), pybind11::arg("x0"), pybind11::arg("y0"), pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("colour") );

		cl.def_readwrite("x0", &straightener::DebugLine::x0);
		cl.def_readwrite("y0", &straightener::DebugLine::y0);
		cl.def_readwrite("x1", &straightener::DebugLine::x1);
		cl.def_readwrite("y1", &straightener::DebugLine::y1);
		cl.def_readwrite("colour", &straightener::DebugLine::colour);
	}
	{ // straightener::ScanObject file:libcola/straightener.h line:86
		pybind11::class_<straightener::ScanObject, std::shared_ptr<straightener::ScanObject>> cl(M("straightener"), "ScanObject", "");
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("id") );

		cl.def( pybind11::init( [](straightener::ScanObject const &o){ return new straightener::ScanObject(o); } ) );
		cl.def_readonly("id", &straightener::ScanObject::id);
		cl.def("getMin", (double (straightener::ScanObject::*)(int) const) &straightener::ScanObject::getMin, "C++: straightener::ScanObject::getMin(int) const --> double", pybind11::arg("d"));
		cl.def("getMax", (double (straightener::ScanObject::*)(int) const) &straightener::ScanObject::getMax, "C++: straightener::ScanObject::getMax(int) const --> double", pybind11::arg("d"));
	}
	{ // straightener::Edge file:libcola/straightener.h line:99
		pybind11::class_<straightener::Edge, std::shared_ptr<straightener::Edge>, straightener::ScanObject> cl(M("straightener"), "Edge", "");
		cl.def( pybind11::init<unsigned int, unsigned int, unsigned int, struct straightener::Route *>(), pybind11::arg("id"), pybind11::arg("start"), pybind11::arg("end"), pybind11::arg("route") );

		cl.def( pybind11::init<unsigned int, unsigned int, unsigned int, double, double, double, double>(), pybind11::arg("id"), pybind11::arg("start"), pybind11::arg("end"), pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2") );

		cl.def_readwrite("openInd", &straightener::Edge::openInd);
		cl.def_readwrite("startNode", &straightener::Edge::startNode);
		cl.def_readwrite("endNode", &straightener::Edge::endNode);
		cl.def_readwrite("idealLength", &straightener::Edge::idealLength);
		cl.def_readwrite("dummyNodes", &straightener::Edge::dummyNodes);
		cl.def_readwrite("path", &straightener::Edge::path);
		cl.def_readwrite("activePath", &straightener::Edge::activePath);
		cl.def_readwrite("debugPoints", &straightener::Edge::debugPoints);
		cl.def_readwrite("debugLines", &straightener::Edge::debugLines);
		cl.def("print", (void (straightener::Edge::*)()) &straightener::Edge::print, "C++: straightener::Edge::print() --> void");
		cl.def("rerouteAround", (void (straightener::Edge::*)(const int &)) &straightener::Edge::rerouteAround, "C++: straightener::Edge::rerouteAround(const int &) --> void", pybind11::arg("rects"));
		cl.def("isEnd", (bool (straightener::Edge::*)(unsigned int) const) &straightener::Edge::isEnd, "C++: straightener::Edge::isEnd(unsigned int) const --> bool", pybind11::arg("n"));
		cl.def("nodePath", (void (straightener::Edge::*)(int &, bool)) &straightener::Edge::nodePath, "C++: straightener::Edge::nodePath(int &, bool) --> void", pybind11::arg("nodes"), pybind11::arg("allActive"));
		cl.def("createRouteFromPath", (void (straightener::Edge::*)(const int &)) &straightener::Edge::createRouteFromPath, "C++: straightener::Edge::createRouteFromPath(const int &) --> void", pybind11::arg("nodes"));
		cl.def("xpos", (void (straightener::Edge::*)(double, int &) const) &straightener::Edge::xpos, "C++: straightener::Edge::xpos(double, int &) const --> void", pybind11::arg("y"), pybind11::arg("xs"));
		cl.def("ypos", (void (straightener::Edge::*)(double, int &) const) &straightener::Edge::ypos, "C++: straightener::Edge::ypos(double, int &) const --> void", pybind11::arg("x"), pybind11::arg("ys"));
		cl.def("getRoute", (const struct straightener::Route * (straightener::Edge::*)() const) &straightener::Edge::getRoute, "C++: straightener::Edge::getRoute() const --> const struct straightener::Route *", pybind11::return_value_policy::automatic);
		cl.def("setRoute", (void (straightener::Edge::*)(struct straightener::Route *)) &straightener::Edge::setRoute, "C++: straightener::Edge::setRoute(struct straightener::Route *) --> void", pybind11::arg("r"));
		cl.def("assign", (class straightener::Edge & (straightener::Edge::*)(const class straightener::Edge &)) &straightener::Edge::operator=, "C++: straightener::Edge::operator=(const class straightener::Edge &) --> class straightener::Edge &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // straightener::Straightener file:libcola/straightener.h line:184
		pybind11::class_<straightener::Straightener, std::shared_ptr<straightener::Straightener>> cl(M("straightener"), "Straightener", "");
		cl.def( pybind11::init( [](){ return new straightener::Straightener(); } ) );
		cl.def( pybind11::init<const double, const int, const int &, const int &, const int &, const int &, int &, int &, int &, int &>(), pybind11::arg("strength"), pybind11::arg("dim"), pybind11::arg("rs"), pybind11::arg("fixed"), pybind11::arg("edges"), pybind11::arg("vs"), pybind11::arg("lvs"), pybind11::arg("lcs"), pybind11::arg("oldCoords"), pybind11::arg("oldG") );

		cl.def_readwrite("dummyNodesX", &straightener::Straightener::dummyNodesX);
		cl.def_readwrite("dummyNodesY", &straightener::Straightener::dummyNodesY);
		cl.def_readwrite("g", &straightener::Straightener::g);
		cl.def_readwrite("coords", &straightener::Straightener::coords);
		cl.def_readwrite("N", &straightener::Straightener::N);
		cl.def("updateNodePositions", (void (straightener::Straightener::*)()) &straightener::Straightener::updateNodePositions, "C++: straightener::Straightener::updateNodePositions() --> void");
		cl.def("finalizeRoutes", (void (straightener::Straightener::*)()) &straightener::Straightener::finalizeRoutes, "C++: straightener::Straightener::finalizeRoutes() --> void");
		cl.def("computeForces", (void (straightener::Straightener::*)(struct cola::SparseMap &)) &straightener::Straightener::computeForces, "C++: straightener::Straightener::computeForces(struct cola::SparseMap &) --> void", pybind11::arg("H"));
		cl.def("computeForces2", (void (straightener::Straightener::*)(struct cola::SparseMap &)) &straightener::Straightener::computeForces2, "C++: straightener::Straightener::computeForces2(struct cola::SparseMap &) --> void", pybind11::arg("H"));
		cl.def("computeStress", (double (straightener::Straightener::*)(const int &)) &straightener::Straightener::computeStress, "C++: straightener::Straightener::computeStress(const int &) --> double", pybind11::arg("coords"));
		cl.def("computeStress2", (double (straightener::Straightener::*)(const int &)) &straightener::Straightener::computeStress2, "C++: straightener::Straightener::computeStress2(const int &) --> double", pybind11::arg("coords"));
	}
	{ // straightener::Cluster file:libcola/straightener.h line:234
		pybind11::class_<straightener::Cluster, std::shared_ptr<straightener::Cluster>> cl(M("straightener"), "Cluster", "");
		cl.def_readwrite("scanpos", &straightener::Cluster::scanpos);
		cl.def_readwrite("boundary", &straightener::Cluster::boundary);
		cl.def("updateActualBoundary", (void (straightener::Cluster::*)()) &straightener::Cluster::updateActualBoundary, "C++: straightener::Cluster::updateActualBoundary() --> void");
	}
	{ // straightener::Node file:libcola/straightener.h line:242
		pybind11::class_<straightener::Node, std::shared_ptr<straightener::Node>, straightener::ScanObject> cl(M("straightener"), "Node", "");
		cl.def( pybind11::init<unsigned int, const int *>(), pybind11::arg("id"), pybind11::arg("r") );

		cl.def( pybind11::init<unsigned int, const double, const double>(), pybind11::arg("id"), pybind11::arg("x"), pybind11::arg("y") );

		cl.def_readwrite("scanpos", &straightener::Node::scanpos);
		cl.def_readwrite("dummy", &straightener::Node::dummy);
		cl.def_readwrite("scan", &straightener::Node::scan);
		cl.def_readwrite("active", &straightener::Node::active);
		cl.def_readwrite("open", &straightener::Node::open);
		cl.def("euclidean_distance", (double (straightener::Node::*)(const class straightener::Node *) const) &straightener::Node::euclidean_distance, "C++: straightener::Node::euclidean_distance(const class straightener::Node *) const --> double", pybind11::arg("v"));
	}
	// straightener::sortNeighbours(const int, class straightener::Node *, class straightener::Node *, class straightener::Node *, const double, const int &, int &, int &) file:libcola/straightener.h line:285
	M("straightener").def("sortNeighbours", (void (*)(const int, class straightener::Node *, class straightener::Node *, class straightener::Node *, const double, const int &, int &, int &)) &straightener::sortNeighbours, "C++: straightener::sortNeighbours(const int, class straightener::Node *, class straightener::Node *, class straightener::Node *, const double, const int &, int &, int &) --> void", pybind11::arg("dim"), pybind11::arg("v"), pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("conjpos"), pybind11::arg("openEdges"), pybind11::arg("L"), pybind11::arg("nodes"));

	{ // straightener::CmpNodePos file:libcola/straightener.h line:301
		pybind11::class_<straightener::CmpNodePos, std::shared_ptr<straightener::CmpNodePos>> cl(M("straightener"), "CmpNodePos", "");
		cl.def( pybind11::init( [](){ return new straightener::CmpNodePos(); } ) );
		cl.def("__call__", (bool (straightener::CmpNodePos::*)(const class straightener::Node *, const class straightener::Node *) const) &straightener::CmpNodePos::operator(), "C++: straightener::CmpNodePos::operator()(const class straightener::Node *, const class straightener::Node *) const --> bool", pybind11::arg("u"), pybind11::arg("v"));
	}
	{ // straightener::LinearConstraint file:libcola/straightener.h line:328
		pybind11::class_<straightener::LinearConstraint, std::shared_ptr<straightener::LinearConstraint>> cl(M("straightener"), "LinearConstraint", "");
		cl.def( pybind11::init<const class straightener::Node &, const class straightener::Node &, const class straightener::Node &, double>(), pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("b"), pybind11::arg("w") );

		cl.def_readwrite("u", &straightener::LinearConstraint::u);
		cl.def_readwrite("v", &straightener::LinearConstraint::v);
		cl.def_readwrite("b", &straightener::LinearConstraint::b);
		cl.def_readwrite("w", &straightener::LinearConstraint::w);
		cl.def_readwrite("t", &straightener::LinearConstraint::t);
		cl.def_readwrite("duu", &straightener::LinearConstraint::duu);
		cl.def_readwrite("duv", &straightener::LinearConstraint::duv);
		cl.def_readwrite("dub", &straightener::LinearConstraint::dub);
		cl.def_readwrite("dvv", &straightener::LinearConstraint::dvv);
		cl.def_readwrite("dvb", &straightener::LinearConstraint::dvb);
		cl.def_readwrite("dbb", &straightener::LinearConstraint::dbb);
	}
	// straightener::pathLength(const class straightener::Edge *, const int &) file:libcola/straightener.h line:370
	M("straightener").def("pathLength", (double (*)(const class straightener::Edge *, const int &)) &straightener::pathLength, "C++: straightener::pathLength(const class straightener::Edge *, const int &) --> double", pybind11::arg("e"), pybind11::arg("nodes"));

	// straightener::computeStressFromRoutes(double, int &) file:libcola/straightener.h line:371
	M("straightener").def("computeStressFromRoutes", (double (*)(double, int &)) &straightener::computeStressFromRoutes, "C++: straightener::computeStressFromRoutes(double, int &) --> double", pybind11::arg("strength"), pybind11::arg("edges"));

	// straightener::generateConstraints(const int, int &, const int &, int &, bool) file:libcola/straightener.h line:373
	M("straightener").def("generateConstraints", (void (*)(const int, int &, const int &, int &, bool)) &straightener::generateConstraints, "C++: straightener::generateConstraints(const int, int &, const int &, int &, bool) --> void", pybind11::arg("dim"), pybind11::arg("nodes"), pybind11::arg("edges"), pybind11::arg("cs"), pybind11::arg("xSkipping"));

	// straightener::nodePath(class straightener::Edge &, int &, int &) file:libcola/straightener.h line:379
	M("straightener").def("nodePath", (void (*)(class straightener::Edge &, int &, int &)) &straightener::nodePath, "C++: straightener::nodePath(class straightener::Edge &, int &, int &) --> void", pybind11::arg("e"), pybind11::arg("nodes"), pybind11::arg("path"));

}
