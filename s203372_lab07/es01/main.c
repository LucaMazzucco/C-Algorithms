#include <stdio.h>
#include <stdlib.h>
#include "libfifo.h"

int main(int argc, char*argv[]){

    int scelta;

    while (1){

        printf("\nScegli opzione:\n");
        printf("1 - Creazione di una nuova coda;\n");
        printf("2 - Stampa del numero di dati in coda;\n");
        printf("3 - Inserimento di un nuovo elemento in coda;\n");
        printf("4 - estrazione di un elemento dalla coda;\n");
        printf("5 - visualizzazione di tutti gli elementi;\n");
        printf("6 - salvataggio di dati su file;\n");
        printf("7 - caricamento di dati da file;\n");
        printf("8 - Esci.\n");

        scanf("%d", &scelta);
        switch (scelta){
            case 1:
                creazione();
                break;
            case 2:
                stampa();
                break;
            case 3:
                inserimento();
                break;
            case 4:
                estrazione();
                break;
            case 5:
                visual();
                break;
            case 6:
                salva();
                break;
            case 7:
                carica(argv[1]);
                break;
            case 8:
                return -1;
            default: printf("Valore inserito non corretto!\n");
        }
    }

    return 0;
}
