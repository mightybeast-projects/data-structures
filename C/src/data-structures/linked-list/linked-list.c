#include "linked-list.h"
#include "stdlib.h"

struct linkedList
{
};

LinkedList* createLinkedList(void)
{
    LinkedList* linkedList = malloc(sizeof(struct linkedList));

    if (!linkedList)
        return NULL;

    return linkedList;
}

void deleteLinkedList(LinkedList* linkedList)
{
    free(linkedList);
}