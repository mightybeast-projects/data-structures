#include "binary-search.h"
#include "unity.h"

#include <stdbool.h>

void Binary_Search_Should_Find_Item()
{
    int arr[] = { 6, 4, 8, 9, 10, 15 };

    TEST_ASSERT_EQUAL_INT(binarySearch(arr, 5, 9), true);
    TEST_ASSERT_EQUAL_INT(binarySearch(arr, 5, 100), false);
}
