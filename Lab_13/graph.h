typedef struct Node {
    int v; //node name
    int d; //distance
    int prev_node;
} Node;

typedef struct Heap {
    int Capacity;
    int Size;
    Node* Element;
} Heap;

typedef struct GraphStruct {
    int size;
    int **weight;
    Node *nodes;
} Graph;

Heap* CreateMinHeap(int heapSize);
void InsertToMinHeap(Heap* minHeap, int vertex, int distance);
Node DeleteMin(Heap* minHeap);

Graph makeGraph(const char *filename);
Graph getShortestDistance(Graph g);
void printShortestPath(Node *node, int last_node, int start_node);
