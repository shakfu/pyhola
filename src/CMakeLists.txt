
set(ADAPTAGRAMS ${CMAKE_SOURCE_DIR}/thirdparty/adaptagrams)
set(PYHOLA_LIB ${ADAPTAGRAMS}/lib)
set(PYHOLA_INCLUDE ${ADAPTAGRAMS}/include)


# Detect the installed pybind11 package and import it into CMake
execute_process(
    COMMAND "${Python_EXECUTABLE}" -m pybind11 --cmakedir
    OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE PB_DIR)
list(APPEND CMAKE_PREFIX_PATH "${PB_DIR}")
find_package(pybind11 CONFIG REQUIRED)

# find_package(pybind11 REQUIRED)

pybind11_add_module(pyhola pyhola.cpp)

set_target_properties(pyhola PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src)

target_include_directories(pyhola
    PUBLIC
    ${PYHOLA_INCLUDE}
)

target_link_directories(pyhola
    PUBLIC
    ${PYHOLA_LIB}
)

target_link_libraries(pyhola
    PUBLIC
    ${PYHOLA_LIB}/libavoid.a 
    ${PYHOLA_LIB}/libcola.a
    ${PYHOLA_LIB}/libdialect.a
    ${PYHOLA_LIB}/libtopology.a
    ${PYHOLA_LIB}/libvpsc.a
)

