add_library(stringhashset_bench OBJECT)

target_sources(stringhashset_bench
    PRIVATE
        stringhashset_bench.cpp)

target_link_libraries(stringhashset_bench
    PRIVATE
        benchmark::benchmark
        stringset)
