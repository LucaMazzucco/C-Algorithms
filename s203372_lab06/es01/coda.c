#include <stdio.h>
#include <stdlib.h>
#include "libcoda.h"
#include "libvar.h"

int coda()
{
    int scelta, i=0,k=0;
    stu *studente_next, *studente_prev, *p;

    studente_next = malloc(sizeof(stu));
    studente_prev = malloc(sizeof(stu));
    studente_next->prev = studente_prev;
    studente_prev->next = studente_next;

    while(1){

        printf("\n\n");
        printf("Scegli opzione per la gestione della coda:\n");
        printf("1 - visualizzazione della cardinalità della coda;\n");
        printf("2 - inserzione in coda di un elemento;\n");
        printf("3 - estrazione dell’elemento di testa;\n");
        printf("4 - visualizzazione del contenuto della coda;\n");
        printf("5 - distruzione della coda;\n");
        printf("6 - Esci.\n");

        scanf("%d", &scelta);

          switch (scelta){

            case 1:
                printf("Studenti catalogati: %d", i);
                break;
            case 2:
                printf("Inserisci nome studente: ");
                scanf("%s", studente_next->nome);
                printf("Inserisci cognome studente: ");
                scanf("%s", studente_next->cognome);
                printf("Inserisci matricola studente: ");
                scanf("%s", studente_next->matricola);
                printf("Inserisci la somma dei crediti: ");
                scanf("%d", &studente_next->voti.crediti);
                printf("Inserisci la media: ");
                scanf("%f", &studente_next->voti.media);

                studente_next->next = malloc(sizeof(stu));
                studente_next->next->prev = studente_next;
                studente_next = studente_next->next;
                i++;
                printf("Studente inserito con successo in coda!\n");
                break;
            case 3:
                studente_prev = studente_prev->next;
                free(studente_prev->prev);
                i--;
                break;
            case 4:
                printf("Elenco studenti:\n");
                for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                    printf("%d - %s %s %s %d %f\n", k, p->nome, p->cognome, p->matricola, p->voti.crediti, p->voti.media);
                break;
            case 5:
                for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                    free(p);
                 i =0;
                 studente_next = malloc(sizeof(stu));
                 studente_prev = malloc(sizeof(stu));
                 studente_next->prev = studente_prev;
                 studente_prev->next = studente_next;
                break;
            case 6:
                return -1;
        }

    }
    return 0;
}
