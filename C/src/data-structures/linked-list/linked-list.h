#include "stdbool.h"

#ifndef LINKED_LIST_ITEM_TYPE
#define LINKED_LIST_ITEM_TYPE void*
#endif

typedef LINKED_LIST_ITEM_TYPE LinkedListItem;

typedef struct linkedList LinkedList;

LinkedList* createLinkedList(void);

bool linkedListIsEmpty(const LinkedList* linkedList);

int linkedListSize(const LinkedList* linkedList);

void linkedListAppend(LinkedList* linkedList, const LinkedListItem value);

void linkedListPrepend(LinkedList* linkedList, const LinkedListItem value);

bool linkedListRemove(LinkedList* linkedList, const LinkedListItem value);

void linkedListInsertAt(
    LinkedList* linkedList,
    const int index,
    const LinkedListItem value);

bool linkedListRemoveAt(LinkedList* linkedList, const int index);

LinkedListItem linkedListGet(const LinkedList* linkedList, const int index);

void deleteLinkedList(LinkedList* linkedList);