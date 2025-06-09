#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "merge-sort.hpp"

using namespace TestingUtils;
using namespace MergeSort;

TEST(MergeSortTests, MergeSort_IsCorrect)
{
    int arr[] = {9, 3, 799, 4, 1};
    int expected[] = {1, 3, 4, 9, 799};

    int arrSize = sizeof(arr) / sizeof(int);

    mergeSort(arr, arrSize - 1);

    EXPECT_EQ_ARR(arr, expected, arrSize);
}