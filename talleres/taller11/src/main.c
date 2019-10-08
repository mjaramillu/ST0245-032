#include "am_graph.h"

int main(int argc, char* argv[]) {
  AMGraph *graph = AM_create();
  am_add_vertex(graph, "Dinosaurios");
  am_add_vertex(graph, "Felices");
  am_add_vertex(graph, "Voladores");
  am_set_connection(graph, "Dinosaurios", "Felices", 42);
  am_set_connection(graph, "Felices", "Voladores", 42);
  am_set_connection(graph, "Voladores", "Dinosaurios", 42);
  am_print_graph(graph);
  printf("holi\n");
}
