add_library(stringflatset_bench OBJECT)

target_sources(stringflatset_bench
    PRIVATE
        stringflatset_bench.cpp)

target_link_libraries(stringflatset_bench
    PRIVATE
        benchmark::benchmark
        stringset)

