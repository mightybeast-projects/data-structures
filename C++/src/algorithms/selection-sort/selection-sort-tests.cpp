#include <gtest/gtest.h>
#include "testing-utils.h"
#include "selection-sort.h"

using namespace TestingUtils;
using namespace SelectionSort;

TEST(SelectionSort, SelectionSort_IsCorrect)
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int expected[] = {1, 2, 3, 4, 5, 6};

    int arrSize = sizeof(arr) / sizeof(int);

    selectionSort(arr, arrSize);

    EXPECT_EQ_ARR(arr, expected, arrSize);
}