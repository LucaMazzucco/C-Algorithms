#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char *argv[])
{
    int x;
    FILE *f;
    G graph;

    if ((f = fopen(argv[1], "r")) == NULL) return -1;
    fscanf(f, "%d", &x);

    graph = graph_init(x, f);
    graph_grade(x, graph);
    graph_show(x, graph);
    graph_adj(x, graph);
    graph_flow(x, graph);

    fclose(f);

    return 0;
}
