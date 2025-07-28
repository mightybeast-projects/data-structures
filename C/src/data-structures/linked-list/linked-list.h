#include "stdbool.h"

typedef struct linkedList LinkedList;

LinkedList* createLinkedList(void);
bool linkedListIsEmpty(const LinkedList* linkedList);
int linkedListSize(const LinkedList* linkedList);
void linkedListAppend(LinkedList* linkedList);
void linkedListRemove(LinkedList* linkedList);
void deleteLinkedList(LinkedList* linkedList);