#include <gtest/gtest.h>
#include "testing-utils.h"
#include "queue.h"

using namespace TestingUtils;

TEST(QueueTests, Queue_IsCorrect)
{
    Queue<int> queue;

    EXPECT_EQ(queue.length, 0);
    EXPECT_EQ(queue.head, nullptr);
    EXPECT_EQ(queue.tail, nullptr);

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
}