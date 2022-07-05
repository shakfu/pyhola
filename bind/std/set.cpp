#include <functional>
#include <iterator>
#include <libavoid/connector.h>
#include <libavoid/graph.h>
#include <libavoid/junction.h>
#include <libavoid/scanline.h>
#include <memory>
#include <set>
#include <sstream> // __str__
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

void bind_std_set(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::set file:set line:443
		pybind11::class_<std::set<unsigned int>, std::shared_ptr<std::set<unsigned int>>> cl(M("std"), "set_unsigned_int_t", "");
		cl.def( pybind11::init( [](){ return new std::set<unsigned int>(); } ) );
		cl.def( pybind11::init<const struct std::less<unsigned int> &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<unsigned int> &, const class std::allocator<unsigned int> &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::set<unsigned int> const &o){ return new std::set<unsigned int>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<unsigned int> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &, const class std::allocator<unsigned int> &>(), pybind11::arg("__s"), pybind11::arg("__a") );

		cl.def("assign", (class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > & (std::set<unsigned int>::*)(const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &)) &std::set<unsigned int>::operator=, "C++: std::set<unsigned int>::operator=(const class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &) --> class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &", pybind11::return_value_policy::automatic, pybind11::arg("__s"));
		cl.def("empty", (bool (std::set<unsigned int>::*)() const) &std::set<unsigned int>::empty, "C++: std::set<unsigned int>::empty() const --> bool");
		cl.def("size", (unsigned long (std::set<unsigned int>::*)() const) &std::set<unsigned int>::size, "C++: std::set<unsigned int>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::set<unsigned int>::*)() const) &std::set<unsigned int>::max_size, "C++: std::set<unsigned int>::max_size() const --> unsigned long");
		cl.def("insert", (struct std::pair<class std::__tree_const_iterator<unsigned int, class std::__tree_node<unsigned int, void *> *, long>, bool> (std::set<unsigned int>::*)(const unsigned int &)) &std::set<unsigned int>::insert, "C++: std::set<unsigned int>::insert(const unsigned int &) --> struct std::pair<class std::__tree_const_iterator<unsigned int, class std::__tree_node<unsigned int, void *> *, long>, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::set<unsigned int>::*)(const unsigned int &)) &std::set<unsigned int>::erase, "C++: std::set<unsigned int>::erase(const unsigned int &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::set<unsigned int>::*)()) &std::set<unsigned int>::clear, "C++: std::set<unsigned int>::clear() --> void");
		cl.def("swap", (void (std::set<unsigned int>::*)(class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &)) &std::set<unsigned int>::swap, "C++: std::set<unsigned int>::swap(class std::set<unsigned int, struct std::less<unsigned int>, class std::allocator<unsigned int> > &) --> void", pybind11::arg("__s"));
		cl.def("get_allocator", (class std::allocator<unsigned int> (std::set<unsigned int>::*)() const) &std::set<unsigned int>::get_allocator, "C++: std::set<unsigned int>::get_allocator() const --> class std::allocator<unsigned int>");
		cl.def("key_comp", (struct std::less<unsigned int> (std::set<unsigned int>::*)() const) &std::set<unsigned int>::key_comp, "C++: std::set<unsigned int>::key_comp() const --> struct std::less<unsigned int>");
		cl.def("value_comp", (struct std::less<unsigned int> (std::set<unsigned int>::*)() const) &std::set<unsigned int>::value_comp, "C++: std::set<unsigned int>::value_comp() const --> struct std::less<unsigned int>");
		cl.def("count", (unsigned long (std::set<unsigned int>::*)(const unsigned int &) const) &std::set<unsigned int>::count, "C++: std::set<unsigned int>::count(const unsigned int &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__tree_const_iterator<unsigned int, class std::__tree_node<unsigned int, void *> *, long>, class std::__tree_const_iterator<unsigned int, class std::__tree_node<unsigned int, void *> *, long> > (std::set<unsigned int>::*)(const unsigned int &)) &std::set<unsigned int>::equal_range, "C++: std::set<unsigned int>::equal_range(const unsigned int &) --> struct std::pair<class std::__tree_const_iterator<unsigned int, class std::__tree_node<unsigned int, void *> *, long>, class std::__tree_const_iterator<unsigned int, class std::__tree_node<unsigned int, void *> *, long> >", pybind11::arg("__k"));
	}
	{ // std::set file:set line:443
		pybind11::class_<std::set<Avoid::VertInf *>, std::shared_ptr<std::set<Avoid::VertInf *>>> cl(M("std"), "set_Avoid_VertInf_*_t", "");
		cl.def( pybind11::init( [](){ return new std::set<Avoid::VertInf *>(); } ) );
		cl.def( pybind11::init<const struct std::less<class Avoid::VertInf *> &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<class Avoid::VertInf *> &, const class std::allocator<class Avoid::VertInf *> &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::set<Avoid::VertInf *> const &o){ return new std::set<Avoid::VertInf *>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<class Avoid::VertInf *> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::set<class Avoid::VertInf *, struct std::less<class Avoid::VertInf *>, class std::allocator<class Avoid::VertInf *> > &, const class std::allocator<class Avoid::VertInf *> &>(), pybind11::arg("__s"), pybind11::arg("__a") );

		cl.def("assign", (class std::set<class Avoid::VertInf *, struct std::less<class Avoid::VertInf *>, class std::allocator<class Avoid::VertInf *> > & (std::set<Avoid::VertInf *>::*)(const class std::set<class Avoid::VertInf *, struct std::less<class Avoid::VertInf *>, class std::allocator<class Avoid::VertInf *> > &)) &std::set<Avoid::VertInf *>::operator=, "C++: std::set<Avoid::VertInf *>::operator=(const class std::set<class Avoid::VertInf *, struct std::less<class Avoid::VertInf *>, class std::allocator<class Avoid::VertInf *> > &) --> class std::set<class Avoid::VertInf *, struct std::less<class Avoid::VertInf *>, class std::allocator<class Avoid::VertInf *> > &", pybind11::return_value_policy::automatic, pybind11::arg("__s"));
		cl.def("empty", (bool (std::set<Avoid::VertInf *>::*)() const) &std::set<Avoid::VertInf *>::empty, "C++: std::set<Avoid::VertInf *>::empty() const --> bool");
		cl.def("size", (unsigned long (std::set<Avoid::VertInf *>::*)() const) &std::set<Avoid::VertInf *>::size, "C++: std::set<Avoid::VertInf *>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::set<Avoid::VertInf *>::*)() const) &std::set<Avoid::VertInf *>::max_size, "C++: std::set<Avoid::VertInf *>::max_size() const --> unsigned long");
		cl.def("insert", (struct std::pair<class std::__tree_const_iterator<class Avoid::VertInf *, class std::__tree_node<class Avoid::VertInf *, void *> *, long>, bool> (std::set<Avoid::VertInf *>::*)(class Avoid::VertInf *const &)) &std::set<Avoid::VertInf *>::insert, "C++: std::set<Avoid::VertInf *>::insert(class Avoid::VertInf *const &) --> struct std::pair<class std::__tree_const_iterator<class Avoid::VertInf *, class std::__tree_node<class Avoid::VertInf *, void *> *, long>, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::set<Avoid::VertInf *>::*)(class Avoid::VertInf *const &)) &std::set<Avoid::VertInf *>::erase, "C++: std::set<Avoid::VertInf *>::erase(class Avoid::VertInf *const &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::set<Avoid::VertInf *>::*)()) &std::set<Avoid::VertInf *>::clear, "C++: std::set<Avoid::VertInf *>::clear() --> void");
		cl.def("swap", (void (std::set<Avoid::VertInf *>::*)(class std::set<class Avoid::VertInf *, struct std::less<class Avoid::VertInf *>, class std::allocator<class Avoid::VertInf *> > &)) &std::set<Avoid::VertInf *>::swap, "C++: std::set<Avoid::VertInf *>::swap(class std::set<class Avoid::VertInf *, struct std::less<class Avoid::VertInf *>, class std::allocator<class Avoid::VertInf *> > &) --> void", pybind11::arg("__s"));
		cl.def("get_allocator", (class std::allocator<class Avoid::VertInf *> (std::set<Avoid::VertInf *>::*)() const) &std::set<Avoid::VertInf *>::get_allocator, "C++: std::set<Avoid::VertInf *>::get_allocator() const --> class std::allocator<class Avoid::VertInf *>");
		cl.def("key_comp", (struct std::less<class Avoid::VertInf *> (std::set<Avoid::VertInf *>::*)() const) &std::set<Avoid::VertInf *>::key_comp, "C++: std::set<Avoid::VertInf *>::key_comp() const --> struct std::less<class Avoid::VertInf *>");
		cl.def("value_comp", (struct std::less<class Avoid::VertInf *> (std::set<Avoid::VertInf *>::*)() const) &std::set<Avoid::VertInf *>::value_comp, "C++: std::set<Avoid::VertInf *>::value_comp() const --> struct std::less<class Avoid::VertInf *>");
		cl.def("count", (unsigned long (std::set<Avoid::VertInf *>::*)(class Avoid::VertInf *const &) const) &std::set<Avoid::VertInf *>::count, "C++: std::set<Avoid::VertInf *>::count(class Avoid::VertInf *const &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__tree_const_iterator<class Avoid::VertInf *, class std::__tree_node<class Avoid::VertInf *, void *> *, long>, class std::__tree_const_iterator<class Avoid::VertInf *, class std::__tree_node<class Avoid::VertInf *, void *> *, long> > (std::set<Avoid::VertInf *>::*)(class Avoid::VertInf *const &)) &std::set<Avoid::VertInf *>::equal_range, "C++: std::set<Avoid::VertInf *>::equal_range(class Avoid::VertInf *const &) --> struct std::pair<class std::__tree_const_iterator<class Avoid::VertInf *, class std::__tree_node<class Avoid::VertInf *, void *> *, long>, class std::__tree_const_iterator<class Avoid::VertInf *, class std::__tree_node<class Avoid::VertInf *, void *> *, long> >", pybind11::arg("__k"));
	}
	{ // std::set file:set line:443
		pybind11::class_<std::set<Avoid::JunctionRef *>, std::shared_ptr<std::set<Avoid::JunctionRef *>>> cl(M("std"), "set_Avoid_JunctionRef_*_t", "");
		cl.def( pybind11::init( [](){ return new std::set<Avoid::JunctionRef *>(); } ) );
		cl.def( pybind11::init<const struct std::less<class Avoid::JunctionRef *> &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<class Avoid::JunctionRef *> &, const class std::allocator<class Avoid::JunctionRef *> &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::set<Avoid::JunctionRef *> const &o){ return new std::set<Avoid::JunctionRef *>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<class Avoid::JunctionRef *> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &, const class std::allocator<class Avoid::JunctionRef *> &>(), pybind11::arg("__s"), pybind11::arg("__a") );

		cl.def("assign", (class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > & (std::set<Avoid::JunctionRef *>::*)(const class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &)) &std::set<Avoid::JunctionRef *>::operator=, "C++: std::set<Avoid::JunctionRef *>::operator=(const class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &) --> class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &", pybind11::return_value_policy::automatic, pybind11::arg("__s"));
		cl.def("empty", (bool (std::set<Avoid::JunctionRef *>::*)() const) &std::set<Avoid::JunctionRef *>::empty, "C++: std::set<Avoid::JunctionRef *>::empty() const --> bool");
		cl.def("size", (unsigned long (std::set<Avoid::JunctionRef *>::*)() const) &std::set<Avoid::JunctionRef *>::size, "C++: std::set<Avoid::JunctionRef *>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::set<Avoid::JunctionRef *>::*)() const) &std::set<Avoid::JunctionRef *>::max_size, "C++: std::set<Avoid::JunctionRef *>::max_size() const --> unsigned long");
		cl.def("insert", (struct std::pair<class std::__tree_const_iterator<class Avoid::JunctionRef *, class std::__tree_node<class Avoid::JunctionRef *, void *> *, long>, bool> (std::set<Avoid::JunctionRef *>::*)(class Avoid::JunctionRef *const &)) &std::set<Avoid::JunctionRef *>::insert, "C++: std::set<Avoid::JunctionRef *>::insert(class Avoid::JunctionRef *const &) --> struct std::pair<class std::__tree_const_iterator<class Avoid::JunctionRef *, class std::__tree_node<class Avoid::JunctionRef *, void *> *, long>, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::set<Avoid::JunctionRef *>::*)(class Avoid::JunctionRef *const &)) &std::set<Avoid::JunctionRef *>::erase, "C++: std::set<Avoid::JunctionRef *>::erase(class Avoid::JunctionRef *const &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::set<Avoid::JunctionRef *>::*)()) &std::set<Avoid::JunctionRef *>::clear, "C++: std::set<Avoid::JunctionRef *>::clear() --> void");
		cl.def("swap", (void (std::set<Avoid::JunctionRef *>::*)(class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &)) &std::set<Avoid::JunctionRef *>::swap, "C++: std::set<Avoid::JunctionRef *>::swap(class std::set<class Avoid::JunctionRef *, struct std::less<class Avoid::JunctionRef *>, class std::allocator<class Avoid::JunctionRef *> > &) --> void", pybind11::arg("__s"));
		cl.def("get_allocator", (class std::allocator<class Avoid::JunctionRef *> (std::set<Avoid::JunctionRef *>::*)() const) &std::set<Avoid::JunctionRef *>::get_allocator, "C++: std::set<Avoid::JunctionRef *>::get_allocator() const --> class std::allocator<class Avoid::JunctionRef *>");
		cl.def("key_comp", (struct std::less<class Avoid::JunctionRef *> (std::set<Avoid::JunctionRef *>::*)() const) &std::set<Avoid::JunctionRef *>::key_comp, "C++: std::set<Avoid::JunctionRef *>::key_comp() const --> struct std::less<class Avoid::JunctionRef *>");
		cl.def("value_comp", (struct std::less<class Avoid::JunctionRef *> (std::set<Avoid::JunctionRef *>::*)() const) &std::set<Avoid::JunctionRef *>::value_comp, "C++: std::set<Avoid::JunctionRef *>::value_comp() const --> struct std::less<class Avoid::JunctionRef *>");
		cl.def("count", (unsigned long (std::set<Avoid::JunctionRef *>::*)(class Avoid::JunctionRef *const &) const) &std::set<Avoid::JunctionRef *>::count, "C++: std::set<Avoid::JunctionRef *>::count(class Avoid::JunctionRef *const &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__tree_const_iterator<class Avoid::JunctionRef *, class std::__tree_node<class Avoid::JunctionRef *, void *> *, long>, class std::__tree_const_iterator<class Avoid::JunctionRef *, class std::__tree_node<class Avoid::JunctionRef *, void *> *, long> > (std::set<Avoid::JunctionRef *>::*)(class Avoid::JunctionRef *const &)) &std::set<Avoid::JunctionRef *>::equal_range, "C++: std::set<Avoid::JunctionRef *>::equal_range(class Avoid::JunctionRef *const &) --> struct std::pair<class std::__tree_const_iterator<class Avoid::JunctionRef *, class std::__tree_node<class Avoid::JunctionRef *, void *> *, long>, class std::__tree_const_iterator<class Avoid::JunctionRef *, class std::__tree_node<class Avoid::JunctionRef *, void *> *, long> >", pybind11::arg("__k"));
	}
	{ // std::set file:set line:443
		pybind11::class_<std::set<cola::ShapePair>, std::shared_ptr<std::set<cola::ShapePair>>> cl(M("std"), "set_cola_ShapePair_t", "");
		cl.def( pybind11::init( [](){ return new std::set<cola::ShapePair>(); } ) );
		cl.def( pybind11::init<const struct std::less<class cola::ShapePair> &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<class cola::ShapePair> &, const class std::allocator<class cola::ShapePair> &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::set<cola::ShapePair> const &o){ return new std::set<cola::ShapePair>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<class cola::ShapePair> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::set<class cola::ShapePair, struct std::less<class cola::ShapePair>, class std::allocator<class cola::ShapePair> > &, const class std::allocator<class cola::ShapePair> &>(), pybind11::arg("__s"), pybind11::arg("__a") );

		cl.def("assign", (class std::set<class cola::ShapePair, struct std::less<class cola::ShapePair>, class std::allocator<class cola::ShapePair> > & (std::set<cola::ShapePair>::*)(const class std::set<class cola::ShapePair, struct std::less<class cola::ShapePair>, class std::allocator<class cola::ShapePair> > &)) &std::set<cola::ShapePair>::operator=, "C++: std::set<cola::ShapePair>::operator=(const class std::set<class cola::ShapePair, struct std::less<class cola::ShapePair>, class std::allocator<class cola::ShapePair> > &) --> class std::set<class cola::ShapePair, struct std::less<class cola::ShapePair>, class std::allocator<class cola::ShapePair> > &", pybind11::return_value_policy::automatic, pybind11::arg("__s"));
		cl.def("empty", (bool (std::set<cola::ShapePair>::*)() const) &std::set<cola::ShapePair>::empty, "C++: std::set<cola::ShapePair>::empty() const --> bool");
		cl.def("size", (unsigned long (std::set<cola::ShapePair>::*)() const) &std::set<cola::ShapePair>::size, "C++: std::set<cola::ShapePair>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::set<cola::ShapePair>::*)() const) &std::set<cola::ShapePair>::max_size, "C++: std::set<cola::ShapePair>::max_size() const --> unsigned long");
		cl.def("insert", (struct std::pair<class std::__tree_const_iterator<class cola::ShapePair, class std::__tree_node<class cola::ShapePair, void *> *, long>, bool> (std::set<cola::ShapePair>::*)(const class cola::ShapePair &)) &std::set<cola::ShapePair>::insert, "C++: std::set<cola::ShapePair>::insert(const class cola::ShapePair &) --> struct std::pair<class std::__tree_const_iterator<class cola::ShapePair, class std::__tree_node<class cola::ShapePair, void *> *, long>, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::set<cola::ShapePair>::*)(const class cola::ShapePair &)) &std::set<cola::ShapePair>::erase, "C++: std::set<cola::ShapePair>::erase(const class cola::ShapePair &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::set<cola::ShapePair>::*)()) &std::set<cola::ShapePair>::clear, "C++: std::set<cola::ShapePair>::clear() --> void");
		cl.def("swap", (void (std::set<cola::ShapePair>::*)(class std::set<class cola::ShapePair, struct std::less<class cola::ShapePair>, class std::allocator<class cola::ShapePair> > &)) &std::set<cola::ShapePair>::swap, "C++: std::set<cola::ShapePair>::swap(class std::set<class cola::ShapePair, struct std::less<class cola::ShapePair>, class std::allocator<class cola::ShapePair> > &) --> void", pybind11::arg("__s"));
		cl.def("get_allocator", (class std::allocator<class cola::ShapePair> (std::set<cola::ShapePair>::*)() const) &std::set<cola::ShapePair>::get_allocator, "C++: std::set<cola::ShapePair>::get_allocator() const --> class std::allocator<class cola::ShapePair>");
		cl.def("key_comp", (struct std::less<class cola::ShapePair> (std::set<cola::ShapePair>::*)() const) &std::set<cola::ShapePair>::key_comp, "C++: std::set<cola::ShapePair>::key_comp() const --> struct std::less<class cola::ShapePair>");
		cl.def("value_comp", (struct std::less<class cola::ShapePair> (std::set<cola::ShapePair>::*)() const) &std::set<cola::ShapePair>::value_comp, "C++: std::set<cola::ShapePair>::value_comp() const --> struct std::less<class cola::ShapePair>");
		cl.def("count", (unsigned long (std::set<cola::ShapePair>::*)(const class cola::ShapePair &) const) &std::set<cola::ShapePair>::count, "C++: std::set<cola::ShapePair>::count(const class cola::ShapePair &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__tree_const_iterator<class cola::ShapePair, class std::__tree_node<class cola::ShapePair, void *> *, long>, class std::__tree_const_iterator<class cola::ShapePair, class std::__tree_node<class cola::ShapePair, void *> *, long> > (std::set<cola::ShapePair>::*)(const class cola::ShapePair &)) &std::set<cola::ShapePair>::equal_range, "C++: std::set<cola::ShapePair>::equal_range(const class cola::ShapePair &) --> struct std::pair<class std::__tree_const_iterator<class cola::ShapePair, class std::__tree_node<class cola::ShapePair, void *> *, long>, class std::__tree_const_iterator<class cola::ShapePair, class std::__tree_node<class cola::ShapePair, void *> *, long> >", pybind11::arg("__k"));
	}
}
