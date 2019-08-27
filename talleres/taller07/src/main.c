#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long int

typedef struct LinkedList {
  ListNode* First;
  u64 Length;
} LinkedList;

LinkedList* LinkedList_Create() {
  LinkedList* result = malloc(sizeof(LinkedList));
  result->First = NULL;
  result->Length = 0;
  return result;
}

void LinkedList_Free (LinkedList* target) {
  free(target);
}

void LinkedList_InsertAtHead (LinkedList* target, char value) {
  ListNode* newNode = ListNode_Create(value);
  newNode->Next = target->First;
  target->First = newNode;
}

void LinkedList_InsertAt (LinkedList* target, u64 index, char value) {
  if (index < result->Length) {
    if (index == 0) {
      LinkedList_InsertAtHead(target, value);
    }
    ListNode_InsertRecursive(target, index - 1, value);
    ListNode->Length += 1;
  }
}

char LinkedList_GetAt (LinkedList* target, u64 index) {
  if (index < result->Length) {
    ListNode_GetRecursive(target->First, index);
  }
}

void LinkedList_RemoveAtHead (LinkedList* target) {
  ListNode* headElement = target->First;
  if (headElement->Next != NULL) {
    target->First = headElement->Next;
  }
  LinkedList_Free(headElement);
}

void LinkedList_RemoveAt (LinkedList* target, u64 index) {
  if (index < result->Length) {
    if (index == 0) {
      LinkedList_RemoveAtHead(target);
    }
    ListNode_RemoveRecursive(target->First, index - 1);
  }
}

u64 LinkedList_Size(LinkedList* target) {
  return Length;
}

typedef struct ListNode {
  ListNode* Next;
  char Value;
} ListNode;

ListNode* ListNode_Create(char value) {
  ListNode* result = malloc(sizeof(ListNode));
  result->Value = value;
  return result;
}

void ListNode_Free(ListNode* target) {
  free(target);
}

char ListNode_GetRecursive (ListNode* target, u64 depth) {
  if (depth == 0) {
    return target->Value;
  }
  return ListNode_GetRecursive(target->Next, depth-1);
}

void ListNode_InsertRecursive (ListNode* target, u64 depth, char value) {
  if (depth == 0) {
    ListNode* newNode = ListNode_Create(value);
    newNode->Next = target->Next;
    target->Next = newNode;
    return 0;
  }
  ListNode_InsertRecursive(target->Next, depth - 1, value);
}

void ListNode_RemoveRecursive (ListNode* target, u64 depth) {
  if (depth == 0) {
    ListNode* next = target->Next;
    if (next->Next != NULL) {
      target->Next = next->Next;
    }
    ListNode_Free(next);
    return 0;
  }
  ListNode_InsertRecursive(target->Next, depth - 1, value);
}

int main(int argc, char* argv[]) {
  printf("Holi mundo :v\n");
  return 0;
}
