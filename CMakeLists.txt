cmake_minimum_required(VERSION 3.18...3.22)

project(pyhola_project)

option(BUILD_PYHOLA_BINDER "enable pyhola binder version")
option(BUILD_PYHOLA_NANO "enable pyhola nanobind version (non-functional)")

find_package(Python 3.8 COMPONENTS Interpreter Development.Module REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# add subprojects
add_subdirectory(pyhola_pybind11)

if(BUILD_PYHOLA_BINDER)
add_subdirectory(bind)
endif()


if(BUILD_PYHOLA_NANO)
add_subdirectory(pyhola_nanobind)
endif()