
#if INTERFACE

#include <stdlib.h>
#include <stdio.h>
#include "comparisons.h"

typedef struct AMGraph {
  unsigned char **vertices;
  unsigned int vertex_count;
  int *matrix;
} DigraphAM;

#endif

#include "am_graph.h"

AMGraph* AM_create() {
  AMGraph* result = malloc(sizeof(AMGraph));
  result->vertex_count = 0;
  result->vertices = NULL;
  result->matrix = NULL;
}

void matrix_set_value(int *matrix, unsigned int side, unsigned int x, unsigned int y, int value) {
  unsigned int index = (x*side)+y;
  matrix[index] = value;
}

int matrix_get_value(int *matrix, unsigned int side, unsigned int x, unsigned int y) {
  unsigned int index = (x*side)+y;
  return matrix[index];
}

void am_add_vertex(AMGraph *graph, char *vertex) {
  unsigned char **new_vertices = malloc(sizeof(unsigned char*) * (graph->vertex_count + 1));
  for (unsigned int i = 0; i < graph->vertex_count; i++) {
    new_vertices[i] = graph->vertices[i];
  }
  new_vertices[graph->vertex_count] = vertex;
  free(graph->vertices);
  graph->vertices = new_vertices;
  int *new_matrix = malloc(sizeof(int) * (graph->vertex_count + 1) * (graph->vertex_count + 1));
  for (unsigned int x = 0; x < graph->vertex_count; x++) {
    for (unsigned int y = 0; y < graph->vertex_count; y++) {
      int value = matrix_get_value(graph->matrix, graph->vertex_count, x, y);
      matrix_set_value(new_matrix, graph->vertex_count + 1, x, y, value);
    }
  }
  free(graph->matrix);
  graph->matrix = new_matrix;
  graph->vertex_count++;
}

unsigned int am_get_vertex_index(AMGraph *graph, char *vertex) {
  for (unsigned int i = 0; i < graph->vertex_count; i++) {
    ComparisonResult result = Comparisons_CompareStrings(graph->vertices[i], vertex);
    if (result == EQUAL) {
      return i;
    }
  }
}

void am_set_connection_index (AMGraph *graph, unsigned int a, unsigned int b, int cost) {
  matrix_set_value(graph->matrix, graph->vertex_count, a, b, cost);
}

void am_set_connection (AMGraph *graph, char *a, char *b, int cost) {
  unsigned int a_index = am_get_vertex_index(graph, a);
  unsigned int b_index = am_get_vertex_index(graph, b);
  am_set_connection_index(graph, a_index, b_index, cost);
}

void am_set_bi_connection (AMGraph *graph, char *a, char *b, int cost) {
  unsigned int a_index = am_get_vertex_index(graph, a);
  unsigned int b_index = am_get_vertex_index(graph, b);
  am_set_connection_index(graph, a_index, b_index, cost);
}

void am_print_graph (AMGraph *graph) {
  for (unsigned int i = 0; i < graph->vertex_count; i++) {
    for (unsigned int j = 0; j < graph->vertex_count; j++) {
      int value = matrix_get_value(graph->matrix, graph->vertex_count, i, j);
      if (value != 0) {
        char *left_name = graph->vertices[i];
        char *right_name = graph->vertices[j];
        printf("\"%s\"->\"%s\"\n", left_name, right_name);
      }
    }
  }
}
