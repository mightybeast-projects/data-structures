#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "insertion-sort.hpp"

using namespace TestingUtils;
using namespace InsertionSort;

TEST(InsertionSortTests, InsertionSort_IsCorrect)
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int expected[] = {1, 2, 3, 4, 5, 6};

    int arrSize = sizeof(arr) / sizeof(int);

    insertionSort(arr, arrSize);

    EXPECT_EQ_ARR(arr, expected, arrSize);
}