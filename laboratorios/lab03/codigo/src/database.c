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

  unsigned long lineId = 0;

  char* previousStudentName = "";
  char* previousCourseName = "";
  unsigned char previousGrade = 0;
  unsigned short previousSemester = 0;

  while((read = getline(&line, &len, fp)) != -1) {
    if ((read > 1) & (lineId != 0)) {
      unsigned char columnId = 0;

      char* studentName;
      char* courseName;
      unsigned char grade;
      unsigned short semester;

      char* ptr = strtok(line, ",");
      while(ptr != NULL) {
        //printf("%d - %s\n", columnId, ptr);
        if (columnId == 0) {
          studentName = malloc(sizeof(char) * (strlen(ptr) + 1));
          strcpy(studentName, ptr);
        }
        if (columnId == 8) {
          courseName = malloc(sizeof(char) * (strlen(ptr) + 1));
          strcpy(courseName, ptr);
        }
        if (columnId == 3) {
          char* end;
          semester = strtol(ptr, &end, 10);
        }
        if (columnId == 10) {
          char* end;
          grade = strtol(ptr, &end, 10);
        }
        ptr = strtok(NULL, ",");
        columnId++;
      }
      if (columnId == 11) {
        ComparisonResult studentNameComparison = Comparisons_CompareStrings(previousStudentName, studentName);
        ComparisonResult courseNameComparison = Comparisons_CompareStrings(previousCourseName, courseName);
        if ((courseNameComparison != EQUAL) | (studentNameComparison != EQUAL) | (previousGrade != grade) | (previousSemester != semester)) {
          printf("%s - %s - %d - %d\n", studentName, courseName, semester, grade);
          printf("Looking up student %s\n", studentName);
          Node* studentNode = NodeList_BalancedLookup(target->Students, studentName);
          if (studentNode == NULL) {
            printf("Student %s not found! Creating it...\n", studentName);
            studentNode = Node_New(studentName);
            printf("Adding to list...\n");
            NodeList_Append(target->Students, studentNode);
            //NodeList_Debug(target->Students);
          }
          Node* courseNode = NodeList_BalancedLookup(target->Courses,courseName);
          if (courseName == NULL) {
            printf("Course %s not found! Creating it...\n", courseName);
            courseNode = Node_New(courseName);
            printf("Adding to list...\n");
            NodeList_Append(target->Courses, courseNode);
          }
          previousStudentName = studentName;
          previousCourseName = courseName;
          previousGrade = grade;
          previousSemester = semester;
        }
      }
    }
    lineId++;
  }
  fclose(fp);
  if (line) {
    free(line);
  }
}
