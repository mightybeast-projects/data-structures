#include "stdbool.h"

#ifndef QUEUE_ITEM_TYPE
#define QUEUE_ITEM_TYPE void*
#endif

typedef QUEUE_ITEM_TYPE QueueItem;

typedef struct queue Queue;

Queue* createQueue(void);
bool queueIsEmpty(const Queue* queue);
void queueEnqueue(Queue* queue, const QueueItem value);
QueueItem queueDequeue(Queue* queue);
QueueItem queuePeek(const Queue* queue);
int queueLength(const Queue* queue);
void deleteQueue(Queue* queue);