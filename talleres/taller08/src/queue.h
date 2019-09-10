#ifndef QUEUE
#define QUEUE

#include <stdlib.h>

typedef struct Queue {
  unsigned char queueStart;
  unsigned char queueEnd;
  char data[256];
} Stack;

Queue* Queue_Create();

void Queue_Free(Queue* target);

void Queue_Add(Queue* target, char value);

char Queue_Poll(Queue* target);

#endif
