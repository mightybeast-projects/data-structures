#define QUEUE_ITEM_TYPE int
#include "queue.h"
#include "queue.tests.h"
#include "unity.h"

Queue* queue;

void setUpQueue(void)
{
    queue = createQueue();
}

void tearDownQueue(void)
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
    queueEnqueue(queue, 10);

    TEST_ASSERT_FALSE(queueIsEmpty(queue));
}

void After_One_Enqueue_And_One_Dequeue_Queue_Should_Be_Empty(void)
{
    queueEnqueue(queue, 10);
    queueDequeue(queue);

    TEST_ASSERT_TRUE(queueIsEmpty(queue));
}

void After_Two_Enqueue_And_One_Dequeue_Queue_Should_Not_Be_Empty(void)
{
    queueEnqueue(queue, 10);
    queueEnqueue(queue, 101);
    queueDequeue(queue);

    TEST_ASSERT_FALSE(queueIsEmpty(queue));
}

void Queue_Should_Return_Its_Length(void)
{
    queueEnqueue(queue, 10);
    queueEnqueue(queue, 10);
    queueEnqueue(queue, 10);

    TEST_ASSERT_EQUAL_INT(3, queueLength(queue));
}

void Queue_Enqueue_Should_Enqueue_New_Value(void)
{
    queueEnqueue(queue, 10);

    TEST_ASSERT_EQUAL_INT(10, queuePeek(queue));
}

void After_Two_Enqueue_First_Value_Should_Be_First(void)
{
    queueEnqueue(queue, 1);
    queueEnqueue(queue, 2);

    TEST_ASSERT_EQUAL_INT(1, queuePeek(queue));
}

void Queue_Should_Dequeue_Current_First()
{
    queueEnqueue(queue, 2);

    TEST_ASSERT_EQUAL_INT(2, queueDequeue(queue));
}

void Queue_Should_Have_FIFO_Behaviour()
{
    queueEnqueue(queue, 1);
    queueEnqueue(queue, 2);

    const int f1 = queueDequeue(queue);

    TEST_ASSERT_EQUAL_INT(2, queuePeek(queue));
    TEST_ASSERT_EQUAL_INT(1, f1);

    queueEnqueue(queue, 10);
    queueEnqueue(queue, 20);

    const int f2 = queueDequeue(queue);

    TEST_ASSERT_EQUAL_INT(2, queueLength(queue));
    TEST_ASSERT_EQUAL_INT(2, f2);
    TEST_ASSERT_EQUAL_INT(10, queuePeek(queue));
}

void Queue_Peek_On_Empty_Queue_Should_Return_Zero_Value()
{
    TEST_ASSERT_EQUAL_INT(0, queuePeek(queue));
}

void Queue_Dequeue_On_Empty_Queue_Should_Return_Zero_Value()
{
    TEST_ASSERT_EQUAL_INT(0, queueDequeue(queue));
}

void runQueueTests(void)
{
    RUN_TEST(Queue_Create_Should_Create_New_Queue);
    RUN_TEST(Newly_Created_Queue_Should_Be_Empty);
    RUN_TEST(After_One_Enqueue_Queue_Should_Not_Be_Empty);
    RUN_TEST(After_One_Enqueue_And_One_Dequeue_Queue_Should_Be_Empty);
    RUN_TEST(After_Two_Enqueue_And_One_Dequeue_Queue_Should_Not_Be_Empty);
    RUN_TEST(Queue_Should_Return_Its_Length);
    RUN_TEST(Queue_Enqueue_Should_Enqueue_New_Value);
    RUN_TEST(After_Two_Enqueue_First_Value_Should_Be_First);
    RUN_TEST(Queue_Should_Dequeue_Current_First);
    RUN_TEST(Queue_Should_Have_FIFO_Behaviour);
    RUN_TEST(Queue_Peek_On_Empty_Queue_Should_Return_Zero_Value);
    RUN_TEST(Queue_Dequeue_On_Empty_Queue_Should_Return_Zero_Value);
}
