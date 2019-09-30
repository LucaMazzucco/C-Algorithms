#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libscelta.h"
#include "libvar.h"

int lista()
{
    int scelta, i=0,k=0, trovato = 0;
    stu *studente_next, *studente_prev, *p, *temp;
    char ricerca[36];

    studente_next = malloc(sizeof(stu));
    studente_prev = malloc(sizeof(stu));
    studente_next->prev = studente_prev;
    studente_prev->next = studente_next;

    while(1){

        printf("\n\n");
        printf("Scegli opzione per la gestione della lista non ordinata:\n");
        printf("1 - Visualizzazione della cardinalità della lista;\n");
        printf("2 - Inserzione in testa di un elemento;\n");
        printf("3 - Inserzione in coda di un elemento;\n");
        printf("4 - ricerca di un elemento con chiave di ricerca alternativamente pari a nome,\n    cognome o matricola;\n");
        printf("5 - estrazione di un elemento con chiave di cancellazione alternativamente pari\n    a nome, cognome o matricola;\n");
        printf("6 - visualizzazione del contenuto della lista;\n");
        printf("7 - distruzione della lista;\n");
        printf("8 - Esci.\n");

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
            case 4:
                p = studente_prev->next;
                printf("Ricerca tramite:\n");
                printf("1 - Nome;\n");
                printf("2 - Cognome;\n");
                printf("3 - Matricola.\n");
                scanf("%d", &scelta);
                switch (scelta){
                    case 1:
                        trovato =0;
                        printf("Inserisci nome: ");
                        scanf("%s", ricerca);
                        for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                            if ((strcmp(ricerca, p->nome))==0){
                                printf("%d - %s %s %s %d %f", k, p->nome, p->cognome, p->matricola, p->voti.crediti, p->voti.media);
                                trovato = 1;
                            }
                        if (trovato == 0)
                            printf("Studente non trovato");
                        break;

                    case 2:
                        trovato =0;
                        printf("Inserisci cognome: ");
                        scanf("%s", ricerca);
                        for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                            if ((strcmp(ricerca, p->cognome))==0){
                                printf("%d - %s %s %s %d %f", k, p->nome, p->cognome, p->matricola, p->voti.crediti, p->voti.media);
                                trovato = 1;
                            }
                        if (trovato == 0)
                            printf("Studente non trovato");
                        break;
                    case 3:
                        trovato =0;
                        printf("Inserisci matricola: ");
                        scanf("%s", ricerca);
                        for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                            if ((strcmp(ricerca, p->matricola))==0){
                                printf("%d - %s %s %s %d %f", k, p->nome, p->cognome, p->matricola, p->voti.crediti, p->voti.media);
                                trovato = 1;
                            }
                        if (trovato == 0)
                            printf("Studente non trovato");
                        break;
                    default:
                        printf("Inserisci valore corretto!");
                        break;
                }
                break;
            case 5:
                p = studente_prev->next;
                printf("Estrazione tramite:\n");
                printf("1 - Nome;\n");
                printf("2 - Cognome;\n");
                printf("3 - Matricola.\n");
                scanf("%d", &scelta);
                switch (scelta){
                    case 1:
                        trovato =0;
                        printf("Inserisci nome: ");
                        scanf("%s", ricerca);
                        for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                            if ((strcmp(ricerca, p->nome))==0){
                                temp = p->next;
                                p->prev->next = p->next;
                                p->next->prev = p->prev;
                                free(p);
                                p = temp->prev;
                                i--;
                                trovato = 1;
                            }
                        if (trovato == 0)
                            printf("Studente non trovato");
                        break;

                    case 2:
                        trovato =0;
                        printf("Inserisci cognome: ");
                        scanf("%s", ricerca);
                        for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                            if ((strcmp(ricerca, p->cognome))==0){
                                temp = p->next;
                                p->prev->next = p->next;
                                p->next->prev = p->prev;
                                free(p);
                                p = temp->prev;
                                i--;
                                trovato = 1;
                            }
                        if (trovato == 0)
                            printf("Studente non trovato");
                        break;
                    case 3:
                        trovato =0;
                        printf("Inserisci matricola: ");
                        scanf("%s", ricerca);
                        for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                            if ((strcmp(ricerca, p->matricola))==0){
                                temp = p->next;
                                p->prev->next = p->next;
                                p->next->prev = p->prev;
                                free(p);
                                p = temp->prev;
                                i--;
                                trovato = 1;
                            }
                        if (trovato == 0)
                            printf("Studente non trovato");
                        break;
                    default:
                        printf("Inserisci valore corretto!");
                        break;
                }
                break;
                break;
            case 6:
                printf("Elenco studenti:\n");
                for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                    printf("%d - %s %s %s %d %f\n", k, p->nome, p->cognome, p->matricola, p->voti.crediti, p->voti.media);
                break;
            case 7:
                 for(k=0, p = studente_prev->next; k<i; k++, p = p->next)
                    free(p);
                 i =0;
                 studente_next = malloc(sizeof(stu));
                 studente_prev = malloc(sizeof(stu));
                 studente_next->prev = studente_prev;
                 studente_prev->next = studente_next;
                break;
            case 8:
                return -1;
             default:
                        printf("Inserisci valore corretto!");
                        break;
        }
    }

    return 0;

}
