#include <_stdio.h>
#include <libcola/sparse_matrix.h>
#include <libtopology/cola_topology_addon.h>
#include <libtopology/orthogonal_topology.h>
#include <libtopology/topology_constraints.h>
#include <libtopology/topology_graph.h>
#include <libvpsc/variable.h>
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <cstdlib>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// topology::TopologyConstraint file:libtopology/topology_constraints.h line:94
struct PyCallBack_topology_TopologyConstraint : public topology::TopologyConstraint {
	using topology::TopologyConstraint::TopologyConstraint;

	void satisfy() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::TopologyConstraint *>(this), "satisfy");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"TopologyConstraint::satisfy\"");
	}
	unsigned int getEdgeID() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::TopologyConstraint *>(this), "getEdgeID");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"TopologyConstraint::getEdgeID\"");
	}
};

// topology::BendConstraint file:libtopology/topology_constraints.h line:124
struct PyCallBack_topology_BendConstraint : public topology::BendConstraint {
	using topology::BendConstraint::BendConstraint;

	void satisfy() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::BendConstraint *>(this), "satisfy");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return BendConstraint::satisfy();
	}
	unsigned int getEdgeID() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::BendConstraint *>(this), "getEdgeID");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		return BendConstraint::getEdgeID();
	}
};

// topology::StraightConstraint file:libtopology/topology_constraints.h line:142
struct PyCallBack_topology_StraightConstraint : public topology::StraightConstraint {
	using topology::StraightConstraint::StraightConstraint;

	void satisfy() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::StraightConstraint *>(this), "satisfy");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return StraightConstraint::satisfy();
	}
	unsigned int getEdgeID() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::StraightConstraint *>(this), "getEdgeID");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		return StraightConstraint::getEdgeID();
	}
};

void bind_libtopology_cola_topology_addon(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // topology::ColaTopologyAddon file:libtopology/cola_topology_addon.h line:44
		pybind11::class_<topology::ColaTopologyAddon, std::shared_ptr<topology::ColaTopologyAddon>> cl(M("topology"), "ColaTopologyAddon", "This class can be passed to libcola to replace some functionality\n          to provide topology preserving layout.\n\n  You should instantiate this class with a given set of nodes and edges to\n  preserve and pass it to cola::ConstrainedFDLayout::setTopology().");
		cl.def( pybind11::init( [](){ return new topology::ColaTopologyAddon(); } ) );
		cl.def( pybind11::init<int &, int &>(), pybind11::arg("tnodes"), pybind11::arg("routes") );

		cl.def_readwrite("topologyNodes", &topology::ColaTopologyAddon::topologyNodes);
		cl.def_readwrite("topologyRoutes", &topology::ColaTopologyAddon::topologyRoutes);
		cl.def("writeSVGFile", [](topology::ColaTopologyAddon &o) -> void { return o.writeSVGFile(); }, "");
		cl.def("writeSVGFile", (void (topology::ColaTopologyAddon::*)(int)) &topology::ColaTopologyAddon::writeSVGFile, "Writes an SVG file displaying the current topology of \n         the nodes and edges.\n\n \n  A string indicating the filename (without \n                      extension) for the output file.  Defaults to\n                      \"libtopology-cola.svg\" if no filename is given.\n\nC++: topology::ColaTopologyAddon::writeSVGFile(int) --> void", pybind11::arg("filename"));
		cl.def("clone", (int * (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::clone, "C++: topology::ColaTopologyAddon::clone() const --> int *", pybind11::return_value_policy::automatic);
		cl.def("freeAssociatedObjects", (void (topology::ColaTopologyAddon::*)()) &topology::ColaTopologyAddon::freeAssociatedObjects, "C++: topology::ColaTopologyAddon::freeAssociatedObjects() --> void");
		cl.def("handleResizes", (void (topology::ColaTopologyAddon::*)(const int &, unsigned int, int &, int &, int &, int &, int *)) &topology::ColaTopologyAddon::handleResizes, "C++: topology::ColaTopologyAddon::handleResizes(const int &, unsigned int, int &, int &, int &, int &, int *) --> void", pybind11::arg("resizeList"), pybind11::arg("n"), pybind11::arg("X"), pybind11::arg("Y"), pybind11::arg("ccs"), pybind11::arg("boundingBoxes"), pybind11::arg("clusterHierarchy"));
		cl.def("computeStress", (double (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::computeStress, "C++: topology::ColaTopologyAddon::computeStress() const --> double");
		cl.def("useTopologySolver", (bool (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::useTopologySolver, "C++: topology::ColaTopologyAddon::useTopologySolver() const --> bool");
		cl.def("makeFeasible", (void (topology::ColaTopologyAddon::*)(bool, int &, int *)) &topology::ColaTopologyAddon::makeFeasible, "C++: topology::ColaTopologyAddon::makeFeasible(bool, int &, int *) --> void", pybind11::arg("generateNonOverlapConstraints"), pybind11::arg("boundingBoxes"), pybind11::arg("clusterHierarchy"));
		cl.def("moveTo", (void (topology::ColaTopologyAddon::*)(const int, int &, int &, int &, int *)) &topology::ColaTopologyAddon::moveTo, "C++: topology::ColaTopologyAddon::moveTo(const int, int &, int &, int &, int *) --> void", pybind11::arg("dim"), pybind11::arg("vs"), pybind11::arg("cs"), pybind11::arg("coords"), pybind11::arg("clusterHierarchy"));
		cl.def("applyForcesAndConstraints", (double (topology::ColaTopologyAddon::*)(int *, const int, int &, int &, int &, int &, int &, double)) &topology::ColaTopologyAddon::applyForcesAndConstraints, "C++: topology::ColaTopologyAddon::applyForcesAndConstraints(int *, const int, int &, int &, int &, int &, int &, double) --> double", pybind11::arg("layout"), pybind11::arg("dim"), pybind11::arg("g"), pybind11::arg("vs"), pybind11::arg("cs"), pybind11::arg("coords"), pybind11::arg("des"), pybind11::arg("oldStress"));
	}
	{ // topology::AvoidTopologyAddon file:libtopology/orthogonal_topology.h line:37
		pybind11::class_<topology::AvoidTopologyAddon, std::shared_ptr<topology::AvoidTopologyAddon>> cl(M("topology"), "AvoidTopologyAddon", "This class can be passed to libavoid to extend it to provide\n          orthogonal topology improvement functionality.\n\n  You should instantiate this class with libcola information about \n  constraints on objects in the diagram and pass it to \n  Avoid::Router::setTopologyAddon().");
		cl.def( pybind11::init( [](){ return new topology::AvoidTopologyAddon(); } ) );
		cl.def( pybind11::init( [](int & a0, int & a1, int * a2, int & a3){ return new topology::AvoidTopologyAddon(a0, a1, a2, a3); } ), "doc" , pybind11::arg("rs"), pybind11::arg("cs"), pybind11::arg("ch"), pybind11::arg("map"));
		cl.def( pybind11::init<int &, int &, int *, int &, const double>(), pybind11::arg("rs"), pybind11::arg("cs"), pybind11::arg("ch"), pybind11::arg("map"), pybind11::arg("moveLimit") );

		cl.def("clone", (int * (topology::AvoidTopologyAddon::*)() const) &topology::AvoidTopologyAddon::clone, "C++: topology::AvoidTopologyAddon::clone() const --> int *", pybind11::return_value_policy::automatic);
		cl.def("improveOrthogonalTopology", (void (topology::AvoidTopologyAddon::*)(int *)) &topology::AvoidTopologyAddon::improveOrthogonalTopology, "C++: topology::AvoidTopologyAddon::improveOrthogonalTopology(int *) --> void", pybind11::arg("router"));
		cl.def("outputCode", (bool (topology::AvoidTopologyAddon::*)(struct __sFILE *) const) &topology::AvoidTopologyAddon::outputCode, "C++: topology::AvoidTopologyAddon::outputCode(struct __sFILE *) const --> bool", pybind11::arg("fp"));
		cl.def("outputDeletionCode", (bool (topology::AvoidTopologyAddon::*)(struct __sFILE *) const) &topology::AvoidTopologyAddon::outputDeletionCode, "C++: topology::AvoidTopologyAddon::outputDeletionCode(struct __sFILE *) const --> bool", pybind11::arg("fp"));
	}
	{ // topology::TriConstraint file:libtopology/topology_constraints.h line:60
		pybind11::class_<topology::TriConstraint, std::shared_ptr<topology::TriConstraint>> cl(M("topology"), "TriConstraint", "");
		cl.def( pybind11::init( [](){ return new topology::TriConstraint(); } ) );
		cl.def( pybind11::init<int, const int *, const int *, const int *, double, double, bool>(), pybind11::arg("dim"), pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("w"), pybind11::arg("p"), pybind11::arg("g"), pybind11::arg("left") );

		cl.def_readwrite("p", &topology::TriConstraint::p);
		cl.def_readwrite("g", &topology::TriConstraint::g);
		cl.def_readwrite("leftOf", &topology::TriConstraint::leftOf);
		cl.def_readwrite("scanDim", &topology::TriConstraint::scanDim);
		cl.def("maxSafeAlpha", (double (topology::TriConstraint::*)() const) &topology::TriConstraint::maxSafeAlpha, "C++: topology::TriConstraint::maxSafeAlpha() const --> double");
		cl.def("slackAtInitial", (double (topology::TriConstraint::*)() const) &topology::TriConstraint::slackAtInitial, "C++: topology::TriConstraint::slackAtInitial() const --> double");
		cl.def("slackAtFinal", (double (topology::TriConstraint::*)() const) &topology::TriConstraint::slackAtFinal, "C++: topology::TriConstraint::slackAtFinal() const --> double");
		cl.def("assertFeasible", (bool (topology::TriConstraint::*)() const) &topology::TriConstraint::assertFeasible, "C++: topology::TriConstraint::assertFeasible() const --> bool");
	}
	{ // topology::TopologyConstraint file:libtopology/topology_constraints.h line:94
		pybind11::class_<topology::TopologyConstraint, std::shared_ptr<topology::TopologyConstraint>, PyCallBack_topology_TopologyConstraint> cl(M("topology"), "TopologyConstraint", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_topology_TopologyConstraint(); } ) );
		cl.def(pybind11::init<PyCallBack_topology_TopologyConstraint const &>());
		cl.def_readwrite("scanDim", &topology::TopologyConstraint::scanDim);
		cl.def("satisfy", (void (topology::TopologyConstraint::*)()) &topology::TopologyConstraint::satisfy, "C++: topology::TopologyConstraint::satisfy() --> void");
		cl.def("toString", (int (topology::TopologyConstraint::*)() const) &topology::TopologyConstraint::toString, "for log messages\n\nC++: topology::TopologyConstraint::toString() const --> int");
		cl.def("getEdgeID", (unsigned int (topology::TopologyConstraint::*)() const) &topology::TopologyConstraint::getEdgeID, "C++: topology::TopologyConstraint::getEdgeID() const --> unsigned int");
		cl.def("assertFeasible", (bool (topology::TopologyConstraint::*)() const) &topology::TopologyConstraint::assertFeasible, "C++: topology::TopologyConstraint::assertFeasible() const --> bool");
		cl.def("assign", (class topology::TopologyConstraint & (topology::TopologyConstraint::*)(const class topology::TopologyConstraint &)) &topology::TopologyConstraint::operator=, "C++: topology::TopologyConstraint::operator=(const class topology::TopologyConstraint &) --> class topology::TopologyConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // topology::BendConstraint file:libtopology/topology_constraints.h line:124
		pybind11::class_<topology::BendConstraint, std::shared_ptr<topology::BendConstraint>, PyCallBack_topology_BendConstraint, topology::TopologyConstraint> cl(M("topology"), "BendConstraint", "");
		cl.def( pybind11::init( [](){ return new topology::BendConstraint(); }, [](){ return new PyCallBack_topology_BendConstraint(); } ) );
		cl.def( pybind11::init<int *, int>(), pybind11::arg("bendPoint"), pybind11::arg("dim") );

		cl.def( pybind11::init( [](PyCallBack_topology_BendConstraint const &o){ return new PyCallBack_topology_BendConstraint(o); } ) );
		cl.def( pybind11::init( [](topology::BendConstraint const &o){ return new topology::BendConstraint(o); } ) );
		cl.def("satisfy", (void (topology::BendConstraint::*)()) &topology::BendConstraint::satisfy, "C++: topology::BendConstraint::satisfy() --> void");
		cl.def("toString", (int (topology::BendConstraint::*)() const) &topology::BendConstraint::toString, "C++: topology::BendConstraint::toString() const --> int");
		cl.def("getEdgeID", (unsigned int (topology::BendConstraint::*)() const) &topology::BendConstraint::getEdgeID, "C++: topology::BendConstraint::getEdgeID() const --> unsigned int");
		cl.def("assign", (class topology::BendConstraint & (topology::BendConstraint::*)(const class topology::BendConstraint &)) &topology::BendConstraint::operator=, "C++: topology::BendConstraint::operator=(const class topology::BendConstraint &) --> class topology::BendConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // topology::StraightConstraint file:libtopology/topology_constraints.h line:142
		pybind11::class_<topology::StraightConstraint, std::shared_ptr<topology::StraightConstraint>, PyCallBack_topology_StraightConstraint, topology::TopologyConstraint> cl(M("topology"), "StraightConstraint", "");
		cl.def( pybind11::init( [](){ return new topology::StraightConstraint(); }, [](){ return new PyCallBack_topology_StraightConstraint(); } ) );
		cl.def( pybind11::init<int *, int, int *, const int, const double, const double, const bool>(), pybind11::arg("s"), pybind11::arg("dim"), pybind11::arg("node"), pybind11::arg("ri"), pybind11::arg("scanPos"), pybind11::arg("segmentPos"), pybind11::arg("nodeLeft") );

		cl.def( pybind11::init( [](PyCallBack_topology_StraightConstraint const &o){ return new PyCallBack_topology_StraightConstraint(o); } ) );
		cl.def( pybind11::init( [](topology::StraightConstraint const &o){ return new topology::StraightConstraint(o); } ) );
		cl.def_readwrite("ri", &topology::StraightConstraint::ri);
		cl.def_readonly("pos", &topology::StraightConstraint::pos);
		cl.def("satisfy", (void (topology::StraightConstraint::*)()) &topology::StraightConstraint::satisfy, "C++: topology::StraightConstraint::satisfy() --> void");
		cl.def("toString", (int (topology::StraightConstraint::*)() const) &topology::StraightConstraint::toString, "C++: topology::StraightConstraint::toString() const --> int");
		cl.def("getEdgeID", (unsigned int (topology::StraightConstraint::*)() const) &topology::StraightConstraint::getEdgeID, "C++: topology::StraightConstraint::getEdgeID() const --> unsigned int");
		cl.def("assign", (class topology::StraightConstraint & (topology::StraightConstraint::*)(const class topology::StraightConstraint &)) &topology::StraightConstraint::operator=, "C++: topology::StraightConstraint::operator=(const class topology::StraightConstraint &) --> class topology::StraightConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // topology::TopologyConstraints file:libtopology/topology_constraints.h line:173
		pybind11::class_<topology::TopologyConstraints, std::shared_ptr<topology::TopologyConstraints>> cl(M("topology"), "TopologyConstraints", "");
		cl.def( pybind11::init( [](){ return new topology::TopologyConstraints(); } ) );
		cl.def_readonly("n", &topology::TopologyConstraints::n);
		cl.def("solve", (bool (topology::TopologyConstraints::*)()) &topology::TopologyConstraints::solve, "C++: topology::TopologyConstraints::solve() --> bool");
		cl.def("constraints", (void (topology::TopologyConstraints::*)(int &) const) &topology::TopologyConstraints::constraints, "C++: topology::TopologyConstraints::constraints(int &) const --> void", pybind11::arg("ts"));
		cl.def("computeForces", (void (topology::TopologyConstraints::*)(int &, struct cola::SparseMap &)) &topology::TopologyConstraints::computeForces, "C++: topology::TopologyConstraints::computeForces(int &, struct cola::SparseMap &) --> void", pybind11::arg("g"), pybind11::arg("h"));
		cl.def("assertFeasible", (bool (topology::TopologyConstraints::*)() const) &topology::TopologyConstraints::assertFeasible, "C++: topology::TopologyConstraints::assertFeasible() const --> bool");
		cl.def("printInstance", (void (topology::TopologyConstraints::*)(int &) const) &topology::TopologyConstraints::printInstance, "C++: topology::TopologyConstraints::printInstance(int &) const --> void", pybind11::arg("g"));
		cl.def("noOverlaps", (bool (topology::TopologyConstraints::*)() const) &topology::TopologyConstraints::noOverlaps, "C++: topology::TopologyConstraints::noOverlaps() const --> bool");
	}
	// topology::getVariables(int &, int &) file:libtopology/topology_constraints.h line:216
	M("topology").def("getVariables", (void (*)(int &, int &)) &topology::getVariables, "C++: topology::getVariables(int &, int &) --> void", pybind11::arg("ns"), pybind11::arg("vs"));

	{ // topology::ResizeInfo file:libtopology/topology_constraints.h line:220
		pybind11::class_<topology::ResizeInfo, std::shared_ptr<topology::ResizeInfo>> cl(M("topology"), "ResizeInfo", "");
		cl.def( pybind11::init( [](){ return new topology::ResizeInfo(); } ) );
		cl.def( pybind11::init<int *, const int *>(), pybind11::arg("v"), pybind11::arg("target") );

	}
	// topology::computeStress(const int &) file:libtopology/topology_constraints.h line:241
	M("topology").def("computeStress", (double (*)(const int &)) &topology::computeStress, "C++: topology::computeStress(const int &) --> double", pybind11::arg("es"));

	{ // topology::Node file:libtopology/topology_graph.h line:58
		pybind11::class_<topology::Node, std::shared_ptr<topology::Node>> cl(M("topology"), "Node", "Topology representation for a node.\n\n Each node is associated with a rectangle and solver variables\n for the x and y axes.\n\n \n You shouldn't need to create these yourself, but you may\n       extract them from an existing ColaTopologyAddon and construct\n       a new ColaTopologyAddon with that same topology information.");
		cl.def( pybind11::init( [](){ return new topology::Node(); } ) );
		cl.def( pybind11::init( [](unsigned int const & a0, int * a1){ return new topology::Node(a0, a1); } ), "doc" , pybind11::arg("id"), pybind11::arg("r"));
		cl.def( pybind11::init<unsigned int, int *, class vpsc::Variable *>(), pybind11::arg("id"), pybind11::arg("r"), pybind11::arg("v") );

		cl.def_readonly("id", &topology::Node::id);
		cl.def("setDesiredPos", [](topology::Node &o, double const & a0) -> void { return o.setDesiredPos(a0); }, "", pybind11::arg("d"));
		cl.def("setDesiredPos", (void (topology::Node::*)(double, double)) &topology::Node::setDesiredPos, "C++: topology::Node::setDesiredPos(double, double) --> void", pybind11::arg("d"), pybind11::arg("weight"));
		cl.def("initialPos", (double (topology::Node::*)(int) const) &topology::Node::initialPos, "C++: topology::Node::initialPos(int) const --> double", pybind11::arg("scanDim"));
		cl.def("finalPos", (double (topology::Node::*)() const) &topology::Node::finalPos, "C++: topology::Node::finalPos() const --> double");
		cl.def("posOnLine", (double (topology::Node::*)(int, double) const) &topology::Node::posOnLine, "C++: topology::Node::posOnLine(int, double) const --> double", pybind11::arg("scanDim"), pybind11::arg("alpha"));
		cl.def("getVar", (class vpsc::Variable * (topology::Node::*)() const) &topology::Node::getVar, "C++: topology::Node::getVar() const --> class vpsc::Variable *", pybind11::return_value_policy::automatic);
	}
}
