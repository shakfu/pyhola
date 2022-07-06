#include <ios>
#include <libavoid/vpsc.h>
#include <locale>
#include <memory>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
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

void bind_libavoid_vpsc(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::CompareConstraints file:libavoid/vpsc.h line:84
		pybind11::class_<Avoid::CompareConstraints, std::shared_ptr<Avoid::CompareConstraints>> cl(M("Avoid"), "CompareConstraints", "");
		cl.def( pybind11::init( [](){ return new Avoid::CompareConstraints(); } ) );
		cl.def("__call__", (bool (Avoid::CompareConstraints::*)(class Avoid::Constraint *const &, class Avoid::Constraint *const &) const) &Avoid::CompareConstraints::operator(), "C++: Avoid::CompareConstraints::operator()(class Avoid::Constraint *const &, class Avoid::Constraint *const &) const --> bool", pybind11::arg("l"), pybind11::arg("r"));
	}
	{ // Avoid::PositionStats file:libavoid/vpsc.h line:88
		pybind11::class_<Avoid::PositionStats, std::shared_ptr<Avoid::PositionStats>> cl(M("Avoid"), "PositionStats", "");
		cl.def( pybind11::init( [](){ return new Avoid::PositionStats(); } ) );
		cl.def_readwrite("scale", &Avoid::PositionStats::scale);
		cl.def_readwrite("AB", &Avoid::PositionStats::AB);
		cl.def_readwrite("AD", &Avoid::PositionStats::AD);
		cl.def_readwrite("A2", &Avoid::PositionStats::A2);
		cl.def("addVariable", (void (Avoid::PositionStats::*)(class Avoid::Variable *const)) &Avoid::PositionStats::addVariable, "C++: Avoid::PositionStats::addVariable(class Avoid::Variable *const) --> void", pybind11::arg("v"));
	}
	{ // Avoid::Block file:libavoid/vpsc.h line:100
		pybind11::class_<Avoid::Block, std::shared_ptr<Avoid::Block>> cl(M("Avoid"), "Block", "");
		cl.def( pybind11::init( [](class Avoid::Blocks * a0){ return new Avoid::Block(a0); } ), "doc" , pybind11::arg("blocks"));
		cl.def( pybind11::init<class Avoid::Blocks *, class Avoid::Variable *const>(), pybind11::arg("blocks"), pybind11::arg("v") );

		cl.def_readwrite("posn", &Avoid::Block::posn);
		cl.def_readwrite("ps", &Avoid::Block::ps);
		cl.def_readwrite("deleted", &Avoid::Block::deleted);
		cl.def_readwrite("timeStamp", &Avoid::Block::timeStamp);
		cl.def("findMinLM", (class Avoid::Constraint * (Avoid::Block::*)()) &Avoid::Block::findMinLM, "C++: Avoid::Block::findMinLM() --> class Avoid::Constraint *", pybind11::return_value_policy::automatic);
		cl.def("findMinLMBetween", (class Avoid::Constraint * (Avoid::Block::*)(class Avoid::Variable *const, class Avoid::Variable *const)) &Avoid::Block::findMinLMBetween, "C++: Avoid::Block::findMinLMBetween(class Avoid::Variable *const, class Avoid::Variable *const) --> class Avoid::Constraint *", pybind11::return_value_policy::automatic, pybind11::arg("lv"), pybind11::arg("rv"));
		cl.def("findMinInConstraint", (class Avoid::Constraint * (Avoid::Block::*)()) &Avoid::Block::findMinInConstraint, "C++: Avoid::Block::findMinInConstraint() --> class Avoid::Constraint *", pybind11::return_value_policy::automatic);
		cl.def("findMinOutConstraint", (class Avoid::Constraint * (Avoid::Block::*)()) &Avoid::Block::findMinOutConstraint, "C++: Avoid::Block::findMinOutConstraint() --> class Avoid::Constraint *", pybind11::return_value_policy::automatic);
		cl.def("deleteMinInConstraint", (void (Avoid::Block::*)()) &Avoid::Block::deleteMinInConstraint, "C++: Avoid::Block::deleteMinInConstraint() --> void");
		cl.def("deleteMinOutConstraint", (void (Avoid::Block::*)()) &Avoid::Block::deleteMinOutConstraint, "C++: Avoid::Block::deleteMinOutConstraint() --> void");
		cl.def("updateWeightedPosition", (void (Avoid::Block::*)()) &Avoid::Block::updateWeightedPosition, "C++: Avoid::Block::updateWeightedPosition() --> void");
		cl.def("merge", (void (Avoid::Block::*)(class Avoid::Block *, class Avoid::Constraint *, double)) &Avoid::Block::merge, "C++: Avoid::Block::merge(class Avoid::Block *, class Avoid::Constraint *, double) --> void", pybind11::arg("b"), pybind11::arg("c"), pybind11::arg("dist"));
		cl.def("merge", (class Avoid::Block * (Avoid::Block::*)(class Avoid::Block *, class Avoid::Constraint *)) &Avoid::Block::merge, "C++: Avoid::Block::merge(class Avoid::Block *, class Avoid::Constraint *) --> class Avoid::Block *", pybind11::return_value_policy::automatic, pybind11::arg("b"), pybind11::arg("c"));
		cl.def("mergeIn", (void (Avoid::Block::*)(class Avoid::Block *)) &Avoid::Block::mergeIn, "C++: Avoid::Block::mergeIn(class Avoid::Block *) --> void", pybind11::arg("b"));
		cl.def("mergeOut", (void (Avoid::Block::*)(class Avoid::Block *)) &Avoid::Block::mergeOut, "C++: Avoid::Block::mergeOut(class Avoid::Block *) --> void", pybind11::arg("b"));
		cl.def("split", (void (Avoid::Block::*)(class Avoid::Block *&, class Avoid::Block *&, class Avoid::Constraint *)) &Avoid::Block::split, "C++: Avoid::Block::split(class Avoid::Block *&, class Avoid::Block *&, class Avoid::Constraint *) --> void", pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("c"));
		cl.def("splitBetween", (class Avoid::Constraint * (Avoid::Block::*)(class Avoid::Variable *, class Avoid::Variable *, class Avoid::Block *&, class Avoid::Block *&)) &Avoid::Block::splitBetween, "C++: Avoid::Block::splitBetween(class Avoid::Variable *, class Avoid::Variable *, class Avoid::Block *&, class Avoid::Block *&) --> class Avoid::Constraint *", pybind11::return_value_policy::automatic, pybind11::arg("vl"), pybind11::arg("vr"), pybind11::arg("lb"), pybind11::arg("rb"));
		cl.def("setUpInConstraints", (void (Avoid::Block::*)()) &Avoid::Block::setUpInConstraints, "C++: Avoid::Block::setUpInConstraints() --> void");
		cl.def("setUpOutConstraints", (void (Avoid::Block::*)()) &Avoid::Block::setUpOutConstraints, "C++: Avoid::Block::setUpOutConstraints() --> void");
		cl.def("cost", (double (Avoid::Block::*)()) &Avoid::Block::cost, "C++: Avoid::Block::cost() --> double");
		cl.def("isActiveDirectedPathBetween", (bool (Avoid::Block::*)(const class Avoid::Variable *, const class Avoid::Variable *) const) &Avoid::Block::isActiveDirectedPathBetween, "C++: Avoid::Block::isActiveDirectedPathBetween(const class Avoid::Variable *, const class Avoid::Variable *) const --> bool", pybind11::arg("u"), pybind11::arg("v"));

		cl.def("__str__", [](Avoid::Block const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // Avoid::Variable file:libavoid/vpsc.h line:162
		pybind11::class_<Avoid::Variable, std::shared_ptr<Avoid::Variable>> cl(M("Avoid"), "Variable", "");
		cl.def( pybind11::init( [](const int & a0){ return new Avoid::Variable(a0); } ), "doc" , pybind11::arg("id"));
		cl.def( pybind11::init( [](const int & a0, const double & a1){ return new Avoid::Variable(a0, a1); } ), "doc" , pybind11::arg("id"), pybind11::arg("desiredPos"));
		cl.def( pybind11::init( [](const int & a0, const double & a1, const double & a2){ return new Avoid::Variable(a0, a1, a2); } ), "doc" , pybind11::arg("id"), pybind11::arg("desiredPos"), pybind11::arg("weight"));
		cl.def( pybind11::init<const int, const double, const double, const double>(), pybind11::arg("id"), pybind11::arg("desiredPos"), pybind11::arg("weight"), pybind11::arg("scale") );

		cl.def( pybind11::init( [](Avoid::Variable const &o){ return new Avoid::Variable(o); } ) );
		cl.def_readwrite("id", &Avoid::Variable::id);
		cl.def_readwrite("desiredPosition", &Avoid::Variable::desiredPosition);
		cl.def_readwrite("finalPosition", &Avoid::Variable::finalPosition);
		cl.def_readwrite("weight", &Avoid::Variable::weight);
		cl.def_readwrite("scale", &Avoid::Variable::scale);
		cl.def_readwrite("offset", &Avoid::Variable::offset);
		cl.def_readwrite("visited", &Avoid::Variable::visited);
		cl.def_readwrite("fixedDesiredPosition", &Avoid::Variable::fixedDesiredPosition);
		cl.def_readwrite("in", &Avoid::Variable::in);
		cl.def_readwrite("out", &Avoid::Variable::out);
		cl.def("dfdv", (double (Avoid::Variable::*)() const) &Avoid::Variable::dfdv, "C++: Avoid::Variable::dfdv() const --> double");

		cl.def("__str__", [](Avoid::Variable const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // Avoid::Constraint file:libavoid/vpsc.h line:208
		pybind11::class_<Avoid::Constraint, std::shared_ptr<Avoid::Constraint>> cl(M("Avoid"), "Constraint", "");
		cl.def( pybind11::init( [](class Avoid::Variable * a0, class Avoid::Variable * a1, double const & a2){ return new Avoid::Constraint(a0, a1, a2); } ), "doc" , pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"));
		cl.def( pybind11::init<class Avoid::Variable *, class Avoid::Variable *, double, bool>(), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"), pybind11::arg("equality") );

		cl.def_readwrite("gap", &Avoid::Constraint::gap);
		cl.def_readwrite("lm", &Avoid::Constraint::lm);
		cl.def_readwrite("timeStamp", &Avoid::Constraint::timeStamp);
		cl.def_readwrite("active", &Avoid::Constraint::active);
		cl.def_readonly("equality", &Avoid::Constraint::equality);
		cl.def_readwrite("unsatisfiable", &Avoid::Constraint::unsatisfiable);
		cl.def_readwrite("needsScaling", &Avoid::Constraint::needsScaling);
		cl.def("slack", (double (Avoid::Constraint::*)() const) &Avoid::Constraint::slack, "C++: Avoid::Constraint::slack() const --> double");

		cl.def("__str__", [](Avoid::Constraint const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
	{ // Avoid::Blocks file:libavoid/vpsc.h line:247
		pybind11::class_<Avoid::Blocks, std::shared_ptr<Avoid::Blocks>> cl(M("Avoid"), "Blocks", "");
		cl.def( pybind11::init( [](Avoid::Blocks const &o){ return new Avoid::Blocks(o); } ) );
		cl.def_readwrite("blockTimeCtr", &Avoid::Blocks::blockTimeCtr);
		cl.def("mergeLeft", (void (Avoid::Blocks::*)(class Avoid::Block *)) &Avoid::Blocks::mergeLeft, "C++: Avoid::Blocks::mergeLeft(class Avoid::Block *) --> void", pybind11::arg("r"));
		cl.def("mergeRight", (void (Avoid::Blocks::*)(class Avoid::Block *)) &Avoid::Blocks::mergeRight, "C++: Avoid::Blocks::mergeRight(class Avoid::Block *) --> void", pybind11::arg("l"));
		cl.def("split", (void (Avoid::Blocks::*)(class Avoid::Block *, class Avoid::Block *&, class Avoid::Block *&, class Avoid::Constraint *)) &Avoid::Blocks::split, "C++: Avoid::Blocks::split(class Avoid::Block *, class Avoid::Block *&, class Avoid::Block *&, class Avoid::Constraint *) --> void", pybind11::arg("b"), pybind11::arg("l"), pybind11::arg("r"), pybind11::arg("c"));
		cl.def("cleanup", (void (Avoid::Blocks::*)()) &Avoid::Blocks::cleanup, "C++: Avoid::Blocks::cleanup() --> void");
		cl.def("cost", (double (Avoid::Blocks::*)()) &Avoid::Blocks::cost, "C++: Avoid::Blocks::cost() --> double");
		cl.def("size", (unsigned long (Avoid::Blocks::*)() const) &Avoid::Blocks::size, "C++: Avoid::Blocks::size() const --> unsigned long");
		cl.def("at", (class Avoid::Block * (Avoid::Blocks::*)(unsigned long) const) &Avoid::Blocks::at, "C++: Avoid::Blocks::at(unsigned long) const --> class Avoid::Block *", pybind11::return_value_policy::automatic, pybind11::arg("index"));
		cl.def("insert", (void (Avoid::Blocks::*)(class Avoid::Block *)) &Avoid::Blocks::insert, "C++: Avoid::Blocks::insert(class Avoid::Block *) --> void", pybind11::arg("block"));
	}
	{ // Avoid::UnsatisfiableException file:libavoid/vpsc.h line:288
		pybind11::class_<Avoid::UnsatisfiableException, std::shared_ptr<Avoid::UnsatisfiableException>> cl(M("Avoid"), "UnsatisfiableException", "");
		cl.def( pybind11::init( [](){ return new Avoid::UnsatisfiableException(); } ) );
		cl.def( pybind11::init( [](Avoid::UnsatisfiableException const &o){ return new Avoid::UnsatisfiableException(o); } ) );
		cl.def_readwrite("path", &Avoid::UnsatisfiableException::path);
	}
	{ // Avoid::UnsatisfiedConstraint file:libavoid/vpsc.h line:291
		pybind11::class_<Avoid::UnsatisfiedConstraint, std::shared_ptr<Avoid::UnsatisfiedConstraint>> cl(M("Avoid"), "UnsatisfiedConstraint", "");
		cl.def( pybind11::init<class Avoid::Constraint &>(), pybind11::arg("c") );

	}
	{ // Avoid::IncSolver file:libavoid/vpsc.h line:298
		pybind11::class_<Avoid::IncSolver, std::shared_ptr<Avoid::IncSolver>> cl(M("Avoid"), "IncSolver", "");
		cl.def( pybind11::init( [](Avoid::IncSolver const &o){ return new Avoid::IncSolver(o); } ) );
		cl.def_readwrite("splitCnt", &Avoid::IncSolver::splitCnt);
		cl.def("satisfy", (bool (Avoid::IncSolver::*)()) &Avoid::IncSolver::satisfy, "C++: Avoid::IncSolver::satisfy() --> bool");
		cl.def("solve", (bool (Avoid::IncSolver::*)()) &Avoid::IncSolver::solve, "C++: Avoid::IncSolver::solve() --> bool");
		cl.def("moveBlocks", (void (Avoid::IncSolver::*)()) &Avoid::IncSolver::moveBlocks, "C++: Avoid::IncSolver::moveBlocks() --> void");
		cl.def("splitBlocks", (void (Avoid::IncSolver::*)()) &Avoid::IncSolver::splitBlocks, "C++: Avoid::IncSolver::splitBlocks() --> void");
		cl.def("addConstraint", (void (Avoid::IncSolver::*)(class Avoid::Constraint *)) &Avoid::IncSolver::addConstraint, "C++: Avoid::IncSolver::addConstraint(class Avoid::Constraint *) --> void", pybind11::arg("constraint"));
	}
	{ // Avoid::delete_object file:libavoid/vpsc.h line:328
		pybind11::class_<Avoid::delete_object, std::shared_ptr<Avoid::delete_object>> cl(M("Avoid"), "delete_object", "");
		cl.def( pybind11::init( [](){ return new Avoid::delete_object(); } ) );
	}
}
