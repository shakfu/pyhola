#include <__functional/operations.h>
#include <_stdio.h>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/debughandler.h>
#include <libavoid/geomtypes.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedge.h>
#include <libavoid/junction.h>
#include <libavoid/obstacle.h>
#include <libavoid/router.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <libavoid/viscluster.h>
#include <libcola/cluster.h>
#include <libcola/cola.h>
#include <libcola/compound_constraints.h>
#include <libcola/sparse_matrix.h>
#include <libtopology/cola_topology_addon.h>
#include <libtopology/orthogonal_topology.h>
#include <libtopology/topology_constraints.h>
#include <libtopology/topology_graph.h>
#include <libtopology/topology_log.h>
#include <libtopology/util.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <list>
#include <memory>
#include <set>
#include <sstream>
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

// topology::ColaTopologyAddon file:libtopology/cola_topology_addon.h line:44
struct PyCallBack_topology_ColaTopologyAddon : public topology::ColaTopologyAddon {
	using topology::ColaTopologyAddon::ColaTopologyAddon;

	class cola::TopologyAddonInterface * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class cola::TopologyAddonInterface *>::value) {
				static pybind11::detail::override_caster_t<class cola::TopologyAddonInterface *> caster;
				return pybind11::detail::cast_ref<class cola::TopologyAddonInterface *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class cola::TopologyAddonInterface *>(std::move(o));
		}
		return ColaTopologyAddon::clone();
	}
	void freeAssociatedObjects() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "freeAssociatedObjects");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return ColaTopologyAddon::freeAssociatedObjects();
	}
	double computeStress() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "computeStress");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<double>::value) {
				static pybind11::detail::override_caster_t<double> caster;
				return pybind11::detail::cast_ref<double>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<double>(std::move(o));
		}
		return ColaTopologyAddon::computeStress();
	}
	bool useTopologySolver() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::ColaTopologyAddon *>(this), "useTopologySolver");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return ColaTopologyAddon::useTopologySolver();
	}
};

// topology::AvoidTopologyAddon file:libtopology/orthogonal_topology.h line:37
struct PyCallBack_topology_AvoidTopologyAddon : public topology::AvoidTopologyAddon {
	using topology::AvoidTopologyAddon::AvoidTopologyAddon;

	class Avoid::TopologyAddonInterface * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::AvoidTopologyAddon *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Avoid::TopologyAddonInterface *>::value) {
				static pybind11::detail::override_caster_t<class Avoid::TopologyAddonInterface *> caster;
				return pybind11::detail::cast_ref<class Avoid::TopologyAddonInterface *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Avoid::TopologyAddonInterface *>(std::move(o));
		}
		return AvoidTopologyAddon::clone();
	}
	void improveOrthogonalTopology(class Avoid::Router * a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::AvoidTopologyAddon *>(this), "improveOrthogonalTopology");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return AvoidTopologyAddon::improveOrthogonalTopology(a0);
	}
	bool outputCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::AvoidTopologyAddon *>(this), "outputCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return AvoidTopologyAddon::outputCode(a0);
	}
	bool outputDeletionCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const topology::AvoidTopologyAddon *>(this), "outputDeletionCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return AvoidTopologyAddon::outputDeletionCode(a0);
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
		pybind11::class_<topology::ColaTopologyAddon, std::shared_ptr<topology::ColaTopologyAddon>, PyCallBack_topology_ColaTopologyAddon, cola::TopologyAddonInterface> cl(M("topology"), "ColaTopologyAddon", "This class can be passed to libcola to replace some functionality\n          to provide topology preserving layout.\n\n  You should instantiate this class with a given set of nodes and edges to\n  preserve and pass it to cola::ConstrainedFDLayout::setTopology().");
		cl.def( pybind11::init( [](){ return new topology::ColaTopologyAddon(); }, [](){ return new PyCallBack_topology_ColaTopologyAddon(); } ) );
		cl.def( pybind11::init( [](PyCallBack_topology_ColaTopologyAddon const &o){ return new PyCallBack_topology_ColaTopologyAddon(o); } ) );
		cl.def( pybind11::init( [](topology::ColaTopologyAddon const &o){ return new topology::ColaTopologyAddon(o); } ) );
		cl.def_readwrite("topologyNodes", &topology::ColaTopologyAddon::topologyNodes);
		cl.def_readwrite("topologyRoutes", &topology::ColaTopologyAddon::topologyRoutes);
		cl.def("clone", (class cola::TopologyAddonInterface * (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::clone, "C++: topology::ColaTopologyAddon::clone() const --> class cola::TopologyAddonInterface *", pybind11::return_value_policy::automatic);
		cl.def("freeAssociatedObjects", (void (topology::ColaTopologyAddon::*)()) &topology::ColaTopologyAddon::freeAssociatedObjects, "C++: topology::ColaTopologyAddon::freeAssociatedObjects() --> void");
		cl.def("computeStress", (double (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::computeStress, "C++: topology::ColaTopologyAddon::computeStress() const --> double");
		cl.def("useTopologySolver", (bool (topology::ColaTopologyAddon::*)() const) &topology::ColaTopologyAddon::useTopologySolver, "C++: topology::ColaTopologyAddon::useTopologySolver() const --> bool");
		cl.def("assign", (class topology::ColaTopologyAddon & (topology::ColaTopologyAddon::*)(const class topology::ColaTopologyAddon &)) &topology::ColaTopologyAddon::operator=, "C++: topology::ColaTopologyAddon::operator=(const class topology::ColaTopologyAddon &) --> class topology::ColaTopologyAddon &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // topology::AvoidTopologyAddon file:libtopology/orthogonal_topology.h line:37
		pybind11::class_<topology::AvoidTopologyAddon, std::shared_ptr<topology::AvoidTopologyAddon>, PyCallBack_topology_AvoidTopologyAddon, Avoid::TopologyAddonInterface> cl(M("topology"), "AvoidTopologyAddon", "This class can be passed to libavoid to extend it to provide\n          orthogonal topology improvement functionality.\n\n  You should instantiate this class with libcola information about \n  constraints on objects in the diagram and pass it to \n  Avoid::Router::setTopologyAddon().");
		cl.def( pybind11::init( [](PyCallBack_topology_AvoidTopologyAddon const &o){ return new PyCallBack_topology_AvoidTopologyAddon(o); } ) );
		cl.def( pybind11::init( [](topology::AvoidTopologyAddon const &o){ return new topology::AvoidTopologyAddon(o); } ) );
		cl.def("clone", (class Avoid::TopologyAddonInterface * (topology::AvoidTopologyAddon::*)() const) &topology::AvoidTopologyAddon::clone, "C++: topology::AvoidTopologyAddon::clone() const --> class Avoid::TopologyAddonInterface *", pybind11::return_value_policy::automatic);
		cl.def("improveOrthogonalTopology", (void (topology::AvoidTopologyAddon::*)(class Avoid::Router *)) &topology::AvoidTopologyAddon::improveOrthogonalTopology, "C++: topology::AvoidTopologyAddon::improveOrthogonalTopology(class Avoid::Router *) --> void", pybind11::arg("router"));
		cl.def("outputCode", (bool (topology::AvoidTopologyAddon::*)(struct __sFILE *) const) &topology::AvoidTopologyAddon::outputCode, "C++: topology::AvoidTopologyAddon::outputCode(struct __sFILE *) const --> bool", pybind11::arg("fp"));
		cl.def("outputDeletionCode", (bool (topology::AvoidTopologyAddon::*)(struct __sFILE *) const) &topology::AvoidTopologyAddon::outputDeletionCode, "C++: topology::AvoidTopologyAddon::outputDeletionCode(struct __sFILE *) const --> bool", pybind11::arg("fp"));
		cl.def("assign", (class topology::AvoidTopologyAddon & (topology::AvoidTopologyAddon::*)(const class topology::AvoidTopologyAddon &)) &topology::AvoidTopologyAddon::operator=, "C++: topology::AvoidTopologyAddon::operator=(const class topology::AvoidTopologyAddon &) --> class topology::AvoidTopologyAddon &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // topology::TriConstraint file:libtopology/topology_constraints.h line:60
		pybind11::class_<topology::TriConstraint, std::shared_ptr<topology::TriConstraint>> cl(M("topology"), "TriConstraint", "");
		cl.def( pybind11::init<enum vpsc::Dim, const class topology::Node *, const class topology::Node *, const class topology::Node *, double, double, bool>(), pybind11::arg("dim"), pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("w"), pybind11::arg("p"), pybind11::arg("g"), pybind11::arg("left") );

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
		pybind11::class_<topology::TopologyConstraint, std::shared_ptr<topology::TopologyConstraint>> cl(M("topology"), "TopologyConstraint", "");
		cl.def_readwrite("scanDim", &topology::TopologyConstraint::scanDim);
		cl.def("satisfy", (void (topology::TopologyConstraint::*)()) &topology::TopologyConstraint::satisfy, "C++: topology::TopologyConstraint::satisfy() --> void");
		cl.def("getEdgeID", (unsigned int (topology::TopologyConstraint::*)() const) &topology::TopologyConstraint::getEdgeID, "C++: topology::TopologyConstraint::getEdgeID() const --> unsigned int");
		cl.def("assertFeasible", (bool (topology::TopologyConstraint::*)() const) &topology::TopologyConstraint::assertFeasible, "C++: topology::TopologyConstraint::assertFeasible() const --> bool");
		cl.def("assign", (class topology::TopologyConstraint & (topology::TopologyConstraint::*)(const class topology::TopologyConstraint &)) &topology::TopologyConstraint::operator=, "C++: topology::TopologyConstraint::operator=(const class topology::TopologyConstraint &) --> class topology::TopologyConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // topology::BendConstraint file:libtopology/topology_constraints.h line:124
		pybind11::class_<topology::BendConstraint, std::shared_ptr<topology::BendConstraint>, PyCallBack_topology_BendConstraint, topology::TopologyConstraint> cl(M("topology"), "BendConstraint", "");
		cl.def( pybind11::init<class topology::EdgePoint *, enum vpsc::Dim>(), pybind11::arg("bendPoint"), pybind11::arg("dim") );

		cl.def( pybind11::init( [](PyCallBack_topology_BendConstraint const &o){ return new PyCallBack_topology_BendConstraint(o); } ) );
		cl.def( pybind11::init( [](topology::BendConstraint const &o){ return new topology::BendConstraint(o); } ) );
		cl.def("satisfy", (void (topology::BendConstraint::*)()) &topology::BendConstraint::satisfy, "C++: topology::BendConstraint::satisfy() --> void");
		cl.def("getEdgeID", (unsigned int (topology::BendConstraint::*)() const) &topology::BendConstraint::getEdgeID, "C++: topology::BendConstraint::getEdgeID() const --> unsigned int");
		cl.def("assign", (class topology::BendConstraint & (topology::BendConstraint::*)(const class topology::BendConstraint &)) &topology::BendConstraint::operator=, "C++: topology::BendConstraint::operator=(const class topology::BendConstraint &) --> class topology::BendConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // topology::StraightConstraint file:libtopology/topology_constraints.h line:142
		pybind11::class_<topology::StraightConstraint, std::shared_ptr<topology::StraightConstraint>, PyCallBack_topology_StraightConstraint, topology::TopologyConstraint> cl(M("topology"), "StraightConstraint", "");
		cl.def( pybind11::init<class topology::Segment *, enum vpsc::Dim, class topology::Node *, const enum topology::EdgePoint::RectIntersect, const double, const double, const bool>(), pybind11::arg("s"), pybind11::arg("dim"), pybind11::arg("node"), pybind11::arg("ri"), pybind11::arg("scanPos"), pybind11::arg("segmentPos"), pybind11::arg("nodeLeft") );

		cl.def( pybind11::init( [](PyCallBack_topology_StraightConstraint const &o){ return new PyCallBack_topology_StraightConstraint(o); } ) );
		cl.def( pybind11::init( [](topology::StraightConstraint const &o){ return new topology::StraightConstraint(o); } ) );
		cl.def_readwrite("ri", &topology::StraightConstraint::ri);
		cl.def_readonly("pos", &topology::StraightConstraint::pos);
		cl.def("satisfy", (void (topology::StraightConstraint::*)()) &topology::StraightConstraint::satisfy, "C++: topology::StraightConstraint::satisfy() --> void");
		cl.def("getEdgeID", (unsigned int (topology::StraightConstraint::*)() const) &topology::StraightConstraint::getEdgeID, "C++: topology::StraightConstraint::getEdgeID() const --> unsigned int");
	}
	{ // topology::TopologyConstraints file:libtopology/topology_constraints.h line:173
		pybind11::class_<topology::TopologyConstraints, std::shared_ptr<topology::TopologyConstraints>> cl(M("topology"), "TopologyConstraints", "");
		cl.def_readonly("n", &topology::TopologyConstraints::n);
		cl.def("solve", (bool (topology::TopologyConstraints::*)()) &topology::TopologyConstraints::solve, "C++: topology::TopologyConstraints::solve() --> bool");
		cl.def("assertFeasible", (bool (topology::TopologyConstraints::*)() const) &topology::TopologyConstraints::assertFeasible, "C++: topology::TopologyConstraints::assertFeasible() const --> bool");
		cl.def("noOverlaps", (bool (topology::TopologyConstraints::*)() const) &topology::TopologyConstraints::noOverlaps, "C++: topology::TopologyConstraints::noOverlaps() const --> bool");
	}
	{ // topology::ResizeInfo file:libtopology/topology_constraints.h line:220
		pybind11::class_<topology::ResizeInfo, std::shared_ptr<topology::ResizeInfo>> cl(M("topology"), "ResizeInfo", "");
		cl.def( pybind11::init<class topology::Node *, const class vpsc::Rectangle *>(), pybind11::arg("v"), pybind11::arg("target") );

	}
	// topology::TLogLevel file:libtopology/topology_log.h line:40
	pybind11::enum_<topology::TLogLevel>(M("topology"), "TLogLevel", pybind11::arithmetic(), "")
		.value("logERROR", topology::logERROR)
		.value("logWARNING", topology::logWARNING)
		.value("logINFO", topology::logINFO)
		.value("logDEBUG", topology::logDEBUG)
		.value("logDEBUG1", topology::logDEBUG1)
		.value("logDEBUG2", topology::logDEBUG2)
		.value("logDEBUG3", topology::logDEBUG3)
		.value("logDEBUG4", topology::logDEBUG4)
		.export_values();

;

	{ // topology::Log file:libtopology/topology_log.h line:43
		pybind11::class_<topology::Log<topology::Output2FILE>, std::shared_ptr<topology::Log<topology::Output2FILE>>> cl(M("topology"), "Log_topology_Output2FILE_t", "");
		cl.def( pybind11::init( [](){ return new topology::Log<topology::Output2FILE>(); } ) );
		cl.def("flush", (void (topology::Log<topology::Output2FILE>::*)()) &topology::Log<topology::Output2FILE>::flush, "C++: topology::Log<topology::Output2FILE>::flush() --> void");
		cl.def_static("ReportingLevel", (enum topology::TLogLevel & (*)()) &topology::Log<topology::Output2FILE>::ReportingLevel, "C++: topology::Log<topology::Output2FILE>::ReportingLevel() --> enum topology::TLogLevel &", pybind11::return_value_policy::automatic);
	}
	{ // topology::Output2FILE file:libtopology/topology_log.h line:124
		pybind11::class_<topology::Output2FILE, std::shared_ptr<topology::Output2FILE>> cl(M("topology"), "Output2FILE", "");
		cl.def( pybind11::init( [](){ return new topology::Output2FILE(); } ) );
		cl.def_static("Stream", (struct __sFILE *& (*)()) &topology::Output2FILE::Stream, "C++: topology::Output2FILE::Stream() --> struct __sFILE *&", pybind11::return_value_policy::automatic);
	}
	{ // topology::FILELog file:libtopology/topology_log.h line:158
		pybind11::class_<topology::FILELog, std::shared_ptr<topology::FILELog>, topology::Log<topology::Output2FILE>> cl(M("topology"), "FILELog", "");
		cl.def( pybind11::init( [](){ return new topology::FILELog(); } ) );
	}
}
