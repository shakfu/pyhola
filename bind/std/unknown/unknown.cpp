#include <ios>
#include <locale>
#include <memory>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
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

// std::basic_streambuf file: line:489
struct PyCallBack_std_streambuf : public std::streambuf {
	using std::streambuf::basic_streambuf;

	void imbue(const class std::locale & a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "imbue");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return basic_streambuf::imbue(a0);
	}
	class std::basic_streambuf<char> * setbuf(char * a0, long a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "setbuf");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<class std::basic_streambuf<char> *>::value) {
				static pybind11::detail::override_caster_t<class std::basic_streambuf<char> *> caster;
				return pybind11::detail::cast_ref<class std::basic_streambuf<char> *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::basic_streambuf<char> *>(std::move(o));
		}
		return basic_streambuf::setbuf(a0, a1);
	}
	class std::fpos<__mbstate_t> seekoff(long long a0, enum std::ios_base::seekdir a1, unsigned int a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "seekoff");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<class std::fpos<__mbstate_t>>::value) {
				static pybind11::detail::override_caster_t<class std::fpos<__mbstate_t>> caster;
				return pybind11::detail::cast_ref<class std::fpos<__mbstate_t>>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::fpos<__mbstate_t>>(std::move(o));
		}
		return basic_streambuf::seekoff(a0, a1, a2);
	}
	class std::fpos<__mbstate_t> seekpos(class std::fpos<__mbstate_t> a0, unsigned int a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "seekpos");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<class std::fpos<__mbstate_t>>::value) {
				static pybind11::detail::override_caster_t<class std::fpos<__mbstate_t>> caster;
				return pybind11::detail::cast_ref<class std::fpos<__mbstate_t>>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::fpos<__mbstate_t>>(std::move(o));
		}
		return basic_streambuf::seekpos(a0, a1);
	}
	int sync() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "sync");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::sync();
	}
	long showmanyc() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "showmanyc");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::override_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::showmanyc();
	}
	long xsgetn(char * a0, long a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "xsgetn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::override_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::xsgetn(a0, a1);
	}
	int underflow() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "underflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::underflow();
	}
	int uflow() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "uflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::uflow();
	}
	int pbackfail(int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "pbackfail");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::pbackfail(a0);
	}
	long xsputn(const char * a0, long a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "xsputn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::override_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::xsputn(a0, a1);
	}
	int overflow(int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "overflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::overflow(a0);
	}
};

// std::ios_base::failure file:ios line:428
struct PyCallBack_std_ios_base_failure : public std::ios_base::failure {
	using std::ios_base::failure::failure;

	const char * what() const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::ios_base::failure *>(this), "what");
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

void bind_std_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::basic_streambuf file: line:489
		pybind11::class_<std::streambuf, std::shared_ptr<std::streambuf>, PyCallBack_std_streambuf> cl(M("std"), "streambuf", "");
		cl.def("pubimbue", (class std::locale (std::streambuf::*)(const class std::locale &)) &std::basic_streambuf<char, std::char_traits<char> >::pubimbue, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubimbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("getloc", (class std::locale (std::streambuf::*)() const) &std::basic_streambuf<char, std::char_traits<char> >::getloc, "C++: std::basic_streambuf<char, std::char_traits<char> >::getloc() const --> class std::locale");
		cl.def("pubsetbuf", (class std::basic_streambuf<char> * (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf(char *, long) --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("pubseekoff", [](std::streambuf &o, long long const & a0, enum std::ios_base::seekdir const & a1) -> std::fpos<__mbstate_t> { return o.pubseekoff(a0, a1); }, "", pybind11::arg("__off"), pybind11::arg("__way"));
		cl.def("pubseekoff", (class std::fpos<__mbstate_t> (std::streambuf::*)(long long, enum std::ios_base::seekdir, unsigned int)) &std::basic_streambuf<char, std::char_traits<char> >::pubseekoff, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubseekoff(long long, enum std::ios_base::seekdir, unsigned int) --> class std::fpos<__mbstate_t>", pybind11::arg("__off"), pybind11::arg("__way"), pybind11::arg("__which"));
		cl.def("pubseekpos", [](std::streambuf &o, class std::fpos<__mbstate_t> const & a0) -> std::fpos<__mbstate_t> { return o.pubseekpos(a0); }, "", pybind11::arg("__sp"));
		cl.def("pubseekpos", (class std::fpos<__mbstate_t> (std::streambuf::*)(class std::fpos<__mbstate_t>, unsigned int)) &std::basic_streambuf<char, std::char_traits<char> >::pubseekpos, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubseekpos(class std::fpos<__mbstate_t>, unsigned int) --> class std::fpos<__mbstate_t>", pybind11::arg("__sp"), pybind11::arg("__which"));
		cl.def("pubsync", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::pubsync, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsync() --> int");
		cl.def("in_avail", (long (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::in_avail, "C++: std::basic_streambuf<char, std::char_traits<char> >::in_avail() --> long");
		cl.def("snextc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::snextc, "C++: std::basic_streambuf<char, std::char_traits<char> >::snextc() --> int");
		cl.def("sbumpc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sbumpc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sbumpc() --> int");
		cl.def("sgetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sgetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetc() --> int");
		cl.def("sgetn", (long (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sgetn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetn(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("sputbackc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputbackc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputbackc(char) --> int", pybind11::arg("__c"));
		cl.def("sungetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sungetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sungetc() --> int");
		cl.def("sputc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputc(char) --> int", pybind11::arg("__c"));
		cl.def("sputn", (long (std::streambuf::*)(const char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sputn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputn(const char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
	}
	{ // std::ios_base file:ios line:230
		pybind11::class_<std::ios_base, std::shared_ptr<std::ios_base>> cl(M("std"), "ios_base", "");

		pybind11::enum_<std::__1::ios_base::seekdir>(cl, "seekdir", pybind11::arithmetic(), "")
			.value("beg", std::__1::ios_base::beg)
			.value("cur", std::__1::ios_base::cur)
			.value("end", std::__1::ios_base::end)
			.export_values();


		pybind11::enum_<std::__1::ios_base::event>(cl, "event", pybind11::arithmetic(), "")
			.value("erase_event", std::__1::ios_base::erase_event)
			.value("imbue_event", std::__1::ios_base::imbue_event)
			.value("copyfmt_event", std::__1::ios_base::copyfmt_event)
			.export_values();

		cl.def("flags", (unsigned int (std::ios_base::*)() const) &std::ios_base::flags, "C++: std::ios_base::flags() const --> unsigned int");
		cl.def("flags", (unsigned int (std::ios_base::*)(unsigned int)) &std::ios_base::flags, "C++: std::ios_base::flags(unsigned int) --> unsigned int", pybind11::arg("__fmtfl"));
		cl.def("setf", (unsigned int (std::ios_base::*)(unsigned int)) &std::ios_base::setf, "C++: std::ios_base::setf(unsigned int) --> unsigned int", pybind11::arg("__fmtfl"));
		cl.def("setf", (unsigned int (std::ios_base::*)(unsigned int, unsigned int)) &std::ios_base::setf, "C++: std::ios_base::setf(unsigned int, unsigned int) --> unsigned int", pybind11::arg("__fmtfl"), pybind11::arg("__mask"));
		cl.def("unsetf", (void (std::ios_base::*)(unsigned int)) &std::ios_base::unsetf, "C++: std::ios_base::unsetf(unsigned int) --> void", pybind11::arg("__mask"));
		cl.def("precision", (long (std::ios_base::*)() const) &std::ios_base::precision, "C++: std::ios_base::precision() const --> long");
		cl.def("precision", (long (std::ios_base::*)(long)) &std::ios_base::precision, "C++: std::ios_base::precision(long) --> long", pybind11::arg("__prec"));
		cl.def("width", (long (std::ios_base::*)() const) &std::ios_base::width, "C++: std::ios_base::width() const --> long");
		cl.def("width", (long (std::ios_base::*)(long)) &std::ios_base::width, "C++: std::ios_base::width(long) --> long", pybind11::arg("__wide"));
		cl.def("imbue", (class std::locale (std::ios_base::*)(const class std::locale &)) &std::ios_base::imbue, "C++: std::ios_base::imbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("getloc", (class std::locale (std::ios_base::*)() const) &std::ios_base::getloc, "C++: std::ios_base::getloc() const --> class std::locale");
		cl.def_static("xalloc", (int (*)()) &std::ios_base::xalloc, "C++: std::ios_base::xalloc() --> int");
		cl.def("iword", (long & (std::ios_base::*)(int)) &std::ios_base::iword, "C++: std::ios_base::iword(int) --> long &", pybind11::return_value_policy::automatic, pybind11::arg("__index"));
		cl.def("pword", (void *& (std::ios_base::*)(int)) &std::ios_base::pword, "C++: std::ios_base::pword(int) --> void *&", pybind11::return_value_policy::automatic, pybind11::arg("__index"));
		cl.def_static("sync_with_stdio", []() -> bool { return std::ios_base::sync_with_stdio(); }, "");
		cl.def_static("sync_with_stdio", (bool (*)(bool)) &std::ios_base::sync_with_stdio, "C++: std::ios_base::sync_with_stdio(bool) --> bool", pybind11::arg("__sync"));
		cl.def("rdstate", (unsigned int (std::ios_base::*)() const) &std::ios_base::rdstate, "C++: std::ios_base::rdstate() const --> unsigned int");
		cl.def("clear", [](std::ios_base &o) -> void { return o.clear(); }, "");
		cl.def("clear", (void (std::ios_base::*)(unsigned int)) &std::ios_base::clear, "C++: std::ios_base::clear(unsigned int) --> void", pybind11::arg("__state"));
		cl.def("setstate", (void (std::ios_base::*)(unsigned int)) &std::ios_base::setstate, "C++: std::ios_base::setstate(unsigned int) --> void", pybind11::arg("__state"));
		cl.def("good", (bool (std::ios_base::*)() const) &std::ios_base::good, "C++: std::ios_base::good() const --> bool");
		cl.def("eof", (bool (std::ios_base::*)() const) &std::ios_base::eof, "C++: std::ios_base::eof() const --> bool");
		cl.def("fail", (bool (std::ios_base::*)() const) &std::ios_base::fail, "C++: std::ios_base::fail() const --> bool");
		cl.def("bad", (bool (std::ios_base::*)() const) &std::ios_base::bad, "C++: std::ios_base::bad() const --> bool");
		cl.def("exceptions", (unsigned int (std::ios_base::*)() const) &std::ios_base::exceptions, "C++: std::ios_base::exceptions() const --> unsigned int");
		cl.def("exceptions", (void (std::ios_base::*)(unsigned int)) &std::ios_base::exceptions, "C++: std::ios_base::exceptions(unsigned int) --> void", pybind11::arg("__iostate"));
		cl.def("__set_badbit_and_consider_rethrow", (void (std::ios_base::*)()) &std::ios_base::__set_badbit_and_consider_rethrow, "C++: std::ios_base::__set_badbit_and_consider_rethrow() --> void");
		cl.def("__set_failbit_and_consider_rethrow", (void (std::ios_base::*)()) &std::ios_base::__set_failbit_and_consider_rethrow, "C++: std::ios_base::__set_failbit_and_consider_rethrow() --> void");
		cl.def("__setstate_nothrow", (void (std::ios_base::*)(unsigned int)) &std::ios_base::__setstate_nothrow, "C++: std::ios_base::__setstate_nothrow(unsigned int) --> void", pybind11::arg("__state"));

		{ // std::ios_base::failure file:ios line:428
			auto & enclosing_class = cl;
			pybind11::class_<std::ios_base::failure, std::shared_ptr<std::ios_base::failure>, PyCallBack_std_ios_base_failure, std::system_error> cl(enclosing_class, "failure", "");
			cl.def( pybind11::init( [](const std::string & a0){ return new std::ios_base::failure(a0); }, [](const std::string & a0){ return new PyCallBack_std_ios_base_failure(a0); } ), "doc");
			cl.def( pybind11::init<const std::string &, const class std::error_code &>(), pybind11::arg("__msg"), pybind11::arg("__ec") );

			cl.def( pybind11::init( [](const char * a0){ return new std::ios_base::failure(a0); }, [](const char * a0){ return new PyCallBack_std_ios_base_failure(a0); } ), "doc");
			cl.def( pybind11::init<const char *, const class std::error_code &>(), pybind11::arg("__msg"), pybind11::arg("__ec") );

			cl.def( pybind11::init( [](PyCallBack_std_ios_base_failure const &o){ return new PyCallBack_std_ios_base_failure(o); } ) );
			cl.def( pybind11::init( [](std::ios_base::failure const &o){ return new std::ios_base::failure(o); } ) );
			cl.def("assign", (class std::ios_base::failure & (std::ios_base::failure::*)(const class std::ios_base::failure &)) &std::ios_base::failure::operator=, "C++: std::ios_base::failure::operator=(const class std::ios_base::failure &) --> class std::ios_base::failure &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // std::ios_base::Init file:ios line:447
			auto & enclosing_class = cl;
			pybind11::class_<std::ios_base::Init, std::shared_ptr<std::ios_base::Init>> cl(enclosing_class, "Init", "");
			cl.def( pybind11::init( [](){ return new std::ios_base::Init(); } ) );
		}

	}
	{ // std::basic_ios file: line:492
		pybind11::class_<std::basic_ios<char,std::char_traits<char>>, std::shared_ptr<std::basic_ios<char,std::char_traits<char>>>, std::ios_base> cl(M("std"), "basic_ios_char_std_char_traits_char_t", "");
		cl.def( pybind11::init<class std::basic_streambuf<char> *>(), pybind11::arg("__sb") );

		cl.def("rdstate", (unsigned int (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::rdstate, "C++: std::basic_ios<char, std::char_traits<char> >::rdstate() const --> unsigned int");
		cl.def("clear", [](std::basic_ios<char,std::char_traits<char>> &o) -> void { return o.clear(); }, "");
		cl.def("clear", (void (std::basic_ios<char,std::char_traits<char>>::*)(unsigned int)) &std::basic_ios<char, std::char_traits<char> >::clear, "C++: std::basic_ios<char, std::char_traits<char> >::clear(unsigned int) --> void", pybind11::arg("__state"));
		cl.def("setstate", (void (std::basic_ios<char,std::char_traits<char>>::*)(unsigned int)) &std::basic_ios<char, std::char_traits<char> >::setstate, "C++: std::basic_ios<char, std::char_traits<char> >::setstate(unsigned int) --> void", pybind11::arg("__state"));
		cl.def("good", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::good, "C++: std::basic_ios<char, std::char_traits<char> >::good() const --> bool");
		cl.def("eof", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::eof, "C++: std::basic_ios<char, std::char_traits<char> >::eof() const --> bool");
		cl.def("fail", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::fail, "C++: std::basic_ios<char, std::char_traits<char> >::fail() const --> bool");
		cl.def("bad", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::bad, "C++: std::basic_ios<char, std::char_traits<char> >::bad() const --> bool");
		cl.def("exceptions", (unsigned int (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::exceptions, "C++: std::basic_ios<char, std::char_traits<char> >::exceptions() const --> unsigned int");
		cl.def("exceptions", (void (std::basic_ios<char,std::char_traits<char>>::*)(unsigned int)) &std::basic_ios<char, std::char_traits<char> >::exceptions, "C++: std::basic_ios<char, std::char_traits<char> >::exceptions(unsigned int) --> void", pybind11::arg("__iostate"));
		cl.def("tie", (std::ostream * (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::tie, "C++: std::basic_ios<char, std::char_traits<char> >::tie() const --> std::ostream *", pybind11::return_value_policy::automatic);
		cl.def("tie", (std::ostream * (std::basic_ios<char,std::char_traits<char>>::*)(std::ostream *)) &std::basic_ios<char, std::char_traits<char> >::tie, "C++: std::basic_ios<char, std::char_traits<char> >::tie(std::ostream *) --> std::ostream *", pybind11::return_value_policy::automatic, pybind11::arg("__tiestr"));
		cl.def("rdbuf", (class std::basic_streambuf<char> * (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::rdbuf, "C++: std::basic_ios<char, std::char_traits<char> >::rdbuf() const --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic);
		cl.def("rdbuf", (class std::basic_streambuf<char> * (std::basic_ios<char,std::char_traits<char>>::*)(class std::basic_streambuf<char> *)) &std::basic_ios<char, std::char_traits<char> >::rdbuf, "C++: std::basic_ios<char, std::char_traits<char> >::rdbuf(class std::basic_streambuf<char> *) --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__sb"));
		cl.def("copyfmt", (class std::basic_ios<char> & (std::basic_ios<char,std::char_traits<char>>::*)(const class std::basic_ios<char> &)) &std::basic_ios<char, std::char_traits<char> >::copyfmt, "C++: std::basic_ios<char, std::char_traits<char> >::copyfmt(const class std::basic_ios<char> &) --> class std::basic_ios<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__rhs"));
		cl.def("fill", (char (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::fill, "C++: std::basic_ios<char, std::char_traits<char> >::fill() const --> char");
		cl.def("fill", (char (std::basic_ios<char,std::char_traits<char>>::*)(char)) &std::basic_ios<char, std::char_traits<char> >::fill, "C++: std::basic_ios<char, std::char_traits<char> >::fill(char) --> char", pybind11::arg("__ch"));
		cl.def("imbue", (class std::locale (std::basic_ios<char,std::char_traits<char>>::*)(const class std::locale &)) &std::basic_ios<char, std::char_traits<char> >::imbue, "C++: std::basic_ios<char, std::char_traits<char> >::imbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("narrow", (char (std::basic_ios<char,std::char_traits<char>>::*)(char, char) const) &std::basic_ios<char, std::char_traits<char> >::narrow, "C++: std::basic_ios<char, std::char_traits<char> >::narrow(char, char) const --> char", pybind11::arg("__c"), pybind11::arg("__dfault"));
		cl.def("widen", (char (std::basic_ios<char,std::char_traits<char>>::*)(char) const) &std::basic_ios<char, std::char_traits<char> >::widen, "C++: std::basic_ios<char, std::char_traits<char> >::widen(char) const --> char", pybind11::arg("__c"));
		cl.def("flags", (unsigned int (std::ios_base::*)() const) &std::ios_base::flags, "C++: std::ios_base::flags() const --> unsigned int");
		cl.def("flags", (unsigned int (std::ios_base::*)(unsigned int)) &std::ios_base::flags, "C++: std::ios_base::flags(unsigned int) --> unsigned int", pybind11::arg("__fmtfl"));
		cl.def("setf", (unsigned int (std::ios_base::*)(unsigned int)) &std::ios_base::setf, "C++: std::ios_base::setf(unsigned int) --> unsigned int", pybind11::arg("__fmtfl"));
		cl.def("setf", (unsigned int (std::ios_base::*)(unsigned int, unsigned int)) &std::ios_base::setf, "C++: std::ios_base::setf(unsigned int, unsigned int) --> unsigned int", pybind11::arg("__fmtfl"), pybind11::arg("__mask"));
		cl.def("unsetf", (void (std::ios_base::*)(unsigned int)) &std::ios_base::unsetf, "C++: std::ios_base::unsetf(unsigned int) --> void", pybind11::arg("__mask"));
		cl.def("precision", (long (std::ios_base::*)() const) &std::ios_base::precision, "C++: std::ios_base::precision() const --> long");
		cl.def("precision", (long (std::ios_base::*)(long)) &std::ios_base::precision, "C++: std::ios_base::precision(long) --> long", pybind11::arg("__prec"));
		cl.def("width", (long (std::ios_base::*)() const) &std::ios_base::width, "C++: std::ios_base::width() const --> long");
		cl.def("width", (long (std::ios_base::*)(long)) &std::ios_base::width, "C++: std::ios_base::width(long) --> long", pybind11::arg("__wide"));
		cl.def("imbue", (class std::locale (std::ios_base::*)(const class std::locale &)) &std::ios_base::imbue, "C++: std::ios_base::imbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("getloc", (class std::locale (std::ios_base::*)() const) &std::ios_base::getloc, "C++: std::ios_base::getloc() const --> class std::locale");
		cl.def_static("xalloc", (int (*)()) &std::ios_base::xalloc, "C++: std::ios_base::xalloc() --> int");
		cl.def("iword", (long & (std::ios_base::*)(int)) &std::ios_base::iword, "C++: std::ios_base::iword(int) --> long &", pybind11::return_value_policy::automatic, pybind11::arg("__index"));
		cl.def("pword", (void *& (std::ios_base::*)(int)) &std::ios_base::pword, "C++: std::ios_base::pword(int) --> void *&", pybind11::return_value_policy::automatic, pybind11::arg("__index"));
		cl.def_static("sync_with_stdio", []() -> bool { return std::ios_base::sync_with_stdio(); }, "");
		cl.def_static("sync_with_stdio", (bool (*)(bool)) &std::ios_base::sync_with_stdio, "C++: std::ios_base::sync_with_stdio(bool) --> bool", pybind11::arg("__sync"));
		cl.def("rdstate", (unsigned int (std::ios_base::*)() const) &std::ios_base::rdstate, "C++: std::ios_base::rdstate() const --> unsigned int");
		cl.def("clear", [](std::ios_base &o) -> void { return o.clear(); }, "");
		cl.def("clear", (void (std::ios_base::*)(unsigned int)) &std::ios_base::clear, "C++: std::ios_base::clear(unsigned int) --> void", pybind11::arg("__state"));
		cl.def("setstate", (void (std::ios_base::*)(unsigned int)) &std::ios_base::setstate, "C++: std::ios_base::setstate(unsigned int) --> void", pybind11::arg("__state"));
		cl.def("good", (bool (std::ios_base::*)() const) &std::ios_base::good, "C++: std::ios_base::good() const --> bool");
		cl.def("eof", (bool (std::ios_base::*)() const) &std::ios_base::eof, "C++: std::ios_base::eof() const --> bool");
		cl.def("fail", (bool (std::ios_base::*)() const) &std::ios_base::fail, "C++: std::ios_base::fail() const --> bool");
		cl.def("bad", (bool (std::ios_base::*)() const) &std::ios_base::bad, "C++: std::ios_base::bad() const --> bool");
		cl.def("exceptions", (unsigned int (std::ios_base::*)() const) &std::ios_base::exceptions, "C++: std::ios_base::exceptions() const --> unsigned int");
		cl.def("exceptions", (void (std::ios_base::*)(unsigned int)) &std::ios_base::exceptions, "C++: std::ios_base::exceptions(unsigned int) --> void", pybind11::arg("__iostate"));
		cl.def("__set_badbit_and_consider_rethrow", (void (std::ios_base::*)()) &std::ios_base::__set_badbit_and_consider_rethrow, "C++: std::ios_base::__set_badbit_and_consider_rethrow() --> void");
		cl.def("__set_failbit_and_consider_rethrow", (void (std::ios_base::*)()) &std::ios_base::__set_failbit_and_consider_rethrow, "C++: std::ios_base::__set_failbit_and_consider_rethrow() --> void");
		cl.def("__setstate_nothrow", (void (std::ios_base::*)(unsigned int)) &std::ios_base::__setstate_nothrow, "C++: std::ios_base::__setstate_nothrow(unsigned int) --> void", pybind11::arg("__state"));
	}
}
