#ifndef STACK
#define STACK

#include <stdlib.h>

typedef struct Stack {
  unsigned char stackIndex;
  unsigned char data[256];
} Stack;

Stack* Stack_Create();

void Stack_Free(Stack* target);

void Stack_Push(Stack* target, char value);

char Stack_Pop(Stack* target);

#endif
