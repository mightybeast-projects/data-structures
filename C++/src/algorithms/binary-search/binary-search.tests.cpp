#include "binary-search.hpp"
#include <gtest/gtest.h>

TEST(Binary_Search, Item_Is_Found)
{
    int arr[] = { 9, 3, 799, 4, 420 };

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(binarySearch::search(arr, arrSize, 3), 1);
}