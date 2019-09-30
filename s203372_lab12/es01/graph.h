#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct Graph *G;

G graph_init(int v, FILE *f);
void graph_grade(int v, G graph);
void graph_show(int v, G graph);
void graph_adj(int v, G graph);
void graph_flow(int v, G graph);

#endif // GRAPH_H_INCLUDED
