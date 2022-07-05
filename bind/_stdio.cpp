#include <_ctermid.h>
#include <_ctype.h>
#include <_stdio.h>
#include <cwchar>
#include <cwctype>
#include <sstream> // __str__
#include <stdio.h>
#include <time.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind__stdio(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // __sFILE file:_stdio.h line:126
		pybind11::class_<__sFILE, std::shared_ptr<__sFILE>> cl(M(""), "__sFILE", "");
		cl.def( pybind11::init( [](){ return new __sFILE(); } ) );
		cl.def_readwrite("_r", &__sFILE::_r);
		cl.def_readwrite("_w", &__sFILE::_w);
		cl.def_readwrite("_flags", &__sFILE::_flags);
		cl.def_readwrite("_file", &__sFILE::_file);
		cl.def_readwrite("_bf", &__sFILE::_bf);
		cl.def_readwrite("_lbfsize", &__sFILE::_lbfsize);
		cl.def_readwrite("_ub", &__sFILE::_ub);
		cl.def_readwrite("_ur", &__sFILE::_ur);
		cl.def_readwrite("_lb", &__sFILE::_lb);
		cl.def_readwrite("_blksize", &__sFILE::_blksize);
		cl.def_readwrite("_offset", &__sFILE::_offset);
	}
}
