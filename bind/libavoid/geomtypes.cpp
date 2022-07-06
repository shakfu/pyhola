#include <libavoid/connector.h>
#include <libavoid/debughandler.h>
#include <libavoid/geometry.h>
#include <libavoid/geomtypes.h>
#include <libavoid/hyperedge.h>
#include <libavoid/junction.h>
#include <libavoid/obstacle.h>
#include <libavoid/router.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <libavoid/viscluster.h>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <string_view>
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

// Avoid::PolygonInterface file:libavoid/geomtypes.h line:150
struct PyCallBack_Avoid_PolygonInterface : public Avoid::PolygonInterface {
	using Avoid::PolygonInterface::PolygonInterface;

	void clear() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::PolygonInterface *>(this), "clear");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"PolygonInterface::clear\"");
	}
	bool empty() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::PolygonInterface *>(this), "empty");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"PolygonInterface::empty\"");
	}
	unsigned long size() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::PolygonInterface *>(this), "size");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned long>::value) {
				static pybind11::detail::override_caster_t<unsigned long> caster;
				return pybind11::detail::cast_ref<unsigned long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned long>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"PolygonInterface::size\"");
	}
	int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::PolygonInterface *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"PolygonInterface::id\"");
	}
	const class Avoid::Point & at(unsigned long a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::PolygonInterface *>(this), "at");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<const class Avoid::Point &>::value) {
				static pybind11::detail::override_caster_t<const class Avoid::Point &> caster;
				return pybind11::detail::cast_ref<const class Avoid::Point &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class Avoid::Point &>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"PolygonInterface::at\"");
	}
};

// Avoid::Polygon file:libavoid/geomtypes.h line:207
struct PyCallBack_Avoid_Polygon : public Avoid::Polygon {
	using Avoid::Polygon::Polygon;

	void clear() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Polygon *>(this), "clear");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Polygon::clear();
	}
	bool empty() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Polygon *>(this), "empty");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Polygon::empty();
	}
	unsigned long size() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Polygon *>(this), "size");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned long>::value) {
				static pybind11::detail::override_caster_t<unsigned long> caster;
				return pybind11::detail::cast_ref<unsigned long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned long>(std::move(o));
		}
		return Polygon::size();
	}
	int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Polygon *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return Polygon::id();
	}
	const class Avoid::Point & at(unsigned long a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Polygon *>(this), "at");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<const class Avoid::Point &>::value) {
				static pybind11::detail::override_caster_t<const class Avoid::Point &> caster;
				return pybind11::detail::cast_ref<const class Avoid::Point &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class Avoid::Point &>(std::move(o));
		}
		return Polygon::at(a0);
	}
};

// Avoid::ReferencingPolygon file:libavoid/geomtypes.h line:336
struct PyCallBack_Avoid_ReferencingPolygon : public Avoid::ReferencingPolygon {
	using Avoid::ReferencingPolygon::ReferencingPolygon;

	void clear() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::ReferencingPolygon *>(this), "clear");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return ReferencingPolygon::clear();
	}
	bool empty() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::ReferencingPolygon *>(this), "empty");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ReferencingPolygon::empty();
	}
	unsigned long size() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::ReferencingPolygon *>(this), "size");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned long>::value) {
				static pybind11::detail::override_caster_t<unsigned long> caster;
				return pybind11::detail::cast_ref<unsigned long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned long>(std::move(o));
		}
		return ReferencingPolygon::size();
	}
	int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::ReferencingPolygon *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return ReferencingPolygon::id();
	}
	const class Avoid::Point & at(unsigned long a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::ReferencingPolygon *>(this), "at");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<const class Avoid::Point &>::value) {
				static pybind11::detail::override_caster_t<const class Avoid::Point &> caster;
				return pybind11::detail::cast_ref<const class Avoid::Point &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class Avoid::Point &>(std::move(o));
		}
		return ReferencingPolygon::at(a0);
	}
};

// Avoid::Rectangle file:libavoid/geomtypes.h line:356
struct PyCallBack_Avoid_Rectangle : public Avoid::Rectangle {
	using Avoid::Rectangle::Rectangle;

	void clear() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Rectangle *>(this), "clear");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Polygon::clear();
	}
	bool empty() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Rectangle *>(this), "empty");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Polygon::empty();
	}
	unsigned long size() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Rectangle *>(this), "size");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned long>::value) {
				static pybind11::detail::override_caster_t<unsigned long> caster;
				return pybind11::detail::cast_ref<unsigned long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned long>(std::move(o));
		}
		return Polygon::size();
	}
	int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Rectangle *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return Polygon::id();
	}
	const class Avoid::Point & at(unsigned long a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Avoid::Rectangle *>(this), "at");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<const class Avoid::Point &>::value) {
				static pybind11::detail::override_caster_t<const class Avoid::Point &> caster;
				return pybind11::detail::cast_ref<const class Avoid::Point &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class Avoid::Point &>(std::move(o));
		}
		return Polygon::at(a0);
	}
};

void bind_libavoid_geomtypes(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::Point file:libavoid/geomtypes.h line:52
		pybind11::class_<Avoid::Point, std::shared_ptr<Avoid::Point>> cl(M("Avoid"), "Point", "The Point class defines a point in the plane.\n\n Points consist of an x and y value.  They may also have an ID and vertex\n number associated with them.");
		cl.def( pybind11::init( [](){ return new Avoid::Point(); } ) );
		cl.def( pybind11::init<const double, const double>(), pybind11::arg("xv"), pybind11::arg("yv") );

		cl.def( pybind11::init( [](Avoid::Point const &o){ return new Avoid::Point(o); } ) );
		cl.def_readwrite("x", &Avoid::Point::x);
		cl.def_readwrite("y", &Avoid::Point::y);
		cl.def_readwrite("id", &Avoid::Point::id);
		cl.def_readwrite("vn", &Avoid::Point::vn);
		cl.def("__eq__", (bool (Avoid::Point::*)(const class Avoid::Point &) const) &Avoid::Point::operator==, "Comparison operator. Returns true if at same position.\n\n \n  The point to compare with this one.\n \n\n          The result of the comparison.\n \n\n         equals()\n\nC++: Avoid::Point::operator==(const class Avoid::Point &) const --> bool", pybind11::arg("rhs"));
		cl.def("equals", [](Avoid::Point const &o, const class Avoid::Point & a0) -> bool { return o.equals(a0); }, "", pybind11::arg("rhs"));
		cl.def("equals", (bool (Avoid::Point::*)(const class Avoid::Point &, double) const) &Avoid::Point::equals, "Comparison operator. Returns true if at same position,\n         or at effectively the same position for a given value of\n         epsilson.\n\n \n      The point to compare with this one.\n \n\n  Value of epsilon to use during comparison.\n \n\n              The result of the comparison.\n \n\n         operator==()\n\nC++: Avoid::Point::equals(const class Avoid::Point &, double) const --> bool", pybind11::arg("rhs"), pybind11::arg("epsilon"));
		cl.def("__ne__", (bool (Avoid::Point::*)(const class Avoid::Point &) const) &Avoid::Point::operator!=, "Comparison operator. Returns true if at different positions.\n\n \n  The point to compare with this one.\n \n\n          The result of the comparison.\n\nC++: Avoid::Point::operator!=(const class Avoid::Point &) const --> bool", pybind11::arg("rhs"));
		cl.def("__getitem__", (double & (Avoid::Point::*)(const unsigned long)) &Avoid::Point::operator[], "Returns the x or y value of the point, given the dimension.\n\n \n  The dimension:  0 for x, 1 for y.\n \n\n                The component of the point in that dimension.\n\nC++: Avoid::Point::operator[](const unsigned long) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("dimension"));
		cl.def("__add__", (class Avoid::Point (Avoid::Point::*)(const class Avoid::Point &) const) &Avoid::Point::operator+, "C++: Avoid::Point::operator+(const class Avoid::Point &) const --> class Avoid::Point", pybind11::arg("rhs"));
		cl.def("__sub__", (class Avoid::Point (Avoid::Point::*)(const class Avoid::Point &) const) &Avoid::Point::operator-, "C++: Avoid::Point::operator-(const class Avoid::Point &) const --> class Avoid::Point", pybind11::arg("rhs"));
		cl.def("assign", (class Avoid::Point & (Avoid::Point::*)(const class Avoid::Point &)) &Avoid::Point::operator=, "C++: Avoid::Point::operator=(const class Avoid::Point &) --> class Avoid::Point &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::Box file:libavoid/geomtypes.h line:133
		pybind11::class_<Avoid::Box, std::shared_ptr<Avoid::Box>> cl(M("Avoid"), "Box", "A bounding box, represented by the top-left and\n         bottom-right corners.");
		cl.def( pybind11::init( [](){ return new Avoid::Box(); } ) );
		cl.def_readwrite("min", &Avoid::Box::min);
		cl.def_readwrite("max", &Avoid::Box::max);
		cl.def("length", (double (Avoid::Box::*)(unsigned long) const) &Avoid::Box::length, "C++: Avoid::Box::length(unsigned long) const --> double", pybind11::arg("dimension"));
		cl.def("width", (double (Avoid::Box::*)() const) &Avoid::Box::width, "C++: Avoid::Box::width() const --> double");
		cl.def("height", (double (Avoid::Box::*)() const) &Avoid::Box::height, "C++: Avoid::Box::height() const --> double");
	}
	{ // Avoid::PolygonInterface file:libavoid/geomtypes.h line:150
		pybind11::class_<Avoid::PolygonInterface, std::shared_ptr<Avoid::PolygonInterface>, PyCallBack_Avoid_PolygonInterface> cl(M("Avoid"), "PolygonInterface", "A common interface used by the Polygon classes.");
		cl.def( pybind11::init( [](){ return new PyCallBack_Avoid_PolygonInterface(); } ) );
		cl.def(pybind11::init<PyCallBack_Avoid_PolygonInterface const &>());
		cl.def("clear", (void (Avoid::PolygonInterface::*)()) &Avoid::PolygonInterface::clear, "Resets this to the empty polygon.\n\nC++: Avoid::PolygonInterface::clear() --> void");
		cl.def("empty", (bool (Avoid::PolygonInterface::*)() const) &Avoid::PolygonInterface::empty, "Returns true if this polygon is empty.\n\nC++: Avoid::PolygonInterface::empty() const --> bool");
		cl.def("size", (unsigned long (Avoid::PolygonInterface::*)() const) &Avoid::PolygonInterface::size, "Returns the number of points in this polygon.\n\nC++: Avoid::PolygonInterface::size() const --> unsigned long");
		cl.def("id", (int (Avoid::PolygonInterface::*)() const) &Avoid::PolygonInterface::id, "Returns the ID value associated with this polygon.\n\nC++: Avoid::PolygonInterface::id() const --> int");
		cl.def("at", (const class Avoid::Point & (Avoid::PolygonInterface::*)(unsigned long) const) &Avoid::PolygonInterface::at, "Returns a specific point in the polygon.\n \n\n  The array index of the point to be returned.\n\nC++: Avoid::PolygonInterface::at(unsigned long) const --> const class Avoid::Point &", pybind11::return_value_policy::automatic, pybind11::arg("index"));
		cl.def("boundingRectPolygon", (class Avoid::Polygon (Avoid::PolygonInterface::*)() const) &Avoid::PolygonInterface::boundingRectPolygon, "Returns the bounding rectangle for this polygon.\n\n \n A new Rectangle representing the bounding box.\n\nC++: Avoid::PolygonInterface::boundingRectPolygon() const --> class Avoid::Polygon");
		cl.def("offsetBoundingBox", (class Avoid::Box (Avoid::PolygonInterface::*)(double) const) &Avoid::PolygonInterface::offsetBoundingBox, "Returns the bounding rectangle that contains this polygon\n         with optionally some buffer space around it for routing.\n\n If a buffer distance of zero is given, then this method returns\n the bounding rectangle for the shape's polygon.\n\n \n  Extra distance to pad each side of the rect.\n \n\n    The bounding box for the polygon.\n\nC++: Avoid::PolygonInterface::offsetBoundingBox(double) const --> class Avoid::Box", pybind11::arg("offset"));
		cl.def("offsetPolygon", (class Avoid::Polygon (Avoid::PolygonInterface::*)(double) const) &Avoid::PolygonInterface::offsetPolygon, "C++: Avoid::PolygonInterface::offsetPolygon(double) const --> class Avoid::Polygon", pybind11::arg("offset"));
		cl.def("assign", (class Avoid::PolygonInterface & (Avoid::PolygonInterface::*)(const class Avoid::PolygonInterface &)) &Avoid::PolygonInterface::operator=, "C++: Avoid::PolygonInterface::operator=(const class Avoid::PolygonInterface &) --> class Avoid::PolygonInterface &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::Edge file:libavoid/geomtypes.h line:188
		pybind11::class_<Avoid::Edge, std::shared_ptr<Avoid::Edge>> cl(M("Avoid"), "Edge", "A line between two points. ");
		cl.def( pybind11::init( [](){ return new Avoid::Edge(); } ) );
		cl.def_readwrite("a", &Avoid::Edge::a);
		cl.def_readwrite("b", &Avoid::Edge::b);
	}
	{ // Avoid::Polygon file:libavoid/geomtypes.h line:207
		pybind11::class_<Avoid::Polygon, std::shared_ptr<Avoid::Polygon>, PyCallBack_Avoid_Polygon, Avoid::PolygonInterface> cl(M("Avoid"), "Polygon", "A dynamic Polygon, to which points can be easily added and removed.\n\n \n The Rectangle class can be used as an easy way of constructing a\n       square or rectangular polygon.");
		cl.def( pybind11::init( [](){ return new Avoid::Polygon(); }, [](){ return new PyCallBack_Avoid_Polygon(); } ) );
		cl.def( pybind11::init<const int>(), pybind11::arg("n") );

		cl.def( pybind11::init<const class Avoid::PolygonInterface &>(), pybind11::arg("poly") );

		cl.def( pybind11::init( [](PyCallBack_Avoid_Polygon const &o){ return new PyCallBack_Avoid_Polygon(o); } ) );
		cl.def( pybind11::init( [](Avoid::Polygon const &o){ return new Avoid::Polygon(o); } ) );
		cl.def_readwrite("_id", &Avoid::Polygon::_id);
		cl.def_readwrite("ps", &Avoid::Polygon::ps);
		cl.def_readwrite("ts", &Avoid::Polygon::ts);
		cl.def_readwrite("checkpointsOnRoute", &Avoid::Polygon::checkpointsOnRoute);
		cl.def("clear", (void (Avoid::Polygon::*)()) &Avoid::Polygon::clear, "Resets this to the empty polygon.\n\nC++: Avoid::Polygon::clear() --> void");
		cl.def("empty", (bool (Avoid::Polygon::*)() const) &Avoid::Polygon::empty, "Returns true if this polygon is empty.\n\nC++: Avoid::Polygon::empty() const --> bool");
		cl.def("size", (unsigned long (Avoid::Polygon::*)() const) &Avoid::Polygon::size, "Returns the number of points in this polygon.\n\nC++: Avoid::Polygon::size() const --> unsigned long");
		cl.def("id", (int (Avoid::Polygon::*)() const) &Avoid::Polygon::id, "Returns the ID value associated with this polygon.\n\nC++: Avoid::Polygon::id() const --> int");
		cl.def("at", (const class Avoid::Point & (Avoid::Polygon::*)(unsigned long) const) &Avoid::Polygon::at, "Returns a specific point in the polygon.\n \n\n  The array index of the point to be returned.\n\nC++: Avoid::Polygon::at(unsigned long) const --> const class Avoid::Point &", pybind11::return_value_policy::automatic, pybind11::arg("index"));
		cl.def("setPoint", (void (Avoid::Polygon::*)(unsigned long, const class Avoid::Point &)) &Avoid::Polygon::setPoint, "Sets a position for a particular point in the polygon..\n \n\n  The array index of the point to be set.\n \n\n  The point value to be assigned..\n\nC++: Avoid::Polygon::setPoint(unsigned long, const class Avoid::Point &) --> void", pybind11::arg("index"), pybind11::arg("point"));
		cl.def("simplify", (class Avoid::Polygon (Avoid::Polygon::*)() const) &Avoid::Polygon::simplify, "Returns a simplified Polyline, where all collinear line\n         segments have been collapsed down into single line \n         segments.\n\n \n A new polyline with a simplified representation.\n\nC++: Avoid::Polygon::simplify() const --> class Avoid::Polygon");
		cl.def("curvedPolyline", [](Avoid::Polygon const &o, const double & a0) -> Avoid::Polygon { return o.curvedPolyline(a0); }, "", pybind11::arg("curve_amount"));
		cl.def("curvedPolyline", (class Avoid::Polygon (Avoid::Polygon::*)(const double, const bool) const) &Avoid::Polygon::curvedPolyline, "Returns a curved approximation of this multi-segment \n         PolyLine, with the corners replaced by smooth Bezier \n         curves.\n\n This function does not do any further obstacle avoidance with the\n curves produced.  Hence, you would usually specify a curve_amount\n in similar size to the space buffer around obstacles in the scene.\n This way the curves will cut the corners around shapes but still\n run within this buffer space.\n\n \n  Describes the distance along the end of each \n                       line segment to turn into a curve.\n \n\n        Describes whether the Polygon should be \n                       treated as closed.  Defaults to false.\n \n\n A new polyline (polygon) representing the curved path.\n         Its points represent endpoints of line segments and \n         Bezier spline control points.  The Polygon::ts vector for\n         this returned polygon is populated with a character for \n         each point describing its type.\n \n\n     ts\n\nC++: Avoid::Polygon::curvedPolyline(const double, const bool) const --> class Avoid::Polygon", pybind11::arg("curve_amount"), pybind11::arg("closed"));
		cl.def("translate", (void (Avoid::Polygon::*)(const double, const double)) &Avoid::Polygon::translate, "Translates the polygon position by a relative amount.\n\n \n  Distance to move polygon in the x dimension.\n \n\n  Distance to move polygon in the y dimension.\n\nC++: Avoid::Polygon::translate(const double, const double) --> void", pybind11::arg("xDist"), pybind11::arg("yDist"));
		cl.def("assign", (class Avoid::Polygon & (Avoid::Polygon::*)(const class Avoid::Polygon &)) &Avoid::Polygon::operator=, "C++: Avoid::Polygon::operator=(const class Avoid::Polygon &) --> class Avoid::Polygon &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::ReferencingPolygon file:libavoid/geomtypes.h line:336
		pybind11::class_<Avoid::ReferencingPolygon, std::shared_ptr<Avoid::ReferencingPolygon>, PyCallBack_Avoid_ReferencingPolygon, Avoid::PolygonInterface> cl(M("Avoid"), "ReferencingPolygon", "A Polygon which just references its points from other Polygons.\n\n This type of Polygon is used to accurately represent cluster boundaries \n made up from the corner points of shapes.");
		cl.def( pybind11::init( [](){ return new Avoid::ReferencingPolygon(); }, [](){ return new PyCallBack_Avoid_ReferencingPolygon(); } ) );
		cl.def( pybind11::init<const class Avoid::Polygon &, const class Avoid::Router *>(), pybind11::arg("poly"), pybind11::arg("router") );

		cl.def( pybind11::init( [](PyCallBack_Avoid_ReferencingPolygon const &o){ return new PyCallBack_Avoid_ReferencingPolygon(o); } ) );
		cl.def( pybind11::init( [](Avoid::ReferencingPolygon const &o){ return new Avoid::ReferencingPolygon(o); } ) );
		cl.def_readwrite("_id", &Avoid::ReferencingPolygon::_id);
		cl.def_readwrite("psRef", &Avoid::ReferencingPolygon::psRef);
		cl.def_readwrite("psPoints", &Avoid::ReferencingPolygon::psPoints);
		cl.def("clear", (void (Avoid::ReferencingPolygon::*)()) &Avoid::ReferencingPolygon::clear, "C++: Avoid::ReferencingPolygon::clear() --> void");
		cl.def("empty", (bool (Avoid::ReferencingPolygon::*)() const) &Avoid::ReferencingPolygon::empty, "C++: Avoid::ReferencingPolygon::empty() const --> bool");
		cl.def("size", (unsigned long (Avoid::ReferencingPolygon::*)() const) &Avoid::ReferencingPolygon::size, "C++: Avoid::ReferencingPolygon::size() const --> unsigned long");
		cl.def("id", (int (Avoid::ReferencingPolygon::*)() const) &Avoid::ReferencingPolygon::id, "C++: Avoid::ReferencingPolygon::id() const --> int");
		cl.def("at", (const class Avoid::Point & (Avoid::ReferencingPolygon::*)(unsigned long) const) &Avoid::ReferencingPolygon::at, "C++: Avoid::ReferencingPolygon::at(unsigned long) const --> const class Avoid::Point &", pybind11::return_value_policy::automatic, pybind11::arg("index"));
		cl.def("assign", (class Avoid::ReferencingPolygon & (Avoid::ReferencingPolygon::*)(const class Avoid::ReferencingPolygon &)) &Avoid::ReferencingPolygon::operator=, "C++: Avoid::ReferencingPolygon::operator=(const class Avoid::ReferencingPolygon &) --> class Avoid::ReferencingPolygon &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::Rectangle file:libavoid/geomtypes.h line:356
		pybind11::class_<Avoid::Rectangle, std::shared_ptr<Avoid::Rectangle>, PyCallBack_Avoid_Rectangle, Avoid::Polygon> cl(M("Avoid"), "Rectangle", "A Rectangle, a simpler way to define the polygon for square or\n         rectangular shapes.");
		cl.def( pybind11::init<const class Avoid::Point &, const class Avoid::Point &>(), pybind11::arg("topLeft"), pybind11::arg("bottomRight") );

		cl.def( pybind11::init<const class Avoid::Point &, const double, const double>(), pybind11::arg("centre"), pybind11::arg("width"), pybind11::arg("height") );

		cl.def("assign", (class Avoid::Rectangle & (Avoid::Rectangle::*)(const class Avoid::Rectangle &)) &Avoid::Rectangle::operator=, "C++: Avoid::Rectangle::operator=(const class Avoid::Rectangle &) --> class Avoid::Rectangle &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// Avoid::euclideanDist(const class Avoid::Point &, const class Avoid::Point &) file:libavoid/geometry.h line:45
	M("Avoid").def("euclideanDist", (double (*)(const class Avoid::Point &, const class Avoid::Point &)) &Avoid::euclideanDist, "C++: Avoid::euclideanDist(const class Avoid::Point &, const class Avoid::Point &) --> double", pybind11::arg("a"), pybind11::arg("b"));

	// Avoid::manhattanDist(const class Avoid::Point &, const class Avoid::Point &) file:libavoid/geometry.h line:46
	M("Avoid").def("manhattanDist", (double (*)(const class Avoid::Point &, const class Avoid::Point &)) &Avoid::manhattanDist, "C++: Avoid::manhattanDist(const class Avoid::Point &, const class Avoid::Point &) --> double", pybind11::arg("a"), pybind11::arg("b"));

}
