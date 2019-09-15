#ifndef LINK
#define LINK

#include <stdlib.h>
#include "node.h"

typedef struct Node Node;

typedef struct Link {
  Node* Student;
  Node* Course;
  unsigned char Grade;
  unsigned short Semester;
} Link;

Link* Link_New(Node* student, Node* course, unsigned char grade, unsigned short semester);

void Link_Free(Link* target);

#endif
