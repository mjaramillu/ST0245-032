#if INTERFACE

#include "file_descriptor.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define KILOBYTE 1024
#define MEGABYTE (KILOBYTE * 1024)
#define GIGABYTE (MEGABYTE * 1024)
#define FOLDER_SIZE (KILOBYTE * 4)
#define ROOT_USER ("root")

typedef struct Folder {
  FileDescriptor *descriptor;
  FileDescriptor **files;
  unsigned long file_count;
  Folder **subdirectories;
  unsigned long subdirectory_count;
} Folder;

#endif


#include "filesystem.h"

void folder_add_subdir(Folder *folder, folder *subdir) {
  Folder **new_folders = malloc(sizeof(Folder) * (folder->subdirectory_count + 1));
  for (unsigned int i = 0; i < folder->subdirectory_count; i++) {
    new_folders[i] = folder->subdirectories[i];
  }
  new_folders[folder->subdirectory_count] = subdir;
  free(folder->subdirectories);
  folder->subdirectories = new_folders;
}

void folder_add_file(Folder *folder, FileDescriptor *file) {
  Folder **new_files = malloc(sizeof(FileDescriptor) * (folder->file_count + 1));
  for (unsigned int i = 0; i < folder->file_count; i++) {
    new_files[i] = folder->files[i];
  }
  new_files[folder->file_count] = file;
  free(folder->files);
  folder->files = new_files;
}

Folder* folder_new(char* username, char* name) {
  FileDescriptor *descriptor = file_descriptor_new(username, name, FOLDER_SIZE);
  Folder *result = malloc(sizeof(Folder));
  return result;
}

Folder* folder_from_descriptor(FileDescriptor *descriptor) {
  Folder *result = folder_new(descriptor->username, descriptor->filename);
  free(descriptor);
  return result;
}

Folder* filesystem_parse(char *path) {
  //Folder stack management.
  Folder *folder_stack[128];
  unsigned char folder_stack_index = 0;
  Folder* pop_folder() {
    Folder *result = folder_stack[folder_stack_index];
    folder_stack_index--;
    return result;
  }
  void push_folder(Folder *to_push) {
    folder_stack_index++;
    folder_stack[folder_stack_index] = to_push;
  }
  Folder* get_folder() {
    return folder_stack[folder_stack_index];
  }
  void set_folder(Folder *to_set) {
    folder_stack[folder_stack_index] = to_set;
  }

  //File reading.
  FileDescriptor *last_descriptor = NULL;
  bool read_file;
  void read_function (char* line, unsigned int length, unsigned int line_id) {
    unsigned int depth = 4 * (folder_stack_index + 1);
    if (line_id == 1) {
      char *folder_name = get_str_copy(line);
      unsigned int len = strlen(folder_name);
      for(unsigned int i = len - 1; i >= 0; i--) {
        if (folder_name[i] == '/') {
          folder_name[i] = '\0';
        }
      }
      Folder *fs_root = folder_new(ROOT_USER, folder_name);
      set_folder(fs_root);
      return;
    }
    char *padding = malloc(128 * sizeof(char));
    char *name = malloc(128 * sizeof(char));
    char *filesize = malloc(128 * sizeof(char));
    char *filename = malloc(128 * sizeof(char));
    sscanf(line, "%*c%[^[]%*c%[^ ] %*c%[^]]]  %99[^\n]", padding, name, filesize, filename);
    padding = fix_str(padding);
    name = fix_str(name);
    filesize = fix_str(filesize);
    filename = fix_str(filename);
    if (strlen(padding) > depth) {
      Folder* new_folder = folder_from_descriptor(last_descriptor);
      folder_add_subdir(get_folder(), new_folder);
      push_folder(new_folder);
    }
    if (strlen(padding) < depth) {
      if (last_descriptor != NULL) {
        folder_add_file(get_folder(), lastFile);
      }
      unsigned int diff = (depth - strlen(padding))/4;
      for (unsigned int i = 0; i < diff; i++) {
        pop_folder();
      }
    }
    if (strlen(padding) == depth) {
      if (last_descriptor != NULL) {
        folder_add_file(get_folder(), lastFile);
      }
    }
    unsigned int size = 0;
    char mult = 'A';
    char *new_filesize = malloc(sizeof(char) * (filesize + 1));
    for (int i = 0; i <= strlen(filesize); i++) {
      if ((filesize[i] == 'K') | (filesize[i] == 'M') | (filesize[i] == 'G')) {
        mult = filesize[i];
        new_filesize[i] = '\0';
        break;
      }
      if (i == strlen(filesize)) {
        new_filesize[i] = '\0';
        break;
      }
      new_filesize[i] = filesize[i];
    }
    free(filesize);
    if(mult == 'A') {
      char* end;
      size = strtol(new_filesize, &end, 10);
    } else {
      float float_size = atof(new_filesize);
      if (mult == 'K') {
        size = (float_size * KILOBYTE);
      }
      if (mult == 'M') {
        size = (float_size * MEGABYTE);
      }
      if (mult == 'G') {
        size = (float_size * GIGABYTE);
      }
    }
    last_descriptor = file_descriptor_new(username, filename, size);
    free(new_size);
    free(padding);
  }
  read_file = read_line_by_line(path, read_function);
  if (read_file) {
    return folder_stack[0];
  }
  else {
    return NULL;
  }
}
