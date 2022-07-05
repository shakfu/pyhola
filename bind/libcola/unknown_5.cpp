#include <_stdio.h>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <string_view>
#include <utility>
#include <valarray>
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

// cola::SubConstraintInfo file: line:116
struct PyCallBack_cola_SubConstraintInfo : public cola::SubConstraintInfo {
	using cola::SubConstraintInfo::SubConstraintInfo;

	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::SubConstraintInfo *>(this), "updateVarIDsWithMapping");
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

// cola::BoundaryConstraint file: line:288
struct PyCallBack_cola_BoundaryConstraint : public cola::BoundaryConstraint {
	using cola::BoundaryConstraint::BoundaryConstraint;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::BoundaryConstraint *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return BoundaryConstraint::toString();
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::BoundaryConstraint *>(this), "updatePosition");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return BoundaryConstraint::updatePosition(a0);
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::BoundaryConstraint *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return BoundaryConstraint::printCreationCode(a0);
	}
	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::BoundaryConstraint *>(this), "updateVarIDsWithMapping");
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
	void markAllSubConstraintsAsInactive() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::BoundaryConstraint *>(this), "markAllSubConstraintsAsInactive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::markAllSubConstraintsAsInactive();
	}
	bool subConstraintsRemaining() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::BoundaryConstraint *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::BoundaryConstraint *>(this), "markCurrSubConstraintAsActive");
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
};

// cola::AlignmentConstraint file: line:345
struct PyCallBack_cola_AlignmentConstraint : public cola::AlignmentConstraint {
	using cola::AlignmentConstraint::AlignmentConstraint;

	std::string toString() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::AlignmentConstraint *>(this), "toString");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return AlignmentConstraint::toString();
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::AlignmentConstraint *>(this), "updatePosition");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return AlignmentConstraint::updatePosition(a0);
	}
	void printCreationCode(struct __sFILE * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::AlignmentConstraint *>(this), "printCreationCode");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return AlignmentConstraint::printCreationCode(a0);
	}
	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::AlignmentConstraint *>(this), "updateVarIDsWithMapping");
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
	void markAllSubConstraintsAsInactive() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::AlignmentConstraint *>(this), "markAllSubConstraintsAsInactive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::markAllSubConstraintsAsInactive();
	}
	bool subConstraintsRemaining() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::AlignmentConstraint *>(this), "subConstraintsRemaining");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::AlignmentConstraint *>(this), "markCurrSubConstraintAsActive");
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
};

void bind_unknown_unknown_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::SparseMap file: line:42
		pybind11::class_<cola::SparseMap, std::shared_ptr<cola::SparseMap>> cl(M("cola"), "SparseMap", "");
		cl.def( pybind11::init( [](){ return new cola::SparseMap(); } ), "doc" );
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("n") );

		cl.def( pybind11::init( [](cola::SparseMap const &o){ return new cola::SparseMap(o); } ) );
		cl.def_readwrite("n", &cola::SparseMap::n);
		cl.def_readwrite("lookup", &cola::SparseMap::lookup);
		cl.def("__getitem__", (double & (cola::SparseMap::*)(const struct std::pair<unsigned int, unsigned int> &)) &cola::SparseMap::operator[], "C++: cola::SparseMap::operator[](const struct std::pair<unsigned int, unsigned int> &) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("k"));
		cl.def("__call__", (double & (cola::SparseMap::*)(const unsigned int, const unsigned int)) &cola::SparseMap::operator(), "C++: cola::SparseMap::operator()(const unsigned int, const unsigned int) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("i"), pybind11::arg("j"));
		cl.def("getIJ", (double (cola::SparseMap::*)(const unsigned int, const unsigned int) const) &cola::SparseMap::getIJ, "C++: cola::SparseMap::getIJ(const unsigned int, const unsigned int) const --> double", pybind11::arg("i"), pybind11::arg("j"));
		cl.def("nonZeroCount", (unsigned long (cola::SparseMap::*)() const) &cola::SparseMap::nonZeroCount, "C++: cola::SparseMap::nonZeroCount() const --> unsigned long");
		cl.def("resize", (void (cola::SparseMap::*)(unsigned int)) &cola::SparseMap::resize, "C++: cola::SparseMap::resize(unsigned int) --> void", pybind11::arg("n"));
		cl.def("clear", (void (cola::SparseMap::*)()) &cola::SparseMap::clear, "C++: cola::SparseMap::clear() --> void");
	}
	{ // cola::SparseMatrix file: line:84
		pybind11::class_<cola::SparseMatrix, std::shared_ptr<cola::SparseMatrix>> cl(M("cola"), "SparseMatrix", "");
		cl.def( pybind11::init<const struct cola::SparseMap &>(), pybind11::arg("m") );

		cl.def( pybind11::init( [](cola::SparseMatrix const &o){ return new cola::SparseMatrix(o); } ) );
		cl.def("rightMultiply", (void (cola::SparseMatrix::*)(const class std::valarray<double> &, class std::valarray<double> &) const) &cola::SparseMatrix::rightMultiply, "C++: cola::SparseMatrix::rightMultiply(const class std::valarray<double> &, class std::valarray<double> &) const --> void", pybind11::arg("v"), pybind11::arg("r"));
		cl.def("getIJ", (double (cola::SparseMatrix::*)(const unsigned int, const unsigned int) const) &cola::SparseMatrix::getIJ, "C++: cola::SparseMatrix::getIJ(const unsigned int, const unsigned int) const --> double", pybind11::arg("i"), pybind11::arg("j"));
		cl.def("print", (void (cola::SparseMatrix::*)() const) &cola::SparseMatrix::print, "C++: cola::SparseMatrix::print() const --> void");
		cl.def("rowSize", (unsigned int (cola::SparseMatrix::*)() const) &cola::SparseMatrix::rowSize, "C++: cola::SparseMatrix::rowSize() const --> unsigned int");
	}
	{ // cola::SubConstraint file: line:51
		pybind11::class_<cola::SubConstraint, std::shared_ptr<cola::SubConstraint>> cl(M("cola"), "SubConstraint", "");
		cl.def( pybind11::init( [](enum vpsc::Dim const & a0, class vpsc::Constraint const & a1){ return new cola::SubConstraint(a0, a1); } ), "doc" , pybind11::arg("dim"), pybind11::arg("constraint"));
		cl.def( pybind11::init<enum vpsc::Dim, class vpsc::Constraint, double>(), pybind11::arg("dim"), pybind11::arg("constraint"), pybind11::arg("cost") );

		cl.def( pybind11::init( [](cola::SubConstraint const &o){ return new cola::SubConstraint(o); } ) );
		cl.def_readwrite("dim", &cola::SubConstraint::dim);
		cl.def_readwrite("constraint", &cola::SubConstraint::constraint);
		cl.def_readwrite("cost", &cola::SubConstraint::cost);
	}
	{ // cola::VariableIDMap file: line:93
		pybind11::class_<cola::VariableIDMap, std::shared_ptr<cola::VariableIDMap>> cl(M("cola"), "VariableIDMap", "Holds a mapping between two sets of Variable indices.\n\n This can be used to rewrite the Rectangles to which a set of \n CompoundConstraints apply to.  This is useful when creating another\n instance of the problem, but using the same CompoundConstraints list.\n You should not usually need to use this yourself.  It is utilised by \n addons such as topology::AvoidTopologyAddon.\n\n If a mapping for a particular value is not set, it is considered to be\n equal on both sides of the mapping.");
		cl.def( pybind11::init( [](){ return new cola::VariableIDMap(); } ) );
		cl.def( pybind11::init( [](cola::VariableIDMap const &o){ return new cola::VariableIDMap(o); } ) );
		cl.def("addMappingForVariable", (bool (cola::VariableIDMap::*)(const unsigned int, const unsigned int)) &cola::VariableIDMap::addMappingForVariable, "Adds a mapping between a pair of variables.\n\n \n  The variable index to map from.\n \n\n    The variable index to map to.\n \n\n          True if the mapping was successfully added.\n\nC++: cola::VariableIDMap::addMappingForVariable(const unsigned int, const unsigned int) --> bool", pybind11::arg("from"), pybind11::arg("to"));
		cl.def("mappingForVariable", [](cola::VariableIDMap const &o, const unsigned int & a0) -> unsigned int { return o.mappingForVariable(a0); }, "", pybind11::arg("var"));
		cl.def("mappingForVariable", (unsigned int (cola::VariableIDMap::*)(const unsigned int, bool) const) &cola::VariableIDMap::mappingForVariable, "C++: cola::VariableIDMap::mappingForVariable(const unsigned int, bool) const --> unsigned int", pybind11::arg("var"), pybind11::arg("forward"));
		cl.def("clear", (void (cola::VariableIDMap::*)()) &cola::VariableIDMap::clear, "C++: cola::VariableIDMap::clear() --> void");
		cl.def("printCreationCode", (void (cola::VariableIDMap::*)(struct __sFILE *) const) &cola::VariableIDMap::printCreationCode, "C++: cola::VariableIDMap::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::VariableIDMap & (cola::VariableIDMap::*)(const class cola::VariableIDMap &)) &cola::VariableIDMap::operator=, "C++: cola::VariableIDMap::operator=(const class cola::VariableIDMap &) --> class cola::VariableIDMap &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::SubConstraintInfo file: line:116
		pybind11::class_<cola::SubConstraintInfo, std::shared_ptr<cola::SubConstraintInfo>, PyCallBack_cola_SubConstraintInfo> cl(M("cola"), "SubConstraintInfo", "");
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("ind") );

		cl.def( pybind11::init( [](PyCallBack_cola_SubConstraintInfo const &o){ return new PyCallBack_cola_SubConstraintInfo(o); } ) );
		cl.def( pybind11::init( [](cola::SubConstraintInfo const &o){ return new cola::SubConstraintInfo(o); } ) );
		cl.def_readwrite("varIndex", &cola::SubConstraintInfo::varIndex);
		cl.def_readwrite("satisfied", &cola::SubConstraintInfo::satisfied);
		cl.def("updateVarIDsWithMapping", (void (cola::SubConstraintInfo::*)(const class cola::VariableIDMap &, bool)) &cola::SubConstraintInfo::updateVarIDsWithMapping, "C++: cola::SubConstraintInfo::updateVarIDsWithMapping(const class cola::VariableIDMap &, bool) --> void", pybind11::arg("idMap"), pybind11::arg("forward"));
		cl.def("assign", (class cola::SubConstraintInfo & (cola::SubConstraintInfo::*)(const class cola::SubConstraintInfo &)) &cola::SubConstraintInfo::operator=, "C++: cola::SubConstraintInfo::operator=(const class cola::SubConstraintInfo &) --> class cola::SubConstraintInfo &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::CompoundConstraint file: line:146
		pybind11::class_<cola::CompoundConstraint, std::shared_ptr<cola::CompoundConstraint>> cl(M("cola"), "CompoundConstraint", "An abstract base class for all high-level compound constraints.\n\n A compound constraint is a conceptual, diagramming application oriented\n type of constraint, which can be translated into a set of simple\n separation constraints, possibly extra dummy variables, and perhaps\n even some extra terms for the quadratic objective function used\n in the gradient projection solver.");
		cl.def("updatePosition", (void (cola::CompoundConstraint::*)(const enum vpsc::Dim)) &cola::CompoundConstraint::updatePosition, "Implemented by the compound constraint to send position\n        information back to the interface.\n\n This will be called for each compound constraint once the VPSC \n instance is solved to allow them to pass information such as \n variable values back to the graphical user interface.\n\n \n   The current active dimension.\n\nC++: cola::CompoundConstraint::updatePosition(const enum vpsc::Dim) --> void", pybind11::arg("dim"));
		cl.def("toString", (std::string (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::CompoundConstraint::toString() const --> std::string");
		cl.def("dimension", (enum vpsc::Dim (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::dimension, "C++: cola::CompoundConstraint::dimension() const --> enum vpsc::Dim");
		cl.def("priority", (unsigned int (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::priority, "C++: cola::CompoundConstraint::priority() const --> unsigned int");
		cl.def("updateVarIDsWithMapping", [](cola::CompoundConstraint &o, const class cola::VariableIDMap & a0) -> void { return o.updateVarIDsWithMapping(a0); }, "", pybind11::arg("idMap"));
		cl.def("updateVarIDsWithMapping", (void (cola::CompoundConstraint::*)(const class cola::VariableIDMap &, bool)) &cola::CompoundConstraint::updateVarIDsWithMapping, "C++: cola::CompoundConstraint::updateVarIDsWithMapping(const class cola::VariableIDMap &, bool) --> void", pybind11::arg("idMap"), pybind11::arg("forward"));
		cl.def("markAllSubConstraintsAsInactive", (void (cola::CompoundConstraint::*)()) &cola::CompoundConstraint::markAllSubConstraintsAsInactive, "C++: cola::CompoundConstraint::markAllSubConstraintsAsInactive() --> void");
		cl.def("subConstraintsRemaining", (bool (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::subConstraintsRemaining, "C++: cola::CompoundConstraint::subConstraintsRemaining() const --> bool");
		cl.def("markCurrSubConstraintAsActive", (void (cola::CompoundConstraint::*)(const bool)) &cola::CompoundConstraint::markCurrSubConstraintAsActive, "C++: cola::CompoundConstraint::markCurrSubConstraintAsActive(const bool) --> void", pybind11::arg("satisfiable"));
		cl.def("printCreationCode", (void (cola::CompoundConstraint::*)(struct __sFILE *) const) &cola::CompoundConstraint::printCreationCode, "C++: cola::CompoundConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("shouldCombineSubConstraints", (bool (cola::CompoundConstraint::*)() const) &cola::CompoundConstraint::shouldCombineSubConstraints, "C++: cola::CompoundConstraint::shouldCombineSubConstraints() const --> bool");
		cl.def("assign", (class cola::CompoundConstraint & (cola::CompoundConstraint::*)(const class cola::CompoundConstraint &)) &cola::CompoundConstraint::operator=, "C++: cola::CompoundConstraint::operator=(const class cola::CompoundConstraint &) --> class cola::CompoundConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::BoundaryConstraint file: line:288
		pybind11::class_<cola::BoundaryConstraint, std::shared_ptr<cola::BoundaryConstraint>, PyCallBack_cola_BoundaryConstraint, cola::CompoundConstraint> cl(M("cola"), "BoundaryConstraint", "A boundary constraint specifies a bounding line that a set of nodes \n        must be either to the left or right of.\n\n A boundary constraint gives a bounding line in a particular dimension (with\n position stored in a variable) and a set of nodes required to be to the left\n of that line and nodes required to be to the right of the line.  Separations\n are determined by offsets passed to addShape().");
		cl.def( pybind11::init<const enum vpsc::Dim>(), pybind11::arg("dim") );

		cl.def( pybind11::init( [](PyCallBack_cola_BoundaryConstraint const &o){ return new PyCallBack_cola_BoundaryConstraint(o); } ) );
		cl.def( pybind11::init( [](cola::BoundaryConstraint const &o){ return new cola::BoundaryConstraint(o); } ) );
		cl.def_readwrite("position", &cola::BoundaryConstraint::position);
		cl.def("addShape", (void (cola::BoundaryConstraint::*)(const unsigned int, const double)) &cola::BoundaryConstraint::addShape, "Mark a node as being part of this boundary constraint.\n\n \n   The index of the node in the Rectangles vector.\n \n\n  The minimum amount to separate the node from the\n                    boundary line.  Negative if left-of, positive if \n                    right-of.  Will usually be equal to half a node's\n                    size plus a buffer amount.\n\nC++: cola::BoundaryConstraint::addShape(const unsigned int, const double) --> void", pybind11::arg("index"), pybind11::arg("offset"));
		cl.def("toString", (std::string (cola::BoundaryConstraint::*)() const) &cola::BoundaryConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::BoundaryConstraint::toString() const --> std::string");
		cl.def("updatePosition", (void (cola::BoundaryConstraint::*)(const enum vpsc::Dim)) &cola::BoundaryConstraint::updatePosition, "C++: cola::BoundaryConstraint::updatePosition(const enum vpsc::Dim) --> void", pybind11::arg("dim"));
		cl.def("printCreationCode", (void (cola::BoundaryConstraint::*)(struct __sFILE *) const) &cola::BoundaryConstraint::printCreationCode, "C++: cola::BoundaryConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::BoundaryConstraint & (cola::BoundaryConstraint::*)(const class cola::BoundaryConstraint &)) &cola::BoundaryConstraint::operator=, "C++: cola::BoundaryConstraint::operator=(const class cola::BoundaryConstraint &) --> class cola::BoundaryConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::AlignmentConstraint file: line:345
		pybind11::class_<cola::AlignmentConstraint, std::shared_ptr<cola::AlignmentConstraint>, PyCallBack_cola_AlignmentConstraint, cola::CompoundConstraint> cl(M("cola"), "AlignmentConstraint", "An alignment constraint specifies a alignment line that a set of\n        nodes must be constrained to by an exact amount.\n\n This is represented as a variable representing the position of a vertical \n or horizontal and a then group of nodes and offsets for those nodes such \n that the nodes must be spaced exactly at those offsets from the alignment\n position.\n\n Optionally, the alignment may be given a suggested position and/or marked \n as \"fixed\".  When fixed, the position variable will be given a higher \n weight to attempt to keep it at that position.");
		cl.def( pybind11::init( [](const enum vpsc::Dim & a0){ return new cola::AlignmentConstraint(a0); }, [](const enum vpsc::Dim & a0){ return new PyCallBack_cola_AlignmentConstraint(a0); } ), "doc");
		cl.def( pybind11::init<const enum vpsc::Dim, double>(), pybind11::arg("dim"), pybind11::arg("position") );

		cl.def( pybind11::init( [](PyCallBack_cola_AlignmentConstraint const &o){ return new PyCallBack_cola_AlignmentConstraint(o); } ) );
		cl.def( pybind11::init( [](cola::AlignmentConstraint const &o){ return new cola::AlignmentConstraint(o); } ) );
		cl.def("addShape", (void (cola::AlignmentConstraint::*)(const unsigned int, const double)) &cola::AlignmentConstraint::addShape, "Mark a node as being part of this alignment constraint.\n\n \n   The index of the node in the Rectangles vector.\n \n\n  The exact amount to separate the node from the\n                    alignment line.  Negative if left-of, positive if \n                    right-of.  Will usually be equal to half a node's\n                    size if aligning to the side of a node, or zero\n                    if aligning with the centre of a node.\n\nC++: cola::AlignmentConstraint::addShape(const unsigned int, const double) --> void", pybind11::arg("index"), pybind11::arg("offset"));
		cl.def("fixPos", (void (cola::AlignmentConstraint::*)(double)) &cola::AlignmentConstraint::fixPos, "Mark the alignment as ideally having a fixed position.\n\n This causes the position variable for the alignment to be given\n the ideal position pos and a higher weight.\n\n \n  The ideal position value for the alignment.\n\nC++: cola::AlignmentConstraint::fixPos(double) --> void", pybind11::arg("pos"));
		cl.def("unfixPos", (void (cola::AlignmentConstraint::*)()) &cola::AlignmentConstraint::unfixPos, "Mark the alignment as not having a fixed position.\n\n This is the default.\n\nC++: cola::AlignmentConstraint::unfixPos() --> void");
		cl.def("isFixed", (bool (cola::AlignmentConstraint::*)() const) &cola::AlignmentConstraint::isFixed, "Indicates if the alignment position is marked as fixed.\n\n \n True if the alignment position is marked as fixed, or \n          false otherwise.\n\nC++: cola::AlignmentConstraint::isFixed() const --> bool");
		cl.def("toString", (std::string (cola::AlignmentConstraint::*)() const) &cola::AlignmentConstraint::toString, "Returns a textual description of the compound constraint.\n\n  \n     A string describing the compound constraint.\n\nC++: cola::AlignmentConstraint::toString() const --> std::string");
		cl.def("updatePosition", (void (cola::AlignmentConstraint::*)(const enum vpsc::Dim)) &cola::AlignmentConstraint::updatePosition, "C++: cola::AlignmentConstraint::updatePosition(const enum vpsc::Dim) --> void", pybind11::arg("dim"));
		cl.def("position", (double (cola::AlignmentConstraint::*)() const) &cola::AlignmentConstraint::position, "C++: cola::AlignmentConstraint::position() const --> double");
		cl.def("printCreationCode", (void (cola::AlignmentConstraint::*)(struct __sFILE *) const) &cola::AlignmentConstraint::printCreationCode, "C++: cola::AlignmentConstraint::printCreationCode(struct __sFILE *) const --> void", pybind11::arg("fp"));
		cl.def("assign", (class cola::AlignmentConstraint & (cola::AlignmentConstraint::*)(const class cola::AlignmentConstraint &)) &cola::AlignmentConstraint::operator=, "C++: cola::AlignmentConstraint::operator=(const class cola::AlignmentConstraint &) --> class cola::AlignmentConstraint &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
