#include "queue.h"
#include "stdlib.h"

struct queue
{
};

Queue* createQueue(void)
{
    return malloc(sizeof(struct queue));
}