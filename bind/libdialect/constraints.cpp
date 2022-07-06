#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/router.h>
#include <libcola/cluster.h>
#include <libcola/compound_constraints.h>
#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/opts.h>
#include <libdialect/ortho.h>
#include <libdialect/routing.h>
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

// dialect::SepPairSubConstraintInfo file:libdialect/constraints.h line:176
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

// dialect::SepMatrix file:libdialect/constraints.h line:185
struct PyCallBack_dialect_SepMatrix : public dialect::SepMatrix {
	using dialect::SepMatrix::SepMatrix;

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

void bind_libdialect_constraints(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::SepPairSubConstraintInfo file:libdialect/constraints.h line:176
		pybind11::class_<dialect::SepPairSubConstraintInfo, std::shared_ptr<dialect::SepPairSubConstraintInfo>, PyCallBack_dialect_SepPairSubConstraintInfo, cola::SubConstraintInfo> cl(M("dialect"), "SepPairSubConstraintInfo", "Since each SepPair may represent up to two VPSC constraints (one in each dimension), we need a simple wrapper\n struct to represent each dimension.");
		cl.def( pybind11::init( [](PyCallBack_dialect_SepPairSubConstraintInfo const &o){ return new PyCallBack_dialect_SepPairSubConstraintInfo(o); } ) );
		cl.def( pybind11::init( [](dialect::SepPairSubConstraintInfo const &o){ return new dialect::SepPairSubConstraintInfo(o); } ) );
		cl.def_readwrite("sp", &dialect::SepPairSubConstraintInfo::sp);
		cl.def_readwrite("dim", &dialect::SepPairSubConstraintInfo::dim);
		cl.def("assign", (struct dialect::SepPairSubConstraintInfo & (dialect::SepPairSubConstraintInfo::*)(const struct dialect::SepPairSubConstraintInfo &)) &dialect::SepPairSubConstraintInfo::operator=, "C++: dialect::SepPairSubConstraintInfo::operator=(const struct dialect::SepPairSubConstraintInfo &) --> struct dialect::SepPairSubConstraintInfo &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::SepMatrix file:libdialect/constraints.h line:185
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
		cl.def("transform", (void (dialect::SepMatrix::*)(enum dialect::SepTransform)) &dialect::SepMatrix::transform, "Apply a transformation to all Nodes.\n\nC++: dialect::SepMatrix::transform(enum dialect::SepTransform) --> void", pybind11::arg("tf"));
		cl.def("removeNode", (void (dialect::SepMatrix::*)(unsigned int)) &dialect::SepMatrix::removeNode, "Remove all records for the Node of given ID.\n\nC++: dialect::SepMatrix::removeNode(unsigned int) --> void", pybind11::arg("id"));
		cl.def("getCardinalDir", (enum dialect::CardinalDir (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::getCardinalDir, "Get the cardinal direction of the separation between two Nodes.\n \n\n  The ID of one of the Nodes.\n \n\n  The ID of the other Node.\n \n\n  Runtime exception if this separation is not cardinal.\n \n\n The cardinal direction.\n\nC++: dialect::SepMatrix::getCardinalDir(unsigned int, unsigned int) const --> enum dialect::CardinalDir", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("areHAligned", (bool (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::areHAligned, "Check whether two nodes are horizontally aligned.\n\nC++: dialect::SepMatrix::areHAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("areVAligned", (bool (dialect::SepMatrix::*)(unsigned int, unsigned int) const) &dialect::SepMatrix::areVAligned, "Check whether two nodes are vertically aligned.\n\nC++: dialect::SepMatrix::areVAligned(unsigned int, unsigned int) const --> bool", pybind11::arg("id1"), pybind11::arg("id2"));
		cl.def("setGraph", (void (dialect::SepMatrix::*)(class dialect::Graph *)) &dialect::SepMatrix::setGraph, "Set the related Graph.\n\nC++: dialect::SepMatrix::setGraph(class dialect::Graph *) --> void", pybind11::arg("G"));
		cl.def("getGraph", (class dialect::Graph * (dialect::SepMatrix::*)()) &dialect::SepMatrix::getGraph, "Get the Graph.\n\nC++: dialect::SepMatrix::getGraph() --> class dialect::Graph *", pybind11::return_value_policy::automatic);
		cl.def("roundGapsUpward", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::roundGapsUpward, "Round gaps up to next largest integer. Useful if desiring to move all nodes to\n         integer coordaintes.\n\nC++: dialect::SepMatrix::roundGapsUpward() --> void");
		cl.def("setExtraBdryGap", (void (dialect::SepMatrix::*)(double)) &dialect::SepMatrix::setExtraBdryGap, "Set a global value to be added onto the gap value for all GapType::BDRY constraints.\n\nC++: dialect::SepMatrix::setExtraBdryGap(double) --> void", pybind11::arg("extraBdryGap"));
		cl.def("getExtraBdryGap", (double (dialect::SepMatrix::*)() const) &dialect::SepMatrix::getExtraBdryGap, "C++: dialect::SepMatrix::getExtraBdryGap() const --> double");
		cl.def("markAllSubConstraintsAsInactive", (void (dialect::SepMatrix::*)()) &dialect::SepMatrix::markAllSubConstraintsAsInactive, "C++: dialect::SepMatrix::markAllSubConstraintsAsInactive() --> void");
		cl.def("assign", (class dialect::SepMatrix & (dialect::SepMatrix::*)(const class dialect::SepMatrix &)) &dialect::SepMatrix::operator=, "C++: dialect::SepMatrix::operator=(const class dialect::SepMatrix &) --> class dialect::SepMatrix &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::SepCo file:libdialect/constraints.h line:422
		pybind11::class_<dialect::SepCo, std::shared_ptr<dialect::SepCo>> cl(M("dialect"), "SepCo", "Simple struct to represent separation constraints in one dimension, in terms\n of Nodes (rather than Rectangle indices).\n\n Also supports separation constraints with negative gaps (unlike VPSC).\n Such constraints are perhaps better called \"containment constraints\". To illustrate,\n in the figure below\n\n             ---\n            | a |  ------|\n             ---         |\n                         |\n             ---         |\n            | b |        |\n             ---         |\n\n the separation constraint b.x - 100 <= a.x might mean that node b is constrained to\n stay to the left of the dashed line (which moves with node a).");
		cl.def( pybind11::init( [](dialect::SepCo const &o){ return new dialect::SepCo(o); } ) );
		cl.def_readwrite("dim", &dialect::SepCo::dim);
		cl.def_readwrite("left", &dialect::SepCo::left);
		cl.def_readwrite("right", &dialect::SepCo::right);
		cl.def_readwrite("gap", &dialect::SepCo::gap);
		cl.def_readwrite("exact", &dialect::SepCo::exact);
		cl.def("addToMatrix", (void (dialect::SepCo::*)(class dialect::SepMatrix &) const) &dialect::SepCo::addToMatrix, "Add this constraint to a SepMatrix.\n\nC++: dialect::SepCo::addToMatrix(class dialect::SepMatrix &) const --> void", pybind11::arg("matrix"));
		cl.def("violation", (double (dialect::SepCo::*)() const) &dialect::SepCo::violation, "Determine the extent to which this separation constraint is currently violated.\n\nC++: dialect::SepCo::violation() const --> double");
	}
	{ // dialect::Projection file:libdialect/constraints.h line:466
		pybind11::class_<dialect::Projection, std::shared_ptr<dialect::Projection>> cl(M("dialect"), "Projection", "A Projection represents a set of constraints (given by SepCos), together\n with a dimension in which to project.");
		cl.def( pybind11::init( [](dialect::Projection const &o){ return new dialect::Projection(o); } ) );
		cl.def_readwrite("sepCoSet", &dialect::Projection::sepCoSet);
		cl.def_readwrite("dim", &dialect::Projection::dim);
		cl.def("size", (unsigned long (dialect::Projection::*)()) &dialect::Projection::size, "Check how many SepCos are in the projection.\n\nC++: dialect::Projection::size() --> unsigned long");
	}
	{ // dialect::ProjSeq file:libdialect/constraints.h line:492
		pybind11::class_<dialect::ProjSeq, std::shared_ptr<dialect::ProjSeq>> cl(M("dialect"), "ProjSeq", "Projection Sequence. Manages a sequence of VPSC projections onto a monotonially\n increasing set of separation constraints.");
		cl.def( pybind11::init( [](){ return new dialect::ProjSeq(); } ) );
		cl.def( pybind11::init( [](dialect::ProjSeq const &o){ return new dialect::ProjSeq(o); } ) );
		cl.def("noteStresschange", (void (dialect::ProjSeq::*)(double)) &dialect::ProjSeq::noteStresschange, "Note a stress change.\n\nC++: dialect::ProjSeq::noteStresschange(double) --> void", pybind11::arg("dS"));
		cl.def("__iadd__", (class dialect::ProjSeq & (dialect::ProjSeq::*)(const class dialect::ProjSeq &)) &dialect::ProjSeq::operator+=, "When another ProjSeq is added to this one, we simply add each\n         Projection from the other one to this one, as usual. Thus is\n         monotonicity maintained, and this ProjSeq's pointer is left in place.\n\nC++: dialect::ProjSeq::operator+=(const class dialect::ProjSeq &) --> class dialect::ProjSeq &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"));
		cl.def("reset", (void (dialect::ProjSeq::*)()) &dialect::ProjSeq::reset, "Reset to start of sequence.\n\nC++: dialect::ProjSeq::reset() --> void");
		cl.def("violation", (double (dialect::ProjSeq::*)() const) &dialect::ProjSeq::violation, "Sum the violations of all SepCos in the final sets.\n\nC++: dialect::ProjSeq::violation() const --> double");
	}
	// dialect::AspectRatioClass file:libdialect/opts.h line:32
	pybind11::enum_<dialect::AspectRatioClass>(M("dialect"), "AspectRatioClass", "")
		.value("NONE", dialect::AspectRatioClass::NONE)
		.value("PORTRAIT", dialect::AspectRatioClass::PORTRAIT)
		.value("LANDSCAPE", dialect::AspectRatioClass::LANDSCAPE);

;

	// dialect::TreeRoutingType file:libdialect/opts.h line:50
	pybind11::enum_<dialect::TreeRoutingType>(M("dialect"), "TreeRoutingType", "When routing connectors for Trees, the set of allowed connection directions\n depends on the application.\n\n In, for example, a NORTH-growing tree, an edge between ranks i and i + 1\n will always be allowed to connect only to the south (S) port of a node in\n rank i + 1.\n\n The TreeRoutingType controls the directions allowed for connection to nodes in\n rank i, as follows:\n\n STRICT:  only N is allowed.\n CORE_ATTACHMENT:  N, E, W are allowed for the root node if it has exactly one child and\n                   is transversely displaced from its one child; otherwise only N.\n MONOTONIC:  N, E, W are allowed for all nodes on rank i.")
		.value("STRICT", dialect::TreeRoutingType::STRICT)
		.value("CORE_ATTACHMENT", dialect::TreeRoutingType::CORE_ATTACHMENT)
		.value("MONOTONIC", dialect::TreeRoutingType::MONOTONIC);

;

	// dialect::ExpansionEstimateMethod file:libdialect/opts.h line:62
	pybind11::enum_<dialect::ExpansionEstimateMethod>(M("dialect"), "ExpansionEstimateMethod", "When expanding faces in order to make room to place the trees, there are different\n ways to estimate which is the best dimension in which to operate first.\n\n SPACE: Look at the available space in each dimension.\n CONSTRAINTS: Compute the separation constraints you would use in each dimension, and\n              sum their violations.")
		.value("SPACE", dialect::ExpansionEstimateMethod::SPACE)
		.value("CONSTRAINTS", dialect::ExpansionEstimateMethod::CONSTRAINTS);

;

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
}
