#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/solve_VPSC.h>
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

void bind_libvpsc_rectangle(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// vpsc::generateXConstraints(const int &, const int &, int &, const bool) file:libvpsc/rectangle.h line:252
	M("vpsc").def("generateXConstraints", (void (*)(const int &, const int &, int &, const bool)) &vpsc::generateXConstraints, "C++: vpsc::generateXConstraints(const int &, const int &, int &, const bool) --> void", pybind11::arg("rs"), pybind11::arg("vars"), pybind11::arg("cs"), pybind11::arg("useNeighbourLists"));

	// vpsc::generateYConstraints(const int &, const int &, int &) file:libvpsc/rectangle.h line:254
	M("vpsc").def("generateYConstraints", (void (*)(const int &, const int &, int &)) &vpsc::generateYConstraints, "C++: vpsc::generateYConstraints(const int &, const int &, int &) --> void", pybind11::arg("rs"), pybind11::arg("vars"), pybind11::arg("cs"));

	// vpsc::removeoverlaps(int &) file:libvpsc/rectangle.h line:265
	M("vpsc").def("removeoverlaps", (void (*)(int &)) &vpsc::removeoverlaps, "Uses VPSC to remove overlaps between rectangles.\n\n Moves rectangles to remove all overlaps.  Heuristic attempts to move \n shapes by as little as possible.\n\n \n  The rectangles which will be moved to remove overlap\n\nC++: vpsc::removeoverlaps(int &) --> void", pybind11::arg("rs"));

	// vpsc::removeoverlaps(int &, const int &, bool) file:libvpsc/rectangle.h line:286
	M("vpsc").def("removeoverlaps", [](int & a0, const int & a1) -> void { return vpsc::removeoverlaps(a0, a1); }, "", pybind11::arg("rs"), pybind11::arg("fixed"));
	M("vpsc").def("removeoverlaps", (void (*)(int &, const int &, bool)) &vpsc::removeoverlaps, "Uses VPSC to remove overlaps between rectangles, excluding some \n        that should not be moved.\n\n Moves rectangles to remove all overlaps.  A heuristic attempts to move \n shapes by as little as possible.  The heuristic is that the overlaps \n are removed horizontally and then vertically, each pass being a \n quadratic program in which the total squared movement is minimised \n subject to non-overlap constraints.  \n\n An optional third horizontal pass (in addition to the first horizontal\n pass and the second vertical pass) can be applied wherein the \n x-positions of rectangles are reset to their original positions and \n overlap removal repeated.  This may avoid some unnecessary movement. \n\n \n    The rectangles which will be moved to remove overlap\n \n\n     A set of indices to rectangles which should not be moved.\n \n\n Optionally run the third horizontal pass described above.\n\nC++: vpsc::removeoverlaps(int &, const int &, bool) --> void", pybind11::arg("rs"), pybind11::arg("fixed"), pybind11::arg("thirdPass"));

	// vpsc::noRectangleOverlaps(const int &) file:libvpsc/rectangle.h line:290
	M("vpsc").def("noRectangleOverlaps", (bool (*)(const int &)) &vpsc::noRectangleOverlaps, "C++: vpsc::noRectangleOverlaps(const int &) --> bool", pybind11::arg("rs"));

	{ // vpsc::delete_object file:libvpsc/rectangle.h line:292
		pybind11::class_<vpsc::delete_object, std::shared_ptr<vpsc::delete_object>> cl(M("vpsc"), "delete_object", "");
		cl.def( pybind11::init( [](){ return new vpsc::delete_object(); } ) );
	}
	{ // vpsc::Solver file:libvpsc/solve_VPSC.h line:60
		pybind11::class_<vpsc::Solver, std::shared_ptr<vpsc::Solver>, PyCallBack_vpsc_Solver> cl(M("vpsc"), "Solver", "Static solver for Variable Placement with Separation Constraints \n        problem instance\n\n This class attempts to solve a least-squares problem subject to a set \n of separation constraints.  The solve() and satisfy() methods return true \n if any constraints are active, in both cases false means an unconstrained \n optimum has been found.\n\n \n IncSolver");
		cl.def( pybind11::init<const int &, const int &>(), pybind11::arg("vs"), pybind11::arg("cs") );

		cl.def( pybind11::init( [](PyCallBack_vpsc_Solver const &o){ return new PyCallBack_vpsc_Solver(o); } ) );
		cl.def( pybind11::init( [](vpsc::Solver const &o){ return new vpsc::Solver(o); } ) );
		cl.def("satisfy", (bool (vpsc::Solver::*)()) &vpsc::Solver::satisfy, "Results in an approximate solution subject to the constraints.\n \n\n true if any constraints are active, or false if an unconstrained \n         optimum has been found.\n\nC++: vpsc::Solver::satisfy() --> bool");
		cl.def("solve", (bool (vpsc::Solver::*)()) &vpsc::Solver::solve, "Results in an optimum solution subject to the constraints\n \n\n true if any constraints are active, or false if an unconstrained \n         optimum has been found.\n\nC++: vpsc::Solver::solve() --> bool");
		cl.def("getVariables", (const int & (vpsc::Solver::*)()) &vpsc::Solver::getVariables, "Returns the Variables in this problem instance.\n \n\n A vector of Variable objects.\n\nC++: vpsc::Solver::getVariables() --> const int &", pybind11::return_value_policy::automatic);
		cl.def("assign", (class vpsc::Solver & (vpsc::Solver::*)(const class vpsc::Solver &)) &vpsc::Solver::operator=, "C++: vpsc::Solver::operator=(const class vpsc::Solver &) --> class vpsc::Solver &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // vpsc::IncSolver file:libvpsc/solve_VPSC.h line:105
		pybind11::class_<vpsc::IncSolver, std::shared_ptr<vpsc::IncSolver>, PyCallBack_vpsc_IncSolver, vpsc::Solver> cl(M("vpsc"), "IncSolver", "Incremental solver for Variable Placement with Separation Constraints \n        problem instance\n\n This class attempts to solve a least-squares problem subject to a set \n of sepation constraints.  The solve() and satisfy() methods return true \n if any constraints are active, in both cases false means an unconstrained \n optimum has been found.  This is an incremental version of that allows \n refinement after blocks are moved.  This version is preferred if you are \n using VPSC in an interactive context.\n\n \n Solver");
		cl.def( pybind11::init<const int &, const int &>(), pybind11::arg("vs"), pybind11::arg("cs") );

		cl.def( pybind11::init( [](PyCallBack_vpsc_IncSolver const &o){ return new PyCallBack_vpsc_IncSolver(o); } ) );
		cl.def( pybind11::init( [](vpsc::IncSolver const &o){ return new vpsc::IncSolver(o); } ) );
		cl.def("satisfy", (bool (vpsc::IncSolver::*)()) &vpsc::IncSolver::satisfy, "Results in an approximate solution subject to the constraints.\n \n\n true if any constraints are active, or false if an unconstrained \n\nC++: vpsc::IncSolver::satisfy() --> bool");
		cl.def("solve", (bool (vpsc::IncSolver::*)()) &vpsc::IncSolver::solve, "Results in an optimum solution subject to the constraints\n \n\n true if any constraints are active, or false if an unconstrained \n         optimum has been found.\n\nC++: vpsc::IncSolver::solve() --> bool");
		cl.def("addConstraint", (void (vpsc::IncSolver::*)(class vpsc::Constraint *)) &vpsc::IncSolver::addConstraint, "Adds a constraint to the existing VPSC solver.\n\n \n The new additional constraint to add. \n\nC++: vpsc::IncSolver::addConstraint(class vpsc::Constraint *) --> void", pybind11::arg("constraint"));
		cl.def("assign", (class vpsc::IncSolver & (vpsc::IncSolver::*)(const class vpsc::IncSolver &)) &vpsc::IncSolver::operator=, "C++: vpsc::IncSolver::operator=(const class vpsc::IncSolver &) --> class vpsc::IncSolver &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // vpsc::Variable file:libvpsc/variable.h line:44
		pybind11::class_<vpsc::Variable, std::shared_ptr<vpsc::Variable>> cl(M("vpsc"), "Variable", "A variable is comprised of an ideal position, final position and \n        a weight.\n\n When creating a variable you specify an ideal value, and a weight---how \n much the variable wants to be at its ideal position.  After solving the \n problem you can read back the final position for the variable.");
		cl.def( pybind11::init( [](const int & a0){ return new vpsc::Variable(a0); } ), "doc" , pybind11::arg("id"));
		cl.def( pybind11::init( [](const int & a0, const double & a1){ return new vpsc::Variable(a0, a1); } ), "doc" , pybind11::arg("id"), pybind11::arg("desiredPos"));
		cl.def( pybind11::init( [](const int & a0, const double & a1, const double & a2){ return new vpsc::Variable(a0, a1, a2); } ), "doc" , pybind11::arg("id"), pybind11::arg("desiredPos"), pybind11::arg("weight"));
		cl.def( pybind11::init<const int, const double, const double, const double>(), pybind11::arg("id"), pybind11::arg("desiredPos"), pybind11::arg("weight"), pybind11::arg("scale") );

		cl.def_readwrite("id", &vpsc::Variable::id);
		cl.def_readwrite("desiredPosition", &vpsc::Variable::desiredPosition);
		cl.def_readwrite("finalPosition", &vpsc::Variable::finalPosition);
		cl.def_readwrite("weight", &vpsc::Variable::weight);
		cl.def_readwrite("scale", &vpsc::Variable::scale);
		cl.def_readwrite("offset", &vpsc::Variable::offset);
		cl.def_readwrite("visited", &vpsc::Variable::visited);
		cl.def_readwrite("fixedDesiredPosition", &vpsc::Variable::fixedDesiredPosition);
		cl.def_readwrite("in", &vpsc::Variable::in);
		cl.def_readwrite("out", &vpsc::Variable::out);
		cl.def("toString", (char * (vpsc::Variable::*)()) &vpsc::Variable::toString, "C++: vpsc::Variable::toString() --> char *", pybind11::return_value_policy::automatic);
		cl.def("dfdv", (double (vpsc::Variable::*)() const) &vpsc::Variable::dfdv, "C++: vpsc::Variable::dfdv() const --> double");
	}
}
