#include <_stdio.h>
#include <functional>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
#include <string_view>
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

// dialect::SepPairSubConstraintInfo file: line:176
struct PyCallBack_dialect_SepPairSubConstraintInfo : public dialect::SepPairSubConstraintInfo {
	using dialect::SepPairSubConstraintInfo::SepPairSubConstraintInfo;

	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepPairSubConstraintInfo *>(this), "updateVarIDsWithMapping");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return SubConstraintInfo::updateVarIDsWithMapping(a0, a1);
	}
};

// dialect::SepMatrix file: line:185
struct PyCallBack_dialect_SepMatrix : public dialect::SepMatrix {
	using dialect::SepMatrix::SepMatrix;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return SepMatrix::toString();
	}
	void markAllSubConstraintsAsInactive() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "markAllSubConstraintsAsInactive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return SepMatrix::markAllSubConstraintsAsInactive();
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "updatePosition");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "updateVarIDsWithMapping");
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
	bool subConstraintsRemaining() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "markCurrSubConstraintAsActive");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::SepMatrix *>(this), "printCreationCode");
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

void bind_unknown_unknown_14(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::GapType file: line:48
	pybind11::enum_<dialect::GapType>(M("dialect"), "GapType", "")
		.value("CENTRE", dialect::GapType::CENTRE)
		.value("BDRY", dialect::GapType::BDRY);

;

	// dialect::SepDir file: line:55
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

	// dialect::SepType file: line:62
	pybind11::enum_<dialect::SepType>(M("dialect"), "SepType", "")
		.value("NONE", dialect::SepType::NONE)
		.value("EQ", dialect::SepType::EQ)
		.value("INEQ", dialect::SepType::INEQ);

;

	// dialect::negateSepDir(enum dialect::SepDir) file: line:71
	M("dialect").def("negateSepDir", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::negateSepDir, "C++: dialect::negateSepDir(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::sepDirIsCardinal(enum dialect::SepDir) file: line:73
	M("dialect").def("sepDirIsCardinal", (bool (*)(enum dialect::SepDir)) &dialect::sepDirIsCardinal, "C++: dialect::sepDirIsCardinal(enum dialect::SepDir) --> bool", pybind11::arg("sd"));

	// dialect::sepDirToCardinalDir(enum dialect::SepDir) file: line:75
	M("dialect").def("sepDirToCardinalDir", (enum dialect::CardinalDir (*)(enum dialect::SepDir)) &dialect::sepDirToCardinalDir, "C++: dialect::sepDirToCardinalDir(enum dialect::SepDir) --> enum dialect::CardinalDir", pybind11::arg("sd"));

	// dialect::cardinalDirToSepDir(enum dialect::CardinalDir) file: line:77
	M("dialect").def("cardinalDirToSepDir", (enum dialect::SepDir (*)(enum dialect::CardinalDir)) &dialect::cardinalDirToSepDir, "C++: dialect::cardinalDirToSepDir(enum dialect::CardinalDir) --> enum dialect::SepDir", pybind11::arg("dir"));

	// dialect::lateralWeakening(enum dialect::SepDir) file: line:79
	M("dialect").def("lateralWeakening", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::lateralWeakening, "C++: dialect::lateralWeakening(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::cardinalStrengthening(enum dialect::SepDir) file: line:81
	M("dialect").def("cardinalStrengthening", (enum dialect::SepDir (*)(enum dialect::SepDir)) &dialect::cardinalStrengthening, "C++: dialect::cardinalStrengthening(enum dialect::SepDir) --> enum dialect::SepDir", pybind11::arg("sd"));

	// dialect::SepTransform file: line:83
	pybind11::enum_<dialect::SepTransform>(M("dialect"), "SepTransform", "")
		.value("ROTATE90CW", dialect::SepTransform::ROTATE90CW)
		.value("ROTATE90ACW", dialect::SepTransform::ROTATE90ACW)
		.value("ROTATE180", dialect::SepTransform::ROTATE180)
		.value("FLIPV", dialect::SepTransform::FLIPV)
		.value("FLIPH", dialect::SepTransform::FLIPH)
		.value("FLIPMD", dialect::SepTransform::FLIPMD)
		.value("FLIPOD", dialect::SepTransform::FLIPOD);

;

	{ // dialect::SepPair file: line:104
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
		cl.def("writeTglf", (std::string (dialect::SepPair::*)(class std::map<unsigned int, unsigned int, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, unsigned int> > >, const class dialect::SepMatrix &) const) &dialect::SepPair::writeTglf, "Write a representation of this constraint in the format of\n         the SEPCO'S section of the TGLF file format.\n \n\n  Mapping from internal Node IDs to external IDs for the TGLF output.\n\nC++: dialect::SepPair::writeTglf(class std::map<unsigned int, unsigned int, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, unsigned int> > >, const class dialect::SepMatrix &) const --> std::string", pybind11::arg("id2ext"), pybind11::arg("m"));
		cl.def("hasConstraintInDim", (bool (dialect::SepPair::*)(enum vpsc::Dim) const) &dialect::SepPair::hasConstraintInDim, "Check whether there is a constraint in a given dimension.\n\nC++: dialect::SepPair::hasConstraintInDim(enum vpsc::Dim) const --> bool", pybind11::arg("dim"));
	}
	{ // dialect::SepPairSubConstraintInfo file: line:176
		pybind11::class_<dialect::SepPairSubConstraintInfo, std::shared_ptr<dialect::SepPairSubConstraintInfo>, PyCallBack_dialect_SepPairSubConstraintInfo, cola::SubConstraintInfo> cl(M("dialect"), "SepPairSubConstraintInfo", "Since each SepPair may represent up to two VPSC constraints (one in each dimension), we need a simple wrapper\n struct to represent each dimension.");
		cl.def( pybind11::init<class std::shared_ptr<struct dialect::SepPair>, enum vpsc::Dim>(), pybind11::arg("sp"), pybind11::arg("dim") );

		cl.def( pybind11::init( [](PyCallBack_dialect_SepPairSubConstraintInfo const &o){ return new PyCallBack_dialect_SepPairSubConstraintInfo(o); } ) );
		cl.def( pybind11::init( [](dialect::SepPairSubConstraintInfo const &o){ return new dialect::SepPairSubConstraintInfo(o); } ) );
		cl.def_readwrite("sp", &dialect::SepPairSubConstraintInfo::sp);
		cl.def_readwrite("dim", &dialect::SepPairSubConstraintInfo::dim);
		cl.def("assign", (struct dialect::SepPairSubConstraintInfo & (dialect::SepPairSubConstraintInfo::*)(const struct dialect::SepPairSubConstraintInfo &)) &dialect::SepPairSubConstraintInfo::operator=, "C++: dialect::SepPairSubConstraintInfo::operator=(const struct dialect::SepPairSubConstraintInfo &) --> struct dialect::SepPairSubConstraintInfo &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::SepMatrix file: line:185
		pybind11::class_<dialect::SepMatrix, std::shared_ptr<dialect::SepMatrix>, PyCallBack_dialect_SepMatrix, cola::CompoundConstraint> cl(M("dialect"), "SepMatrix", "");
		cl.def( pybind11::init<class dialect::Graph *>(), pybind11::arg("G") );

		cl.def( pybind11::init( [](PyCallBack_dialect_SepMatrix const &o){ return new PyCallBack_dialect_SepMatrix(o); } ) );
		cl.def( pybind11::init( [](dialect::SepMatrix const &o){ return new dialect::SepMatrix(o); } ) );
		cl.def("addSep", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double)) &dialect::SepMatrix::addSep, "Add a constraint.\n\n \n   The specified separation is /added/ to any existing constraints\n         between the two nodes. It overwrites anything with which it is\n         in conflict, but leaves everything else intact. For example, if\n         the second node was already constrained to lie UP and to the LEFT\n         of the first, and then a RIGHT sep is added, then the second node\n         will be constrained to lie UP and to the RIGHT of the first.\n\n \n   You cannot /remove/ a constraint using this method. If NONE is passed\n         as the SepType, nothing happens.\n\n \n  The ID of the first node.\n \n\n  The ID of the second node.\n \n\n  The gap type (centre-to-centre, or between opposing boundaries).\n \n\n  The direction of the separation from the first node\n                 to the second node.\n \n\n  The type of the separation.\n \n\n  The size of the separation.\n\nC++: dialect::SepMatrix::addSep(unsigned int, unsigned int, enum dialect::GapType, enum dialect::SepDir, enum dialect::SepType, double) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("gt"), pybind11::arg("sd"), pybind11::arg("st"), pybind11::arg("gap"));
		cl.def("setCardinalOP", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, enum dialect::CardinalDir)) &dialect::SepMatrix::setCardinalOP, "Convenience method, for setting that particular type of cardinal separation that merely\n         prevents overlap in the stated direction.\n \n\n SepMatrix::addSep\n\nC++: dialect::SepMatrix::setCardinalOP(unsigned int, unsigned int, enum dialect::CardinalDir) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("dir"));
		cl.def("addFixedRelativeSep", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, double, double)) &dialect::SepMatrix::addFixedRelativeSep, "Constrain two Nodes to sit at a fixed separation between their centre coordinates.\n\n \n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n \n\n   The desired fixed value for v.x - u.x (centre coordinates)\n \n\n   The desired fixed value for v.y - u.y (centre coordinates)\n\nC++: dialect::SepMatrix::addFixedRelativeSep(unsigned int, unsigned int, double, double) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("dx"), pybind11::arg("dy"));
		cl.def("addFixedRelativeSep", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::addFixedRelativeSep, "Constrain two Nodes to sit at their present exact separation.\n\n \n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n\nC++: dialect::SepMatrix::addFixedRelativeSep(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("hAlign", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::hAlign, "Align a pair of nodes horizontally.\n\nC++: dialect::SepMatrix::hAlign(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("vAlign", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::vAlign, "Align a pair of nodes vertically.\n\nC++: dialect::SepMatrix::vAlign(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("alignByEquatedCoord", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, enum vpsc::Dim)) &dialect::SepMatrix::alignByEquatedCoord, "Align a pair of nodes by saying which is the coordinate to be equated.\n \n\n  The ID of the first node, u.\n \n\n  The ID of the second node, v.\n \n\n  vpsc::Dim naming the coordinate to be equated. Thus XDIM means x-coords will\n                      be equated, giving a vertical alignment; YDIM means y-coords will be equated,\n                      giving a horizontal alignment.\n\nC++: dialect::SepMatrix::alignByEquatedCoord(unsigned int, unsigned int, enum vpsc::Dim) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("eqCoord"));
		cl.def("free", (void (dialect::SepMatrix::*)(unsigned int, unsigned int)) &dialect::SepMatrix::free, "Free a pair of Nodes; i.e. remove the SepPair for these Nodes\n         completely.\n\nC++: dialect::SepMatrix::free(unsigned int, unsigned int) --> void", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("clear", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::clear, "Clear all constraints.\n\n \n We do not destroy the SepPairs; we merely erase our pointers to them.\n\nC++: dialect::SepMatrix::clear() --> void");
		cl.def("setCorrespondingConstraints", (void (dialect::SepMatrix::*)(class dialect::SepMatrix &) const) &dialect::SepMatrix::setCorrespondingConstraints, "Set corresponding constraints in another SepMatrix.\n\n         This means that for each constraint between nodes of IDs id1 and id2 in this\n         SepMatrix, we set that constraint in the other SepMatrix if and only if its\n         underlying Graph contains Nodes of IDs id1 and id2.\n \n\n  The other SepMatrix.\n\nC++: dialect::SepMatrix::setCorrespondingConstraints(class dialect::SepMatrix &) const --> void", pybind11::arg("matrix"));
		cl.def("setSepPair", (void (dialect::SepMatrix::*)(unsigned int, unsigned int, class std::shared_ptr<struct dialect::SepPair>)) &dialect::SepMatrix::setSepPair, "Set a SepPair directly into another SepMatrix.\n \n\n  The primary ID under which the SepPair is to be stored.\n \n\n  The secondary ID under which the SepPair is to be stored.\n \n\n  The SepPair to be stored.\n \n\n  Runtime error if id1 >= id2.\n\nC++: dialect::SepMatrix::setSepPair(unsigned int, unsigned int, class std::shared_ptr<struct dialect::SepPair>) --> void", pybind11::arg("id1"), pybind11::arg("id2"), pybind11::arg("sp"));
		cl.def("transform", (void (dialect::SepMatrix::*)(enum dialect::SepTransform)) &dialect::SepMatrix::transform, "Apply a transformation to all Nodes.\n\nC++: dialect::SepMatrix::transform(enum dialect::SepTransform) --> void", pybind11::arg("tf"));
		cl.def("transformClosedSubset", (void (dialect::SepMatrix::*)(enum dialect::SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &)) &dialect::SepMatrix::transformClosedSubset, "Apply a transformation to a closed subset of all Nodes.\n\n \n  the transformation to be performed\n \n\n  the set of IDs of all Nodes to which the transformation\n                  should be applied. /Both/ Nodes must be in the set.\n \n\n transformOpenSubset\n\nC++: dialect::SepMatrix::transformClosedSubset(enum dialect::SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &) --> void", pybind11::arg("tf"), pybind11::arg("ids"));
		cl.def("transformOpenSubset", (void (dialect::SepMatrix::*)(enum dialect::SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &)) &dialect::SepMatrix::transformOpenSubset, "Apply a transformation to an open subset of all Nodes.\n\n \n  the transformation to be performed\n \n\n  the set of IDs of all Nodes to which the transformation\n                  should be applied. /At least one/ Node must be in the set.\n \n\n transformClosedSubset\n\nC++: dialect::SepMatrix::transformOpenSubset(enum dialect::SepTransform, const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &) --> void", pybind11::arg("tf"), pybind11::arg("ids"));
		cl.def("removeNode", (void (dialect::SepMatrix::*)(unsigned int)) &dialect::SepMatrix::removeNode, "Remove all records for the Node of given ID.\n\nC++: dialect::SepMatrix::removeNode(unsigned int) --> void", pybind11::arg("id"));
		cl.def("removeNodes", (void (dialect::SepMatrix::*)(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &)) &dialect::SepMatrix::removeNodes, "Remove all records for the given Nodes.\n\nC++: dialect::SepMatrix::removeNodes(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &) --> void", pybind11::arg("nodes"));
		cl.def("getCardinalDir", (enum dialect::CardinalDir (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::getCardinalDir, "Get the cardinal direction of the separation between two Nodes.\n \n\n  The ID of one of the Nodes.\n \n\n  The ID of the other Node.\n \n\n  Runtime exception if this separation is not cardinal.\n \n\n The cardinal direction.\n\nC++: dialect::SepMatrix::getCardinalDir(unsigned int, unsigned int) const --> enum dialect::CardinalDir", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("getAlignedSets", (void (dialect::SepMatrix::*)(class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &, class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &) const) &dialect::SepMatrix::getAlignedSets, "Determine which sets of nodes are aligned with one another.\n \n\n  Will be populated with a lookup from Node ID to set of IDs of\n                    all Nodes that are horizontally aligned with that one.\n \n\n  Like hSets, only for vertical alignment.\n\nC++: dialect::SepMatrix::getAlignedSets(class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &, class std::map<unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> >, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > > > > &) const --> void", pybind11::arg("hSets"), pybind11::arg("vSets"));
		cl.def("areHAligned", (bool (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::areHAligned, "Check whether two nodes are horizontally aligned.\n\nC++: dialect::SepMatrix::areHAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("areVAligned", (bool (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::areVAligned, "Check whether two nodes are vertically aligned.\n\nC++: dialect::SepMatrix::areVAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("writeTglf", (std::string (dialect::SepMatrix::*)(class std::map<unsigned int, unsigned int, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, unsigned int> > >) const) &dialect::SepMatrix::writeTglf, "Write a representation of all constraints in the format of\n         the SEPCO'S section of the TGLF file format.\n \n\n  Mapping from internal Node IDs to external IDs for the TGLF output.\n\nC++: dialect::SepMatrix::writeTglf(class std::map<unsigned int, unsigned int, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, unsigned int> > >) const --> std::string", pybind11::arg("id2ext"));
		cl.def("setGraph", (void (dialect::SepMatrix::*)(class dialect::Graph *)) &dialect::SepMatrix::setGraph, "Set the related Graph.\n\nC++: dialect::SepMatrix::setGraph(class dialect::Graph *) --> void", pybind11::arg("G"));
		cl.def("getGraph", (class dialect::Graph * (dialect::SepMatrix::*)()) &dialect::SepMatrix::getGraph, "Get the Graph.\n\nC++: dialect::SepMatrix::getGraph() --> class dialect::Graph *", pybind11::return_value_policy::automatic);
		cl.def("roundGapsUpward", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::roundGapsUpward, "Round gaps up to next largest integer. Useful if desiring to move all nodes to\n         integer coordaintes.\n\nC++: dialect::SepMatrix::roundGapsUpward() --> void");
		cl.def("setExtraBdryGap", (void (dialect::SepMatrix::*)(double)) &dialect::SepMatrix::setExtraBdryGap, "Set a global value to be added onto the gap value for all GapType::BDRY constraints.\n\nC++: dialect::SepMatrix::setExtraBdryGap(double) --> void", pybind11::arg("extraBdryGap"));
		cl.def("getExtraBdryGap", (double (dialect::SepMatrix::*)() const) &dialect::SepMatrix::getExtraBdryGap, "C++: dialect::SepMatrix::getExtraBdryGap() const --> double");
		cl.def("toString", (std::string (dialect::SepMatrix::*)() const) &dialect::SepMatrix::toString, "C++: dialect::SepMatrix::toString() const --> std::string");
		cl.def("markAllSubConstraintsAsInactive", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::markAllSubConstraintsAsInactive, "C++: dialect::SepMatrix::markAllSubConstraintsAsInactive() --> void");
		cl.def("assign", (class dialect::SepMatrix & (dialect::SepMatrix::*)(const class dialect::SepMatrix &)) &dialect::SepMatrix::operator=, "C++: dialect::SepMatrix::operator=(const class dialect::SepMatrix &) --> class dialect::SepMatrix &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
