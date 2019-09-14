#ifndef NODE
#define NODE

#include <stdlib.h>
#include "link.h"

typedef struct Node {
  char* Name;
  Link** Links;
  unsigned long LinkCount;
} Node;

void Node_AddLink(Node* target, Link* toAdd);

Node* Node_New(char* name);

void Node_Free(Node* target);

#endif
