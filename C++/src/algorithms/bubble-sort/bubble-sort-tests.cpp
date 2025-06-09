#include <gtest/gtest.h>
#include "bubble-sort.hpp"
#include "testing-utils.hpp"

using namespace bubbleSort;
using namespace testingUtils;

TEST(BubbleSortTests, BubbleSort_IsCorrect)
{
    int arr[] = {9, 3, 799, 4, 420};
    int expected[] = {3, 4, 9, 420, 799};

    int arrSize = sizeof(arr) / sizeof(int);

    sort(arr, arrSize);

    EXPECT_EQ_ARR(arr, expected, arrSize);
}