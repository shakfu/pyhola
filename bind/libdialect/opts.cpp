#include <libdialect/opts.h>
#include <libdialect/ortho.h>
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

void bind_libdialect_opts(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::HolaOpts file:libdialect/opts.h line:67
		pybind11::class_<dialect::HolaOpts, std::shared_ptr<dialect::HolaOpts>> cl(M("dialect"), "HolaOpts", "");
		cl.def( pybind11::init( [](){ return new dialect::HolaOpts(); } ) );
		cl.def_readwrite("defaultTreeGrowthDir", &dialect::HolaOpts::defaultTreeGrowthDir);
		cl.def_readwrite("treeLayoutScalar_nodeSep", &dialect::HolaOpts::treeLayoutScalar_nodeSep);
		cl.def_readwrite("treeLayoutScalar_rankSep", &dialect::HolaOpts::treeLayoutScalar_rankSep);
		cl.def_readwrite("preferConvexTrees", &dialect::HolaOpts::preferConvexTrees);
		cl.def_readwrite("peeledTreeRouting", &dialect::HolaOpts::peeledTreeRouting);
		cl.def_readwrite("wholeTreeRouting", &dialect::HolaOpts::wholeTreeRouting);
		cl.def_readwrite("orthoHubAvoidFlatTriangles", &dialect::HolaOpts::orthoHubAvoidFlatTriangles);
		cl.def_readwrite("useACAforLinks", &dialect::HolaOpts::useACAforLinks);
		cl.def_readwrite("routingScalar_crossingPenalty", &dialect::HolaOpts::routingScalar_crossingPenalty);
		cl.def_readwrite("routingScalar_segmentPenalty", &dialect::HolaOpts::routingScalar_segmentPenalty);
		cl.def_readwrite("routingAbs_nudgingDistance", &dialect::HolaOpts::routingAbs_nudgingDistance);
		cl.def_readwrite("treePlacement_favourCardinal", &dialect::HolaOpts::treePlacement_favourCardinal);
		cl.def_readwrite("treePlacement_favourExternal", &dialect::HolaOpts::treePlacement_favourExternal);
		cl.def_readwrite("treePlacement_favourIsolation", &dialect::HolaOpts::treePlacement_favourIsolation);
		cl.def_readwrite("expansion_doCostlierDimensionFirst", &dialect::HolaOpts::expansion_doCostlierDimensionFirst);
		cl.def_readwrite("expansion_estimateMethod", &dialect::HolaOpts::expansion_estimateMethod);
		cl.def_readwrite("do_near_align", &dialect::HolaOpts::do_near_align);
		cl.def_readwrite("align_reps", &dialect::HolaOpts::align_reps);
		cl.def_readwrite("nearAlignScalar_kinkWidth", &dialect::HolaOpts::nearAlignScalar_kinkWidth);
		cl.def_readwrite("nearAlignScalar_scope", &dialect::HolaOpts::nearAlignScalar_scope);
		cl.def_readwrite("nodePaddingScalar", &dialect::HolaOpts::nodePaddingScalar);
		cl.def_readwrite("preferredAspectRatio", &dialect::HolaOpts::preferredAspectRatio);
		cl.def_readwrite("preferredTreeGrowthDir", &dialect::HolaOpts::preferredTreeGrowthDir);
		cl.def_readwrite("putUlcAtOrigin", &dialect::HolaOpts::putUlcAtOrigin);
	}
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
		cl.def_static("isInDim", (bool (*)(enum dialect::CompassDir, int)) &dialect::Compass::isInDim, "Check whether a compass direction is in a given dimension.\n\nC++: dialect::Compass::isInDim(enum dialect::CompassDir, int) --> bool", pybind11::arg("d"), pybind11::arg("dim"));
		cl.def_static("isIncreasing", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isIncreasing, "Check whether a compass direction is \"increasing\", i.e. the\n         variable coordinate increases in this direction.\n\nC++: dialect::Compass::isIncreasing(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("isDecreasing", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isDecreasing, "Check whether a compass direction is \"decreasing\", i.e. the\n         variable coordinate decreases in this direction.\n\nC++: dialect::Compass::isDecreasing(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("isIncreasingCard", (bool (*)(enum dialect::CardinalDir)) &dialect::Compass::isIncreasingCard, "Check whether a cardinal direction is \"increasing\", i.e. the\n         variable coordinate increases in this direction.\n\nC++: dialect::Compass::isIncreasingCard(enum dialect::CardinalDir) --> bool", pybind11::arg("d"));
		cl.def_static("isDecreasingCard", (bool (*)(enum dialect::CardinalDir)) &dialect::Compass::isDecreasingCard, "Check whether a cardinal direction is \"decreasing\", i.e. the\n         variable coordinate decreases in this direction.\n\nC++: dialect::Compass::isDecreasingCard(enum dialect::CardinalDir) --> bool", pybind11::arg("d"));
		cl.def_static("sameDimension", (bool (*)(enum dialect::CardinalDir, enum dialect::CardinalDir)) &dialect::Compass::sameDimension, "Check whether two cardinal directions are in the same dimension.\n \n\n Compass::arePerpendicular\n\nC++: dialect::Compass::sameDimension(enum dialect::CardinalDir, enum dialect::CardinalDir) --> bool", pybind11::arg("d0"), pybind11::arg("d1"));
		cl.def_static("arePerpendicular", (bool (*)(enum dialect::CardinalDir, enum dialect::CardinalDir)) &dialect::Compass::arePerpendicular, "Check whether two cardinal directions are perpendicular.\n \n\n Compass::sameDimension\n\nC++: dialect::Compass::arePerpendicular(enum dialect::CardinalDir, enum dialect::CardinalDir) --> bool", pybind11::arg("d0"), pybind11::arg("d1"));
		cl.def_static("compassDirection", (enum dialect::CompassDir (*)(int, int)) &dialect::Compass::compassDirection, "Determine the predominant compass direction from point\n         p0 to point p1.\n\nC++: dialect::Compass::compassDirection(int, int) --> enum dialect::CompassDir", pybind11::arg("p0"), pybind11::arg("p1"));
		cl.def_static("compassDirection", (enum dialect::CompassDir (*)(int, int)) &dialect::Compass::compassDirection, "Convenience method to determine the compass direction\n         from Node u0 to Node u1.\n\nC++: dialect::Compass::compassDirection(int, int) --> enum dialect::CompassDir", pybind11::arg("u0"), pybind11::arg("u1"));
		cl.def_static("cardinalDirection", (enum dialect::CardinalDir (*)(int, int)) &dialect::Compass::cardinalDirection, "Determine the predominant cardinal direction from point\n         p0 to point p1.\n\nC++: dialect::Compass::cardinalDirection(int, int) --> enum dialect::CardinalDir", pybind11::arg("p0"), pybind11::arg("p1"));
		cl.def_static("cardinalDirection", (enum dialect::CardinalDir (*)(int, int)) &dialect::Compass::cardinalDirection, "Convenience method to determine the cardinal direction\n         from Node u0 to Node u1.\n\nC++: dialect::Compass::cardinalDirection(int, int) --> enum dialect::CardinalDir", pybind11::arg("u0"), pybind11::arg("u1"));
		cl.def_static("isCardinal", (bool (*)(enum dialect::CompassDir)) &dialect::Compass::isCardinal, "Say whether a CompassDir is cardinal.\n\nC++: dialect::Compass::isCardinal(enum dialect::CompassDir) --> bool", pybind11::arg("d"));
		cl.def_static("cardRotateCw90", (enum dialect::CardinalDir (*)(enum dialect::CardinalDir)) &dialect::Compass::cardRotateCw90, "Rotate a cardinal direction clockwise 90 degrees.\n\nC++: dialect::Compass::cardRotateCw90(enum dialect::CardinalDir) --> enum dialect::CardinalDir", pybind11::arg("d"));
		cl.def_static("cardRotateAcw90", (enum dialect::CardinalDir (*)(enum dialect::CardinalDir)) &dialect::Compass::cardRotateAcw90, "Rotate a cardinal direction anticlockwise 90 degrees.\n\nC++: dialect::Compass::cardRotateAcw90(enum dialect::CardinalDir) --> enum dialect::CardinalDir", pybind11::arg("d"));
		cl.def_static("cardFlip", (enum dialect::CardinalDir (*)(enum dialect::CardinalDir)) &dialect::Compass::cardFlip, "Flip a cardinal direction.\n\nC++: dialect::Compass::cardFlip(enum dialect::CardinalDir) --> enum dialect::CardinalDir", pybind11::arg("d"));
		cl.def_static("dirToString", (int (*)(enum dialect::CompassDir)) &dialect::Compass::dirToString, "Write the name of a CompassDir.\n\nC++: dialect::Compass::dirToString(enum dialect::CompassDir) --> int", pybind11::arg("d"));
		cl.def_static("cardToString", (int (*)(enum dialect::CardinalDir)) &dialect::Compass::cardToString, "Write the name of a CardinalDir.\n\nC++: dialect::Compass::cardToString(enum dialect::CardinalDir) --> int", pybind11::arg("d"));
		cl.def_static("cardinalComponents", (int (*)(enum dialect::CompassDir)) &dialect::Compass::cardinalComponents, "Get the cardinal components of a given direction.\n\nC++: dialect::Compass::cardinalComponents(enum dialect::CompassDir) --> int", pybind11::arg("d"));
		cl.def_static("getRotationFunction", (int (*)(enum dialect::CardinalDir, enum dialect::CardinalDir)) &dialect::Compass::getRotationFunction, "Get a function that rotates points by the angular displacement\n        from one cardinal direction to another.\n \n\n  The starting cardinal direction.\n \n\n  The ending cardinal direction.\n \n\n  A function from Avoid::Points to Avoid::Points.\n \n\n Compass::getInplaceRotationFunction\n\nC++: dialect::Compass::getRotationFunction(enum dialect::CardinalDir, enum dialect::CardinalDir) --> int", pybind11::arg("fromDir"), pybind11::arg("toDir"));
		cl.def_static("getInplaceRotationFunction", (int (*)(enum dialect::CardinalDir, enum dialect::CardinalDir)) &dialect::Compass::getInplaceRotationFunction, "Get a function that rotates points by the angular displacement\n        from one cardinal direction to another.\n \n\n  The starting cardinal direction.\n \n\n  The ending cardinal direction.\n \n\n  A function that alters Avoid::Points in-place.\n \n\n Compass::getRotationFunction\n\nC++: dialect::Compass::getInplaceRotationFunction(enum dialect::CardinalDir, enum dialect::CardinalDir) --> int", pybind11::arg("fromDir"), pybind11::arg("toDir"));
		cl.def_static("vectorSigns", (int (*)(enum dialect::CompassDir)) &dialect::Compass::vectorSigns, "Get the signs of the coordinates of a vector pointing in the given direction.\n \n\n  The direction.\n \n\n  An Avoid::Point (xs, ys), where xs in {-1, 0, 1} represents the sign of the\n          x-coordinate of a vector lying in the \"octant\" represented by the given direction,\n          and likewise for ys. Here an \"octant\" is a semiaxis for a cardinal direction,\n          and an open quadrant for an ordinal direction.\n\nC++: dialect::Compass::vectorSigns(enum dialect::CompassDir) --> int", pybind11::arg("d"));
	}
	{ // dialect::LineSegment file:libdialect/ortho.h line:230
		pybind11::class_<dialect::LineSegment, std::shared_ptr<dialect::LineSegment>> cl(M("dialect"), "LineSegment", "");
		cl.def( pybind11::init( [](){ return new dialect::LineSegment(); } ) );
		cl.def( pybind11::init<int, int>(), pybind11::arg("p0"), pybind11::arg("p1") );

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
		cl.def("closedIntervalIntersection", (int (dialect::LineSegment::*)(double, double) const) &dialect::LineSegment::closedIntervalIntersection, "Compute the intersection of this segment's closed interval, with\n         the given interval.\n \n\n  Low end of the interval.\n \n\n  High end of the interval.\n \n\n  an interval representing the intersection.\n\n \n  If the intersection is empty, we return an \"empty interval\" in which\n        the second coordinate is less than the first.\n\nC++: dialect::LineSegment::closedIntervalIntersection(double, double) const --> int", pybind11::arg("a"), pybind11::arg("b"));
		cl.def("openIntervalIntersection", (int (dialect::LineSegment::*)(double, double) const) &dialect::LineSegment::openIntervalIntersection, "Compute the intersection of this segment's open interval, with\n         the given interval.\n \n\n  Low end of the interval.\n \n\n  High end of the interval.\n \n\n  an interval representing the intersection.\n\n \n  If the intersection is empty, we return an \"empty interval\" in which\n        the second coordinate is less than the first.\n\nC++: dialect::LineSegment::openIntervalIntersection(double, double) const --> int", pybind11::arg("a"), pybind11::arg("b"));
		cl.def("ptOnWhichSide", (int (dialect::LineSegment::*)(int) const) &dialect::LineSegment::ptOnWhichSide, "Check on which side of the line segment a given point lies.\n \n\n  The point in question.\n \n\n  An integer in {-1, 0, 1} indicating, respectively, that in the dimension in\n          which the line segment is constant, the point's coordinate is less than,\n          equal to, or greater than the constant coord of the segment.\n\nC++: dialect::LineSegment::ptOnWhichSide(int) const --> int", pybind11::arg("p"));
		cl.def("coordOnWhichSide", (int (dialect::LineSegment::*)(double) const) &dialect::LineSegment::coordOnWhichSide, "Check whether a given coord is less than, equal to, or greater than the\n         line segment's constant coord.\n \n\n  The coordinate in question.\n \n\n  An integer in {-1, 0, 1} indicating, respectively, that the given coordinate\n          is less than, equal to, or greater that the segment's constant coord.\n\nC++: dialect::LineSegment::coordOnWhichSide(double) const --> int", pybind11::arg("z1"));
	}
}