#ifndef COURSE
#define COURSE

#include "link.h"

typedef struct Course {
  char* Name;
  Link* Links;
  unsigned long LinkCount;
} Course;

#endif
