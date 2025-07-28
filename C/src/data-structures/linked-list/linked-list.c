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

void deleteLinkedListNode(Node* node);

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
    Node* node = malloc(sizeof(struct node));

    if (!node)
        return;

    node->value = value;
    node->prev = NULL;
    node->next = NULL;

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
    Node* node = malloc(sizeof(struct node));

    if (!node)
        return;

    node->value = value;
    node->prev = NULL;
    node->next = NULL;

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

void linkedListRemove(LinkedList* linkedList)
{
    linkedList->size--;
}

int linkedListGet(const LinkedList* linkedList, const int index)
{
    if (index < 0 || index >= linkedList->size)
        return -1;

    Node* node = linkedList->head;

    for (int i = 0; i < index; i++)
        node = node->next;

    return node->value;
}

void deleteLinkedList(LinkedList* linkedList)
{
    deleteLinkedListNode(linkedList->head);
    free(linkedList);
}

void deleteLinkedListNode(Node* node)
{
    while (node)
    {
        Node* next = node->next;
        free(node);
        node = next;
    }
}