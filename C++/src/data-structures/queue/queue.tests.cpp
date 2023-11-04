#include <gtest/gtest.h>
#include "testing-utils.h"
#include "queue.h"

using namespace TestingUtils;

void expectEmptyQueue(Queue<int> queue);

TEST(QueueTests, Queue_IsCorrect)
{
    Queue<int> queue;

    expectEmptyQueue(queue);

    queue.enqueue(3);

    EXPECT_EQ(queue.length, 1);
    EXPECT_EQ(queue.head->value, 3);
    EXPECT_EQ(queue.tail->value, 3);

    queue.enqueue(5);
    queue.enqueue(7);

    EXPECT_EQ(queue.length, 3);
    EXPECT_EQ(queue.head->value, 3);
    EXPECT_EQ(queue.head->next->value, 5);
    EXPECT_EQ(queue.tail->value, 7);
    EXPECT_EQ(queue.tail->next, nullptr);
    EXPECT_EQ(queue.peek(), 3);

    EXPECT_EQ(queue.dequeue(), 3);
    EXPECT_EQ(queue.length, 2);
    EXPECT_EQ(queue.head->value, 5);

    queue.dequeue();
    queue.dequeue();

    expectEmptyQueue(queue);
}

void expectEmptyQueue(Queue<int> queue)
{
    EXPECT_EQ(queue.length, 0);
    EXPECT_EQ(queue.head, nullptr);
    EXPECT_EQ(queue.tail, nullptr);
    EXPECT_EQ(queue.dequeue(), NULL);
    EXPECT_EQ(queue.peek(), NULL);
}