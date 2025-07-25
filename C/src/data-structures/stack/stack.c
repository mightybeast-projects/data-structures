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

Stack* create()
{
    Stack* stack = malloc(sizeof(struct stack));
    stack->size = 0;
    stack->top = NULL;

    return stack;
}

void deleteNode(Node* n);

bool isEmpty(const Stack* s)
{
    return s->size == 0;
}

void push(Stack* s, int value)
{
    Node* node = malloc(sizeof(struct node));
    node->value = value;
    node->prev = NULL;

    if (!s->top)
        s->top = node;
    else
    {
        node->prev = s->top;
        s->top = node;
    }

    s->size++;
}

int pop(Stack* s)
{
    Node* top = s->top;
    int value = top->value;

    s->top = top->prev;
    s->size--;

    free(top);

    return value;
}

int peek(const Stack* s)
{
    return s->top->value;
}

void delete(Stack* s)
{
    deleteNode(s->top);
    free(s);
}

void deleteNode(Node* n)
{
    if (!n)
        return;

    deleteNode(n->prev);
    free(n);
}