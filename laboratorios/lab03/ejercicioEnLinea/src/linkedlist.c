#include "linkedlist.h"

LinkedList* LinkedList_New() {
  LinkedList* result = malloc(sizeof(LinkedList));
  return result;
}

LinkedList* LinkedList_NewFromString(char* input) {
  LinkedList* result = LinkedList_New();
  LinkedListNode* previous = NULL;
  for (unsigned long i = 0; input[i] != "\0"; i++) {
    LinkedListNode* this = LinkedListNode_New(input[i]);
    this->Previous = previous;
    if (previous != NULL) {
      previous->Next = this;
    } else {
      result->Head = this;
    }
    previous = this;
  }
  result->Tail = previous;
}

void LinkedList_Free(LinkedList* target) {
  free(target);
}

LinkedListNode LinkedListNode_New(char data) {
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
}

void LinkedListNode_InsertAfter(LinkedListNode* target, LinkedListNode* toInsert) {
  LinkedListNode* next = target->Next;
  if (next != NULL) {
    next->Previous = toInsert;
  }
  toInsert->Next = next;
  toInsert->Previous = target;
  target->Next = toInsert;
}
