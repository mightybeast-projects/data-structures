#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "insertion-sort.hpp"

using namespace testingUtils;
using namespace insertionSort;

TEST(Insertion_Sort, Array_Is_Sorted)
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int expected[] = {1, 2, 3, 4, 5, 6};

    int arrSize = sizeof(arr) / sizeof(int);

    sort(arr, arrSize);

    EXPECT_EQ_ARR(arr, expected, arrSize);
}