
execute_process(
    COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE NB_DIR)
list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")

find_package(nanobind CONFIG REQUIRED)


nanobind_add_module(node_nano node_nano.cpp)

target_include_directories(node_nano
    PUBLIC
    ${CMAKE_SOURCE_DIR}
)
