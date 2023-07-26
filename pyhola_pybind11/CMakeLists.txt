
set(PYHOLA_LIBS ${CMAKE_SOURCE_DIR}/libs)
set(PYHOLA_INCLUDE ${CMAKE_SOURCE_DIR}/include)


find_package(pybind11 REQUIRED)

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

