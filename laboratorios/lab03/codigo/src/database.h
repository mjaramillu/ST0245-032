#ifndef DATABASE
#define DATABASE

#include "course.h"
#include "student.h"
#include "comparisons.h"

typedef struct Database {
  Student* Students;
  unsigned long StudentCount;
  Course* Courses;
  unsigned long CourseCount;
} Database;

void Database_QueryStudentsFromCourse(Database* target, char* courseName, unsigned short semester);
void Database_QueryCoursesFromStudent(Database* target, char* studentName, unsigned short semester);

#endif
