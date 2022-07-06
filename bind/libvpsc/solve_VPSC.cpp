#include <libvpsc/constraint.h>
#include <libvpsc/solve_VPSC.h>
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

// vpsc::Solver file:libvpsc/solve_VPSC.h line:60
struct PyCallBack_vpsc_Solver : public vpsc::Solver {
	using vpsc::Solver::Solver;

	bool satisfy() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const vpsc::Solver *>(this), "satisfy");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Solver::satisfy();
	}
	bool solve() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const vpsc::Solver *>(this), "solve");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Solver::solve();
	}
};

// vpsc::IncSolver file:libvpsc/solve_VPSC.h line:105
struct PyCallBack_vpsc_IncSolver : public vpsc::IncSolver {
	using vpsc::IncSolver::IncSolver;

	bool satisfy() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const vpsc::IncSolver *>(this), "satisfy");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return IncSolver::satisfy();
	}
	bool solve() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const vpsc::IncSolver *>(this), "solve");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return IncSolver::solve();
	}
};

void bind_libvpsc_solve_VPSC(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // vpsc::Solver file:libvpsc/solve_VPSC.h line:60
		pybind11::class_<vpsc::Solver, std::shared_ptr<vpsc::Solver>, PyCallBack_vpsc_Solver> cl(M("vpsc"), "Solver", "Static solver for Variable Placement with Separation Constraints \n        problem instance\n\n This class attempts to solve a least-squares problem subject to a set \n of separation constraints.  The solve() and satisfy() methods return true \n if any constraints are active, in both cases false means an unconstrained \n optimum has been found.\n\n \n IncSolver");
		cl.def( pybind11::init( [](PyCallBack_vpsc_Solver const &o){ return new PyCallBack_vpsc_Solver(o); } ) );
		cl.def( pybind11::init( [](vpsc::Solver const &o){ return new vpsc::Solver(o); } ) );
		cl.def("satisfy", (bool (vpsc::Solver::*)()) &vpsc::Solver::satisfy, "Results in an approximate solution subject to the constraints.\n \n\n true if any constraints are active, or false if an unconstrained \n         optimum has been found.\n\nC++: vpsc::Solver::satisfy() --> bool");
		cl.def("solve", (bool (vpsc::Solver::*)()) &vpsc::Solver::solve, "Results in an optimum solution subject to the constraints\n \n\n true if any constraints are active, or false if an unconstrained \n         optimum has been found.\n\nC++: vpsc::Solver::solve() --> bool");
	}
	{ // vpsc::IncSolver file:libvpsc/solve_VPSC.h line:105
		pybind11::class_<vpsc::IncSolver, std::shared_ptr<vpsc::IncSolver>, PyCallBack_vpsc_IncSolver, vpsc::Solver> cl(M("vpsc"), "IncSolver", "Incremental solver for Variable Placement with Separation Constraints \n        problem instance\n\n This class attempts to solve a least-squares problem subject to a set \n of sepation constraints.  The solve() and satisfy() methods return true \n if any constraints are active, in both cases false means an unconstrained \n optimum has been found.  This is an incremental version of that allows \n refinement after blocks are moved.  This version is preferred if you are \n using VPSC in an interactive context.\n\n \n Solver");
		cl.def( pybind11::init( [](PyCallBack_vpsc_IncSolver const &o){ return new PyCallBack_vpsc_IncSolver(o); } ) );
		cl.def( pybind11::init( [](vpsc::IncSolver const &o){ return new vpsc::IncSolver(o); } ) );
		cl.def("satisfy", (bool (vpsc::IncSolver::*)()) &vpsc::IncSolver::satisfy, "Results in an approximate solution subject to the constraints.\n \n\n true if any constraints are active, or false if an unconstrained \n\nC++: vpsc::IncSolver::satisfy() --> bool");
		cl.def("solve", (bool (vpsc::IncSolver::*)()) &vpsc::IncSolver::solve, "Results in an optimum solution subject to the constraints\n \n\n true if any constraints are active, or false if an unconstrained \n         optimum has been found.\n\nC++: vpsc::IncSolver::solve() --> bool");
		cl.def("addConstraint", (void (vpsc::IncSolver::*)(class vpsc::Constraint *)) &vpsc::IncSolver::addConstraint, "Adds a constraint to the existing VPSC solver.\n\n \n The new additional constraint to add. \n\nC++: vpsc::IncSolver::addConstraint(class vpsc::Constraint *) --> void", pybind11::arg("constraint"));
	}
}
