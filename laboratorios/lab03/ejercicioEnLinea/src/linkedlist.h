#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct LinkedListNode {
  char Data;
  LinkedListNode* Next;
  LinkedListNode* Previous;
} LinkedListNode;

typedef struct LinkedList {
  unsigned long Size;
  LinkedListNode* Head;
  LinkedListNode* Tail;
} LinkedList;

LinkedList* LinkedList_NewFromString(char* input);

LinkedList* LinkedList_New();

void LinkedList_Free(LinkedList* target);

LinkedListNode LinkedListNode_New(char data);

void LinkedListNode_Free(LinkedListNode* target);

void LinkedListNode_InsertBefore(LinkedListNode* target, LinkedListNode* toInsert);

void LinkedListNode_InsertAfter(LinkedListNode* target, LinkedListNode* toInsert);

#endif
