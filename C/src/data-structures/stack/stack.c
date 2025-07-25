#include "stack.h"
#include "stdlib.h"

struct stack
{
    int size;
};

Stack* create()
{
    Stack* stack = malloc(sizeof(struct stack));
    stack->size = 0;

    return stack;
}

bool isEmpty(const Stack* s)
{
    return s->size == 0;
}

void push(Stack* s, int value)
{
    s->size++;
}

int pop(Stack* s)
{
    s->size--;
}

void delete(Stack* s)
{
    free(s);
}