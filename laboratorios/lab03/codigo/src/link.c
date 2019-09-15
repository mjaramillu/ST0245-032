#include "link.h"

Link* Link_New(Node* student, Node* course, unsigned char grade, unsigned short semester) {
  Link* result = malloc(sizeof(Link));
  result->Student = student;
  result->Course = course;
  result->Grade = grade;
  result->Semester = semester;
  printf("Adding to student\n");
  Node_AddLink(student, result);
  printf("Adding to course\n");
  Node_AddLink(course, result);
  return result;
}

void Link_Free(Link* target) {
  free(target);
}
