#include <_stdio.h>
#include <functional>
#include <libavoid/connector.h>
#include <libavoid/debughandler.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedge.h>
#include <libavoid/junction.h>
#include <libavoid/scanline.h>
#include <list>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
#include <string_view>
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

void bind_libavoid_scanline(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::Event file:libavoid/scanline.h line:117
		pybind11::class_<Avoid::Event, std::shared_ptr<Avoid::Event>> cl(M("Avoid"), "Event", "");
		cl.def( pybind11::init<Avoid::EventType, class Avoid::Node *, double>(), pybind11::arg("t"), pybind11::arg("v"), pybind11::arg("p") );

		cl.def_readwrite("type", &Avoid::Event::type);
		cl.def_readwrite("pos", &Avoid::Event::pos);
	}
	// Avoid::compare_events(const void *, const void *) file:libavoid/scanline.h line:127
	M("Avoid").def("compare_events", (int (*)(const void *, const void *)) &Avoid::compare_events, "C++: Avoid::compare_events(const void *, const void *) --> int", pybind11::arg("a"), pybind11::arg("b"));

	// Avoid::buildConnectorRouteCheckpointCache(class Avoid::Router *) file:libavoid/scanline.h line:128
	M("Avoid").def("buildConnectorRouteCheckpointCache", (void (*)(class Avoid::Router *)) &Avoid::buildConnectorRouteCheckpointCache, "C++: Avoid::buildConnectorRouteCheckpointCache(class Avoid::Router *) --> void", pybind11::arg("router"));

	// Avoid::clearConnectorRouteCheckpointCache(class Avoid::Router *) file:libavoid/scanline.h line:129
	M("Avoid").def("clearConnectorRouteCheckpointCache", (void (*)(class Avoid::Router *)) &Avoid::clearConnectorRouteCheckpointCache, "C++: Avoid::clearConnectorRouteCheckpointCache(class Avoid::Router *) --> void", pybind11::arg("router"));

	// Avoid::buildOrthogonalChannelInfo(class Avoid::Router *, const unsigned long, class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &) file:libavoid/scanline.h line:130
	M("Avoid").def("buildOrthogonalChannelInfo", (void (*)(class Avoid::Router *, const unsigned long, class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &)) &Avoid::buildOrthogonalChannelInfo, "C++: Avoid::buildOrthogonalChannelInfo(class Avoid::Router *, const unsigned long, class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &) --> void", pybind11::arg("router"), pybind11::arg("dim"), pybind11::arg("segmentList"));

}
