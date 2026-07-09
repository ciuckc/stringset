cmake_minimum_required(VERSION 3.22)

project(stringset
    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(Dependencies)

enable_testing()

add_subdirectory(src)

add_subdirectory(tst)
