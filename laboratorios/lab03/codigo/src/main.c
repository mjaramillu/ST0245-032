#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int main(int argc, char* argv[]) {
  Database* testDb = Database_New();
  Database_PopulateFromCSV(testDb, "./datasets/NOTAS-ST0242.csv");
  Database_Free(testDb);
  return 0;
}
