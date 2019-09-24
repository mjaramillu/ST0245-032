#if INTERFACE

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

typedef Node Node;

typedef struct Node {
  Node* left;
  Node* right;
  int value;
} Node;

#endif

#include "tree.h"

Node* node_create(int value) {
  Node* result = malloc(sizeof(Node));
  result->value = value;
  result->left = NULL;
  result->right = NULL;
  return result;
}

void node_print_text(Node *node) {
  if (node->left != NULL) {
    printf("\"%d\" -> \"%d\"\n", node->value, node->left->value);
    node_print_text(node->left);
  }
  if (node->right != NULL) {
    printf("\"%d\" -> \"%d\"\n", node->value, node->right->value);
    node_print_text(node->right);
  }
}

void node_insert(Node *node, int value) {
  if (node->value > value) {
    if (node->right != NULL) {
      if (node->right->value == value) { return; }
      node_insert(node->right, value);
    } else {
      node->right = node_create(value);
    }
  }
  if (node->value < value) {
    if (node->left != NULL) {
      if (node->left->value == value) { return; }
      node_insert(node->left, value);
    } else {
      node->left = node_create(value);
    }
  }
}

Node* node_lookup(Node *node, int value) {
  if (node->value == value) {
    return node;
  }
  if (node->value > value) {
    if (node->right != NULL) {
      node_lookup(node->right, value);
    } else {
      return NULL;
    }
  }
  if (node->value < value) {
    if (node->left != NULL) {
      node_lookup(node->left, value);
    } else {
      return NULL;
    }
  }
}
