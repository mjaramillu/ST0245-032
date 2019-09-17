#ifndef NODELIST
#define NODELIST

#include <stdio.h>
#include "node.h"
#include "comparisons.h"

typedef struct NodeList {
  Node** Data;
  unsigned long Size;
} NodeList;

unsigned long NodeList_BalancedLookupIndex(NodeList* target, char* nameToFind);

Node* NodeList_BalancedLookup(NodeList* target, char* nameToFind);

void NodeList_Append(NodeList* target, Node* toInsert);

void NodeList_Sort(NodeList* target);

void NodeList_Debug(NodeList* target);

NodeList* NodeList_New();

void NodeList_Free(NodeList* target);

#endif
