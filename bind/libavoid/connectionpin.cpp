#include <libavoid/connectionpin.h>
#include <libavoid/connector.h>
#include <libavoid/junction.h>
#include <memory>
#include <sstream> // __str__
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

void bind_libavoid_connectionpin(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::ShapeConnectionPin file:libavoid/connectionpin.h line:96
		pybind11::class_<Avoid::ShapeConnectionPin, std::shared_ptr<Avoid::ShapeConnectionPin>> cl(M("Avoid"), "ShapeConnectionPin", "The ShapeConnectionPin class represents a fixed point or \"pin\" \n         on a shape that can be connected to.\n\n A pin has a position that is specified relative to its parent shape.  \n When the shape is moved or resized, the pin will be automatically moved \n accordingly.  Connectors attached to the pin will be rerouted.\n\n Pins have a visibility direction and numeric ID used to identify them.\n This ID, known as their classId, may be shared by multiple pins on the\n same shape.  You can use classIds when you want libavoid to choose from \n multiple potential choices (e.g., to specify multiple types of pins such \n as \"input\" or \"output\" pins on circuit elements).\n\n If you would like connectors that attach to a single specific position\n on a shape, then just give each pin a unique classId (for that shape)\n and tell the connector to attach to that particular pin.\n\n Pins may optionally be given a connection cost, via setConnectionCost(). \n In the case of multiple pins with the same classId, this causes the \n lower-cost pins to be chosen first, rather than libavoid choosing the\n best pin with that classId based solely on connector path cost.\n\n Pins can be exclusive, which means subsequent connectors routed to the \n same classId will choose a different pin.  Pins with a specified direction \n are exclusive by default, those with visibility in all directions are \n non-exclusive by default.  This behaviour can be changed by calling the \n ShapeConnectionPin::setExclusive() method.  Exclusive pins may only have \n a single connector attached to them.");
		cl.def( pybind11::init<class Avoid::ShapeRef *, const unsigned int, const double, const double, const bool, const double, const unsigned int>(), pybind11::arg("shape"), pybind11::arg("classId"), pybind11::arg("xOffset"), pybind11::arg("yOffset"), pybind11::arg("proportional"), pybind11::arg("insideOffset"), pybind11::arg("visDirs") );

		cl.def( pybind11::init<class Avoid::ShapeRef *, const unsigned int, const double, const double, const double, const unsigned int>(), pybind11::arg("shape"), pybind11::arg("classId"), pybind11::arg("xOffset"), pybind11::arg("yOffset"), pybind11::arg("insideOffset"), pybind11::arg("visDirs") );

		cl.def( pybind11::init( [](class Avoid::JunctionRef * a0, const unsigned int & a1){ return new Avoid::ShapeConnectionPin(a0, a1); } ), "doc" , pybind11::arg("junction"), pybind11::arg("classId"));
		cl.def( pybind11::init<class Avoid::JunctionRef *, const unsigned int, const unsigned int>(), pybind11::arg("junction"), pybind11::arg("classId"), pybind11::arg("visDirs") );

		cl.def( pybind11::init( [](Avoid::ShapeConnectionPin const &o){ return new Avoid::ShapeConnectionPin(o); } ) );
		cl.def("setConnectionCost", (void (Avoid::ShapeConnectionPin::*)(const double)) &Avoid::ShapeConnectionPin::setConnectionCost, "Sets a cost used when selecting whether connectors should be\n        be attached to this connection pin.\n\n \n  A routing cost applied to a route when selecting\n                   this connection pin.\n\nC++: Avoid::ShapeConnectionPin::setConnectionCost(const double) --> void", pybind11::arg("cost"));
		cl.def("position", [](Avoid::ShapeConnectionPin const &o) -> const Avoid::Point { return o.position(); }, "");
		cl.def("position", (const class Avoid::Point (Avoid::ShapeConnectionPin::*)(const class Avoid::Polygon &) const) &Avoid::ShapeConnectionPin::position, "Returns the position of this connection pin.\n\n \n The position of this connection pin.\n\nC++: Avoid::ShapeConnectionPin::position(const class Avoid::Polygon &) const --> const class Avoid::Point", pybind11::arg("newPoly"));
		cl.def("directions", (unsigned int (Avoid::ShapeConnectionPin::*)() const) &Avoid::ShapeConnectionPin::directions, "Returns the directions in which this connection pin\n        has visibility.\n\n \n The visibility directions for this connection pin.\n\nC++: Avoid::ShapeConnectionPin::directions() const --> unsigned int");
		cl.def("setExclusive", (void (Avoid::ShapeConnectionPin::*)(const bool)) &Avoid::ShapeConnectionPin::setExclusive, "Sets whether the pin is exclusive, i.e., only one connector\n         can attach to it.  This defaults to true for connection \n         pins with visibility in a specific directions and false for\n         pins with visibility in all directions.\n\n \n  A bool representing whether this pin should\n                        be exclusive.\n\nC++: Avoid::ShapeConnectionPin::setExclusive(const bool) --> void", pybind11::arg("exclusive"));
		cl.def("isExclusive", (bool (Avoid::ShapeConnectionPin::*)() const) &Avoid::ShapeConnectionPin::isExclusive, "Returns whether the connection pin is exclusive, \n        i.e., only one connector can attach to it.\n\n \n  A boolean denoting whether this pin is exclusive.\n\nC++: Avoid::ShapeConnectionPin::isExclusive() const --> bool");
		cl.def("ids", (struct std::pair<unsigned int, unsigned int> (Avoid::ShapeConnectionPin::*)() const) &Avoid::ShapeConnectionPin::ids, "C++: Avoid::ShapeConnectionPin::ids() const --> struct std::pair<unsigned int, unsigned int>");
		cl.def("__eq__", (bool (Avoid::ShapeConnectionPin::*)(const class Avoid::ShapeConnectionPin &) const) &Avoid::ShapeConnectionPin::operator==, "C++: Avoid::ShapeConnectionPin::operator==(const class Avoid::ShapeConnectionPin &) const --> bool", pybind11::arg("rhs"));
	}
	{ // Avoid::CmpConnPinPtr file:libavoid/connectionpin.h line:283
		pybind11::class_<Avoid::CmpConnPinPtr, std::shared_ptr<Avoid::CmpConnPinPtr>> cl(M("Avoid"), "CmpConnPinPtr", "");
		cl.def( pybind11::init( [](){ return new Avoid::CmpConnPinPtr(); } ) );
		cl.def("__call__", (bool (Avoid::CmpConnPinPtr::*)(const class Avoid::ShapeConnectionPin *, const class Avoid::ShapeConnectionPin *) const) &Avoid::CmpConnPinPtr::operator(), "C++: Avoid::CmpConnPinPtr::operator()(const class Avoid::ShapeConnectionPin *, const class Avoid::ShapeConnectionPin *) const --> bool", pybind11::arg("lhs"), pybind11::arg("rhs"));
	}
}
