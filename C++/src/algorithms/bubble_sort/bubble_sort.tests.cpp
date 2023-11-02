#include <gtest/gtest.h>
#include "bubble_sort.h"

namespace BubbleSortTests
{
    TEST(BubbleSortTests, BubbleSort_IsCorrect)
    {
        int arr[] = {9, 3, 799, 4, 420};
        int expected[] = {3, 4, 9, 420, 799};

        int arrSize = sizeof(arr) / sizeof(int);

        BubbleSort::bubble_sort(arr, arrSize);

        for (int i = 0; i < arrSize; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        for (int i = 0; i < arrSize; i++)
            EXPECT_EQ(arr[i], expected[i]);
    }
}