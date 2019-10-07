
#if INTERFACE
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

#include "utils.h"

bool read_line_by_line(char* path, void (*f)(char*, unsigned int, unsigned int)) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  fp = fopen(path, "r");
  if (fp == NULL) {
    fclose(fp);
    return false;
  }
  unsigned int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    f(line, read, i);
    i++;
  }
  fclose(fp);
  if (line) {
    free(line);
  }
  return true;
}

char* get_str_copy(char *original) {
  unsigned long new_size = strlen(original) + (1 * sizeof(char));
  char *buffer = malloc(new_size);
  strcpy(original, buffer);
  return buffer;
}

char* fix_str(char *original) {
  char *new = get_str_copy(original);
  free(original);
  return new;
}
