
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

char* str_append_with_space(char *a, char *b) {
  unsigned int len_a = strlen(a);
  unsigned int len_b = strlen(b);
  unsigned int new_len = len_a + 1 + len_b + 1;
  char *result = malloc(sizeof(char) * new_len);
  for (unsigned int i = 0; i < len_a; i++) {
    result[i] = a[i];
  }
  result[len_a] = ' ';
  for (unsigned int i = 0; i < len_b; i++) {
    unsigned int index = i + len_a + 1;
    result[index] = b[i];
  }
  result[new_len - 1] = '\0';
  return result;
}

char* fix_str(char *original) {
  char *new = get_str_copy(original);
  free(original);
  return new;
}
