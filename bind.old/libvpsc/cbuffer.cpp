#include <libvpsc/cbuffer.h>
#include <libvpsc/constraint.h>
#include <libvpsc/exceptions.h>
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

void bind_libvpsc_cbuffer(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // vpsc::CBuffer file:libvpsc/cbuffer.h line:29
		pybind11::class_<vpsc::CBuffer, std::shared_ptr<vpsc::CBuffer>> cl(M("vpsc"), "CBuffer", "");
		cl.def( pybind11::init( [](vpsc::CBuffer const &o){ return new vpsc::CBuffer(o); } ) );
		cl.def("reset", (void (vpsc::CBuffer::*)()) &vpsc::CBuffer::reset, "C++: vpsc::CBuffer::reset() --> void");
		cl.def("load", (void (vpsc::CBuffer::*)()) &vpsc::CBuffer::load, "C++: vpsc::CBuffer::load() --> void");
		cl.def("mostViolated", (class vpsc::Constraint * (vpsc::CBuffer::*)()) &vpsc::CBuffer::mostViolated, "C++: vpsc::CBuffer::mostViolated() --> class vpsc::Constraint *", pybind11::return_value_policy::automatic);
	}
	{ // vpsc::UnsatisfiableException file:libvpsc/exceptions.h line:27
		pybind11::class_<vpsc::UnsatisfiableException, std::shared_ptr<vpsc::UnsatisfiableException>> cl(M("vpsc"), "UnsatisfiableException", "");
		cl.def( pybind11::init( [](){ return new vpsc::UnsatisfiableException(); } ) );
		cl.def( pybind11::init( [](vpsc::UnsatisfiableException const &o){ return new vpsc::UnsatisfiableException(o); } ) );
		cl.def_readwrite("path", &vpsc::UnsatisfiableException::path);
	}
	{ // vpsc::UnsatisfiedConstraint file:libvpsc/exceptions.h line:30
		pybind11::class_<vpsc::UnsatisfiedConstraint, std::shared_ptr<vpsc::UnsatisfiedConstraint>> cl(M("vpsc"), "UnsatisfiedConstraint", "");
		cl.def( pybind11::init<class vpsc::Constraint &>(), pybind11::arg("c") );

	}
}
