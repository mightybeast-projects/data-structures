#include "bubble-sort.h"
#include "unity.h"

void Bubble_Sort_Should_Sort_Array()
{
    int actual[] = { 5, 3, 2, 1, 4 };
    int expected[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(actual) / sizeof(actual[0]);

    bubbleSort(actual, size);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, size);
}