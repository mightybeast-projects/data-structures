#include <gtest/gtest.h>
#include "stack.h"
#include "testing-utils.h"

using namespace TestingUtils;

void expectEmptyStack(Stack<int> stack);

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

    expectEmptyStack(stack);

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

    expectEmptyStack(stack);
}

void expectEmptyStack(Stack<int> stack)
{
    EXPECT_EQ(stack.length, 0);
    EXPECT_NULLPTR(stack.head);
    EXPECT_NULL(stack.peek());
    EXPECT_NULL(stack.pop());
}