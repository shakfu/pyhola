#include <_stdio.h>
#include <libproject/project.h>
#include <libproject/project_log.h>
#include <libproject/util.h>
#include <memory>
#include <sstream>
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

// project::ExternalAlphaCheck file:libproject/project.h line:228
struct PyCallBack_project_ExternalAlphaCheck : public project::ExternalAlphaCheck {
	using project::ExternalAlphaCheck::ExternalAlphaCheck;

	void operator()(double a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const project::ExternalAlphaCheck *>(this), "__call__");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"ExternalAlphaCheck::__call__\"");
	}
};

void bind_libproject_util(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // project::delete_object file:libproject/util.h line:55
		pybind11::class_<project::delete_object, std::shared_ptr<project::delete_object>> cl(M("project"), "delete_object", "templated delete functor for use in for_each loop over vector");
		cl.def( pybind11::init( [](){ return new project::delete_object(); } ) );
	}
	{ // project::Uncopyable file:libproject/util.h line:78
		pybind11::class_<project::Uncopyable, project::Uncopyable*> cl(M("project"), "Uncopyable", "Item 6 in Meyers' Effective C++: \n Explicitly disallow the use of compiler-generated functions you do not want");
	}
	// project::approx_equals(double, double) file:libproject/util.h line:88
	M("project").def("approx_equals", (bool (*)(double, double)) &project::approx_equals, "C++: project::approx_equals(double, double) --> bool", pybind11::arg("a"), pybind11::arg("b"));

	{ // project::Initial file:libproject/project.h line:46
		pybind11::class_<project::Initial, std::shared_ptr<project::Initial>> cl(M("project"), "Initial", "type for Initial position for Variable ctor");
		cl.def( pybind11::init<double>(), pybind11::arg("pos") );

		cl.def_readwrite("pos", &project::Initial::pos);
	}
	{ // project::Desired file:libproject/project.h line:51
		pybind11::class_<project::Desired, std::shared_ptr<project::Desired>> cl(M("project"), "Desired", "type for Desired position for Variable ctor");
		cl.def( pybind11::init<double>(), pybind11::arg("pos") );

		cl.def_readwrite("pos", &project::Desired::pos);
	}
	{ // project::Weight file:libproject/project.h line:56
		pybind11::class_<project::Weight, std::shared_ptr<project::Weight>> cl(M("project"), "Weight", "type for Weight of Variable ctor");
		cl.def( pybind11::init<double>(), pybind11::arg("w") );

		cl.def( pybind11::init( [](project::Weight const &o){ return new project::Weight(o); } ) );
		cl.def_readwrite("w", &project::Weight::w);
	}
	{ // project::Variable file:libproject/project.h line:63
		pybind11::class_<project::Variable, std::shared_ptr<project::Variable>> cl(M("project"), "Variable", "Data for a Variable in a projection problem.");
		cl.def( pybind11::init<const unsigned int, const struct project::Initial &>(), pybind11::arg("id"), pybind11::arg("i") );

		cl.def( pybind11::init( [](const unsigned int & a0, const struct project::Initial & a1, const struct project::Desired & a2){ return new project::Variable(a0, a1, a2); } ), "doc" , pybind11::arg("id"), pybind11::arg("i"), pybind11::arg("d"));
		cl.def( pybind11::init<const unsigned int, const struct project::Initial &, const struct project::Desired &, const struct project::Weight &>(), pybind11::arg("id"), pybind11::arg("i"), pybind11::arg("d"), pybind11::arg("w") );

		cl.def( pybind11::init( [](const struct project::Initial & a0, const struct project::Desired & a1){ return new project::Variable(a0, a1); } ), "doc" , pybind11::arg("i"), pybind11::arg("d"));
		cl.def( pybind11::init<const struct project::Initial &, const struct project::Desired &, const struct project::Weight &>(), pybind11::arg("i"), pybind11::arg("d"), pybind11::arg("w") );

		cl.def( pybind11::init( [](project::Variable const &o){ return new project::Variable(o); } ) );
		cl.def_readonly("id", &project::Variable::id);
		cl.def("setPosition", (void (project::Variable::*)(const struct project::Desired &)) &project::Variable::setPosition, "It may be necessary for the user to change the desired position after\n the Variable is created.\n\nC++: project::Variable::setPosition(const struct project::Desired &) --> void", pybind11::arg("des"));
		cl.def("getDesiredPosition", (double (project::Variable::*)() const) &project::Variable::getDesiredPosition, "C++: project::Variable::getDesiredPosition() const --> double");
		cl.def("setWeight", (void (project::Variable::*)(const struct project::Weight &)) &project::Variable::setWeight, "Similarly weight may need to be adjusted after initialisation\n\nC++: project::Variable::setWeight(const struct project::Weight &) --> void", pybind11::arg("weight"));
		cl.def("getWeight", (double (project::Variable::*)() const) &project::Variable::getWeight, "C++: project::Variable::getWeight() const --> double");
		cl.def("getPosition", (double (project::Variable::*)() const) &project::Variable::getPosition, "get the current position (x)\n\nC++: project::Variable::getPosition() const --> double");
		cl.def("setPosition", (void (project::Variable::*)(const struct project::Initial &)) &project::Variable::setPosition, "C++: project::Variable::setPosition(const struct project::Initial &) --> void", pybind11::arg("p"));
		cl.def("dfdv", (double (project::Variable::*)() const) &project::Variable::dfdv, "compute derivative of goal function\n\nC++: project::Variable::dfdv() const --> double");
		cl.def("displacement", (double (project::Variable::*)() const) &project::Variable::displacement, "weighted displacement from ideal position for block position\n\nC++: project::Variable::displacement() const --> double");
		cl.def("cost", (double (project::Variable::*)() const) &project::Variable::cost, "compute cost of goal function at current position\n\nC++: project::Variable::cost() const --> double");
		cl.def("relativeInitialPos", (double (project::Variable::*)() const) &project::Variable::relativeInitialPos, "block->XI + b\n\nC++: project::Variable::relativeInitialPos() const --> double");
		cl.def("relativeDesiredPos", (double (project::Variable::*)() const) &project::Variable::relativeDesiredPos, "block->X + b\n\nC++: project::Variable::relativeDesiredPos() const --> double");
		cl.def("updatePosition", (void (project::Variable::*)()) &project::Variable::updatePosition, "recompute the current position based on offset and block position\n\nC++: project::Variable::updatePosition() --> void");
		cl.def("moveBy", (void (project::Variable::*)(double)) &project::Variable::moveBy, "move x by alpha along the line from the relative initial position\n  to the relative desired position\n\nC++: project::Variable::moveBy(double) --> void", pybind11::arg("alpha"));
		cl.def("clearConstraints", (void (project::Variable::*)()) &project::Variable::clearConstraints, "C++: project::Variable::clearConstraints() --> void");
	}
	// project::compute_dfdv(const class project::Variable *, const class project::Constraint *) file:libproject/project.h line:132
	M("project").def("compute_dfdv", (double (*)(const class project::Variable *, const class project::Constraint *)) &project::compute_dfdv, "C++: project::compute_dfdv(const class project::Variable *, const class project::Constraint *) --> double", pybind11::arg(""), pybind11::arg(""));

	{ // project::Constraint file:libproject/project.h line:138
		pybind11::class_<project::Constraint, std::shared_ptr<project::Constraint>> cl(M("project"), "Constraint", "A separation constraint of the form \n\n ");
		cl.def( pybind11::init<class project::Variable *, class project::Variable *, const double>(), pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("g") );

		cl.def_readonly("g", &project::Constraint::g);
		cl.def("initialSlack", (double (project::Constraint::*)() const) &project::Constraint::initialSlack, "C++: project::Constraint::initialSlack() const --> double");
		cl.def("feasibleAtDesired", (bool (project::Constraint::*)() const) &project::Constraint::feasibleAtDesired, "true if the constraint can be satisfied at the relative desired\n positions for l and r.\n\nC++: project::Constraint::feasibleAtDesired() const --> bool");
		cl.def("maxSafeAlpha", (double (project::Constraint::*)() const) &project::Constraint::maxSafeAlpha, "the maximum move we can make along the line from initial to\n desired positions without violating this constraint\n\nC++: project::Constraint::maxSafeAlpha() const --> double");
		cl.def("setActive", (void (project::Constraint::*)(bool)) &project::Constraint::setActive, "C++: project::Constraint::setActive(bool) --> void", pybind11::arg("val"));
		cl.def("isActive", (bool (project::Constraint::*)() const) &project::Constraint::isActive, "C++: project::Constraint::isActive() const --> bool");
		cl.def("resetLM", (void (project::Constraint::*)()) &project::Constraint::resetLM, "C++: project::Constraint::resetLM() --> void");
		cl.def("wantsToMoveApart", (bool (project::Constraint::*)() const) &project::Constraint::wantsToMoveApart, "C++: project::Constraint::wantsToMoveApart() const --> bool");
	}
	// project::cmpLagrangians(class project::Constraint *, class project::Constraint *) file:libproject/project.h line:175
	M("project").def("cmpLagrangians", (bool (*)(class project::Constraint *, class project::Constraint *)) &project::cmpLagrangians, "C++: project::cmpLagrangians(class project::Constraint *, class project::Constraint *) --> bool", pybind11::arg("a"), pybind11::arg("b"));

	{ // project::Block file:libproject/project.h line:182
		pybind11::class_<project::Block, std::shared_ptr<project::Block>> cl(M("project"), "Block", "A block is a set of variables spanned by a tree of active constraints.");
		cl.def( pybind11::init<class project::Variable *>(), pybind11::arg("v") );

		cl.def( pybind11::init<class project::Variable *, class project::Constraint *>(), pybind11::arg("v"), pybind11::arg("c") );

		cl.def( pybind11::init( [](project::Block const &o){ return new project::Block(o); } ) );
		cl.def_readwrite("V", &project::Block::V);
		cl.def_readwrite("w", &project::Block::w);
		cl.def_readwrite("C", &project::Block::C);
		cl.def_readwrite("X", &project::Block::X);
		cl.def_readwrite("XI", &project::Block::XI);
		cl.def("optimalPosition", (double (project::Block::*)() const) &project::Block::optimalPosition, "Compute the optimal position for this block based on the ideal positions of\n its constituent variables.  \n\nC++: project::Block::optimalPosition() const --> double");
		cl.def("computeLagrangians", (void (project::Block::*)()) &project::Block::computeLagrangians, "compute the lagrangian multipliers of all the active constraints in this block.\n\nC++: project::Block::computeLagrangians() --> void");
		cl.def("toDesired", (double (project::Block::*)() const) &project::Block::toDesired, "vector to desired position\n\nC++: project::Block::toDesired() const --> double");
	}
	{ // project::ExternalAlphaCheck file:libproject/project.h line:228
		pybind11::class_<project::ExternalAlphaCheck, std::shared_ptr<project::ExternalAlphaCheck>, PyCallBack_project_ExternalAlphaCheck> cl(M("project"), "ExternalAlphaCheck", "Override this functor and pass in a pointer to the implementation using \n Project::setExternalAlphaCheck in order to apply extra checks in each \n invocation of findSafeMove.");
		cl.def( pybind11::init( [](){ return new PyCallBack_project_ExternalAlphaCheck(); } ) );
		cl.def("__call__", (void (project::ExternalAlphaCheck::*)(double)) &project::ExternalAlphaCheck::operator(), "C++: project::ExternalAlphaCheck::operator()(double) --> void", pybind11::arg(""));
		cl.def("assign", (struct project::ExternalAlphaCheck & (project::ExternalAlphaCheck::*)(const struct project::ExternalAlphaCheck &)) &project::ExternalAlphaCheck::operator=, "C++: project::ExternalAlphaCheck::operator=(const struct project::ExternalAlphaCheck &) --> struct project::ExternalAlphaCheck &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // project::Project file:libproject/project.h line:239
		pybind11::class_<project::Project, std::shared_ptr<project::Project>> cl(M("project"), "Project", "A solver that projects onto separation constraints, starting from a\n feasible solution, and maintaining feasibility at all times.");
		cl.def("solve", (bool (project::Project::*)()) &project::Project::solve, "attempts to solve a least-squares\n problem subject to a set of separation constraints.\n \n\n false if an unsatisfiable constraint is found\n\nC++: project::Project::solve() --> bool");
		cl.def("cost", (double (project::Project::*)() const) &project::Project::cost, "computes cost of the goal function over all variables\n\nC++: project::Project::cost() const --> double");
		cl.def("setExternalAlphaCheck", (void (project::Project::*)(struct project::ExternalAlphaCheck *)) &project::Project::setExternalAlphaCheck, "Set a pointer to a function that checks to make sure a given alpha does\n not violate some external condition.\n\nC++: project::Project::setExternalAlphaCheck(struct project::ExternalAlphaCheck *) --> void", pybind11::arg("check"));
	}
	{ // project::CriticalFailure file:libproject/project.h line:325
		pybind11::class_<project::CriticalFailure, std::shared_ptr<project::CriticalFailure>> cl(M("project"), "CriticalFailure", "Critical failure: either something went wrong with the solver or (more likely) there\n was infeasible input.");
		cl.def( pybind11::init<const char *, const char *, int, const char *>(), pybind11::arg("expr"), pybind11::arg("file"), pybind11::arg("line"), pybind11::arg("function") );

		cl.def_readwrite("line", &project::CriticalFailure::line);
		cl.def("print", (void (project::CriticalFailure::*)()) &project::CriticalFailure::print, "C++: project::CriticalFailure::print() --> void");
	}
	// project::TLogLevel file:libproject/project_log.h line:41
	pybind11::enum_<project::TLogLevel>(M("project"), "TLogLevel", pybind11::arithmetic(), "")
		.value("logERROR", project::logERROR)
		.value("logWARNING", project::logWARNING)
		.value("logINFO", project::logINFO)
		.value("logDEBUG", project::logDEBUG)
		.value("logDEBUG1", project::logDEBUG1)
		.value("logDEBUG2", project::logDEBUG2)
		.value("logDEBUG3", project::logDEBUG3)
		.value("logDEBUG4", project::logDEBUG4)
		.export_values();

;

	{ // project::Log file:libproject/project_log.h line:44
		pybind11::class_<project::Log<project::Output2FILE>, std::shared_ptr<project::Log<project::Output2FILE>>> cl(M("project"), "Log_project_Output2FILE_t", "");
		cl.def( pybind11::init( [](){ return new project::Log<project::Output2FILE>(); } ) );
		cl.def_static("ReportingLevel", (enum project::TLogLevel & (*)()) &project::Log<project::Output2FILE>::ReportingLevel, "C++: project::Log<project::Output2FILE>::ReportingLevel() --> enum project::TLogLevel &", pybind11::return_value_policy::automatic);
	}
	{ // project::Output2FILE file:libproject/project_log.h line:119
		pybind11::class_<project::Output2FILE, std::shared_ptr<project::Output2FILE>> cl(M("project"), "Output2FILE", "");
		cl.def( pybind11::init( [](){ return new project::Output2FILE(); } ) );
		cl.def_static("Stream", (struct __sFILE *& (*)()) &project::Output2FILE::Stream, "C++: project::Output2FILE::Stream() --> struct __sFILE *&", pybind11::return_value_policy::automatic);
	}
	{ // project::FILELog file:libproject/project_log.h line:153
		pybind11::class_<project::FILELog, std::shared_ptr<project::FILELog>, project::Log<project::Output2FILE>> cl(M("project"), "FILELog", "");
		cl.def( pybind11::init( [](){ return new project::FILELog(); } ) );
	}
}
