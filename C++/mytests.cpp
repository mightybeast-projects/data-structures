#include <gtest/gtest.h>
#include "myfunctions.h"

TEST(MyTests, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(MyTests, AddTest)
{
    EXPECT_EQ(add(10, 10), 20);
}