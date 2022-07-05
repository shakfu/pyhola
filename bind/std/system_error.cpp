#include <memory>
#include <sstream> // __str__
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// std::error_category file:system_error line:196
struct PyCallBack_std_error_category : public std::error_category {
	using std::error_category::error_category;

	const char * name() const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::error_category *>(this), "name");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::override_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"error_category::name\"");
	}
	class std::error_condition default_error_condition(int a0) const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::error_category *>(this), "default_error_condition");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<class std::error_condition>::value) {
				static pybind11::detail::override_caster_t<class std::error_condition> caster;
				return pybind11::detail::cast_ref<class std::error_condition>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::error_condition>(std::move(o));
		}
		return error_category::default_error_condition(a0);
	}
	bool equivalent(int a0, const class std::error_condition & a1) const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::error_category *>(this), "equivalent");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return error_category::equivalent(a0, a1);
	}
	bool equivalent(const class std::error_code & a0, int a1) const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::error_category *>(this), "equivalent");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return error_category::equivalent(a0, a1);
	}
	std::string message(int a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::error_category *>(this), "message");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"error_category::message\"");
	}
};

// std::system_error file:system_error line:461
struct PyCallBack_std_system_error : public std::system_error {
	using std::system_error::system_error;

	const char * what() const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::system_error *>(this), "what");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::override_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		return runtime_error::what();
	}
};

void bind_std_system_error(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::error_category file:system_error line:196
		pybind11::class_<std::error_category, std::shared_ptr<std::error_category>, PyCallBack_std_error_category> cl(M("std"), "error_category", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_std_error_category(); } ) );
		cl.def("name", (const char * (std::error_category::*)() const) &std::error_category::name, "C++: std::error_category::name() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("default_error_condition", (class std::error_condition (std::error_category::*)(int) const) &std::error_category::default_error_condition, "C++: std::error_category::default_error_condition(int) const --> class std::error_condition", pybind11::arg("__ev"));
		cl.def("equivalent", (bool (std::error_category::*)(int, const class std::error_condition &) const) &std::error_category::equivalent, "C++: std::error_category::equivalent(int, const class std::error_condition &) const --> bool", pybind11::arg("__code"), pybind11::arg("__condition"));
		cl.def("equivalent", (bool (std::error_category::*)(const class std::error_code &, int) const) &std::error_category::equivalent, "C++: std::error_category::equivalent(const class std::error_code &, int) const --> bool", pybind11::arg("__code"), pybind11::arg("__condition"));
		cl.def("message", (std::string (std::error_category::*)(int) const) &std::error_category::message, "C++: std::error_category::message(int) const --> std::string", pybind11::arg("__ev"));
		cl.def("__eq__", (bool (std::error_category::*)(const class std::error_category &) const) &std::error_category::operator==, "C++: std::error_category::operator==(const class std::error_category &) const --> bool", pybind11::arg("__rhs"));
		cl.def("__ne__", (bool (std::error_category::*)(const class std::error_category &) const) &std::error_category::operator!=, "C++: std::error_category::operator!=(const class std::error_category &) const --> bool", pybind11::arg("__rhs"));
	}
	{ // std::error_condition file:system_error line:241
		pybind11::class_<std::error_condition, std::shared_ptr<std::error_condition>> cl(M("std"), "error_condition", "");
		cl.def( pybind11::init( [](){ return new std::error_condition(); } ) );
		cl.def( pybind11::init<int, const class std::error_category &>(), pybind11::arg("__val"), pybind11::arg("__cat") );

		cl.def( pybind11::init( [](std::error_condition const &o){ return new std::error_condition(o); } ) );
		cl.def("assign", (void (std::error_condition::*)(int, const class std::error_category &)) &std::error_condition::assign, "C++: std::error_condition::assign(int, const class std::error_category &) --> void", pybind11::arg("__val"), pybind11::arg("__cat"));
		cl.def("clear", (void (std::error_condition::*)()) &std::error_condition::clear, "C++: std::error_condition::clear() --> void");
		cl.def("value", (int (std::error_condition::*)() const) &std::error_condition::value, "C++: std::error_condition::value() const --> int");
		cl.def("category", (const class std::error_category & (std::error_condition::*)() const) &std::error_condition::category, "C++: std::error_condition::category() const --> const class std::error_category &", pybind11::return_value_policy::automatic);
		cl.def("message", (std::string (std::error_condition::*)() const) &std::error_condition::message, "C++: std::error_condition::message() const --> std::string");
	}
	{ // std::error_code file:system_error line:313
		pybind11::class_<std::error_code, std::shared_ptr<std::error_code>> cl(M("std"), "error_code", "");
		cl.def( pybind11::init( [](){ return new std::error_code(); } ) );
		cl.def( pybind11::init<int, const class std::error_category &>(), pybind11::arg("__val"), pybind11::arg("__cat") );

		cl.def( pybind11::init( [](std::error_code const &o){ return new std::error_code(o); } ) );
		cl.def("assign", (void (std::error_code::*)(int, const class std::error_category &)) &std::error_code::assign, "C++: std::error_code::assign(int, const class std::error_category &) --> void", pybind11::arg("__val"), pybind11::arg("__cat"));
		cl.def("clear", (void (std::error_code::*)()) &std::error_code::clear, "C++: std::error_code::clear() --> void");
		cl.def("value", (int (std::error_code::*)() const) &std::error_code::value, "C++: std::error_code::value() const --> int");
		cl.def("category", (const class std::error_category & (std::error_code::*)() const) &std::error_code::category, "C++: std::error_code::category() const --> const class std::error_category &", pybind11::return_value_policy::automatic);
		cl.def("default_error_condition", (class std::error_condition (std::error_code::*)() const) &std::error_code::default_error_condition, "C++: std::error_code::default_error_condition() const --> class std::error_condition");
		cl.def("message", (std::string (std::error_code::*)() const) &std::error_code::message, "C++: std::error_code::message() const --> std::string");
		cl.def("assign", (class std::error_code & (std::error_code::*)(const class std::error_code &)) &std::error_code::operator=, "C++: std::error_code::operator=(const class std::error_code &) --> class std::error_code &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // std::system_error file:system_error line:461
		pybind11::class_<std::system_error, std::shared_ptr<std::system_error>, PyCallBack_std_system_error, std::runtime_error> cl(M("std"), "system_error", "");
		cl.def( pybind11::init<class std::error_code, const std::string &>(), pybind11::arg("__ec"), pybind11::arg("__what_arg") );

		cl.def( pybind11::init<class std::error_code, const char *>(), pybind11::arg("__ec"), pybind11::arg("__what_arg") );

		cl.def( pybind11::init<class std::error_code>(), pybind11::arg("__ec") );

		cl.def( pybind11::init<int, const class std::error_category &, const std::string &>(), pybind11::arg("__ev"), pybind11::arg("__ecat"), pybind11::arg("__what_arg") );

		cl.def( pybind11::init<int, const class std::error_category &, const char *>(), pybind11::arg("__ev"), pybind11::arg("__ecat"), pybind11::arg("__what_arg") );

		cl.def( pybind11::init<int, const class std::error_category &>(), pybind11::arg("__ev"), pybind11::arg("__ecat") );

		cl.def( pybind11::init( [](PyCallBack_std_system_error const &o){ return new PyCallBack_std_system_error(o); } ) );
		cl.def( pybind11::init( [](std::system_error const &o){ return new std::system_error(o); } ) );
		cl.def("code", (const class std::error_code & (std::system_error::*)() const) &std::system_error::code, "C++: std::system_error::code() const --> const class std::error_code &", pybind11::return_value_policy::automatic);
		cl.def("assign", (class std::system_error & (std::system_error::*)(const class std::system_error &)) &std::system_error::operator=, "C++: std::system_error::operator=(const class std::system_error &) --> class std::system_error &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
