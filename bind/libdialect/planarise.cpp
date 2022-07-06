#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/planarise.h>
#include <memory>
#include <sstream> // __str__
#include <utility>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_libdialect_planarise(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::CompareActiveEvents(struct dialect::Event *, struct dialect::Event *) file:libdialect/planarise.h line:111
	M("dialect").def("CompareActiveEvents", (bool (*)(struct dialect::Event *, struct dialect::Event *)) &dialect::CompareActiveEvents, "We need a special function for comparing Events, using a positive tolerance.\n Here's why. Suppose vertical segment A has its south end at (0, 0), and horizontal\n segment B has its east end at (0, -0.00000000001). This means that /technically/\n A and B intersect. However (http://xkcd.com/1475/) you probably don't actually want\n to treat this as an intersection. The comparison function is designed so that,\n when the list of active events is sorted, the \"close\" event for segment A will come\n /before/ the \"sustain\" event for segment B, instead of the other way around, as\n dictated by their exact y-coordinates. This way we will /not/ detect an intersection\n between A and B.\n\nC++: dialect::CompareActiveEvents(struct dialect::Event *, struct dialect::Event *) --> bool", pybind11::arg("a"), pybind11::arg("b"));

	{ // dialect::OrthoPlanariserOptions file:libdialect/planarise.h line:117
		pybind11::class_<dialect::OrthoPlanariserOptions, std::shared_ptr<dialect::OrthoPlanariserOptions>> cl(M("dialect"), "OrthoPlanariserOptions", "");
		cl.def( pybind11::init( [](dialect::OrthoPlanariserOptions const &o){ return new dialect::OrthoPlanariserOptions(o); } ) );
		cl.def( pybind11::init( [](){ return new dialect::OrthoPlanariserOptions(); } ) );
		cl.def_readwrite("generateConstraints", &dialect::OrthoPlanariserOptions::generateConstraints);
		cl.def("assign", (struct dialect::OrthoPlanariserOptions & (dialect::OrthoPlanariserOptions::*)(const struct dialect::OrthoPlanariserOptions &)) &dialect::OrthoPlanariserOptions::operator=, "C++: dialect::OrthoPlanariserOptions::operator=(const struct dialect::OrthoPlanariserOptions &) --> struct dialect::OrthoPlanariserOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::OrthoPlanariser file:libdialect/planarise.h line:130
		pybind11::class_<dialect::OrthoPlanariser, std::shared_ptr<dialect::OrthoPlanariser>> cl(M("dialect"), "OrthoPlanariser", "This class is for planarising orthogonally routed graphs.\n To say that a graph G is orthogonally routed means a certain condition on\n the connector route stored in each Edge; namely, that precisely one coordinate\n change between consecutive route points.");
		cl.def( pybind11::init<const class std::shared_ptr<class dialect::Graph> &>(), pybind11::arg("G") );

		cl.def( pybind11::init( [](dialect::OrthoPlanariser const &o){ return new dialect::OrthoPlanariser(o); } ) );
		cl.def("setOpts", (void (dialect::OrthoPlanariser::*)(const struct dialect::OrthoPlanariserOptions &)) &dialect::OrthoPlanariser::setOpts, "Set the options.\n\nC++: dialect::OrthoPlanariser::setOpts(const struct dialect::OrthoPlanariserOptions &) --> void", pybind11::arg("opts"));
		cl.def("planarise", (class std::shared_ptr<class dialect::Graph> (dialect::OrthoPlanariser::*)()) &dialect::OrthoPlanariser::planarise, "Compute a planarisation of the given Graph.\n \n\n  The planarised Graph.\n\nC++: dialect::OrthoPlanariser::planarise() --> class std::shared_ptr<class dialect::Graph>");
	}
}
