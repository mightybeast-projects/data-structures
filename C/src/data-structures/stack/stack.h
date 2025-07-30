#include "stdbool.h"

#ifndef STACK_ITEM_TYPE
#define STACK_ITEM_TYPE void*
#endif

typedef STACK_ITEM_TYPE StackItem;

typedef struct stack Stack;

Stack* createStack(void);

bool stackIsEmpty(const Stack* stack);

int stackSize(const Stack* stack);

void stackPush(Stack* stack, StackItem value);

StackItem stackPop(Stack* stack);

StackItem stackPeek(const Stack* stack);

void deleteStack(Stack* stack);