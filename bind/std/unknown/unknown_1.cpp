#include <ios>
#include <istream>
#include <locale>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
#include <string>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_std_unknown_unknown_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::basic_ostream file: line:1101
		pybind11::class_<std::ostream, std::shared_ptr<std::ostream>, std::basic_ios<char,std::char_traits<char>>> cl(M("std"), "ostream", "");
		cl.def( pybind11::init<class std::basic_streambuf<char> *>(), pybind11::arg("__sb") );

		cl.def("put", (std::ostream & (std::ostream::*)(char)) &std::basic_ostream<char, std::char_traits<char> >::put, "C++: std::basic_ostream<char, std::char_traits<char> >::put(char) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("write", (std::ostream & (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::write, "C++: std::basic_ostream<char, std::char_traits<char> >::write(const char *, long) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("flush", (std::ostream & (std::ostream::*)()) &std::basic_ostream<char, std::char_traits<char> >::flush, "C++: std::basic_ostream<char, std::char_traits<char> >::flush() --> std::ostream &", pybind11::return_value_policy::automatic);
		cl.def("tellp", (class std::fpos<__mbstate_t> (std::ostream::*)()) &std::basic_ostream<char, std::char_traits<char> >::tellp, "C++: std::basic_ostream<char, std::char_traits<char> >::tellp() --> class std::fpos<__mbstate_t>");
		cl.def("seekp", (std::ostream & (std::ostream::*)(class std::fpos<__mbstate_t>)) &std::basic_ostream<char, std::char_traits<char> >::seekp, "C++: std::basic_ostream<char, std::char_traits<char> >::seekp(class std::fpos<__mbstate_t>) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__pos"));
		cl.def("seekp", (std::ostream & (std::ostream::*)(long long, enum std::ios_base::seekdir)) &std::basic_ostream<char, std::char_traits<char> >::seekp, "C++: std::basic_ostream<char, std::char_traits<char> >::seekp(long long, enum std::ios_base::seekdir) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__off"), pybind11::arg("__dir"));
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

		{ // std::basic_ostream<char, std::char_traits<char> >::sentry file:ostream line:191
			auto & enclosing_class = cl;
			pybind11::class_<std::basic_ostream<char, std::char_traits<char> >::sentry, std::shared_ptr<std::basic_ostream<char, std::char_traits<char> >::sentry>> cl(enclosing_class, "sentry", "");
			cl.def( pybind11::init<std::ostream &>(), pybind11::arg("__os") );

		}

	}
	{ // std::basic_istream file: line:1642
		pybind11::class_<std::istream, std::shared_ptr<std::istream>, std::basic_ios<char,std::char_traits<char>>> cl(M("std"), "istream", "");
		cl.def( pybind11::init<class std::basic_streambuf<char> *>(), pybind11::arg("__sb") );

		cl.def("gcount", (long (std::istream::*)() const) &std::basic_istream<char, std::char_traits<char> >::gcount, "C++: std::basic_istream<char, std::char_traits<char> >::gcount() const --> long");
		cl.def("get", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get() --> int");
		cl.def("get", (std::istream & (std::istream::*)(char &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char &) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("get", (std::istream & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("get", (std::istream & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long, char) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__dlm"));
		cl.def("get", (std::istream & (std::istream::*)(class std::basic_streambuf<char> &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"));
		cl.def("get", (std::istream & (std::istream::*)(class std::basic_streambuf<char> &, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &, char) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"), pybind11::arg("__dlm"));
		cl.def("getline", (std::istream & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("getline", (std::istream & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long, char) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__dlm"));
		cl.def("ignore", [](std::istream &o) -> std::istream & { return o.ignore(); }, "", pybind11::return_value_policy::automatic);
		cl.def("ignore", [](std::istream &o, long const & a0) -> std::istream & { return o.ignore(a0); }, "", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("ignore", (std::istream & (std::istream::*)(long, int)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long, int) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__n"), pybind11::arg("__dlm"));
		cl.def("peek", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::peek, "C++: std::basic_istream<char, std::char_traits<char> >::peek() --> int");
		cl.def("read", (std::istream & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::read, "C++: std::basic_istream<char, std::char_traits<char> >::read(char *, long) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("readsome", (long (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::readsome, "C++: std::basic_istream<char, std::char_traits<char> >::readsome(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("putback", (std::istream & (std::istream::*)(char)) &std::basic_istream<char, std::char_traits<char> >::putback, "C++: std::basic_istream<char, std::char_traits<char> >::putback(char) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("unget", (std::istream & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::unget, "C++: std::basic_istream<char, std::char_traits<char> >::unget() --> std::istream &", pybind11::return_value_policy::automatic);
		cl.def("sync", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::sync, "C++: std::basic_istream<char, std::char_traits<char> >::sync() --> int");
		cl.def("tellg", (class std::fpos<__mbstate_t> (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::tellg, "C++: std::basic_istream<char, std::char_traits<char> >::tellg() --> class std::fpos<__mbstate_t>");
		cl.def("seekg", (std::istream & (std::istream::*)(class std::fpos<__mbstate_t>)) &std::basic_istream<char, std::char_traits<char> >::seekg, "C++: std::basic_istream<char, std::char_traits<char> >::seekg(class std::fpos<__mbstate_t>) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__pos"));
		cl.def("seekg", (std::istream & (std::istream::*)(long long, enum std::ios_base::seekdir)) &std::basic_istream<char, std::char_traits<char> >::seekg, "C++: std::basic_istream<char, std::char_traits<char> >::seekg(long long, enum std::ios_base::seekdir) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("__off"), pybind11::arg("__dir"));
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

		{ // std::basic_istream<char, std::char_traits<char> >::sentry file:istream line:216
			auto & enclosing_class = cl;
			pybind11::class_<std::basic_istream<char, std::char_traits<char> >::sentry, std::shared_ptr<std::basic_istream<char, std::char_traits<char> >::sentry>> cl(enclosing_class, "sentry", "");
			cl.def( pybind11::init( [](std::istream & a0){ return new std::basic_istream<char, std::char_traits<char> >::sentry(a0); } ), "doc" , pybind11::arg("__is"));
			cl.def( pybind11::init<std::istream &, bool>(), pybind11::arg("__is"), pybind11::arg("__noskipws") );

		}

	}
}
