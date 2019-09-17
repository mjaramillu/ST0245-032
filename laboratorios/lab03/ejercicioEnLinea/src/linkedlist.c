#include "linkedlist.h"

void LinkedList_Print(LinkedList* target) {
  LinkedListNode* selectedNode = target->Head;
  while(selectedNode != target->Tail) {
    printf("%c", selectedNode->Data);
    selectedNode = selectedNode->Next;
  }
  printf("%c", selectedNode->Data);
  printf("\n");
}

LinkedList* LinkedList_New() {
  LinkedList* result = malloc(sizeof(LinkedList));
  return result;
}

void LinkedList_Free(LinkedList* target) {
  free(target);
}

void LinkedList_AddBeginning(LinkedList* target, LinkedListNode* toAdd) {
  if (target->Head == NULL) {
    target->Head = toAdd;
    target->Tail = toAdd;
    toAdd->Owner = target;
  }
  LinkedListNode_InsertBefore(target->Head, toAdd);
}

void LinkedList_AddEnd(LinkedList* target, LinkedListNode* toAdd) {
  if (target->Tail == NULL) {
    target->Head = toAdd;
    target->Tail = toAdd;
    toAdd->Owner = target;
  }
  LinkedListNode_InsertAfter(target->Tail, toAdd);
}

void LinkedList_AddEnd(LinkedList* target, LinkedListNode* toAdd);

LinkedListNode* LinkedListNode_New(char data) {
  LinkedListNode* result = malloc(sizeof(LinkedListNode));
  result->Data = data;
  return result;
}

void LinkedListNode_Free(LinkedListNode* target) {
  free(target);
}

void LinkedListNode_InsertBefore(LinkedListNode* target, LinkedListNode* toInsert) {
  LinkedListNode* previous = target->Previous;
  if (previous != NULL) {
    previous->Next = toInsert;
  }
  toInsert->Previous = previous;
  toInsert->Next = target;
  target->Previous = toInsert;
  if(target->Owner->Head == target) {
    target->Owner->Head = toInsert;
  }
  toInsert->Owner = target->Owner;
}

void LinkedListNode_InsertAfter(LinkedListNode* target, LinkedListNode* toInsert) {
  LinkedListNode* next = target->Next;
  if (next != NULL) {
    next->Previous = toInsert;
  }
  toInsert->Next = next;
  toInsert->Previous = target;
  target->Next = toInsert;
  if(target->Owner->Tail == target) {
    target->Owner->Tail = toInsert;
  }
  toInsert->Owner = target->Owner;
}
