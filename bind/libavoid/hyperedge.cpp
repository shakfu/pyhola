#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/debughandler.h>
#include <libavoid/geomtypes.h>
#include <libavoid/hyperedge.h>
#include <libavoid/hyperedgeimprover.h>
#include <libavoid/hyperedgetree.h>
#include <libavoid/junction.h>
#include <libavoid/obstacle.h>
#include <libavoid/router.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <libavoid/viscluster.h>
#include <list>
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

void bind_libavoid_hyperedge(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Avoid::HyperedgeRerouter file:libavoid/hyperedge.h line:129
		pybind11::class_<Avoid::HyperedgeRerouter, std::shared_ptr<Avoid::HyperedgeRerouter>> cl(M("Avoid"), "HyperedgeRerouter", "The HyperedgeRerouter class is a convenience object that can be\n          used to register hyperedges to be rerouted, improving the\n          placement of their junctions and connector paths.\n\n To work with this class, you should get a copy from the router instance\n via a call to Router::hyperedgeRerouter().\n\n If you would like a particular hyperedge to be completely rerouted with\n new junction positions then you should register it with this class via a\n call to registerHyperedgeForRerouting.  A hyperedge can either be\n specified as a set of terminal vertices, or as a single JunctionRef.\n Passing a JunctionRef will cause HyperedgeRerouter to follow the attached\n connectors and junctions to determine the hyperedge.  When you register\n a hyperedge you get an index number that can be used to later find\n information about it.\n\n The rerouting will actually occur the next time the Router processes a\n transaction, see Router::processTransaction().  The rerouting will\n effectively create new junctions (JunctionRefs) and connectors (ConnRefs)\n for the hyperedge.  \n\n Since hyperedges are composed of multiple connections and junction objects,\n rerouting a hyperedge can cause creation of new or deletion of existing \n connectors and/or junctions.  Thus once the transaction has been completed\n you should call the newAndDeletedObjectLists() to get an object containing\n the lists of created and deleted junctions and connectors.  After the\n transaction You should not use references to these deleted objects any \n more from your own code (since the router will free their memory at its\n convenience) and you should refer only to the unaffected objects and the \n new connectors and junctions.");
		cl.def( pybind11::init( [](){ return new Avoid::HyperedgeRerouter(); } ) );
		cl.def( pybind11::init( [](Avoid::HyperedgeRerouter const &o){ return new Avoid::HyperedgeRerouter(o); } ) );
		cl.def("registerHyperedgeForRerouting", (unsigned long (Avoid::HyperedgeRerouter::*)(class Avoid::JunctionRef *)) &Avoid::HyperedgeRerouter::registerHyperedgeForRerouting, "Registers a hyperedge to be fully rerouted the next time\n         the router processes a transaction.\n\n In this case the connectors and junctions attached to the given\n junction will be traversed to determine the endpoints of the\n hyperedge.  These endpoints will then be used for the rerouting.\n The junctions and connectors forming the old route will be\n deleted.\n\n \n  One of the junctions that forms the\n                      hyperedge.\n \n\n An index that can be used to request information on the\n         resulting routing of the hyperedge.\n\nC++: Avoid::HyperedgeRerouter::registerHyperedgeForRerouting(class Avoid::JunctionRef *) --> unsigned long", pybind11::arg("junction"));
		cl.def("newAndDeletedObjectLists", (struct Avoid::HyperedgeNewAndDeletedObjectLists (Avoid::HyperedgeRerouter::*)(unsigned long) const) &Avoid::HyperedgeRerouter::newAndDeletedObjectLists, "Returns a HyperedgeNewAndDeletedObjectLists detailing the\n         lists of junctions and connectors created and deleted\n         during hyperedge improvement.\n\n This method will only return information once the router has\n processed the transaction.  You should read this information \n before processTransaction() is called again.\n\n After calling this you should no longer refer to any of the\n objects in the \"deleted\" lists --- the router will delete these \n and free their memory at its convenience.\n\n \n  The index of the hyperedge to return junctions for.\n \n\n A HyperedgeNewAndDeletedObjectLists containing lists of \n         junctions and connectors created and deleted.\n\nC++: Avoid::HyperedgeRerouter::newAndDeletedObjectLists(unsigned long) const --> struct Avoid::HyperedgeNewAndDeletedObjectLists", pybind11::arg("index"));
		cl.def("count", (unsigned long (Avoid::HyperedgeRerouter::*)() const) &Avoid::HyperedgeRerouter::count, "C++: Avoid::HyperedgeRerouter::count() const --> unsigned long");
		cl.def("assign", (class Avoid::HyperedgeRerouter & (Avoid::HyperedgeRerouter::*)(const class Avoid::HyperedgeRerouter &)) &Avoid::HyperedgeRerouter::operator=, "C++: Avoid::HyperedgeRerouter::operator=(const class Avoid::HyperedgeRerouter &) --> class Avoid::HyperedgeRerouter &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::HyperedgeImprover file:libavoid/hyperedgeimprover.h line:51
		pybind11::class_<Avoid::HyperedgeImprover, std::shared_ptr<Avoid::HyperedgeImprover>> cl(M("Avoid"), "HyperedgeImprover", "");
		cl.def( pybind11::init( [](){ return new Avoid::HyperedgeImprover(); } ) );
		cl.def( pybind11::init( [](Avoid::HyperedgeImprover const &o){ return new Avoid::HyperedgeImprover(o); } ) );
		cl.def("clear", (void (Avoid::HyperedgeImprover::*)()) &Avoid::HyperedgeImprover::clear, "C++: Avoid::HyperedgeImprover::clear() --> void");
		cl.def("setRouter", (void (Avoid::HyperedgeImprover::*)(class Avoid::Router *)) &Avoid::HyperedgeImprover::setRouter, "C++: Avoid::HyperedgeImprover::setRouter(class Avoid::Router *) --> void", pybind11::arg("router"));
		cl.def("newAndDeletedObjectLists", (struct Avoid::HyperedgeNewAndDeletedObjectLists (Avoid::HyperedgeImprover::*)() const) &Avoid::HyperedgeImprover::newAndDeletedObjectLists, "C++: Avoid::HyperedgeImprover::newAndDeletedObjectLists() const --> struct Avoid::HyperedgeNewAndDeletedObjectLists");
		cl.def("execute", (void (Avoid::HyperedgeImprover::*)(bool)) &Avoid::HyperedgeImprover::execute, "C++: Avoid::HyperedgeImprover::execute(bool) --> void", pybind11::arg("canMakeMajorChanges"));
		cl.def("assign", (class Avoid::HyperedgeImprover & (Avoid::HyperedgeImprover::*)(const class Avoid::HyperedgeImprover &)) &Avoid::HyperedgeImprover::operator=, "C++: Avoid::HyperedgeImprover::operator=(const class Avoid::HyperedgeImprover &) --> class Avoid::HyperedgeImprover &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Avoid::HyperedgeTreeNode file:libavoid/hyperedgetree.h line:64
		pybind11::class_<Avoid::HyperedgeTreeNode, std::shared_ptr<Avoid::HyperedgeTreeNode>> cl(M("Avoid"), "HyperedgeTreeNode", "");
		cl.def( pybind11::init( [](){ return new Avoid::HyperedgeTreeNode(); } ) );
		cl.def( pybind11::init( [](Avoid::HyperedgeTreeNode const &o){ return new Avoid::HyperedgeTreeNode(o); } ) );
		cl.def_readwrite("edges", &Avoid::HyperedgeTreeNode::edges);
		cl.def_readwrite("point", &Avoid::HyperedgeTreeNode::point);
		cl.def_readwrite("isConnectorSource", &Avoid::HyperedgeTreeNode::isConnectorSource);
		cl.def_readwrite("isPinDummyEndpoint", &Avoid::HyperedgeTreeNode::isPinDummyEndpoint);
		cl.def_readwrite("visited", &Avoid::HyperedgeTreeNode::visited);
		cl.def("deleteEdgesExcept", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *)) &Avoid::HyperedgeTreeNode::deleteEdgesExcept, "C++: Avoid::HyperedgeTreeNode::deleteEdgesExcept(struct Avoid::HyperedgeTreeEdge *) --> void", pybind11::arg("ignored"));
		cl.def("removeOtherJunctionsFrom", (bool (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *, class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &)) &Avoid::HyperedgeTreeNode::removeOtherJunctionsFrom, "C++: Avoid::HyperedgeTreeNode::removeOtherJunctionsFrom(struct Avoid::HyperedgeTreeEdge *, class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &) --> bool", pybind11::arg("ignored"), pybind11::arg("treeRoots"));
		cl.def("outputEdgesExcept", (void (Avoid::HyperedgeTreeNode::*)(struct __sFILE *, struct Avoid::HyperedgeTreeEdge *)) &Avoid::HyperedgeTreeNode::outputEdgesExcept, "C++: Avoid::HyperedgeTreeNode::outputEdgesExcept(struct __sFILE *, struct Avoid::HyperedgeTreeEdge *) --> void", pybind11::arg("fp"), pybind11::arg("ignored"));
		cl.def("disconnectEdge", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *)) &Avoid::HyperedgeTreeNode::disconnectEdge, "C++: Avoid::HyperedgeTreeNode::disconnectEdge(struct Avoid::HyperedgeTreeEdge *) --> void", pybind11::arg("edge"));
		cl.def("spliceEdgesFrom", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeNode::spliceEdgesFrom, "C++: Avoid::HyperedgeTreeNode::spliceEdgesFrom(struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("oldNode"));
		cl.def("writeEdgesToConns", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *, unsigned long)) &Avoid::HyperedgeTreeNode::writeEdgesToConns, "C++: Avoid::HyperedgeTreeNode::writeEdgesToConns(struct Avoid::HyperedgeTreeEdge *, unsigned long) --> void", pybind11::arg("ignored"), pybind11::arg("pass"));
		cl.def("addConns", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *, class Avoid::Router *, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &, class Avoid::ConnRef *)) &Avoid::HyperedgeTreeNode::addConns, "C++: Avoid::HyperedgeTreeNode::addConns(struct Avoid::HyperedgeTreeEdge *, class Avoid::Router *, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &, class Avoid::ConnRef *) --> void", pybind11::arg("ignored"), pybind11::arg("router"), pybind11::arg("oldConns"), pybind11::arg("conn"));
		cl.def("updateConnEnds", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *, bool, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &Avoid::HyperedgeTreeNode::updateConnEnds, "C++: Avoid::HyperedgeTreeNode::updateConnEnds(struct Avoid::HyperedgeTreeEdge *, bool, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> void", pybind11::arg("ignored"), pybind11::arg("forward"), pybind11::arg("changedConns"));
		cl.def("listJunctionsAndConnectors", (void (Avoid::HyperedgeTreeNode::*)(struct Avoid::HyperedgeTreeEdge *, class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &Avoid::HyperedgeTreeNode::listJunctionsAndConnectors, "C++: Avoid::HyperedgeTreeNode::listJunctionsAndConnectors(struct Avoid::HyperedgeTreeEdge *, class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> void", pybind11::arg("ignored"), pybind11::arg("junctions"), pybind11::arg("connectors"));
		cl.def("isImmovable", (bool (Avoid::HyperedgeTreeNode::*)() const) &Avoid::HyperedgeTreeNode::isImmovable, "C++: Avoid::HyperedgeTreeNode::isImmovable() const --> bool");
		cl.def("validateHyperedge", (void (Avoid::HyperedgeTreeNode::*)(const struct Avoid::HyperedgeTreeEdge *, const unsigned long) const) &Avoid::HyperedgeTreeNode::validateHyperedge, "C++: Avoid::HyperedgeTreeNode::validateHyperedge(const struct Avoid::HyperedgeTreeEdge *, const unsigned long) const --> void", pybind11::arg("ignored"), pybind11::arg("dist"));
	}
	{ // Avoid::HyperedgeTreeEdge file:libavoid/hyperedgetree.h line:96
		pybind11::class_<Avoid::HyperedgeTreeEdge, std::shared_ptr<Avoid::HyperedgeTreeEdge>> cl(M("Avoid"), "HyperedgeTreeEdge", "");
		cl.def( pybind11::init<struct Avoid::HyperedgeTreeNode *, struct Avoid::HyperedgeTreeNode *, class Avoid::ConnRef *>(), pybind11::arg("node1"), pybind11::arg("node2"), pybind11::arg("conn") );

		cl.def( pybind11::init( [](Avoid::HyperedgeTreeEdge const &o){ return new Avoid::HyperedgeTreeEdge(o); } ) );
		cl.def_readwrite("ends", &Avoid::HyperedgeTreeEdge::ends);
		cl.def_readwrite("hasFixedRoute", &Avoid::HyperedgeTreeEdge::hasFixedRoute);
		cl.def("followFrom", (struct Avoid::HyperedgeTreeNode * (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *) const) &Avoid::HyperedgeTreeEdge::followFrom, "C++: Avoid::HyperedgeTreeEdge::followFrom(struct Avoid::HyperedgeTreeNode *) const --> struct Avoid::HyperedgeTreeNode *", pybind11::return_value_policy::automatic, pybind11::arg("from"));
		cl.def("zeroLength", (bool (Avoid::HyperedgeTreeEdge::*)() const) &Avoid::HyperedgeTreeEdge::zeroLength, "C++: Avoid::HyperedgeTreeEdge::zeroLength() const --> bool");
		cl.def("splitFromNodeAtPoint", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, const class Avoid::Point &)) &Avoid::HyperedgeTreeEdge::splitFromNodeAtPoint, "C++: Avoid::HyperedgeTreeEdge::splitFromNodeAtPoint(struct Avoid::HyperedgeTreeNode *, const class Avoid::Point &) --> void", pybind11::arg("source"), pybind11::arg("point"));
		cl.def("hasOrientation", (bool (Avoid::HyperedgeTreeEdge::*)(const unsigned long) const) &Avoid::HyperedgeTreeEdge::hasOrientation, "C++: Avoid::HyperedgeTreeEdge::hasOrientation(const unsigned long) const --> bool", pybind11::arg("dimension"));
		cl.def("outputNodesExcept", (void (Avoid::HyperedgeTreeEdge::*)(struct __sFILE *, struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeEdge::outputNodesExcept, "C++: Avoid::HyperedgeTreeEdge::outputNodesExcept(struct __sFILE *, struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("file"), pybind11::arg("ignored"));
		cl.def("deleteNodesExcept", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeEdge::deleteNodesExcept, "C++: Avoid::HyperedgeTreeEdge::deleteNodesExcept(struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("ignored"));
		cl.def("removeOtherJunctionsFrom", (bool (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &)) &Avoid::HyperedgeTreeEdge::removeOtherJunctionsFrom, "C++: Avoid::HyperedgeTreeEdge::removeOtherJunctionsFrom(struct Avoid::HyperedgeTreeNode *, class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &) --> bool", pybind11::arg("ignored"), pybind11::arg("treeRoots"));
		cl.def("writeEdgesToConns", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, unsigned long)) &Avoid::HyperedgeTreeEdge::writeEdgesToConns, "C++: Avoid::HyperedgeTreeEdge::writeEdgesToConns(struct Avoid::HyperedgeTreeNode *, unsigned long) --> void", pybind11::arg("ignored"), pybind11::arg("pass"));
		cl.def("addConns", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, class Avoid::Router *, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &Avoid::HyperedgeTreeEdge::addConns, "C++: Avoid::HyperedgeTreeEdge::addConns(struct Avoid::HyperedgeTreeNode *, class Avoid::Router *, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> void", pybind11::arg("ignored"), pybind11::arg("router"), pybind11::arg("oldConns"));
		cl.def("updateConnEnds", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, bool, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &Avoid::HyperedgeTreeEdge::updateConnEnds, "C++: Avoid::HyperedgeTreeEdge::updateConnEnds(struct Avoid::HyperedgeTreeNode *, bool, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> void", pybind11::arg("ignored"), pybind11::arg("forward"), pybind11::arg("changedConns"));
		cl.def("disconnectEdge", (void (Avoid::HyperedgeTreeEdge::*)()) &Avoid::HyperedgeTreeEdge::disconnectEdge, "C++: Avoid::HyperedgeTreeEdge::disconnectEdge() --> void");
		cl.def("replaceNode", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, struct Avoid::HyperedgeTreeNode *)) &Avoid::HyperedgeTreeEdge::replaceNode, "C++: Avoid::HyperedgeTreeEdge::replaceNode(struct Avoid::HyperedgeTreeNode *, struct Avoid::HyperedgeTreeNode *) --> void", pybind11::arg("oldNode"), pybind11::arg("newNode"));
		cl.def("listJunctionsAndConnectors", (void (Avoid::HyperedgeTreeEdge::*)(struct Avoid::HyperedgeTreeNode *, class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &Avoid::HyperedgeTreeEdge::listJunctionsAndConnectors, "C++: Avoid::HyperedgeTreeEdge::listJunctionsAndConnectors(struct Avoid::HyperedgeTreeNode *, class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &, class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> void", pybind11::arg("ignored"), pybind11::arg("junctions"), pybind11::arg("connectors"));
		cl.def("validateHyperedge", (void (Avoid::HyperedgeTreeEdge::*)(const struct Avoid::HyperedgeTreeNode *, const unsigned long) const) &Avoid::HyperedgeTreeEdge::validateHyperedge, "C++: Avoid::HyperedgeTreeEdge::validateHyperedge(const struct Avoid::HyperedgeTreeNode *, const unsigned long) const --> void", pybind11::arg("ignored"), pybind11::arg("dist"));
	}
}
