#include "stack.h"
#include "queue.h"
#include <stdio.h>

int ParseOperation (char* input) {
  Stack* operations = Stack_Create();
  Stack* number = Stack_Create();
  for (unsigned char i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') {
      if ((input[i-1] >= 48) & (input[i-1] <= 57)) {
        if (number->stackIndex > 0) {
          unsigned char accum = 0;
          unsigned char order = 1;
          while (number->stackIndex != 0) {
            accum += Stack_Pop(number) * order;
            order *= 10;
          }
          Stack_Push(operations, accum);
        }
      }
      continue;
    }
    if ((input[i] >= 48) & (input[i] <= 57)) {
      unsigned char digit = input[i] - 48;
      Stack_Push(number, digit);
      continue;
    }
    unsigned char a = Stack_Pop(operations);
    unsigned char b = Stack_Pop(operations);
    if (input[i] == '+') {
      Stack_Push(operations, a + b);
      continue;
    }
    if (input[i] == '-') {
      Stack_Push(operations, b - a);
      continue;
    }
    if (input[i] == '*') {
      Stack_Push(operations, a * b);
      continue;
    }
    if (input[i] == '/') {
      Stack_Push(operations, b / a);
      continue;
    }
  }
  unsigned char result = Stack_Pop(operations);
  Stack_Free(operations);
  Stack_Free(number);
  return result;
}

void Fridges(char* storage, char* requests) {
  Stack* storageStack = Stack_Create();
  for (unsigned char i = 0; storage[i] != '\0'; i++) {
    Stack_Push(storageStack, storage[i]);
  }
  Queue* requestsQueue = Queue_Create();
  for (unsigned char i = 0; storage[i] != '\0'; i++) {
    Queue_Add(storageStack, storage[i]);
  }
  char result[255][255];
  for (unsigned char x = 0; x < 255; x++) {
    for (unsigned char y = 0; y < 255; y++) {
      result[x][y] = '\0';
    }
  }
  while(requestsQueue->queueStart != requestsQueue->queueEnd) {
    char store = Queue_Poll(requestsQueue);
    char count = Queue_Poll(requestsQueue);
    unsigned char currentFridges = (unsigned char)result[(unsigned char)store][0];
    for(unsigned char i = currentFridges + 1; i <= count + currentFridges; i++) {
      result[(unsigned char)store][i] = Stack_Pop(storageStack);
    }
  }
  for (unsigned char i = 0; i < 255; i++) {
    if(result[i][0] > 0) {
      printf("Fridges for store %c:\n", (char)i);
      for (int j = 1; result[i][j] != '\0'; j++) {
        if (j != 1) {
          printf(", ");
        }
        printf("%c", (char)result[i][j]);
      }
      printf("\n");
    }
  }
  Stack_Free(storageStack);
  Queue_Free(requestsQueue);
}

int main(int argc, char* argv[]) {
  unsigned char test = ParseOperation("4 6 4 - +");
  printf("The result is %d\n", test);
}
