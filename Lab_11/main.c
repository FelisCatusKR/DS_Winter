#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "circular.h"
#include "graph.h"

#define Qsize 100

int main(void)
{
    FILE *fi;
    Graph g;
    int i;
    Vertex V, w;
    CircularQueue *q;

    fi = fopen("input.txt", "r");
    g = makeGraph(fi);
    q = MakeEmpty(Qsize);
    g.Indegree = checkIndegree(g);

    printf("%10s", "Node no:");
    for(i=1; i<=g.size;i++)
        printf("%3d ", i);
    putchar('\n');
    puts("----------------------------------------");
    printf("%10s", "Indegree:");
    for(i=1;i<=g.size;i++)
        printf("%3d ", g.Indegree[i]);
    putchar('\n');
    puts("----------------------------------------");

    for(i=1; i<=g.size; i++) {
        if(g.Indegree[i] == 0)
            Enqueue(q, i);
    }

    while(!IsEmpty(q)) {
        V = Dequeue(q);
        printf("dequeue: %d\n", V);
        for(w=1; w<=g.size; w++) {
            if(g.weight[V][w] == 1 && --g.Indegree[w] == 0)
                Enqueue(q, w);
        }
    }

    fclose(fi);
    free(q);
    free(g.Indegree);
    for(i=1; i<=g.size; i++)
        free(g.weight[i]);
    free(g.weight);
    DeleteQueue(q);
    return 0;
}
