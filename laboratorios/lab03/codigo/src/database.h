#ifndef DATABASE
#define DATABASE

#include "nodelist.h"

typedef struct Database {
  NodeList* Students;
  NodeList* Courses;
} Database;

void Database_QueryStudentsFromCourse(Database* target, char* courseName, unsigned short semester);
void Database_QueryCoursesFromStudent(Database* target, char* studentName, unsigned short semester);

Database* Database_New();
void Database_Free(Database* target);


#endif
