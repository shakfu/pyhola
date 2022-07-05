#include <functional>
#include <iterator>
#include <libproject/project.h>
#include <memory>
#include <set>
#include <sstream> // __str__
#include <string>
#include <string_view>
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

void bind_std_set_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::set file:set line:443
		pybind11::class_<std::set<std::shared_ptr<dialect::SepCo>>, std::shared_ptr<std::set<std::shared_ptr<dialect::SepCo>>>> cl(M("std"), "set_std_shared_ptr_dialect_SepCo_t", "");
		cl.def( pybind11::init( [](){ return new std::set<std::shared_ptr<dialect::SepCo>>(); } ) );
		cl.def( pybind11::init<const struct std::less<class std::shared_ptr<struct dialect::SepCo> > &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<class std::shared_ptr<struct dialect::SepCo> > &, const class std::allocator<class std::shared_ptr<struct dialect::SepCo> > &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::set<std::shared_ptr<dialect::SepCo>> const &o){ return new std::set<std::shared_ptr<dialect::SepCo>>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<class std::shared_ptr<struct dialect::SepCo> > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > &, const class std::allocator<class std::shared_ptr<struct dialect::SepCo> > &>(), pybind11::arg("__s"), pybind11::arg("__a") );

		cl.def("assign", (class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > & (std::set<std::shared_ptr<dialect::SepCo>>::*)(const class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > &)) &std::set<std::shared_ptr<dialect::SepCo>>::operator=, "C++: std::set<std::shared_ptr<dialect::SepCo>>::operator=(const class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > &) --> class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > &", pybind11::return_value_policy::automatic, pybind11::arg("__s"));
		cl.def("empty", (bool (std::set<std::shared_ptr<dialect::SepCo>>::*)() const) &std::set<std::shared_ptr<dialect::SepCo>>::empty, "C++: std::set<std::shared_ptr<dialect::SepCo>>::empty() const --> bool");
		cl.def("size", (unsigned long (std::set<std::shared_ptr<dialect::SepCo>>::*)() const) &std::set<std::shared_ptr<dialect::SepCo>>::size, "C++: std::set<std::shared_ptr<dialect::SepCo>>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::set<std::shared_ptr<dialect::SepCo>>::*)() const) &std::set<std::shared_ptr<dialect::SepCo>>::max_size, "C++: std::set<std::shared_ptr<dialect::SepCo>>::max_size() const --> unsigned long");
		cl.def("insert", (struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<struct dialect::SepCo>, class std::__tree_node<class std::shared_ptr<struct dialect::SepCo>, void *> *, long>, bool> (std::set<std::shared_ptr<dialect::SepCo>>::*)(const class std::shared_ptr<struct dialect::SepCo> &)) &std::set<std::shared_ptr<dialect::SepCo>>::insert, "C++: std::set<std::shared_ptr<dialect::SepCo>>::insert(const class std::shared_ptr<struct dialect::SepCo> &) --> struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<struct dialect::SepCo>, class std::__tree_node<class std::shared_ptr<struct dialect::SepCo>, void *> *, long>, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::set<std::shared_ptr<dialect::SepCo>>::*)(const class std::shared_ptr<struct dialect::SepCo> &)) &std::set<std::shared_ptr<dialect::SepCo>>::erase, "C++: std::set<std::shared_ptr<dialect::SepCo>>::erase(const class std::shared_ptr<struct dialect::SepCo> &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::set<std::shared_ptr<dialect::SepCo>>::*)()) &std::set<std::shared_ptr<dialect::SepCo>>::clear, "C++: std::set<std::shared_ptr<dialect::SepCo>>::clear() --> void");
		cl.def("swap", (void (std::set<std::shared_ptr<dialect::SepCo>>::*)(class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > &)) &std::set<std::shared_ptr<dialect::SepCo>>::swap, "C++: std::set<std::shared_ptr<dialect::SepCo>>::swap(class std::set<class std::shared_ptr<struct dialect::SepCo>, struct std::less<class std::shared_ptr<struct dialect::SepCo> >, class std::allocator<class std::shared_ptr<struct dialect::SepCo> > > &) --> void", pybind11::arg("__s"));
		cl.def("get_allocator", (class std::allocator<class std::shared_ptr<struct dialect::SepCo> > (std::set<std::shared_ptr<dialect::SepCo>>::*)() const) &std::set<std::shared_ptr<dialect::SepCo>>::get_allocator, "C++: std::set<std::shared_ptr<dialect::SepCo>>::get_allocator() const --> class std::allocator<class std::shared_ptr<struct dialect::SepCo> >");
		cl.def("key_comp", (struct std::less<class std::shared_ptr<struct dialect::SepCo> > (std::set<std::shared_ptr<dialect::SepCo>>::*)() const) &std::set<std::shared_ptr<dialect::SepCo>>::key_comp, "C++: std::set<std::shared_ptr<dialect::SepCo>>::key_comp() const --> struct std::less<class std::shared_ptr<struct dialect::SepCo> >");
		cl.def("value_comp", (struct std::less<class std::shared_ptr<struct dialect::SepCo> > (std::set<std::shared_ptr<dialect::SepCo>>::*)() const) &std::set<std::shared_ptr<dialect::SepCo>>::value_comp, "C++: std::set<std::shared_ptr<dialect::SepCo>>::value_comp() const --> struct std::less<class std::shared_ptr<struct dialect::SepCo> >");
		cl.def("count", (unsigned long (std::set<std::shared_ptr<dialect::SepCo>>::*)(const class std::shared_ptr<struct dialect::SepCo> &) const) &std::set<std::shared_ptr<dialect::SepCo>>::count, "C++: std::set<std::shared_ptr<dialect::SepCo>>::count(const class std::shared_ptr<struct dialect::SepCo> &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<struct dialect::SepCo>, class std::__tree_node<class std::shared_ptr<struct dialect::SepCo>, void *> *, long>, class std::__tree_const_iterator<class std::shared_ptr<struct dialect::SepCo>, class std::__tree_node<class std::shared_ptr<struct dialect::SepCo>, void *> *, long> > (std::set<std::shared_ptr<dialect::SepCo>>::*)(const class std::shared_ptr<struct dialect::SepCo> &)) &std::set<std::shared_ptr<dialect::SepCo>>::equal_range, "C++: std::set<std::shared_ptr<dialect::SepCo>>::equal_range(const class std::shared_ptr<struct dialect::SepCo> &) --> struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<struct dialect::SepCo>, class std::__tree_node<class std::shared_ptr<struct dialect::SepCo>, void *> *, long>, class std::__tree_const_iterator<class std::shared_ptr<struct dialect::SepCo>, class std::__tree_node<class std::shared_ptr<struct dialect::SepCo>, void *> *, long> >", pybind11::arg("__k"));
	}
	{ // std::set file:set line:443
		pybind11::class_<std::set<std::shared_ptr<dialect::TreePlacement>>, std::shared_ptr<std::set<std::shared_ptr<dialect::TreePlacement>>>> cl(M("std"), "set_std_shared_ptr_dialect_TreePlacement_t", "");
		cl.def( pybind11::init( [](){ return new std::set<std::shared_ptr<dialect::TreePlacement>>(); } ) );
		cl.def( pybind11::init<const struct std::less<class std::shared_ptr<class dialect::TreePlacement> > &>(), pybind11::arg("__comp") );

		cl.def( pybind11::init<const struct std::less<class std::shared_ptr<class dialect::TreePlacement> > &, const class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::set<std::shared_ptr<dialect::TreePlacement>> const &o){ return new std::set<std::shared_ptr<dialect::TreePlacement>>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > &, const class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > &>(), pybind11::arg("__s"), pybind11::arg("__a") );

		cl.def("assign", (class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > & (std::set<std::shared_ptr<dialect::TreePlacement>>::*)(const class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > &)) &std::set<std::shared_ptr<dialect::TreePlacement>>::operator=, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::operator=(const class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > &) --> class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > &", pybind11::return_value_policy::automatic, pybind11::arg("__s"));
		cl.def("empty", (bool (std::set<std::shared_ptr<dialect::TreePlacement>>::*)() const) &std::set<std::shared_ptr<dialect::TreePlacement>>::empty, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::empty() const --> bool");
		cl.def("size", (unsigned long (std::set<std::shared_ptr<dialect::TreePlacement>>::*)() const) &std::set<std::shared_ptr<dialect::TreePlacement>>::size, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::set<std::shared_ptr<dialect::TreePlacement>>::*)() const) &std::set<std::shared_ptr<dialect::TreePlacement>>::max_size, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::max_size() const --> unsigned long");
		cl.def("insert", (struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<class dialect::TreePlacement>, class std::__tree_node<class std::shared_ptr<class dialect::TreePlacement>, void *> *, long>, bool> (std::set<std::shared_ptr<dialect::TreePlacement>>::*)(const class std::shared_ptr<class dialect::TreePlacement> &)) &std::set<std::shared_ptr<dialect::TreePlacement>>::insert, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::insert(const class std::shared_ptr<class dialect::TreePlacement> &) --> struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<class dialect::TreePlacement>, class std::__tree_node<class std::shared_ptr<class dialect::TreePlacement>, void *> *, long>, bool>", pybind11::arg("__v"));
		cl.def("erase", (unsigned long (std::set<std::shared_ptr<dialect::TreePlacement>>::*)(const class std::shared_ptr<class dialect::TreePlacement> &)) &std::set<std::shared_ptr<dialect::TreePlacement>>::erase, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::erase(const class std::shared_ptr<class dialect::TreePlacement> &) --> unsigned long", pybind11::arg("__k"));
		cl.def("clear", (void (std::set<std::shared_ptr<dialect::TreePlacement>>::*)()) &std::set<std::shared_ptr<dialect::TreePlacement>>::clear, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::clear() --> void");
		cl.def("swap", (void (std::set<std::shared_ptr<dialect::TreePlacement>>::*)(class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > &)) &std::set<std::shared_ptr<dialect::TreePlacement>>::swap, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::swap(class std::set<class std::shared_ptr<class dialect::TreePlacement>, struct std::less<class std::shared_ptr<class dialect::TreePlacement> >, class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > > &) --> void", pybind11::arg("__s"));
		cl.def("get_allocator", (class std::allocator<class std::shared_ptr<class dialect::TreePlacement> > (std::set<std::shared_ptr<dialect::TreePlacement>>::*)() const) &std::set<std::shared_ptr<dialect::TreePlacement>>::get_allocator, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::get_allocator() const --> class std::allocator<class std::shared_ptr<class dialect::TreePlacement> >");
		cl.def("key_comp", (struct std::less<class std::shared_ptr<class dialect::TreePlacement> > (std::set<std::shared_ptr<dialect::TreePlacement>>::*)() const) &std::set<std::shared_ptr<dialect::TreePlacement>>::key_comp, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::key_comp() const --> struct std::less<class std::shared_ptr<class dialect::TreePlacement> >");
		cl.def("value_comp", (struct std::less<class std::shared_ptr<class dialect::TreePlacement> > (std::set<std::shared_ptr<dialect::TreePlacement>>::*)() const) &std::set<std::shared_ptr<dialect::TreePlacement>>::value_comp, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::value_comp() const --> struct std::less<class std::shared_ptr<class dialect::TreePlacement> >");
		cl.def("count", (unsigned long (std::set<std::shared_ptr<dialect::TreePlacement>>::*)(const class std::shared_ptr<class dialect::TreePlacement> &) const) &std::set<std::shared_ptr<dialect::TreePlacement>>::count, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::count(const class std::shared_ptr<class dialect::TreePlacement> &) const --> unsigned long", pybind11::arg("__k"));
		cl.def("equal_range", (struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<class dialect::TreePlacement>, class std::__tree_node<class std::shared_ptr<class dialect::TreePlacement>, void *> *, long>, class std::__tree_const_iterator<class std::shared_ptr<class dialect::TreePlacement>, class std::__tree_node<class std::shared_ptr<class dialect::TreePlacement>, void *> *, long> > (std::set<std::shared_ptr<dialect::TreePlacement>>::*)(const class std::shared_ptr<class dialect::TreePlacement> &)) &std::set<std::shared_ptr<dialect::TreePlacement>>::equal_range, "C++: std::set<std::shared_ptr<dialect::TreePlacement>>::equal_range(const class std::shared_ptr<class dialect::TreePlacement> &) --> struct std::pair<class std::__tree_const_iterator<class std::shared_ptr<class dialect::TreePlacement>, class std::__tree_node<class std::shared_ptr<class dialect::TreePlacement>, void *> *, long>, class std::__tree_const_iterator<class std::shared_ptr<class dialect::TreePlacement>, class std::__tree_node<class std::shared_ptr<class dialect::TreePlacement>, void *> *, long> >", pybind11::arg("__k"));
	}
}
