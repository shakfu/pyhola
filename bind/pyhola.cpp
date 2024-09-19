#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind__stdio(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_pseudorandom(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_straightener(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_aca(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_chains(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_constraints(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_constraints_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_faces(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_graphs(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_graphs_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_hola(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_opts(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_peeling(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_quadaction(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_trees(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libtopology_cola_topology_addon(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libtopology_topology_graph(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libvpsc_block(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libvpsc_rectangle(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(pyhola, root_module) {
	root_module.doc() = "pyhola module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {"nonlocal", "global", };

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			else return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "cola"},
		{"", "dialect"},
		{"", "straightener"},
		{"", "topology"},
		{"", "vpsc"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind__stdio(M);
	bind_libcola_pseudorandom(M);
	bind_libcola_straightener(M);
	bind_libdialect_aca(M);
	bind_libdialect_chains(M);
	bind_libdialect_constraints(M);
	bind_libdialect_constraints_1(M);
	bind_libdialect_faces(M);
	bind_libdialect_graphs(M);
	bind_libdialect_graphs_1(M);
	bind_libdialect_hola(M);
	bind_libdialect_opts(M);
	bind_libdialect_peeling(M);
	bind_libdialect_quadaction(M);
	bind_libdialect_trees(M);
	bind_libtopology_cola_topology_addon(M);
	bind_libtopology_topology_graph(M);
	bind_libvpsc_block(M);
	bind_libvpsc_rectangle(M);

}
