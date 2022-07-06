#include <libvpsc/block.h>
#include <libvpsc/blocks.h>
#include <libvpsc/constraint.h>
#include <libvpsc/variable.h>
#include <memory>
#include <sstream> // __str__
#include <string>
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

void bind_libvpsc_blocks(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // vpsc::Blocks file:libvpsc/blocks.h line:54
		pybind11::class_<vpsc::Blocks, std::shared_ptr<vpsc::Blocks>> cl(M("vpsc"), "Blocks", "");
		cl.def( pybind11::init( [](vpsc::Blocks const &o){ return new vpsc::Blocks(o); } ) );
		cl.def_readwrite("blockTimeCtr", &vpsc::Blocks::blockTimeCtr);
		cl.def("mergeLeft", (void (vpsc::Blocks::*)(class vpsc::Block *)) &vpsc::Blocks::mergeLeft, "C++: vpsc::Blocks::mergeLeft(class vpsc::Block *) --> void", pybind11::arg("r"));
		cl.def("mergeRight", (void (vpsc::Blocks::*)(class vpsc::Block *)) &vpsc::Blocks::mergeRight, "C++: vpsc::Blocks::mergeRight(class vpsc::Block *) --> void", pybind11::arg("l"));
		cl.def("split", (void (vpsc::Blocks::*)(class vpsc::Block *, class vpsc::Block *&, class vpsc::Block *&, class vpsc::Constraint *)) &vpsc::Blocks::split, "C++: vpsc::Blocks::split(class vpsc::Block *, class vpsc::Block *&, class vpsc::Block *&, class vpsc::Constraint *) --> void", pybind11::arg("b"), pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("c"));
		cl.def("cleanup", (void (vpsc::Blocks::*)()) &vpsc::Blocks::cleanup, "C++: vpsc::Blocks::cleanup() --> void");
		cl.def("cost", (double (vpsc::Blocks::*)()) &vpsc::Blocks::cost, "C++: vpsc::Blocks::cost() --> double");
		cl.def("size", (unsigned long (vpsc::Blocks::*)() const) &vpsc::Blocks::size, "C++: vpsc::Blocks::size() const --> unsigned long");
		cl.def("at", (class vpsc::Block * (vpsc::Blocks::*)(unsigned long) const) &vpsc::Blocks::at, "C++: vpsc::Blocks::at(unsigned long) const --> class vpsc::Block *", pybind11::return_value_policy::automatic, pybind11::arg("index"));
		cl.def("insert", (void (vpsc::Blocks::*)(class vpsc::Block *)) &vpsc::Blocks::insert, "C++: vpsc::Blocks::insert(class vpsc::Block *) --> void", pybind11::arg("block"));
	}
}
