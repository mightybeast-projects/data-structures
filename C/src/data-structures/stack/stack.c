#include "stack.h"
#include "stdlib.h"

struct stack
{
    bool isEmpty;
};

Stack* create()
{
    Stack* stack = malloc(sizeof(struct stack));
    stack->isEmpty = true;

    return stack;
}

bool isEmpty(const Stack* s)
{
    return s->isEmpty;
}

void push(Stack* s, int value)
{
    s->isEmpty = false;
}

void delete(Stack* s)
{
    free(s);
}