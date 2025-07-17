#include "linear-search.c"
#include "unity-include.tests.h"

void Linear_Search_Should_Find_Item()
{
    int arr[] = { 6, 4, 8, 9, 10 };

    TEST_ASSERT_EQUAL_INT(linearSearch(arr, 5, 8), true);
    TEST_ASSERT_EQUAL_INT(linearSearch(arr, 5, 100), false);
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(Linear_Search_Should_Find_Item);

    return UNITY_END();
}
