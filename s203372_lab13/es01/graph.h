#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct Graph *GRAPH;

GRAPH graph_init(FILE *f);
int get_node(GRAPH G, char *name);
void graph_min(GRAPH G, int v1, int v2, int n);
void graph_max(GRAPH G, int v1, int v2, int n);
void graph_min_path(GRAPH G, int v1, int v2);
void graph_max_path(GRAPH G, int v1, int v2);
int graph_num(GRAPH G, int v1, int v2, int n);
void init_globalvariables(GRAPH G);
int graph_num_path(GRAPH G, int v1,int v2,int n);
int GRAPHscc(GRAPH G, FILE*f);
void SCCdfsR(GRAPH G, int w);
GRAPH GRAPHreverse(GRAPH G, FILE*f);
#endif // GRAPH_H_INCLUDED
