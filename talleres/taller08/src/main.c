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

int main(int argc, char* argv[]) {
  unsigned char test = ParseOperation("4 6 4 - +");
  printf("The result is %d\n", test);
}
