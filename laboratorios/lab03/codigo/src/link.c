#include "link.h"

Link* Link_New(Node* student, Node* course, unsigned char grade, unsigned short semester) {
  Link* result = malloc(sizeof(Link));
  result->Student = student;
  result->Course = course;
  result->Grade = grade;
  result->Semester = semester;
  Node_AddLink(student, result);
  Node_AddLink(course, result);
  return result;
}

void Link_Free(Link* target) {
  free(target);
}
