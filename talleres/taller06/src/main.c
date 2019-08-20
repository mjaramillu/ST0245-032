#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long int

typedef struct CustomArray {
  u64 size;
  unsigned char* data;
} CustomArray;

CustomArray* CustomArray_Create (u64 size) {
  CustomArray* result = malloc(sizeof(CustomArray));            //O(1)
  result->size = size;                                          //O(1)
  unsigned char* data = malloc(sizeof(unsigned char) * size);   //O(1)
  result->data = data;                                          //O(1)
  return result;                                                //O(1)
}

long long int CustomArray_Size (CustomArray* target) {
  return target->size;                                          //O(1)
}

void CustomArray_Dispose (CustomArray* target) {
  free(target->data);                                           //O(1)
  free(target);                                                 //O(1)
}

unsigned char CustomArray_Get (CustomArray* target, u64 index) {
  if (index < target->size) {                                   //O(1)
    return target->data[index];                                 //O(1)
  }
  else {
    printf("Array index overflow!\n");                          //O(1)
  }
  return 0;                                                     //O(1)
}

void CustomArray_Set (CustomArray* target, u64 index, unsigned char value) {
  if (index < target->size) {                                   //O(1)
    target->data[index] = value;                                //O(1)
  }
  else {
    printf("Array index overflow!\n");                          //O(1)
  }
}

void CustomArray_Add (CustomArray* target, unsigned char value) {
  target->size += 1;                                                  //O(1)
  unsigned char* data = malloc(sizeof(unsigned char) * target->size); //O(1)
  for (u64 i = 0; i < target->size - 1; i++) {                        //O(n)
    data[i] = target->data[i];                                        //O(n)
  }
  data[target->size - 1] = value;                                     //O(1)
  free(target->data);                                                 //O(1)
  target->data = data;                                                //O(1)
}

void CustomArray_Delete (CustomArray* target, u64 index) {
  if (index < target->size) {                                           //O(1)
    target->size -= 1;                                                  //O(1)
    unsigned char* data = malloc(sizeof(unsigned char) * target->size); //O(1)
    for (u64 i = 0; i < index; i++) {                                   //O(n)
      data[i] = target->data[i];                                        //O(n)
    }
    for (u64 i = index; i < target->size; i++) {                        //O(n)
      data[i] = target->data[i + 1];                                    //O(n)
    }
    free(target->data);                                                 //O(1)
    target->data = data;                                                //O(1)
  }
  else {
    printf("Array index overflow!\n");
  }
}

int main(int argc, char* argv[]) {
  CustomArray* testArray = CustomArray_Create(3);
  for (int i = 0; i < 3; i++) {
    printf("The array pos %d is %d\n", i, CustomArray_Get(testArray, i));
  }
  printf("The size of the array is %d\n", CustomArray_Size(testArray));
  CustomArray_Add(testArray, 42);
  printf("The size of the array is %d\n", CustomArray_Size(testArray));
  for (int i = 0; i < 4; i++) {
    printf("The array pos %d is %d\n", i, CustomArray_Get(testArray, i));
  }
  CustomArray_Delete(testArray, 2);
  printf("The size of the array is %d\n", CustomArray_Size(testArray));
  CustomArray_Dispose(testArray);
  return 0;
}
