#if INTERFACE

typedef struct Node {
  unsigned int value;
  Node *a;
  Node *b;
}

#endif

#include "binary_tree.h"

Node *node_new(unsigned int value) {
  Node *result = malloc(sizeof(Node));
  result->value = value;
  result->a = NULL;
  result->b = NULL;
  return result;
}

void tree_rec_insert(Node *node, unsigned int value) {
  if (value > node->value) {
    if (node->right != NULL) {
      tree_rec_insert(node->right, value);
    }
    else {
      node->right = node_new(value);
    }
  }
  if (value < node->value) {
    if (node->left != NULL) {
      tree_rec_insert(node->left, value);
    }
    else {
      node->left = node_new(value);
    }
  }
}
void print_tree_pos_rec(Node *node) {
  if (node->left != NULL) {
    print_tree_pos_rec(node->left);
  }
  if (node->right != NULL) {
    print_tree_pos_rec(node->right);
  }
  printf("%d\n", node->value);
}

void tree_print_post(unsigned int *values, unsigned int count) {
  Node *root = node_new(values[0]);
  for (int i = 1; i < count; i++) {
    tree_rec_insert(values[i]);
  }
  print_tree_pos_rec(root);
}
