#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char *test = "├── [mauriciotoro  12M]  007 - GoldenEye (USA).n64";
  char *test2 = malloc(200);
  char *test3 = malloc(200);
  char *test4 = malloc(200);
  char *test5 = malloc(200);
  sscanf(test, "%*c%[^[]%*c%[^ ] %*c%[^]]]  %99[^\n]", test2, test3, test4, test5);
  printf("%s\n", test2);
  printf("%s\n", test3);
  printf("%s\n", test4);
  printf("%s\n", test5);
}
