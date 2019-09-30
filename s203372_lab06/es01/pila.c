#include <stdio.h>
#include <stdlib.h>
#include "libpila.h"
#include "libvar.h"

int pila()
{
    int scelta, i=0,k=0;
    stu *studente_next, *studente_prev, *p;

    studente_next = malloc(sizeof(stu));
    studente_prev = malloc(sizeof(stu));
    studente_next->prev = studente_prev;
    studente_prev->next = studente_next;

    while(1){

        printf("\n\n");
        printf("Scegli opzione per la gestione della pila:\n");
        printf("1 - visualizzazione della cardinalita' della pila;\n");
        printf("2 - inserzione in testa di un elemento;\n");
        printf("3 - estrazione dell’elemento di testa;\n");
        printf("4 - visualizzazione del contenuto della pila;\n");
        printf("5 - distruzione della pila;\n");
        printf("6 - Esci.\n");

        scanf("%d", &scelta);

          switch (scelta){

            case 1:
                printf("Studenti catalogati: %d", i);
                break;
            case 2:
                 printf("Inserisci nome studente: ");
                scanf("%s", studente_prev->nome);
                printf("Inserisci cognome studente: ");
                scanf("%s", studente_prev->cognome);
                printf("Inserisci matricola studente: ");
                scanf("%s", studente_prev->matricola);
                printf("Inserisci la somma dei crediti: ");
                scanf("%d", &studente_prev->voti.crediti);
                printf("Inserisci la media: ");
                scanf("%f", &studente_prev->voti.media);

                studente_prev->prev = malloc(sizeof(stu));
                studente_prev->prev->next = studente_prev;
                studente_prev = studente_prev->prev;
                i++;
                printf("Studente inserito con successo in testa!\n");
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
