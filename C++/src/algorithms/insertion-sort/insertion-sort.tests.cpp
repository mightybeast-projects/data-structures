#include "insertion-sort.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(Insertion_Sort, Array_Is_Sorted)
{
    int arr[] = { 5, 2, 4, 6, 1, 3 };
    int expected[] = { 1, 2, 3, 4, 5, 6 };

    int arrSize = sizeof(arr) / sizeof(int);

    insertionSort::sort(arr, arrSize);

    testingUtils::EXPECT_EQ_ARR(arr, expected, arrSize);
}