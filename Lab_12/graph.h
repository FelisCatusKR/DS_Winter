#include <stdbool.h>

typedef int Vertex;
typedef struct Graph {
    int size;
    int **weight;
    bool *check_visit;
} Graph;

Graph makeGraph(FILE *fi);
Graph refreshGraph(Graph g);
