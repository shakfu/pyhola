#include <_stdio.h>
#include <memory>
#include <sstream> // __str__
#include <utility>
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

void bind_unknown_unknown_10(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // straightener::Route file: line:39
		pybind11::class_<straightener::Route, std::shared_ptr<straightener::Route>> cl(M("straightener"), "Route", "");
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("n") );

		cl.def( pybind11::init( [](straightener::Route const &o){ return new straightener::Route(o); } ) );
		cl.def_readwrite("n", &straightener::Route::n);
		cl.def("print", (void (straightener::Route::*)()) &straightener::Route::print, "C++: straightener::Route::print() --> void");
		cl.def("boundingBox", (void (straightener::Route::*)(double &, double &, double &, double &)) &straightener::Route::boundingBox, "C++: straightener::Route::boundingBox(double &, double &, double &, double &) --> void", pybind11::arg("xmin"), pybind11::arg("ymin"), pybind11::arg("xmax"), pybind11::arg("ymax"));
		cl.def("routeLength", (double (straightener::Route::*)() const) &straightener::Route::routeLength, "C++: straightener::Route::routeLength() const --> double");
		cl.def("rerouteAround", (void (straightener::Route::*)(class vpsc::Rectangle *)) &straightener::Route::rerouteAround, "C++: straightener::Route::rerouteAround(class vpsc::Rectangle *) --> void", pybind11::arg("rect"));
	}
}
