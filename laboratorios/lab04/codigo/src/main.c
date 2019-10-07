#include "binary_tree.h"


int main(int argc, char* argv[]) {
  unsigned int* values = {50, 30, 24, 5, 28, 45, 98, 52, 60};
  tree_print_post(values, sizeof(values));
}
