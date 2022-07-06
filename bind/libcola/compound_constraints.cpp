#include <_stdio.h>
#include <libcola/compound_constraints.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
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

// cola::SeparationConstraint file:libcola/compound_constraints.h line:432
struct PyCallBack_cola_SeparationConstraint : public cola::SeparationConstraint {
	using cola::SeparationConstraint::SeparationConstraint;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SeparationConstraint *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return SeparationConstraint::toString();
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SeparationConstraint *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return SeparationConstraint::printCreationCode(a0);
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SeparationConstraint *>(this), "updatePosition");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SeparationConstraint *>(this), "updateVarIDsWithMapping");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SeparationConstraint *>(this), "markAllSubConstraintsAsInactive");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SeparationConstraint *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SeparationConstraint *>(this), "markCurrSubConstraintAsActive");
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
};

// cola::OrthogonalEdgeConstraint file:libcola/compound_constraints.h line:499
struct PyCallBack_cola_OrthogonalEdgeConstraint : public cola::OrthogonalEdgeConstraint {
	using cola::OrthogonalEdgeConstraint::OrthogonalEdgeConstraint;

	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OrthogonalEdgeConstraint *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return OrthogonalEdgeConstraint::printCreationCode(a0);
	}
	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OrthogonalEdgeConstraint *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return OrthogonalEdgeConstraint::toString();
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OrthogonalEdgeConstraint *>(this), "updatePosition");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OrthogonalEdgeConstraint *>(this), "updateVarIDsWithMapping");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OrthogonalEdgeConstraint *>(this), "markAllSubConstraintsAsInactive");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OrthogonalEdgeConstraint *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OrthogonalEdgeConstraint *>(this), "markCurrSubConstraintAsActive");
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
};

// cola::MultiSeparationConstraint file:libcola/compound_constraints.h line:534
struct PyCallBack_cola_MultiSeparationConstraint : public cola::MultiSeparationConstraint {
	using cola::MultiSeparationConstraint::MultiSeparationConstraint;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::MultiSeparationConstraint *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return MultiSeparationConstraint::toString();
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::MultiSeparationConstraint *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return MultiSeparationConstraint::printCreationCode(a0);
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::MultiSeparationConstraint *>(this), "updatePosition");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::MultiSeparationConstraint *>(this), "updateVarIDsWithMapping");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::MultiSeparationConstraint *>(this), "markAllSubConstraintsAsInactive");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::MultiSeparationConstraint *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::MultiSeparationConstraint *>(this), "markCurrSubConstraintAsActive");
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
};

// cola::DistributionConstraint file:libcola/compound_constraints.h line:611
struct PyCallBack_cola_DistributionConstraint : public cola::DistributionConstraint {
	using cola::DistributionConstraint::DistributionConstraint;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::DistributionConstraint *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return DistributionConstraint::toString();
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::DistributionConstraint *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return DistributionConstraint::printCreationCode(a0);
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::DistributionConstraint *>(this), "updatePosition");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::DistributionConstraint *>(this), "updateVarIDsWithMapping");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::DistributionConstraint *>(this), "markAllSubConstraintsAsInactive");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::DistributionConstraint *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::DistributionConstraint *>(this), "markCurrSubConstraintAsActive");
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
};

// cola::FixedRelativeConstraint file:libcola/compound_constraints.h line:679
struct PyCallBack_cola_FixedRelativeConstraint : public cola::FixedRelativeConstraint {
	using cola::FixedRelativeConstraint::FixedRelativeConstraint;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::FixedRelativeConstraint *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return FixedRelativeConstraint::toString();
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::FixedRelativeConstraint *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return FixedRelativeConstraint::printCreationCode(a0);
	}
	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::FixedRelativeConstraint *>(this), "updateVarIDsWithMapping");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return FixedRelativeConstraint::updateVarIDsWithMapping(a0, a1);
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::FixedRelativeConstraint *>(this), "updatePosition");
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
	void markAllSubConstraintsAsInactive() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::FixedRelativeConstraint *>(this), "markAllSubConstraintsAsInactive");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::FixedRelativeConstraint *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::FixedRelativeConstraint *>(this), "markCurrSubConstraintAsActive");
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
};

// cola::PageBoundaryConstraints file:libcola/compound_constraints.h line:730
struct PyCallBack_cola_PageBoundaryConstraints : public cola::PageBoundaryConstraints {
	using cola::PageBoundaryConstraints::PageBoundaryConstraints;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PageBoundaryConstraints *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return PageBoundaryConstraints::toString();
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PageBoundaryConstraints *>(this), "updatePosition");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return PageBoundaryConstraints::updatePosition(a0);
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PageBoundaryConstraints *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return PageBoundaryConstraints::printCreationCode(a0);
	}
	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PageBoundaryConstraints *>(this), "updateVarIDsWithMapping");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PageBoundaryConstraints *>(this), "markAllSubConstraintsAsInactive");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PageBoundaryConstraints *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::PageBoundaryConstraints *>(this), "markCurrSubConstraintAsActive");
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
};

void bind_libcola_compound_constraints(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::SeparationConstraint file:libcola/compound_constraints.h line:432
		pybind11::class_<cola::SeparationConstraint, std::shared_ptr<cola::SeparationConstraint>, PyCallBack_cola_SeparationConstraint, cola::CompoundConstraint> cl(M("cola"), "SeparationConstraint", "A separation constraint specifies a simple horizontal or vertical \n        spacing constraint between 2 nodes or alignment constraints.\n\n The non-equality constraint is  lPos + g <= rPos\n and the equality constraint is  lPos + g  = rPos\n\n \n With an equality, you can effectively reverse the ordering of the \n       two variables by making the gap a negative number.  This is not so\n       for the non-equality case, there you need to keep the same gap value\n       but reverse the order of the variables passed to the constructor.");
		cl.def( pybind11::init( [](const enum vpsc::Dim & a0, unsigned int const & a1, unsigned int const & a2, double const & a3){ return new cola::SeparationConstraint(a0, a1, a2, a3); }, [](const enum vpsc::Dim & a0, unsigned int const & a1, unsigned int const & a2, double const & a3){ return new PyCallBack_cola_SeparationConstraint(a0, a1, a2, a3); } ), "doc");
		cl.def( pybind11::init<const enum vpsc::Dim, unsigned int, unsigned int, double, bool>(), pybind11::arg("dim"), pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("g"), pybind11::arg("equality") );

		cl.def( pybind11::init( [](const enum vpsc::Dim & a0, class cola::AlignmentConstraint * a1, class cola::AlignmentConstraint * a2, double const & a3){ return new cola::SeparationConstraint(a0, a1, a2, a3); }, [](const enum vpsc::Dim & a0, class cola::AlignmentConstraint * a1, class cola::AlignmentConstraint * a2, double const & a3){ return new PyCallBack_cola_SeparationConstraint(a0, a1, a2, a3); } ), "doc");
		cl.def( pybind11::init<const enum vpsc::Dim, class cola::AlignmentConstraint *, class cola::AlignmentConstraint *, double, bool>(), pybind11::arg("dim"), pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("g"), pybind11::arg("equality") );

		cl.def( pybind11::init( [](PyCallBack_cola_SeparationConstraint const &o){ return new PyCallBack_cola_SeparationConstraint(o); } ) );
		cl.def( pybind11::init( [](cola::SeparationConstraint const &o){ return new cola::SeparationConstraint(o); } ) );
		cl.def_readwrite("gap", &cola::SeparationConstraint::gap);
		cl.def_readwrite("equality", &cola::SeparationConstraint::equality);
		cl.def("toString", (std::string (cola::SeparationConstraint::*)() const) &cola::SeparationConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::SeparationConstraint::toString() const --> std::string");
		cl.def("setSeparation", (void (cola::SeparationConstraint::*)(double)) &cola::SeparationConstraint::setSeparation, "C++: cola::SeparationConstraint::setSeparation(double) --> void", pybind11::arg("gap"));
		cl.def("left", (unsigned int (cola::SeparationConstraint::*)() const) &cola::SeparationConstraint::left, "C++: cola::SeparationConstraint::left() const --> unsigned int");
		cl.def("right", (unsigned int (cola::SeparationConstraint::*)() const) &cola::SeparationConstraint::right, "C++: cola::SeparationConstraint::right() const --> unsigned int");
		cl.def("printCreationCode", (void (cola::SeparationConstraint::*)(struct __sFILE *) const) &cola::SeparationConstraint::printCreationCode, "C++: cola::SeparationConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::SeparationConstraint & (cola::SeparationConstraint::*)(const class cola::SeparationConstraint &)) &cola::SeparationConstraint::operator=, "C++: cola::SeparationConstraint::operator=(const class cola::SeparationConstraint &) --> class cola::SeparationConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::OrthogonalEdgeConstraint file:libcola/compound_constraints.h line:499
		pybind11::class_<cola::OrthogonalEdgeConstraint, std::shared_ptr<cola::OrthogonalEdgeConstraint>, PyCallBack_cola_OrthogonalEdgeConstraint, cola::CompoundConstraint> cl(M("cola"), "OrthogonalEdgeConstraint", "");
		cl.def( pybind11::init<const enum vpsc::Dim, unsigned int, unsigned int>(), pybind11::arg("dim"), pybind11::arg("l"), pybind11::arg("r") );

		cl.def( pybind11::init( [](PyCallBack_cola_OrthogonalEdgeConstraint const &o){ return new PyCallBack_cola_OrthogonalEdgeConstraint(o); } ) );
		cl.def( pybind11::init( [](cola::OrthogonalEdgeConstraint const &o){ return new cola::OrthogonalEdgeConstraint(o); } ) );
		cl.def_readwrite("left", &cola::OrthogonalEdgeConstraint::left);
		cl.def_readwrite("right", &cola::OrthogonalEdgeConstraint::right);
		cl.def("printCreationCode", (void (cola::OrthogonalEdgeConstraint::*)(struct __sFILE *) const) &cola::OrthogonalEdgeConstraint::printCreationCode, "C++: cola::OrthogonalEdgeConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("toString", (std::string (cola::OrthogonalEdgeConstraint::*)() const) &cola::OrthogonalEdgeConstraint::toString, "C++: cola::OrthogonalEdgeConstraint::toString() const --> std::string");
		cl.def("assign", (class cola::OrthogonalEdgeConstraint & (cola::OrthogonalEdgeConstraint::*)(const class cola::OrthogonalEdgeConstraint &)) &cola::OrthogonalEdgeConstraint::operator=, "C++: cola::OrthogonalEdgeConstraint::operator=(const class cola::OrthogonalEdgeConstraint &) --> class cola::OrthogonalEdgeConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::MultiSeparationConstraint file:libcola/compound_constraints.h line:534
		pybind11::class_<cola::MultiSeparationConstraint, std::shared_ptr<cola::MultiSeparationConstraint>, PyCallBack_cola_MultiSeparationConstraint, cola::CompoundConstraint> cl(M("cola"), "MultiSeparationConstraint", "A multi-separation constraint Specifies a set of horizontal or \n        vertical equal spacing constraints between pairs of alignment \n        constraints.\n\n This is a way of arranging a group of alignment lines to be equally \n distributed, or given a uniform minimum spacing.");
		cl.def( pybind11::init( [](const enum vpsc::Dim & a0){ return new cola::MultiSeparationConstraint(a0); }, [](const enum vpsc::Dim & a0){ return new PyCallBack_cola_MultiSeparationConstraint(a0); } ), "doc");
		cl.def( pybind11::init( [](const enum vpsc::Dim & a0, double const & a1){ return new cola::MultiSeparationConstraint(a0, a1); }, [](const enum vpsc::Dim & a0, double const & a1){ return new PyCallBack_cola_MultiSeparationConstraint(a0, a1); } ), "doc");
		cl.def( pybind11::init<const enum vpsc::Dim, double, bool>(), pybind11::arg("dim"), pybind11::arg("minSep"), pybind11::arg("equality") );

		cl.def( pybind11::init( [](PyCallBack_cola_MultiSeparationConstraint const &o){ return new PyCallBack_cola_MultiSeparationConstraint(o); } ) );
		cl.def( pybind11::init( [](cola::MultiSeparationConstraint const &o){ return new cola::MultiSeparationConstraint(o); } ) );
		cl.def_readwrite("cs", &cola::MultiSeparationConstraint::cs);
		cl.def_readwrite("sep", &cola::MultiSeparationConstraint::sep);
		cl.def_readwrite("equality", &cola::MultiSeparationConstraint::equality);
		cl.def("addAlignmentPair", (void (cola::MultiSeparationConstraint::*)(class cola::AlignmentConstraint *, class cola::AlignmentConstraint *)) &cola::MultiSeparationConstraint::addAlignmentPair, "Mark a pair of alignment constraints as being part of this \n        multi separation constraint.\n\n You will often specify spacing beteen a set of alignments (e.g., \n {1, 2, 3, 4}) by calling this method with each neighbouring pair \n (e.g., {(1, 2), (2, 3), (3, 4)}), but you can also specify \n non-neighbouring alignment constraints, if you wish them to have \n equal exact or minimum separation.\n\n \n  A pointer to the left AlignmentConstraint object\n                 of the pair.\n \n\n  A pointer to the right AlignmentConstraint object\n                 of the pair.\n\nC++: cola::MultiSeparationConstraint::addAlignmentPair(class cola::AlignmentConstraint *, class cola::AlignmentConstraint *) --> void", pybind11::arg("ac1"), pybind11::arg("ac2"));
		cl.def("setSeparation", (void (cola::MultiSeparationConstraint::*)(double)) &cola::MultiSeparationConstraint::setSeparation, "Alter the minimum or exact spacing between each pair of\n        alignment constraints.\n\n \n  The minimum or exact distance to separate the\n                 alignment constraints.\n\nC++: cola::MultiSeparationConstraint::setSeparation(double) --> void", pybind11::arg("sep"));
		cl.def("toString", (std::string (cola::MultiSeparationConstraint::*)() const) &cola::MultiSeparationConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::MultiSeparationConstraint::toString() const --> std::string");
		cl.def("printCreationCode", (void (cola::MultiSeparationConstraint::*)(struct __sFILE *) const) &cola::MultiSeparationConstraint::printCreationCode, "C++: cola::MultiSeparationConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::MultiSeparationConstraint & (cola::MultiSeparationConstraint::*)(const class cola::MultiSeparationConstraint &)) &cola::MultiSeparationConstraint::operator=, "C++: cola::MultiSeparationConstraint::operator=(const class cola::MultiSeparationConstraint &) --> class cola::MultiSeparationConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::DistributionConstraint file:libcola/compound_constraints.h line:611
		pybind11::class_<cola::DistributionConstraint, std::shared_ptr<cola::DistributionConstraint>, PyCallBack_cola_DistributionConstraint, cola::CompoundConstraint> cl(M("cola"), "DistributionConstraint", "A distribution constraint specifies an ordered set of alignment \n        constraints and a fixed separation required between them.\n\n This compound constraint it used to keep a set of alignment constraints\n equally distributed.\n\n If no separation distance is set, then it is detemined from the distance \n between the two outer alignments, divided by the number of alignments - 1.");
		cl.def( pybind11::init<const enum vpsc::Dim>(), pybind11::arg("dim") );

		cl.def( pybind11::init( [](PyCallBack_cola_DistributionConstraint const &o){ return new PyCallBack_cola_DistributionConstraint(o); } ) );
		cl.def( pybind11::init( [](cola::DistributionConstraint const &o){ return new cola::DistributionConstraint(o); } ) );
		cl.def_readwrite("cs", &cola::DistributionConstraint::cs);
		cl.def_readwrite("sep", &cola::DistributionConstraint::sep);
		cl.def("addAlignmentPair", (void (cola::DistributionConstraint::*)(class cola::AlignmentConstraint *, class cola::AlignmentConstraint *)) &cola::DistributionConstraint::addAlignmentPair, "Mark a pair of alignment constraints as being part of this \n        distribution constraint.\n\n You should specify spacing beteen a set of alignments (e.g., \n {1, 2, 3, 4}) by calling this method with each neighbouring pair \n (e.g., {(1, 2), (2, 3), (3, 4)}).\n\n \n  A pointer to the left AlignmentConstraint object \n                 of the pair.\n \n\n  A pointer to the right AlignmentConstraint object\n                 of the pair.\n\nC++: cola::DistributionConstraint::addAlignmentPair(class cola::AlignmentConstraint *, class cola::AlignmentConstraint *) --> void", pybind11::arg("ac1"), pybind11::arg("ac2"));
		cl.def("setSeparation", (void (cola::DistributionConstraint::*)(double)) &cola::DistributionConstraint::setSeparation, "Alter the exact spacing between each pair of alignment \n        constraints.\n\n \n  The exact distance to separate the alignment\n                 constraints.\n\nC++: cola::DistributionConstraint::setSeparation(double) --> void", pybind11::arg("sep"));
		cl.def("toString", (std::string (cola::DistributionConstraint::*)() const) &cola::DistributionConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::DistributionConstraint::toString() const --> std::string");
		cl.def("printCreationCode", (void (cola::DistributionConstraint::*)(struct __sFILE *) const) &cola::DistributionConstraint::printCreationCode, "C++: cola::DistributionConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::DistributionConstraint & (cola::DistributionConstraint::*)(const class cola::DistributionConstraint &)) &cola::DistributionConstraint::operator=, "C++: cola::DistributionConstraint::operator=(const class cola::DistributionConstraint &) --> class cola::DistributionConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::FixedRelativeConstraint file:libcola/compound_constraints.h line:679
		pybind11::class_<cola::FixedRelativeConstraint, std::shared_ptr<cola::FixedRelativeConstraint>, PyCallBack_cola_FixedRelativeConstraint, cola::CompoundConstraint> cl(M("cola"), "FixedRelativeConstraint", "A fixed-relative constraint specifies that a group of nodes are\n        constrained to be fixed in position relative to each other.  \n\n These nodes are fixed relative to each other in both the x- and y-dimensions\n but still free to move as a group.\n\n Optionally, this compound constraint can be marked as desiring a fixed\n position.  If this is specified, the group of nodes will attempt to stay\n close to its current position.");
		cl.def( pybind11::init( [](PyCallBack_cola_FixedRelativeConstraint const &o){ return new PyCallBack_cola_FixedRelativeConstraint(o); } ) );
		cl.def( pybind11::init( [](cola::FixedRelativeConstraint const &o){ return new cola::FixedRelativeConstraint(o); } ) );
		cl.def("toString", (std::string (cola::FixedRelativeConstraint::*)() const) &cola::FixedRelativeConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::FixedRelativeConstraint::toString() const --> std::string");
		cl.def("printCreationCode", (void (cola::FixedRelativeConstraint::*)(struct __sFILE *) const) &cola::FixedRelativeConstraint::printCreationCode, "C++: cola::FixedRelativeConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("updateVarIDsWithMapping", [](cola::FixedRelativeConstraint &o, const class cola::VariableIDMap & a0) -> void { return o.updateVarIDsWithMapping(a0); }, "", pybind11::arg("idMap"));
		cl.def("updateVarIDsWithMapping", (void (cola::FixedRelativeConstraint::*)(const class cola::VariableIDMap &, bool)) &cola::FixedRelativeConstraint::updateVarIDsWithMapping, "C++: cola::FixedRelativeConstraint::updateVarIDsWithMapping(const class cola::VariableIDMap &, bool) --> void", pybind11::arg("idMap"), pybind11::arg("forward"));
		cl.def("assign", (class cola::FixedRelativeConstraint & (cola::FixedRelativeConstraint::*)(const class cola::FixedRelativeConstraint &)) &cola::FixedRelativeConstraint::operator=, "C++: cola::FixedRelativeConstraint::operator=(const class cola::FixedRelativeConstraint &) --> class cola::FixedRelativeConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::PageBoundaryConstraints file:libcola/compound_constraints.h line:730
		pybind11::class_<cola::PageBoundaryConstraints, std::shared_ptr<cola::PageBoundaryConstraints>, PyCallBack_cola_PageBoundaryConstraints, cola::CompoundConstraint> cl(M("cola"), "PageBoundaryConstraints", "A page boundary contraint specifies constraints that attempt to keep\n        the given nodes within a defined rectangular region.\n\n This compound constraint creates dummy variables for each of the four edges \n of the page and constraints between all nodes and these dummy vars such \n that nodes are contained between the edges.  The variables for the page \n edges have a high weight but will \"balloon out\" if other constraints force\n nodes to stick out past the ideal edge positions.");
		cl.def( pybind11::init( [](double const & a0, double const & a1, double const & a2, double const & a3){ return new cola::PageBoundaryConstraints(a0, a1, a2, a3); }, [](double const & a0, double const & a1, double const & a2, double const & a3){ return new PyCallBack_cola_PageBoundaryConstraints(a0, a1, a2, a3); } ), "doc");
		cl.def( pybind11::init<double, double, double, double, double>(), pybind11::arg("xLow"), pybind11::arg("xHigh"), pybind11::arg("yLow"), pybind11::arg("yHigh"), pybind11::arg("weight") );

		cl.def( pybind11::init( [](PyCallBack_cola_PageBoundaryConstraints const &o){ return new PyCallBack_cola_PageBoundaryConstraints(o); } ) );
		cl.def( pybind11::init( [](cola::PageBoundaryConstraints const &o){ return new cola::PageBoundaryConstraints(o); } ) );
		cl.def("addShape", (void (cola::PageBoundaryConstraints::*)(unsigned int, double, double)) &cola::PageBoundaryConstraints::addShape, "Mark a node as being contained within this page boundary.\n\n \n   The index of the node in the Rectangles vector.\n \n\n   Half of the width of the node.  Needed because\n                    node position variables represent their centre.\n \n\n   Half of the height of the node.  \n\nC++: cola::PageBoundaryConstraints::addShape(unsigned int, double, double) --> void", pybind11::arg("index"), pybind11::arg("halfW"), pybind11::arg("halfH"));
		cl.def("toString", (std::string (cola::PageBoundaryConstraints::*)() const) &cola::PageBoundaryConstraints::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::PageBoundaryConstraints::toString() const --> std::string");
		cl.def("updatePosition", (void (cola::PageBoundaryConstraints::*)(const enum vpsc::Dim)) &cola::PageBoundaryConstraints::updatePosition, "C++: cola::PageBoundaryConstraints::updatePosition(const enum vpsc::Dim) --> void", pybind11::arg("dim"));
		cl.def("getActualLeftMargin", (double (cola::PageBoundaryConstraints::*)(const enum vpsc::Dim)) &cola::PageBoundaryConstraints::getActualLeftMargin, "C++: cola::PageBoundaryConstraints::getActualLeftMargin(const enum vpsc::Dim) --> double", pybind11::arg("dim"));
		cl.def("getActualRightMargin", (double (cola::PageBoundaryConstraints::*)(const enum vpsc::Dim)) &cola::PageBoundaryConstraints::getActualRightMargin, "C++: cola::PageBoundaryConstraints::getActualRightMargin(const enum vpsc::Dim) --> double", pybind11::arg("dim"));
		cl.def("printCreationCode", (void (cola::PageBoundaryConstraints::*)(struct __sFILE *) const) &cola::PageBoundaryConstraints::printCreationCode, "C++: cola::PageBoundaryConstraints::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::PageBoundaryConstraints & (cola::PageBoundaryConstraints::*)(const class cola::PageBoundaryConstraints &)) &cola::PageBoundaryConstraints::operator=, "C++: cola::PageBoundaryConstraints::operator=(const class cola::PageBoundaryConstraints &) --> class cola::PageBoundaryConstraints &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
