#include <functional>
#include <ios>
#include <iterator>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <locale>
#include <memory>
#include <ostream>
#include <set>
#include <sstream> // __str__
#include <streambuf>
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

void bind_libvpsc_rectangle(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// vpsc::Dim file:libvpsc/rectangle.h line:41
	pybind11::enum_<vpsc::Dim>(M("vpsc"), "Dim", pybind11::arithmetic(), "Indicates the x- or y-dimension.")
		.value("HORIZONTAL", vpsc::HORIZONTAL)
		.value("XDIM", vpsc::XDIM)
		.value("VERTICAL", vpsc::VERTICAL)
		.value("YDIM", vpsc::YDIM)
		.value("UNSET", vpsc::UNSET)
		.export_values();

;

	// vpsc::conjugate(enum vpsc::Dim) file:libvpsc/rectangle.h line:54
	M("vpsc").def("conjugate", (enum vpsc::Dim (*)(enum vpsc::Dim)) &vpsc::conjugate, "C++: vpsc::conjugate(enum vpsc::Dim) --> enum vpsc::Dim", pybind11::arg("d"));

	{ // vpsc::RectangleIntersections file:libvpsc/rectangle.h line:59
		pybind11::class_<vpsc::RectangleIntersections, std::shared_ptr<vpsc::RectangleIntersections>> cl(M("vpsc"), "RectangleIntersections", "");
		cl.def( pybind11::init( [](){ return new vpsc::RectangleIntersections(); } ) );
		cl.def_readwrite("intersects", &vpsc::RectangleIntersections::intersects);
		cl.def_readwrite("top", &vpsc::RectangleIntersections::top);
		cl.def_readwrite("bottom", &vpsc::RectangleIntersections::bottom);
		cl.def_readwrite("left", &vpsc::RectangleIntersections::left);
		cl.def_readwrite("right", &vpsc::RectangleIntersections::right);
		cl.def_readwrite("topX", &vpsc::RectangleIntersections::topX);
		cl.def_readwrite("topY", &vpsc::RectangleIntersections::topY);
		cl.def_readwrite("bottomX", &vpsc::RectangleIntersections::bottomX);
		cl.def_readwrite("bottomY", &vpsc::RectangleIntersections::bottomY);
		cl.def_readwrite("leftX", &vpsc::RectangleIntersections::leftX);
		cl.def_readwrite("leftY", &vpsc::RectangleIntersections::leftY);
		cl.def_readwrite("rightX", &vpsc::RectangleIntersections::rightX);
		cl.def_readwrite("rightY", &vpsc::RectangleIntersections::rightY);
		cl.def("countIntersections", (int (vpsc::RectangleIntersections::*)()) &vpsc::RectangleIntersections::countIntersections, "C++: vpsc::RectangleIntersections::countIntersections() --> int");
		cl.def("printIntersections", (void (vpsc::RectangleIntersections::*)()) &vpsc::RectangleIntersections::printIntersections, "C++: vpsc::RectangleIntersections::printIntersections() --> void");
		cl.def("nearest", (void (vpsc::RectangleIntersections::*)(double, double, double &, double &)) &vpsc::RectangleIntersections::nearest, "C++: vpsc::RectangleIntersections::nearest(double, double, double &, double &) --> void", pybind11::arg("x"), pybind11::arg("y"), pybind11::arg("xi"), pybind11::arg("yi"));
	}
	{ // vpsc::Rectangle file:libvpsc/rectangle.h line:78
		pybind11::class_<vpsc::Rectangle, std::shared_ptr<vpsc::Rectangle>> cl(M("vpsc"), "Rectangle", "A rectangle represents a fixed-size shape in the diagram that may\n         be moved to prevent overlaps and satisfy constraints.");
		cl.def( pybind11::init( [](double const & a0, double const & a1, double const & a2, double const & a3){ return new vpsc::Rectangle(a0, a1, a2, a3); } ), "doc" , pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y"));
		cl.def( pybind11::init<double, double, double, double, bool>(), pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y"), pybind11::arg("allowOverlap") );

		cl.def( pybind11::init( [](vpsc::Rectangle const &o){ return new vpsc::Rectangle(o); } ) );
		cl.def( pybind11::init( [](){ return new vpsc::Rectangle(); } ) );
		cl.def("isValid", (bool (vpsc::Rectangle::*)() const) &vpsc::Rectangle::isValid, "C++: vpsc::Rectangle::isValid() const --> bool");
		cl.def("unionWith", (class vpsc::Rectangle (vpsc::Rectangle::*)(const class vpsc::Rectangle &) const) &vpsc::Rectangle::unionWith, "C++: vpsc::Rectangle::unionWith(const class vpsc::Rectangle &) const --> class vpsc::Rectangle", pybind11::arg("rhs"));
		cl.def("reset", (void (vpsc::Rectangle::*)(const unsigned int, double, double)) &vpsc::Rectangle::reset, "C++: vpsc::Rectangle::reset(const unsigned int, double, double) --> void", pybind11::arg("d"), pybind11::arg("x"), pybind11::arg("X"));
		cl.def("getMaxX", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMaxX, "C++: vpsc::Rectangle::getMaxX() const --> double");
		cl.def("getMaxY", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMaxY, "C++: vpsc::Rectangle::getMaxY() const --> double");
		cl.def("getMinX", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMinX, "C++: vpsc::Rectangle::getMinX() const --> double");
		cl.def("getMinY", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMinY, "C++: vpsc::Rectangle::getMinY() const --> double");
		cl.def("getMinD", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::getMinD, "C++: vpsc::Rectangle::getMinD(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("getMaxD", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::getMaxD, "C++: vpsc::Rectangle::getMaxD(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("setMinD", (void (vpsc::Rectangle::*)(const unsigned int, const double)) &vpsc::Rectangle::setMinD, "C++: vpsc::Rectangle::setMinD(const unsigned int, const double) --> void", pybind11::arg("d"), pybind11::arg("val"));
		cl.def("setMaxD", (void (vpsc::Rectangle::*)(const unsigned int, const double)) &vpsc::Rectangle::setMaxD, "C++: vpsc::Rectangle::setMaxD(const unsigned int, const double) --> void", pybind11::arg("d"), pybind11::arg("val"));
		cl.def("getCentreX", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getCentreX, "C++: vpsc::Rectangle::getCentreX() const --> double");
		cl.def("getCentreY", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getCentreY, "C++: vpsc::Rectangle::getCentreY() const --> double");
		cl.def("getCentreD", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::getCentreD, "C++: vpsc::Rectangle::getCentreD(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("width", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::width, "C++: vpsc::Rectangle::width() const --> double");
		cl.def("height", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::height, "C++: vpsc::Rectangle::height() const --> double");
		cl.def("length", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::length, "C++: vpsc::Rectangle::length(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("set_width", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::set_width, "C++: vpsc::Rectangle::set_width(double) --> void", pybind11::arg("w"));
		cl.def("set_height", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::set_height, "C++: vpsc::Rectangle::set_height(double) --> void", pybind11::arg("h"));
		cl.def("moveCentreD", (void (vpsc::Rectangle::*)(const unsigned int, double)) &vpsc::Rectangle::moveCentreD, "C++: vpsc::Rectangle::moveCentreD(const unsigned int, double) --> void", pybind11::arg("d"), pybind11::arg("p"));
		cl.def("moveCentreX", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveCentreX, "C++: vpsc::Rectangle::moveCentreX(double) --> void", pybind11::arg("x"));
		cl.def("moveCentreY", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveCentreY, "C++: vpsc::Rectangle::moveCentreY(double) --> void", pybind11::arg("y"));
		cl.def("moveCentre", (void (vpsc::Rectangle::*)(double, double)) &vpsc::Rectangle::moveCentre, "C++: vpsc::Rectangle::moveCentre(double, double) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("moveMinX", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveMinX, "C++: vpsc::Rectangle::moveMinX(double) --> void", pybind11::arg("x"));
		cl.def("moveMinY", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveMinY, "C++: vpsc::Rectangle::moveMinY(double) --> void", pybind11::arg("y"));
		cl.def("overlapD", (double (vpsc::Rectangle::*)(const unsigned int, class vpsc::Rectangle *)) &vpsc::Rectangle::overlapD, "C++: vpsc::Rectangle::overlapD(const unsigned int, class vpsc::Rectangle *) --> double", pybind11::arg("d"), pybind11::arg("r"));
		cl.def("overlapX", (double (vpsc::Rectangle::*)(class vpsc::Rectangle *) const) &vpsc::Rectangle::overlapX, "C++: vpsc::Rectangle::overlapX(class vpsc::Rectangle *) const --> double", pybind11::arg("r"));
		cl.def("overlapY", (double (vpsc::Rectangle::*)(class vpsc::Rectangle *) const) &vpsc::Rectangle::overlapY, "C++: vpsc::Rectangle::overlapY(class vpsc::Rectangle *) const --> double", pybind11::arg("r"));
		cl.def("allowOverlap", (bool (vpsc::Rectangle::*)()) &vpsc::Rectangle::allowOverlap, "C++: vpsc::Rectangle::allowOverlap() --> bool");
		cl.def("offset", (void (vpsc::Rectangle::*)(double, double)) &vpsc::Rectangle::offset, "C++: vpsc::Rectangle::offset(double, double) --> void", pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("lineIntersections", (void (vpsc::Rectangle::*)(double, double, double, double, struct vpsc::RectangleIntersections &) const) &vpsc::Rectangle::lineIntersections, "C++: vpsc::Rectangle::lineIntersections(double, double, double, double, struct vpsc::RectangleIntersections &) const --> void", pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2"), pybind11::arg("ri"));
		cl.def("inside", (bool (vpsc::Rectangle::*)(double, double) const) &vpsc::Rectangle::inside, "C++: vpsc::Rectangle::inside(double, double) const --> bool", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("overlaps", (bool (vpsc::Rectangle::*)(double, double, double, double)) &vpsc::Rectangle::overlaps, "C++: vpsc::Rectangle::overlaps(double, double, double, double) --> bool", pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2"));
		cl.def_static("setXBorder", (void (*)(double)) &vpsc::Rectangle::setXBorder, "C++: vpsc::Rectangle::setXBorder(double) --> void", pybind11::arg("x"));
		cl.def_static("setYBorder", (void (*)(double)) &vpsc::Rectangle::setYBorder, "C++: vpsc::Rectangle::setYBorder(double) --> void", pybind11::arg("y"));
		cl.def("assign", (class vpsc::Rectangle & (vpsc::Rectangle::*)(const class vpsc::Rectangle &)) &vpsc::Rectangle::operator=, "C++: vpsc::Rectangle::operator=(const class vpsc::Rectangle &) --> class vpsc::Rectangle &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](vpsc::Rectangle const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // vpsc::delete_object file:libvpsc/rectangle.h line:295
		pybind11::class_<vpsc::delete_object, std::shared_ptr<vpsc::delete_object>> cl(M("vpsc"), "delete_object", "");
		cl.def( pybind11::init( [](){ return new vpsc::delete_object(); } ) );
	}
}
