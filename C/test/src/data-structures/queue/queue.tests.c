#include "queue.tests.h"
#include "unity.h"

Queue* queue;

void queueSetUp()
{
    queue = createQueue();
}

void queueTearDown()
{
    deleteQueue(queue);
}

void Queue_Create_Should_Create_New_Queue(void)
{
    TEST_ASSERT_NOT_NULL(queue);
}

void Newly_Created_Queue_Should_Be_Empty(void)
{
    TEST_ASSERT_TRUE(queueIsEmpty(queue));
}

void After_One_Enqueue_Queue_Should_Not_Be_Empty(void)
{
    queueEnqueue(queue);

    TEST_ASSERT_FALSE(queueIsEmpty(queue));
}

void After_One_Enqueue_And_One_Dequeue_Queue_Should_Be_Empty()
{
    queueEnqueue(queue);
    queueDequeue(queue);

    TEST_ASSERT_TRUE(queueIsEmpty(queue));
}

void After_Two_Enqueue_And_One_Dequeue_Queue_Should_Not_Be_Empty()
{
    queueEnqueue(queue);
    queueEnqueue(queue);
    queueDequeue(queue);

    TEST_ASSERT_FALSE(queueIsEmpty(queue));
}

void Queue_Should_Return_Its_Length()
{
    queueEnqueue(queue);
    queueEnqueue(queue);
    queueEnqueue(queue);

    TEST_ASSERT_EQUAL_INT(3, queueLength(queue));
}

void runQueueTests(void)
{
    RUN_TEST(Queue_Create_Should_Create_New_Queue);
    RUN_TEST(Newly_Created_Queue_Should_Be_Empty);
    RUN_TEST(After_One_Enqueue_Queue_Should_Not_Be_Empty);
    RUN_TEST(After_One_Enqueue_And_One_Dequeue_Queue_Should_Be_Empty);
    RUN_TEST(After_Two_Enqueue_And_One_Dequeue_Queue_Should_Not_Be_Empty);
    RUN_TEST(Queue_Should_Return_Its_Length);
}
