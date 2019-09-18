#ifndef COMPANIES
#define COMPANIES

#include <stdlib.h>
#include "hashtable.h"
#include "comparisons.h"

typedef struct CompaniesLinkedList CompaniesLinkedList;

typedef struct Companies {
  CompaniesLinkedList** Table;
  unsigned long Size;
} Companies;

typedef struct CompaniesEntry {
  char* Name;
  char* Country;
} CompaniesEntry;

typedef struct CompaniesLinkedListNode CompaniesLinkedListNode;

typedef struct CompaniesLinkedList {
  unsigned long Size;
  CompaniesLinkedListNode* Head;
} CompaniesLinkedList;

typedef struct CompaniesLinkedListNode {
  CompaniesEntry* Data;
  CompaniesLinkedListNode* Next;
} CompaniesLinkedListNode;

CompaniesLinkedListNode* CompaniesLinkedListNode_New(CompaniesEntry* data);

void CompaniesLinkedListNode_Free(CompaniesLinkedListNode* target);

CompaniesLinkedList* CompaniesLinkedList_New();

void CompaniesLinkedList_Free(CompaniesLinkedList* target);

void CompaniesLinkedList_Insert(CompaniesLinkedList* target, CompaniesLinkedListNode* toInsert);

CompaniesLinkedListNode* CompaniesLinkedList_Lookup(CompaniesLinkedList* target, char* name);

CompaniesEntry* CompaniesEntry_New(char* name, char* country);

void CompaniesEntry_Free(CompaniesEntry* target);

Companies* Companies_New(unsigned long size);

CompaniesEntry* Companies_Lookup(Companies* target, char* name);

void Companies_Add(Companies* target, CompaniesEntry* toAdd);

#endif
