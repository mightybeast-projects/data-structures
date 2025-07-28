#include "linked-list.h"
#include "stdbool.h"
#include "stdlib.h"

typedef struct node Node;

struct node
{
    int value;
    Node* prev;
    Node* next;
};

struct linkedList
{
    int size;
    Node* head;
    Node* tail;
};

static bool indexOutOfBounds(const int index, const int size);
static Node* createNode(const int value);
static void deleteNode(Node* node);

LinkedList* createLinkedList(void)
{
    LinkedList* linkedList = malloc(sizeof(struct linkedList));

    if (!linkedList)
        return NULL;

    linkedList->size = 0;
    linkedList->head = NULL;
    linkedList->tail = NULL;

    return linkedList;
}

bool linkedListIsEmpty(const LinkedList* linkedList)
{
    return linkedList->size == 0;
}

int linkedListSize(const LinkedList* linkedList)
{
    return linkedList->size;
}

void linkedListAppend(LinkedList* linkedList, const int value)
{
    Node* node = createNode(value);

    if (!node)
        return;

    if (!linkedList->tail)
    {
        linkedList->head = node;
        linkedList->tail = node;
    } else
    {
        linkedList->tail->next = node;
        node->prev = linkedList->tail;
        linkedList->tail = node;
    }

    linkedList->size++;
}

void linkedListPrepend(LinkedList* linkedList, const int value)
{
    Node* node = createNode(value);

    if (!node)
        return;

    if (!linkedList->head)
    {
        linkedList->head = node;
        linkedList->tail = node;
    } else
    {
        linkedList->head->prev = node;
        node->next = linkedList->head;
        linkedList->head = node;
    }

    linkedList->size++;
}

bool linkedListRemove(LinkedList* linkedList, const int value)
{
    Node* node = linkedList->head;

    while (node)
    {
        if (node->value != value)
        {
            node = node->next;

            continue;
        }

        if (node == linkedList->head)
            linkedList->head = node->next;

        if (node == linkedList->tail)
            linkedList->tail = node->prev;

        if (node->prev)
            node->prev->next = node->next;

        if (node->next)
            node->next->prev = node->prev;

        linkedList->size--;

        free(node);

        return true;
    }

    return false;
}

void linkedListInsertAt(LinkedList* linkedList,
    const int index,
    const int value)
{
    if (indexOutOfBounds(index, linkedList->size))
        return;

    if (index == 0)
        return linkedListPrepend(linkedList, value);

    if (index == linkedList->size)
        return linkedListAppend(linkedList, value);

    Node* prev = linkedList->head;

    for (int i = 0; i < index - 1; i++)
        prev = prev->next;

    Node* node = createNode(value);
    Node* next = prev->next;

    prev->next = node;
    node->prev = prev;

    next->prev = node;
    node->next = next;

    linkedList->size++;
}

bool linkedListRemoveAt(LinkedList* linkedList, const int index)
{
    if (indexOutOfBounds(index, linkedList->size))
        return false;

    Node* node = linkedList->head;

    for (int i = 0; i < index; i++)
        node = node->next;

    if (node == linkedList->head)
        linkedList->head = node->next;

    if (node == linkedList->tail)
        linkedList->tail = node->prev;

    if (node->prev)
        node->prev->next = node->next;

    if (node->next)
        node->next->prev = node->prev;

    free(node);

    linkedList->size--;

    return true;
}

int linkedListGet(const LinkedList* linkedList, const int index)
{
    if (indexOutOfBounds(index, linkedList->size))
        return -1;

    Node* node = linkedList->head;

    for (int i = 0; i < index; i++)
        node = node->next;

    return node->value;
}

void deleteLinkedList(LinkedList* linkedList)
{
    deleteNode(linkedList->head);
    free(linkedList);
}

static Node* createNode(const int value)
{
    Node* node = malloc(sizeof(struct node));

    if (!node)
        return NULL;

    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

static void deleteNode(Node* node)
{
    while (node)
    {
        Node* next = node->next;
        free(node);
        node = next;
    }
}

static bool indexOutOfBounds(const int index, const int size)
{
    return index < 0 || index > size;
}