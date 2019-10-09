#if INTERFACE

#include <stdlib.h>
#include "comparisons.h"

typedef struct Vertex {
  Connection *head;
  unsigned int connection_count;
  char *name;
  Vertex *next;
} Vertex;

typedef struct Connection {
  int cost;
  unsigned int index;
  Connection *next;
} Connection;

typedef struct ALGraph {
  Vertex *head;
  Vertex *tail;
  unsigned int vertex_count;
} ALGraph;

#endif

#include "al_graph.h"

ALGraph* AL_create() {
  ALGraph *result = malloc(sizeof(ALGraph));
  result->head = NULL;
  result->tail = NULL;
}

void al_add_vertex(ALGraph *graph, char *vertex) {
  Vertex *new_vertex = malloc(sizeof(Vertex));
  new_vertex->name = vertex;
  new_vertex->next = NULL;
  new_vertex->head = NULL;
  new_vertex->connection_count = 0;
  if (graph->head == NULL) {
    graph->head = new_vertex;
    graph->tail = new_vertex;
  } else {
    graph->tail->next = new_vertex;
    graph->tail = new_vertex;
  }
  graph->vertex_count++;
}

void vertex_add_connection(Vertex *vertex, unsigned int other_index, unsigned int cost) {
  Connection *new_connection = malloc(sizeof(Connection));
  new_connection->next = vertex->head;
  new_connection->cost = cost;
  new_connection->index = other_index;
  vertex->head = new_connection;
  vertex->connection_count++;
}

unsigned int am_get_vertex_index(ALGraph *graph, char *vertex) {
  Vertex *focus_vertex = graph->head;
  for (unsigned int i = 0; i < graph->vertex_count; i++) {
    ComparisonResult result = Comparisons_CompareStrings(focus_vertex->name, vertex);
    if (result == EQUAL) {
      return i;
    }
    focus_vertex = focus_vertex->next;
  }
}
