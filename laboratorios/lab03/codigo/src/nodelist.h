#ifndef NODELIST
#define NODELIST

#include "node.h"
#include "comparisons.h"

typedef struct NodeList {
  Node** Data;
  unsigned long Size;
} NodeList;

unsigned long NodeList_BalancedLookupIndex(NodeList* target, char* nameToFind);

Node* NodeList_BalancedLookup(NodeList* target, char* nameToFind);

#endif
