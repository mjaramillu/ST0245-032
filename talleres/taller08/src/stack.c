#include "stack.h"

Stack* Stack_Create() {
  return malloc(sizeof(Stack))
}

void Stack_Free(Stack* target) {
  free(target);
}

void Stack_Push(Stack* target, char value) {
  target->data[target->stackIndex] = value;
  target->stackIndex++;
}

char Stack_Pop(Stack* target) {
  char result = target->data[target->stackIndex];
  target->stackIndex--;
  return result;
}
