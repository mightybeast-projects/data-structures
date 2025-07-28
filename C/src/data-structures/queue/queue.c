#include "queue.h"
#include "stdlib.h"

typedef struct node Node;

struct node
{
    int value;
    Node* next;
};

struct queue
{
    int length;
    Node* first;
    Node* last;
};

void deleteQueueNode(Node* node);

Queue* createQueue(void)
{
    Queue* queue = malloc(sizeof(struct queue));

    if (!queue)
        return NULL;

    queue->length = 0;
    queue->first = NULL;
    queue->last = NULL;

    return queue;
}

bool queueIsEmpty(const Queue* queue)
{
    return queue->length == 0;
}

void queueEnqueue(Queue* queue, int value)
{
    Node* node = malloc(sizeof(struct node));

    if (!node)
        return;

    node->value = value;
    node->next = NULL;

    if (!queue->first)
    {
        queue->first = node;
        queue->last = node;
    } else
        queue->last->next = node;

    queue->last = node;

    queue->length++;
}

int queueDequeue(Queue* queue)
{
    if (queueIsEmpty(queue))
        return -1;

    Node* node = queue->first;
    int value = node->value;

    queue->first = node->next;
    queue->length--;

    if (!queue->first)
        queue->last = NULL;

    free(node);

    return value;
}

int queuePeek(const Queue* queue)
{
    if (queueIsEmpty(queue))
        return -1;

    return queue->first->value;
}

int queueLength(const Queue* queue)
{
    return queue->length;
}

void deleteQueue(Queue* queue)
{
    deleteQueueNode(queue->first);
    free(queue);
}

void deleteQueueNode(Node* node)
{
    while (node)
    {
        Node* next = node->next;
        free(node);
        node = next;
    }
}