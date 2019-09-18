#include "companies.h"


CompaniesLinkedListNode* CompaniesLinkedListNode_New(CompaniesEntry* data) {
  CompaniesLinkedListNode* result = malloc(sizeof(CompaniesLinkedListNode));
  result->Data = data;
  return result;
}

void CompaniesLinkedListNode_Free(CompaniesLinkedListNode* target) {
  free(target);
}

CompaniesLinkedList* CompaniesLinkedList_New() {
  CompaniesLinkedList* result = malloc(sizeof(CompaniesLinkedList));
  return result;
}


void CompaniesLinkedList_Free(CompaniesLinkedList* target) {
  free(target);
}

void CompaniesLinkedList_Insert(CompaniesLinkedList* target, CompaniesLinkedListNode* toInsert) {
  if (target->Head != NULL) {
    toInsert->Next = target->Head;
  }
  target->Head = toInsert;
  target->Size++;
}

CompaniesLinkedListNode* CompaniesLinkedList_Lookup(CompaniesLinkedList* target, char* name) {
  CompaniesLinkedListNode* toInspect = target->Head;
  while (toInspect != NULL) {
    ComparisonResult result = Comparisons_CompareStrings(toInspect->Data->Name, name);
    if (result == EQUAL) {
      return toInspect;
    }
    toInspect = toInspect->Next;
  }
  return NULL;
}

CompaniesEntry* CompaniesEntry_New(char* name, char* country) {
  CompaniesEntry* result = malloc(sizeof(CompaniesEntry));
  result->Name = name;
  result->Country = country;
  return result;
}

void CompaniesEntry_Free(CompaniesEntry* target) {
  free(target);
}

Companies* Companies_New(unsigned long size) {
  Companies* result = malloc(sizeof(Companies));
  result->Size = size;
  result->Table = malloc(sizeof(CompaniesLinkedList*) * size);
  for (unsigned long i = 0; i < size; i++) {
    result->Table[i] = CompaniesLinkedList_New();
  }
  return result;
}

CompaniesEntry* Companies_Lookup(Companies* target, char* name) {
  unsigned long hash = Hashtable_Hash(name);
  unsigned long index = hash % target->Size;
  CompaniesLinkedList* list = target->Table[index];
  CompaniesEntry* result = CompaniesLinkedList_Lookup(list, name)->Data;
  return result;
}

void Companies_Add(Companies* target, CompaniesEntry* toAdd) {
  unsigned long hash = Hashtable_Hash(toAdd->Name);
  unsigned long index = hash % target->Size;
  CompaniesLinkedList* list = target->Table[index];
  CompaniesLinkedListNode* newNode = CompaniesLinkedListNode_New(toAdd);
  CompaniesLinkedList_Insert(list, newNode);
}
