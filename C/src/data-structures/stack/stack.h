#include "stdbool.h"

typedef struct stack Stack;

Stack* create();
bool isEmpty(const Stack* stack);
int size(const Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(const Stack* stack);
void delete(Stack* stack);