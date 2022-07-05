#include <_stdio.h>
#include <functional>
#include <iterator>
#include <libavoid/connector.h>
#include <libavoid/graph.h>
#include <libavoid/hyperedgetree.h>
#include <libavoid/junction.h>
#include <libcola/box.h>
#include <libcola/cc_nonoverlapconstraints.h>
#include <list>
#include <map>
#include <memory>
#include <set>
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

void bind_std_map(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::map file:map line:898
		pybind11::class_<std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>, std::shared_ptr<std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>>> cl(M("std"), "map_Avoid_JunctionRef_*_Avoid_HyperedgeTreeNode_*_std_less_Avoid_JunctionRef_*_std_allocator_std_pair_Avoid_JunctionRef_*const_Avoid_HyperedgeTreeNode_*_t", "");
		cl.def( pybind11::init( [](){ return new std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>(); } ) );
		cl.def( pybind11::init<const struct std::less<class Avoid::JunctionRef *> &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<class Avoid::JunctionRef *> &, const class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >> const &o){ return new std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::map<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > > &, const class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > &>(), pybind11::arg("__m"), pybind11::arg("__a") );

		cl.def("assign", (class std::map<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > > & (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(const class std::map<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > > &)) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::operator=, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::operator=(const class std::map<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > > &) --> class std::map<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > > &", pybind11::return_value_policy::automatic, pybind11::arg("__m"));
		cl.def("empty", (bool (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)() const) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::empty, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::empty() const --> bool");
		cl.def("size", (unsigned long (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)() const) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::size, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)() const) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::max_size, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::max_size() const --> unsigned long");
		cl.def("__getitem__", (struct Avoid::HyperedgeTreeNode *& (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(class Avoid::JunctionRef *const &)) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::operator[], "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::operator[](class Avoid::JunctionRef *const &) --> struct Avoid::HyperedgeTreeNode *&", pybind11::return_value_policy::automatic, pybind11::arg("__k"));
		cl.def("at", (struct Avoid::HyperedgeTreeNode *& (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(class Avoid::JunctionRef *const &)) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::at, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::at(class Avoid::JunctionRef *const &) --> struct Avoid::HyperedgeTreeNode *&", pybind11::return_value_policy::automatic, pybind11::arg("__k"));
		cl.def("get_allocator", (class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)() const) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::get_allocator, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::get_allocator() const --> class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> >");
		cl.def("key_comp", (struct std::less<class Avoid::JunctionRef *> (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)() const) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::key_comp, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::key_comp() const --> struct std::less<class Avoid::JunctionRef *>");
		cl.def("insert", (struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, class std::__tree_node<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, void *> *, long> >, bool> (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(const struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> &)) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::insert, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::insert(const struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> &) --> struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, class std::__tree_node<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, void *> *, long> >, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(class Avoid::JunctionRef *const &)) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::erase, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::erase(class Avoid::JunctionRef *const &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)()) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::clear, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::clear() --> void");
		cl.def("swap", (void (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(class std::map<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > > &)) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::swap, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::swap(class std::map<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<struct std::pair<class Avoid::JunctionRef *const, struct Avoid::HyperedgeTreeNode *> > > &) --> void", pybind11::arg("__m"));
		cl.def("count", (unsigned long (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(class Avoid::JunctionRef *const &) const) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::count, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::count(class Avoid::JunctionRef *const &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, class std::__tree_node<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, void *> *, long> >, class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, class std::__tree_node<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, void *> *, long> > > (std::map<Avoid::JunctionRef *,Avoid::HyperedgeTreeNode *,std::less<Avoid::JunctionRef *>,std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> >>::*)(class Avoid::JunctionRef *const &)) &std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::equal_range, "C++: std::map<Avoid::JunctionRef *, Avoid::HyperedgeTreeNode *, std::less<Avoid::JunctionRef *>, std::allocator<std::pair<Avoid::JunctionRef *const, Avoid::HyperedgeTreeNode *> > >::equal_range(class Avoid::JunctionRef *const &) --> struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, class std::__tree_node<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, void *> *, long> >, class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, class std::__tree_node<struct std::__value_type<class Avoid::JunctionRef *, struct Avoid::HyperedgeTreeNode *>, void *> *, long> > >", pybind11::arg("__k"));
	}
	{ // std::map file:map line:898
		pybind11::class_<std::map<unsigned int,std::shared_ptr<dialect::Node>>, std::shared_ptr<std::map<unsigned int,std::shared_ptr<dialect::Node>>>> cl(M("std"), "map_unsigned_int_std_shared_ptr_dialect_Node_t", "");
		cl.def( pybind11::init( [](){ return new std::map<unsigned int,std::shared_ptr<dialect::Node>>(); } ) );
		cl.def( pybind11::init<const struct std::less<unsigned int> &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<unsigned int> &, const class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::map<unsigned int,std::shared_ptr<dialect::Node>> const &o){ return new std::map<unsigned int,std::shared_ptr<dialect::Node>>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &, const class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > &>(), pybind11::arg("__m"), pybind11::arg("__a") );

		cl.def("assign", (class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > & (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &)) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::operator=, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::operator=(const class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &) --> class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &", pybind11::return_value_policy::automatic, pybind11::arg("__m"));
		cl.def("empty", (bool (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)() const) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::empty, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::empty() const --> bool");
		cl.def("size", (unsigned long (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)() const) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::size, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)() const) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::max_size, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::max_size() const --> unsigned long");
		cl.def("__getitem__", (class std::shared_ptr<class dialect::Node> & (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(const unsigned int &)) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::operator[], "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::operator[](const unsigned int &) --> class std::shared_ptr<class dialect::Node> &", pybind11::return_value_policy::automatic, pybind11::arg("__k"));
		cl.def("at", (class std::shared_ptr<class dialect::Node> & (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(const unsigned int &)) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::at, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::at(const unsigned int &) --> class std::shared_ptr<class dialect::Node> &", pybind11::return_value_policy::automatic, pybind11::arg("__k"));
		cl.def("get_allocator", (class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)() const) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::get_allocator, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::get_allocator() const --> class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > >");
		cl.def("key_comp", (struct std::less<unsigned int> (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)() const) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::key_comp, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::key_comp() const --> struct std::less<unsigned int>");
		cl.def("insert", (struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, class std::__tree_node<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, void *> *, long> >, bool> (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(const struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > &)) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::insert, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::insert(const struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > &) --> struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, class std::__tree_node<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, void *> *, long> >, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(const unsigned int &)) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::erase, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::erase(const unsigned int &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)()) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::clear, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::clear() --> void");
		cl.def("swap", (void (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &)) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::swap, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::swap(class std::map<unsigned int, class std::shared_ptr<class dialect::Node>, struct std::less<unsigned int>, class std::allocator<struct std::pair<const unsigned int, class std::shared_ptr<class dialect::Node> > > > &) --> void", pybind11::arg("__m"));
		cl.def("count", (unsigned long (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(const unsigned int &) const) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::count, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::count(const unsigned int &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, class std::__tree_node<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, void *> *, long> >, class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, class std::__tree_node<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, void *> *, long> > > (std::map<unsigned int,std::shared_ptr<dialect::Node>>::*)(const unsigned int &)) &std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::equal_range, "C++: std::map<unsigned int, std::shared_ptr<dialect::Node>, std::less<unsigned int>, std::allocator<std::pair<const unsigned int, std::shared_ptr<dialect::Node> > > >::equal_range(const unsigned int &) --> struct std::pair<class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, class std::__tree_node<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, void *> *, long> >, class std::__map_iterator<class std::__tree_iterator<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, class std::__tree_node<struct std::__value_type<unsigned int, class std::shared_ptr<class dialect::Node> >, void *> *, long> > >", pybind11::arg("__k"));
	}
}
