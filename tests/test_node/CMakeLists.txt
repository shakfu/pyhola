cmake_minimum_required(VERSION 3.18...3.22)

project(test_node_project)

find_package(Python 3.8 COMPONENTS Interpreter Development.Module REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(node_pybind11)
add_subdirectory(node_nanobind)

