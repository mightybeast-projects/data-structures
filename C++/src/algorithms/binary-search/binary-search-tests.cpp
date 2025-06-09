#include <gtest/gtest.h>
#include "binary-search.hpp"

using namespace binarySearch;

TEST(BinarySearchTests, BinarySearch_IsCorrect)
{
    int arr[] = {9, 3, 799, 4, 420};

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    EXPECT_EQ(search(arr, arrSize, 3), 1);
}