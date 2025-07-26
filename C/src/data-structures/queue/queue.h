#include "stdbool.h"

typedef struct queue Queue;

Queue* createQueue(void);
bool queueIsEmpty(const Queue* queue);
void queueEnqueue(Queue* queue, int value);
void queueDequeue(Queue* queue);
int queuePeek(const Queue* queue);
int queueLength(const Queue* queue);
void deleteQueue(Queue* queue);