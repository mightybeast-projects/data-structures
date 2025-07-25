#include "stdbool.h"

typedef struct stack Stack;

Stack* create();
bool isEmpty(const Stack* s);
int size(const Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(const Stack* s);
void delete(Stack* s);