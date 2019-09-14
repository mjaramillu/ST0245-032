#include "database.h"

void Database_QueryStudentsFromCourse(Database* target, char* courseName, unsigned short semester) {
  unsigned long start = 0;
  unsigned long end = target->CourseCount - 1;
  unsigned long pivot;
  unsigned long diff = end;
  unsigned char foundTarget = 0;
  while(diff > 1) {
    diff = end - start;
    pivot = diff / 2;
    char* pivotName = target->Courses[pivot]->Name;
    ComparisonResult comparison = Comparisons_CompareStrings(courseName,pivotName);
    if (comparison == GREATER) { start = pivot + 1; }
    if (comparison == LESSER) { end = pivot - 1; }
    if (comparison == EQUAL) {
      foundTarget = 1;
      break;
    }
  }
  if (foundTarget) {
    printf("The course was found!\n");
    Course* selectedCourse = target->Courses[pivot]
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
