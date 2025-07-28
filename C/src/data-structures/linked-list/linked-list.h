#include "stdbool.h"

typedef struct linkedList LinkedList;

LinkedList* createLinkedList(void);
bool linkedListIsEmpty(const LinkedList* linkedList);
int linkedListSize(const LinkedList* linkedList);
void linkedListAppend(LinkedList* linkedList, const int value);
void linkedListPrepend(LinkedList* linkedList, const int value);
bool linkedListRemove(LinkedList* linkedList, const int value);
void linkedListInsertAt(LinkedList* linkedList,
    const int index,
    const int value);
int linkedListGet(const LinkedList* linkedList, const int index);
void deleteLinkedList(LinkedList* linkedList);