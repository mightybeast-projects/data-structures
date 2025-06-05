#include <gtest/gtest.h>
#include "linear-search.h"

using namespace LinearSearch;

TEST(LinearSearchTests, LinearSearch_IsCorrect)
{
    int arr[] = {9, 3, 799, 4, 420};

    int arrSize = sizeof(arr) / sizeof(int);

    EXPECT_EQ(linearSearch(arr, 4, arrSize), true);
}