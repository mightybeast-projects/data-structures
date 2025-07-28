#include "stack.h"
#include "stdlib.h"

typedef struct node Node;

struct node
{
    int value;
    Node* prev;
};

struct stack
{
    int size;
    Node* top;
};

void deleteStackNode(Node* node);

Stack* createStack(void)
{
    Stack* stack = malloc(sizeof(struct stack));

    if (!stack)
        return NULL;

    stack->size = 0;
    stack->top = NULL;

    return stack;
}

bool stackIsEmpty(const Stack* stack)
{
    return stack->size == 0;
}

int stackSize(const Stack* stack)
{
    return stack->size;
}

void stackPush(Stack* stack, int value)
{
    Node* node = malloc(sizeof(struct node));

    if (!node)
        return;

    node->value = value;
    node->prev = stack->top;
    stack->top = node;

    stack->size++;
}

int stackPop(Stack* stack)
{
    if (!stack->top)
        return -1;

    Node* top = stack->top;
    int value = top->value;

    stack->top = top->prev;
    stack->size--;

    free(top);

    return value;
}

int stackPeek(const Stack* stack)
{
    if (!stack->top)
        return -1;

    return stack->top->value;
}

void deleteStack(Stack* stack)
{
    deleteStackNode(stack->top);
    free(stack);
}

void deleteStackNode(Node* node)
{
    while (node)
    {
        Node* prev = node->prev;
        free(node);
        node = prev;
    }
}