#pragma once

#include "stack.h"
#include "stdlib.h"
#include "unity.h"

static Stack* stack;

static void Create_Should_Return_Newly_Created_Stack(void);
static void Newly_Created_Stack_Should_Be_Empty(void);
static void After_One_Push_Stack_Should_Not_Be_Empty(void);

void stackSetUp()
{
    stack = create();
}

void stackTearDown()
{
    delete (stack);
}

void runStackTests(void)
{
    RUN_TEST(Create_Should_Return_Newly_Created_Stack);
    RUN_TEST(Newly_Created_Stack_Should_Be_Empty);
    RUN_TEST(After_One_Push_Stack_Should_Not_Be_Empty);
}

static void Create_Should_Return_Newly_Created_Stack(void)
{
    TEST_ASSERT_NOT_NULL(stack);
}

static void Newly_Created_Stack_Should_Be_Empty(void)
{
    TEST_ASSERT_TRUE(isEmpty(stack));
    TEST_ASSERT_EQUAL_INT(1, isEmpty(stack));
}

static void After_One_Push_Stack_Should_Not_Be_Empty(void)
{
    push(stack, 1);

    TEST_ASSERT_FALSE(isEmpty(stack));
}