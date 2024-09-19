#include <_stdio.h>
#include <libcola/box.h>
#include <libcola/cluster.h>
#include <libcola/commondefs.h>
#include <libcola/gradient_projection.h>
#include <libcola/shapepair.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <memory>
#include <sstream> // __str__
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

// cola::RootCluster file:libcola/cluster.h line:172
struct PyCallBack_cola_RootCluster : public cola::RootCluster {
	using cola::RootCluster::RootCluster;

	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RootCluster *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return RootCluster::printCreationCode(a0);
	}
	void outputToSVG(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RootCluster *>(this), "outputToSVG");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return RootCluster::outputToSVG(a0);
	}
	void addChildNode(unsigned int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RootCluster *>(this), "addChildNode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Cluster::addChildNode(a0);
	}
	class cola::Box padding() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RootCluster *>(this), "padding");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::Box>::value) {
				static pybind11::detail::override_caster_t<class cola::Box> caster;
				return pybind11::detail::cast_ref<class cola::Box>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::Box>(std::move(o));
		}
		return Cluster::padding();
	}
	class cola::Box margin() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RootCluster *>(this), "margin");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::Box>::value) {
				static pybind11::detail::override_caster_t<class cola::Box> caster;
				return pybind11::detail::cast_ref<class cola::Box>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::Box>(std::move(o));
		}
		return Cluster::margin();
	}
	bool clusterIsFromFixedRectangle() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RootCluster *>(this), "clusterIsFromFixedRectangle");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Cluster::clusterIsFromFixedRectangle();
	}
};

// cola::RectangularCluster file:libcola/cluster.h line:218
struct PyCallBack_cola_RectangularCluster : public cola::RectangularCluster {
	using cola::RectangularCluster::RectangularCluster;

	class cola::Box margin() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RectangularCluster *>(this), "margin");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::Box>::value) {
				static pybind11::detail::override_caster_t<class cola::Box> caster;
				return pybind11::detail::cast_ref<class cola::Box>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::Box>(std::move(o));
		}
		return RectangularCluster::margin();
	}
	class cola::Box padding() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RectangularCluster *>(this), "padding");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::Box>::value) {
				static pybind11::detail::override_caster_t<class cola::Box> caster;
				return pybind11::detail::cast_ref<class cola::Box>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::Box>(std::move(o));
		}
		return RectangularCluster::padding();
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RectangularCluster *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return RectangularCluster::printCreationCode(a0);
	}
	void outputToSVG(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RectangularCluster *>(this), "outputToSVG");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return RectangularCluster::outputToSVG(a0);
	}
	void addChildNode(unsigned int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RectangularCluster *>(this), "addChildNode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return RectangularCluster::addChildNode(a0);
	}
	bool clusterIsFromFixedRectangle() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::RectangularCluster *>(this), "clusterIsFromFixedRectangle");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return RectangularCluster::clusterIsFromFixedRectangle();
	}
};

// cola::ConvexCluster file:libcola/cluster.h line:358
struct PyCallBack_cola_ConvexCluster : public cola::ConvexCluster {
	using cola::ConvexCluster::ConvexCluster;

	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ConvexCluster *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return ConvexCluster::printCreationCode(a0);
	}
	void outputToSVG(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ConvexCluster *>(this), "outputToSVG");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return ConvexCluster::outputToSVG(a0);
	}
	void addChildNode(unsigned int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ConvexCluster *>(this), "addChildNode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Cluster::addChildNode(a0);
	}
	class cola::Box padding() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ConvexCluster *>(this), "padding");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::Box>::value) {
				static pybind11::detail::override_caster_t<class cola::Box> caster;
				return pybind11::detail::cast_ref<class cola::Box>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::Box>(std::move(o));
		}
		return Cluster::padding();
	}
	class cola::Box margin() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ConvexCluster *>(this), "margin");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::Box>::value) {
				static pybind11::detail::override_caster_t<class cola::Box> caster;
				return pybind11::detail::cast_ref<class cola::Box>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::Box>(std::move(o));
		}
		return Cluster::margin();
	}
	bool clusterIsFromFixedRectangle() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ConvexCluster *>(this), "clusterIsFromFixedRectangle");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Cluster::clusterIsFromFixedRectangle();
	}
};

void bind_libcola_commondefs(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// cola::NonOverlapConstraintsMode file:libcola/commondefs.h line:47
	pybind11::enum_<cola::NonOverlapConstraintsMode>(M("cola"), "NonOverlapConstraintsMode", pybind11::arithmetic(), "")
		.value("None", cola::None)
		.value("Horizontal", cola::Horizontal)
		.value("Both", cola::Both)
		.export_values();

;

	{ // cola::FixedList file:libcola/commondefs.h line:49
		pybind11::class_<cola::FixedList, std::shared_ptr<cola::FixedList>> cl(M("cola"), "FixedList", "");
		cl.def( pybind11::init<const unsigned int>(), pybind11::arg("n") );

		cl.def( pybind11::init( [](cola::FixedList const &o){ return new cola::FixedList(o); } ) );
		cl.def("set", [](cola::FixedList &o, const unsigned int & a0) -> void { return o.set(a0); }, "", pybind11::arg("i"));
		cl.def("set", (void (cola::FixedList::*)(const unsigned int, const bool)) &cola::FixedList::set, "C++: cola::FixedList::set(const unsigned int, const bool) --> void", pybind11::arg("i"), pybind11::arg("value"));
		cl.def("check", (bool (cola::FixedList::*)(const unsigned int) const) &cola::FixedList::check, "C++: cola::FixedList::check(const unsigned int) const --> bool", pybind11::arg("i"));
		cl.def("unsetAll", (void (cola::FixedList::*)()) &cola::FixedList::unsetAll, "C++: cola::FixedList::unsetAll() --> void");
		cl.def("fixAll", (void (cola::FixedList::*)(bool)) &cola::FixedList::fixAll, "C++: cola::FixedList::fixAll(bool) --> void", pybind11::arg("val"));
	}
	{ // cola::delete_object file:libcola/commondefs.h line:79
		pybind11::class_<cola::delete_object, std::shared_ptr<cola::delete_object>> cl(M("cola"), "delete_object", "");
		cl.def( pybind11::init( [](){ return new cola::delete_object(); } ) );
	}
	{ // cola::ShapePair file:libcola/shapepair.h line:32
		pybind11::class_<cola::ShapePair, std::shared_ptr<cola::ShapePair>> cl(M("cola"), "ShapePair", "");
		cl.def( pybind11::init<unsigned int, unsigned int>(), pybind11::arg("ind1"), pybind11::arg("ind2") );

		cl.def( pybind11::init( [](cola::ShapePair const &o){ return new cola::ShapePair(o); } ) );
		cl.def("index1", (unsigned short (cola::ShapePair::*)() const) &cola::ShapePair::index1, "C++: cola::ShapePair::index1() const --> unsigned short");
		cl.def("index2", (unsigned short (cola::ShapePair::*)() const) &cola::ShapePair::index2, "C++: cola::ShapePair::index2() const --> unsigned short");
		cl.def("assign", (class cola::ShapePair & (cola::ShapePair::*)(const class cola::ShapePair &)) &cola::ShapePair::operator=, "C++: cola::ShapePair::operator=(const class cola::ShapePair &) --> class cola::ShapePair &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::Cluster file:libcola/cluster.h line:50
		pybind11::class_<cola::Cluster, std::shared_ptr<cola::Cluster>> cl(M("cola"), "Cluster", "A cluster defines a hierarchical partitioning over the nodes\n         which should be kept disjoint by the layout somehow.\n\n You should not use this directly.  This is an abstract base class.  \n At the top level you should be using RootCluster, and then below that \n either RectangualarCLuster or ConvexCluster.");
		cl.def_readwrite("bounds", &cola::Cluster::bounds);
		cl.def_readwrite("varRect", &cola::Cluster::varRect);
		cl.def_readwrite("clusterVarId", &cola::Cluster::clusterVarId);
		cl.def_readwrite("varWeight", &cola::Cluster::varWeight);
		cl.def_readwrite("internalEdgeWeightFactor", &cola::Cluster::internalEdgeWeightFactor);
		cl.def_readwrite("nodes", &cola::Cluster::nodes);
		cl.def_readwrite("clusters", &cola::Cluster::clusters);
		cl.def_readwrite("hullX", &cola::Cluster::hullX);
		cl.def_readwrite("hullY", &cola::Cluster::hullY);
		cl.def("addChildNode", (void (cola::Cluster::*)(unsigned int)) &cola::Cluster::addChildNode, "Mark a rectangle as being a child of this cluster.\n\n \n  The index of the Rectangle in the rectangles vector.\n\nC++: cola::Cluster::addChildNode(unsigned int) --> void", pybind11::arg("index"));
		cl.def("addChildCluster", (void (cola::Cluster::*)(class cola::Cluster *)) &cola::Cluster::addChildCluster, "Mark a cluster as being a sub-cluster of this cluster.\n\n \n  The Cluster to be marked as a sub-cluster.\n\nC++: cola::Cluster::addChildCluster(class cola::Cluster *) --> void", pybind11::arg("cluster"));
		cl.def("padding", (class cola::Box (cola::Cluster::*)() const) &cola::Cluster::padding, "C++: cola::Cluster::padding() const --> class cola::Box");
		cl.def("margin", (class cola::Box (cola::Cluster::*)() const) &cola::Cluster::margin, "C++: cola::Cluster::margin() const --> class cola::Box");
		cl.def("setDesiredBounds", (void (cola::Cluster::*)(const class vpsc::Rectangle)) &cola::Cluster::setDesiredBounds, "C++: cola::Cluster::setDesiredBounds(const class vpsc::Rectangle) --> void", pybind11::arg("bounds"));
		cl.def("unsetDesiredBounds", (void (cola::Cluster::*)()) &cola::Cluster::unsetDesiredBounds, "C++: cola::Cluster::unsetDesiredBounds() --> void");
		cl.def("printCreationCode", (void (cola::Cluster::*)(struct __sFILE *) const) &cola::Cluster::printCreationCode, "C++: cola::Cluster::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("clusterIsFromFixedRectangle", (bool (cola::Cluster::*)() const) &cola::Cluster::clusterIsFromFixedRectangle, "C++: cola::Cluster::clusterIsFromFixedRectangle() const --> bool");
		cl.def("outputToSVG", (void (cola::Cluster::*)(struct __sFILE *) const) &cola::Cluster::outputToSVG, "C++: cola::Cluster::outputToSVG(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("updateBounds", (void (cola::Cluster::*)(const enum vpsc::Dim)) &cola::Cluster::updateBounds, "C++: cola::Cluster::updateBounds(const enum vpsc::Dim) --> void", pybind11::arg("dim"));
		cl.def("assign", (class cola::Cluster & (cola::Cluster::*)(const class cola::Cluster &)) &cola::Cluster::operator=, "C++: cola::Cluster::operator=(const class cola::Cluster &) --> class cola::Cluster &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::RootCluster file:libcola/cluster.h line:172
		pybind11::class_<cola::RootCluster, std::shared_ptr<cola::RootCluster>, PyCallBack_cola_RootCluster, cola::Cluster> cl(M("cola"), "RootCluster", "Holds the cluster hierarchy specification for a diagram.\n\n This is not considered a cluster itself, but it records all the nodes in \n the diagram not contained within any clusters, as well as optionally a \n hierarchy of clusters.\n\n You can add clusters via addChildCluster() and nodes via addChildNode().\n\n You can specify just the shapes contained in clusters, but not the nodes \n at this top level---the library will add any remaining nodes not appearing \n in the cluster hierarchy as children of the root cluster.\n\n It is possible to add a node as the child of two parent clusters.  In this \n case, the clusters will overlap to contain this (and possibly other nodes).\n The library will warn you if you do this unless you have called the method\n setAllowsMultipleParents() to mark this intention.\n\n Be careful not to create cycles in the cluster hierarchy (i.e., to mark \n two clusters as children of each other.  The library does not check for \n this and strange things may occur.");
		cl.def( pybind11::init( [](){ return new cola::RootCluster(); }, [](){ return new PyCallBack_cola_RootCluster(); } ) );
		cl.def( pybind11::init( [](PyCallBack_cola_RootCluster const &o){ return new PyCallBack_cola_RootCluster(o); } ) );
		cl.def( pybind11::init( [](cola::RootCluster const &o){ return new cola::RootCluster(o); } ) );
		cl.def("flat", (bool (cola::RootCluster::*)() const) &cola::RootCluster::flat, "C++: cola::RootCluster::flat() const --> bool");
		cl.def("printCreationCode", (void (cola::RootCluster::*)(struct __sFILE *) const) &cola::RootCluster::printCreationCode, "C++: cola::RootCluster::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("outputToSVG", (void (cola::RootCluster::*)(struct __sFILE *) const) &cola::RootCluster::outputToSVG, "C++: cola::RootCluster::outputToSVG(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("allowsMultipleParents", (bool (cola::RootCluster::*)() const) &cola::RootCluster::allowsMultipleParents, "Returns true if this cluster hierarchy allows multiple parents, \n otherwise returns false.\n\n Defaults to false.  If this is false, the library will display\n warnings if you add a single node to multiple clusters.\n\n \n setAllowsMultipleParents()\n\nC++: cola::RootCluster::allowsMultipleParents() const --> bool");
		cl.def("setAllowsMultipleParents", (void (cola::RootCluster::*)(const bool)) &cola::RootCluster::setAllowsMultipleParents, "Set whether the cluster hierarchy should allow multiple parents.\n\n \n New value for this setting.\n\n sa allowsMultipleParents()\n\nC++: cola::RootCluster::setAllowsMultipleParents(const bool) --> void", pybind11::arg("value"));
		cl.def("assign", (class cola::RootCluster & (cola::RootCluster::*)(const class cola::RootCluster &)) &cola::RootCluster::operator=, "C++: cola::RootCluster::operator=(const class cola::RootCluster &) --> class cola::RootCluster &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::RectangularCluster file:libcola/cluster.h line:218
		pybind11::class_<cola::RectangularCluster, std::shared_ptr<cola::RectangularCluster>, PyCallBack_cola_RectangularCluster, cola::Cluster> cl(M("cola"), "RectangularCluster", "Defines a rectangular cluster, either variable-sized with floating \n         sides or a fixed size based on a particular rectangle.\n\n The chosen constructor decides the type and behaviour of the cluster.");
		cl.def( pybind11::init( [](){ return new cola::RectangularCluster(); }, [](){ return new PyCallBack_cola_RectangularCluster(); } ) );
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("rectIndex") );

		cl.def( pybind11::init( [](PyCallBack_cola_RectangularCluster const &o){ return new PyCallBack_cola_RectangularCluster(o); } ) );
		cl.def( pybind11::init( [](cola::RectangularCluster const &o){ return new cola::RectangularCluster(o); } ) );
		cl.def("setMargin", (void (cola::RectangularCluster::*)(double)) &cola::RectangularCluster::setMargin, "Sets the margin size for this cluster.\n\n This value represents the outer spacing that will be put between\n the cluster boundary on all sides and other clusters (plus their \n margin) and rectangles at the same level when non-overlap \n constraints are enabled.\n\n \n  The size of the margin for this cluster.\n\nC++: cola::RectangularCluster::setMargin(double) --> void", pybind11::arg("margin"));
		cl.def("setMargin", (void (cola::RectangularCluster::*)(const class cola::Box)) &cola::RectangularCluster::setMargin, "Sets the margin box for this cluster.\n\n This box represents the outer spacing that will be put between\n the cluster boundary and other clusters (plus their margin) and \n rectangles at the same level when non-overlap constraints are \n enabled.\n\n \n  The box representing the margins for this \n                     cluster.\n\nC++: cola::RectangularCluster::setMargin(const class cola::Box) --> void", pybind11::arg("margin"));
		cl.def("margin", (class cola::Box (cola::RectangularCluster::*)() const) &cola::RectangularCluster::margin, "Returns the margin box for this cluster.\n\n \n  The margin box for the cluster.\n\nC++: cola::RectangularCluster::margin() const --> class cola::Box");
		cl.def("setPadding", (void (cola::RectangularCluster::*)(double)) &cola::RectangularCluster::setPadding, "Sets the padding size for this cluster.\n\n This value represents the inner spacing that will be put between\n the cluster boundary and other child clusters (plus their margin) \n and child rectangles on all sides.\n\n \n  The size of the padding for this cluster.\n\nC++: cola::RectangularCluster::setPadding(double) --> void", pybind11::arg("padding"));
		cl.def("setPadding", (void (cola::RectangularCluster::*)(const class cola::Box)) &cola::RectangularCluster::setPadding, "Sets the padding box for this cluster.\n\n This box represents the inner spacing that will be put between\n the cluster boundary and other child clusters (plus their margin) \n and child rectangles for each edge.\n\n \n  The Box representing padding values for this \n                      cluster.\n\nC++: cola::RectangularCluster::setPadding(const class cola::Box) --> void", pybind11::arg("padding"));
		cl.def("padding", (class cola::Box (cola::RectangularCluster::*)() const) &cola::RectangularCluster::padding, "Returns the padding box for this cluster.\n\n \n  The padding box for the cluster.\n\nC++: cola::RectangularCluster::padding() const --> class cola::Box");
		cl.def("printCreationCode", (void (cola::RectangularCluster::*)(struct __sFILE *) const) &cola::RectangularCluster::printCreationCode, "C++: cola::RectangularCluster::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("outputToSVG", (void (cola::RectangularCluster::*)(struct __sFILE *) const) &cola::RectangularCluster::outputToSVG, "C++: cola::RectangularCluster::outputToSVG(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("addChildNode", (void (cola::RectangularCluster::*)(unsigned int)) &cola::RectangularCluster::addChildNode, "C++: cola::RectangularCluster::addChildNode(unsigned int) --> void", pybind11::arg("index"));
		cl.def("getMinEdgeRect", (class vpsc::Rectangle * (cola::RectangularCluster::*)(const enum vpsc::Dim)) &cola::RectangularCluster::getMinEdgeRect, "C++: cola::RectangularCluster::getMinEdgeRect(const enum vpsc::Dim) --> class vpsc::Rectangle *", pybind11::return_value_policy::automatic, pybind11::arg("dim"));
		cl.def("getMaxEdgeRect", (class vpsc::Rectangle * (cola::RectangularCluster::*)(const enum vpsc::Dim)) &cola::RectangularCluster::getMaxEdgeRect, "C++: cola::RectangularCluster::getMaxEdgeRect(const enum vpsc::Dim) --> class vpsc::Rectangle *", pybind11::return_value_policy::automatic, pybind11::arg("dim"));
		cl.def("clusterIsFromFixedRectangle", (bool (cola::RectangularCluster::*)() const) &cola::RectangularCluster::clusterIsFromFixedRectangle, "C++: cola::RectangularCluster::clusterIsFromFixedRectangle() const --> bool");
		cl.def("rectangleIndex", (int (cola::RectangularCluster::*)() const) &cola::RectangularCluster::rectangleIndex, "C++: cola::RectangularCluster::rectangleIndex() const --> int");
		cl.def("assign", (class cola::RectangularCluster & (cola::RectangularCluster::*)(const class cola::RectangularCluster &)) &cola::RectangularCluster::operator=, "C++: cola::RectangularCluster::operator=(const class cola::RectangularCluster &) --> class cola::RectangularCluster &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::ConvexCluster file:libcola/cluster.h line:358
		pybind11::class_<cola::ConvexCluster, std::shared_ptr<cola::ConvexCluster>, PyCallBack_cola_ConvexCluster, cola::Cluster> cl(M("cola"), "ConvexCluster", "Defines a cluster that will be treated as a convex boundary around\n         the child nodes and clusters.");
		cl.def( pybind11::init( [](){ return new cola::ConvexCluster(); }, [](){ return new PyCallBack_cola_ConvexCluster(); } ) );
		cl.def( pybind11::init( [](PyCallBack_cola_ConvexCluster const &o){ return new PyCallBack_cola_ConvexCluster(o); } ) );
		cl.def( pybind11::init( [](cola::ConvexCluster const &o){ return new cola::ConvexCluster(o); } ) );
		cl.def_readwrite("hullRIDs", &cola::ConvexCluster::hullRIDs);
		cl.def_readwrite("hullCorners", &cola::ConvexCluster::hullCorners);
		cl.def("printCreationCode", (void (cola::ConvexCluster::*)(struct __sFILE *) const) &cola::ConvexCluster::printCreationCode, "C++: cola::ConvexCluster::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("outputToSVG", (void (cola::ConvexCluster::*)(struct __sFILE *) const) &cola::ConvexCluster::outputToSVG, "C++: cola::ConvexCluster::outputToSVG(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::ConvexCluster & (cola::ConvexCluster::*)(const class cola::ConvexCluster &)) &cola::ConvexCluster::operator=, "C++: cola::ConvexCluster::operator=(const class cola::ConvexCluster &) --> class cola::ConvexCluster &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// cola::SolveWithMosek file:libcola/gradient_projection.h line:45
	pybind11::enum_<cola::SolveWithMosek>(M("cola"), "SolveWithMosek", pybind11::arithmetic(), "")
		.value("Off", cola::Off)
		.value("Inner", cola::Inner)
		.value("Outer", cola::Outer)
		.export_values();

;

}
