#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "city.h"

typedef struct adj_list{
    int v;
    int widht;
    struct adj_list *next;
}ADJ_LIST;

struct Graph{
    int v;
    int e;
    int **adj;
    ADJ_LIST **ad_list;
};

struct City{
    char name[20];
    char region[20];
}*city;


G graph_init(int v, FILE *f){

    G graph;
    CITY c_tab;
    ADJ_LIST *x1, *x2;
    int i, j, widht, num1, num2;
    char name1[20];
    char name2[20];
    graph = malloc(sizeof (struct Graph));
    graph->v = v;
    graph->e = 0;
    graph->adj = malloc(v*sizeof(int*));
    graph->ad_list = malloc(v*sizeof(ADJ_LIST*));
    city = malloc(v*sizeof(struct City));
    c_tab = city_init(v);
    for(i=0; i<v; i++){
        graph->adj[i] = malloc(v*sizeof(int));
        graph->ad_list[i] = malloc(sizeof(ADJ_LIST));
        graph->ad_list[i]->next = NULL;
        fscanf(f, "%s%s", city[i].name, city[i].region);
        city_add(c_tab, city[i].name, city[i].region, i);
        for(j=0; j<v; graph->adj[i][j]=0,j++);
    }
    while(!feof(f)){
        fscanf(f, "%s%s%d", name1, name2, &widht);
        num1 = city_getv(c_tab, name1, v);
        num2 = city_getv(c_tab, name2, v);
        x1 = graph->ad_list[num1];
        for(; x1->next!=NULL; x1 = x1->next);
        x2 = graph->ad_list[num2];
        for(; x2->next!=NULL; x2 = x2->next);
        x1->v = num2;
        x2->v = num1;
        x1->widht = widht;
        x2->widht = widht;
        x1->next = malloc(sizeof(ADJ_LIST));
        x2->next = malloc(sizeof(ADJ_LIST));
        x1->next->next = NULL;
        x2->next->next = NULL;
    }

    for(i=0; i<v; i++){
        for(x1 = graph->ad_list[i]; x1->next!=NULL; x1 = x1->next){
            graph->adj[i][x1->v] = x1->widht;
            graph->adj[x1->v][i] = x1->widht;
        }

    }
    return graph;
}

void graph_grade(int v, G graph){

    int i, count;
    ADJ_LIST *x;
    printf("\n\nGradi dei nodi:\n");
    for(i=0; i<v; i++){
        printf("Vertici connessi a %s: (", city[i].name);
        for(x = graph->ad_list[i], count =0; x->next!=NULL; count++, printf("%d ", x->v), x = x->next);
        printf(") -> grado %d;\n\n", count);
    }
    return;
}
void graph_show(int v, G graph){

    int i;
    printf("\n\nTotale nodi %d:\n", v);
    printf("Elenco nodi:\n");
    for(i=0; i<v; i++)
        printf("Nodo %d: %20s   %20s\n",i, city[i].name, city[i].region);
    return;
}

void graph_adj(int v, G graph){

    int i,j;
    printf("\n\nMatrice adiacenze:\n");
    for(i=0; i<v; i++){
        for(j=0; j<v; j++)
            printf("%3d ", graph->adj[i][j]);
        printf("\n");
    }
return;
}
void graph_flow(int v, G graph){

    int sum_inter=0, sum_intra=0, i, j;
    for(i=0; i<v; i++)
        for(j=0; j<i; j++)
            if(graph->adj[i][j] != 0){
                if(strcmp(city[i].region, city[j].region) == 0)
                    sum_intra += graph->adj[i][j];
                else
                    sum_inter += graph->adj[i][j];
            }
    printf("\n\nSomma traffico interregionale globale: %d;", sum_inter);
    printf("\n\nSomma traffico intraregionale globale: %d;", sum_intra);

return;
}
