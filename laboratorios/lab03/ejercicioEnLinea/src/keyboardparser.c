#include "keyboardparser.h"

void KeyboardParser_Parse(char* input) {
  LinkedList* result = LinkedList_New();
  LinkedListNode* selectedNode = NULL;
  unsigned char flag = 0;
  for (unsigned long i = 0; input[i] != '\0'; i++) {
    if(input[i] == ']') {
      selectedNode = result->Tail;
      continue;
    }
    if(input[i] == '[') {
      flag = 1;
      selectedNode = result->Head;
      continue;
    }
    LinkedListNode* newNode = LinkedListNode_New(input[i]);
    if (selectedNode != NULL) {
      if (flag == 1) {
        LinkedListNode_InsertBefore(selectedNode, newNode);
        flag = 0;
      } else {
        LinkedListNode_InsertAfter(selectedNode, newNode);
      }
    } else {
      LinkedList_AddBeginning(result, newNode);
    }
    selectedNode = newNode;
  }
  LinkedList_Print(result);
  LinkedList_Free(result);
}
