#if INTERFACE

#include "al_graph.h"
#include <stdbool.h>

typedef struct VertexBufferObject {
  Vertex *vertex;
  VertexBufferObject *next;
} VertexBufferObject;

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
      c = c->next;
    }
    return false;
  }
  bool result = graph_ops_dfs_internal(start);
  free(vertex_flags);
  return result;
}

bool graph_ops_path_exists_afs (ALGraph *graph, char *a, char *b) {
  bool *vertex_flags = calloc(graph->vertex_count, sizeof(bool));

  Vertex *start = al_get_vertex(graph, a);
  Vertex *end = al_get_vertex(graph, b);

  VertexBufferObject *buffer;
  unsigned int object_count = 0;

  VertexBufferObject *old_buffer;
  unsigned int old_object_count = 0;

  void add_vertex(VertexBufferObject **target, unsigned int *count, Vertex *vertex) {
    VertexBufferObject *new = malloc(sizeof(VertexBufferObject));
    new->vertex = vertex;
    if (*target != NULL) {
      new->next = *target;
    }
    *target = new;
    *count++;
  }

  void buffer_free(VertexBufferObject *target) {
    VertexBufferObject *c = target;
    while (c!=NULL) {
      VertexBufferObject *to_free = c;
      c = c->next;
      free(to_free);
    }
  }

  void add_from_vertex(VertexBufferObject **target, unsigned int *count, Vertex *vertex) {
    Connection *c = target->head;
    while (c != NULL) {
      Vertex *vert = al_get_vertex_from_index(graph, c->index);
      add_vertex(target, count, vert);
      c = c->next;
    }
  }

  add_from_vertex(&old_buffer, &old_object_count, start);

  while (old_object_count != 0) {
    VertexBufferObject *b = old_buffer;
    buffer_free(buffer);
    while (b != NULL) {
      if (v->vertex == end) {
        return true;
      }
      add_from_vertex(&buffer, &object_count, v->vertex);
      b = b->next;
    }
    old_buffer = buffer;
    old_object_count = object_count;
  }

  free(vertex_flags);
  return result;
}
