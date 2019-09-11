#include "stack.h"

#include <stdio.h>

Stack* Stack_Create() {
  return malloc(sizeof(Stack));
}

void Stack_Free(Stack* target) {
  free(target);
}

void Stack_Push(Stack* target, char value) {
  target->data[target->stackIndex] = value;
  target->stackIndex += 1;
}

char Stack_Pop(Stack* target) {
  target->stackIndex -= 1;
  char result = target->data[target->stackIndex];
  return result;
}
