# google benchmark

fetchcontent_declare(googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.5
)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

fetchcontent_makeavailable(googlebenchmark)

add_executable(bench)

target_sources(bench
    PRIVATE
        benchmark.cpp)

add_subdirectory(stringflatset)
add_subdirectory(stringhashset)

target_link_libraries(bench
    PRIVATE
        benchmark::benchmark
        stringflatset_bench
        stringhashset_bench)
