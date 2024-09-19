#include <__memory/shared_ptr.h>
#include <functional>
#include <libavoid/connend.h>
#include <libavoid/geomtypes.h>
#include <libavoid/router.h>
#include <libcola/cluster.h>
#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/logging.h>
#include <libdialect/nodeconfig.h>
#include <libdialect/ortho.h>
#include <libdialect/peeling.h>
#include <libdialect/planarise.h>
#include <libdialect/routing.h>
#include <libvpsc/rectangle.h>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <utility>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// dialect::PeeledNode file:libdialect/peeling.h line:50
struct PyCallBack_dialect_PeeledNode : public dialect::PeeledNode {
	using dialect::PeeledNode::PeeledNode;

	unsigned int id() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::PeeledNode *>(this), "id");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value) {
				static pybind11::detail::override_caster_t<unsigned int> caster;
				return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<unsigned int>(std::move(o));
		}
		return GhostNode::id();
	}
	int getChildren() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const dialect::PeeledNode *>(this), "getChildren");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return GhostNode::getChildren();
	}
};

void bind_libdialect_nodeconfig(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::OrthoHubLayoutOptions file:libdialect/nodeconfig.h line:38
		pybind11::class_<dialect::OrthoHubLayoutOptions, std::shared_ptr<dialect::OrthoHubLayoutOptions>> cl(M("dialect"), "OrthoHubLayoutOptions", "Options to control OrthoHubLayout");
		cl.def( pybind11::init( [](){ return new dialect::OrthoHubLayoutOptions(); } ) );
		cl.def_readwrite("avoidFlatTriangles", &dialect::OrthoHubLayoutOptions::avoidFlatTriangles);
		cl.def_readwrite("includeLinks", &dialect::OrthoHubLayoutOptions::includeLinks);
	}
	{ // dialect::OrthoHubLayout file:libdialect/nodeconfig.h line:62
		pybind11::class_<dialect::OrthoHubLayout, std::shared_ptr<dialect::OrthoHubLayout>> cl(M("dialect"), "OrthoHubLayout", "A layout object that tries to orthogonalise hubs.\n         This means it visits nodes of degrees 3 or higher, and\n         tries to set their neighbours in cardinal compass directions\n         from it.");
		cl.def("layout", [](dialect::OrthoHubLayout &o) -> void { return o.layout(); }, "");
		cl.def("layout", (void (dialect::OrthoHubLayout::*)(struct dialect::Logger *)) &dialect::OrthoHubLayout::layout, "Try to orthogonalise hubs.\n\n \n  Optional logger to record the individual layout steps.\n\nC++: dialect::OrthoHubLayout::layout(struct dialect::Logger *) --> void", pybind11::arg("logger"));
	}
	{ // dialect::PeeledNode file:libdialect/peeling.h line:50
		pybind11::class_<dialect::PeeledNode, std::shared_ptr<dialect::PeeledNode>, PyCallBack_dialect_PeeledNode, dialect::GhostNode> cl(M("dialect"), "PeeledNode", "A PeeledNode is a type of GhostNode, used in the peeling process.");
	}
	{ // dialect::Stem file:libdialect/peeling.h line:87
		pybind11::class_<dialect::Stem, std::shared_ptr<dialect::Stem>> cl(M("dialect"), "Stem", "Represents a leaf node, along with its one edge and neighbour.");
		cl.def("addSelfToGraph", (void (dialect::Stem::*)(class dialect::Graph &)) &dialect::Stem::addSelfToGraph, "C++: dialect::Stem::addSelfToGraph(class dialect::Graph &) --> void", pybind11::arg("H"));
	}
	// dialect::makeStemsFromLeaves(const int &) file:libdialect/peeling.h line:95
	M("dialect").def("makeStemsFromLeaves", (int (*)(const int &)) &dialect::makeStemsFromLeaves, "Make a Stem object to represent each leaf.\n\nC++: dialect::makeStemsFromLeaves(const int &) --> int", pybind11::arg("leaves"));

	{ // dialect::NodeBuckets file:libdialect/peeling.h line:101
		pybind11::class_<dialect::NodeBuckets, std::shared_ptr<dialect::NodeBuckets>> cl(M("dialect"), "NodeBuckets", "For sorting all the nodes of a graph into \"buckets\" according\n to their degree.\n You can take all the leaves (degree-1 nodes) and you can move\n a node from one bucket to another.");
		cl.def( pybind11::init<class dialect::Graph &>(), pybind11::arg("graph") );

		cl.def_readwrite("m_maxDegree", &dialect::NodeBuckets::m_maxDegree);
		cl.def_readwrite("m_buckets", &dialect::NodeBuckets::m_buckets);
		cl.def("takeLeaves", (int (dialect::NodeBuckets::*)()) &dialect::NodeBuckets::takeLeaves, "Return a copy of the bucket of leaves, and clear the latter.\n\nC++: dialect::NodeBuckets::takeLeaves() --> int");
		cl.def("moveNode", (bool (dialect::NodeBuckets::*)(unsigned int, unsigned int, unsigned int)) &dialect::NodeBuckets::moveNode, "Move a node from one bucket to another.\n\n \n  The ID of the Node to be moved.\n \n\n  The bucket in which the Node should be found.\n \n\n  The bucket to which the Node should be moved.\n\n \n  boolean saying whether the Node was found and moved.\n\nC++: dialect::NodeBuckets::moveNode(unsigned int, unsigned int, unsigned int) --> bool", pybind11::arg("id"), pybind11::arg("oldDegree"), pybind11::arg("newDegree"));
		cl.def("severNodes", (void (dialect::NodeBuckets::*)(const int &)) &dialect::NodeBuckets::severNodes, "Sever the given Nodes from our Graph.\n\n \n  This method does modify the Graph.\n        For each given Node, all incident Edges are severed, and the Node\n        is removed from the Graph.\n        The neighbouring Nodes are moved to new buckets as appropriate.\n \n\n  The given Nodes themselves are NOT moved to new buckets.\n        This preserves the freedom to handle that operation separately.\n\nC++: dialect::NodeBuckets::severNodes(const int &) --> void", pybind11::arg("nodes"));
	}
	// dialect::peel(class dialect::Graph &) file:libdialect/peeling.h line:157
	M("dialect").def("peel", (int (*)(class dialect::Graph &)) &dialect::peel, "Perform the \"peeling\" process, in which the exterior trees are\n         removed from the given Graph.\n\n \n  See Abello, James, Frank Van Ham, and Neeraj Krishnan.\n         \"Ask-graphview: A large scale graph visualization system.\"\n         IEEE transactions on visualization and computer graphics 12\n         no. 5 (2006): 669-676.\n\n \n  The given Graph is modiifed in place. It will be pared down\n        to its own /core/ -- i.e. all that remains after the trees have\n        been peeled away.\n\n        Each tree includes a root node which is a copy of a node that\n        remains in the core.\n\n        The underlying Graphs of the created Trees consist of PeeledNodes.\n\n        In the case that the given Graph is itself a tree, the remaining core\n        will consist only of the tree's root node. Meanwhile the one Tree will\n        be a copy of the entire original graph.\n\n \n  The trees.\n\nC++: dialect::peel(class dialect::Graph &) --> int", pybind11::arg("G"));

	{ // dialect::EdgeSegment file:libdialect/planarise.h line:41
		pybind11::class_<dialect::EdgeSegment, std::shared_ptr<dialect::EdgeSegment>> cl(M("dialect"), "EdgeSegment", "Represents an axis-aligned segment of an orthogonal connector route.");
		cl.def_readwrite("orientation", &dialect::EdgeSegment::orientation);
		cl.def_readwrite("constCoord", &dialect::EdgeSegment::constCoord);
		cl.def_readwrite("lowerBound", &dialect::EdgeSegment::lowerBound);
		cl.def_readwrite("upperBound", &dialect::EdgeSegment::upperBound);
		cl.def_readwrite("openingNode", &dialect::EdgeSegment::openingNode);
		cl.def_readwrite("closingNode", &dialect::EdgeSegment::closingNode);
		cl.def("addSep", (void (dialect::EdgeSegment::*)(class dialect::SepMatrix &) const) &dialect::EdgeSegment::addSep, "Update a SepMatrix with a constraint requiring this segment to\n         remain aligned and at least its current length.\n\nC++: dialect::EdgeSegment::addSep(class dialect::SepMatrix &) const --> void", pybind11::arg("m"));
	}
	// dialect::EventType file:libdialect/planarise.h line:75
	pybind11::enum_<dialect::EventType>(M("dialect"), "EventType", "")
		.value("CLOSE", dialect::EventType::CLOSE)
		.value("SUSTAIN", dialect::EventType::SUSTAIN)
		.value("OPEN", dialect::EventType::OPEN);

;

	{ // dialect::Event file:libdialect/planarise.h line:81
		pybind11::class_<dialect::Event, std::shared_ptr<dialect::Event>> cl(M("dialect"), "Event", "");
		cl.def_readwrite("endpt", &dialect::Event::endpt);
		cl.def_readwrite("constCoord", &dialect::Event::constCoord);
		cl.def_readwrite("varCoord", &dialect::Event::varCoord);
		cl.def_readwrite("type", &dialect::Event::type);
		cl.def("x", (double (dialect::Event::*)()) &dialect::Event::x, "C++: dialect::Event::x() --> double");
		cl.def("y", (double (dialect::Event::*)()) &dialect::Event::y, "C++: dialect::Event::y() --> double");
	}
	// dialect::CompareActiveEvents(struct dialect::Event *, struct dialect::Event *) file:libdialect/planarise.h line:111
	M("dialect").def("CompareActiveEvents", (bool (*)(struct dialect::Event *, struct dialect::Event *)) &dialect::CompareActiveEvents, "We need a special function for comparing Events, using a positive tolerance.\n Here's why. Suppose vertical segment A has its south end at (0, 0), and horizontal\n segment B has its east end at (0, -0.00000000001). This means that /technically/\n A and B intersect. However (http://xkcd.com/1475/) you probably don't actually want\n to treat this as an intersection. The comparison function is designed so that,\n when the list of active events is sorted, the \"close\" event for segment A will come\n /before/ the \"sustain\" event for segment B, instead of the other way around, as\n dictated by their exact y-coordinates. This way we will /not/ detect an intersection\n between A and B.\n\nC++: dialect::CompareActiveEvents(struct dialect::Event *, struct dialect::Event *) --> bool", pybind11::arg("a"), pybind11::arg("b"));

	{ // dialect::OrthoPlanariserOptions file:libdialect/planarise.h line:117
		pybind11::class_<dialect::OrthoPlanariserOptions, std::shared_ptr<dialect::OrthoPlanariserOptions>> cl(M("dialect"), "OrthoPlanariserOptions", "");
		cl.def( pybind11::init( [](){ return new dialect::OrthoPlanariserOptions(); } ) );
		cl.def_readwrite("generateConstraints", &dialect::OrthoPlanariserOptions::generateConstraints);
		cl.def("assign", (struct dialect::OrthoPlanariserOptions & (dialect::OrthoPlanariserOptions::*)(const struct dialect::OrthoPlanariserOptions &)) &dialect::OrthoPlanariserOptions::operator=, "C++: dialect::OrthoPlanariserOptions::operator=(const struct dialect::OrthoPlanariserOptions &) --> struct dialect::OrthoPlanariserOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::OrthoPlanariser file:libdialect/planarise.h line:130
		pybind11::class_<dialect::OrthoPlanariser, std::shared_ptr<dialect::OrthoPlanariser>> cl(M("dialect"), "OrthoPlanariser", "This class is for planarising orthogonally routed graphs.\n To say that a graph G is orthogonally routed means a certain condition on\n the connector route stored in each Edge; namely, that precisely one coordinate\n change between consecutive route points.");
		cl.def("setOpts", (void (dialect::OrthoPlanariser::*)(const struct dialect::OrthoPlanariserOptions &)) &dialect::OrthoPlanariser::setOpts, "Set the options.\n\nC++: dialect::OrthoPlanariser::setOpts(const struct dialect::OrthoPlanariserOptions &) --> void", pybind11::arg("opts"));
	}
}
