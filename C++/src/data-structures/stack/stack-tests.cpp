#include <gtest/gtest.h>
#include "stack.hpp"
#include "testing-utils.hpp"

using namespace testingUtils;
using namespace stack;

TEST(Stack, Stack_Is_Correct)
{
    Stack<int> stack;

    EXPECT_EQ(stack.length, 0);
    EXPECT_NULLPTR(stack.head);

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
    EXPECT_NULLPTR(stack.head);
}