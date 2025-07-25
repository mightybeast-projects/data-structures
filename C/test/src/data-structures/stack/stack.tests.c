#include "stack.h"
#include "stack.tests.h"
#include "stdlib.h"
#include "unity.h"

static Stack* stack;

void stackSetUp()
{
    stack = create();
}

void stackTearDown()
{
    delete(stack);
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

void Stack_Push_Should_Push_New_Value_On_Top(void)
{
    push(stack, 2);

    TEST_ASSERT_EQUAL_INT(2, peek(stack));
}

void Stack_Should_Have_First_Value_After_Two_Pushes_And_One_Pop(void)
{
    push(stack, 2);
    push(stack, 10);
    pop(stack);

    TEST_ASSERT_EQUAL_INT(2, peek(stack));
}

void Stack_Pop_On_Empty_Stack_Should_Return_Minus_One()
{
    TEST_ASSERT_EQUAL_INT(-1, pop(stack));
}

void Stack_Peek_On_Empty_Stack_Should_Return_Minus_One()
{
    TEST_ASSERT_EQUAL_INT(-1, peek(stack));
}

void Stack_Size_Should_Return_Stack_Size(void)
{
    push(stack, 2);
    push(stack, 10);
    push(stack, 5);
    push(stack, 6);
    pop(stack);

    TEST_ASSERT_EQUAL_INT(3, size(stack));
}

void Stack_Should_Have_LIFO_Behaviour(void)
{
    push(stack, 4);
    push(stack, 6);

    TEST_ASSERT_EQUAL_INT(6, peek(stack));

    push(stack, 2);
    push(stack, -1);

    TEST_ASSERT_EQUAL_INT(4, size(stack));

    const int t1 = pop(stack);

    TEST_ASSERT_EQUAL_INT(t1, -1);
    TEST_ASSERT_EQUAL_INT(3, size(stack));

    pop(stack);
    const int t2 = pop(stack);

    TEST_ASSERT_EQUAL_INT(6, t2);
    TEST_ASSERT_EQUAL_INT(4, peek(stack));
    TEST_ASSERT_EQUAL_INT(1, size(stack));
}

void runStackTests(void)
{
    RUN_TEST(Stack_Create_Should_Return_Newly_Created_Stack);
    RUN_TEST(Newly_Created_Stack_Should_Be_Empty);
    RUN_TEST(Stack_Should_Not_Be_Empty_After_One_Push);
    RUN_TEST(Stack_Should_Be_Empty_After_One_Push_And_One_Pop);
    RUN_TEST(Stack_Should_Not_Be_Empty_After_Two_Pushed_And_One_Pop);
    RUN_TEST(Stack_Push_Should_Push_New_Value_On_Top);
    RUN_TEST(Stack_Should_Have_First_Value_After_Two_Pushes_And_One_Pop);
    RUN_TEST(Stack_Pop_On_Empty_Stack_Should_Return_Minus_One);
    RUN_TEST(Stack_Size_Should_Return_Stack_Size);
    RUN_TEST(Stack_Should_Have_LIFO_Behaviour);
}