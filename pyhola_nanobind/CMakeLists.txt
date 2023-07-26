
set(PYHOLA_LIBS ${CMAKE_SOURCE_DIR}/libs)
set(PYHOLA_INCLUDE ${CMAKE_SOURCE_DIR}/include)


# Detect the installed nanobind package and import it into CMake
execute_process(
    COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE NB_DIR)
list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")
find_package(nanobind CONFIG REQUIRED)


nanobind_add_module(pyhola_nano pyhola.nanobind.cpp)


target_include_directories(pyhola_nano
    PUBLIC
    ${PYHOLA_INCLUDE}
)

target_link_directories(pyhola_nano
    PUBLIC
    ${PYHOLA_LIBS}
)

target_link_libraries(pyhola_nano
    PUBLIC
    ${PYHOLA_LIBS}/libavoid.a 
    ${PYHOLA_LIBS}/libcola.a
    ${PYHOLA_LIBS}/libdialect.a
    ${PYHOLA_LIBS}/libtopology.a
    ${PYHOLA_LIBS}/libvpsc.a
)

