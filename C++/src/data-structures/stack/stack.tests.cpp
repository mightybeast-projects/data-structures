#include <gtest/gtest.h>
#include "stack.h"
#include "testing-utils.h"

using namespace TestingUtils;

TEST(StackTests, Node_Referencing_IsCorrect)
{
    Node<int> *ptr = nullptr, node1, node2;

    node1.value = 123;

    node2.value = 345;
    node2.prev = &node1;

    ptr = &node2;

    EXPECT_EQ(ptr->prev->value, 123);
}

TEST(StackTests, Stack_IsCorrect)
{
    Stack<int> stack;

    EXPECT_EQ(stack.length, 0);
    EXPECT_EQ(stack.head, nullptr);

    stack.push(5);

    EXPECT_EQ(stack.length, 1);
    EXPECT_EQ(stack.head->value, 5);
}