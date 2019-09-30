#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define maxN 20

int main()
{

    int choose, priority;
    PQ pq;
    FILE *f;
    char name[6], file[25];

    pq = PQUEUEinit(maxN);

    while(choose!= 0){

        printf("Scelta:\n");
        printf("1 - Aggiungi nuovo cliente in coda;\n");
        printf("2 - Estrai cliente dalla coda;\n");
        printf("3 - Leggi e inserisci in coda clienti da file;\n");
        printf("4 - Stampa coda;\n");
        printf("0 - Esci.\n");
        printf("Scegli: ");
        scanf("%d", &choose);
        switch(choose){

            case 1:
                printf("Inserisci codice a 5 caratteri: ");
                scanf("%s", name);
                printf("Inserisci priotita': ");
                scanf("%d", &priority);
                PQinsert (pq, name, priority);
                printf("Cliente inserito in coda con successo!\n");
                break;
            case 2:
                 PQUEUEextractMax(pq);
                 printf("Cliente estratto con successo!\n");
                break;
            case 3:
                printf("Inserire nome file: ");
                scanf("%s", file);
                if ((f = fopen(file, "r")) == NULL)
                    printf("File non trovato!\n");
                else
                    while(!feof(f)){
                        fscanf(f, "%s%d", name, &priority);
                        PQinsert (pq, name, priority);
                    }
                    printf("Coda caricata con successo!\n");
                break;
            case 4:
                PQshow(pq);
                break;
            default:
                printf("Inserire valore corretto!\n");
                break;
        }
    }

    return 0;
}
