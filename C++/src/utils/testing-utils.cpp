#include <gtest/gtest.h>

namespace TestingUtils
{
    void assertArraysAreEqual(int *arr, int *expected, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            ASSERT_EQ(arr[i], expected[i]);
    }
}