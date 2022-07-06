#include <_stdio.h>
#include <libcola/box.h>
#include <libvpsc/rectangle.h>
#include <memory>
#include <sstream> // __str__
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

void bind_libcola_box(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::Box file:libcola/box.h line:37
		pybind11::class_<cola::Box, std::shared_ptr<cola::Box>> cl(M("cola"), "Box", "A box consisting of four edge values for representing padding or \n        margins for rectangles.");
		cl.def( pybind11::init<double, double, double, double>(), pybind11::arg("xMin"), pybind11::arg("xMax"), pybind11::arg("yMin"), pybind11::arg("yMax") );

		cl.def( pybind11::init<double>(), pybind11::arg("all") );

		cl.def( pybind11::init( [](){ return new cola::Box(); } ) );
		cl.def( pybind11::init( [](cola::Box const &o){ return new cola::Box(o); } ) );
		cl.def("empty", (bool (cola::Box::*)() const) &cola::Box::empty, "C++: cola::Box::empty() const --> bool");
		cl.def("min", (double (cola::Box::*)(unsigned long) const) &cola::Box::min, "C++: cola::Box::min(unsigned long) const --> double", pybind11::arg("dim"));
		cl.def("max", (double (cola::Box::*)(unsigned long) const) &cola::Box::max, "C++: cola::Box::max(unsigned long) const --> double", pybind11::arg("dim"));
		cl.def("outputCode", (void (cola::Box::*)(struct __sFILE *) const) &cola::Box::outputCode, "C++: cola::Box::outputCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("rectangleByApplyingBox", (class vpsc::Rectangle (cola::Box::*)(const class vpsc::Rectangle) const) &cola::Box::rectangleByApplyingBox, "C++: cola::Box::rectangleByApplyingBox(const class vpsc::Rectangle) const --> class vpsc::Rectangle", pybind11::arg("rectangle"));
		cl.def("assign", (class cola::Box & (cola::Box::*)(const class cola::Box &)) &cola::Box::operator=, "C++: cola::Box::operator=(const class cola::Box &) --> class cola::Box &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
