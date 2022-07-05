#include <__tuple>
#include <exception>
#include <filesystem>
#include <functional>
#include <iterator>
#include <libavoid/connector.h>
#include <libavoid/hyperedgetree.h>
#include <map>
#include <memory>
#include <new>
#include <set>
#include <sstream> // __str__
#include <string>
#include <string_view>
#include <tuple>
#include <typeinfo>
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

// std::exception file:exception line:97
struct PyCallBack_std_exception : public std::exception {
	using std::exception::exception;

	const char * what() const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::exception *>(this), "what");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::override_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		return exception::what();
	}
};

void bind_std_exception(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::exception file:exception line:97
		pybind11::class_<std::exception, std::shared_ptr<std::exception>, PyCallBack_std_exception> cl(M("std"), "exception", "");
		cl.def( pybind11::init( [](){ return new std::exception(); }, [](){ return new PyCallBack_std_exception(); } ) );
		cl.def( pybind11::init( [](PyCallBack_std_exception const &o){ return new PyCallBack_std_exception(o); } ) );
		cl.def( pybind11::init( [](std::exception const &o){ return new std::exception(o); } ) );
		cl.def("what", (const char * (std::exception::*)() const) &std::exception::what, "C++: std::exception::what() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("assign", (class std::exception & (std::exception::*)(const class std::exception &)) &std::exception::operator=, "C++: std::exception::operator=(const class std::exception &) --> class std::exception &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
