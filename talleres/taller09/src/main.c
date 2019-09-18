#include <stdio.h>
#include "directory.h"
#include "companies.h"

int main(int argc, char* argv[]) {
  Directory* dir = Directory_New(64);
  Directory_Add(dir, DirectoryEntry_New("Puli", 3405738593));
  Directory_Add(dir, DirectoryEntry_New("Yo", 3045625371));
  Directory_Add(dir, DirectoryEntry_New("Mauro Jaramillo", 3045422431));
  printf("%u\n", Directory_Lookup(dir, "Mauro Jaramillo")->Number);
  printf("%u\n", Directory_Lookup(dir, "Yo")->Number);
  printf("%u\n", Directory_Lookup(dir, "Puli")->Number);
  Companies* comps = Companies_New(64);
  Companies_Add(comps, CompaniesEntry_New("Google", "US"));
  Companies_Add(comps, CompaniesEntry_New("La locura", "Colombia"));
  Companies_Add(comps, CompaniesEntry_New("Nokia", "Finlandia"));
  Companies_Add(comps, CompaniesEntry_New("Sony", "Japón"));
  printf("%s\n", Companies_Lookup(comps, "La locura")->Country);
}
