#ifndef COMPARISONS
#define COMPARISONS

typedef enum ComparisonResult {
  GREATER,
  EQUAL,
  LESSER
} ComparisonResult;

ComparisonResult Comparisons_CompareStrings(char* a, char* b);

#endif
