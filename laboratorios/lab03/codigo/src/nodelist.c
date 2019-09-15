#include "nodelist.h"

void NodeList_Debug(NodeList* target) {
  unsigned long count = 0;
  for (unsigned long i = 0; i < target->Size; i++) {
    Node* lookup = NodeList_BalancedLookup(target, target->Data[i]->Name);
    printf("%s, %x\n", target->Data[i]->Name, lookup);
    if (lookup==NULL) count++;
  }
  printf("%d weren't found \n", count);
}

unsigned long NodeList_BalancedLookupIndex(NodeList* target, char* nameToFind) {
  unsigned long start = 0;
  unsigned long end = target->Size;
  unsigned long diff = end;
  unsigned long pivot = start + (diff / 2);
  char* pivotName = target->Data[pivot]->Name;
  while(diff > 1) {
    ComparisonResult comparison = Comparisons_CompareStrings(nameToFind,pivotName);
    if (comparison == GREATER) { start = pivot; }
    if (comparison == LESSER) { end = pivot; }
    if (comparison == EQUAL) {
      break;
    }
    diff = end - start;
    pivot = start + (diff / 2);
    pivotName = target->Data[pivot]->Name;
    //printf("%s, %s, start %d, end %d, diff %d, pivot %d\n", nameToFind, pivotName, start, end, diff, pivot);
  }
  return pivot;
}

void NodeList_Sort(NodeList* target) {
  unsigned char sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (unsigned long i = 0; i < target->Size - 1; i++) {
      Node* this = target->Data[i];
      Node* next = target->Data[i+1];
      ComparisonResult comparison = Comparisons_CompareStrings(this->Name, next->Name);
      if (comparison == GREATER) {
        sorted = 0;
        target->Data[i+1] = this;
        target->Data[i] = next;
      }
    }
  }
}


Node* NodeList_BalancedLookup(NodeList* target, char* nameToFind) {
  if (target->Data == NULL) return NULL;
  unsigned long index = NodeList_BalancedLookupIndex(target, nameToFind);
  //printf("Index %d\n", index);
  if (index >= target->Size || index < 0) return NULL;
  Node* result = target->Data[index];
  ComparisonResult comparison = Comparisons_CompareStrings(result->Name, nameToFind);
  if (comparison == EQUAL) { return result; }
  return NULL;
}

void NodeList_Append(NodeList* target, Node* toInsert) {
  Node** newData = malloc(sizeof(Node*) * (target->Size + 1));
  for(unsigned long i = 0; i < target->Size; i++) {
    newData[i] = target->Data[i];
  }
  newData[target->Size] = toInsert;
  free(target->Data);
  target->Data = newData;
  target->Size++;
  NodeList_Sort(target);
}

NodeList* NodeList_New() {
  NodeList* result = malloc(sizeof(NodeList));
  result->Size = 0;
  return result;
}

void NodeList_Free(NodeList* target) {
  free(target);
}
