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

static Node* createNode(const int value);
static void deleteNode(Node* node);
static Node* getAt(const LinkedList* linkedList, int index);
static void removeNode(LinkedList* linkedList, Node* node);
static bool indexOutOfBounds(const int index, const int size);

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

        removeNode(linkedList, node);

        return true;
    }

    return false;
}

void linkedListInsertAt(LinkedList* linkedList,
    const int index,
    const int value)
{
    if (indexOutOfBounds(index, linkedList->size + 1))
        return;

    if (index == 0)
        return linkedListPrepend(linkedList, value);

    if (index == linkedList->size)
        return linkedListAppend(linkedList, value);

    Node* prev = getAt(linkedList, index - 1);
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

    Node* node = getAt(linkedList, index);

    removeNode(linkedList, node);

    return true;
}

int linkedListGet(const LinkedList* linkedList, const int index)
{
    if (indexOutOfBounds(index, linkedList->size))
        return -1;

    Node* node = getAt(linkedList, index);

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

static Node* getAt(const LinkedList* linkedList, int index)
{
    Node* node = linkedList->head;

    for (int i = 0; i < index; i++)
        node = node->next;

    return node;
}

static void removeNode(LinkedList* linkedList, Node* node)
{
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
}

static bool indexOutOfBounds(const int index, const int size)
{
    return index < 0 || index >= size;
}