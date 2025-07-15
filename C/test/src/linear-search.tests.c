#include "linear-search.h"
#include "unity.h"

void setUp(void) { }

void tearDown(void) { }

void test_add_should_add_two_numbers(void)
{
    tmp();
    TEST_ASSERT_EQUAL_INT(5, 5);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_add_should_add_two_numbers);

    return UNITY_END();
}
