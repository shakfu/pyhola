#include <libavoid/actioninfo.h>
#include <libavoid/connectionpin.h>
#include <libavoid/connector.h>
#include <libavoid/connend.h>
#include <libavoid/geomtypes.h>
#include <libavoid/graph.h>
#include <libavoid/junction.h>
#include <libavoid/obstacle.h>
#include <libavoid/router.h>
#include <libavoid/scanline.h>
#include <libavoid/shape.h>
#include <libavoid/vertices.h>
#include <list>
#include <memory>
#include <sstream> // __str__
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

void bind_std_list(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::list file:list line:834
		pybind11::class_<std::list<Avoid::ConnRef *>, std::shared_ptr<std::list<Avoid::ConnRef *>>> cl(M("std"), "list_Avoid_ConnRef_*_t", "");
		cl.def( pybind11::init( [](){ return new std::list<Avoid::ConnRef *>(); } ) );
		cl.def( pybind11::init<const class std::allocator<class Avoid::ConnRef *> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long>(), pybind11::arg("__n") );

		cl.def( pybind11::init<unsigned long, class Avoid::ConnRef *const &>(), pybind11::arg("__n"), pybind11::arg("__x") );

		cl.def( pybind11::init<unsigned long, class Avoid::ConnRef *const &, const class std::allocator<class Avoid::ConnRef *> &>(), pybind11::arg("__n"), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::list<Avoid::ConnRef *> const &o){ return new std::list<Avoid::ConnRef *>(o); } ) );
		cl.def( pybind11::init<const class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &, const class std::allocator<class Avoid::ConnRef *> &>(), pybind11::arg("__c"), pybind11::arg("__a") );

		cl.def("assign", (class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > & (std::list<Avoid::ConnRef *>::*)(const class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &std::list<Avoid::ConnRef *>::operator=, "C++: std::list<Avoid::ConnRef *>::operator=(const class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("assign", (void (std::list<Avoid::ConnRef *>::*)(unsigned long, class Avoid::ConnRef *const &)) &std::list<Avoid::ConnRef *>::assign, "C++: std::list<Avoid::ConnRef *>::assign(unsigned long, class Avoid::ConnRef *const &) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("get_allocator", (class std::allocator<class Avoid::ConnRef *> (std::list<Avoid::ConnRef *>::*)() const) &std::list<Avoid::ConnRef *>::get_allocator, "C++: std::list<Avoid::ConnRef *>::get_allocator() const --> class std::allocator<class Avoid::ConnRef *>");
		cl.def("size", (unsigned long (std::list<Avoid::ConnRef *>::*)() const) &std::list<Avoid::ConnRef *>::size, "C++: std::list<Avoid::ConnRef *>::size() const --> unsigned long");
		cl.def("empty", (bool (std::list<Avoid::ConnRef *>::*)() const) &std::list<Avoid::ConnRef *>::empty, "C++: std::list<Avoid::ConnRef *>::empty() const --> bool");
		cl.def("max_size", (unsigned long (std::list<Avoid::ConnRef *>::*)() const) &std::list<Avoid::ConnRef *>::max_size, "C++: std::list<Avoid::ConnRef *>::max_size() const --> unsigned long");
		cl.def("front", (class Avoid::ConnRef *& (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::front, "C++: std::list<Avoid::ConnRef *>::front() --> class Avoid::ConnRef *&", pybind11::return_value_policy::automatic);
		cl.def("back", (class Avoid::ConnRef *& (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::back, "C++: std::list<Avoid::ConnRef *>::back() --> class Avoid::ConnRef *&", pybind11::return_value_policy::automatic);
		cl.def("push_front", (void (std::list<Avoid::ConnRef *>::*)(class Avoid::ConnRef *const &)) &std::list<Avoid::ConnRef *>::push_front, "C++: std::list<Avoid::ConnRef *>::push_front(class Avoid::ConnRef *const &) --> void", pybind11::arg("__x"));
		cl.def("push_back", (void (std::list<Avoid::ConnRef *>::*)(class Avoid::ConnRef *const &)) &std::list<Avoid::ConnRef *>::push_back, "C++: std::list<Avoid::ConnRef *>::push_back(class Avoid::ConnRef *const &) --> void", pybind11::arg("__x"));
		cl.def("swap", (void (std::list<Avoid::ConnRef *>::*)(class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &std::list<Avoid::ConnRef *>::swap, "C++: std::list<Avoid::ConnRef *>::swap(class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> void", pybind11::arg("__c"));
		cl.def("clear", (void (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::clear, "C++: std::list<Avoid::ConnRef *>::clear() --> void");
		cl.def("pop_front", (void (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::pop_front, "C++: std::list<Avoid::ConnRef *>::pop_front() --> void");
		cl.def("pop_back", (void (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::pop_back, "C++: std::list<Avoid::ConnRef *>::pop_back() --> void");
		cl.def("resize", (void (std::list<Avoid::ConnRef *>::*)(unsigned long)) &std::list<Avoid::ConnRef *>::resize, "C++: std::list<Avoid::ConnRef *>::resize(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("resize", (void (std::list<Avoid::ConnRef *>::*)(unsigned long, class Avoid::ConnRef *const &)) &std::list<Avoid::ConnRef *>::resize, "C++: std::list<Avoid::ConnRef *>::resize(unsigned long, class Avoid::ConnRef *const &) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("remove", (void (std::list<Avoid::ConnRef *>::*)(class Avoid::ConnRef *const &)) &std::list<Avoid::ConnRef *>::remove, "C++: std::list<Avoid::ConnRef *>::remove(class Avoid::ConnRef *const &) --> void", pybind11::arg("__x"));
		cl.def("unique", (void (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::unique, "C++: std::list<Avoid::ConnRef *>::unique() --> void");
		cl.def("merge", (void (std::list<Avoid::ConnRef *>::*)(class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &)) &std::list<Avoid::ConnRef *>::merge, "C++: std::list<Avoid::ConnRef *>::merge(class std::list<class Avoid::ConnRef *, class std::allocator<class Avoid::ConnRef *> > &) --> void", pybind11::arg("__c"));
		cl.def("sort", (void (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::sort, "C++: std::list<Avoid::ConnRef *>::sort() --> void");
		cl.def("reverse", (void (std::list<Avoid::ConnRef *>::*)()) &std::list<Avoid::ConnRef *>::reverse, "C++: std::list<Avoid::ConnRef *>::reverse() --> void");
		cl.def("__invariants", (bool (std::list<Avoid::ConnRef *>::*)() const) &std::list<Avoid::ConnRef *>::__invariants, "C++: std::list<Avoid::ConnRef *>::__invariants() const --> bool");
		cl.def("__allocate_node", (class std::unique_ptr<struct std::__list_node<class Avoid::ConnRef *, void *>, class std::__allocator_destructor<class std::allocator<struct std::__list_node<class Avoid::ConnRef *, void *> > > > (std::list<Avoid::ConnRef *>::*)(class std::allocator<struct std::__list_node<class Avoid::ConnRef *, void *> > &)) &std::list<Avoid::ConnRef *>::__allocate_node, "C++: std::list<Avoid::ConnRef *>::__allocate_node(class std::allocator<struct std::__list_node<class Avoid::ConnRef *, void *> > &) --> class std::unique_ptr<struct std::__list_node<class Avoid::ConnRef *, void *>, class std::__allocator_destructor<class std::allocator<struct std::__list_node<class Avoid::ConnRef *, void *> > > >", pybind11::arg("__na"));
	}
	{ // std::list file:list line:834
		pybind11::class_<std::list<Avoid::JunctionRef *>, std::shared_ptr<std::list<Avoid::JunctionRef *>>> cl(M("std"), "list_Avoid_JunctionRef_*_t", "");
		cl.def( pybind11::init( [](){ return new std::list<Avoid::JunctionRef *>(); } ) );
		cl.def( pybind11::init<const class std::allocator<class Avoid::JunctionRef *> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long>(), pybind11::arg("__n") );

		cl.def( pybind11::init<unsigned long, class Avoid::JunctionRef *const &>(), pybind11::arg("__n"), pybind11::arg("__x") );

		cl.def( pybind11::init<unsigned long, class Avoid::JunctionRef *const &, const class std::allocator<class Avoid::JunctionRef *> &>(), pybind11::arg("__n"), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::list<Avoid::JunctionRef *> const &o){ return new std::list<Avoid::JunctionRef *>(o); } ) );
		cl.def( pybind11::init<const class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &, const class std::allocator<class Avoid::JunctionRef *> &>(), pybind11::arg("__c"), pybind11::arg("__a") );

		cl.def("assign", (class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > & (std::list<Avoid::JunctionRef *>::*)(const class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &)) &std::list<Avoid::JunctionRef *>::operator=, "C++: std::list<Avoid::JunctionRef *>::operator=(const class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &) --> class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("assign", (void (std::list<Avoid::JunctionRef *>::*)(unsigned long, class Avoid::JunctionRef *const &)) &std::list<Avoid::JunctionRef *>::assign, "C++: std::list<Avoid::JunctionRef *>::assign(unsigned long, class Avoid::JunctionRef *const &) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("get_allocator", (class std::allocator<class Avoid::JunctionRef *> (std::list<Avoid::JunctionRef *>::*)() const) &std::list<Avoid::JunctionRef *>::get_allocator, "C++: std::list<Avoid::JunctionRef *>::get_allocator() const --> class std::allocator<class Avoid::JunctionRef *>");
		cl.def("size", (unsigned long (std::list<Avoid::JunctionRef *>::*)() const) &std::list<Avoid::JunctionRef *>::size, "C++: std::list<Avoid::JunctionRef *>::size() const --> unsigned long");
		cl.def("empty", (bool (std::list<Avoid::JunctionRef *>::*)() const) &std::list<Avoid::JunctionRef *>::empty, "C++: std::list<Avoid::JunctionRef *>::empty() const --> bool");
		cl.def("max_size", (unsigned long (std::list<Avoid::JunctionRef *>::*)() const) &std::list<Avoid::JunctionRef *>::max_size, "C++: std::list<Avoid::JunctionRef *>::max_size() const --> unsigned long");
		cl.def("front", (class Avoid::JunctionRef *& (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::front, "C++: std::list<Avoid::JunctionRef *>::front() --> class Avoid::JunctionRef *&", pybind11::return_value_policy::automatic);
		cl.def("back", (class Avoid::JunctionRef *& (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::back, "C++: std::list<Avoid::JunctionRef *>::back() --> class Avoid::JunctionRef *&", pybind11::return_value_policy::automatic);
		cl.def("push_front", (void (std::list<Avoid::JunctionRef *>::*)(class Avoid::JunctionRef *const &)) &std::list<Avoid::JunctionRef *>::push_front, "C++: std::list<Avoid::JunctionRef *>::push_front(class Avoid::JunctionRef *const &) --> void", pybind11::arg("__x"));
		cl.def("push_back", (void (std::list<Avoid::JunctionRef *>::*)(class Avoid::JunctionRef *const &)) &std::list<Avoid::JunctionRef *>::push_back, "C++: std::list<Avoid::JunctionRef *>::push_back(class Avoid::JunctionRef *const &) --> void", pybind11::arg("__x"));
		cl.def("swap", (void (std::list<Avoid::JunctionRef *>::*)(class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &)) &std::list<Avoid::JunctionRef *>::swap, "C++: std::list<Avoid::JunctionRef *>::swap(class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &) --> void", pybind11::arg("__c"));
		cl.def("clear", (void (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::clear, "C++: std::list<Avoid::JunctionRef *>::clear() --> void");
		cl.def("pop_front", (void (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::pop_front, "C++: std::list<Avoid::JunctionRef *>::pop_front() --> void");
		cl.def("pop_back", (void (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::pop_back, "C++: std::list<Avoid::JunctionRef *>::pop_back() --> void");
		cl.def("resize", (void (std::list<Avoid::JunctionRef *>::*)(unsigned long)) &std::list<Avoid::JunctionRef *>::resize, "C++: std::list<Avoid::JunctionRef *>::resize(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("resize", (void (std::list<Avoid::JunctionRef *>::*)(unsigned long, class Avoid::JunctionRef *const &)) &std::list<Avoid::JunctionRef *>::resize, "C++: std::list<Avoid::JunctionRef *>::resize(unsigned long, class Avoid::JunctionRef *const &) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("remove", (void (std::list<Avoid::JunctionRef *>::*)(class Avoid::JunctionRef *const &)) &std::list<Avoid::JunctionRef *>::remove, "C++: std::list<Avoid::JunctionRef *>::remove(class Avoid::JunctionRef *const &) --> void", pybind11::arg("__x"));
		cl.def("unique", (void (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::unique, "C++: std::list<Avoid::JunctionRef *>::unique() --> void");
		cl.def("merge", (void (std::list<Avoid::JunctionRef *>::*)(class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &)) &std::list<Avoid::JunctionRef *>::merge, "C++: std::list<Avoid::JunctionRef *>::merge(class std::list<class Avoid::JunctionRef *, class std::allocator<class Avoid::JunctionRef *> > &) --> void", pybind11::arg("__c"));
		cl.def("sort", (void (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::sort, "C++: std::list<Avoid::JunctionRef *>::sort() --> void");
		cl.def("reverse", (void (std::list<Avoid::JunctionRef *>::*)()) &std::list<Avoid::JunctionRef *>::reverse, "C++: std::list<Avoid::JunctionRef *>::reverse() --> void");
		cl.def("__invariants", (bool (std::list<Avoid::JunctionRef *>::*)() const) &std::list<Avoid::JunctionRef *>::__invariants, "C++: std::list<Avoid::JunctionRef *>::__invariants() const --> bool");
		cl.def("__allocate_node", (class std::unique_ptr<struct std::__list_node<class Avoid::JunctionRef *, void *>, class std::__allocator_destructor<class std::allocator<struct std::__list_node<class Avoid::JunctionRef *, void *> > > > (std::list<Avoid::JunctionRef *>::*)(class std::allocator<struct std::__list_node<class Avoid::JunctionRef *, void *> > &)) &std::list<Avoid::JunctionRef *>::__allocate_node, "C++: std::list<Avoid::JunctionRef *>::__allocate_node(class std::allocator<struct std::__list_node<class Avoid::JunctionRef *, void *> > &) --> class std::unique_ptr<struct std::__list_node<class Avoid::JunctionRef *, void *>, class std::__allocator_destructor<class std::allocator<struct std::__list_node<class Avoid::JunctionRef *, void *> > > >", pybind11::arg("__na"));
	}
	{ // std::list file:list line:834
		pybind11::class_<std::list<Avoid::ShiftSegment *>, std::shared_ptr<std::list<Avoid::ShiftSegment *>>> cl(M("std"), "list_Avoid_ShiftSegment_*_t", "");
		cl.def( pybind11::init( [](){ return new std::list<Avoid::ShiftSegment *>(); } ) );
		cl.def( pybind11::init<const class std::allocator<class Avoid::ShiftSegment *> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long>(), pybind11::arg("__n") );

		cl.def( pybind11::init<unsigned long, class Avoid::ShiftSegment *const &>(), pybind11::arg("__n"), pybind11::arg("__x") );

		cl.def( pybind11::init<unsigned long, class Avoid::ShiftSegment *const &, const class std::allocator<class Avoid::ShiftSegment *> &>(), pybind11::arg("__n"), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::list<Avoid::ShiftSegment *> const &o){ return new std::list<Avoid::ShiftSegment *>(o); } ) );
		cl.def( pybind11::init<const class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &, const class std::allocator<class Avoid::ShiftSegment *> &>(), pybind11::arg("__c"), pybind11::arg("__a") );

		cl.def("assign", (class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > & (std::list<Avoid::ShiftSegment *>::*)(const class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &)) &std::list<Avoid::ShiftSegment *>::operator=, "C++: std::list<Avoid::ShiftSegment *>::operator=(const class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &) --> class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("assign", (void (std::list<Avoid::ShiftSegment *>::*)(unsigned long, class Avoid::ShiftSegment *const &)) &std::list<Avoid::ShiftSegment *>::assign, "C++: std::list<Avoid::ShiftSegment *>::assign(unsigned long, class Avoid::ShiftSegment *const &) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("get_allocator", (class std::allocator<class Avoid::ShiftSegment *> (std::list<Avoid::ShiftSegment *>::*)() const) &std::list<Avoid::ShiftSegment *>::get_allocator, "C++: std::list<Avoid::ShiftSegment *>::get_allocator() const --> class std::allocator<class Avoid::ShiftSegment *>");
		cl.def("size", (unsigned long (std::list<Avoid::ShiftSegment *>::*)() const) &std::list<Avoid::ShiftSegment *>::size, "C++: std::list<Avoid::ShiftSegment *>::size() const --> unsigned long");
		cl.def("empty", (bool (std::list<Avoid::ShiftSegment *>::*)() const) &std::list<Avoid::ShiftSegment *>::empty, "C++: std::list<Avoid::ShiftSegment *>::empty() const --> bool");
		cl.def("max_size", (unsigned long (std::list<Avoid::ShiftSegment *>::*)() const) &std::list<Avoid::ShiftSegment *>::max_size, "C++: std::list<Avoid::ShiftSegment *>::max_size() const --> unsigned long");
		cl.def("front", (class Avoid::ShiftSegment *& (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::front, "C++: std::list<Avoid::ShiftSegment *>::front() --> class Avoid::ShiftSegment *&", pybind11::return_value_policy::automatic);
		cl.def("back", (class Avoid::ShiftSegment *& (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::back, "C++: std::list<Avoid::ShiftSegment *>::back() --> class Avoid::ShiftSegment *&", pybind11::return_value_policy::automatic);
		cl.def("push_front", (void (std::list<Avoid::ShiftSegment *>::*)(class Avoid::ShiftSegment *const &)) &std::list<Avoid::ShiftSegment *>::push_front, "C++: std::list<Avoid::ShiftSegment *>::push_front(class Avoid::ShiftSegment *const &) --> void", pybind11::arg("__x"));
		cl.def("push_back", (void (std::list<Avoid::ShiftSegment *>::*)(class Avoid::ShiftSegment *const &)) &std::list<Avoid::ShiftSegment *>::push_back, "C++: std::list<Avoid::ShiftSegment *>::push_back(class Avoid::ShiftSegment *const &) --> void", pybind11::arg("__x"));
		cl.def("swap", (void (std::list<Avoid::ShiftSegment *>::*)(class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &)) &std::list<Avoid::ShiftSegment *>::swap, "C++: std::list<Avoid::ShiftSegment *>::swap(class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &) --> void", pybind11::arg("__c"));
		cl.def("clear", (void (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::clear, "C++: std::list<Avoid::ShiftSegment *>::clear() --> void");
		cl.def("pop_front", (void (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::pop_front, "C++: std::list<Avoid::ShiftSegment *>::pop_front() --> void");
		cl.def("pop_back", (void (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::pop_back, "C++: std::list<Avoid::ShiftSegment *>::pop_back() --> void");
		cl.def("resize", (void (std::list<Avoid::ShiftSegment *>::*)(unsigned long)) &std::list<Avoid::ShiftSegment *>::resize, "C++: std::list<Avoid::ShiftSegment *>::resize(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("resize", (void (std::list<Avoid::ShiftSegment *>::*)(unsigned long, class Avoid::ShiftSegment *const &)) &std::list<Avoid::ShiftSegment *>::resize, "C++: std::list<Avoid::ShiftSegment *>::resize(unsigned long, class Avoid::ShiftSegment *const &) --> void", pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("remove", (void (std::list<Avoid::ShiftSegment *>::*)(class Avoid::ShiftSegment *const &)) &std::list<Avoid::ShiftSegment *>::remove, "C++: std::list<Avoid::ShiftSegment *>::remove(class Avoid::ShiftSegment *const &) --> void", pybind11::arg("__x"));
		cl.def("unique", (void (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::unique, "C++: std::list<Avoid::ShiftSegment *>::unique() --> void");
		cl.def("merge", (void (std::list<Avoid::ShiftSegment *>::*)(class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &)) &std::list<Avoid::ShiftSegment *>::merge, "C++: std::list<Avoid::ShiftSegment *>::merge(class std::list<class Avoid::ShiftSegment *, class std::allocator<class Avoid::ShiftSegment *> > &) --> void", pybind11::arg("__c"));
		cl.def("sort", (void (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::sort, "C++: std::list<Avoid::ShiftSegment *>::sort() --> void");
		cl.def("reverse", (void (std::list<Avoid::ShiftSegment *>::*)()) &std::list<Avoid::ShiftSegment *>::reverse, "C++: std::list<Avoid::ShiftSegment *>::reverse() --> void");
		cl.def("__invariants", (bool (std::list<Avoid::ShiftSegment *>::*)() const) &std::list<Avoid::ShiftSegment *>::__invariants, "C++: std::list<Avoid::ShiftSegment *>::__invariants() const --> bool");
		cl.def("__allocate_node", (class std::unique_ptr<struct std::__list_node<class Avoid::ShiftSegment *, void *>, class std::__allocator_destructor<class std::allocator<struct std::__list_node<class Avoid::ShiftSegment *, void *> > > > (std::list<Avoid::ShiftSegment *>::*)(class std::allocator<struct std::__list_node<class Avoid::ShiftSegment *, void *> > &)) &std::list<Avoid::ShiftSegment *>::__allocate_node, "C++: std::list<Avoid::ShiftSegment *>::__allocate_node(class std::allocator<struct std::__list_node<class Avoid::ShiftSegment *, void *> > &) --> class std::unique_ptr<struct std::__list_node<class Avoid::ShiftSegment *, void *>, class std::__allocator_destructor<class std::allocator<struct std::__list_node<class Avoid::ShiftSegment *, void *> > > >", pybind11::arg("__na"));
	}
}
