#include "stack.h"
#include "stdlib.h"

struct stack
{
};

Stack* create()
{
    return malloc(sizeof(struct stack));
}

bool isEmpty(const Stack* s)
{
    return true;
}