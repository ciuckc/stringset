cmake_minimum_required(VERSION 3.22)

project(stringset
    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build test" ON)
option(BUILD_BENCH "Build benchmark" OFF)

add_subdirectory(src)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tst)
endif()

if(BUILD_BENCH)
    add_subdirectory(bench EXCLUDE_FROM_ALL)
endif()

