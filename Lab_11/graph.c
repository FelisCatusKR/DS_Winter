#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph makeGraph(FILE *fi) {
    int i, j, n, a, b;
    char tmp;
    Graph tmpGraph;
    fscanf(fi, "%d", &n);
    tmpGraph.size = n;
    tmpGraph.weight = (int**)malloc(sizeof(int*)*(n+1));
    for(i=1; i<=n; i++)
        tmpGraph.weight[i] = (int*)malloc(sizeof(int)*(n+1));
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++)
            tmpGraph.weight[i][j] = 0;
    }
    tmp = '\0';
    while(tmp != '\n') {
        fscanf(fi, "%d-%d", &a, &b);
        tmpGraph.weight[a][b] = 1;
        tmp = (char)fgetc(fi);
    }
    return tmpGraph;
}

int *checkIndegree(Graph g) {
    int i, j;
    int *tmp = (int*)malloc(sizeof(int)*(g.size+1));
    for(i=1; i<=g.size; i++)
        tmp[i] = 0;
    for(i=1; i<=g.size; i++) {
        for(j=1; j<=g.size; j++) {
            if(g.weight[i][j] == 1)
                tmp[j]++;
        }
    }
    return tmp;
}
