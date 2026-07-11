#include "gtest/gtest.h"
#include "stringflatset/stringflatset.hpp"

TEST(StringFlatSetContains, ContainsEmptyStringReturnsFalse) {
    containers::StringFlatSet set{};

    EXPECT_FALSE(set.contains(""));
}

TEST(StringFlatSetContains, ContainsRandomStringReturnsFalse) {
    containers::StringFlatSet set{};

    EXPECT_FALSE(set.contains("car"));
}

TEST(StringFlatSetAdd, AddEmptyStringReturnsTrue) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add(""));
}


TEST(StringFlatSetAdd, AddRadomStringReturnsTrue) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("car"));
}


TEST(StringFlatSetAdd, AddMultipleStringReturnsTrue) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("car"));
    EXPECT_TRUE(set.add("cart"));
    EXPECT_TRUE(set.add("carts"));
    EXPECT_TRUE(set.add("carten"));
    EXPECT_TRUE(set.add("cars"));
    EXPECT_TRUE(set.add("carol"));
}

TEST(StringFlatSetAdd, AddEmptyStringTwiceReturnsTrueAndFalse) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add(""));
    EXPECT_FALSE(set.add(""));
}

TEST(StringFlatSetAdd, AddRandomStringTwiceReturnsTrueAndFalse) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_FALSE(set.add("desktop"));
}

TEST(StringFlatSetAddContains, AddRandomStringAndContainsReturnTrue) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.contains("desktop"));
}

TEST(StringFlatSetAddRemoveContains, AddRandomstringAndContainsAndRemoveReturnTrue) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.contains("desktop"));
    EXPECT_TRUE(set.remove("desktop"));
}

TEST(StringFlatSetAddRemoveContains, AddRandomStringAndRemoveTwiceReturnsTrueAndFalse) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.contains("desktop"));
    EXPECT_TRUE(set.remove("desktop"));
    EXPECT_FALSE(set.remove("desktop"));
    EXPECT_FALSE(set.contains("desktop"));
}

TEST(StringFlatSetRemove, RemoveAddedStringDoesNotRemoveTheOtherString) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("desktop"));
    EXPECT_TRUE(set.add("mouse"));
    EXPECT_TRUE(set.remove("desktop"));
    EXPECT_TRUE(set.contains("mouse"));
}

TEST(StringFlatSetRemove, RemoveSimilarPrefixNonExistentStringDoesNotRemoveThePresentString) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.add("desktops"));
    EXPECT_FALSE(set.remove("desktop"));
    EXPECT_TRUE(set.contains("desktops"));
}

TEST(StringFlatSetIterator, BeginIsEqualToEnd) {
    containers::StringFlatSet set{};

    EXPECT_TRUE(set.begin() == set.end());
}

TEST(StringFlatSetIterator, IterationIsOrdered) {
    containers::StringFlatSet set{};
    std::vector<std::string> expected{"bronze", "apple", "banana",
        "cristal", "1302031l", "something", "freesbee",
        "okeiokei", "\t\t\t\t"};

    for (auto str : expected) {
        set.add(str);
    }
    std::sort(expected.begin(), expected.end());

    int i = 0;
    for (auto str : set) {
        EXPECT_TRUE(str == expected[i]);
        ++i;
    }
}
