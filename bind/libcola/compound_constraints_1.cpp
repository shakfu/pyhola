#include <_stdio.h>
#include <libcola/box.h>
#include <libcola/cc_clustercontainmentconstraints.h>
#include <libcola/cluster.h>
#include <libcola/compound_constraints.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <memory>
#include <sstream> // __str__
#include <string>
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

// cola::ClusterContainmentConstraints file:libcola/cc_clustercontainmentconstraints.h line:35
struct PyCallBack_cola_ClusterContainmentConstraints : public cola::ClusterContainmentConstraints {
	using cola::ClusterContainmentConstraints::ClusterContainmentConstraints;

	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ClusterContainmentConstraints *>(this), "updatePosition");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ClusterContainmentConstraints *>(this), "updateVarIDsWithMapping");
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
	void markAllSubConstraintsAsInactive() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ClusterContainmentConstraints *>(this), "markAllSubConstraintsAsInactive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::markAllSubConstraintsAsInactive();
	}
	bool subConstraintsRemaining() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ClusterContainmentConstraints *>(this), "subConstraintsRemaining");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return CompoundConstraint::subConstraintsRemaining();
	}
	void markCurrSubConstraintAsActive(const bool a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ClusterContainmentConstraints *>(this), "markCurrSubConstraintAsActive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::markCurrSubConstraintAsActive(a0);
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::ClusterContainmentConstraints *>(this), "printCreationCode");
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

void bind_libcola_compound_constraints_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::UnsatisfiableConstraintInfo file:libcola/compound_constraints.h line:788
		pybind11::class_<cola::UnsatisfiableConstraintInfo, std::shared_ptr<cola::UnsatisfiableConstraintInfo>> cl(M("cola"), "UnsatisfiableConstraintInfo", "Info about constraints that could not be satisfied in gradient \n        projection process.");
		cl.def( pybind11::init<const class vpsc::Constraint *>(), pybind11::arg("c") );

		cl.def_readwrite("leftVarIndex", &cola::UnsatisfiableConstraintInfo::leftVarIndex);
		cl.def_readwrite("rightVarIndex", &cola::UnsatisfiableConstraintInfo::rightVarIndex);
		cl.def_readwrite("separation", &cola::UnsatisfiableConstraintInfo::separation);
		cl.def_readwrite("equality", &cola::UnsatisfiableConstraintInfo::equality);
	}
	{ // cola::ClusterContainmentConstraints file:libcola/cc_clustercontainmentconstraints.h line:35
		pybind11::class_<cola::ClusterContainmentConstraints, std::shared_ptr<cola::ClusterContainmentConstraints>, PyCallBack_cola_ClusterContainmentConstraints, cola::CompoundConstraint> cl(M("cola"), "ClusterContainmentConstraints", "");
		cl.def( pybind11::init( [](PyCallBack_cola_ClusterContainmentConstraints const &o){ return new PyCallBack_cola_ClusterContainmentConstraints(o); } ) );
		cl.def( pybind11::init( [](cola::ClusterContainmentConstraints const &o){ return new cola::ClusterContainmentConstraints(o); } ) );
		cl.def("assign", (class cola::ClusterContainmentConstraints & (cola::ClusterContainmentConstraints::*)(const class cola::ClusterContainmentConstraints &)) &cola::ClusterContainmentConstraints::operator=, "C++: cola::ClusterContainmentConstraints::operator=(const class cola::ClusterContainmentConstraints &) --> class cola::ClusterContainmentConstraints &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
