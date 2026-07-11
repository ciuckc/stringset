include(GoogleTest)

add_executable(stringhashset_test)

target_sources(stringhashset_test
    PUBLIC
        stringhashset_test.cpp)

target_link_libraries(stringhashset_test
    PRIVATE
        GTest::gtest_main
        stringset)

gtest_discover_tests(stringhashset_test)
