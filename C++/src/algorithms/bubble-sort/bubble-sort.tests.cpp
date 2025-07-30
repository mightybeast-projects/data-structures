#include "bubble-sort.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(Bubble_Sort, Array_Is_Sorted)
{
    int arr[] = { 9, 3, 799, 4, 420 };
    int expected[] = { 3, 4, 9, 420, 799 };

    int arrSize = sizeof(arr) / sizeof(int);

    bubbleSort::sort(arr, arrSize);

    testingUtils::EXPECT_EQ_ARR(arr, expected, arrSize);
}