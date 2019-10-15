#if INTERFACE

#include "al_graph.h"
#include <stdbool.h>

#endif

#include "graph_ops.c"




bool graph_ops_path_exists_dfs (ALGraph *graph, char *a, char *b) {
  bool *vertex_flags = calloc(graph->vertex_count, sizeof(bool));

  Vertex *start = al_get_vertex(graph, a);
  unsigned int end_index = al_get_vertex_index(graph, b);

  bool graph_ops_dfs_internal (Vertex *focus) {
    vertex_flags[c->index] = true;
    Connection *c = start->head;
    while (c != NULL) {
      if (vertex_flags[c->index] == false) {

        if (c->index == end_index) {
          return true;
        }
        Vertex *next = al_get_vertex_from_index(graph, c->index);

        if (graph_ops_dfs_internal(next)) {
          return true;
        }
      }
    }
    return false;
  }
  bool result = graph_ops_dfs_internal(start);
  free(vertex_flags);
  return result;
}
