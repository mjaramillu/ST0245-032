#ifndef DATABASE
#define DATABASE

#include "course.h"
#include "student.h"
#include "comparisons.h"

typedef struct Database {
  Node** Students;
  unsigned long StudentCount;
  Node** Courses;
  unsigned long CourseCount;
} Database;

void Database_QueryStudentsFromCourse(Database* target, char* courseName, unsigned short semester);
void Database_QueryCoursesFromStudent(Database* target, char* studentName, unsigned short semester);

#endif
