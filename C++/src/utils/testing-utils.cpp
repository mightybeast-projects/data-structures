#include <gtest/gtest.h>

namespace TestingUtils
{
    void expectArraysAreEqual(int *arr, int *expected, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            EXPECT_EQ(arr[i], expected[i]);
    }
}