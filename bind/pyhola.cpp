#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_std_exception(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind__stdio(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_unknown_unknown_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_vertices(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_connector(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_hyperedge(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_hyperedgetree(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_router(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_viscluster(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_scanline(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_vpsc(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libvpsc_rectangle(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_box(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libvpsc_block(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_valarray(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_valarray_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_valarray_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_sparse_matrix(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_compound_constraints(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_compound_constraints_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libvpsc_solve_VPSC(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_commondefs(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_gradient_projection(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_straightener(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_exceptions(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_cola(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libcola_connected_components(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_util(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_constraints(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_constraints_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_routing(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_graphs(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_aca(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_chains(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_faces(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_treeplacement(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_expansion(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_quadaction(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libdialect_planarise(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libproject_util(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libtopology_util(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libtopology_orthogonal_topology(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libvpsc_cbuffer(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libvpsc_blocks(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_sstream(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_string(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_list(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_geomtypes(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_geometry(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_map(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_map_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_map_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_map_3(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_set(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_set_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_libavoid_connectionpin(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_system_error(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std___locale(std::function< pybind11::module &(std::string const &namespace_) > &M);


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
		{"", "Avoid"},
		{"", "cola"},
		{"", "dialect"},
		{"", "project"},
		{"", "std"},
		{"", "straightener"},
		{"", "topology"},
		{"", "vpsc"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_std_exception(M);
	bind__stdio(M);
	bind_std_unknown_unknown(M);
	bind_std_unknown_unknown_1(M);
	bind_libavoid_vertices(M);
	bind_libavoid_connector(M);
	bind_libavoid_hyperedge(M);
	bind_libavoid_hyperedgetree(M);
	bind_libavoid_router(M);
	bind_libavoid_viscluster(M);
	bind_libavoid_scanline(M);
	bind_libavoid_vpsc(M);
	bind_libvpsc_rectangle(M);
	bind_libcola_box(M);
	bind_libvpsc_block(M);
	bind_std_valarray(M);
	bind_std_valarray_1(M);
	bind_std_valarray_2(M);
	bind_libcola_sparse_matrix(M);
	bind_libcola_compound_constraints(M);
	bind_libcola_compound_constraints_1(M);
	bind_libvpsc_solve_VPSC(M);
	bind_libcola_commondefs(M);
	bind_libcola_gradient_projection(M);
	bind_libcola_straightener(M);
	bind_libcola_exceptions(M);
	bind_libcola_cola(M);
	bind_libcola_connected_components(M);
	bind_libdialect_util(M);
	bind_libdialect_constraints(M);
	bind_libdialect_constraints_1(M);
	bind_libdialect_routing(M);
	bind_libdialect_graphs(M);
	bind_libdialect_aca(M);
	bind_libdialect_chains(M);
	bind_libdialect_faces(M);
	bind_libdialect_treeplacement(M);
	bind_libdialect_expansion(M);
	bind_libdialect_quadaction(M);
	bind_libdialect_planarise(M);
	bind_libproject_util(M);
	bind_libtopology_util(M);
	bind_libtopology_orthogonal_topology(M);
	bind_libvpsc_cbuffer(M);
	bind_libvpsc_blocks(M);
	bind_std_sstream(M);
	bind_std_string(M);
	bind_std_list(M);
	bind_libavoid_geomtypes(M);
	bind_libavoid_geometry(M);
	bind_std_map(M);
	bind_std_map_1(M);
	bind_std_map_2(M);
	bind_std_map_3(M);
	bind_std_set(M);
	bind_std_set_1(M);
	bind_libavoid_connectionpin(M);
	bind_std_system_error(M);
	bind_std___locale(M);

}
