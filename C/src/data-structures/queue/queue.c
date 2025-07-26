#include "queue.h"
#include "stdlib.h"

struct queue
{
    int length;
};

Queue* createQueue(void)
{
    Queue* queue = malloc(sizeof(struct queue));
    queue->length = 0;

    return queue;
}

bool queueIsEmpty(const Queue* queue)
{
    return queue->length == 0;
}

void queueEnqueue(Queue* queue)
{
    queue->length++;
}

void queueDequeue(Queue* queue)
{
    queue->length--;
}

int queueLength(const Queue* queue)
{
    return queue->length;
}
