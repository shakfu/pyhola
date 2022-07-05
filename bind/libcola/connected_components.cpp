#include <libcola/connected_components.h>
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

void bind_libcola_connected_components(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::Component file:libcola/connected_components.h line:30
		pybind11::class_<cola::Component, std::shared_ptr<cola::Component>> cl(M("cola"), "Component", "");
		cl.def( pybind11::init( [](){ return new cola::Component(); } ) );
		cl.def( pybind11::init( [](cola::Component const &o){ return new cola::Component(o); } ) );
		cl.def_readwrite("node_ids", &cola::Component::node_ids);
		cl.def_readwrite("rects", &cola::Component::rects);
		cl.def_readwrite("edges", &cola::Component::edges);
		cl.def("moveRectangles", (void (cola::Component::*)(double, double)) &cola::Component::moveRectangles, "C++: cola::Component::moveRectangles(double, double) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("getBoundingBox", (class vpsc::Rectangle * (cola::Component::*)()) &cola::Component::getBoundingBox, "C++: cola::Component::getBoundingBox() --> class vpsc::Rectangle *", pybind11::return_value_policy::automatic);
	}
}
