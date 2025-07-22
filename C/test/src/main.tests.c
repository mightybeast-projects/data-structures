#include "binary-search.tests.h"
#include "bubble-sort.tests.h"
#include "insertion-sort.tests.h"
#include "linear-search.tests.h"
#include "quick-sort.tests.h"
#include "unity.h"

void setUp() { }

void tearDown() { }

int main()
{
    UNITY_BEGIN();

    RUN_TEST(Linear_Search_Should_Find_Item);
    RUN_TEST(Binary_Search_Should_Find_Item);
    RUN_TEST(Bubble_Sort_Should_Sort_Array);
    RUN_TEST(Insertion_Sort_Should_Sort_Array);
    RUN_TEST(Quick_Sort_Should_Sort_Array);

    return UNITY_END();
}