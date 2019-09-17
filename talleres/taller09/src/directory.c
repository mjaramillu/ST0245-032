#include "directory.h"

DirectoryLinkedListNode* DirectoryLinkedListNode_New(DirectoryEntry* data) {
  DirectoryLinkedListNode* result = malloc(sizeof(DirectoryLinkedListNode));
  result->Data = data;
  return result;
}

void DirectoryLinkedListNode_Free(DirectoryLinkedListNode* target) {
  free(target);
}

DirectoryLinkedList* DirectoryLinkedList_New() {
  DirectoryLinkedList* result = malloc(sizeof(DirectoryLinkedList));
  return result;
}


void DirectoryLinkedList_Free(DirectoryLinkedList* target) {
  free(target);
}

void DirectoryLinkedList_Insert(DirectoryLinkedList* target, DirectoryLinkedListNode* toInsert) {
  if (target->Head != NULL) {
    toInsert->Next = target->Head;
  }
  target->Head = toInsert;
  target->Size++;
}

DirectoryLinkedListNode* DirectoryLinkedList_Lookup(DirectoryLinkedList* target, char* name) {
  DirectoryLinkedListNode* toInspect = target->Head;
  while (toInspect != NULL) {
    ComparisonResult result = Comparisons_CompareStrings(toInspect->Data->Name, name);
    if (result == EQUAL) {
      return toInspect;
    }
    toInspect = toInspect->Next;
  }
  return NULL;
}

DirectoryEntry* DirectoryEntry_New(char* name, unsigned long long number) {
  DirectoryEntry* result = malloc(sizeof(DirectoryEntry));
  result->Name = name;
  result->Number = number;
  return result;
}

void DirectoryEntry_Free(DirectoryEntry* target) {
  free(target);
}

Directory* Directory_New(unsigned long size) {
  Directory* result = malloc(sizeof(Directory));
  result->Size = size;
  result->Table = malloc(sizeof(DirectoryLinkedList*) * size);
  for (unsigned long i = 0; i < size; i++) {
    result->Table[i] = DirectoryLinkedList_New();
  }
  return result;
}

DirectoryEntry* Directory_Lookup(Directory* target, char* name) {
  unsigned long hash = Hashtable_Hash(name);
  unsigned long index = hash % target->Size;
  DirectoryLinkedList* list = target->Table[index];
  DirectoryEntry* result = DirectoryLinkedList_Lookup(list, name)->Data;
  return result;
}

void Directory_Add(Directory* target, DirectoryEntry* toAdd) {
  unsigned long hash = Hashtable_Hash(toAdd->Name);
  unsigned long index = hash % target->Size;
  DirectoryLinkedList* list = target->Table[index];
  DirectoryLinkedListNode* newNode = DirectoryLinkedListNode_New(toAdd);
  DirectoryLinkedList_Insert(list, newNode);
}
