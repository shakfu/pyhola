#include <functional>
#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/ortho.h>
#include <libdialect/planarise.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
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

void bind_libdialect_planarise(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::EdgeSegment file:libdialect/planarise.h line:41
		pybind11::class_<dialect::EdgeSegment, std::shared_ptr<dialect::EdgeSegment>> cl(M("dialect"), "EdgeSegment", "Represents an axis-aligned segment of an orthogonal connector route.");
		cl.def( pybind11::init( [](dialect::EdgeSegment const &o){ return new dialect::EdgeSegment(o); } ) );
		cl.def_readwrite("orientation", &dialect::EdgeSegment::orientation);
		cl.def_readwrite("constCoord", &dialect::EdgeSegment::constCoord);
		cl.def_readwrite("lowerBound", &dialect::EdgeSegment::lowerBound);
		cl.def_readwrite("upperBound", &dialect::EdgeSegment::upperBound);
		cl.def_readwrite("openingNode", &dialect::EdgeSegment::openingNode);
		cl.def_readwrite("closingNode", &dialect::EdgeSegment::closingNode);
		cl.def("addSep", (void (dialect::EdgeSegment::*)(class dialect::SepMatrix &) const) &dialect::EdgeSegment::addSep, "Update a SepMatrix with a constraint requiring this segment to\n         remain aligned and at least its current length.\n\nC++: dialect::EdgeSegment::addSep(class dialect::SepMatrix &) const --> void", pybind11::arg("m"));
	}
	// dialect::EventType file:libdialect/planarise.h line:75
	pybind11::enum_<dialect::EventType>(M("dialect"), "EventType", "")
		.value("CLOSE", dialect::EventType::CLOSE)
		.value("SUSTAIN", dialect::EventType::SUSTAIN)
		.value("OPEN", dialect::EventType::OPEN);

;

	{ // dialect::Event file:libdialect/planarise.h line:81
		pybind11::class_<dialect::Event, std::shared_ptr<dialect::Event>> cl(M("dialect"), "Event", "");
		cl.def( pybind11::init( [](dialect::Event const &o){ return new dialect::Event(o); } ) );
		cl.def_readwrite("endpt", &dialect::Event::endpt);
		cl.def_readwrite("constCoord", &dialect::Event::constCoord);
		cl.def_readwrite("varCoord", &dialect::Event::varCoord);
		cl.def_readwrite("type", &dialect::Event::type);
		cl.def("x", (double (dialect::Event::*)()) &dialect::Event::x, "C++: dialect::Event::x() --> double");
		cl.def("y", (double (dialect::Event::*)()) &dialect::Event::y, "C++: dialect::Event::y() --> double");
	}
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
		cl.def( pybind11::init( [](dialect::OrthoPlanariser const &o){ return new dialect::OrthoPlanariser(o); } ) );
		cl.def("setOpts", (void (dialect::OrthoPlanariser::*)(const struct dialect::OrthoPlanariserOptions &)) &dialect::OrthoPlanariser::setOpts, "Set the options.\n\nC++: dialect::OrthoPlanariser::setOpts(const struct dialect::OrthoPlanariserOptions &) --> void", pybind11::arg("opts"));
	}
}
