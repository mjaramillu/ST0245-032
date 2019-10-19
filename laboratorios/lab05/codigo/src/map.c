#if INTERFACE

typedef struct Edge {
  Vertex *a;
  Vertex *b;
  unsigned int distance;
} Edge;

typedef struct Vertex {
  Edge *head;
  unsigned int EdgeCount;
  float x;
  float y;
} Vertex;

typedef struct Map {
  Vertex *head;
  unsigned int vertex_count;
} Map;

#endif

#include "map.h"
