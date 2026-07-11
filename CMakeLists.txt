cmake_minimum_required(VERSION 3.22)

project(stringflatset
    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build test" ON)

add_subdirectory(src)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tst EXCLUDE_FROM_ALL)
endif()


