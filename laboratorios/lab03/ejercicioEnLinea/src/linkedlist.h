#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList LinkedList;

typedef struct LinkedListNode LinkedListNode;

typedef struct LinkedListNode {
  char Data;
  LinkedList* Owner;
  LinkedListNode* Next;
  LinkedListNode* Previous;
} LinkedListNode;

typedef struct LinkedList {
  unsigned long Size;
  LinkedListNode* Head;
  LinkedListNode* Tail;
} LinkedList;

void LinkedList_Print(LinkedList* target);

LinkedList* LinkedList_New();

void LinkedList_Free(LinkedList* target);

void LinkedList_AddBeginning(LinkedList* target, LinkedListNode* toAdd);

void LinkedList_AddEnd(LinkedList* target, LinkedListNode* toAdd);

LinkedListNode* LinkedListNode_New(char data);

void LinkedListNode_Free(LinkedListNode* target);

void LinkedListNode_InsertBefore(LinkedListNode* target, LinkedListNode* toInsert);

void LinkedListNode_InsertAfter(LinkedListNode* target, LinkedListNode* toInsert);

#endif
