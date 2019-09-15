#include "node.h"

Node* Node_New(char* name) {
  Node* result = malloc(sizeof(Node));
  result->Name = name;
  return result;
}

void Node_Free(Node* target) {
  free(target);
}

void Node_AddLink(Node* target, Link* toAdd) {
  Link** newLinks = malloc(sizeof(Link*) * (target->LinkCount + 1));
  for (unsigned long i = 0; i < target->LinkCount; i++) {
    newLinks[i] = target->Links[i];
  }
  newLinks[target->LinkCount] = toAdd;
  free(target->Links);
  target->Links = newLinks;
  target->LinkCount++;
}
