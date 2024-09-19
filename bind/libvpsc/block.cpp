#include <libvpsc/block.h>
#include <libvpsc/constraint.h>
#include <libvpsc/exceptions.h>
#include <libvpsc/rectangle.h>
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

void bind_libvpsc_block(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // vpsc::PositionStats file:libvpsc/block.h line:42
		pybind11::class_<vpsc::PositionStats, std::shared_ptr<vpsc::PositionStats>> cl(M("vpsc"), "PositionStats", "");
		cl.def( pybind11::init( [](){ return new vpsc::PositionStats(); } ) );
		cl.def_readwrite("scale", &vpsc::PositionStats::scale);
		cl.def_readwrite("AB", &vpsc::PositionStats::AB);
		cl.def_readwrite("AD", &vpsc::PositionStats::AD);
		cl.def_readwrite("A2", &vpsc::PositionStats::A2);
		cl.def("addVariable", (void (vpsc::PositionStats::*)(class vpsc::Variable *const)) &vpsc::PositionStats::addVariable, "C++: vpsc::PositionStats::addVariable(class vpsc::Variable *const) --> void", pybind11::arg("v"));
	}
	{ // vpsc::Block file:libvpsc/block.h line:51
		pybind11::class_<vpsc::Block, std::shared_ptr<vpsc::Block>> cl(M("vpsc"), "Block", "");
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
		cl.def("getActivePathBetween", (bool (vpsc::Block::*)(int &, const class vpsc::Variable *, const class vpsc::Variable *, const class vpsc::Variable *) const) &vpsc::Block::getActivePathBetween, "C++: vpsc::Block::getActivePathBetween(int &, const class vpsc::Variable *, const class vpsc::Variable *, const class vpsc::Variable *) const --> bool", pybind11::arg("path"), pybind11::arg("u"), pybind11::arg("v"), pybind11::arg("w"));
		cl.def("isActiveDirectedPathBetween", (bool (vpsc::Block::*)(const class vpsc::Variable *, const class vpsc::Variable *) const) &vpsc::Block::isActiveDirectedPathBetween, "C++: vpsc::Block::isActiveDirectedPathBetween(const class vpsc::Variable *, const class vpsc::Variable *) const --> bool", pybind11::arg("u"), pybind11::arg("v"));
		cl.def("getActiveDirectedPathBetween", (bool (vpsc::Block::*)(int &, const class vpsc::Variable *, const class vpsc::Variable *) const) &vpsc::Block::getActiveDirectedPathBetween, "C++: vpsc::Block::getActiveDirectedPathBetween(int &, const class vpsc::Variable *, const class vpsc::Variable *) const --> bool", pybind11::arg("path"), pybind11::arg("u"), pybind11::arg("v"));
	}
	{ // vpsc::Constraint file:libvpsc/constraint.h line:44
		pybind11::class_<vpsc::Constraint, std::shared_ptr<vpsc::Constraint>> cl(M("vpsc"), "Constraint", "A constraint determines a minimum or exact spacing required between\n        two Variable objects.");
		cl.def( pybind11::init( [](class vpsc::Variable * a0, class vpsc::Variable * a1, double const & a2){ return new vpsc::Constraint(a0, a1, a2); } ), "doc" , pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"));
		cl.def( pybind11::init<class vpsc::Variable *, class vpsc::Variable *, double, bool>(), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("gap"), pybind11::arg("equality") );

		cl.def_readwrite("gap", &vpsc::Constraint::gap);
		cl.def_readwrite("lm", &vpsc::Constraint::lm);
		cl.def_readwrite("timeStamp", &vpsc::Constraint::timeStamp);
		cl.def_readwrite("active", &vpsc::Constraint::active);
		cl.def_readonly("equality", &vpsc::Constraint::equality);
		cl.def_readwrite("unsatisfiable", &vpsc::Constraint::unsatisfiable);
		cl.def_readwrite("needsScaling", &vpsc::Constraint::needsScaling);
		cl.def("toString", (int (vpsc::Constraint::*)() const) &vpsc::Constraint::toString, "Returns a textual description of the constraint.\n\n  \n     A string describing the constraint.\n\nC++: vpsc::Constraint::toString() const --> int");
		cl.def("slack", (double (vpsc::Constraint::*)() const) &vpsc::Constraint::slack, "C++: vpsc::Constraint::slack() const --> double");
	}
	{ // vpsc::CompareConstraints file:libvpsc/constraint.h line:119
		pybind11::class_<vpsc::CompareConstraints, std::shared_ptr<vpsc::CompareConstraints>> cl(M("vpsc"), "CompareConstraints", "");
		cl.def( pybind11::init( [](){ return new vpsc::CompareConstraints(); } ) );
		cl.def("__call__", (bool (vpsc::CompareConstraints::*)(class vpsc::Constraint *const &, class vpsc::Constraint *const &) const) &vpsc::CompareConstraints::operator(), "C++: vpsc::CompareConstraints::operator()(class vpsc::Constraint *const &, class vpsc::Constraint *const &) const --> bool", pybind11::arg("l"), pybind11::arg("r"));
	}
	// vpsc::constraintsRemovingRedundantEqualities(const int &, const int &) file:libvpsc/constraint.h line:134
	M("vpsc").def("constraintsRemovingRedundantEqualities", (int (*)(const int &, const int &)) &vpsc::constraintsRemovingRedundantEqualities, "Given a set of variables and constraints, returns a modified set\n         of constraints with all redundant equality constraints removed.\n\n VPSC doesn't work well with redundant equality constraints, usually showing\n them as unsatisfiable.  This function looks for cycles of equality \n constraints and removes the redundant ones.\n\nC++: vpsc::constraintsRemovingRedundantEqualities(const int &, const int &) --> int", pybind11::arg("vars"), pybind11::arg("constraints"));

	{ // vpsc::UnsatisfiableException file:libvpsc/exceptions.h line:27
		pybind11::class_<vpsc::UnsatisfiableException, std::shared_ptr<vpsc::UnsatisfiableException>> cl(M("vpsc"), "UnsatisfiableException", "");
		cl.def( pybind11::init( [](){ return new vpsc::UnsatisfiableException(); } ) );
		cl.def_readwrite("path", &vpsc::UnsatisfiableException::path);
	}
	{ // vpsc::UnsatisfiedConstraint file:libvpsc/exceptions.h line:30
		pybind11::class_<vpsc::UnsatisfiedConstraint, std::shared_ptr<vpsc::UnsatisfiedConstraint>> cl(M("vpsc"), "UnsatisfiedConstraint", "");
		cl.def( pybind11::init<class vpsc::Constraint &>(), pybind11::arg("c") );

	}
	// vpsc::Dim file:libvpsc/rectangle.h line:41
	pybind11::enum_<vpsc::Dim>(M("vpsc"), "Dim", pybind11::arithmetic(), "Indicates the x- or y-dimension.")
		.value("HORIZONTAL", vpsc::HORIZONTAL)
		.value("XDIM", vpsc::XDIM)
		.value("VERTICAL", vpsc::VERTICAL)
		.value("YDIM", vpsc::YDIM)
		.value("UNSET", vpsc::UNSET)
		.export_values();

;

	// vpsc::conjugate(enum vpsc::Dim) file:libvpsc/rectangle.h line:54
	M("vpsc").def("conjugate", (enum vpsc::Dim (*)(enum vpsc::Dim)) &vpsc::conjugate, "C++: vpsc::conjugate(enum vpsc::Dim) --> enum vpsc::Dim", pybind11::arg("d"));

	{ // vpsc::RectangleIntersections file:libvpsc/rectangle.h line:59
		pybind11::class_<vpsc::RectangleIntersections, std::shared_ptr<vpsc::RectangleIntersections>> cl(M("vpsc"), "RectangleIntersections", "");
		cl.def( pybind11::init( [](){ return new vpsc::RectangleIntersections(); } ) );
		cl.def_readwrite("intersects", &vpsc::RectangleIntersections::intersects);
		cl.def_readwrite("top", &vpsc::RectangleIntersections::top);
		cl.def_readwrite("bottom", &vpsc::RectangleIntersections::bottom);
		cl.def_readwrite("left", &vpsc::RectangleIntersections::left);
		cl.def_readwrite("right", &vpsc::RectangleIntersections::right);
		cl.def_readwrite("topX", &vpsc::RectangleIntersections::topX);
		cl.def_readwrite("topY", &vpsc::RectangleIntersections::topY);
		cl.def_readwrite("bottomX", &vpsc::RectangleIntersections::bottomX);
		cl.def_readwrite("bottomY", &vpsc::RectangleIntersections::bottomY);
		cl.def_readwrite("leftX", &vpsc::RectangleIntersections::leftX);
		cl.def_readwrite("leftY", &vpsc::RectangleIntersections::leftY);
		cl.def_readwrite("rightX", &vpsc::RectangleIntersections::rightX);
		cl.def_readwrite("rightY", &vpsc::RectangleIntersections::rightY);
		cl.def("countIntersections", (int (vpsc::RectangleIntersections::*)()) &vpsc::RectangleIntersections::countIntersections, "C++: vpsc::RectangleIntersections::countIntersections() --> int");
		cl.def("printIntersections", (void (vpsc::RectangleIntersections::*)()) &vpsc::RectangleIntersections::printIntersections, "C++: vpsc::RectangleIntersections::printIntersections() --> void");
		cl.def("nearest", (void (vpsc::RectangleIntersections::*)(double, double, double &, double &)) &vpsc::RectangleIntersections::nearest, "C++: vpsc::RectangleIntersections::nearest(double, double, double &, double &) --> void", pybind11::arg("x"), pybind11::arg("y"), pybind11::arg("xi"), pybind11::arg("yi"));
	}
	{ // vpsc::Rectangle file:libvpsc/rectangle.h line:78
		pybind11::class_<vpsc::Rectangle, std::shared_ptr<vpsc::Rectangle>> cl(M("vpsc"), "Rectangle", "A rectangle represents a fixed-size shape in the diagram that may\n         be moved to prevent overlaps and satisfy constraints.");
		cl.def( pybind11::init( [](double const & a0, double const & a1, double const & a2, double const & a3){ return new vpsc::Rectangle(a0, a1, a2, a3); } ), "doc" , pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y"));
		cl.def( pybind11::init<double, double, double, double, bool>(), pybind11::arg("x"), pybind11::arg("X"), pybind11::arg("y"), pybind11::arg("Y"), pybind11::arg("allowOverlap") );

		cl.def( pybind11::init( [](vpsc::Rectangle const &o){ return new vpsc::Rectangle(o); } ) );
		cl.def( pybind11::init( [](){ return new vpsc::Rectangle(); } ) );
		cl.def("isValid", (bool (vpsc::Rectangle::*)() const) &vpsc::Rectangle::isValid, "C++: vpsc::Rectangle::isValid() const --> bool");
		cl.def("unionWith", (class vpsc::Rectangle (vpsc::Rectangle::*)(const class vpsc::Rectangle &) const) &vpsc::Rectangle::unionWith, "C++: vpsc::Rectangle::unionWith(const class vpsc::Rectangle &) const --> class vpsc::Rectangle", pybind11::arg("rhs"));
		cl.def("reset", (void (vpsc::Rectangle::*)(const unsigned int, double, double)) &vpsc::Rectangle::reset, "C++: vpsc::Rectangle::reset(const unsigned int, double, double) --> void", pybind11::arg("d"), pybind11::arg("x"), pybind11::arg("X"));
		cl.def("getMaxX", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMaxX, "C++: vpsc::Rectangle::getMaxX() const --> double");
		cl.def("getMaxY", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMaxY, "C++: vpsc::Rectangle::getMaxY() const --> double");
		cl.def("getMinX", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMinX, "C++: vpsc::Rectangle::getMinX() const --> double");
		cl.def("getMinY", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getMinY, "C++: vpsc::Rectangle::getMinY() const --> double");
		cl.def("getMinD", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::getMinD, "C++: vpsc::Rectangle::getMinD(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("getMaxD", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::getMaxD, "C++: vpsc::Rectangle::getMaxD(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("setMinD", (void (vpsc::Rectangle::*)(const unsigned int, const double)) &vpsc::Rectangle::setMinD, "C++: vpsc::Rectangle::setMinD(const unsigned int, const double) --> void", pybind11::arg("d"), pybind11::arg("val"));
		cl.def("setMaxD", (void (vpsc::Rectangle::*)(const unsigned int, const double)) &vpsc::Rectangle::setMaxD, "C++: vpsc::Rectangle::setMaxD(const unsigned int, const double) --> void", pybind11::arg("d"), pybind11::arg("val"));
		cl.def("getCentreX", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getCentreX, "C++: vpsc::Rectangle::getCentreX() const --> double");
		cl.def("getCentreY", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::getCentreY, "C++: vpsc::Rectangle::getCentreY() const --> double");
		cl.def("getCentreD", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::getCentreD, "C++: vpsc::Rectangle::getCentreD(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("width", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::width, "C++: vpsc::Rectangle::width() const --> double");
		cl.def("height", (double (vpsc::Rectangle::*)() const) &vpsc::Rectangle::height, "C++: vpsc::Rectangle::height() const --> double");
		cl.def("length", (double (vpsc::Rectangle::*)(const unsigned int) const) &vpsc::Rectangle::length, "C++: vpsc::Rectangle::length(const unsigned int) const --> double", pybind11::arg("d"));
		cl.def("set_width", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::set_width, "C++: vpsc::Rectangle::set_width(double) --> void", pybind11::arg("w"));
		cl.def("set_height", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::set_height, "C++: vpsc::Rectangle::set_height(double) --> void", pybind11::arg("h"));
		cl.def("moveCentreD", (void (vpsc::Rectangle::*)(const unsigned int, double)) &vpsc::Rectangle::moveCentreD, "C++: vpsc::Rectangle::moveCentreD(const unsigned int, double) --> void", pybind11::arg("d"), pybind11::arg("p"));
		cl.def("moveCentreX", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveCentreX, "C++: vpsc::Rectangle::moveCentreX(double) --> void", pybind11::arg("x"));
		cl.def("moveCentreY", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveCentreY, "C++: vpsc::Rectangle::moveCentreY(double) --> void", pybind11::arg("y"));
		cl.def("moveCentre", (void (vpsc::Rectangle::*)(double, double)) &vpsc::Rectangle::moveCentre, "C++: vpsc::Rectangle::moveCentre(double, double) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("moveMinX", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveMinX, "C++: vpsc::Rectangle::moveMinX(double) --> void", pybind11::arg("x"));
		cl.def("moveMinY", (void (vpsc::Rectangle::*)(double)) &vpsc::Rectangle::moveMinY, "C++: vpsc::Rectangle::moveMinY(double) --> void", pybind11::arg("y"));
		cl.def("overlapD", (double (vpsc::Rectangle::*)(const unsigned int, class vpsc::Rectangle *)) &vpsc::Rectangle::overlapD, "C++: vpsc::Rectangle::overlapD(const unsigned int, class vpsc::Rectangle *) --> double", pybind11::arg("d"), pybind11::arg("r"));
		cl.def("overlapX", (double (vpsc::Rectangle::*)(class vpsc::Rectangle *) const) &vpsc::Rectangle::overlapX, "C++: vpsc::Rectangle::overlapX(class vpsc::Rectangle *) const --> double", pybind11::arg("r"));
		cl.def("overlapY", (double (vpsc::Rectangle::*)(class vpsc::Rectangle *) const) &vpsc::Rectangle::overlapY, "C++: vpsc::Rectangle::overlapY(class vpsc::Rectangle *) const --> double", pybind11::arg("r"));
		cl.def("allowOverlap", (bool (vpsc::Rectangle::*)()) &vpsc::Rectangle::allowOverlap, "C++: vpsc::Rectangle::allowOverlap() --> bool");
		cl.def("offset", (void (vpsc::Rectangle::*)(double, double)) &vpsc::Rectangle::offset, "C++: vpsc::Rectangle::offset(double, double) --> void", pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("lineIntersections", (void (vpsc::Rectangle::*)(double, double, double, double, struct vpsc::RectangleIntersections &) const) &vpsc::Rectangle::lineIntersections, "C++: vpsc::Rectangle::lineIntersections(double, double, double, double, struct vpsc::RectangleIntersections &) const --> void", pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2"), pybind11::arg("ri"));
		cl.def("inside", (bool (vpsc::Rectangle::*)(double, double) const) &vpsc::Rectangle::inside, "C++: vpsc::Rectangle::inside(double, double) const --> bool", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("overlaps", (bool (vpsc::Rectangle::*)(double, double, double, double)) &vpsc::Rectangle::overlaps, "C++: vpsc::Rectangle::overlaps(double, double, double, double) --> bool", pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2"));
		cl.def("routeAround", (void (vpsc::Rectangle::*)(double, double, double, double, int &, int &)) &vpsc::Rectangle::routeAround, "C++: vpsc::Rectangle::routeAround(double, double, double, double, int &, int &) --> void", pybind11::arg("x1"), pybind11::arg("y1"), pybind11::arg("x2"), pybind11::arg("y2"), pybind11::arg("xs"), pybind11::arg("ys"));
		cl.def_static("setXBorder", (void (*)(double)) &vpsc::Rectangle::setXBorder, "C++: vpsc::Rectangle::setXBorder(double) --> void", pybind11::arg("x"));
		cl.def_static("setYBorder", (void (*)(double)) &vpsc::Rectangle::setYBorder, "C++: vpsc::Rectangle::setYBorder(double) --> void", pybind11::arg("y"));
	}
}
