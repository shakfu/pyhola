
set(PYHOLA_LIBS ${CMAKE_SOURCE_DIR}/libs)
set(PYHOLA_INCLUDE ${CMAKE_SOURCE_DIR}/include)


# Detect the installed pybind11 package and import it into CMake
execute_process(
    COMMAND "${Python_EXECUTABLE}" -m pybind11 --cmakedir
    OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE PB_DIR)
list(APPEND CMAKE_PREFIX_PATH "${PB_DIR}")
find_package(pybind11 CONFIG REQUIRED)

# find_package(pybind11 REQUIRED)

pybind11_add_module(pyhola pyhola.pybind11.cpp)


target_include_directories(pyhola
    PUBLIC
    ${PYHOLA_INCLUDE}
)

target_link_directories(pyhola
    PUBLIC
    ${PYHOLA_LIBS}
)

target_link_libraries(pyhola
    PUBLIC
    ${PYHOLA_LIBS}/libavoid.a 
    ${PYHOLA_LIBS}/libcola.a
    ${PYHOLA_LIBS}/libdialect.a
    ${PYHOLA_LIBS}/libtopology.a
    ${PYHOLA_LIBS}/libvpsc.a
)

