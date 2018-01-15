#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "graph.h"

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
