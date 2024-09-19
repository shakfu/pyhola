#include <libdialect/constraints.h>
#include <libdialect/graphs.h>
#include <libdialect/ortho.h>
#include <libdialect/peeling.h>
#include <libdialect/planarise.h>
#include <libdialect/quadaction.h>
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

void bind_libdialect_peeling(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// dialect::identifyRootNode(const class dialect::Graph &) file:libdialect/peeling.h line:47
	M("dialect").def("identifyRootNode", (int (*)(const class dialect::Graph &)) &dialect::identifyRootNode, "Mark as \"root\" the PeeledNode having largest serial number.\n\n \n  The Graph must contain only PeeledNodes.\n\n \n  The PeeledNode identified as root.\n\nC++: dialect::identifyRootNode(const class dialect::Graph &) --> int", pybind11::arg("graph"));

	{ // dialect::PeeledNode file:libdialect/peeling.h line:50
		pybind11::class_<dialect::PeeledNode, std::shared_ptr<dialect::PeeledNode>, PyCallBack_dialect_PeeledNode, dialect::GhostNode> cl(M("dialect"), "PeeledNode", "A PeeledNode is a type of GhostNode, used in the peeling process.");
		cl.def_static("allocate", (int (*)(const class dialect::Node &)) &dialect::PeeledNode::allocate, "Factory function.\n\n \n  A shared_ptr to PeeledNode (PeeledNode_SP).\n\nC++: dialect::PeeledNode::allocate(const class dialect::Node &) --> int", pybind11::arg("node"));
	}
	{ // dialect::Stem file:libdialect/peeling.h line:87
		pybind11::class_<dialect::Stem, std::shared_ptr<dialect::Stem>> cl(M("dialect"), "Stem", "Represents a leaf node, along with its one edge and neighbour.");
		cl.def( pybind11::init<const int &, const int &>(), pybind11::arg("leaf"), pybind11::arg("root") );

		cl.def_readwrite("m_plain_leaf", &dialect::Stem::m_plain_leaf);
		cl.def_readwrite("m_plain_root", &dialect::Stem::m_plain_root);
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
		cl.def( pybind11::init<int, int>(), pybind11::arg("node1"), pybind11::arg("node2") );

		cl.def_readwrite("orientation", &dialect::EdgeSegment::orientation);
		cl.def_readwrite("constCoord", &dialect::EdgeSegment::constCoord);
		cl.def_readwrite("lowerBound", &dialect::EdgeSegment::lowerBound);
		cl.def_readwrite("upperBound", &dialect::EdgeSegment::upperBound);
		cl.def_readwrite("openingNode", &dialect::EdgeSegment::openingNode);
		cl.def_readwrite("closingNode", &dialect::EdgeSegment::closingNode);
		cl.def("setNewClosingNode", (void (dialect::EdgeSegment::*)(int)) &dialect::EdgeSegment::setNewClosingNode, "Substitute a new Node as the closing node of the segment.\n         This is useful during our scan line process.\n\nC++: dialect::EdgeSegment::setNewClosingNode(int) --> void", pybind11::arg("u"));
		cl.def("getEvents", (int (dialect::EdgeSegment::*)()) &dialect::EdgeSegment::getEvents, "Generate the two Events, in order, representing the opening\n         and closing of this segment.\n\nC++: dialect::EdgeSegment::getEvents() --> int");
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
		cl.def( pybind11::init<struct dialect::EdgeSegment *, int, enum dialect::EventType>(), pybind11::arg("seg"), pybind11::arg("endpt"), pybind11::arg("type") );

		cl.def( pybind11::init<double, int, enum dialect::EventType>(), pybind11::arg("varCoord"), pybind11::arg("node"), pybind11::arg("type") );

		cl.def_readwrite("endpt", &dialect::Event::endpt);
		cl.def_readwrite("constCoord", &dialect::Event::constCoord);
		cl.def_readwrite("varCoord", &dialect::Event::varCoord);
		cl.def_readwrite("type", &dialect::Event::type);
		cl.def("getNode", (int (dialect::Event::*)()) &dialect::Event::getNode, "C++: dialect::Event::getNode() --> int");
		cl.def("x", (double (dialect::Event::*)()) &dialect::Event::x, "C++: dialect::Event::x() --> double");
		cl.def("y", (double (dialect::Event::*)()) &dialect::Event::y, "C++: dialect::Event::y() --> double");
	}
	// dialect::CompareActiveEvents(struct dialect::Event *, struct dialect::Event *) file:libdialect/planarise.h line:111
	M("dialect").def("CompareActiveEvents", (bool (*)(struct dialect::Event *, struct dialect::Event *)) &dialect::CompareActiveEvents, "We need a special function for comparing Events, using a positive tolerance.\n Here's why. Suppose vertical segment A has its south end at (0, 0), and horizontal\n segment B has its east end at (0, -0.00000000001). This means that /technically/\n A and B intersect. However (http://xkcd.com/1475/) you probably don't actually want\n to treat this as an intersection. The comparison function is designed so that,\n when the list of active events is sorted, the \"close\" event for segment A will come\n /before/ the \"sustain\" event for segment B, instead of the other way around, as\n dictated by their exact y-coordinates. This way we will /not/ detect an intersection\n between A and B.\n\nC++: dialect::CompareActiveEvents(struct dialect::Event *, struct dialect::Event *) --> bool", pybind11::arg("a"), pybind11::arg("b"));

	{ // dialect::OrthoPlanariserOptions file:libdialect/planarise.h line:117
		pybind11::class_<dialect::OrthoPlanariserOptions, std::shared_ptr<dialect::OrthoPlanariserOptions>> cl(M("dialect"), "OrthoPlanariserOptions", "");
		cl.def( pybind11::init( [](){ return new dialect::OrthoPlanariserOptions(); } ) );
		cl.def( pybind11::init( [](dialect::OrthoPlanariserOptions const &o){ return new dialect::OrthoPlanariserOptions(o); } ) );
		cl.def_readwrite("generateConstraints", &dialect::OrthoPlanariserOptions::generateConstraints);
		cl.def("assign", (struct dialect::OrthoPlanariserOptions & (dialect::OrthoPlanariserOptions::*)(const struct dialect::OrthoPlanariserOptions &)) &dialect::OrthoPlanariserOptions::operator=, "C++: dialect::OrthoPlanariserOptions::operator=(const struct dialect::OrthoPlanariserOptions &) --> struct dialect::OrthoPlanariserOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // dialect::OrthoPlanariser file:libdialect/planarise.h line:130
		pybind11::class_<dialect::OrthoPlanariser, std::shared_ptr<dialect::OrthoPlanariser>> cl(M("dialect"), "OrthoPlanariser", "This class is for planarising orthogonally routed graphs.\n To say that a graph G is orthogonally routed means a certain condition on\n the connector route stored in each Edge; namely, that precisely one coordinate\n change between consecutive route points.");
		cl.def( pybind11::init<const int &>(), pybind11::arg("G") );

		cl.def("setOpts", (void (dialect::OrthoPlanariser::*)(const struct dialect::OrthoPlanariserOptions &)) &dialect::OrthoPlanariser::setOpts, "Set the options.\n\nC++: dialect::OrthoPlanariser::setOpts(const struct dialect::OrthoPlanariserOptions &) --> void", pybind11::arg("opts"));
		cl.def("planarise", (int (dialect::OrthoPlanariser::*)()) &dialect::OrthoPlanariser::planarise, "Compute a planarisation of the given Graph.\n \n\n  The planarised Graph.\n\nC++: dialect::OrthoPlanariser::planarise() --> int");
	}
	// dialect::lookupQuadActions(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long) file:libdialect/quadaction.h line:50
	M("dialect").def("lookupQuadActions", (int (*)(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)) &dialect::lookupQuadActions, "Look up legal quad actions\n\n \n  = 0, 1, or 2, indicating whether there are 0, 1, or >= 2\n                nodes in the first quadrant\n \n\n  like p, only for the second quadrant\n \n\n  like p, only for the third quadrant\n \n\n  like p, only for the fourth quadrant\n \n\n  binary coded representation of which semiaxes are to be used:\n                 1's bit: 1 if EAST is to be used; else 0\n                 2's bit: 1 if SOUTH is to be used; else 0\n                 4's bit: 1 if WEST is to be used; else 0\n                 8's bit: 1 if NORTH is to be used; else 0\n\n \n  vector of strings, naming the legal quad actions\n\nC++: dialect::lookupQuadActions(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long) --> int", pybind11::arg("p"), pybind11::arg("q"), pybind11::arg("r"), pybind11::arg("s"), pybind11::arg("c"));

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
		cl.def( pybind11::init<const int &, double>(), pybind11::arg("semis"), pybind11::arg("cost") );

		cl.def( pybind11::init( [](){ return new dialect::Assignment(); } ) );
		cl.def_readwrite("semis", &dialect::Assignment::semis);
		cl.def_readwrite("cost", &dialect::Assignment::cost);
		cl.def("cardinality", (unsigned long (dialect::Assignment::*)() const) &dialect::Assignment::cardinality, "Return the \"cardinality\" of this Assignment, i.e. the number\n         of Nbrs assigned to semiaxes.\n\nC++: dialect::Assignment::cardinality() const --> unsigned long");
		cl.def("makeUnion", (struct dialect::Assignment (dialect::Assignment::*)(const struct dialect::Assignment &) const) &dialect::Assignment::makeUnion, "Create union of two Assignments.\n\n \n  A new Assignment representing the union of this one with\n          the other.\n\n \n  This function assumes you never try to put more than one\n        Nbr on a given semiaxis. If you do, you will get an incorrect\n        result; an exception will not be raised.\n\nC++: dialect::Assignment::makeUnion(const struct dialect::Assignment &) const --> struct dialect::Assignment", pybind11::arg("other"));
		cl.def("toString", (int (dialect::Assignment::*)() const) &dialect::Assignment::toString, "Write a string representation, listing the id of the Nbr\n         assigned to each semiaxis. For example if Nbrs 3, 7, 8 are\n         assigned to semiaxes E, S, N resp., represent this as \"3 7 - 8\".\n\n \n  string representation.\n\nC++: dialect::Assignment::toString() const --> int");
	}
	{ // dialect::Quad file:libdialect/quadaction.h line:139
		pybind11::class_<dialect::Quad, std::shared_ptr<dialect::Quad>> cl(M("dialect"), "Quad", "Represents a quadrant, relative to a central node.");
		cl.def( pybind11::init<unsigned int>(), pybind11::arg("num") );

		cl.def_readwrite("num", &dialect::Quad::num);
		cl.def_readwrite("nbrs", &dialect::Quad::nbrs);
		cl.def_readwrite("ACost", &dialect::Quad::ACost);
		cl.def_readwrite("CCost", &dialect::Quad::CCost);
		cl.def("addNbr", (void (dialect::Quad::*)(const int &)) &dialect::Quad::addNbr, "Add a neighbour.\n\nC++: dialect::Quad::addNbr(const int &) --> void", pybind11::arg("nbr"));
		cl.def("size", (unsigned long (dialect::Quad::*)() const) &dialect::Quad::size, "Say how many Nbrs are in this quadrant.\n\nC++: dialect::Quad::size() const --> unsigned long");
		cl.def("sortAndComputeCosts", (void (dialect::Quad::*)()) &dialect::Quad::sortAndComputeCosts, "To be called after all nbrs have been added.\n         Sorts the nbrs into clockwise order, and then computes\n         and stores the costs associated with the clockwise and\n         anticlockwise actions.\n\nC++: dialect::Quad::sortAndComputeCosts() --> void");
		cl.def("constructAssignmentForAction", (struct dialect::Assignment (dialect::Quad::*)(char) const) &dialect::Quad::constructAssignmentForAction, "Construct an Assignment indicating which Nbr(s) were assigned\n         to which semiaxes, and representing the cost.\n\n \n  an action code letter, in {A, B, C, D}:\n                         A: Anticlockwise\n                         B: Both\n                         C: Clockwise\n                         D: Do nothing\n\n \n  the Assignment\n\nC++: dialect::Quad::constructAssignmentForAction(char) const --> struct dialect::Assignment", pybind11::arg("action"));
	}
}
