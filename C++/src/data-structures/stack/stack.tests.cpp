#include "stack.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(Stack, Stack_Is_Correct)
{
    stack::Stack<int> stack;

    EXPECT_EQ(stack.length, 0);
    testingUtils::EXPECT_NULLPTR(stack.head);

    stack.push(5);
    stack.push(7);
    stack.push(9);

    EXPECT_EQ(stack.length, 3);
    EXPECT_EQ(stack.head->value, 9);
    EXPECT_EQ(stack.head->prev->value, 7);

    EXPECT_EQ(stack.peek(), 9);

    EXPECT_EQ(stack.pop(), 9);
    EXPECT_EQ(stack.length, 2);
    EXPECT_EQ(stack.peek(), 7);

    stack.pop();
    stack.pop();

    EXPECT_EQ(stack.length, 0);
    testingUtils::EXPECT_NULLPTR(stack.head);
}