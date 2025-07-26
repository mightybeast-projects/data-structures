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
};

void deleteQueueNode(Node* node);

Queue* createQueue(void)
{
    Queue* queue = malloc(sizeof(struct queue));
    queue->length = 0;
    queue->first = NULL;

    return queue;
}

bool queueIsEmpty(const Queue* queue)
{
    return queue->length == 0;
}

void queueEnqueue(Queue* queue, int value)
{
    queue->length++;

    Node* node = malloc(sizeof(struct node));
    node->value = value;

    if (!queue->first)
        queue->first = node;
    else
    {
        Node* n = queue->first;

        while (n->next)
            n = n->next;

        n->next = node;
    }
}

void queueDequeue(Queue* queue)
{
    queue->length--;

    Node* node = queue->first;

    queue->first = node->next;

    free(node);
}

int queuePeek(const Queue* queue)
{
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
    if (!node)
        return;

    deleteQueueNode(node->next);
    free(node);
}