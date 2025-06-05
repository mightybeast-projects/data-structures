#include <gtest/gtest.h>
#include "testing-utils.h"
#include "queue.h"

namespace Queue
{
    using namespace TestingUtils;

    template <typename T>
    void EXPECT_NULL_QUEUE(Queue<T> queue);

    TEST(QueueTests, Queue_IsCorrect)
    {
        Queue<int> queue;

        EXPECT_NULL_QUEUE(queue);

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
        EXPECT_NULLPTR(queue.tail->next);
        EXPECT_EQ(queue.peek(), 3);

        EXPECT_EQ(queue.dequeue(), 3);
        EXPECT_EQ(queue.length, 2);
        EXPECT_EQ(queue.head->value, 5);

        queue.dequeue();
        queue.dequeue();

        EXPECT_NULL_QUEUE(queue);
    }

    template <typename T>
    void EXPECT_NULL_QUEUE(Queue<T> queue)
    {
        EXPECT_EQ(queue.length, 0);
        EXPECT_NULLPTR(queue.head);
        EXPECT_NULLPTR(queue.tail);
        EXPECT_NULL(queue.dequeue());
        EXPECT_NULL(queue.peek());
    }
}