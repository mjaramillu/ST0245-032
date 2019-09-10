#ifndef STUDENT
#define STUDENT

#include "link.h"

typedef struct Student {
  char* Name;
  Link* Links;
  unsigned long LinkCount;
} Student;

#endif
