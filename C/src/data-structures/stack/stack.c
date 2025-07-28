#include "stack.h"
#include "stdlib.h"

typedef struct node Node;

struct node
{
    StackItem value;
    Node* prev;
};

struct stack
{
    int size;
    Node* top;
};

static void deleteNode(Node* node);

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

void stackPush(Stack* stack, StackItem value)
{
    Node* node = malloc(sizeof(struct node));

    if (!node)
        return;

    node->value = value;
    node->prev = stack->top;
    stack->top = node;

    stack->size++;
}

StackItem stackPop(Stack* stack)
{
    if (!stack->top)
        return NULL;

    Node* top = stack->top;
    StackItem value = top->value;

    stack->top = top->prev;
    stack->size--;

    free(top);

    return value;
}

StackItem stackPeek(const Stack* stack)
{
    if (!stack->top)
        return NULL;

    return stack->top->value;
}

void deleteStack(Stack* stack)
{
    deleteNode(stack->top);
    free(stack);
}

static void deleteNode(Node* node)
{
    while (node)
    {
        Node* prev = node->prev;
        free(node);
        node = prev;
    }
}