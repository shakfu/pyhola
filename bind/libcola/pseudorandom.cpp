#include <libcola/pseudorandom.h>
#include <libcola/shapepair.h>
#include <libcola/sparse_matrix.h>
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <cstdlib>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_libcola_pseudorandom(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::PseudoRandom file:libcola/pseudorandom.h line:27
		pybind11::class_<cola::PseudoRandom, std::shared_ptr<cola::PseudoRandom>> cl(M("cola"), "PseudoRandom", "");
		cl.def( pybind11::init( [](){ return new cola::PseudoRandom(); } ), "doc" );
		cl.def( pybind11::init<double>(), pybind11::arg("s") );

		cl.def("getNext", (double (cola::PseudoRandom::*)()) &cola::PseudoRandom::getNext, "C++: cola::PseudoRandom::getNext() --> double");
		cl.def("getNextBetween", (double (cola::PseudoRandom::*)(double, double)) &cola::PseudoRandom::getNextBetween, "C++: cola::PseudoRandom::getNextBetween(double, double) --> double", pybind11::arg("min"), pybind11::arg("max"));
	}
	{ // cola::ShapePair file:libcola/shapepair.h line:32
		pybind11::class_<cola::ShapePair, std::shared_ptr<cola::ShapePair>> cl(M("cola"), "ShapePair", "");
		cl.def( pybind11::init<unsigned int, unsigned int>(), pybind11::arg("ind1"), pybind11::arg("ind2") );

		cl.def("index1", (unsigned short (cola::ShapePair::*)() const) &cola::ShapePair::index1, "C++: cola::ShapePair::index1() const --> unsigned short");
		cl.def("index2", (unsigned short (cola::ShapePair::*)() const) &cola::ShapePair::index2, "C++: cola::ShapePair::index2() const --> unsigned short");
	}
	{ // cola::SparseMap file:libcola/sparse_matrix.h line:42
		pybind11::class_<cola::SparseMap, std::shared_ptr<cola::SparseMap>> cl(M("cola"), "SparseMap", "");
		cl.def( pybind11::init( [](){ return new cola::SparseMap(); } ), "doc" );
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("n") );

		cl.def_readwrite("n", &cola::SparseMap::n);
		cl.def_readwrite("lookup", &cola::SparseMap::lookup);
		cl.def("__getitem__", (double & (cola::SparseMap::*)(const int &)) &cola::SparseMap::operator[], "C++: cola::SparseMap::operator[](const int &) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("k"));
		cl.def("__call__", (double & (cola::SparseMap::*)(const unsigned int, const unsigned int)) &cola::SparseMap::operator(), "C++: cola::SparseMap::operator()(const unsigned int, const unsigned int) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("i"), pybind11::arg("j"));
		cl.def("getIJ", (double (cola::SparseMap::*)(const unsigned int, const unsigned int) const) &cola::SparseMap::getIJ, "C++: cola::SparseMap::getIJ(const unsigned int, const unsigned int) const --> double", pybind11::arg("i"), pybind11::arg("j"));
		cl.def("nonZeroCount", (unsigned long (cola::SparseMap::*)() const) &cola::SparseMap::nonZeroCount, "C++: cola::SparseMap::nonZeroCount() const --> unsigned long");
		cl.def("resize", (void (cola::SparseMap::*)(unsigned int)) &cola::SparseMap::resize, "C++: cola::SparseMap::resize(unsigned int) --> void", pybind11::arg("n"));
		cl.def("clear", (void (cola::SparseMap::*)()) &cola::SparseMap::clear, "C++: cola::SparseMap::clear() --> void");
	}
	{ // cola::SparseMatrix file:libcola/sparse_matrix.h line:84
		pybind11::class_<cola::SparseMatrix, std::shared_ptr<cola::SparseMatrix>> cl(M("cola"), "SparseMatrix", "");
		cl.def( pybind11::init<const struct cola::SparseMap &>(), pybind11::arg("m") );

		cl.def("rightMultiply", (void (cola::SparseMatrix::*)(const int &, int &) const) &cola::SparseMatrix::rightMultiply, "C++: cola::SparseMatrix::rightMultiply(const int &, int &) const --> void", pybind11::arg("v"), pybind11::arg("r"));
		cl.def("getIJ", (double (cola::SparseMatrix::*)(const unsigned int, const unsigned int) const) &cola::SparseMatrix::getIJ, "C++: cola::SparseMatrix::getIJ(const unsigned int, const unsigned int) const --> double", pybind11::arg("i"), pybind11::arg("j"));
		cl.def("print", (void (cola::SparseMatrix::*)() const) &cola::SparseMatrix::print, "C++: cola::SparseMatrix::print() const --> void");
		cl.def("rowSize", (unsigned int (cola::SparseMatrix::*)() const) &cola::SparseMatrix::rowSize, "C++: cola::SparseMatrix::rowSize() const --> unsigned int");
	}
}
