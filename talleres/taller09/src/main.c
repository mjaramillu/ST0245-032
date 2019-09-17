#include <stdio.h>
#include "directory.h"

int main(int argc, char* argv[]) {
  Directory* dir = Directory_New(64);
  Directory_Add(dir, DirectoryEntry_New("Puli", 3405738593));
  Directory_Add(dir, DirectoryEntry_New("Yo", 3045625371));
  Directory_Add(dir, DirectoryEntry_New("Mauro Jaramillo", 3045422431));
  printf("%u\n", Directory_Lookup(dir, "Mauro Jaramillo")->Number);
  printf("%u\n", Directory_Lookup(dir, "Yo")->Number);
  printf("%u\n", Directory_Lookup(dir, "Puli")->Number);
}
