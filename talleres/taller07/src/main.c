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

char LinkedList_GetAt (LinkedList* target, u64 index) {
  if (index < result->Length) {
    ListNode_GetRecursive(target->First, index);
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
  return ListNode_GetRecursive(ListNode_GetRecursive(target->Next, depth-1));
}

int main(int argc, char* argv[]) {
  printf("Holi mundo :v\n");
  return 0;
}
