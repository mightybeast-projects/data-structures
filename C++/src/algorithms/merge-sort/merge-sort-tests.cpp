#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "merge-sort.hpp"

using namespace testingUtils;
using namespace mergeSort;

TEST(Merge_Sort, Array_Is_Sorted)
{
    int arr[] = {9, 3, 799, 4, 1};
    int expected[] = {1, 3, 4, 9, 799};

    int arrSize = sizeof(arr) / sizeof(int);

    sort(arr, arrSize - 1);

    EXPECT_EQ_ARR(arr, expected, arrSize);
}