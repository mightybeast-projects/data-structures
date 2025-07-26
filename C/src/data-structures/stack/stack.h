#include "stdbool.h"

typedef struct stack Stack;

Stack* createStack(void);
bool stackIsEmpty(const Stack* stack);
int stackSize(const Stack* stack);
void stackPush(Stack* stack, int value);
int stackPop(Stack* stack);
int stackPeek(const Stack* stack);
void deleteStack(Stack* stack);