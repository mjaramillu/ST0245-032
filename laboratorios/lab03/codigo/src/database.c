#include "database.h"

void Database_QueryStudentsFromCourse(Database* target, char* courseName, unsigned short semester) {
  Node* selectedCourse = NodeList_BalancedLookup(target->Courses, courseName);
  if (selectedCourse != NULL) {
    printf("The course was found!\n");
    for(unsigned long i = 0; i < selectedCourse->LinkCount; i++) {
      if(selectedCourse->Links[i]->Semester == semester) {
        char* studentName = selectedCourse->Links[i]->Student->Name;
        unsigned char grade = selectedCourse->Links[i]->Grade;
        printf("%s - %d\n", studentName, grade);
      }
    }
  } else {
    printf("Unable to find course %s\n", courseName);
  }
}

void Database_QueryCoursesFromStudent(Database* target, char* studentName, unsigned short semester) {
  Node* selectedStudent = NodeList_BalancedLookup(target->Students, studentName);
  if (selectedStudent != NULL) {
    printf("The student was found!\n");
    for(unsigned long i = 0; i < selectedStudent->LinkCount; i++) {
      if(selectedStudent->Links[i]->Semester == semester) {
        char* courseName = selectedStudent->Links[i]->Course->Name;
        unsigned char grade = selectedStudent->Links[i]->Grade;
        printf("%s - %d\n", courseName, grade);
      }
    }
  } else {
    printf("Unable to find student %s\n", studentName);
  }
}

Database* Database_New() {
  Database* result = malloc(sizeof(Database));
  result->Students = NodeList_New();
  result->Courses = NodeList_New();
  return result;
}
void Database_Free(Database* target) {
  NodeList_Free(target->Students);
  NodeList_Free(target->Courses);
  free(target);
}

void Database_PopulateFromCSV(Database* target, char* path) {
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen(path, "r");
  if (fp == NULL) {
    printf("Unable to load file %s!\n", path);
    return;
  }
  while((read = getline(&line, &len, fp)) != -1) {
    unsigned char columnId = 0;
    char* ptr = strtok(line, ",");
    while(ptr != NULL) {
      printf("%d - %s\n", columnId, ptr);
      ptr = strtok(NULL, ",");
      columnId++;
    }
  }
  fclose(fp);
  if (line) {
    free(line);
  }
}
