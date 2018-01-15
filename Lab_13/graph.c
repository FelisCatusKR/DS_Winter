#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

#define INF 99999

Graph makeGraph(const char *filename) {
    int n, node1, node2, weight;
    char tmp;
    Graph tmpGraph;
    FILE* fi = fopen(filename, "r");
    fscanf(fi, "%d", &n);
    tmpGraph.size = n;
    tmpGraph.weight = (int**)malloc(sizeof(int*)*(n+1));
    for(int i=1; i<=n; i++) {
        tmpGraph.weight[i] = (int*)malloc(sizeof(int)*(n+1));
        memset(tmpGraph.weight[i], 0, sizeof(int)*(n+1));
    }
    tmpGraph.nodes = (Node*)malloc(sizeof(Node)*(n+1));
    memset(tmpGraph.nodes, 0, sizeof(Node)*(n+1));
    tmp = '\0';
    while(tmp != '\n') {
        fscanf(fi, "%d-%d-%d", &node1, &node2, &weight);
        tmpGraph.weight[node1][node2] = weight;
        tmp = (char)fgetc(fi);
    }
    fclose(fi);
    return tmpGraph;
}
Graph getShortestDistance(Graph g) {
    for(int i = 1; i <= g.size; i++) {
        g.nodes[i].v = i;
        g.nodes[i].d = INF;
        g.nodes[i].prev_node = -1;
    }
    g.nodes[1].d = 0;
    Heap* priorityQ = CreateMinHeap(g.size);
    InsertToMinHeap(priorityQ, 1, 0);
    while(priorityQ->Size != 0) {
        Node minNode = DeleteMin(priorityQ);
        int u = minNode.v;
        int d = minNode.d;
        for(int i = 1; i <= g.size; i++) {
            int weight = g.weight[u][i];
            if(weight == 0) continue;
            if(d + weight < g.nodes[i].d) {
                g.nodes[i].d = d + weight;
                g.nodes[i].prev_node = u;
                InsertToMinHeap(priorityQ, i, g.nodes[i].d);
            }
        }
    }
    return g;
}

void printShortestPath(Node *node, int last_node, int start_node) {
    if(last_node != start_node)
        printShortestPath(node, node[last_node].prev_node, start_node);
    printf("%d ",last_node);
}

Heap* CreateMinHeap(int heapSize) {
    Heap* tmpHeap;
    tmpHeap = (Heap*)malloc(sizeof(Heap));
    tmpHeap->Capacity = heapSize;
    tmpHeap->Size = 0;
    tmpHeap->Element = (Node*)malloc(sizeof(Node) * (heapSize+1));
    return tmpHeap;
}

void InsertToMinHeap(Heap* minHeap, int vertex, int distance) {
    Node tmpNode;
    tmpNode.v = vertex;
    tmpNode.d = distance;

    if(minHeap->Size ==  minHeap->Capacity) {
        puts("Insertion Error: Heap is full.");
        return;
    }
    int pos;
    for(pos = ++(minHeap->Size); pos/2 > 0 && vertex < minHeap->Element[pos].v ; pos /= 2)
        minHeap->Element[pos] = minHeap->Element[pos/2];
    minHeap->Element[pos] = tmpNode;
}

Node DeleteMin(Heap* minHeap) {
    if(minHeap->Size == 0) {
        Node tmpNode;
        tmpNode.d = -1;
        return tmpNode;
    }
    Node minNode = minHeap->Element[1];
    Node lastNode = minHeap->Element[minHeap->Size--];

    int pos, child;
    for(pos = 1; pos*2 <= minHeap->Size; pos = child) {
        child = pos*2;
        if(child != minHeap->Size && minHeap->Element[child+1].v < minHeap->Element[child].v)
            child++;
        if(lastNode.v > minHeap->Element[child].v)
            minHeap->Element[pos] = minHeap->Element[child];
        else
            break;
    }
    minHeap->Element[pos] = lastNode;
    return minNode;
}

/*
Graph makeGraph(FILE *fi) {
    int n, a, b;
    char tmp;
    Graph tmpGraph;
    fscanf(fi, "%d", &n);
    tmpGraph.size = n;
    tmpGraph.weight = (int**)malloc(sizeof(int*)*(n+1));
    for(int i=1; i<=n; i++) {
        tmpGraph.weight[i] = (int*)malloc(sizeof(int)*(n+1));
        memset(tmpGraph.weight[i], 0, sizeof(int)*(n+1));
    }
    tmpGraph.check_visit = (bool*)malloc(sizeof(bool)*(n+1));
    memset(tmpGraph.check_visit, false, sizeof(bool)*(n+1));
    tmp = '\0';
    while(tmp != '\n') {
        fscanf(fi, "%d-%d", &a, &b);
        tmpGraph.weight[a][b] = 1;
        tmp = (char)fgetc(fi);
    }
    return tmpGraph;
}

Graph refreshGraph(Graph g) {
    memset(g.check_visit, false, sizeof(bool)*(g.size+1));
    return g;
}
*/
