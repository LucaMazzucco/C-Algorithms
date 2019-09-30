
#include <stdio.h>
#include <stdlib.h>
#include "libpriorita.h"
#include "libvar.h"

int priorita()
{
    int scelta, i=0,k=0, j=0;
    stu *studente_next, *inizio, *p, *temp;

    studente_next = malloc(sizeof(stu));
    inizio = studente_next;


    while(1){

        printf("\n\n");
        printf("Scegli opzione per la gestione della coda a priorita':\n");
        printf("1 - visualizzazione della cardinalita' della coda a priorita';\n");
        printf("2 - inserzione di un elemento nella posizione corretta in base al campo media,\n    identificato come priorita';\n");
        printf("3 - estrazione dell’elemento a priorita' massima;\n");
        printf("4 - visualizzazione del contenuto della coda a priorita';\n");
        printf("5 - distruzione della coda a priorita';\n");
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
                k = 0;
                p = inizio;
                if (k!=i){
                    while(k<i&&p->voti.media<studente_next->voti.media){
                        p = p->next;
                        k++;
                    }
                    if (k == 0){
                        temp = inizio;
                        inizio = studente_next;
                        studente_next->next = temp;
                    }
                    else{
                        if (k == i)
                            p->next = studente_next;

                        temp = p->next;
                        p->next= studente_next;
                        studente_next->next = temp;
                    }
                }
                else{

                }
                studente_next = malloc(sizeof(stu));
                i++;
                printf("Studente inserito con successo in coda di priorita'!\n");
                break;
            case 3:
                temp = inizio->next;
                free(inizio);
                inizio = temp;
                break;
            case 4:
                printf("Elenco studenti:\n");
                for(k=0, p = inizio; k<i; k++, p = p->next)
                    printf("%d - %s %s %s %d %f\n", k, p->nome, p->cognome, p->matricola, p->voti.crediti, p->voti.media);
                break;
            case 5:
                 for(k=0, p = inizio; k<i; k++, p = p->next)
                    free(p);
                 i =0;
                 studente_next = malloc(sizeof(stu));
                break;
            case 6:
                return -1;
        }

    }

 return 0;
}
