#include "stdbool.h"

typedef struct queue Queue;

Queue* createQueue(void);
bool queueIsEmpty(const Queue* queue);
void queueEnqueue(Queue* queue);
void queueDequeue(Queue* queue);
int queueLength(const Queue* queue);
void deleteQueue(Queue* queue);