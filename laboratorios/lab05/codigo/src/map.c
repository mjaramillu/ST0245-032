#if INTERFACE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "utils.h"
#include "compare.h"

typedef struct Edge {
  Vertex *a;
  Vertex *b;
  float distance;
  char *name;
  Edge *next;
} Edge;

typedef struct Vertex {
  Edge *head;
  unsigned int EdgeCount;
  unsigned long long id;
  float x;
  float y;
  char *name;
  Vertex *next;
} Vertex;

typedef struct Map {
  Vertex *head;
  unsigned int vertex_count;
} Map;

#endif

#include "map.h"

Edge *edge_create(Vertex *a, Vertex *b, float distance, char *name) {
  Edge *edge = malloc(sizeof(Edge));
  edge->a = a;
  edge->b = b;
  edge->distance = distance;
  edge->name = name;
  return edge;
}

void vertex_add_edge(Vertex *vertex, Edge *edge) {
  if(vertex->head != NULL) {
    edge->next = vertex->head;
  }
  vertex->head = edge;
}

Vertex *map_get_vertex_from_id(Map *map, unsigned long long id) {
  Vertex *focus = map->head;
  while(focus != NULL) {
    if(focus->id == id) {
      return focus;
    }
    focus = focus->next;
  }
  if(focus->id == id) {
    return focus;
  }
  return NULL;
}

Map *map_create() {
  Map *map = malloc(sizeof(Map));
  return map;
  return map;
}

void map_add_vertex(Map *map, Vertex *vertex) {
  if (map->head != NULL) {
    vertex->next = map->head;
  }
  map->head = vertex;
}

Vertex *vertex_create(unsigned long long id, float x, float y, char *name) {
  Vertex *vertex = malloc(sizeof(Vertex));
  vertex->id = vertex;
  vertex->x = x;
  vertex->y = y;
  vertex->name = name;
  return vertex;
}

Map *map_from_file(char *path) {
  Map *map = map_create();
  bool reading_vertices = false;
  bool reading_edges = false;
  void read_function (char* line, unsigned int length, unsigned int line_id) {
    if (length >= 1) {
      if(compare_strings(line, "Vertices.") == 0) {
        reading_vertices = true;
        reading_edges = false;
        return;
      }
      if(compare_strings(line, "Edges.") == 0) {
        reading_vertices = false;
        reading_edges = true;
        return;
      }
      unsigned char column_id = 0;
      char *token = strtok(line, " ");
      unsigned long long id = 0;
      float x = 0.0;
      float y = 0.0;
      char *name = NULL;
      unsigned long long id_a = 0;
      unsigned long long id_b = 0;
      float distance = 0;
      while (token != NULL) {
        if (reading_vertices) {
          if (column_id == 0) {
            char *end;
            id = strtoll(token, &end, 10);
          }
          if (column_id == 1) {
            char *end;
            x = strtof(token, &end);
          }
          if (column_id == 2) {
            char *end;
            y = strtof(token, &end);
          }
          if (column_id == 3) {
            name = get_str_copy(token);
          }
        }
        if (reading_edges) {
          if (column_id == 0) {
            char *end;
            id_a = strtoll(token, &end, 10);
          }
          if (column_id == 1) {
            char *end;
            id_b = strtoll(token, &end, 10);
          }
          if (column_id == 2) {
            char *end;
            distance = strtof(token, &end);
          }
          if (column_id == 3) {
            name = get_str_copy(token);
          }
          if (column_id > 3) {
            char *new_name = str_append_with_space(name, token);
            free(name);
            name = new_name;
          }
        }
        token = strtok(NULL, " ");
        column_id++;
      }
      if (reading_vertices) {
        Vertex *vertex = vertex_create(id, x, y, name);
        map_add_vertex(map, vertex);
      }
      if (reading_edges) {
        Vertex *a = map_get_vertex_from_id(map, id_a);
        Vertex *b = map_get_vertex_from_id(map, id_b);
        Edge *edge = edge_create(a, b, distance, name);
        vertex_add_edge(a, edge);
      }
    }
  }
  read_file = read_line_by_line(path, read_function);
  if (read_file) {
    return map;
  }
  return NULL;
}
