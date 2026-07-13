#include "gtest/gtest.h"

#include "stringhashset/stringhashset.hpp"

TEST(StringHashSetContains, ContainsReturnsFalseOnNotFound) {
    containers::StringHashSet set{};

    EXPECT_FALSE(set.contains("a"));
}

TEST(StringHashSetAdd, AddReturnsTrueOnFirstAdd) {
    containers::StringHashSet set{};

    EXPECT_TRUE(set.add("a"));
}

TEST(StringHashSetAdd, AddReturnsFalseOnSecondSimilarAdd) {
    containers::StringHashSet set{};

    EXPECT_TRUE(set.add("a"));
    EXPECT_FALSE(set.add("a"));
}

TEST(StringHashSetAddContains, AddReturnsTrueOnAddingPastTheInitialBucketCount) {
    containers::StringHashSet set{4};

    EXPECT_TRUE(set.add("a"));
    EXPECT_TRUE(set.add("4ac"));
    EXPECT_TRUE(set.add("booleans"));
    EXPECT_TRUE(set.add("same thing"));
    EXPECT_TRUE(set.add("same thing other"));
    EXPECT_TRUE(set.add("same thing other than that"));
    EXPECT_TRUE(set.add("same thing other than anything"));
    EXPECT_TRUE(set.contains("a"));
    EXPECT_TRUE(set.contains("4ac"));
    EXPECT_TRUE(set.contains("booleans"));
    EXPECT_TRUE(set.contains("same thing"));
    EXPECT_TRUE(set.contains("same thing other"));
    EXPECT_TRUE(set.contains("same thing other than that"));
    EXPECT_TRUE(set.contains("same thing other than anything"));
}

TEST(StringHashSetAddContains, AddAndContainsReturnsTrue) {
    containers::StringHashSet set{4};

    EXPECT_TRUE(set.add("same thing other than anything"));
    EXPECT_TRUE(set.contains("same thing other than anything"));
}

TEST(StringHashSetAddContains, AddOneStringAndContainsOnNonexistingReturnsFalse) {
    containers::StringHashSet set{4};

    EXPECT_TRUE(set.add("same thing other than anything"));
    EXPECT_TRUE(set.contains("same thing other than anything"));
    EXPECT_FALSE(set.contains("same thing other than the others"));
}
