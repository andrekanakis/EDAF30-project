# Run debug with cmake -DCMAKE_BUILD_TYPE=Debug .. && make
# Run release with  cmake -DCMAKE_BUILD_TYPE=Release .. && make

cmake_minimum_required(VERSION 3.10)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectId})

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build (Debug/Release)" FORCE)
endif()

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(
    -Wall
    -Werror
    -Wextra
    -pedantic-errors
)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(main main.cc node.cc edge.cc nodeset.cc graph.cc )
add_executable(test_smapp test/test_graph_small.cc node.cc edge.cc)
add_executable(test_nodeset node.cc nodeset.cc edge.cc test/test_nodeset.cc)
add_executable(test_dijkstra node.cc nodeset.cc edge.cc test/test_dijkstra.cc)
add_executable(test_nofile graph.cc node.cc edge.cc nodeset.cc test/test_graph_nofile.cc)
add_executable(test_general node.cc edge.cc nodeset.cc graph.cc test/test.cc) 

add_custom_target(run_all_tests
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_smapp
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_nodeset
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_dijkstra
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_nofile
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_general
)
