#ifndef TREE 
#define TREE 
 /* This file was automatically generated.  Do not edit! */
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Node Node;
struct Node {
  Node* left;
  Node* right;
  int value;
};
Node *node_lookup(Node *node,int value);
void node_insert(Node *node,int value);
void node_print_text(Node *node);
Node *node_create(int value);
#define INTERFACE 0 
#endif
