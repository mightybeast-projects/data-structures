#include "linked-list.h"
#include "stdbool.h"
#include "stdlib.h"

struct linkedList
{
    int size;
};

LinkedList* createLinkedList(void)
{
    LinkedList* linkedList = malloc(sizeof(struct linkedList));

    if (!linkedList)
        return NULL;

    linkedList->size = 0;

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

void linkedListAppend(LinkedList* linkedList)
{
    linkedList->size++;
}

void linkedListRemove(LinkedList* linkedList)
{
    linkedList->size--;
}

void deleteLinkedList(LinkedList* linkedList)
{
    free(linkedList);
}