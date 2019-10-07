#if INTERFACE

#include <stdlib.h>

typedef struct FileDescriptor {
  char* username;
  char* filename;
  unsigned long filesize;
} FileDescriptor;

#endif

#include "file_descriptor.h"

FileDescriptor* file_descriptor_new(char* username, char* filename, unsigned long filesize) {
  FileDescriptor *result = malloc(sizeof(FileDescriptor));
  result->username = username;
  result->filename = filename;
  result->filesize = filesize;
  return result;
}
