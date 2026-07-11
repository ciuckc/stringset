include(GoogleTest)

add_executable(stringflatset_test)

target_sources(stringflatset_test
    PUBLIC
        stringflatset_test.cpp)

target_link_libraries(stringflatset_test
    PRIVATE
        GTest::gtest_main
        stringset)

gtest_discover_tests(stringflatset_test)
