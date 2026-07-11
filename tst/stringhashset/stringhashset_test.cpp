#include "gtest/gtest.h"

#include "stringhashset/stringhashset.hpp"

TEST(StringHashSetBasic, BasicTest) {
    containers::StringHashSet set{};

    EXPECT_TRUE(set.add("a"));
    EXPECT_TRUE(set.add("b"));
    EXPECT_TRUE(set.contains("a"));
    EXPECT_TRUE(set.contains("b"));
}
