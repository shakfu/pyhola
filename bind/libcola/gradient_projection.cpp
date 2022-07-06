#include <_stdio.h>
#include <libcola/cluster.h>
#include <libcola/commondefs.h>
#include <libcola/compound_constraints.h>
#include <libcola/gradient_projection.h>
#include <libvpsc/rectangle.h>
#include <memory>
#include <sstream> // __str__
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

void bind_libcola_gradient_projection(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::GradientProjection file:libcola/gradient_projection.h line:47
		pybind11::class_<cola::GradientProjection, std::shared_ptr<cola::GradientProjection>> cl(M("cola"), "GradientProjection", "");
		cl.def( pybind11::init( [](cola::GradientProjection const &o){ return new cola::GradientProjection(o); } ) );
		cl.def_static("dumpSquareMatrix", (void (*)(const class std::valarray<double> &)) &cola::GradientProjection::dumpSquareMatrix, "C++: cola::GradientProjection::dumpSquareMatrix(const class std::valarray<double> &) --> void", pybind11::arg("L"));
		cl.def("getNumStaticVars", (unsigned int (cola::GradientProjection::*)() const) &cola::GradientProjection::getNumStaticVars, "C++: cola::GradientProjection::getNumStaticVars() const --> unsigned int");
		cl.def("solve", (unsigned int (cola::GradientProjection::*)(const class std::valarray<double> &, class std::valarray<double> &)) &cola::GradientProjection::solve, "C++: cola::GradientProjection::solve(const class std::valarray<double> &, class std::valarray<double> &) --> unsigned int", pybind11::arg("b"), pybind11::arg("x"));
		cl.def("unfixPos", (void (cola::GradientProjection::*)(unsigned int)) &cola::GradientProjection::unfixPos, "C++: cola::GradientProjection::unfixPos(unsigned int) --> void", pybind11::arg("i"));
		cl.def("fixPos", (void (cola::GradientProjection::*)(const unsigned int, const double)) &cola::GradientProjection::fixPos, "C++: cola::GradientProjection::fixPos(const unsigned int, const double) --> void", pybind11::arg("i"), pybind11::arg("pos"));
		cl.def("getDimension", (enum vpsc::Dim (cola::GradientProjection::*)() const) &cola::GradientProjection::getDimension, "C++: cola::GradientProjection::getDimension() const --> enum vpsc::Dim");
		cl.def("getFullResult", (const class std::valarray<double> & (cola::GradientProjection::*)() const) &cola::GradientProjection::getFullResult, "C++: cola::GradientProjection::getFullResult() const --> const class std::valarray<double> &", pybind11::return_value_policy::automatic);
	}
}
