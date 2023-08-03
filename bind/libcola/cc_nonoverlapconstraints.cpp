#include <libcola/box.h>
#include <libcola/cc_nonoverlapconstraints.h>
#include <libcola/cluster.h>
#include <libcola/cola_log.h>
#include <libcola/compound_constraints.h>
#include <libcola/connected_components.h>
#include <libcola/shapepair.h>
#include <libvpsc/rectangle.h>
#include <memory>
#include <sstream> // __str__
#include <string>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// cola::OverlapShapeOffsets file:libcola/cc_nonoverlapconstraints.h line:40
struct PyCallBack_cola_OverlapShapeOffsets : public cola::OverlapShapeOffsets {
	using cola::OverlapShapeOffsets::OverlapShapeOffsets;

	void updateVarIDsWithMapping(const class cola::VariableIDMap & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::OverlapShapeOffsets *>(this), "updateVarIDsWithMapping");
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

// cola::NonOverlapConstraints file:libcola/cc_nonoverlapconstraints.h line:136
struct PyCallBack_cola_NonOverlapConstraints : public cola::NonOverlapConstraints {
	using cola::NonOverlapConstraints::NonOverlapConstraints;

	void markCurrSubConstraintAsActive(const bool a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "markCurrSubConstraintAsActive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return NonOverlapConstraints::markCurrSubConstraintAsActive(a0);
	}
	void markAllSubConstraintsAsInactive() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "markAllSubConstraintsAsInactive");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return NonOverlapConstraints::markAllSubConstraintsAsInactive();
	}
	bool subConstraintsRemaining() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "subConstraintsRemaining");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return NonOverlapConstraints::subConstraintsRemaining();
	}
	void generateVariables(const enum vpsc::Dim a0, int & a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "generateVariables");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return NonOverlapConstraints::generateVariables(a0, a1);
	}
	void generateSeparationConstraints(const enum vpsc::Dim a0, int & a1, int & a2, int & a3) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "generateSeparationConstraints");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2, a3);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"CompoundConstraint::generateSeparationConstraints\"");
	}
	void updatePosition(const enum vpsc::Dim a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "updatePosition");
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
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "updateVarIDsWithMapping");
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
	void updateShapeOffsetsForDifferentCentres(const int & a0, bool a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "updateShapeOffsetsForDifferentCentres");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CompoundConstraint::updateShapeOffsetsForDifferentCentres(a0, a1);
	}
	void printCreationCode(int * a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const cola::NonOverlapConstraints *>(this), "printCreationCode");
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

void bind_libcola_cc_nonoverlapconstraints(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // cola::OverlapShapeOffsets file:libcola/cc_nonoverlapconstraints.h line:40
		pybind11::class_<cola::OverlapShapeOffsets, std::shared_ptr<cola::OverlapShapeOffsets>, PyCallBack_cola_OverlapShapeOffsets, cola::SubConstraintInfo> cl(M("cola"), "OverlapShapeOffsets", "");
		cl.def( pybind11::init<unsigned int, double, double, unsigned int>(), pybind11::arg("ind"), pybind11::arg("xOffset"), pybind11::arg("yOffset"), pybind11::arg("group") );

		cl.def( pybind11::init<unsigned int, class cola::Cluster *, unsigned int>(), pybind11::arg("ind"), pybind11::arg("cluster"), pybind11::arg("group") );

		cl.def( pybind11::init( [](){ return new cola::OverlapShapeOffsets(); }, [](){ return new PyCallBack_cola_OverlapShapeOffsets(); } ) );
		cl.def( pybind11::init( [](PyCallBack_cola_OverlapShapeOffsets const &o){ return new PyCallBack_cola_OverlapShapeOffsets(o); } ) );
		cl.def( pybind11::init( [](cola::OverlapShapeOffsets const &o){ return new cola::OverlapShapeOffsets(o); } ) );
		cl.def_readwrite("rectPadding", &cola::OverlapShapeOffsets::rectPadding);
		cl.def_readwrite("group", &cola::OverlapShapeOffsets::group);
		cl.def("usesClusterBounds", (bool (cola::OverlapShapeOffsets::*)() const) &cola::OverlapShapeOffsets::usesClusterBounds, "C++: cola::OverlapShapeOffsets::usesClusterBounds() const --> bool");
		cl.def("resize", (void (cola::OverlapShapeOffsets::*)(double, double)) &cola::OverlapShapeOffsets::resize, "C++: cola::OverlapShapeOffsets::resize(double, double) --> void", pybind11::arg("xOffset"), pybind11::arg("yOffset"));
		cl.def("assign", (class cola::OverlapShapeOffsets & (cola::OverlapShapeOffsets::*)(const class cola::OverlapShapeOffsets &)) &cola::OverlapShapeOffsets::operator=, "C++: cola::OverlapShapeOffsets::operator=(const class cola::OverlapShapeOffsets &) --> class cola::OverlapShapeOffsets &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // cola::ShapePairInfo file:libcola/cc_nonoverlapconstraints.h line:84
		pybind11::class_<cola::ShapePairInfo, std::shared_ptr<cola::ShapePairInfo>> cl(M("cola"), "ShapePairInfo", "");
		cl.def( pybind11::init( [](unsigned int const & a0, unsigned int const & a1){ return new cola::ShapePairInfo(a0, a1); } ), "doc" , pybind11::arg("ind1"), pybind11::arg("ind2"));
		cl.def( pybind11::init<unsigned int, unsigned int, unsigned int>(), pybind11::arg("ind1"), pybind11::arg("ind2"), pybind11::arg("ord") );

		cl.def_readwrite("order", &cola::ShapePairInfo::order);
		cl.def_readwrite("varIndex1", &cola::ShapePairInfo::varIndex1);
		cl.def_readwrite("varIndex2", &cola::ShapePairInfo::varIndex2);
		cl.def_readwrite("satisfied", &cola::ShapePairInfo::satisfied);
		cl.def_readwrite("processed", &cola::ShapePairInfo::processed);
		cl.def_readwrite("overlapMax", &cola::ShapePairInfo::overlapMax);
	}
	{ // cola::NonOverlapConstraintExemptions file:libcola/cc_nonoverlapconstraints.h line:124
		pybind11::class_<cola::NonOverlapConstraintExemptions, std::shared_ptr<cola::NonOverlapConstraintExemptions>> cl(M("cola"), "NonOverlapConstraintExemptions", "");
		cl.def( pybind11::init( [](){ return new cola::NonOverlapConstraintExemptions(); } ) );
		cl.def("addExemptGroupOfNodes", (void (cola::NonOverlapConstraintExemptions::*)(int)) &cola::NonOverlapConstraintExemptions::addExemptGroupOfNodes, "C++: cola::NonOverlapConstraintExemptions::addExemptGroupOfNodes(int) --> void", pybind11::arg("listOfNodeGroups"));
		cl.def("shapePairIsExempt", (bool (cola::NonOverlapConstraintExemptions::*)(class cola::ShapePair) const) &cola::NonOverlapConstraintExemptions::shapePairIsExempt, "C++: cola::NonOverlapConstraintExemptions::shapePairIsExempt(class cola::ShapePair) const --> bool", pybind11::arg("shapePair"));
		cl.def("getExemptPairs", (int (cola::NonOverlapConstraintExemptions::*)()) &cola::NonOverlapConstraintExemptions::getExemptPairs, "C++: cola::NonOverlapConstraintExemptions::getExemptPairs() --> int");
	}
	{ // cola::NonOverlapConstraints file:libcola/cc_nonoverlapconstraints.h line:136
		pybind11::class_<cola::NonOverlapConstraints, std::shared_ptr<cola::NonOverlapConstraints>, PyCallBack_cola_NonOverlapConstraints, cola::CompoundConstraint> cl(M("cola"), "NonOverlapConstraints", "");
		cl.def( pybind11::init( [](class cola::NonOverlapConstraintExemptions * a0){ return new cola::NonOverlapConstraints(a0); }, [](class cola::NonOverlapConstraintExemptions * a0){ return new PyCallBack_cola_NonOverlapConstraints(a0); } ), "doc");
		cl.def( pybind11::init<class cola::NonOverlapConstraintExemptions *, unsigned int>(), pybind11::arg("exemptions"), pybind11::arg("priority") );

		cl.def("addShape", [](cola::NonOverlapConstraints &o, unsigned int const & a0, double const & a1, double const & a2) -> void { return o.addShape(a0, a1, a2); }, "", pybind11::arg("id"), pybind11::arg("halfW"), pybind11::arg("halfH"));
		cl.def("addShape", [](cola::NonOverlapConstraints &o, unsigned int const & a0, double const & a1, double const & a2, unsigned int const & a3) -> void { return o.addShape(a0, a1, a2, a3); }, "", pybind11::arg("id"), pybind11::arg("halfW"), pybind11::arg("halfH"), pybind11::arg("group"));
		cl.def("addShape", (void (cola::NonOverlapConstraints::*)(unsigned int, double, double, unsigned int, int)) &cola::NonOverlapConstraints::addShape, "Use this method to add all the shapes between which you want\n        to prevent overlaps.\n \n\n     This will be used as index into both the vars and\n               boundingBoxes vectors when you call the\n               generateSeparationConstraints method.\n \n\n  If you add two shapes with half-widths hwi and hwj, then\n               if a horizontal separation constraint is generated between\n               them its gap will be hwi + hwj.\n \n\n  Similar to halfW.\n \n\n  Assign a group number to this shape. A separation constraint\n               will be generated between two shapes only if they belong to\n               the same group. This is useful for clusters.\n \n\n  Optional set of IDs of shapes to be skipped, i.e. such that\n                    a separation constraint should /not/ be generated between\n                    that shape and the one being added.\n\nC++: cola::NonOverlapConstraints::addShape(unsigned int, double, double, unsigned int, int) --> void", pybind11::arg("id"), pybind11::arg("halfW"), pybind11::arg("halfH"), pybind11::arg("group"), pybind11::arg("exemptions"));
		cl.def("resizeShape", (void (cola::NonOverlapConstraints::*)(unsigned int, double, double)) &cola::NonOverlapConstraints::resizeShape, "C++: cola::NonOverlapConstraints::resizeShape(unsigned int, double, double) --> void", pybind11::arg("id"), pybind11::arg("halfW"), pybind11::arg("halfH"));
		cl.def("removeShape", (void (cola::NonOverlapConstraints::*)(unsigned int)) &cola::NonOverlapConstraints::removeShape, "C++: cola::NonOverlapConstraints::removeShape(unsigned int) --> void", pybind11::arg("id"));
		cl.def("addCluster", (void (cola::NonOverlapConstraints::*)(class cola::Cluster *, unsigned int)) &cola::NonOverlapConstraints::addCluster, "C++: cola::NonOverlapConstraints::addCluster(class cola::Cluster *, unsigned int) --> void", pybind11::arg("cluster"), pybind11::arg("group"));
		cl.def("markCurrSubConstraintAsActive", (void (cola::NonOverlapConstraints::*)(const bool)) &cola::NonOverlapConstraints::markCurrSubConstraintAsActive, "C++: cola::NonOverlapConstraints::markCurrSubConstraintAsActive(const bool) --> void", pybind11::arg("satisfiable"));
		cl.def("markAllSubConstraintsAsInactive", (void (cola::NonOverlapConstraints::*)()) &cola::NonOverlapConstraints::markAllSubConstraintsAsInactive, "C++: cola::NonOverlapConstraints::markAllSubConstraintsAsInactive() --> void");
		cl.def("subConstraintsRemaining", (bool (cola::NonOverlapConstraints::*)() const) &cola::NonOverlapConstraints::subConstraintsRemaining, "C++: cola::NonOverlapConstraints::subConstraintsRemaining() const --> bool");
		cl.def("setClusterClusterExemptions", (void (cola::NonOverlapConstraints::*)(int)) &cola::NonOverlapConstraints::setClusterClusterExemptions, "C++: cola::NonOverlapConstraints::setClusterClusterExemptions(int) --> void", pybind11::arg("exemptions"));
		cl.def("generateVariables", (void (cola::NonOverlapConstraints::*)(const enum vpsc::Dim, int &)) &cola::NonOverlapConstraints::generateVariables, "C++: cola::NonOverlapConstraints::generateVariables(const enum vpsc::Dim, int &) --> void", pybind11::arg("dim"), pybind11::arg("vars"));
		cl.def("generateSeparationConstraints", (void (cola::NonOverlapConstraints::*)(const enum vpsc::Dim, int &, int &)) &cola::NonOverlapConstraints::generateSeparationConstraints, "C++: cola::NonOverlapConstraints::generateSeparationConstraints(const enum vpsc::Dim, int &, int &) --> void", pybind11::arg("dim"), pybind11::arg("vars"), pybind11::arg("gcs"));
		cl.def("generateSeparationConstraints", (void (cola::NonOverlapConstraints::*)(const enum vpsc::Dim, int &, int &, int &)) &cola::NonOverlapConstraints::generateSeparationConstraints, "Generate separation constraints in one dimension, to ensure\n        nonoverlap between all shapes in that dimension.\n \n\n   The dimension for which to generate constraints.\n \n\n  The variables between which the constraints will hold.\n \n\n   The generated constraints will be added to this vector.\n \n\n  For those id's corresponding to added shapes\n      (not clusters), the rectangle boundingBox[id] will be consulted\n      in order to determine:\n      (1) whether a separation constraint is called for, i.e. whether the\n          shapes in question span any of the same coods in the dimension\n          opposite to dim;\n      (2) which var is left and which is right in the separation constraint.\n      Note however that the dimensions of the boundingBoxes do NOT determine\n      the gaps of the separation constraints, which are instead based on the\n      half-width and half-height passed when adding the shapes.\n\nC++: cola::NonOverlapConstraints::generateSeparationConstraints(const enum vpsc::Dim, int &, int &, int &) --> void", pybind11::arg("dim"), pybind11::arg("vars"), pybind11::arg("gcs"), pybind11::arg("boundingBoxes"));
	}
	// cola::TLogLevel file:libcola/cola_log.h line:40
	pybind11::enum_<cola::TLogLevel>(M("cola"), "TLogLevel", pybind11::arithmetic(), "")
		.value("logERROR", cola::logERROR)
		.value("logWARNING", cola::logWARNING)
		.value("logINFO", cola::logINFO)
		.value("logDEBUG", cola::logDEBUG)
		.value("logDEBUG1", cola::logDEBUG1)
		.value("logDEBUG2", cola::logDEBUG2)
		.value("logDEBUG3", cola::logDEBUG3)
		.value("logDEBUG4", cola::logDEBUG4)
		.export_values();

;

	{ // cola::Output2FILE file:libcola/cola_log.h line:118
		pybind11::class_<cola::Output2FILE, std::shared_ptr<cola::Output2FILE>> cl(M("cola"), "Output2FILE", "");
		cl.def( pybind11::init( [](){ return new cola::Output2FILE(); } ) );
		cl.def_static("Stream", (int *& (*)()) &cola::Output2FILE::Stream, "C++: cola::Output2FILE::Stream() --> int *&", pybind11::return_value_policy::automatic);
	}
	{ // cola::FILELog file:libcola/cola_log.h line:152
		pybind11::class_<cola::FILELog, std::shared_ptr<cola::FILELog>> cl(M("cola"), "FILELog", "");
		cl.def( pybind11::init( [](){ return new cola::FILELog(); } ) );
	}
	{ // cola::Component file:libcola/connected_components.h line:30
		pybind11::class_<cola::Component, std::shared_ptr<cola::Component>> cl(M("cola"), "Component", "");
		cl.def( pybind11::init( [](){ return new cola::Component(); } ) );
		cl.def_readwrite("node_ids", &cola::Component::node_ids);
		cl.def_readwrite("rects", &cola::Component::rects);
		cl.def_readwrite("edges", &cola::Component::edges);
		cl.def("moveRectangles", (void (cola::Component::*)(double, double)) &cola::Component::moveRectangles, "C++: cola::Component::moveRectangles(double, double) --> void", pybind11::arg("x"), pybind11::arg("y"));
		cl.def("getBoundingBox", (class vpsc::Rectangle * (cola::Component::*)()) &cola::Component::getBoundingBox, "C++: cola::Component::getBoundingBox() --> class vpsc::Rectangle *", pybind11::return_value_policy::automatic);
	}
	// cola::connectedComponents(const int &, const int &, int &) file:libcola/connected_components.h line:41
	M("cola").def("connectedComponents", (void (*)(const int &, const int &, int &)) &cola::connectedComponents, "C++: cola::connectedComponents(const int &, const int &, int &) --> void", pybind11::arg("rs"), pybind11::arg("es"), pybind11::arg("components"));

	// cola::separateComponents(const int &) file:libcola/connected_components.h line:50
	M("cola").def("separateComponents", (void (*)(const int &)) &cola::separateComponents, "C++: cola::separateComponents(const int &) --> void", pybind11::arg("components"));

}
