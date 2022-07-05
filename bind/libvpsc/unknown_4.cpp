#include <ios>
#include <libvpsc/blocks.h>
#include <locale>
#include <memory>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
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

void bind_unknown_unknown_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // vpsc::PositionStats file: line:42
		pybind11::class_<vpsc::PositionStats, std::shared_ptr<vpsc::PositionStats>> cl(M("vpsc"), "PositionStats", "");
		cl.def( pybind11::init( [](){ return new vpsc::PositionStats(); } ) );
		cl.def_readwrite("scale", &vpsc::PositionStats::scale);
		cl.def_readwrite("AB", &vpsc::PositionStats::AB);
		cl.def_readwrite("AD", &vpsc::PositionStats::AD);
		cl.def_readwrite("A2", &vpsc::PositionStats::A2);
		cl.def("addVariable", (void (vpsc::PositionStats::*)(class vpsc::Variable *const)) &vpsc::PositionStats::addVariable, "C++: vpsc::PositionStats::addVariable(class vpsc::Variable *const) --> void", pybind11::arg("v"));
	}
	{ // vpsc::Block file: line:51
		pybind11::class_<vpsc::Block, std::shared_ptr<vpsc::Block>> cl(M("vpsc"), "Block", "");
		cl.def( pybind11::init( [](class vpsc::Blocks * a0){ return new vpsc::Block(a0); } ), "doc" , pybind11::arg("blocks"));
		cl.def( pybind11::init<class vpsc::Blocks *, class vpsc::Variable *const>(), pybind11::arg("blocks"), pybind11::arg("v") );

		cl.def_readwrite("posn", &vpsc::Block::posn);
		cl.def_readwrite("ps", &vpsc::Block::ps);
		cl.def_readwrite("deleted", &vpsc::Block::deleted);
		cl.def_readwrite("timeStamp", &vpsc::Block::timeStamp);
		cl.def("findMinLM", (class vpsc::Constraint * (vpsc::Block::*)()) &vpsc::Block::findMinLM, "C++: vpsc::Block::findMinLM() --> class vpsc::Constraint *", pybind11::return_value_policy::automatic);
		cl.def("findMinLMBetween", (class vpsc::Constraint * (vpsc::Block::*)(class vpsc::Variable *const, class vpsc::Variable *const)) &vpsc::Block::findMinLMBetween, "C++: vpsc::Block::findMinLMBetween(class vpsc::Variable *const, class vpsc::Variable *const) --> class vpsc::Constraint *", pybind11::return_value_policy::automatic, pybind11::arg("lv"), pybind11::arg("rv"));
		cl.def("findMinInConstraint", (class vpsc::Constraint * (vpsc::Block::*)()) &vpsc::Block::findMinInConstraint, "C++: vpsc::Block::findMinInConstraint() --> class vpsc::Constraint *", pybind11::return_value_policy::automatic);
		cl.def("findMinOutConstraint", (class vpsc::Constraint * (vpsc::Block::*)()) &vpsc::Block::findMinOutConstraint, "C++: vpsc::Block::findMinOutConstraint() --> class vpsc::Constraint *", pybind11::return_value_policy::automatic);
		cl.def("deleteMinInConstraint", (void (vpsc::Block::*)()) &vpsc::Block::deleteMinInConstraint, "C++: vpsc::Block::deleteMinInConstraint() --> void");
		cl.def("deleteMinOutConstraint", (void (vpsc::Block::*)()) &vpsc::Block::deleteMinOutConstraint, "C++: vpsc::Block::deleteMinOutConstraint() --> void");
		cl.def("updateWeightedPosition", (void (vpsc::Block::*)()) &vpsc::Block::updateWeightedPosition, "C++: vpsc::Block::updateWeightedPosition() --> void");
		cl.def("merge", (void (vpsc::Block::*)(class vpsc::Block *, class vpsc::Constraint *, double)) &vpsc::Block::merge, "C++: vpsc::Block::merge(class vpsc::Block *, class vpsc::Constraint *, double) --> void", pybind11::arg("b"), pybind11::arg("c"), pybind11::arg("dist"));
		cl.def("merge", (class vpsc::Block * (vpsc::Block::*)(class vpsc::Block *, class vpsc::Constraint *)) &vpsc::Block::merge, "C++: vpsc::Block::merge(class vpsc::Block *, class vpsc::Constraint *) --> class vpsc::Block *", pybind11::return_value_policy::automatic, pybind11::arg("b"), pybind11::arg("c"));
		cl.def("mergeIn", (void (vpsc::Block::*)(class vpsc::Block *)) &vpsc::Block::mergeIn, "C++: vpsc::Block::mergeIn(class vpsc::Block *) --> void", pybind11::arg("b"));
		cl.def("mergeOut", (void (vpsc::Block::*)(class vpsc::Block *)) &vpsc::Block::mergeOut, "C++: vpsc::Block::mergeOut(class vpsc::Block *) --> void", pybind11::arg("b"));
		cl.def("split", (void (vpsc::Block::*)(class vpsc::Block *&, class vpsc::Block *&, class vpsc::Constraint *)) &vpsc::Block::split, "C++: vpsc::Block::split(class vpsc::Block *&, class vpsc::Block *&, class vpsc::Constraint *) --> void", pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("c"));
		cl.def("splitBetween", (class vpsc::Constraint * (vpsc::Block::*)(class vpsc::Variable *, class vpsc::Variable *, class vpsc::Block *&, class vpsc::Block *&)) &vpsc::Block::splitBetween, "C++: vpsc::Block::splitBetween(class vpsc::Variable *, class vpsc::Variable *, class vpsc::Block *&, class vpsc::Block *&) --> class vpsc::Constraint *", pybind11::return_value_policy::automatic, pybind11::arg("vl"), pybind11::arg("vr"), pybind11::arg("lb"), pybind11::arg("rb"));
		cl.def("setUpInConstraints", (void (vpsc::Block::*)()) &vpsc::Block::setUpInConstraints, "C++: vpsc::Block::setUpInConstraints() --> void");
		cl.def("setUpOutConstraints", (void (vpsc::Block::*)()) &vpsc::Block::setUpOutConstraints, "C++: vpsc::Block::setUpOutConstraints() --> void");
		cl.def("cost", (double (vpsc::Block::*)()) &vpsc::Block::cost, "C++: vpsc::Block::cost() --> double");
		cl.def("isActiveDirectedPathBetween", (bool (vpsc::Block::*)(const class vpsc::Variable *, const class vpsc::Variable *) const) &vpsc::Block::isActiveDirectedPathBetween, "C++: vpsc::Block::isActiveDirectedPathBetween(const class vpsc::Variable *, const class vpsc::Variable *) const --> bool", pybind11::arg("u"), pybind11::arg("v"));

		cl.def("__str__", [](vpsc::Block const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // vpsc::Variable file: line:44
		pybind11::class_<vpsc::Variable, std::shared_ptr<vpsc::Variable>> cl(M("vpsc"), "Variable", "A variable is comprised of an ideal position, final position and \n        a weight.\n\n When creating a variable you specify an ideal value, and a weight---how \n much the variable wants to be at its ideal position.  After solving the \n problem you can read back the final position for the variable.");
		cl.def( pybind11::init( [](const int & a0){ return new vpsc::Variable(a0); } ), "doc" , pybind11::arg("id"));
		cl.def( pybind11::init( [](const int & a0, const double & a1){ return new vpsc::Variable(a0, a1); } ), "doc" , pybind11::arg("id"), pybind11::arg("desiredPos"));
		cl.def( pybind11::init( [](const int & a0, const double & a1, const double & a2){ return new vpsc::Variable(a0, a1, a2); } ), "doc" , pybind11::arg("id"), pybind11::arg("desiredPos"), pybind11::arg("weight"));
		cl.def( pybind11::init<const int, const double, const double, const double>(), pybind11::arg("id"), pybind11::arg("desiredPos"), pybind11::arg("weight"), pybind11::arg("scale") );

		cl.def( pybind11::init( [](vpsc::Variable const &o){ return new vpsc::Variable(o); } ) );
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

		cl.def("__str__", [](vpsc::Variable const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // vpsc::Constraint file: line:44
		pybind11::class_<vpsc::Constraint, std::shared_ptr<vpsc::Constraint>> cl(M("vpsc"), "Constraint", "A constraint determines a minimum or exact spacing required between\n        two Variable objects.");
		cl.def( pybind11::init( [](class vpsc::Variable * a0, class vpsc::Variable * a1, double const & a2){ return new vpsc::Constraint(a0, a1, a2); } ), "doc" , pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"));
		cl.def( pybind11::init<class vpsc::Variable *, class vpsc::Variable *, double, bool>(), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"), pybind11::arg("equality") );

		cl.def( pybind11::init( [](vpsc::Constraint const &o){ return new vpsc::Constraint(o); } ) );
		cl.def_readwrite("gap", &vpsc::Constraint::gap);
		cl.def_readwrite("lm", &vpsc::Constraint::lm);
		cl.def_readwrite("timeStamp", &vpsc::Constraint::timeStamp);
		cl.def_readwrite("active", &vpsc::Constraint::active);
		cl.def_readonly("equality", &vpsc::Constraint::equality);
		cl.def_readwrite("unsatisfiable", &vpsc::Constraint::unsatisfiable);
		cl.def_readwrite("needsScaling", &vpsc::Constraint::needsScaling);
		cl.def("toString", (std::string (vpsc::Constraint::*)() const) &vpsc::Constraint::toString, "Returns a textual description of the constraint.\n\n  \n     A string describing the constraint.\n\nC++: vpsc::Constraint::toString() const --> std::string");
		cl.def("slack", (double (vpsc::Constraint::*)() const) &vpsc::Constraint::slack, "C++: vpsc::Constraint::slack() const --> double");

		cl.def("__str__", [](vpsc::Constraint const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // vpsc::CompareConstraints file: line:119
		pybind11::class_<vpsc::CompareConstraints, std::shared_ptr<vpsc::CompareConstraints>> cl(M("vpsc"), "CompareConstraints", "");
		cl.def( pybind11::init( [](){ return new vpsc::CompareConstraints(); } ) );
		cl.def("__call__", (bool (vpsc::CompareConstraints::*)(class vpsc::Constraint *const &, class vpsc::Constraint *const &) const) &vpsc::CompareConstraints::operator(), "C++: vpsc::CompareConstraints::operator()(class vpsc::Constraint *const &, class vpsc::Constraint *const &) const --> bool", pybind11::arg("l"), pybind11::arg("r"));
	}
}
