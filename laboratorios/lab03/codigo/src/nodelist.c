#include "nodelist.h"

unsigned long NodeList_BalancedLookupIndex(NodeList* target, char* nameToFind) {
  unsigned long start = 0;
  unsigned long end = target->Size - 1;
  unsigned long pivot;
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
