#ifndef LINK
#define LINK

#include "node.h"

typedef struct Link {
  Node* Student;
  Node* Course;
  unsigned char Grade;
  unsigned char Semester;
} Link;

#endif
