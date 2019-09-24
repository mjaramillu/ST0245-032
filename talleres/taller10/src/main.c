#include <stdio.h>
#include "tree.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
  Node* root = node_create(42);
  node_insert(root, 4);
  node_insert(root, 85);
  node_insert(root, 24);
  node_insert(root, 59);
  node_insert(root, 100);
  node_insert(root, 53);
  node_insert(root, 173);
  printf("%x\n", node_lookup(root, 100));
  node_print_text(root);
}
