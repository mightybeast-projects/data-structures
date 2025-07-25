#include "stdbool.h"

typedef struct stack Stack;

Stack* create();
bool isEmpty(const Stack* s);
void push(Stack* s, int value);
void delete(Stack* s);