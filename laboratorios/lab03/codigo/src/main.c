#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int main(int argc, char* argv[]) {
  Database* testDb = Database_New();
  Database_PopulateFromCSV(testDb, "./datasets/joined.csv");
  //NodeList_Debug(testDb->Students);
  Database_QueryStudentsFromCourse(testDb, "\"FUNDAMENTOS DE PROGRAMACIÓN\"", 20142);
  Database_QueryCoursesFromStudent(testDb, "Adón", 20142);
  Database_Free(testDb);
  return 0;
}
