#include "nodelist.h"

unsigned long NodeList_BalancedLookupIndex(NodeList* target, char* nameToFind) {
  unsigned long start = 0;
  unsigned long end = target->Size - 1;
  unsigned long pivot = 0;
  unsigned long diff = end;
  while(diff > 1) {
    diff = end - start;
    pivot = diff / 2;
    char* pivotName = target->Data[pivot]->Name;
    ComparisonResult comparison = Comparisons_CompareStrings(nameToFind,pivotName);
    if (comparison == GREATER) { start = pivot + 1; }
    if (comparison == LESSER) { end = pivot - 1; }
    if (comparison == EQUAL) {
      break;
    }
  }
  return pivot;
}

Node* NodeList_BalancedLookup(NodeList* target, char* nameToFind) {
  unsigned long index = NodeList_BalancedLookupIndex(target, nameToFind);
  Node* result = target->Data[index];
  ComparisonResult comparison = Comparisons_CompareStrings(result->Name, nameToFind);
  if (comparison == EQUAL) { return result; }
  return NULL;
}

void NodeList_BalancedInsert(NodeList* target, Node* toInsert) {
  unsigned long index = NodeList_BalancedLookupIndex(target, toInsert->Name);
  Node** newData = malloc(sizeof(Node*) * (target->Size + 1));
  for(unsigned long i = 0; i < (target->Size + 1); i++) {
    if(i < index) {
      newData[i] = target->Data[i];
    }
    if(i == index) {
      newData[i] = toInsert;
    }
    if(i > index) {
      newData[i] = target->Data[i-1];
    }
  }
  free(target->Data);
  target->Data = newData;
  target->Size++;
}

NodeList* NodeList_New() {
  NodeList* result = malloc(sizeof(NodeList));
  result->Size = 0;
  return result;
}

void NodeList_Free(NodeList* target) {
  free(target);
}
