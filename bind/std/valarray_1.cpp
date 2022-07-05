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

void bind_std_valarray_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::valarray file:valarray line:792
		pybind11::class_<std::valarray<double>, std::shared_ptr<std::valarray<double>>> cl(M("std"), "valarray_double_t", "");
		cl.def( pybind11::init( [](){ return new std::valarray<double>(); } ) );
		cl.def( pybind11::init<unsigned long>(), pybind11::arg("__n") );

		cl.def( pybind11::init<const double &, unsigned long>(), pybind11::arg("__x"), pybind11::arg("__n") );

		cl.def( pybind11::init<const double *, unsigned long>(), pybind11::arg("__p"), pybind11::arg("__n") );

		cl.def( pybind11::init( [](std::valarray<double> const &o){ return new std::valarray<double>(o); } ) );
		cl.def( pybind11::init<const class std::slice_array<double> &>(), pybind11::arg("__sa") );

		cl.def( pybind11::init<const class std::gslice_array<double> &>(), pybind11::arg("__ga") );

		cl.def( pybind11::init<const class std::mask_array<double> &>(), pybind11::arg("__ma") );

		cl.def( pybind11::init<const class std::indirect_array<double> &>(), pybind11::arg("__ia") );

		cl.def("assign", (class std::valarray<double> & (std::valarray<double>::*)(const class std::valarray<double> &)) &std::valarray<double>::operator=, "C++: std::valarray<double>::operator=(const class std::valarray<double> &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__v"));
		cl.def("assign", (class std::valarray<double> & (std::valarray<double>::*)(const double &)) &std::valarray<double>::operator=, "C++: std::valarray<double>::operator=(const double &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (class std::valarray<double> & (std::valarray<double>::*)(const class std::slice_array<double> &)) &std::valarray<double>::operator=, "C++: std::valarray<double>::operator=(const class std::slice_array<double> &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__sa"));
		cl.def("assign", (class std::valarray<double> & (std::valarray<double>::*)(const class std::gslice_array<double> &)) &std::valarray<double>::operator=, "C++: std::valarray<double>::operator=(const class std::gslice_array<double> &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__ga"));
		cl.def("assign", (class std::valarray<double> & (std::valarray<double>::*)(const class std::mask_array<double> &)) &std::valarray<double>::operator=, "C++: std::valarray<double>::operator=(const class std::mask_array<double> &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__ma"));
		cl.def("assign", (class std::valarray<double> & (std::valarray<double>::*)(const class std::indirect_array<double> &)) &std::valarray<double>::operator=, "C++: std::valarray<double>::operator=(const class std::indirect_array<double> &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__ia"));
		cl.def("__getitem__", (double & (std::valarray<double>::*)(unsigned long)) &std::valarray<double>::operator[], "C++: std::valarray<double>::operator[](unsigned long) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("__i"));
		cl.def("__getitem__", (class std::slice_array<double> (std::valarray<double>::*)(class std::slice)) &std::valarray<double>::operator[], "C++: std::valarray<double>::operator[](class std::slice) --> class std::slice_array<double>", pybind11::arg("__s"));
		cl.def("__getitem__", (class std::gslice_array<double> (std::valarray<double>::*)(const class std::gslice &)) &std::valarray<double>::operator[], "C++: std::valarray<double>::operator[](const class std::gslice &) --> class std::gslice_array<double>", pybind11::arg("__gs"));
		cl.def("__getitem__", (class std::mask_array<double> (std::valarray<double>::*)(const class std::valarray<bool> &)) &std::valarray<double>::operator[], "C++: std::valarray<double>::operator[](const class std::valarray<bool> &) --> class std::mask_array<double>", pybind11::arg("__vb"));
		cl.def("__getitem__", (class std::indirect_array<double> (std::valarray<double>::*)(const class std::valarray<unsigned long> &)) &std::valarray<double>::operator[], "C++: std::valarray<double>::operator[](const class std::valarray<unsigned long> &) --> class std::indirect_array<double>", pybind11::arg("__vs"));
		cl.def("__add__", (class std::valarray<double> (std::valarray<double>::*)() const) &std::valarray<double>::operator+, "C++: std::valarray<double>::operator+() const --> class std::valarray<double>");
		cl.def("__sub__", (class std::valarray<double> (std::valarray<double>::*)() const) &std::valarray<double>::operator-, "C++: std::valarray<double>::operator-() const --> class std::valarray<double>");
		cl.def("__imul__", (class std::valarray<double> & (std::valarray<double>::*)(const double &)) &std::valarray<double>::operator*=, "C++: std::valarray<double>::operator*=(const double &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__idiv__", (class std::valarray<double> & (std::valarray<double>::*)(const double &)) &std::valarray<double>::operator/=, "C++: std::valarray<double>::operator/=(const double &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__iadd__", (class std::valarray<double> & (std::valarray<double>::*)(const double &)) &std::valarray<double>::operator+=, "C++: std::valarray<double>::operator+=(const double &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__isub__", (class std::valarray<double> & (std::valarray<double>::*)(const double &)) &std::valarray<double>::operator-=, "C++: std::valarray<double>::operator-=(const double &) --> class std::valarray<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("swap", (void (std::valarray<double>::*)(class std::valarray<double> &)) &std::valarray<double>::swap, "C++: std::valarray<double>::swap(class std::valarray<double> &) --> void", pybind11::arg("__v"));
		cl.def("size", (unsigned long (std::valarray<double>::*)() const) &std::valarray<double>::size, "C++: std::valarray<double>::size() const --> unsigned long");
		cl.def("sum", (double (std::valarray<double>::*)() const) &std::valarray<double>::sum, "C++: std::valarray<double>::sum() const --> double");
		cl.def("min", (double (std::valarray<double>::*)() const) &std::valarray<double>::min, "C++: std::valarray<double>::min() const --> double");
		cl.def("max", (double (std::valarray<double>::*)() const) &std::valarray<double>::max, "C++: std::valarray<double>::max() const --> double");
		cl.def("shift", (class std::valarray<double> (std::valarray<double>::*)(int) const) &std::valarray<double>::shift, "C++: std::valarray<double>::shift(int) const --> class std::valarray<double>", pybind11::arg("__i"));
		cl.def("cshift", (class std::valarray<double> (std::valarray<double>::*)(int) const) &std::valarray<double>::cshift, "C++: std::valarray<double>::cshift(int) const --> class std::valarray<double>", pybind11::arg("__i"));
		cl.def("apply", (class std::valarray<double> (std::valarray<double>::*)(double (double)) const) &std::valarray<double>::apply, "C++: std::valarray<double>::apply(double (double)) const --> class std::valarray<double>", pybind11::arg("__f"));
		cl.def("apply", (class std::valarray<double> (std::valarray<double>::*)(double (const double &)) const) &std::valarray<double>::apply, "C++: std::valarray<double>::apply(double (const double &)) const --> class std::valarray<double>", pybind11::arg("__f"));
		cl.def("resize", [](std::valarray<double> &o, unsigned long const & a0) -> void { return o.resize(a0); }, "", pybind11::arg("__n"));
		cl.def("resize", (void (std::valarray<double>::*)(unsigned long, double)) &std::valarray<double>::resize, "C++: std::valarray<double>::resize(unsigned long, double) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
	}
	{ // std::slice file:valarray line:361
		pybind11::class_<std::slice, std::shared_ptr<std::slice>> cl(M("std"), "slice", "");
		cl.def( pybind11::init( [](){ return new std::slice(); } ) );
		cl.def( pybind11::init<unsigned long, unsigned long, unsigned long>(), pybind11::arg("__start"), pybind11::arg("__size"), pybind11::arg("__stride") );

		cl.def( pybind11::init( [](std::slice const &o){ return new std::slice(o); } ) );
		cl.def("start", (unsigned long (std::slice::*)() const) &std::slice::start, "C++: std::slice::start() const --> unsigned long");
		cl.def("size", (unsigned long (std::slice::*)() const) &std::slice::size, "C++: std::slice::size() const --> unsigned long");
		cl.def("stride", (unsigned long (std::slice::*)() const) &std::slice::stride, "C++: std::slice::stride() const --> unsigned long");
	}
	{ // std::slice_array file:valarray line:1149
		pybind11::class_<std::slice_array<unsigned long>, std::shared_ptr<std::slice_array<unsigned long>>> cl(M("std"), "slice_array_unsigned_long_t", "");
		cl.def( pybind11::init( [](std::slice_array<unsigned long> const &o){ return new std::slice_array<unsigned long>(o); } ) );
		cl.def("assign", (const class std::slice_array<unsigned long> & (std::slice_array<unsigned long>::*)(const class std::slice_array<unsigned long> &) const) &std::slice_array<unsigned long>::operator=, "C++: std::slice_array<unsigned long>::operator=(const class std::slice_array<unsigned long> &) const --> const class std::slice_array<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__sa"));
		cl.def("assign", (void (std::slice_array<unsigned long>::*)(const unsigned long &) const) &std::slice_array<unsigned long>::operator=, "C++: std::slice_array<unsigned long>::operator=(const unsigned long &) const --> void", pybind11::arg("__x"));
	}
	{ // std::slice_array file:valarray line:1149
		pybind11::class_<std::slice_array<bool>, std::shared_ptr<std::slice_array<bool>>> cl(M("std"), "slice_array_bool_t", "");
		cl.def( pybind11::init( [](std::slice_array<bool> const &o){ return new std::slice_array<bool>(o); } ) );
		cl.def("assign", (const class std::slice_array<bool> & (std::slice_array<bool>::*)(const class std::slice_array<bool> &) const) &std::slice_array<bool>::operator=, "C++: std::slice_array<bool>::operator=(const class std::slice_array<bool> &) const --> const class std::slice_array<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__sa"));
		cl.def("assign", (void (std::slice_array<bool>::*)(const bool &) const) &std::slice_array<bool>::operator=, "C++: std::slice_array<bool>::operator=(const bool &) const --> void", pybind11::arg("__x"));
	}
	{ // std::slice_array file:valarray line:1149
		pybind11::class_<std::slice_array<double>, std::shared_ptr<std::slice_array<double>>> cl(M("std"), "slice_array_double_t", "");
		cl.def( pybind11::init( [](std::slice_array<double> const &o){ return new std::slice_array<double>(o); } ) );
		cl.def("assign", (const class std::slice_array<double> & (std::slice_array<double>::*)(const class std::slice_array<double> &) const) &std::slice_array<double>::operator=, "C++: std::slice_array<double>::operator=(const class std::slice_array<double> &) const --> const class std::slice_array<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__sa"));
		cl.def("assign", (void (std::slice_array<double>::*)(const double &) const) &std::slice_array<double>::operator=, "C++: std::slice_array<double>::operator=(const double &) const --> void", pybind11::arg("__x"));
	}
	{ // std::gslice_array file:valarray line:1530
		pybind11::class_<std::gslice_array<unsigned long>, std::shared_ptr<std::gslice_array<unsigned long>>> cl(M("std"), "gslice_array_unsigned_long_t", "");
		cl.def( pybind11::init( [](std::gslice_array<unsigned long> const &o){ return new std::gslice_array<unsigned long>(o); } ) );
		cl.def("assign", (const class std::gslice_array<unsigned long> & (std::gslice_array<unsigned long>::*)(const class std::gslice_array<unsigned long> &) const) &std::gslice_array<unsigned long>::operator=, "C++: std::gslice_array<unsigned long>::operator=(const class std::gslice_array<unsigned long> &) const --> const class std::gslice_array<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__ga"));
		cl.def("assign", (void (std::gslice_array<unsigned long>::*)(const unsigned long &) const) &std::gslice_array<unsigned long>::operator=, "C++: std::gslice_array<unsigned long>::operator=(const unsigned long &) const --> void", pybind11::arg("__x"));
	}
	{ // std::gslice_array file:valarray line:1530
		pybind11::class_<std::gslice_array<bool>, std::shared_ptr<std::gslice_array<bool>>> cl(M("std"), "gslice_array_bool_t", "");
		cl.def( pybind11::init( [](std::gslice_array<bool> const &o){ return new std::gslice_array<bool>(o); } ) );
		cl.def("assign", (const class std::gslice_array<bool> & (std::gslice_array<bool>::*)(const class std::gslice_array<bool> &) const) &std::gslice_array<bool>::operator=, "C++: std::gslice_array<bool>::operator=(const class std::gslice_array<bool> &) const --> const class std::gslice_array<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__ga"));
		cl.def("assign", (void (std::gslice_array<bool>::*)(const bool &) const) &std::gslice_array<bool>::operator=, "C++: std::gslice_array<bool>::operator=(const bool &) const --> void", pybind11::arg("__x"));
	}
	{ // std::gslice_array file:valarray line:1530
		pybind11::class_<std::gslice_array<double>, std::shared_ptr<std::gslice_array<double>>> cl(M("std"), "gslice_array_double_t", "");
		cl.def( pybind11::init( [](std::gslice_array<double> const &o){ return new std::gslice_array<double>(o); } ) );
		cl.def("assign", (const class std::gslice_array<double> & (std::gslice_array<double>::*)(const class std::gslice_array<double> &) const) &std::gslice_array<double>::operator=, "C++: std::gslice_array<double>::operator=(const class std::gslice_array<double> &) const --> const class std::gslice_array<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__ga"));
		cl.def("assign", (void (std::gslice_array<double>::*)(const double &) const) &std::gslice_array<double>::operator=, "C++: std::gslice_array<double>::operator=(const double &) const --> void", pybind11::arg("__x"));
	}
	{ // std::mask_array file:valarray line:1865
		pybind11::class_<std::mask_array<unsigned long>, std::shared_ptr<std::mask_array<unsigned long>>> cl(M("std"), "mask_array_unsigned_long_t", "");
		cl.def( pybind11::init( [](std::mask_array<unsigned long> const &o){ return new std::mask_array<unsigned long>(o); } ) );
		cl.def("assign", (const class std::mask_array<unsigned long> & (std::mask_array<unsigned long>::*)(const class std::mask_array<unsigned long> &) const) &std::mask_array<unsigned long>::operator=, "C++: std::mask_array<unsigned long>::operator=(const class std::mask_array<unsigned long> &) const --> const class std::mask_array<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__ma"));
		cl.def("assign", (void (std::mask_array<unsigned long>::*)(const unsigned long &) const) &std::mask_array<unsigned long>::operator=, "C++: std::mask_array<unsigned long>::operator=(const unsigned long &) const --> void", pybind11::arg("__x"));
	}
	{ // std::mask_array file:valarray line:1865
		pybind11::class_<std::mask_array<bool>, std::shared_ptr<std::mask_array<bool>>> cl(M("std"), "mask_array_bool_t", "");
		cl.def( pybind11::init( [](std::mask_array<bool> const &o){ return new std::mask_array<bool>(o); } ) );
		cl.def("assign", (const class std::mask_array<bool> & (std::mask_array<bool>::*)(const class std::mask_array<bool> &) const) &std::mask_array<bool>::operator=, "C++: std::mask_array<bool>::operator=(const class std::mask_array<bool> &) const --> const class std::mask_array<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__ma"));
		cl.def("assign", (void (std::mask_array<bool>::*)(const bool &) const) &std::mask_array<bool>::operator=, "C++: std::mask_array<bool>::operator=(const bool &) const --> void", pybind11::arg("__x"));
	}
	{ // std::mask_array file:valarray line:1865
		pybind11::class_<std::mask_array<double>, std::shared_ptr<std::mask_array<double>>> cl(M("std"), "mask_array_double_t", "");
		cl.def( pybind11::init( [](std::mask_array<double> const &o){ return new std::mask_array<double>(o); } ) );
		cl.def("assign", (const class std::mask_array<double> & (std::mask_array<double>::*)(const class std::mask_array<double> &) const) &std::mask_array<double>::operator=, "C++: std::mask_array<double>::operator=(const class std::mask_array<double> &) const --> const class std::mask_array<double> &", pybind11::return_value_policy::automatic, pybind11::arg("__ma"));
		cl.def("assign", (void (std::mask_array<double>::*)(const double &) const) &std::mask_array<double>::operator=, "C++: std::mask_array<double>::operator=(const double &) const --> void", pybind11::arg("__x"));
	}
}
