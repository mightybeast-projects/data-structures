#include "stack.h"
#include "stack.tests.h"
#include "stdlib.h"
#include "unity.h"

static Stack* stack;

void stackSetUp()
{
    stack = createStack();
}

void stackTearDown()
{
    deleteStack(stack);
}

void Stack_Create_Should_Return_Newly_Created_Stack(void)
{
    TEST_ASSERT_NOT_NULL(stack);
}

void Newly_Created_Stack_Should_Be_Empty(void)
{
    TEST_ASSERT_TRUE(stackIsEmpty(stack));
}

void Stack_Should_Not_Be_Empty_After_One_Push(void)
{
    stackPush(stack, 1);

    TEST_ASSERT_FALSE(stackIsEmpty(stack));
}

void Stack_Should_Be_Empty_After_One_Push_And_One_Pop(void)
{
    stackPush(stack, 1);
    stackPop(stack);

    TEST_ASSERT_TRUE(stackIsEmpty(stack));
}

void Stack_Should_Not_Be_Empty_After_Two_Pushed_And_One_Pop(void)
{
    stackPush(stack, 1);
    stackPush(stack, 2);
    stackPop(stack);

    TEST_ASSERT_FALSE(stackIsEmpty(stack));
}

void Stack_Push_Should_Push_New_Value_On_Top(void)
{
    stackPush(stack, 2);

    TEST_ASSERT_EQUAL_INT(2, stackPeek(stack));
}

void Stack_Should_Have_First_Value_After_Two_Pushes_And_One_Pop(void)
{
    stackPush(stack, 2);
    stackPush(stack, 10);
    stackPop(stack);

    TEST_ASSERT_EQUAL_INT(2, stackPeek(stack));
}

void Stack_Size_Should_Return_Stack_Size(void)
{
    stackPush(stack, 2);
    stackPush(stack, 10);
    stackPush(stack, 5);
    stackPush(stack, 6);
    stackPop(stack);

    TEST_ASSERT_EQUAL_INT(3, stackSize(stack));
}

void Stack_Should_Have_LIFO_Behaviour(void)
{
    stackPush(stack, 4);
    stackPush(stack, 6);

    TEST_ASSERT_EQUAL_INT(6, stackPeek(stack));

    stackPush(stack, 2);
    stackPush(stack, -1);

    TEST_ASSERT_EQUAL_INT(4, stackSize(stack));

    const int t1 = stackPop(stack);

    TEST_ASSERT_EQUAL_INT(t1, -1);
    TEST_ASSERT_EQUAL_INT(3, stackSize(stack));

    stackPop(stack);
    const int t2 = stackPop(stack);

    TEST_ASSERT_EQUAL_INT(6, t2);
    TEST_ASSERT_EQUAL_INT(4, stackPeek(stack));
    TEST_ASSERT_EQUAL_INT(1, stackSize(stack));
}

void Stack_Pop_On_Empty_Stack_Should_Return_Minus_One()
{
    TEST_ASSERT_EQUAL_INT(-1, stackPop(stack));
}

void Stack_Peek_On_Empty_Stack_Should_Return_Minus_One()
{
    TEST_ASSERT_EQUAL_INT(-1, stackPeek(stack));
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