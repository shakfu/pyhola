#include <_stdio.h>
#include <libcola/cluster.h>
#include <libcola/cola.h>
#include <libcola/compound_constraints.h>
#include <libcola/exceptions.h>
#include <libcola/pseudorandom.h>
#include <libcola/straightener.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <utility>
#include <valarray>
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

// cola::PreIteration file:libcola/cola.h line:168
struct PyCallBack_cola_PreIteration : public cola::PreIteration {
	using cola::PreIteration::PreIteration;

	bool operator()() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PreIteration *>(this), "__call__");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return PreIteration::operator()();
	}
};

// cola::TestConvergence file:libcola/cola.h line:216
struct PyCallBack_cola_TestConvergence : public cola::TestConvergence {
	using cola::TestConvergence::TestConvergence;

};

// cola::TopologyAddonInterface file:libcola/cola.h line:531
struct PyCallBack_cola_TopologyAddonInterface : public cola::TopologyAddonInterface {
	using cola::TopologyAddonInterface::TopologyAddonInterface;

	class cola::TopologyAddonInterface * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::TopologyAddonInterface *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::TopologyAddonInterface *>::value) {
				static pybind11::detail::override_caster_t<class cola::TopologyAddonInterface *> caster;
				return pybind11::detail::cast_ref<class cola::TopologyAddonInterface *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::TopologyAddonInterface *>(std::move(o));
		}
		return TopologyAddonInterface::clone();
	}
	void freeAssociatedObjects() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::TopologyAddonInterface *>(this), "freeAssociatedObjects");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return TopologyAddonInterface::freeAssociatedObjects();
	}
	double computeStress() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::TopologyAddonInterface *>(this), "computeStress");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<double>::value) {
				static pybind11::detail::override_caster_t<double> caster;
				return pybind11::detail::cast_ref<double>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<double>(std::move(o));
		}
		return TopologyAddonInterface::computeStress();
	}
	bool useTopologySolver() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::TopologyAddonInterface *>(this), "useTopologySolver");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return TopologyAddonInterface::useTopologySolver();
	}
};

void bind_libcola_exceptions(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::InvalidConstraint file:libcola/exceptions.h line:29
		pybind11::class_<cola::InvalidConstraint, std::shared_ptr<cola::InvalidConstraint>> cl(M("cola"), "InvalidConstraint", "");
		cl.def( pybind11::init<class cola::CompoundConstraint *>(), pybind11::arg("c") );

	}
	{ // cola::InvalidVariableIndexException file:libcola/exceptions.h line:35
		pybind11::class_<cola::InvalidVariableIndexException, std::shared_ptr<cola::InvalidVariableIndexException>> cl(M("cola"), "InvalidVariableIndexException", "");
		cl.def( pybind11::init<class cola::CompoundConstraint *, unsigned int>(), pybind11::arg("c"), pybind11::arg("i") );

		cl.def_readwrite("index", &cola::InvalidVariableIndexException::index);
	}
	{ // cola::PseudoRandom file:libcola/pseudorandom.h line:27
		pybind11::class_<cola::PseudoRandom, std::shared_ptr<cola::PseudoRandom>> cl(M("cola"), "PseudoRandom", "");
		cl.def( pybind11::init( [](){ return new cola::PseudoRandom(); } ), "doc" );
		cl.def( pybind11::init<double>(), pybind11::arg("s") );

		cl.def( pybind11::init( [](cola::PseudoRandom const &o){ return new cola::PseudoRandom(o); } ) );
		cl.def("getNext", (double (cola::PseudoRandom::*)()) &cola::PseudoRandom::getNext, "C++: cola::PseudoRandom::getNext() --> double");
		cl.def("getNextBetween", (double (cola::PseudoRandom::*)(double, double)) &cola::PseudoRandom::getNextBetween, "C++: cola::PseudoRandom::getNextBetween(double, double) --> double", pybind11::arg("min"), pybind11::arg("max"));
	}
	{ // cola::Lock file:libcola/cola.h line:78
		pybind11::class_<cola::Lock, std::shared_ptr<cola::Lock>> cl(M("cola"), "Lock", "A Lock specifies a required position for a node.");
		cl.def( pybind11::init( [](){ return new cola::Lock(); } ) );
		cl.def( pybind11::init<unsigned int, double, double>(), pybind11::arg("id"), pybind11::arg("X"), pybind11::arg("Y") );

		cl.def("getID", (unsigned int (cola::Lock::*)() const) &cola::Lock::getID, "C++: cola::Lock::getID() const --> unsigned int");
		cl.def("pos", (double (cola::Lock::*)(enum vpsc::Dim) const) &cola::Lock::pos, "C++: cola::Lock::pos(enum vpsc::Dim) const --> double", pybind11::arg("dim"));
	}
	{ // cola::Resize file:libcola/cola.h line:107
		pybind11::class_<cola::Resize, std::shared_ptr<cola::Resize>> cl(M("cola"), "Resize", "A Resize specifies a new required bounding box for a node.");
		cl.def( pybind11::init( [](){ return new cola::Resize(); } ) );
		cl.def( pybind11::init<unsigned int, double, double, double, double>(), pybind11::arg("id"), pybind11::arg("x"), pybind11::arg("y"), pybind11::arg("w"), pybind11::arg("h") );

		cl.def( pybind11::init( [](cola::Resize const &o){ return new cola::Resize(o); } ) );
		cl.def("getID", (unsigned int (cola::Resize::*)() const) &cola::Resize::getID, "C++: cola::Resize::getID() const --> unsigned int");
		cl.def("getTarget", (const class vpsc::Rectangle * (cola::Resize::*)() const) &cola::Resize::getTarget, "C++: cola::Resize::getTarget() const --> const class vpsc::Rectangle *", pybind11::return_value_policy::automatic);
	}
	{ // cola::DesiredPosition file:libcola/cola.h line:141
		pybind11::class_<cola::DesiredPosition, std::shared_ptr<cola::DesiredPosition>> cl(M("cola"), "DesiredPosition", "");
		cl.def( pybind11::init( [](){ return new cola::DesiredPosition(); } ) );
		cl.def_readwrite("id", &cola::DesiredPosition::id);
		cl.def_readwrite("x", &cola::DesiredPosition::x);
		cl.def_readwrite("y", &cola::DesiredPosition::y);
		cl.def_readwrite("weight", &cola::DesiredPosition::weight);
	}
	{ // cola::PreIteration file:libcola/cola.h line:168
		pybind11::class_<cola::PreIteration, std::shared_ptr<cola::PreIteration>, PyCallBack_cola_PreIteration> cl(M("cola"), "PreIteration", "A default functor that is called before each iteration in the \n        main loop of the ConstrainedFDLayout::run() method.\n\n Override the operator() for things like locking the position of nodes\n for the duration of the iteration.\n\n If the operator() returns false the subsequent iterations are\n abandoned, i.e., layout ends immediately.  You can make it return true\n when a user-interrupt is detected, for instance.");
		cl.def_readwrite("changed", &cola::PreIteration::changed);
		cl.def("__call__", (bool (cola::PreIteration::*)()) &cola::PreIteration::operator(), "C++: cola::PreIteration::operator()() --> bool");
	}
	{ // cola::TestConvergence file:libcola/cola.h line:216
		pybind11::class_<cola::TestConvergence, std::shared_ptr<cola::TestConvergence>, PyCallBack_cola_TestConvergence> cl(M("cola"), "TestConvergence", "A default functor that is called after each iteration of the layout\n         algorithm.\n\n You can either instantiate ConstrainedFDLayout with an instance of this\n class setting the tolerance and maxiterations as desired, or create a\n derived class implementing the operator() to do your own convergence test,\n or create your own operator() that calls the TestConvergence::operator() in\n order to do any other post processing you might need, e.g., to animate\n changes.");
		cl.def( pybind11::init( [](){ return new cola::TestConvergence(); }, [](){ return new PyCallBack_cola_TestConvergence(); } ), "doc");
		cl.def( pybind11::init( [](const double & a0){ return new cola::TestConvergence(a0); }, [](const double & a0){ return new PyCallBack_cola_TestConvergence(a0); } ), "doc");
		cl.def( pybind11::init<const double, const unsigned int>(), pybind11::arg("tol"), pybind11::arg("maxiterations") );

		cl.def_readwrite("old_stress", &cola::TestConvergence::old_stress);
		cl.def_readonly("tolerance", &cola::TestConvergence::tolerance);
		cl.def_readonly("maxiterations", &cola::TestConvergence::maxiterations);
		cl.def_readwrite("iterations", &cola::TestConvergence::iterations);
		cl.def("reset", (void (cola::TestConvergence::*)()) &cola::TestConvergence::reset, "C++: cola::TestConvergence::reset() --> void");
	}
	{ // cola::ConstrainedMajorizationLayout file:libcola/cola.h line:270
		pybind11::class_<cola::ConstrainedMajorizationLayout, std::shared_ptr<cola::ConstrainedMajorizationLayout>> cl(M("cola"), "ConstrainedMajorizationLayout", "Implements the Constrained Majorization graph layout algorithm \n         (deprecated).\n\n The optimisation method used is \"stress majorization\", where a sequence of \n quadratic functions which strictly bound the stress from above, is solved \n to monotonically reduce the stress (by iteratively changing the \n configuration of nodes).\n\n Once the problem has been set up, call run() or runOnce() to run the \n layout algorithm.\n\n \n  We recommend the use of ConstrainedFDLayout instead of this class. \n        ConstrainedFDLayout tends to produce better results and has more \n        features.  We are no longer working on ConstrainedMajorizationLayout.");
		cl.def( pybind11::init( [](cola::ConstrainedMajorizationLayout const &o){ return new cola::ConstrainedMajorizationLayout(o); } ) );
		cl.def("setScaling", (void (cola::ConstrainedMajorizationLayout::*)(bool)) &cola::ConstrainedMajorizationLayout::setScaling, "Scaling speeds up the solver by conditioning the quadratic terms matrix.\n\nC++: cola::ConstrainedMajorizationLayout::setScaling(bool) --> void", pybind11::arg("scaling"));
		cl.def("setExternalSolver", (void (cola::ConstrainedMajorizationLayout::*)(bool)) &cola::ConstrainedMajorizationLayout::setExternalSolver, "Says that the Mosek optimisation library should be used to solve the \n quadratic programs rather than the libvpsc solver.\n\nC++: cola::ConstrainedMajorizationLayout::setExternalSolver(bool) --> void", pybind11::arg("externalSolver"));
		cl.def("setAvoidOverlaps", [](cola::ConstrainedMajorizationLayout &o) -> void { return o.setAvoidOverlaps(); }, "");
		cl.def("setAvoidOverlaps", (void (cola::ConstrainedMajorizationLayout::*)(bool)) &cola::ConstrainedMajorizationLayout::setAvoidOverlaps, "At each iteration of layout, generate constraints to avoid overlaps.\n If bool horizontal is true, all overlaps will be resolved horizontally, \n otherwise some overlaps will be left to be resolved vertically where \n doing so leads to less displacement\n\nC++: cola::ConstrainedMajorizationLayout::setAvoidOverlaps(bool) --> void", pybind11::arg("horizontal"));
		cl.def("setNonOverlappingClusters", (void (cola::ConstrainedMajorizationLayout::*)()) &cola::ConstrainedMajorizationLayout::setNonOverlappingClusters, "Add constraints to prevent clusters overlapping.\n\nC++: cola::ConstrainedMajorizationLayout::setNonOverlappingClusters() --> void");
		cl.def("moveBoundingBoxes", (void (cola::ConstrainedMajorizationLayout::*)()) &cola::ConstrainedMajorizationLayout::moveBoundingBoxes, "Update position of bounding boxes.\n\nC++: cola::ConstrainedMajorizationLayout::moveBoundingBoxes() --> void");
		cl.def("run", [](cola::ConstrainedMajorizationLayout &o) -> void { return o.run(); }, "");
		cl.def("run", [](cola::ConstrainedMajorizationLayout &o, bool const & a0) -> void { return o.run(a0); }, "", pybind11::arg("x"));
		cl.def("run", (void (cola::ConstrainedMajorizationLayout::*)(bool, bool)) &cola::ConstrainedMajorizationLayout::run, "Implements the main layout loop, taking descent steps until\n         stress is no-longer significantly reduced.\n\n \n  If true, layout will be performed in x-dimension\n               (default: true).\n \n\n  If true, layout will be performed in y-dimension\n               (default: true).\n\nC++: cola::ConstrainedMajorizationLayout::run(bool, bool) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("runOnce", [](cola::ConstrainedMajorizationLayout &o) -> void { return o.runOnce(); }, "");
		cl.def("runOnce", [](cola::ConstrainedMajorizationLayout &o, bool const & a0) -> void { return o.runOnce(a0); }, "", pybind11::arg("x"));
		cl.def("runOnce", (void (cola::ConstrainedMajorizationLayout::*)(bool, bool)) &cola::ConstrainedMajorizationLayout::runOnce, "Same as run(), but only applies one iteration.  \n\n This may be useful here it's too hard to implement a call-back \n (e.g., in java apps).\n\n \n  If true, layout will be performed in x-dimension\n               (default: true).\n \n\n  If true, layout will be performed in y-dimension\n               (default: true).\n\nC++: cola::ConstrainedMajorizationLayout::runOnce(bool, bool) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("setConstrainedLayout", (void (cola::ConstrainedMajorizationLayout::*)(bool)) &cola::ConstrainedMajorizationLayout::setConstrainedLayout, "C++: cola::ConstrainedMajorizationLayout::setConstrainedLayout(bool) --> void", pybind11::arg("c"));
		cl.def("computeStress", (double (cola::ConstrainedMajorizationLayout::*)()) &cola::ConstrainedMajorizationLayout::computeStress, "C++: cola::ConstrainedMajorizationLayout::computeStress() --> double");
	}
	{ // cola::TopologyAddonInterface file:libcola/cola.h line:531
		pybind11::class_<cola::TopologyAddonInterface, std::shared_ptr<cola::TopologyAddonInterface>, PyCallBack_cola_TopologyAddonInterface> cl(M("cola"), "TopologyAddonInterface", "Interface for writing COLA addons to handle topology preserving \n         layout.");
		cl.def( pybind11::init( [](){ return new cola::TopologyAddonInterface(); }, [](){ return new PyCallBack_cola_TopologyAddonInterface(); } ) );
		cl.def( pybind11::init( [](PyCallBack_cola_TopologyAddonInterface const &o){ return new PyCallBack_cola_TopologyAddonInterface(o); } ) );
		cl.def( pybind11::init( [](cola::TopologyAddonInterface const &o){ return new cola::TopologyAddonInterface(o); } ) );
		cl.def("clone", (class cola::TopologyAddonInterface * (cola::TopologyAddonInterface::*)() const) &cola::TopologyAddonInterface::clone, "C++: cola::TopologyAddonInterface::clone() const --> class cola::TopologyAddonInterface *", pybind11::return_value_policy::automatic);
		cl.def("freeAssociatedObjects", (void (cola::TopologyAddonInterface::*)()) &cola::TopologyAddonInterface::freeAssociatedObjects, "C++: cola::TopologyAddonInterface::freeAssociatedObjects() --> void");
		cl.def("computeStress", (double (cola::TopologyAddonInterface::*)() const) &cola::TopologyAddonInterface::computeStress, "C++: cola::TopologyAddonInterface::computeStress() const --> double");
		cl.def("useTopologySolver", (bool (cola::TopologyAddonInterface::*)() const) &cola::TopologyAddonInterface::useTopologySolver, "C++: cola::TopologyAddonInterface::useTopologySolver() const --> bool");
		cl.def("assign", (class cola::TopologyAddonInterface & (cola::TopologyAddonInterface::*)(const class cola::TopologyAddonInterface &)) &cola::TopologyAddonInterface::operator=, "C++: cola::TopologyAddonInterface::operator=(const class cola::TopologyAddonInterface &) --> class cola::TopologyAddonInterface &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::ConstrainedFDLayout file:libcola/cola.h line:622
		pybind11::class_<cola::ConstrainedFDLayout, std::shared_ptr<cola::ConstrainedFDLayout>> cl(M("cola"), "ConstrainedFDLayout", "Implements a constrained force-directed layout algorithm.\n\n This method is based on a non-linear gradient projection technique.\n Conceptually it's similar to a force directed method like\n Fruchterman-Reingold---but using a more principled goal function and\n optimisation techniques.");
		cl.def( pybind11::init( [](cola::ConstrainedFDLayout const &o){ return new cola::ConstrainedFDLayout(o); } ) );
		cl.def("run", [](cola::ConstrainedFDLayout &o) -> void { return o.run(); }, "");
		cl.def("run", [](cola::ConstrainedFDLayout &o, bool const & a0) -> void { return o.run(a0); }, "", pybind11::arg("x"));
		cl.def("run", (void (cola::ConstrainedFDLayout::*)(bool, bool)) &cola::ConstrainedFDLayout::run, "Implements the main layout loop, taking descent steps until\n         stress is no-longer significantly reduced.\n\n \n  If true, layout will be performed in x-dimension\n               (default: true).\n \n\n  If true, layout will be performed in y-dimension\n               (default: true).\n\nC++: cola::ConstrainedFDLayout::run(bool, bool) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("runOnce", [](cola::ConstrainedFDLayout &o) -> void { return o.runOnce(); }, "");
		cl.def("runOnce", [](cola::ConstrainedFDLayout &o, bool const & a0) -> void { return o.runOnce(a0); }, "", pybind11::arg("x"));
		cl.def("runOnce", (void (cola::ConstrainedFDLayout::*)(bool, bool)) &cola::ConstrainedFDLayout::runOnce, "Same as run(), but only applies one iteration.  \n\n This may be useful here it's too hard to implement a call-back \n (e.g., in java apps).\n\n \n  If true, layout will be performed in x-dimension\n               (default: true).\n \n\n  If true, layout will be performed in y-dimension\n               (default: true).\n\nC++: cola::ConstrainedFDLayout::runOnce(bool, bool) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("setTopology", (void (cola::ConstrainedFDLayout::*)(class cola::TopologyAddonInterface *)) &cola::ConstrainedFDLayout::setTopology, "Set an addon for doing topology preserving layout.\n\n  It is expected that you would use the topology::ColaTopologyAddon() \n  from libtopology rather than write your own.  This is done so that \n  libcola does not have to depend on libtopology.\n\n  \n  Instance of a class implementing the\n                       TopologyAddonInterface.\n  \n\n topology::ColaTopologyAddon\n\nC++: cola::ConstrainedFDLayout::setTopology(class cola::TopologyAddonInterface *) --> void", pybind11::arg("topology"));
		cl.def("getTopology", (class cola::TopologyAddonInterface * (cola::ConstrainedFDLayout::*)()) &cola::ConstrainedFDLayout::getTopology, "C++: cola::ConstrainedFDLayout::getTopology() --> class cola::TopologyAddonInterface *", pybind11::return_value_policy::automatic);
		cl.def("setClusterHierarchy", (void (cola::ConstrainedFDLayout::*)(class cola::RootCluster *)) &cola::ConstrainedFDLayout::setClusterHierarchy, "Specifies an optional hierarchy for clustering nodes.\n\n \n  A pointer to a RootCluster object defining the\n                      the cluster hierarchy (optional).\n\nC++: cola::ConstrainedFDLayout::setClusterHierarchy(class cola::RootCluster *) --> void", pybind11::arg("hierarchy"));
		cl.def("makeFeasible", [](cola::ConstrainedFDLayout &o) -> void { return o.makeFeasible(); }, "");
		cl.def("makeFeasible", [](cola::ConstrainedFDLayout &o, double const & a0) -> void { return o.makeFeasible(a0); }, "", pybind11::arg("xBorder"));
		cl.def("makeFeasible", (void (cola::ConstrainedFDLayout::*)(double, double)) &cola::ConstrainedFDLayout::makeFeasible, "Finds a feasible starting position for nodes that satisfies the\n        given constraints.\n\n Starts with an initial position (x, y) for the nodes.  This position \n is then iteratively updated with a greedy heuristic that tries adding\n additional constraints based on compound constraint priority to the\n satisfiable set, so as to satisfy as many of the placement constraints\n as possible.  This includes automatically generated constraints for\n non-overlap and cluster containment.\n\n \n  Optional border width to add to left and right\n                     sides of rectangles. Defaults to 1.\n \n\n  Optional border width to add to top and bottom\n                     sides of rectangles. Defaults to 1.\n\n \n This method doesn't do force-directed layout.  All forces are \n       ignored and it merely satisfies the constraints with minimal \n       movement to nodes.\n\nC++: cola::ConstrainedFDLayout::makeFeasible(double, double) --> void", pybind11::arg("xBorder"), pybind11::arg("yBorder"));
		cl.def("freeAssociatedObjects", (void (cola::ConstrainedFDLayout::*)()) &cola::ConstrainedFDLayout::freeAssociatedObjects, "A convenience method that can be called from Java to free\n         the memory of nodes (Rectangles), CompoundConstraints, etc.\n\n This assumes that the ConstrainedFDLayout instance takes ownership\n of all the objects passed to it.\n\n This is useful because in SWIG we have problems with Java wrapper\n classes going out of scope and causing objects like Rectanges to \n sometimes be freed when the layout instance still needs them.  For \n this reason we prevent the Java wrappers from deleting the internal\n C++ instances, and let them be cleaned up later via this method.\n\nC++: cola::ConstrainedFDLayout::freeAssociatedObjects() --> void");
		cl.def("setUseNeighbourStress", (void (cola::ConstrainedFDLayout::*)(bool)) &cola::ConstrainedFDLayout::setUseNeighbourStress, "Specifies whether neighbour stress should be used.\n\n Under neighbour stress, only the terms representing neighbouring\n nodes contribute to the stress function. This can help to distribute\n nodes more evenly, eliminating long-range forces.\n\n Default value is false.\n\n \n  New boolean value for this option.\n\nC++: cola::ConstrainedFDLayout::setUseNeighbourStress(bool) --> void", pybind11::arg("useNeighbourStress"));
		cl.def("computeStress", (double (cola::ConstrainedFDLayout::*)() const) &cola::ConstrainedFDLayout::computeStress, "C++: cola::ConstrainedFDLayout::computeStress() const --> double");
	}
}
