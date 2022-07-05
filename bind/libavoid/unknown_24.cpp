#include <libavoid/actioninfo.h>
#include <libavoid/connectionpin.h>
#include <libavoid/connector.h>
#include <libavoid/junction.h>
#include <list>
#include <memory>
#include <sstream> // __str__
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

void bind_unknown_unknown_24(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Avoid::angle(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) file: line:48
	M("Avoid").def("angle", (double (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &)) &Avoid::angle, "C++: Avoid::angle(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) --> double", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"));

	// Avoid::segmentIntersect(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) file: line:49
	M("Avoid").def("segmentIntersect", (bool (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &)) &Avoid::segmentIntersect, "C++: Avoid::segmentIntersect(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"), pybind11::arg("d"));

	// Avoid::segmentShapeIntersect(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, bool &) file: line:51
	M("Avoid").def("segmentShapeIntersect", (bool (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, bool &)) &Avoid::segmentShapeIntersect, "C++: Avoid::segmentShapeIntersect(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, bool &) --> bool", pybind11::arg("e1"), pybind11::arg("e2"), pybind11::arg("s1"), pybind11::arg("s2"), pybind11::arg("seenIntersectionAtEndpoint"));

	// Avoid::inPoly(const class Avoid::Polygon &, const class Avoid::Point &, bool) file: line:53
	M("Avoid").def("inPoly", [](const class Avoid::Polygon & a0, const class Avoid::Point & a1) -> bool { return Avoid::inPoly(a0, a1); }, "", pybind11::arg("poly"), pybind11::arg("q"));
	M("Avoid").def("inPoly", (bool (*)(const class Avoid::Polygon &, const class Avoid::Point &, bool)) &Avoid::inPoly, "C++: Avoid::inPoly(const class Avoid::Polygon &, const class Avoid::Point &, bool) --> bool", pybind11::arg("poly"), pybind11::arg("q"), pybind11::arg("countBorder"));

	// Avoid::inPolyGen(const class Avoid::PolygonInterface &, const class Avoid::Point &) file: line:54
	M("Avoid").def("inPolyGen", (bool (*)(const class Avoid::PolygonInterface &, const class Avoid::Point &)) &Avoid::inPolyGen, "C++: Avoid::inPolyGen(const class Avoid::PolygonInterface &, const class Avoid::Point &) --> bool", pybind11::arg("poly"), pybind11::arg("q"));

	// Avoid::inValidRegion(bool, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) file: line:55
	M("Avoid").def("inValidRegion", (bool (*)(bool, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &)) &Avoid::inValidRegion, "C++: Avoid::inValidRegion(bool, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) --> bool", pybind11::arg("IgnoreRegions"), pybind11::arg("a0"), pybind11::arg("a1"), pybind11::arg("a2"), pybind11::arg("b"));

	// Avoid::cornerSide(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) file: line:57
	M("Avoid").def("cornerSide", (int (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &)) &Avoid::cornerSide, "C++: Avoid::cornerSide(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) --> int", pybind11::arg("c1"), pybind11::arg("c2"), pybind11::arg("c3"), pybind11::arg("p"));

	// Avoid::pointOnLine(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double) file: line:59
	M("Avoid").def("pointOnLine", [](const class Avoid::Point & a0, const class Avoid::Point & a1, const class Avoid::Point & a2) -> bool { return Avoid::pointOnLine(a0, a1, a2); }, "", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"));
	M("Avoid").def("pointOnLine", (bool (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double)) &Avoid::pointOnLine, "C++: Avoid::pointOnLine(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"), pybind11::arg("tolerance"));

	// Avoid::colinear(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double) file: line:61
	M("Avoid").def("colinear", [](const class Avoid::Point & a0, const class Avoid::Point & a1, const class Avoid::Point & a2) -> bool { return Avoid::colinear(a0, a1, a2); }, "", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"));
	M("Avoid").def("colinear", (bool (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double)) &Avoid::colinear, "C++: Avoid::colinear(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"), pybind11::arg("tolerance"));

	// Avoid::inBetween(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) file: line:64
	M("Avoid").def("inBetween", (bool (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &)) &Avoid::inBetween, "C++: Avoid::inBetween(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"));

	// Avoid::vecDir(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double) file: line:79
	M("Avoid").def("vecDir", [](const class Avoid::Point & a0, const class Avoid::Point & a1, const class Avoid::Point & a2) -> int { return Avoid::vecDir(a0, a1, a2); }, "", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"));
	M("Avoid").def("vecDir", (int (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double)) &Avoid::vecDir, "C++: Avoid::vecDir(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const double) --> int", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"), pybind11::arg("maybeZero"));

	// Avoid::projection(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) file: line:99
	M("Avoid").def("projection", (class Avoid::Point (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &)) &Avoid::projection, "C++: Avoid::projection(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &) --> class Avoid::Point", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("c"));

	// Avoid::segmentIntersectPoint(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, double *, double *) file: line:119
	M("Avoid").def("segmentIntersectPoint", (int (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, double *, double *)) &Avoid::segmentIntersectPoint, "C++: Avoid::segmentIntersectPoint(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, double *, double *) --> int", pybind11::arg("a1"), pybind11::arg("a2"), pybind11::arg("b1"), pybind11::arg("b2"), pybind11::arg("x"), pybind11::arg("y"));

	// Avoid::rayIntersectPoint(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, double *, double *) file: line:121
	M("Avoid").def("rayIntersectPoint", (int (*)(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, double *, double *)) &Avoid::rayIntersectPoint, "C++: Avoid::rayIntersectPoint(const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, const class Avoid::Point &, double *, double *) --> int", pybind11::arg("a1"), pybind11::arg("a2"), pybind11::arg("b1"), pybind11::arg("b2"), pybind11::arg("x"), pybind11::arg("y"));

	// Avoid::rotationalAngle(const class Avoid::Point &) file: line:123
	M("Avoid").def("rotationalAngle", (double (*)(const class Avoid::Point &)) &Avoid::rotationalAngle, "C++: Avoid::rotationalAngle(const class Avoid::Point &) --> double", pybind11::arg("p"));

	// Avoid::ConnDirFlag file: line:62
	pybind11::enum_<Avoid::ConnDirFlag>(M("Avoid"), "ConnDirFlag", pybind11::arithmetic(), "Flags that can be passed to the ConnEnd constructor to specify\n         which sides of a shape this point should have visibility to if\n         it is located within the shape's area.\n\n Like SVG, libavoid considers the Y-axis to point downwards, that is, \n like screen coordinates the coordinates increase from left-to-right and \n also from top-to-bottom.")
		.value("ConnDirNone", Avoid::ConnDirNone)
		.value("ConnDirUp", Avoid::ConnDirUp)
		.value("ConnDirDown", Avoid::ConnDirDown)
		.value("ConnDirLeft", Avoid::ConnDirLeft)
		.value("ConnDirRight", Avoid::ConnDirRight)
		.value("ConnDirAll", Avoid::ConnDirAll)
		.export_values();

;

	// Avoid::ConnEndType file: line:89
	pybind11::enum_<Avoid::ConnEndType>(M("Avoid"), "ConnEndType", pybind11::arithmetic(), "Types that describe the kind a connection that a ConnEnd \n         represents.")
		.value("ConnEndPoint", Avoid::ConnEndPoint)
		.value("ConnEndShapePin", Avoid::ConnEndShapePin)
		.value("ConnEndJunction", Avoid::ConnEndJunction)
		.value("ConnEndEmpty", Avoid::ConnEndEmpty)
		.export_values();

;

	{ // Avoid::ConnEnd file: line:110
		pybind11::class_<Avoid::ConnEnd, std::shared_ptr<Avoid::ConnEnd>> cl(M("Avoid"), "ConnEnd", "The ConnEnd class represents different possible endpoints for \n         connectors.\n\n ConnEnds may be free-floating points, points attached to junctions (between\n multiple connectors), or points attached to shapes (either to the centre of \n the shape or to particular pin positions on the shape).");
		cl.def( pybind11::init<const class Avoid::Point &>(), pybind11::arg("point") );

		cl.def( pybind11::init<const class Avoid::Point &, const unsigned int>(), pybind11::arg("point"), pybind11::arg("visDirs") );

		cl.def( pybind11::init<class Avoid::ShapeRef *, const unsigned int>(), pybind11::arg("shapeRef"), pybind11::arg("connectionPinClassID") );

		cl.def( pybind11::init<class Avoid::JunctionRef *>(), pybind11::arg("junctionRef") );

		cl.def( pybind11::init( [](){ return new Avoid::ConnEnd(); } ) );
		cl.def("type", (enum Avoid::ConnEndType (Avoid::ConnEnd::*)() const) &Avoid::ConnEnd::type, "Returns the kind of connection this ConnEnd represents.\n\n \n The ConnEndType represented by this ConnEnd.\n\nC++: Avoid::ConnEnd::type() const --> enum Avoid::ConnEndType");
		cl.def("position", (const class Avoid::Point (Avoid::ConnEnd::*)() const) &Avoid::ConnEnd::position, "Returns the position of this connector endpoint.\n\n \n The position of this connector endpoint.\n\nC++: Avoid::ConnEnd::position() const --> const class Avoid::Point");
		cl.def("directions", (unsigned int (Avoid::ConnEnd::*)() const) &Avoid::ConnEnd::directions, "Returns the directions in which this connector endpoint\n        should be given visibility.\n\n \n The visibility directions for this connector endpoint.\n\nC++: Avoid::ConnEnd::directions() const --> unsigned int");
		cl.def("shape", (class Avoid::ShapeRef * (Avoid::ConnEnd::*)() const) &Avoid::ConnEnd::shape, "Returns the shape this ConnEnd attaches to, or nullptr.\n\n Will be valid only if type() == ConnEndShapePin.\n\n \n The ShapeRef pointer that the ConnEnd attaches to, or nullptr.\n\nC++: Avoid::ConnEnd::shape() const --> class Avoid::ShapeRef *", pybind11::return_value_policy::automatic);
		cl.def("junction", (class Avoid::JunctionRef * (Avoid::ConnEnd::*)() const) &Avoid::ConnEnd::junction, "Returns the junction this ConnEnd attaches to, or nullptr.\n\n Will be valid only if type() == ConnEndJunction.\n\n \n The JunctionRef pointer that the ConnEnd attaches to,\n         or nullptr.\n\nC++: Avoid::ConnEnd::junction() const --> class Avoid::JunctionRef *", pybind11::return_value_policy::automatic);
		cl.def("pinClassId", (unsigned int (Avoid::ConnEnd::*)() const) &Avoid::ConnEnd::pinClassId, "Returns the pin class ID for a ConnEnd attached to a shape.\n\n Will be valid only if type() == ConnEndShapePin.\n\n \n An unsigned int representing the pin class ID for the\n         ConnEnd.\n\nC++: Avoid::ConnEnd::pinClassId() const --> unsigned int");
	}
	// Avoid::ActionType file:libavoid/actioninfo.h line:46
	pybind11::enum_<Avoid::ActionType>(M("Avoid"), "ActionType", pybind11::arithmetic(), "")
		.value("ShapeMove", Avoid::ShapeMove)
		.value("ShapeAdd", Avoid::ShapeAdd)
		.value("ShapeRemove", Avoid::ShapeRemove)
		.value("JunctionMove", Avoid::JunctionMove)
		.value("JunctionAdd", Avoid::JunctionAdd)
		.value("JunctionRemove", Avoid::JunctionRemove)
		.value("ConnChange", Avoid::ConnChange)
		.value("ConnectionPinChange", Avoid::ConnectionPinChange)
		.export_values();

;

	{ // Avoid::ActionInfo file:libavoid/actioninfo.h line:59
		pybind11::class_<Avoid::ActionInfo, std::shared_ptr<Avoid::ActionInfo>> cl(M("Avoid"), "ActionInfo", "");
		cl.def( pybind11::init<enum Avoid::ActionType, class Avoid::ShapeRef *, const class Avoid::Polygon &, bool>(), pybind11::arg("t"), pybind11::arg("s"), pybind11::arg("p"), pybind11::arg("fM") );

		cl.def( pybind11::init<enum Avoid::ActionType, class Avoid::ShapeRef *>(), pybind11::arg("t"), pybind11::arg("s") );

		cl.def( pybind11::init<enum Avoid::ActionType, class Avoid::JunctionRef *, const class Avoid::Point &>(), pybind11::arg("t"), pybind11::arg("j"), pybind11::arg("p") );

		cl.def( pybind11::init<enum Avoid::ActionType, class Avoid::JunctionRef *>(), pybind11::arg("t"), pybind11::arg("j") );

		cl.def( pybind11::init<enum Avoid::ActionType, class Avoid::ConnRef *>(), pybind11::arg("t"), pybind11::arg("c") );

		cl.def( pybind11::init<enum Avoid::ActionType, class Avoid::ShapeConnectionPin *>(), pybind11::arg("t"), pybind11::arg("p") );

		cl.def( pybind11::init( [](Avoid::ActionInfo const &o){ return new Avoid::ActionInfo(o); } ) );
		cl.def_readwrite("type", &Avoid::ActionInfo::type);
		cl.def_readwrite("newPoly", &Avoid::ActionInfo::newPoly);
		cl.def_readwrite("newPosition", &Avoid::ActionInfo::newPosition);
		cl.def_readwrite("firstMove", &Avoid::ActionInfo::firstMove);
		cl.def_readwrite("conns", &Avoid::ActionInfo::conns);
		cl.def("obstacle", (class Avoid::Obstacle * (Avoid::ActionInfo::*)() const) &Avoid::ActionInfo::obstacle, "C++: Avoid::ActionInfo::obstacle() const --> class Avoid::Obstacle *", pybind11::return_value_policy::automatic);
		cl.def("shape", (class Avoid::ShapeRef * (Avoid::ActionInfo::*)() const) &Avoid::ActionInfo::shape, "C++: Avoid::ActionInfo::shape() const --> class Avoid::ShapeRef *", pybind11::return_value_policy::automatic);
		cl.def("conn", (class Avoid::ConnRef * (Avoid::ActionInfo::*)() const) &Avoid::ActionInfo::conn, "C++: Avoid::ActionInfo::conn() const --> class Avoid::ConnRef *", pybind11::return_value_policy::automatic);
		cl.def("junction", (class Avoid::JunctionRef * (Avoid::ActionInfo::*)() const) &Avoid::ActionInfo::junction, "C++: Avoid::ActionInfo::junction() const --> class Avoid::JunctionRef *", pybind11::return_value_policy::automatic);
		cl.def("addConnEndUpdate", (void (Avoid::ActionInfo::*)(const unsigned int, const class Avoid::ConnEnd &, bool)) &Avoid::ActionInfo::addConnEndUpdate, "C++: Avoid::ActionInfo::addConnEndUpdate(const unsigned int, const class Avoid::ConnEnd &, bool) --> void", pybind11::arg("type"), pybind11::arg("connEnd"), pybind11::arg("isConnPinMoveUpdate"));
		cl.def("__eq__", (bool (Avoid::ActionInfo::*)(const class Avoid::ActionInfo &) const) &Avoid::ActionInfo::operator==, "C++: Avoid::ActionInfo::operator==(const class Avoid::ActionInfo &) const --> bool", pybind11::arg("rhs"));
	}
}
