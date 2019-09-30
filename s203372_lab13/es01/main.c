#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char*argv[])
{

    GRAPH G;
    FILE *f;
    int choose = -1;
    int v1, v2;

    if (( f=fopen(argv[1], "r"))==NULL) return -1;

    G = graph_init(f);

    while(choose!=0){

        printf("Scegli:\n");
        printf("1 - Cammino semplice di lunghezza minima tra una data coppia di vertici;\n");
        printf("2 - Cammino semplice di lunghezza massima tra una data coppia di vertici;\n");
        printf("3 - Numero di cammini semplici tra una data coppia di vertici;\n");
        printf("4 - Componenti fortemente connesse del grafo;\n");
        printf("0 - Esci.\n");
        printf("Scelta: ");
        scanf("%d", &choose);
        switch (choose){

            case 1:
                printf("Inserire vertice di partenza: ");
                scanf("%d", &v1);
                printf("Inserire vertice di arrivo: ");
                scanf("%d", &v2);
                graph_min_path(G, v1, v2);
                break;
            case 2:

                printf("Inserire vertice di partenza: ");
                scanf("%d", &v1);
                printf("Inserire vertice di arrivo: ");
                scanf("%d", &v2);
                graph_max_path(G, v1, v2);
                break;
            case 3:
                printf("Inserire vertice di partenza: ");
                scanf("%d", &v1);
                printf("Inserire vertice di arrivo: ");
                scanf("%d", &v2);
                printf("Numero di cammini semplici: %d\n", graph_num_path(G, v1, v2,0));
                break;
            case 4:
                GRAPHscc(G,f);
                break;
            default:
                printf("Valore inserito non corretto!\n");
        }
    }
    fclose(f);


    return 0;
}
