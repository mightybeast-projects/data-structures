#include <gtest/gtest.h>
#include "bubble-sort.hpp"
#include "testing-utils.hpp"

using namespace BubbleSort;
using namespace TestingUtils;

TEST(BubbleSortTests, BubbleSort_IsCorrect)
{
    int arr[] = {9, 3, 799, 4, 420};
    int expected[] = {3, 4, 9, 420, 799};

    int arrSize = sizeof(arr) / sizeof(int);

    bubbleSort(arr, arrSize);

    EXPECT_EQ_ARR(arr, expected, arrSize);
}