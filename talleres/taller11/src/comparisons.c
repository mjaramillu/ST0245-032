#if INTERFACE

typedef enum ComparisonResult {
  GREATER,
  EQUAL,
  LESSER
} ComparisonResult;

#endif

#include "comparisons.h"

ComparisonResult Comparisons_CompareStrings(char* a, char* b) {
  unsigned short index = 0;
  while (1) {
    if ((a[index] == '\0') & (b[index] == '\0')) {
      return EQUAL;
    }
    if (b[index] == '\0') {
      return GREATER;
    }
    if (a[index] == '\0') {
      return LESSER;
    }
    if (a[index] > b[index]) {
      return GREATER;
    }
    if (b[index] > a[index]) {
      return LESSER;
    }
    index++;
  }
}
