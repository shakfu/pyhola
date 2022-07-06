#include <_stdio.h>
#include <functional>
#include <iterator>
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
#include <libdialect/quadaction.h>
#include <libdialect/routing.h>
#include <libvpsc/constraint.h>
#include <libvpsc/rectangle.h>
#include <libvpsc/variable.h>
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
};

void bind_libdialect_quadaction(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dialect::Nbr file:libdialect/quadaction.h line:65
		pybind11::class_<dialect::Nbr, std::shared_ptr<dialect::Nbr>> cl(M("dialect"), "Nbr", "Represents a neighbouring node to a central node.");
		cl.def( pybind11::init<unsigned int, double, double>(), pybind11::arg("id"), pybind11::arg("dx"), pybind11::arg("dy") );

		cl.def_readwrite("id", &dialect::Nbr::id);
		cl.def_readwrite("x", &dialect::Nbr::x);
		cl.def_readwrite("y", &dialect::Nbr::y);
		cl.def("octalCode", (unsigned int (dialect::Nbr::*)() const) &dialect::Nbr::octalCode, "A code number from 0 to 7, indicating where this neighbour\n         lies relative to the central node:\n             Semiaxes 0,1,2,3 get octal codes 0,2,4,6;\n             Quadrants 0,1,2,3 get octal codes 1,3,5,7.\n\nC++: dialect::Nbr::octalCode() const --> unsigned int");
		cl.def("deflection", (double (dialect::Nbr::*)() const) &dialect::Nbr::deflection, "A measure of how far into its quadrant this nbr lies, in the\n         clockwise direction.\n\n \n If this nbr lies in quadrant n or on semiaxis n, then return\n         the squared sine of the angle that this nbr makes with semiaxis n.\n\nC++: dialect::Nbr::deflection() const --> double");
	}
	{ // dialect::Assignment file:libdialect/quadaction.h line:95
		pybind11::class_<dialect::Assignment, std::shared_ptr<dialect::Assignment>> cl(M("dialect"), "Assignment", "Represents an assignment of nbrs to semiaxes, and records the\n         cost of this assignment.");
		cl.def( pybind11::init( [](){ return new dialect::Assignment(); } ) );
		cl.def( pybind11::init( [](dialect::Assignment const &o){ return new dialect::Assignment(o); } ) );
		cl.def_readwrite("semis", &dialect::Assignment::semis);
		cl.def_readwrite("cost", &dialect::Assignment::cost);
		cl.def("cardinality", (unsigned long (dialect::Assignment::*)() const) &dialect::Assignment::cardinality, "Return the \"cardinality\" of this Assignment, i.e. the number\n         of Nbrs assigned to semiaxes.\n\nC++: dialect::Assignment::cardinality() const --> unsigned long");
		cl.def("makeUnion", (struct dialect::Assignment (dialect::Assignment::*)(const struct dialect::Assignment &) const) &dialect::Assignment::makeUnion, "Create union of two Assignments.\n\n \n  A new Assignment representing the union of this one with\n          the other.\n\n \n  This function assumes you never try to put more than one\n        Nbr on a given semiaxis. If you do, you will get an incorrect\n        result; an exception will not be raised.\n\nC++: dialect::Assignment::makeUnion(const struct dialect::Assignment &) const --> struct dialect::Assignment", pybind11::arg("other"));
		cl.def("toString", (std::string (dialect::Assignment::*)() const) &dialect::Assignment::toString, "Write a string representation, listing the id of the Nbr\n         assigned to each semiaxis. For example if Nbrs 3, 7, 8 are\n         assigned to semiaxes E, S, N resp., represent this as \"3 7 - 8\".\n\n \n  string representation.\n\nC++: dialect::Assignment::toString() const --> std::string");
	}
	{ // dialect::Quad file:libdialect/quadaction.h line:139
		pybind11::class_<dialect::Quad, std::shared_ptr<dialect::Quad>> cl(M("dialect"), "Quad", "Represents a quadrant, relative to a central node.");
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("num") );

		cl.def( pybind11::init( [](dialect::Quad const &o){ return new dialect::Quad(o); } ) );
		cl.def_readwrite("num", &dialect::Quad::num);
		cl.def_readwrite("nbrs", &dialect::Quad::nbrs);
		cl.def_readwrite("ACost", &dialect::Quad::ACost);
		cl.def_readwrite("CCost", &dialect::Quad::CCost);
		cl.def("addNbr", (void (dialect::Quad::*)(const class std::shared_ptr<struct dialect::Nbr> &)) &dialect::Quad::addNbr, "Add a neighbour.\n\nC++: dialect::Quad::addNbr(const class std::shared_ptr<struct dialect::Nbr> &) --> void", pybind11::arg("nbr"));
		cl.def("size", (unsigned long (dialect::Quad::*)() const) &dialect::Quad::size, "Say how many Nbrs are in this quadrant.\n\nC++: dialect::Quad::size() const --> unsigned long");
		cl.def("sortAndComputeCosts", (void (dialect::Quad::*)()) &dialect::Quad::sortAndComputeCosts, "To be called after all nbrs have been added.\n         Sorts the nbrs into clockwise order, and then computes\n         and stores the costs associated with the clockwise and\n         anticlockwise actions.\n\nC++: dialect::Quad::sortAndComputeCosts() --> void");
		cl.def("constructAssignmentForAction", (struct dialect::Assignment (dialect::Quad::*)(char) const) &dialect::Quad::constructAssignmentForAction, "Construct an Assignment indicating which Nbr(s) were assigned\n         to which semiaxes, and representing the cost.\n\n \n  an action code letter, in {A, B, C, D}:\n                         A: Anticlockwise\n                         B: Both\n                         C: Clockwise\n                         D: Do nothing\n\n \n  the Assignment\n\nC++: dialect::Quad::constructAssignmentForAction(char) const --> struct dialect::Assignment", pybind11::arg("action"));
	}
	{ // dialect::Arrangement file:libdialect/quadaction.h line:181
		pybind11::class_<dialect::Arrangement, std::shared_ptr<dialect::Arrangement>> cl(M("dialect"), "Arrangement", "Represents the arrangement of all Nbrs around a centre node.");
		cl.def( pybind11::init( [](dialect::Arrangement const &o){ return new dialect::Arrangement(o); } ) );
		cl.def_readwrite("nbrs", &dialect::Arrangement::nbrs);
		cl.def_readwrite("semis", &dialect::Arrangement::semis);
		cl.def_readwrite("quads", &dialect::Arrangement::quads);
		cl.def("getBasicAssignment", (class std::shared_ptr<struct dialect::Assignment> (dialect::Arrangement::*)() const) &dialect::Arrangement::getBasicAssignment, "Get the \"basic Assignment\" for this Arrangement.\n\n \n  the Assignment in which no quad actions have been taken, i.e.\n          in which the semiaxees are just as initially defined, and in\n          which the cost is zero.\n\nC++: dialect::Arrangement::getBasicAssignment() const --> class std::shared_ptr<struct dialect::Assignment>");
		cl.def("getAssignmentForQuadAction", (class std::shared_ptr<struct dialect::Assignment> (dialect::Arrangement::*)(std::string) const) &dialect::Arrangement::getAssignmentForQuadAction, "Get the Assignment resulting from a given quad action.\n\n \n  a string of four letters chosen from among\n                     {A, B, C, D}, representing the action to be taken\n                     in each of the four quadrants.\n\n \n  the Assignment resulting from the quad action.\n\nC++: dialect::Arrangement::getAssignmentForQuadAction(std::string) const --> class std::shared_ptr<struct dialect::Assignment>", pybind11::arg("quadAction"));
	}
	{ // dialect::OrthoHubLayoutOptions file:libdialect/nodeconfig.h line:38
		pybind11::class_<dialect::OrthoHubLayoutOptions, std::shared_ptr<dialect::OrthoHubLayoutOptions>> cl(M("dialect"), "OrthoHubLayoutOptions", "Options to control OrthoHubLayout");
		cl.def( pybind11::init( [](){ return new dialect::OrthoHubLayoutOptions(); } ) );
		cl.def( pybind11::init( [](dialect::OrthoHubLayoutOptions const &o){ return new dialect::OrthoHubLayoutOptions(o); } ) );
		cl.def_readwrite("avoidFlatTriangles", &dialect::OrthoHubLayoutOptions::avoidFlatTriangles);
		cl.def_readwrite("includeLinks", &dialect::OrthoHubLayoutOptions::includeLinks);
		cl.def("assign", (struct dialect::OrthoHubLayoutOptions & (dialect::OrthoHubLayoutOptions::*)(const struct dialect::OrthoHubLayoutOptions &)) &dialect::OrthoHubLayoutOptions::operator=, "C++: dialect::OrthoHubLayoutOptions::operator=(const struct dialect::OrthoHubLayoutOptions &) --> struct dialect::OrthoHubLayoutOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::OrthoHubLayout file:libdialect/nodeconfig.h line:62
		pybind11::class_<dialect::OrthoHubLayout, std::shared_ptr<dialect::OrthoHubLayout>> cl(M("dialect"), "OrthoHubLayout", "A layout object that tries to orthogonalise hubs.\n         This means it visits nodes of degrees 3 or higher, and\n         tries to set their neighbours in cardinal compass directions\n         from it.");
		cl.def( pybind11::init<class std::shared_ptr<class dialect::Graph>, struct dialect::OrthoHubLayoutOptions>(), pybind11::arg("G"), pybind11::arg("opts") );

		cl.def( pybind11::init( [](dialect::OrthoHubLayout const &o){ return new dialect::OrthoHubLayout(o); } ) );
		cl.def("layout", [](dialect::OrthoHubLayout &o) -> void { return o.layout(); }, "");
		cl.def("layout", (void (dialect::OrthoHubLayout::*)(struct dialect::Logger *)) &dialect::OrthoHubLayout::layout, "Try to orthogonalise hubs.\n\n \n  Optional logger to record the individual layout steps.\n\nC++: dialect::OrthoHubLayout::layout(struct dialect::Logger *) --> void", pybind11::arg("logger"));
	}
	// dialect::identifyRootNode(const class dialect::Graph &) file:libdialect/peeling.h line:47
	M("dialect").def("identifyRootNode", (class std::shared_ptr<class dialect::PeeledNode> (*)(const class dialect::Graph &)) &dialect::identifyRootNode, "Mark as \"root\" the PeeledNode having largest serial number.\n\n \n  The Graph must contain only PeeledNodes.\n\n \n  The PeeledNode identified as root.\n\nC++: dialect::identifyRootNode(const class dialect::Graph &) --> class std::shared_ptr<class dialect::PeeledNode>", pybind11::arg("graph"));

	{ // dialect::PeeledNode file:libdialect/peeling.h line:50
		pybind11::class_<dialect::PeeledNode, std::shared_ptr<dialect::PeeledNode>, PyCallBack_dialect_PeeledNode, dialect::GhostNode> cl(M("dialect"), "PeeledNode", "A PeeledNode is a type of GhostNode, used in the peeling process.");
		cl.def_static("allocate", (class std::shared_ptr<class dialect::PeeledNode> (*)(const class dialect::Node &)) &dialect::PeeledNode::allocate, "Factory function.\n\n \n  A shared_ptr to PeeledNode (PeeledNode_SP).\n\nC++: dialect::PeeledNode::allocate(const class dialect::Node &) --> class std::shared_ptr<class dialect::PeeledNode>", pybind11::arg("node"));
	}
	{ // dialect::Stem file:libdialect/peeling.h line:87
		pybind11::class_<dialect::Stem, std::shared_ptr<dialect::Stem>> cl(M("dialect"), "Stem", "Represents a leaf node, along with its one edge and neighbour.");
		cl.def( pybind11::init<const class std::shared_ptr<class dialect::Node> &, const class std::shared_ptr<class dialect::Node> &>(), pybind11::arg("leaf"), pybind11::arg("root") );

		cl.def( pybind11::init( [](dialect::Stem const &o){ return new dialect::Stem(o); } ) );
		cl.def_readwrite("m_plain_leaf", &dialect::Stem::m_plain_leaf);
		cl.def_readwrite("m_plain_root", &dialect::Stem::m_plain_root);
		cl.def("addSelfToGraph", (void (dialect::Stem::*)(class dialect::Graph &)) &dialect::Stem::addSelfToGraph, "C++: dialect::Stem::addSelfToGraph(class dialect::Graph &) --> void", pybind11::arg("H"));
	}
	{ // dialect::NodeBuckets file:libdialect/peeling.h line:101
		pybind11::class_<dialect::NodeBuckets, std::shared_ptr<dialect::NodeBuckets>> cl(M("dialect"), "NodeBuckets", "For sorting all the nodes of a graph into \"buckets\" according\n to their degree.\n You can take all the leaves (degree-1 nodes) and you can move\n a node from one bucket to another.");
		cl.def( pybind11::init<class dialect::Graph &>(), pybind11::arg("graph") );

		cl.def( pybind11::init( [](dialect::NodeBuckets const &o){ return new dialect::NodeBuckets(o); } ) );
		cl.def_readwrite("m_maxDegree", &dialect::NodeBuckets::m_maxDegree);
		cl.def_readwrite("m_buckets", &dialect::NodeBuckets::m_buckets);
		cl.def("takeLeaves", (class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > (dialect::NodeBuckets::*)()) &dialect::NodeBuckets::takeLeaves, "Return a copy of the bucket of leaves, and clear the latter.\n\nC++: dialect::NodeBuckets::takeLeaves() --> class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > >");
		cl.def("moveNode", (bool (dialect::NodeBuckets::*)(unsigned int, unsigned int, unsigned int)) &dialect::NodeBuckets::moveNode, "Move a node from one bucket to another.\n\n \n  The ID of the Node to be moved.\n \n\n  The bucket in which the Node should be found.\n \n\n  The bucket to which the Node should be moved.\n\n \n  boolean saying whether the Node was found and moved.\n\nC++: dialect::NodeBuckets::moveNode(unsigned int, unsigned int, unsigned int) --> bool", pybind11::arg("id"), pybind11::arg("oldDegree"), pybind11::arg("newDegree"));
		cl.def("severNodes", (void (dialect::NodeBuckets::*)(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &)) &dialect::NodeBuckets::severNodes, "Sever the given Nodes from our Graph.\n\n \n  This method does modify the Graph.\n        For each given Node, all incident Edges are severed, and the Node\n        is removed from the Graph.\n        The neighbouring Nodes are moved to new buckets as appropriate.\n \n\n  The given Nodes themselves are NOT moved to new buckets.\n        This preserves the freedom to handle that operation separately.\n\nC++: dialect::NodeBuckets::severNodes(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &) --> void", pybind11::arg("nodes"));
	}
	{ // dialect::EdgeSegment file:libdialect/planarise.h line:41
		pybind11::class_<dialect::EdgeSegment, std::shared_ptr<dialect::EdgeSegment>> cl(M("dialect"), "EdgeSegment", "Represents an axis-aligned segment of an orthogonal connector route.");
		cl.def( pybind11::init<class std::shared_ptr<class dialect::Node>, class std::shared_ptr<class dialect::Node>>(), pybind11::arg("node1"), pybind11::arg("node2") );

		cl.def( pybind11::init( [](dialect::EdgeSegment const &o){ return new dialect::EdgeSegment(o); } ) );
		cl.def_readwrite("orientation", &dialect::EdgeSegment::orientation);
		cl.def_readwrite("constCoord", &dialect::EdgeSegment::constCoord);
		cl.def_readwrite("lowerBound", &dialect::EdgeSegment::lowerBound);
		cl.def_readwrite("upperBound", &dialect::EdgeSegment::upperBound);
		cl.def_readwrite("openingNode", &dialect::EdgeSegment::openingNode);
		cl.def_readwrite("closingNode", &dialect::EdgeSegment::closingNode);
		cl.def("setNewClosingNode", (void (dialect::EdgeSegment::*)(class std::shared_ptr<class dialect::Node>)) &dialect::EdgeSegment::setNewClosingNode, "Substitute a new Node as the closing node of the segment.\n         This is useful during our scan line process.\n\nC++: dialect::EdgeSegment::setNewClosingNode(class std::shared_ptr<class dialect::Node>) --> void", pybind11::arg("u"));
		cl.def("getEvents", (struct std::pair<struct dialect::Event *, struct dialect::Event *> (dialect::EdgeSegment::*)()) &dialect::EdgeSegment::getEvents, "Generate the two Events, in order, representing the opening\n         and closing of this segment.\n\nC++: dialect::EdgeSegment::getEvents() --> struct std::pair<struct dialect::Event *, struct dialect::Event *>");
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
		cl.def( pybind11::init<struct dialect::EdgeSegment *, class std::shared_ptr<class dialect::Node>, enum dialect::EventType>(), pybind11::arg("seg"), pybind11::arg("endpt"), pybind11::arg("type") );

		cl.def( pybind11::init<double, class std::shared_ptr<class dialect::Node>, enum dialect::EventType>(), pybind11::arg("varCoord"), pybind11::arg("node"), pybind11::arg("type") );

		cl.def( pybind11::init( [](dialect::Event const &o){ return new dialect::Event(o); } ) );
		cl.def_readwrite("endpt", &dialect::Event::endpt);
		cl.def_readwrite("constCoord", &dialect::Event::constCoord);
		cl.def_readwrite("varCoord", &dialect::Event::varCoord);
		cl.def_readwrite("type", &dialect::Event::type);
		cl.def("getNode", (class std::shared_ptr<class dialect::Node> (dialect::Event::*)()) &dialect::Event::getNode, "C++: dialect::Event::getNode() --> class std::shared_ptr<class dialect::Node>");
		cl.def("x", (double (dialect::Event::*)()) &dialect::Event::x, "C++: dialect::Event::x() --> double");
		cl.def("y", (double (dialect::Event::*)()) &dialect::Event::y, "C++: dialect::Event::y() --> double");
	}
}
