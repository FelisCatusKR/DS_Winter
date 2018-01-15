typedef int Vertex;
typedef struct Graph {
    int size;
    int **weight;
    int *Indegree;
} Graph;

Graph makeGraph(FILE *fi);
int *checkIndegree(Graph g);
