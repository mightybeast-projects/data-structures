#include "merge-sort.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(Merge_Sort, Array_Is_Sorted)
{
    int arr[] = { 9, 3, 799, 4, 1 };
    int expected[] = { 1, 3, 4, 9, 799 };

    int arrSize = sizeof(arr) / sizeof(int);

    mergeSort::sort(arr, arrSize);

    testingUtils::EXPECT_EQ_ARR(arr, expected, arrSize);
}