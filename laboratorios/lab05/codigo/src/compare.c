
#include "compare.h"

char compare_strings(char* a, char* b) {
  unsigned short index = 0;
  while (1) {
    if ((a[index] == '\0') & (b[index] == '\0')) {
      return 0;
    }
    if (b[index] == '\0') {
      return 1;
    }
    if (a[index] == '\0') {
      return -1;
    }
    if (a[index] > b[index]) {
      return 1;
    }
    if (b[index] > a[index]) {
      return -1;
    }
    index++;
  }
}
