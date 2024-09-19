#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libcola/box.h>
#include <libcola/cc_nonoverlapconstraints.h>
#include <libcola/cluster.h>
#include <libcola/cola.h>
#include <libcola/cola_log.h>
#include <libcola/compound_constraints.h>
#include <libcola/shapepair.h>
#include <libcola/straightener.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <memory>
#include <set>
#include <sstream>
#include <sstream> // __str__
#include <string>
#include <sys/_types/_timeval64.h>
#include <sys/time.h>
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

// cola::OverlapShapeOffsets file:libcola/cc_nonoverlapconstraints.h line:40
struct PyCallBack_cola_OverlapShapeOffsets : public cola::OverlapShapeOffsets {
	using cola::OverlapShapeOffsets::OverlapShapeOffsets;

	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OverlapShapeOffsets *>(this), "updateVarIDsWithMapping");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return SubConstraintInfo::updateVarIDsWithMapping(a0, a1);
	}
};

// cola::NonOverlapConstraints file:libcola/cc_nonoverlapconstraints.h line:136
struct PyCallBack_cola_NonOverlapConstraints : public cola::NonOverlapConstraints {
	using cola::NonOverlapConstraints::NonOverlapConstraints;

	void markCurrSubConstraintAsActive(const bool a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "markCurrSubConstraintAsActive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return NonOverlapConstraints::markCurrSubConstraintAsActive(a0);
	}
	void markAllSubConstraintsAsInactive() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "markAllSubConstraintsAsInactive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return NonOverlapConstraints::markAllSubConstraintsAsInactive();
	}
	bool subConstraintsRemaining() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "subConstraintsRemaining");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return NonOverlapConstraints::subConstraintsRemaining();
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "updatePosition");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::updatePosition(a0);
	}
	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "updateVarIDsWithMapping");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::updateVarIDsWithMapping(a0, a1);
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::printCreationCode(a0);
	}
};

void bind_libcola_cola(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::ProjectionResult file:libcola/cola.h line:925
		pybind11::class_<cola::ProjectionResult, std::shared_ptr<cola::ProjectionResult>> cl(M("cola"), "ProjectionResult", "");
		cl.def( pybind11::init( [](){ return new cola::ProjectionResult(); } ) );
		cl.def( pybind11::init( [](cola::ProjectionResult const &o){ return new cola::ProjectionResult(o); } ) );
		cl.def_readwrite("errorLevel", &cola::ProjectionResult::errorLevel);
		cl.def_readwrite("unsatinfo", &cola::ProjectionResult::unsatinfo);
	}
	{ // cola::OverlapShapeOffsets file:libcola/cc_nonoverlapconstraints.h line:40
		pybind11::class_<cola::OverlapShapeOffsets, std::shared_ptr<cola::OverlapShapeOffsets>, PyCallBack_cola_OverlapShapeOffsets, cola::SubConstraintInfo> cl(M("cola"), "OverlapShapeOffsets", "");
		cl.def( pybind11::init<unsigned int, double, double, unsigned int>(), pybind11::arg("ind"), pybind11::arg("xOffset"), pybind11::arg("yOffset"), pybind11::arg("group") );

		cl.def( pybind11::init<unsigned int, class cola::Cluster *, unsigned int>(), pybind11::arg("ind"), pybind11::arg("cluster"), pybind11::arg("group") );

		cl.def( pybind11::init( [](){ return new cola::OverlapShapeOffsets(); }, [](){ return new PyCallBack_cola_OverlapShapeOffsets(); } ) );
		cl.def( pybind11::init( [](PyCallBack_cola_OverlapShapeOffsets const &o){ return new PyCallBack_cola_OverlapShapeOffsets(o); } ) );
		cl.def( pybind11::init( [](cola::OverlapShapeOffsets const &o){ return new cola::OverlapShapeOffsets(o); } ) );
		cl.def_readwrite("rectPadding", &cola::OverlapShapeOffsets::rectPadding);
		cl.def_readwrite("group", &cola::OverlapShapeOffsets::group);
		cl.def("usesClusterBounds", (bool (cola::OverlapShapeOffsets::*)() const) &cola::OverlapShapeOffsets::usesClusterBounds, "C++: cola::OverlapShapeOffsets::usesClusterBounds() const --> bool");
		cl.def("resize", (void (cola::OverlapShapeOffsets::*)(double, double)) &cola::OverlapShapeOffsets::resize, "C++: cola::OverlapShapeOffsets::resize(double, double) --> void", pybind11::arg("xOffset"), pybind11::arg("yOffset"));
		cl.def("assign", (class cola::OverlapShapeOffsets & (cola::OverlapShapeOffsets::*)(const class cola::OverlapShapeOffsets &)) &cola::OverlapShapeOffsets::operator=, "C++: cola::OverlapShapeOffsets::operator=(const class cola::OverlapShapeOffsets &) --> class cola::OverlapShapeOffsets &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::ShapePairInfo file:libcola/cc_nonoverlapconstraints.h line:84
		pybind11::class_<cola::ShapePairInfo, std::shared_ptr<cola::ShapePairInfo>> cl(M("cola"), "ShapePairInfo", "");
		cl.def( pybind11::init( [](unsigned int const & a0, unsigned int const & a1){ return new cola::ShapePairInfo(a0, a1); } ), "doc" , pybind11::arg("ind1"), pybind11::arg("ind2"));
		cl.def( pybind11::init<unsigned int, unsigned int, unsigned int>(), pybind11::arg("ind1"), pybind11::arg("ind2"), pybind11::arg("ord") );

		cl.def_readwrite("order", &cola::ShapePairInfo::order);
		cl.def_readwrite("varIndex1", &cola::ShapePairInfo::varIndex1);
		cl.def_readwrite("varIndex2", &cola::ShapePairInfo::varIndex2);
		cl.def_readwrite("satisfied", &cola::ShapePairInfo::satisfied);
		cl.def_readwrite("processed", &cola::ShapePairInfo::processed);
		cl.def_readwrite("overlapMax", &cola::ShapePairInfo::overlapMax);
	}
	{ // cola::NonOverlapConstraintExemptions file:libcola/cc_nonoverlapconstraints.h line:124
		pybind11::class_<cola::NonOverlapConstraintExemptions, std::shared_ptr<cola::NonOverlapConstraintExemptions>> cl(M("cola"), "NonOverlapConstraintExemptions", "");
		cl.def( pybind11::init( [](){ return new cola::NonOverlapConstraintExemptions(); } ) );
		cl.def( pybind11::init( [](cola::NonOverlapConstraintExemptions const &o){ return new cola::NonOverlapConstraintExemptions(o); } ) );
		cl.def("shapePairIsExempt", (bool (cola::NonOverlapConstraintExemptions::*)(class cola::ShapePair) const) &cola::NonOverlapConstraintExemptions::shapePairIsExempt, "C++: cola::NonOverlapConstraintExemptions::shapePairIsExempt(class cola::ShapePair) const --> bool", pybind11::arg("shapePair"));
	}
	{ // cola::NonOverlapConstraints file:libcola/cc_nonoverlapconstraints.h line:136
		pybind11::class_<cola::NonOverlapConstraints, std::shared_ptr<cola::NonOverlapConstraints>, PyCallBack_cola_NonOverlapConstraints, cola::CompoundConstraint> cl(M("cola"), "NonOverlapConstraints", "");
		cl.def( pybind11::init( [](class cola::NonOverlapConstraintExemptions * a0){ return new cola::NonOverlapConstraints(a0); }, [](class cola::NonOverlapConstraintExemptions * a0){ return new PyCallBack_cola_NonOverlapConstraints(a0); } ), "doc");
		cl.def( pybind11::init<class cola::NonOverlapConstraintExemptions *, unsigned int>(), pybind11::arg("exemptions"), pybind11::arg("priority") );

		cl.def( pybind11::init( [](PyCallBack_cola_NonOverlapConstraints const &o){ return new PyCallBack_cola_NonOverlapConstraints(o); } ) );
		cl.def( pybind11::init( [](cola::NonOverlapConstraints const &o){ return new cola::NonOverlapConstraints(o); } ) );
		cl.def("resizeShape", (void (cola::NonOverlapConstraints::*)(unsigned int, double, double)) &cola::NonOverlapConstraints::resizeShape, "C++: cola::NonOverlapConstraints::resizeShape(unsigned int, double, double) --> void", pybind11::arg("id"), pybind11::arg("halfW"), pybind11::arg("halfH"));
		cl.def("removeShape", (void (cola::NonOverlapConstraints::*)(unsigned int)) &cola::NonOverlapConstraints::removeShape, "C++: cola::NonOverlapConstraints::removeShape(unsigned int) --> void", pybind11::arg("id"));
		cl.def("addCluster", (void (cola::NonOverlapConstraints::*)(class cola::Cluster *, unsigned int)) &cola::NonOverlapConstraints::addCluster, "C++: cola::NonOverlapConstraints::addCluster(class cola::Cluster *, unsigned int) --> void", pybind11::arg("cluster"), pybind11::arg("group"));
		cl.def("markCurrSubConstraintAsActive", (void (cola::NonOverlapConstraints::*)(const bool)) &cola::NonOverlapConstraints::markCurrSubConstraintAsActive, "C++: cola::NonOverlapConstraints::markCurrSubConstraintAsActive(const bool) --> void", pybind11::arg("satisfiable"));
		cl.def("markAllSubConstraintsAsInactive", (void (cola::NonOverlapConstraints::*)()) &cola::NonOverlapConstraints::markAllSubConstraintsAsInactive, "C++: cola::NonOverlapConstraints::markAllSubConstraintsAsInactive() --> void");
		cl.def("subConstraintsRemaining", (bool (cola::NonOverlapConstraints::*)() const) &cola::NonOverlapConstraints::subConstraintsRemaining, "C++: cola::NonOverlapConstraints::subConstraintsRemaining() const --> bool");
		cl.def("assign", (class cola::NonOverlapConstraints & (cola::NonOverlapConstraints::*)(const class cola::NonOverlapConstraints &)) &cola::NonOverlapConstraints::operator=, "C++: cola::NonOverlapConstraints::operator=(const class cola::NonOverlapConstraints &) --> class cola::NonOverlapConstraints &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// cola::TLogLevel file:libcola/cola_log.h line:40
	pybind11::enum_<cola::TLogLevel>(M("cola"), "TLogLevel", pybind11::arithmetic(), "")
		.value("logERROR", cola::logERROR)
		.value("logWARNING", cola::logWARNING)
		.value("logINFO", cola::logINFO)
		.value("logDEBUG", cola::logDEBUG)
		.value("logDEBUG1", cola::logDEBUG1)
		.value("logDEBUG2", cola::logDEBUG2)
		.value("logDEBUG3", cola::logDEBUG3)
		.value("logDEBUG4", cola::logDEBUG4)
		.export_values();

;

	{ // cola::Log file:libcola/cola_log.h line:43
		pybind11::class_<cola::Log<cola::Output2FILE>, std::shared_ptr<cola::Log<cola::Output2FILE>>> cl(M("cola"), "Log_cola_Output2FILE_t", "");
		cl.def( pybind11::init( [](){ return new cola::Log<cola::Output2FILE>(); } ) );
		cl.def_static("ReportingLevel", (enum cola::TLogLevel & (*)()) &cola::Log<cola::Output2FILE>::ReportingLevel, "C++: cola::Log<cola::Output2FILE>::ReportingLevel() --> enum cola::TLogLevel &", pybind11::return_value_policy::automatic);
	}
	{ // cola::Output2FILE file:libcola/cola_log.h line:118
		pybind11::class_<cola::Output2FILE, std::shared_ptr<cola::Output2FILE>> cl(M("cola"), "Output2FILE", "");
		cl.def( pybind11::init( [](){ return new cola::Output2FILE(); } ) );
		cl.def_static("Stream", (struct __sFILE *& (*)()) &cola::Output2FILE::Stream, "C++: cola::Output2FILE::Stream() --> struct __sFILE *&", pybind11::return_value_policy::automatic);
	}
	{ // cola::FILELog file:libcola/cola_log.h line:152
		pybind11::class_<cola::FILELog, std::shared_ptr<cola::FILELog>, cola::Log<cola::Output2FILE>> cl(M("cola"), "FILELog", "");
		cl.def( pybind11::init( [](){ return new cola::FILELog(); } ) );
	}
}
