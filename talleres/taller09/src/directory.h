#ifndef DIRECTORY
#define DIRECTORY

#include <stdlib.h>
#include "hashtable.h"
#include "comparisons.h"

typedef struct DirectoryLinkedList DirectoryLinkedList;

typedef struct Directory {
  DirectoryLinkedList** Table;
  unsigned long Size;
} Directory;

typedef struct DirectoryEntry {
  char* Name;
  unsigned long long Number;
} DirectoryEntry;

typedef struct DirectoryLinkedListNode DirectoryLinkedListNode;

typedef struct DirectoryLinkedList {
  unsigned long Size;
  DirectoryLinkedListNode* Head;
} DirectoryLinkedList;

typedef struct DirectoryLinkedListNode {
  DirectoryEntry* Data;
  DirectoryLinkedListNode* Next;
} DirectoryLinkedListNode;

DirectoryLinkedListNode* DirectoryLinkedListNode_New(DirectoryEntry* data);

void DirectoryLinkedListNode_Free(DirectoryLinkedListNode* target);

DirectoryLinkedList* DirectoryLinkedList_New();

void DirectoryLinkedList_Free(DirectoryLinkedList* target);

void DirectoryLinkedList_Insert(DirectoryLinkedList* target, DirectoryLinkedListNode* toInsert);

DirectoryLinkedListNode* DirectoryLinkedList_Lookup(DirectoryLinkedList* target, char* name);

DirectoryEntry* DirectoryEntry_New(char* name, unsigned long long number);

void DirectoryEntry_Free(DirectoryEntry* target);

Directory* Directory_New(unsigned long size);

DirectoryEntry* Directory_Lookup(Directory* target, char* name);

void Directory_Add(Directory* target, DirectoryEntry* toAdd);

#endif
