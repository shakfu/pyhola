#include <sstream> // __str__
#include <valarray>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_std_valarray_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::indirect_array file:valarray line:2221
		pybind11::class_<std::indirect_array<unsigned long>, std::shared_ptr<std::indirect_array<unsigned long>>> cl(M("std"), "indirect_array_unsigned_long_t", "");
		cl.def( pybind11::init( [](std::indirect_array<unsigned long> const &o){ return new std::indirect_array<unsigned long>(o); } ) );
		cl.def("assign", (const class std::indirect_array<unsigned long> & (std::indirect_array<unsigned long>::*)(const class std::indirect_array<unsigned long> &) const) &std::indirect_array<unsigned long>::operator=, "C++: std::indirect_array<unsigned long>::operator=(const class std::indirect_array<unsigned long> &) const --> const class std::indirect_array<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__ia"));
		cl.def("assign", (void (std::indirect_array<unsigned long>::*)(const unsigned long &) const) &std::indirect_array<unsigned long>::operator=, "C++: std::indirect_array<unsigned long>::operator=(const unsigned long &) const --> void", pybind11::arg("__x"));
	}
	{ // std::indirect_array file:valarray line:2221
		pybind11::class_<std::indirect_array<bool>, std::shared_ptr<std::indirect_array<bool>>> cl(M("std"), "indirect_array_bool_t", "");
		cl.def( pybind11::init( [](std::indirect_array<bool> const &o){ return new std::indirect_array<bool>(o); } ) );
		cl.def("assign", (const class std::indirect_array<bool> & (std::indirect_array<bool>::*)(const class std::indirect_array<bool> &) const) &std::indirect_array<bool>::operator=, "C++: std::indirect_array<bool>::operator=(const class std::indirect_array<bool> &) const --> const class std::indirect_array<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__ia"));
		cl.def("assign", (void (std::indirect_array<bool>::*)(const bool &) const) &std::indirect_array<bool>::operator=, "C++: std::indirect_array<bool>::operator=(const bool &) const --> void", pybind11::arg("__x"));
	}
	{ // std::indirect_array file:valarray line:2221
		pybind11::class_<std::indirect_array<double>, std::shared_ptr<std::indirect_array<double>>> cl(M("std"), "indirect_array_double_t", "");
		cl.def( pybind11::init( [](std::indirect_array<double> const &o){ return new std::indirect_array<double>(o); } ) );
		cl.def("assign", (const class std::indirect_array<double> & (std::indirect_array<double>::*)(const class std::indirect_array<double> &) const) &std::indirect_array<double>::operator=, "C++: std::indirect_array<double>::operator=(const class std::indirect_array<double> &) const --> const class std::indirect_array<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__ia"));
		cl.def("assign", (void (std::indirect_array<double>::*)(const double &) const) &std::indirect_array<double>::operator=, "C++: std::indirect_array<double>::operator=(const double &) const --> void", pybind11::arg("__x"));
	}
	{ // std::gslice file:valarray line:1468
		pybind11::class_<std::gslice, std::shared_ptr<std::gslice>> cl(M("std"), "gslice", "");
		cl.def( pybind11::init( [](){ return new std::gslice(); } ) );
		cl.def( pybind11::init<unsigned long, const class std::valarray<unsigned long> &, const class std::valarray<unsigned long> &>(), pybind11::arg("__start"), pybind11::arg("__size"), pybind11::arg("__stride") );

		cl.def( pybind11::init( [](std::gslice const &o){ return new std::gslice(o); } ) );
		cl.def("start", (unsigned long (std::gslice::*)() const) &std::gslice::start, "C++: std::gslice::start() const --> unsigned long");
		cl.def("size", (class std::valarray<unsigned long> (std::gslice::*)() const) &std::gslice::size, "C++: std::gslice::size() const --> class std::valarray<unsigned long>");
		cl.def("stride", (class std::valarray<unsigned long> (std::gslice::*)() const) &std::gslice::stride, "C++: std::gslice::stride() const --> class std::valarray<unsigned long>");
	}
}
