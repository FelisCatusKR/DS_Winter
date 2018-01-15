#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main(void) {
    Graph g;
    g = makeGraph("input.txt");
    g = getShortestDistance(g);
    for(int i = 2; i <= g.size; i++) {
        printShortestPath(g.nodes, i, 1);
        printf(" (distance : %d)\n", g.nodes[i].d);
    }
    return 0;
}
