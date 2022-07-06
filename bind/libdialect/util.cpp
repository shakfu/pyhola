#include <functional>
#include <iterator>
#include <libavoid/geomtypes.h>
#include <libdialect/commontypes.h>
#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/nearalign.h>
#include <libdialect/ortho.h>
#include <libdialect/util.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
#include <utility>
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

void bind_libdialect_util(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::logically_equal(double, double, double) file:libdialect/util.h line:48
	M("dialect").def("logically_equal", [](double const & a0, double const & a1) -> bool { return dialect::logically_equal(a0, a1); }, "", pybind11::arg("a"), pybind11::arg("b"));
	M("dialect").def("logically_equal", (bool (*)(double, double, double)) &dialect::logically_equal, "Tolerant equality test for doubles. Generates principled value\n         for tolerance.\n\n \n  Thanks to: https://stackoverflow.com/a/4010279\n\nC++: dialect::logically_equal(double, double, double) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("error_factor"));

	// dialect::approx_equal(double, double, double) file:libdialect/util.h line:54
	M("dialect").def("approx_equal", [](double const & a0, double const & a1) -> bool { return dialect::approx_equal(a0, a1); }, "", pybind11::arg("a"), pybind11::arg("b"));
	M("dialect").def("approx_equal", (bool (*)(double, double, double)) &dialect::approx_equal, "Tolerant equality test for doubles. Uses arbitrary tolerance.\n\nC++: dialect::approx_equal(double, double, double) --> bool", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("tol"));

	// dialect::CompassDir file:libdialect/ortho.h line:46
	pybind11::enum_<dialect::CompassDir>(M("dialect"), "CompassDir", "")
		.value("EAST", dialect::CompassDir::EAST)
		.value("SOUTH", dialect::CompassDir::SOUTH)
		.value("WEST", dialect::CompassDir::WEST)
		.value("NORTH", dialect::CompassDir::NORTH)
		.value("SE", dialect::CompassDir::SE)
		.value("SW", dialect::CompassDir::SW)
		.value("NW", dialect::CompassDir::NW)
		.value("NE", dialect::CompassDir::NE);

;

	// dialect::CardinalDir file:libdialect/ortho.h line:57
	pybind11::enum_<dialect::CardinalDir>(M("dialect"), "CardinalDir", "")
		.value("EAST", dialect::CardinalDir::EAST)
		.value("SOUTH", dialect::CardinalDir::SOUTH)
		.value("WEST", dialect::CardinalDir::WEST)
		.value("NORTH", dialect::CardinalDir::NORTH);

;

	{ // dialect::Compass file:libdialect/ortho.h line:67
		pybind11::class_<dialect::Compass, std::shared_ptr<dialect::Compass>> cl(M("dialect"), "Compass", "");
		cl.def( pybind11::init( [](){ return new dialect::Compass(); } ) );
		cl.def_static("isVertical", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isVertical, "Check whether a compass direction is vertical.\n\nC++: dialect::Compass::isVertical(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("isHorizontal", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isHorizontal, "Check whether a compass direction is horizontal.\n\nC++: dialect::Compass::isHorizontal(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("isVerticalCard", (bool (*)(enum dialect::CardinalDir)) &dialect::Compass::isVerticalCard, "Check whether a cardinal direction is vertical.\n\nC++: dialect::Compass::isVerticalCard(enum dialect::CardinalDir) --> bool", pybind11::arg("d"));
		cl.def_static("isHorizontalCard", (bool (*)(enum dialect::CardinalDir)) &dialect::Compass::isHorizontalCard, "Check whether a cardinal direction is vertical.\n\nC++: dialect::Compass::isHorizontalCard(enum dialect::CardinalDir) --> bool", pybind11::arg("d"));
		cl.def_static("isInDim", (bool (*)(enum dialect::CompassDir, enum vpsc::Dim)) &dialect::Compass::isInDim, "Check whether a compass direction is in a given dimension.\n\nC++: dialect::Compass::isInDim(enum dialect::CompassDir, enum vpsc::Dim) --> bool", pybind11::arg("d"), pybind11::arg("dim"));
		cl.def_static("isIncreasing", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isIncreasing, "Check whether a compass direction is \"increasing\", i.e. the\n         variable coordinate increases in this direction.\n\nC++: dialect::Compass::isIncreasing(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("isDecreasing", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isDecreasing, "Check whether a compass direction is \"decreasing\", i.e. the\n         variable coordinate decreases in this direction.\n\nC++: dialect::Compass::isDecreasing(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("isIncreasingCard", (bool (*)(enum dialect::CardinalDir)) &dialect::Compass::isIncreasingCard, "Check whether a cardinal direction is \"increasing\", i.e. the\n         variable coordinate increases in this direction.\n\nC++: dialect::Compass::isIncreasingCard(enum dialect::CardinalDir) --> bool", pybind11::arg("d"));
		cl.def_static("isDecreasingCard", (bool (*)(enum dialect::CardinalDir)) &dialect::Compass::isDecreasingCard, "Check whether a cardinal direction is \"decreasing\", i.e. the\n         variable coordinate decreases in this direction.\n\nC++: dialect::Compass::isDecreasingCard(enum dialect::CardinalDir) --> bool", pybind11::arg("d"));
		cl.def_static("sameDimension", (bool (*)(enum dialect::CardinalDir, enum dialect::CardinalDir)) &dialect::Compass::sameDimension, "Check whether two cardinal directions are in the same dimension.\n \n\n Compass::arePerpendicular\n\nC++: dialect::Compass::sameDimension(enum dialect::CardinalDir, enum dialect::CardinalDir) --> bool", pybind11::arg("d0"), pybind11::arg("d1"));
		cl.def_static("arePerpendicular", (bool (*)(enum dialect::CardinalDir, enum dialect::CardinalDir)) &dialect::Compass::arePerpendicular, "Check whether two cardinal directions are perpendicular.\n \n\n Compass::sameDimension\n\nC++: dialect::Compass::arePerpendicular(enum dialect::CardinalDir, enum dialect::CardinalDir) --> bool", pybind11::arg("d0"), pybind11::arg("d1"));
		cl.def_static("compassDirection", (enum dialect::CompassDir (*)(class Avoid::Point, class Avoid::Point)) &dialect::Compass::compassDirection, "Determine the predominant compass direction from point\n         p0 to point p1.\n\nC++: dialect::Compass::compassDirection(class Avoid::Point, class Avoid::Point) --> enum dialect::CompassDir", pybind11::arg("p0"), pybind11::arg("p1"));
		cl.def_static("cardinalDirection", (enum dialect::CardinalDir (*)(class Avoid::Point, class Avoid::Point)) &dialect::Compass::cardinalDirection, "Determine the predominant cardinal direction from point\n         p0 to point p1.\n\nC++: dialect::Compass::cardinalDirection(class Avoid::Point, class Avoid::Point) --> enum dialect::CardinalDir", pybind11::arg("p0"), pybind11::arg("p1"));
		cl.def_static("isCardinal", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isCardinal, "Say whether a CompassDir is cardinal.\n\nC++: dialect::Compass::isCardinal(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("cardRotateCw90", (enum dialect::CardinalDir (*)(enum dialect::CardinalDir)) &dialect::Compass::cardRotateCw90, "Rotate a cardinal direction clockwise 90 degrees.\n\nC++: dialect::Compass::cardRotateCw90(enum dialect::CardinalDir) --> enum dialect::CardinalDir", pybind11::arg("d"));
		cl.def_static("cardRotateAcw90", (enum dialect::CardinalDir (*)(enum dialect::CardinalDir)) &dialect::Compass::cardRotateAcw90, "Rotate a cardinal direction anticlockwise 90 degrees.\n\nC++: dialect::Compass::cardRotateAcw90(enum dialect::CardinalDir) --> enum dialect::CardinalDir", pybind11::arg("d"));
		cl.def_static("cardFlip", (enum dialect::CardinalDir (*)(enum dialect::CardinalDir)) &dialect::Compass::cardFlip, "Flip a cardinal direction.\n\nC++: dialect::Compass::cardFlip(enum dialect::CardinalDir) --> enum dialect::CardinalDir", pybind11::arg("d"));
		cl.def_static("vectorSigns", (class Avoid::Point (*)(enum dialect::CompassDir)) &dialect::Compass::vectorSigns, "Get the signs of the coordinates of a vector pointing in the given direction.\n \n\n  The direction.\n \n\n  An Avoid::Point (xs, ys), where xs in {-1, 0, 1} represents the sign of the\n          x-coordinate of a vector lying in the \"octant\" represented by the given direction,\n          and likewise for ys. Here an \"octant\" is a semiaxis for a cardinal direction,\n          and an open quadrant for an ordinal direction.\n\nC++: dialect::Compass::vectorSigns(enum dialect::CompassDir) --> class Avoid::Point", pybind11::arg("d"));
	}
	{ // dialect::LineSegment file:libdialect/ortho.h line:230
		pybind11::class_<dialect::LineSegment, std::shared_ptr<dialect::LineSegment>> cl(M("dialect"), "LineSegment", "");
		cl.def( pybind11::init<class Avoid::Point, class Avoid::Point>(), pybind11::arg("p0"), pybind11::arg("p1") );

		cl.def( pybind11::init( [](dialect::LineSegment const &o){ return new dialect::LineSegment(o); } ) );
		cl.def_readwrite("p0", &dialect::LineSegment::p0);
		cl.def_readwrite("p1", &dialect::LineSegment::p1);
		cl.def_readwrite("x0", &dialect::LineSegment::x0);
		cl.def_readwrite("y0", &dialect::LineSegment::y0);
		cl.def_readwrite("x1", &dialect::LineSegment::x1);
		cl.def_readwrite("y1", &dialect::LineSegment::y1);
		cl.def_readwrite("direc", &dialect::LineSegment::direc);
		cl.def_readwrite("varDim", &dialect::LineSegment::varDim);
		cl.def_readwrite("constDim", &dialect::LineSegment::constDim);
		cl.def_readwrite("z", &dialect::LineSegment::z);
		cl.def_readwrite("w0", &dialect::LineSegment::w0);
		cl.def_readwrite("w1", &dialect::LineSegment::w1);
		cl.def_readwrite("wl", &dialect::LineSegment::wl);
		cl.def_readwrite("wh", &dialect::LineSegment::wh);
		cl.def_readwrite("length", &dialect::LineSegment::length);
		cl.def("getConstCoord", (double (dialect::LineSegment::*)() const) &dialect::LineSegment::getConstCoord, "Get the constant coordinate.\n\nC++: dialect::LineSegment::getConstCoord() const --> double");
		cl.def("closedIntervalIntersects", (bool (dialect::LineSegment::*)(double, double) const) &dialect::LineSegment::closedIntervalIntersects, "Check whether the closed interval spanned by this segment\n         intersects a given closed interval [a, b].\n \n\n  Low end of the interval.\n \n\n  High end of the interval.\n\nC++: dialect::LineSegment::closedIntervalIntersects(double, double) const --> bool", pybind11::arg("a"), pybind11::arg("b"));
		cl.def("openIntervalIntersects", (bool (dialect::LineSegment::*)(double, double) const) &dialect::LineSegment::openIntervalIntersects, "Check whether the open interval spanned by this segment\n         intersects a given open interval (a, b).\n \n\n  Low end of the interval.\n \n\n  High end of the interval.\n\nC++: dialect::LineSegment::openIntervalIntersects(double, double) const --> bool", pybind11::arg("a"), pybind11::arg("b"));
		cl.def("closedIntervalIncludesCoord", (bool (dialect::LineSegment::*)(double) const) &dialect::LineSegment::closedIntervalIncludesCoord, "Check whether the closed interval spanned by this segment\n         includes a given value.\n \n\n  The value in question.\n\nC++: dialect::LineSegment::closedIntervalIncludesCoord(double) const --> bool", pybind11::arg("a"));
		cl.def("openIntervalIncludesCoord", (bool (dialect::LineSegment::*)(double) const) &dialect::LineSegment::openIntervalIncludesCoord, "Check whether the open interval spanned by this segment\n         includes a given value.\n \n\n  The value in question.\n\nC++: dialect::LineSegment::openIntervalIncludesCoord(double) const --> bool", pybind11::arg("a"));
		cl.def("ptOnWhichSide", (int (dialect::LineSegment::*)(class Avoid::Point) const) &dialect::LineSegment::ptOnWhichSide, "Check on which side of the line segment a given point lies.\n \n\n  The point in question.\n \n\n  An integer in {-1, 0, 1} indicating, respectively, that in the dimension in\n          which the line segment is constant, the point's coordinate is less than,\n          equal to, or greater than the constant coord of the segment.\n\nC++: dialect::LineSegment::ptOnWhichSide(class Avoid::Point) const --> int", pybind11::arg("p"));
		cl.def("coordOnWhichSide", (int (dialect::LineSegment::*)(double) const) &dialect::LineSegment::coordOnWhichSide, "Check whether a given coord is less than, equal to, or greater than the\n         line segment's constant coord.\n \n\n  The coordinate in question.\n \n\n  An integer in {-1, 0, 1} indicating, respectively, that the given coordinate\n          is less than, equal to, or greater that the segment's constant coord.\n\nC++: dialect::LineSegment::coordOnWhichSide(double) const --> int", pybind11::arg("z1"));
		cl.def("assign", (struct dialect::LineSegment & (dialect::LineSegment::*)(const struct dialect::LineSegment &)) &dialect::LineSegment::operator=, "C++: dialect::LineSegment::operator=(const struct dialect::LineSegment &) --> struct dialect::LineSegment &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// dialect::GapType file:libdialect/constraints.h line:48
	pybind11::enum_<dialect::GapType>(M("dialect"), "GapType", "")
		.value("CENTRE", dialect::GapType::CENTRE)
		.value("BDRY", dialect::GapType::BDRY);

;

	// dialect::SepDir file:libdialect/constraints.h line:55
	pybind11::enum_<dialect::SepDir>(M("dialect"), "SepDir", "")
		.value("EAST", dialect::SepDir::EAST)
		.value("SOUTH", dialect::SepDir::SOUTH)
		.value("WEST", dialect::SepDir::WEST)
		.value("NORTH", dialect::SepDir::NORTH)
		.value("RIGHT", dialect::SepDir::RIGHT)
		.value("DOWN", dialect::SepDir::DOWN)
		.value("LEFT", dialect::SepDir::LEFT)
		.value("UP", dialect::SepDir::UP);

;

	// dialect::SepType file:libdialect/constraints.h line:62
	pybind11::enum_<dialect::SepType>(M("dialect"), "SepType", "")
		.value("NONE", dialect::SepType::NONE)
		.value("EQ", dialect::SepType::EQ)
		.value("INEQ", dialect::SepType::INEQ);

;

	// dialect::negateSepDir(enum dialect::SepDir) file:libdialect/constraints.h line:71
	M("dialect").def("negateSepDir", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::negateSepDir, "C++: dialect::negateSepDir(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::sepDirIsCardinal(enum dialect::SepDir) file:libdialect/constraints.h line:73
	M("dialect").def("sepDirIsCardinal", (bool (*)(enum dialect::SepDir)) &dialect::sepDirIsCardinal, "C++: dialect::sepDirIsCardinal(enum dialect::SepDir) --> bool", pybind11::arg("sd"));

	// dialect::sepDirToCardinalDir(enum dialect::SepDir) file:libdialect/constraints.h line:75
	M("dialect").def("sepDirToCardinalDir", (enum dialect::CardinalDir (*)(enum dialect::SepDir)) &dialect::sepDirToCardinalDir, "C++: dialect::sepDirToCardinalDir(enum dialect::SepDir) --> enum dialect::CardinalDir", pybind11::arg("sd"));

	// dialect::cardinalDirToSepDir(enum dialect::CardinalDir) file:libdialect/constraints.h line:77
	M("dialect").def("cardinalDirToSepDir", (enum dialect::SepDir (*)(enum dialect::CardinalDir)) &dialect::cardinalDirToSepDir, "C++: dialect::cardinalDirToSepDir(enum dialect::CardinalDir) --> enum dialect::SepDir", pybind11::arg("dir"));

	// dialect::lateralWeakening(enum dialect::SepDir) file:libdialect/constraints.h line:79
	M("dialect").def("lateralWeakening", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::lateralWeakening, "C++: dialect::lateralWeakening(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::cardinalStrengthening(enum dialect::SepDir) file:libdialect/constraints.h line:81
	M("dialect").def("cardinalStrengthening", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::cardinalStrengthening, "C++: dialect::cardinalStrengthening(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::SepTransform file:libdialect/constraints.h line:83
	pybind11::enum_<dialect::SepTransform>(M("dialect"), "SepTransform", "")
		.value("ROTATE90CW", dialect::SepTransform::ROTATE90CW)
		.value("ROTATE90ACW", dialect::SepTransform::ROTATE90ACW)
		.value("ROTATE180", dialect::SepTransform::ROTATE180)
		.value("FLIPV", dialect::SepTransform::FLIPV)
		.value("FLIPH", dialect::SepTransform::FLIPH)
		.value("FLIPMD", dialect::SepTransform::FLIPMD)
		.value("FLIPOD", dialect::SepTransform::FLIPOD);

;

	{ // dialect::SepPair file:libdialect/constraints.h line:104
		pybind11::class_<dialect::SepPair, std::shared_ptr<dialect::SepPair>> cl(M("dialect"), "SepPair", "");
		cl.def( pybind11::init( [](){ return new dialect::SepPair(); } ) );
		cl.def_readwrite("src", &dialect::SepPair::src);
		cl.def_readwrite("tgt", &dialect::SepPair::tgt);
		cl.def_readwrite("xgt", &dialect::SepPair::xgt);
		cl.def_readwrite("ygt", &dialect::SepPair::ygt);
		cl.def_readwrite("xst", &dialect::SepPair::xst);
		cl.def_readwrite("yst", &dialect::SepPair::yst);
		cl.def_readwrite("xgap", &dialect::SepPair::xgap);
		cl.def_readwrite("ygap", &dialect::SepPair::ygap);
		cl.def_readwrite("tglfPrecision", &dialect::SepPair::tglfPrecision);
		cl.def_readwrite("flippedRetrieval", &dialect::SepPair::flippedRetrieval);
		cl.def("addSep", (void (dialect::SepPair::*)(enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double)) &dialect::SepPair::addSep, "Add a constraint.\n \n\n  addSep method of SepMatrix class\n\nC++: dialect::SepPair::addSep(enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double) --> void", pybind11::arg("gt"), pybind11::arg("sd"), pybind11::arg("st"), pybind11::arg("gap"));
		cl.def("transform", (void (dialect::SepPair::*)(enum dialect::SepTransform)) &dialect::SepPair::transform, "Apply a transformation.\n\nC++: dialect::SepPair::transform(enum dialect::SepTransform) --> void", pybind11::arg("tf"));
		cl.def("isVerticalCardinal", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isVerticalCardinal, "Check whether this SepPair represents a separation in a vertical cardinal compass direction.\n\nC++: dialect::SepPair::isVerticalCardinal() const --> bool");
		cl.def("isHorizontalCardinal", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isHorizontalCardinal, "Check whether this SepPair represents a separation in a horizontal cardinal compass direction.\n\nC++: dialect::SepPair::isHorizontalCardinal() const --> bool");
		cl.def("isVAlign", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isVAlign, "Check whether this SepPair represents a vertical alignment.\n\nC++: dialect::SepPair::isVAlign() const --> bool");
		cl.def("isHAlign", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isHAlign, "Check whether this SepPair represents a horizontal alignment.\n\nC++: dialect::SepPair::isHAlign() const --> bool");
		cl.def("isCardinal", (bool (dialect::SepPair::*)() const) &dialect::SepPair::isCardinal, "Check whether this SepPair represents a separation in a cardinal compass direction.\n\nC++: dialect::SepPair::isCardinal() const --> bool");
		cl.def("getCardinalDir", (enum dialect::CardinalDir (dialect::SepPair::*)() const) &dialect::SepPair::getCardinalDir, "Get the cardinal direction of this separation.\n \n\n  Runtime exception if this separation is not cardinal.\n \n\n The cardinal direction.\n\nC++: dialect::SepPair::getCardinalDir() const --> enum dialect::CardinalDir");
		cl.def("roundGapsUpAbs", (void (dialect::SepPair::*)()) &dialect::SepPair::roundGapsUpAbs, "Round gaps upward in absolute value. Useful when trying to move nodes to integer coords.\n\n E.g., -2.3 goes to -3.0; 2.3 goes to 3.0.\n\nC++: dialect::SepPair::roundGapsUpAbs() --> void");
		cl.def("hasConstraintInDim", (bool (dialect::SepPair::*)(enum vpsc::Dim) const) &dialect::SepPair::hasConstraintInDim, "Check whether there is a constraint in a given dimension.\n\nC++: dialect::SepPair::hasConstraintInDim(enum vpsc::Dim) const --> bool", pybind11::arg("dim"));
	}
}
