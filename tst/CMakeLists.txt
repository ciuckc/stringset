include(GoogleTest)

add_executable(stringset_test)

target_sources(stringset_test
    PUBLIC
        stringset_test.cpp)

target_link_libraries(stringset_test
    PRIVATE
        GTest::gtest_main
        stringset)

gtest_discover_tests(stringset_test)

