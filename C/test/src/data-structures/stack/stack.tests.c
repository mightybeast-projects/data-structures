#include "stack.h"
#include "stack.tests.h"
#include "stdlib.h"
#include "unity.h"

static Stack* stack;

void Stack_Create_Should_Return_Newly_Created_Stack(void);
void Newly_Created_Stack_Should_Be_Empty(void);
void Stack_Should_Not_Be_Empty_After_One_Push(void);
void Stack_Should_Be_Empty_After_One_Push_And_One_Pop(void);
void Stack_Should_Not_Be_Empty_After_Two_Pushed_And_One_Pop(void);

void stackSetUp()
{
    stack = create();
}

void stackTearDown()
{
    delete(stack);
}

void runStackTests(void)
{
    RUN_TEST(Stack_Create_Should_Return_Newly_Created_Stack);
    RUN_TEST(Newly_Created_Stack_Should_Be_Empty);
    RUN_TEST(Stack_Should_Not_Be_Empty_After_One_Push);
    RUN_TEST(Stack_Should_Be_Empty_After_One_Push_And_One_Pop);
    RUN_TEST(Stack_Should_Not_Be_Empty_After_Two_Pushed_And_One_Pop);
}

void Stack_Create_Should_Return_Newly_Created_Stack(void)
{
    TEST_ASSERT_NOT_NULL(stack);
}

void Newly_Created_Stack_Should_Be_Empty(void)
{
    TEST_ASSERT_TRUE(isEmpty(stack));
    TEST_ASSERT_EQUAL_INT(1, isEmpty(stack));
}

void Stack_Should_Not_Be_Empty_After_One_Push(void)
{
    push(stack, 1);

    TEST_ASSERT_FALSE(isEmpty(stack));
}

void Stack_Should_Be_Empty_After_One_Push_And_One_Pop(void)
{
    push(stack, 1);
    pop(stack);

    TEST_ASSERT_TRUE(isEmpty(stack));
    TEST_ASSERT_EQUAL_INT(1, isEmpty(stack));
}

void Stack_Should_Not_Be_Empty_After_Two_Pushed_And_One_Pop(void)
{
    push(stack, 1);
    push(stack, 2);
    pop(stack);

    TEST_ASSERT_FALSE(isEmpty(stack));
}