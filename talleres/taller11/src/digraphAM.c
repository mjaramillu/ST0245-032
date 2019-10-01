
#include <stdlib.h>
#include <stdio.h>

typedef struct DigraphAM {
  int size;
  int matriz[size][size];
  unsigned char* data;
} DigraphAM;

DigraphAM* DigraphAM_create(int size) {
  DigraphAM* result = malloc(sizeof(DigraphAM));
  result->size = size;
  int* matriz[size][size] = malloc(sizeof(matriz[size][size]));
  result->matriz= matriz; 
}
