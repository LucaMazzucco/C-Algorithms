#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

typedef struct adj{

    int v;
    struct adj* next;
}ADJ;

struct Graph{

    int v;
    int *scc;
    char **name;
    ADJ **adj_list;
};

int nmin, nmax = 0, *visited, *best_min, *best_max, time0, time1,*post,*postR;

GRAPH graph_init(FILE *f){

    GRAPH G;
    ADJ *L;
    char name1[11], name2[11];
    int i, count=0, v1,v2;
    G = malloc(sizeof(struct Graph));
    fscanf(f, "%d", &G->v);
    nmin = G->v;
    visited = malloc(G->v*sizeof(int));
    best_min = malloc(G->v*sizeof(int));
    best_max = malloc(G->v*sizeof(int));
    G->adj_list = malloc(G->v*sizeof(ADJ*));
    G->name = malloc(G->v*sizeof(char*));
    for(i=0; i<G->v; i++){
        G->name[i] = malloc(11*sizeof(char));
        G->adj_list[i] = malloc(sizeof(ADJ));
        G->adj_list[i]->next = NULL;
    }
    while(!feof(f)){
        fscanf(f, "%s", name1);
        for(i=0; i<G->v; i++){
            if(strcmp(G->name[i], name1)==0)
                break;
        }
        if(i==G->v){
            strcpy(G->name[count], name1);
            count++;
        }
    }
    rewind(f);
    fscanf(f, "%*d");
    while(!feof(f)){
        fscanf(f, "%s%s", name1, name2);
        v1 = get_node(G, name1);
        v2 = get_node(G, name2);
        for(L = G->adj_list[v1]; L->next!=NULL; L=L->next);
        L->next = malloc(sizeof(ADJ));
        L->v = v2;
        L->next->next = NULL;
    }
    for(i=0; i<G->v; i++){
        printf("%s  ",G->name[i] );
        for(L= G->adj_list[i]; L->next!=NULL; L=L->next)
            printf("%s", G->name[L->v]);
        printf("\n\n");

    }

    return G;
}

int get_node(GRAPH G, char *name){

    int i;
    for(i=0; i<G->v; i++){
        if(strcmp(name, G->name[i])==0)
            return i;
    }
    return -1;
}
void graph_min_path(GRAPH G, int v1, int v2){

    int i, j;
    init_globalvariables(G);
    graph_min(G,v1,v2,0);

    for(i=0; i<G->v; i++)
        for(j=0; j<G->v; j++)
            if(best_min[j] == i)
                printf("%s  ", G->name[j]);

    return;
}
void graph_max_path(GRAPH G, int v1, int v2){
    int i, j;
    init_globalvariables(G);
    graph_max(G,v1,v2,0);

    for(i=0; i<G->v; i++)
        for(j=0; j<G->v; j++)
            if(best_max[j] == i)
                printf("%s  ", G->name[j]);

    return;
}

void graph_min(GRAPH G, int v1, int v2, int n){

    int i;
    ADJ *L;
    if(v1 == v2){
        if(n<nmin){
            for(i=0; i<G->v; i++)
                best_min[i] = visited[i];
        }
        return;
    }
    for(L = G->adj_list[v1]; L->next!=NULL; L=L->next)
        if(visited[L->v]==-1){
            visited[L->v]=n;
            graph_min(G,L->v, v2, n+1);
        }
    visited[v1] = -1;

    return;
}
void graph_max(GRAPH G, int v1, int v2, int n){

    int i;
    ADJ *L;
    if(v1 == v2){
        if(n>nmax){
            for(i=0; i<G->v; i++)
                best_max[i] = visited[i];
        }
        return;
    }
    for(L = G->adj_list[v1]; L->next!=NULL; L=L->next)
        if(visited[L->v]==-1){
            visited[L->v]=n;
            graph_max(G,L->v, v2, n+1);
        }

    visited[v1] = -1;


    return;
}
int graph_num_path(GRAPH G, int v1,int v2,int n){

    init_globalvariables(G);
    n = graph_num(G, v1,v2, n);

    return n;
}
int graph_num(GRAPH G, int v1, int v2, int n){

    ADJ *L;
    if(v1 == v2){
        n++;
        return n;
    }
    for(L = G->adj_list[v1]; L->next!=NULL; L=L->next)
        if(visited[L->v]==-1){
            visited[L->v]=n;
            n = graph_num(G,L->v, v2, n);
        }

    visited[v1] = -1;
    return n;
}

void init_globalvariables(GRAPH G){

    int i;
    nmin = G->v;
    nmax = 0;
    for(i=0; i<G->v; i++)
        visited[i] = -1;
    return;
}

int GRAPHscc(GRAPH G, FILE*f) {

    int v;
    GRAPH R;

    R = GRAPHreverse(G, f);
    time0 = 0;
    time1 = 0;
    G->scc = malloc(G->v * sizeof(int));
    R->scc = malloc(G->v * sizeof(int));
    post = malloc(G->v * sizeof(int));
    postR = malloc(G->v * sizeof(int));
    for (v=0; v < G->v; v++)
        R->scc[v] = -1;
    for (v=0; v < G->v; v++)
        if (R->scc[v] == -1)
            SCCdfsR(R, v);
    time0 = 0;
    time1 = 0;
    for (v=0; v < G->v; v++)
        G->scc[v] = -1;
    for (v=0; v < G->v; v++)
        postR[v] = post[v];
        printf("Archi da aggiungere per rendere il grafo SCC:\n");
    for (v = G->v-1; v >= 0; v--)
        if (G->scc[postR[v]]==-1){
            if(v!=G->v-1)
                printf("%s  %s\n", G->name[postR[G->v-1]], G->name[postR[v]]);
            SCCdfsR(G,postR[v]);
            time1++;
        }

    printf("\n\nComponenti fortemente connesse: %d\n", time1);
    for (v = 0; v < G->v; v++)
        printf("%s in scc %d \n", G->name[v], G->scc[v]);

    return time1;
}

void SCCdfsR(GRAPH G, int w) {
    ADJ* t;
    G->scc[w] = time1;
    for (t = G->adj_list[w]; t->next!= NULL; t = t->next)
        if (G->scc[t->v] == -1)
            SCCdfsR(G, t->v);
    post[time0++]= w;

    return;
}

GRAPH GRAPHreverse(GRAPH G, FILE*f){
    GRAPH R;
    ADJ* L;
    int i, v1, v2;
    char name1[11], name2[11];
    R = malloc(sizeof(struct Graph));
    R->adj_list = malloc(G->v*sizeof(ADJ*));
    for(i=0; i<G->v; i++){
        R->adj_list[i] = malloc(sizeof(ADJ));
        R->adj_list[i]->next = NULL;
    }
    rewind(f);
    fscanf(f, "%*d");
    while(!feof(f)){
        fscanf(f, "%s%s", name1, name2);
        v1 = get_node(G, name1);
        v2 = get_node(G, name2);
        for(L = R->adj_list[v2]; L->next!=NULL; L=L->next);
        L->next = malloc(sizeof(ADJ));
        L->v = v1;
        L->next->next = NULL;
    }


    return R;
}

