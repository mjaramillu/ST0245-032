#ifndef LINK
#define LINK

#include <stdlib.h>
#include "node.h"

typedef struct Link {
  Node* Student;
  Node* Course;
  unsigned char Grade;
  unsigned short Semester;
} Link;

Link* Link_New(Node* student, Node* course, unsigned char Grade, unsigned short Semester);

void Link_Free(Link* target);

#endif
