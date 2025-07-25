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

void deleteNode(Node* node);

Stack* create()
{
    Stack* stack = malloc(sizeof(struct stack));

    if (!stack)
        return NULL;

    stack->size = 0;
    stack->top = NULL;

    return stack;
}

bool isEmpty(const Stack* stack)
{
    return stack->size == 0;
}

int size(const Stack* stack)
{
    return stack->size;
}

void push(Stack* stack, int value)
{
    Node* node = malloc(sizeof(struct node));

    if (!node)
        return;

    node->value = value;
    node->prev = stack->top;
    stack->top = node;

    stack->size++;
}

int pop(Stack* stack)
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

int peek(const Stack* stack)
{
    if (!stack->top)
        return -1;

    return stack->top->value;
}

void delete(Stack* stack)
{
    deleteNode(stack->top);
    free(stack);
}

void deleteNode(Node* node)
{
    if (!node)
        return;

    deleteNode(node->prev);
    free(node);
}