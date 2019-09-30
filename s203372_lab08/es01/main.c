#include <stdio.h>
#include <stdlib.h>
#include "table.h"


int main(int argc, char*argv[])
{
    TABLE tab = NULL;
    FILE *f;
    int scelta;

    if((f = fopen(argv[1], "r")) == NULL) return -1;


    while (scelta!=0){

        printf("Seleziona una scelta:\n\n");
        printf("1 - Inizializza tabella di simboli;\n");
        printf("2 - Carica dati da file;\n");
        printf("3 - Ricerca dato tramite chiave di ricerca;\n");
        printf("4 - Stampa tabella di simboli;\n");
        printf("5 - Ordina tabella di simboli;\n");
        printf("6 - Inserisci un nuovo item;\n");
        printf("7 - Elimina item in base alla chiave di ricerca;\n");
        printf("0 - Termina programma.\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta){

            case 1:
                if (tab == NULL){
                    tab = table_init(f, tab);
                    printf("\nTabella inizializzata con successo\n");
                }
                else
                    printf("\nTabella già inizializzata\n");
                break;
            case 2:
                if (tab != NULL){
                    table_upload(f, tab);
                    printf("\nTabella caricata con successo\n");
                }
                else
                    printf("\nTabella non ancora inizializzata\n");
                break;
            case 3:
                if (tab != NULL)
                    table_search(tab);
                else
                    printf("\nTabella non ancora inizializzata\n");
                break;
            case 4:
                if (tab != NULL)
                    table_print(tab);
                else
                    printf("\nTabella non ancora inizializzata\n");
                break;
            case 5:
                if (tab != NULL)
                    table_quicksort(tab);
                else
                    printf("\nTabella non ancora inizializzata\n");
                break;
            case 6:
                if (tab != NULL)
                    tab = table_push(tab);
                else
                    printf("\nTabella non ancora inizializzata\n");
                break;
            case 7:
                if (tab != NULL)
                    table_pop();
                else
                    printf("\nTabella non ancora inizializzata\n");
                break;
            case 0:
                if (tab != NULL)
                    table_free(tab);
                else
                    printf("\nTabella non ancora inizializzata\n");
                break;
            default:
                printf("\nValore inserito non corretto\n");
                break;
        }
    }

    return 0;
}
