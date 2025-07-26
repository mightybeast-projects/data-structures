#include "queue.tests.h"
#include "unity.h"

Queue* queue;

void queueSetUp()
{
    createQueue();
}

void queueTearDown() { }

void Newly_Created_Queue_Should_Be_Empty() { }

void runQueueTests(void)
{
    RUN_TEST(Newly_Created_Queue_Should_Be_Empty);
}
