#include <gtest/gtest.h>
#include "linear-search.hpp"

using namespace linearSearch;

TEST(Linear_Search, Item_Is_Found)
{
    int arr[] = {9, 3, 799, 4, 420};

    int arrSize = sizeof(arr) / sizeof(int);

    EXPECT_EQ(search(arr, 4, arrSize), true);
}