
set(PYHOLA_LIBS ${CMAKE_SOURCE_DIR}/libs)
set(PYHOLA_INCLUDE ${CMAKE_SOURCE_DIR}/include)


find_package(pybind11 REQUIRED)

pybind11_add_module(pyhola_binder
    pyhola.cpp
    _stdio.cpp
    libavoid/geomtypes.cpp
    libavoid/geometry.cpp
    libavoid/connectionpin.cpp
    libavoid/vertices.cpp
    libavoid/connector.cpp
    libavoid/hyperedgeimprover.cpp
    libavoid/shape.cpp
    libavoid/viscluster.cpp
    libavoid/scanline.cpp
    libavoid/vpsc.cpp
    libvpsc/rectangle.cpp
    libcola/box.cpp
    libvpsc/block.cpp
    libcola/sparse_matrix.cpp
    libcola/compound_constraints.cpp
    libcola/compound_constraints_1.cpp
    libvpsc/solve_VPSC.cpp
    libcola/commondefs.cpp
    libcola/gradient_projection.cpp
    libcola/straightener.cpp
    libcola/exceptions.cpp
    libcola/cola.cpp
    libcola/connected_components.cpp
    libdialect/util.cpp
    libdialect/constraints.cpp
    libdialect/constraints_1.cpp
    libdialect/graphs.cpp
    libdialect/aca.cpp
    libdialect/faces.cpp
    libdialect/expansion.cpp
    libdialect/planarise.cpp
    libproject/util.cpp
    libtopology/util.cpp
    libtopology/cola_topology_addon.cpp
    libvpsc/cbuffer.cpp
    libvpsc/blocks.cpp
)


target_include_directories(pyhola_binder
    PUBLIC
    ${PYHOLA_INCLUDE}
)

target_link_directories(pyhola_binder
    PUBLIC
    ${PYHOLA_LIBS}
)

target_link_libraries(pyhola_binder
    PUBLIC
    ${PYHOLA_LIBS}/libavoid.a 
    ${PYHOLA_LIBS}/libcola.a
    ${PYHOLA_LIBS}/libdialect.a
    ${PYHOLA_LIBS}/libtopology.a
    ${PYHOLA_LIBS}/libvpsc.a
)

