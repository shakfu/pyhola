#include <_stdio.h>
#include <algorithm>
#include <atomic>
#include <filesystem>
#include <functional>
#include <ios>
#include <iterator>
#include <libavoid/actioninfo.h>
#include <libavoid/connectionpin.h>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/geomtypes.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedgetree.h>
#include <libavoid/junction.h>
#include <libavoid/obstacle.h>
#include <libavoid/router.h>
#include <libavoid/scanline.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <libavoid/viscluster.h>
#include <libavoid/vpsc.h>
#include <libcola/box.h>
#include <libcola/cc_nonoverlapconstraints.h>
#include <libcola/cluster.h>
#include <libcola/cola.h>
#include <libcola/compound_constraints.h>
#include <libcola/shapepair.h>
#include <libcola/straightener.h>
#include <libdialect/aca.h>
#include <libdialect/chains.h>
#include <libdialect/constraints.h>
#include <libdialect/expansion.h>
#include <libdialect/faces.h>
#include <libdialect/graphs.h>
#include <libdialect/nearalign.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/peeling.h>
#include <libdialect/planarise.h>
#include <libdialect/quadaction.h>
#include <libdialect/routing.h>
#include <libdialect/treeplacement.h>
#include <libdialect/trees.h>
#include <libproject/project.h>
#include <libtopology/topology_constraints.h>
#include <libtopology/topology_graph.h>
#include <libtopology/util.h>
#include <libvpsc/block.h>
#include <libvpsc/blocks.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <list>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <sstream> // __str__
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <tuple>
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

// std::runtime_error file:stdexcept line:101
struct PyCallBack_std_runtime_error : public std::runtime_error {
	using std::runtime_error::runtime_error;

	const char * what() const noexcept override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::runtime_error *>(this), "what");
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

void bind_std_string(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::fpos file:string line:537
		pybind11::class_<std::fpos<__mbstate_t>, std::shared_ptr<std::fpos<__mbstate_t>>> cl(M("std"), "fpos___mbstate_t_t", "");
		cl.def( pybind11::init( [](){ return new std::fpos<__mbstate_t>(); } ), "doc" );
		cl.def( pybind11::init<long long>(), pybind11::arg("__off") );

		cl.def( pybind11::init( [](std::fpos<__mbstate_t> const &o){ return new std::fpos<__mbstate_t>(o); } ) );
		cl.def("__iadd__", (class std::fpos<__mbstate_t> & (std::fpos<__mbstate_t>::*)(long long)) &std::fpos<__mbstate_t>::operator+=, "C++: std::fpos<__mbstate_t>::operator+=(long long) --> class std::fpos<__mbstate_t> &", pybind11::return_value_policy::automatic, pybind11::arg("__off"));
		cl.def("__add__", (class std::fpos<__mbstate_t> (std::fpos<__mbstate_t>::*)(long long) const) &std::fpos<__mbstate_t>::operator+, "C++: std::fpos<__mbstate_t>::operator+(long long) const --> class std::fpos<__mbstate_t>", pybind11::arg("__off"));
		cl.def("__isub__", (class std::fpos<__mbstate_t> & (std::fpos<__mbstate_t>::*)(long long)) &std::fpos<__mbstate_t>::operator-=, "C++: std::fpos<__mbstate_t>::operator-=(long long) --> class std::fpos<__mbstate_t> &", pybind11::return_value_policy::automatic, pybind11::arg("__off"));
		cl.def("__sub__", (class std::fpos<__mbstate_t> (std::fpos<__mbstate_t>::*)(long long) const) &std::fpos<__mbstate_t>::operator-, "C++: std::fpos<__mbstate_t>::operator-(long long) const --> class std::fpos<__mbstate_t>", pybind11::arg("__off"));
	}
	{ // std::runtime_error file:stdexcept line:101
		pybind11::class_<std::runtime_error, std::shared_ptr<std::runtime_error>, PyCallBack_std_runtime_error, std::exception> cl(M("std"), "runtime_error", "");
		cl.def( pybind11::init<const std::string &>(), pybind11::arg("") );

		cl.def( pybind11::init<const char *>(), pybind11::arg("") );

		cl.def( pybind11::init( [](PyCallBack_std_runtime_error const &o){ return new PyCallBack_std_runtime_error(o); } ) );
		cl.def( pybind11::init( [](std::runtime_error const &o){ return new std::runtime_error(o); } ) );
		cl.def("assign", (class std::runtime_error & (std::runtime_error::*)(const class std::runtime_error &)) &std::runtime_error::operator=, "C++: std::runtime_error::operator=(const class std::runtime_error &) --> class std::runtime_error &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("what", (const char * (std::runtime_error::*)() const) &std::runtime_error::what, "C++: std::runtime_error::what() const --> const char *", pybind11::return_value_policy::automatic);
	}
}
