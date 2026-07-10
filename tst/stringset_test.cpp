#include "gtest/gtest.h"
#include "stringset.hpp"

TEST(StringSetContains, ContainsEmptyStringReturnsFalse) {
    containers::StringSet set{};

    EXPECT_FALSE(set.contains(""));
}

TEST(StringSetContains, ContainsRandomStringReturnsFalse) {
    containers::StringSet set{};

    EXPECT_FALSE(set.contains("car"));
}

TEST(StringSetAdd, AddEmptyStringReturnsTrue) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add(""));
}


TEST(StringSetAdd, AddRadomStringReturnsTrue) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("car"));
}


TEST(StringSetAdd, AddMultipleStringReturnsTrue) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("car"));
    EXPECT_TRUE(set.add("cart"));
    EXPECT_TRUE(set.add("carts"));
    EXPECT_TRUE(set.add("carten"));
    EXPECT_TRUE(set.add("cars"));
    EXPECT_TRUE(set.add("carol"));
}

TEST(StringSetAdd, AddEmptyStringTwiceReturnsTrueAndFalse) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add(""));
    EXPECT_FALSE(set.add(""));
}

TEST(StringSetAdd, AddRandomStringTwiceReturnsTrueAndFalse) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_FALSE(set.add("desktop"));
}

TEST(StringSetAddContains, AddRandomStringAndContainsReturnTrue) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.contains("desktop"));
}

TEST(StringSetAddRemoveContains, AddRandomstringAndContainsAndRemoveReturnTrue) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.contains("desktop"));
    EXPECT_TRUE(set.remove("desktop"));
}

TEST(StringSetAddRemoveContains, AddRandomStringAndRemoveTwiceReturnsTrueAndFalse) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.contains("desktop"));
    EXPECT_TRUE(set.remove("desktop"));
    EXPECT_FALSE(set.remove("desktop"));
    EXPECT_FALSE(set.contains("desktop"));
}

TEST(StringSetRemove, RemoveAddedStringDoesNotRemoveTheOtherString) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.add("mouse"));
    EXPECT_TRUE(set.remove("desktop"));
    EXPECT_TRUE(set.contains("mouse"));
}

TEST(StringSetRemove, RemoveSimilarPrefixNonExistentStringDoesNotRemoveThePresentString) {
    containers::StringSet set{};

    EXPECT_TRUE(set.add("desktops"));
    EXPECT_FALSE(set.remove("desktop"));
    EXPECT_TRUE(set.contains("desktops"));
}
