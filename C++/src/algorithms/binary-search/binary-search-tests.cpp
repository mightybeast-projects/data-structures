#include <gtest/gtest.h>
#include "binary-search.h"

using namespace BinarySearch;

TEST(BinarySearchTests, BinarySearch_IsCorrect)
{
    int arr[] = {9, 3, 799, 4, 420};

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(binarySearch(arr, arrSize, 3), 1);
}