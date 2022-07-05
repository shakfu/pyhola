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

void bind_std_valarray(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::valarray file:valarray line:792
		pybind11::class_<std::valarray<bool>, std::shared_ptr<std::valarray<bool>>> cl(M("std"), "valarray_bool_t", "");
		cl.def( pybind11::init( [](){ return new std::valarray<bool>(); } ) );
		cl.def( pybind11::init<unsigned long>(), pybind11::arg("__n") );

		cl.def( pybind11::init<const bool &, unsigned long>(), pybind11::arg("__x"), pybind11::arg("__n") );

		cl.def( pybind11::init<const bool *, unsigned long>(), pybind11::arg("__p"), pybind11::arg("__n") );

		cl.def( pybind11::init( [](std::valarray<bool> const &o){ return new std::valarray<bool>(o); } ) );
		cl.def( pybind11::init<const class std::slice_array<bool> &>(), pybind11::arg("__sa") );

		cl.def( pybind11::init<const class std::gslice_array<bool> &>(), pybind11::arg("__ga") );

		cl.def( pybind11::init<const class std::mask_array<bool> &>(), pybind11::arg("__ma") );

		cl.def( pybind11::init<const class std::indirect_array<bool> &>(), pybind11::arg("__ia") );

		cl.def("assign", (class std::valarray<bool> & (std::valarray<bool>::*)(const class std::valarray<bool> &)) &std::valarray<bool>::operator=, "C++: std::valarray<bool>::operator=(const class std::valarray<bool> &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__v"));
		cl.def("assign", (class std::valarray<bool> & (std::valarray<bool>::*)(const bool &)) &std::valarray<bool>::operator=, "C++: std::valarray<bool>::operator=(const bool &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (class std::valarray<bool> & (std::valarray<bool>::*)(const class std::slice_array<bool> &)) &std::valarray<bool>::operator=, "C++: std::valarray<bool>::operator=(const class std::slice_array<bool> &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__sa"));
		cl.def("assign", (class std::valarray<bool> & (std::valarray<bool>::*)(const class std::gslice_array<bool> &)) &std::valarray<bool>::operator=, "C++: std::valarray<bool>::operator=(const class std::gslice_array<bool> &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__ga"));
		cl.def("assign", (class std::valarray<bool> & (std::valarray<bool>::*)(const class std::mask_array<bool> &)) &std::valarray<bool>::operator=, "C++: std::valarray<bool>::operator=(const class std::mask_array<bool> &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__ma"));
		cl.def("assign", (class std::valarray<bool> & (std::valarray<bool>::*)(const class std::indirect_array<bool> &)) &std::valarray<bool>::operator=, "C++: std::valarray<bool>::operator=(const class std::indirect_array<bool> &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__ia"));
		cl.def("__getitem__", (bool & (std::valarray<bool>::*)(unsigned long)) &std::valarray<bool>::operator[], "C++: std::valarray<bool>::operator[](unsigned long) --> bool &", pybind11::return_value_policy::automatic, pybind11::arg("__i"));
		cl.def("__getitem__", (class std::slice_array<bool> (std::valarray<bool>::*)(class std::slice)) &std::valarray<bool>::operator[], "C++: std::valarray<bool>::operator[](class std::slice) --> class std::slice_array<bool>", pybind11::arg("__s"));
		cl.def("__getitem__", (class std::gslice_array<bool> (std::valarray<bool>::*)(const class std::gslice &)) &std::valarray<bool>::operator[], "C++: std::valarray<bool>::operator[](const class std::gslice &) --> class std::gslice_array<bool>", pybind11::arg("__gs"));
		cl.def("__getitem__", (class std::mask_array<bool> (std::valarray<bool>::*)(const class std::valarray<bool> &)) &std::valarray<bool>::operator[], "C++: std::valarray<bool>::operator[](const class std::valarray<bool> &) --> class std::mask_array<bool>", pybind11::arg("__vb"));
		cl.def("__getitem__", (class std::indirect_array<bool> (std::valarray<bool>::*)(const class std::valarray<unsigned long> &)) &std::valarray<bool>::operator[], "C++: std::valarray<bool>::operator[](const class std::valarray<unsigned long> &) --> class std::indirect_array<bool>", pybind11::arg("__vs"));
		cl.def("__add__", (class std::valarray<bool> (std::valarray<bool>::*)() const) &std::valarray<bool>::operator+, "C++: std::valarray<bool>::operator+() const --> class std::valarray<bool>");
		cl.def("__sub__", (class std::valarray<bool> (std::valarray<bool>::*)() const) &std::valarray<bool>::operator-, "C++: std::valarray<bool>::operator-() const --> class std::valarray<bool>");
		cl.def("__imul__", (class std::valarray<bool> & (std::valarray<bool>::*)(const bool &)) &std::valarray<bool>::operator*=, "C++: std::valarray<bool>::operator*=(const bool &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__idiv__", (class std::valarray<bool> & (std::valarray<bool>::*)(const bool &)) &std::valarray<bool>::operator/=, "C++: std::valarray<bool>::operator/=(const bool &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__iadd__", (class std::valarray<bool> & (std::valarray<bool>::*)(const bool &)) &std::valarray<bool>::operator+=, "C++: std::valarray<bool>::operator+=(const bool &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__isub__", (class std::valarray<bool> & (std::valarray<bool>::*)(const bool &)) &std::valarray<bool>::operator-=, "C++: std::valarray<bool>::operator-=(const bool &) --> class std::valarray<bool> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("swap", (void (std::valarray<bool>::*)(class std::valarray<bool> &)) &std::valarray<bool>::swap, "C++: std::valarray<bool>::swap(class std::valarray<bool> &) --> void", pybind11::arg("__v"));
		cl.def("size", (unsigned long (std::valarray<bool>::*)() const) &std::valarray<bool>::size, "C++: std::valarray<bool>::size() const --> unsigned long");
		cl.def("sum", (bool (std::valarray<bool>::*)() const) &std::valarray<bool>::sum, "C++: std::valarray<bool>::sum() const --> bool");
		cl.def("min", (bool (std::valarray<bool>::*)() const) &std::valarray<bool>::min, "C++: std::valarray<bool>::min() const --> bool");
		cl.def("max", (bool (std::valarray<bool>::*)() const) &std::valarray<bool>::max, "C++: std::valarray<bool>::max() const --> bool");
		cl.def("shift", (class std::valarray<bool> (std::valarray<bool>::*)(int) const) &std::valarray<bool>::shift, "C++: std::valarray<bool>::shift(int) const --> class std::valarray<bool>", pybind11::arg("__i"));
		cl.def("cshift", (class std::valarray<bool> (std::valarray<bool>::*)(int) const) &std::valarray<bool>::cshift, "C++: std::valarray<bool>::cshift(int) const --> class std::valarray<bool>", pybind11::arg("__i"));
		cl.def("apply", (class std::valarray<bool> (std::valarray<bool>::*)(bool (bool)) const) &std::valarray<bool>::apply, "C++: std::valarray<bool>::apply(bool (bool)) const --> class std::valarray<bool>", pybind11::arg("__f"));
		cl.def("apply", (class std::valarray<bool> (std::valarray<bool>::*)(bool (const bool &)) const) &std::valarray<bool>::apply, "C++: std::valarray<bool>::apply(bool (const bool &)) const --> class std::valarray<bool>", pybind11::arg("__f"));
		cl.def("resize", [](std::valarray<bool> &o, unsigned long const & a0) -> void { return o.resize(a0); }, "", pybind11::arg("__n"));
		cl.def("resize", (void (std::valarray<bool>::*)(unsigned long, bool)) &std::valarray<bool>::resize, "C++: std::valarray<bool>::resize(unsigned long, bool) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
	}
	{ // std::valarray file:valarray line:792
		pybind11::class_<std::valarray<unsigned long>, std::shared_ptr<std::valarray<unsigned long>>> cl(M("std"), "valarray_unsigned_long_t", "");
		cl.def( pybind11::init( [](){ return new std::valarray<unsigned long>(); } ) );
		cl.def( pybind11::init<unsigned long>(), pybind11::arg("__n") );

		cl.def( pybind11::init<const unsigned long &, unsigned long>(), pybind11::arg("__x"), pybind11::arg("__n") );

		cl.def( pybind11::init<const unsigned long *, unsigned long>(), pybind11::arg("__p"), pybind11::arg("__n") );

		cl.def( pybind11::init( [](std::valarray<unsigned long> const &o){ return new std::valarray<unsigned long>(o); } ) );
		cl.def( pybind11::init<const class std::slice_array<unsigned long> &>(), pybind11::arg("__sa") );

		cl.def( pybind11::init<const class std::gslice_array<unsigned long> &>(), pybind11::arg("__ga") );

		cl.def( pybind11::init<const class std::mask_array<unsigned long> &>(), pybind11::arg("__ma") );

		cl.def( pybind11::init<const class std::indirect_array<unsigned long> &>(), pybind11::arg("__ia") );

		cl.def("assign", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const class std::valarray<unsigned long> &)) &std::valarray<unsigned long>::operator=, "C++: std::valarray<unsigned long>::operator=(const class std::valarray<unsigned long> &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__v"));
		cl.def("assign", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const unsigned long &)) &std::valarray<unsigned long>::operator=, "C++: std::valarray<unsigned long>::operator=(const unsigned long &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const class std::slice_array<unsigned long> &)) &std::valarray<unsigned long>::operator=, "C++: std::valarray<unsigned long>::operator=(const class std::slice_array<unsigned long> &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__sa"));
		cl.def("assign", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const class std::gslice_array<unsigned long> &)) &std::valarray<unsigned long>::operator=, "C++: std::valarray<unsigned long>::operator=(const class std::gslice_array<unsigned long> &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__ga"));
		cl.def("assign", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const class std::mask_array<unsigned long> &)) &std::valarray<unsigned long>::operator=, "C++: std::valarray<unsigned long>::operator=(const class std::mask_array<unsigned long> &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__ma"));
		cl.def("assign", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const class std::indirect_array<unsigned long> &)) &std::valarray<unsigned long>::operator=, "C++: std::valarray<unsigned long>::operator=(const class std::indirect_array<unsigned long> &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__ia"));
		cl.def("__getitem__", (unsigned long & (std::valarray<unsigned long>::*)(unsigned long)) &std::valarray<unsigned long>::operator[], "C++: std::valarray<unsigned long>::operator[](unsigned long) --> unsigned long &", pybind11::return_value_policy::automatic, pybind11::arg("__i"));
		cl.def("__getitem__", (class std::slice_array<unsigned long> (std::valarray<unsigned long>::*)(class std::slice)) &std::valarray<unsigned long>::operator[], "C++: std::valarray<unsigned long>::operator[](class std::slice) --> class std::slice_array<unsigned long>", pybind11::arg("__s"));
		cl.def("__getitem__", (class std::gslice_array<unsigned long> (std::valarray<unsigned long>::*)(const class std::gslice &)) &std::valarray<unsigned long>::operator[], "C++: std::valarray<unsigned long>::operator[](const class std::gslice &) --> class std::gslice_array<unsigned long>", pybind11::arg("__gs"));
		cl.def("__getitem__", (class std::mask_array<unsigned long> (std::valarray<unsigned long>::*)(const class std::valarray<bool> &)) &std::valarray<unsigned long>::operator[], "C++: std::valarray<unsigned long>::operator[](const class std::valarray<bool> &) --> class std::mask_array<unsigned long>", pybind11::arg("__vb"));
		cl.def("__getitem__", (class std::indirect_array<unsigned long> (std::valarray<unsigned long>::*)(const class std::valarray<unsigned long> &)) &std::valarray<unsigned long>::operator[], "C++: std::valarray<unsigned long>::operator[](const class std::valarray<unsigned long> &) --> class std::indirect_array<unsigned long>", pybind11::arg("__vs"));
		cl.def("__add__", (class std::valarray<unsigned long> (std::valarray<unsigned long>::*)() const) &std::valarray<unsigned long>::operator+, "C++: std::valarray<unsigned long>::operator+() const --> class std::valarray<unsigned long>");
		cl.def("__sub__", (class std::valarray<unsigned long> (std::valarray<unsigned long>::*)() const) &std::valarray<unsigned long>::operator-, "C++: std::valarray<unsigned long>::operator-() const --> class std::valarray<unsigned long>");
		cl.def("__imul__", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const unsigned long &)) &std::valarray<unsigned long>::operator*=, "C++: std::valarray<unsigned long>::operator*=(const unsigned long &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__idiv__", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const unsigned long &)) &std::valarray<unsigned long>::operator/=, "C++: std::valarray<unsigned long>::operator/=(const unsigned long &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__iadd__", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const unsigned long &)) &std::valarray<unsigned long>::operator+=, "C++: std::valarray<unsigned long>::operator+=(const unsigned long &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("__isub__", (class std::valarray<unsigned long> & (std::valarray<unsigned long>::*)(const unsigned long &)) &std::valarray<unsigned long>::operator-=, "C++: std::valarray<unsigned long>::operator-=(const unsigned long &) --> class std::valarray<unsigned long> &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("swap", (void (std::valarray<unsigned long>::*)(class std::valarray<unsigned long> &)) &std::valarray<unsigned long>::swap, "C++: std::valarray<unsigned long>::swap(class std::valarray<unsigned long> &) --> void", pybind11::arg("__v"));
		cl.def("size", (unsigned long (std::valarray<unsigned long>::*)() const) &std::valarray<unsigned long>::size, "C++: std::valarray<unsigned long>::size() const --> unsigned long");
		cl.def("sum", (unsigned long (std::valarray<unsigned long>::*)() const) &std::valarray<unsigned long>::sum, "C++: std::valarray<unsigned long>::sum() const --> unsigned long");
		cl.def("min", (unsigned long (std::valarray<unsigned long>::*)() const) &std::valarray<unsigned long>::min, "C++: std::valarray<unsigned long>::min() const --> unsigned long");
		cl.def("max", (unsigned long (std::valarray<unsigned long>::*)() const) &std::valarray<unsigned long>::max, "C++: std::valarray<unsigned long>::max() const --> unsigned long");
		cl.def("shift", (class std::valarray<unsigned long> (std::valarray<unsigned long>::*)(int) const) &std::valarray<unsigned long>::shift, "C++: std::valarray<unsigned long>::shift(int) const --> class std::valarray<unsigned long>", pybind11::arg("__i"));
		cl.def("cshift", (class std::valarray<unsigned long> (std::valarray<unsigned long>::*)(int) const) &std::valarray<unsigned long>::cshift, "C++: std::valarray<unsigned long>::cshift(int) const --> class std::valarray<unsigned long>", pybind11::arg("__i"));
		cl.def("apply", (class std::valarray<unsigned long> (std::valarray<unsigned long>::*)(unsigned long (unsigned long)) const) &std::valarray<unsigned long>::apply, "C++: std::valarray<unsigned long>::apply(unsigned long (unsigned long)) const --> class std::valarray<unsigned long>", pybind11::arg("__f"));
		cl.def("apply", (class std::valarray<unsigned long> (std::valarray<unsigned long>::*)(unsigned long (const unsigned long &)) const) &std::valarray<unsigned long>::apply, "C++: std::valarray<unsigned long>::apply(unsigned long (const unsigned long &)) const --> class std::valarray<unsigned long>", pybind11::arg("__f"));
		cl.def("resize", [](std::valarray<unsigned long> &o, unsigned long const & a0) -> void { return o.resize(a0); }, "", pybind11::arg("__n"));
		cl.def("resize", (void (std::valarray<unsigned long>::*)(unsigned long, unsigned long)) &std::valarray<unsigned long>::resize, "C++: std::valarray<unsigned long>::resize(unsigned long, unsigned long) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
	}
}
