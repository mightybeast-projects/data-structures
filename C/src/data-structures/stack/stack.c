#include "stack.h"
#include "stdlib.h"

struct stack
{
};

Stack createStack()
{
    return malloc(sizeof(struct stack));
}
