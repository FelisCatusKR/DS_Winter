#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "circular.h"
#include "graph.h"
#define QUEUE_SIZE 1000

void DFS(Graph g, int start, int end);
void BFS(Graph g, int start, int end);

int main(void) {
    FILE *fi = fopen("input.txt", "r");
    Graph g = makeGraph(fi);

    int start, end;
    fscanf(fi,"%d-%d",&start,&end);

    printf("DFS recursive : ");
    DFS(g, start, end);
    if(g.check_visit[end] == false)
        printf("cannot find");
    putchar('\n');

    g = refreshGraph(g);

    printf("BFS: ");
    BFS(g, start, end);
    if(g.check_visit[end] == false)
        printf("cannot find");
    putchar('\n');

    for(int i=1; i<=g.size; i++) free(g.weight[i]);
    free(g.weight);
    free(g.check_visit);
    return 0;
}

void DFS(Graph g, int start, int end) {
    int u = start;
    printf("%d ", u);
    g.check_visit[u] = true;
    if(u == end)
        return;
    for(int v=1; v<=g.size && !g.check_visit[end]; v++) {
        if(g.weight[u][v] == 1 && !g.check_visit[v])
            DFS(g, v, end);
    }
}

void BFS(Graph g, int start, int end) {
    CircularQueue* q = MakeEmpty(QUEUE_SIZE);
    Enqueue(q, start);
    while(!g.check_visit[end] && !IsEmpty(q)) {
        int u = Dequeue(q);
        if(g.check_visit[u])
            continue;
        printf("%d ", u);
        g.check_visit[u] = true;
        for(int v=1; v<=g.size; v++) {
            if(g.weight[u][v] == 1 && !g.check_visit[v])
                Enqueue(q, v);
        }
    }
    DeleteQueue(q);
}
