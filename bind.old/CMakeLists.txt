
set(PYHOLA_LIBS ${CMAKE_SOURCE_DIR}/libs)
set(PYHOLA_INCLUDE ${CMAKE_SOURCE_DIR}/include)


find_package(pybind11 REQUIRED)

pybind11_add_module(pyhola_binder
    pyhola.cpp
    _stdio.cpp
    # -------------------------------
    # libavoid
    libavoid/connectionpin.cpp
    libavoid/connector.cpp
    libavoid/geometry.cpp
    libavoid/geomtypes.cpp
    libavoid/hyperedgeimprover.cpp
    libavoid/scanline.cpp
    libavoid/shape.cpp
    libavoid/vertices.cpp
    libavoid/viscluster.cpp
    libavoid/vpsc.cpp
    # -------------------------------
    # libcola
    libcola/box.cpp
    # libcola/cc_nonoverlapconstraints.cpp
    libcola/cola.cpp
    libcola/commondefs.cpp
    libcola/compound_constraints.cpp
    libcola/compound_constraints_1.cpp
    libcola/connected_components.cpp
    libcola/exceptions.cpp
    libcola/gradient_projection.cpp
    libcola/sparse_matrix.cpp
    libcola/straightener.cpp
    # -------------------------------
    # libdialect
    libdialect/aca.cpp
    # libdialect/chains.cpp
    libdialect/constraints.cpp
    libdialect/constraints_1.cpp
    libdialect/expansion.cpp
    libdialect/faces.cpp
    libdialect/graphs.cpp
    libdialect/logging.cpp
    # libdialect/nodeconfig.cpp
    # libdialect/opts.cpp
    libdialect/planarise.cpp
    libdialect/trees.cpp
    libdialect/util.cpp
    # -------------------------------
    # libprojects
    libproject/util.cpp
    # -------------------------------
    # libtopology
    libtopology/cola_topology_addon.cpp
    libtopology/topology_constraints.cpp
    libtopology/util.cpp
    # -------------------------------
    #libvpsc
    libvpsc/block.cpp
    libvpsc/blocks.cpp
    libvpsc/cbuffer.cpp
    libvpsc/rectangle.cpp
    libvpsc/solve_VPSC.cpp
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

