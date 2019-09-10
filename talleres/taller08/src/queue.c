#include "queue.h"

Queue* Queue_Create() {
  return malloc(sizeof(Queue));
}

void Queue_Free(Stack* target) {
  free(target);
}

void Queue_Add(Queue* target, char value) {
  target->data[target->queueEnd] = value;
  target->queueEnd++;
}

char Queue_Poll(Queue* target) {
  char result = target->data[target->queueStart];
  target->queueStart++;
  return result;
}
