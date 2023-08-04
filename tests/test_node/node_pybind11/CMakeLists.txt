find_package(pybind11 REQUIRED)

pybind11_add_module(node_pybind node_pybind11.cpp)

target_include_directories(node_pybind
	PUBLIC
	${CMAKE_SOURCE_DIR}
)

