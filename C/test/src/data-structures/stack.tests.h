#pragma once

#include "stack.h"
#include "stdlib.h"
#include "unity.h"

Stack stack;

void Create_Should_Return_Newly_Created_Stack(void);

void stackSetUp()
{
    stack = createStack();
}
void stackTearDown()
{
    free(stack);
}

void runStackTests(void)
{
    RUN_TEST(Create_Should_Return_Newly_Created_Stack);
}

void Create_Should_Return_Newly_Created_Stack(void)
{
    TEST_ASSERT_NOT_NULL(stack);
}