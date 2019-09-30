#include <stdio.h>
#include <stdlib.h>
#include "libscelta.h"
#include "libpila.h"
#include "libcoda.h"
#include "libpriorita.h"

int main()
{
    int scelta;


    printf("Scegli una opzione tra le seguenti:\n");
    printf("1 - Gestione lista non ordinata;\n");
    printf("2 - Gestione pila;\n");
    printf("3 - Gestione coda;\n");
    printf("4 - Gestione coda a priorita';\n");
    printf("5 - Esci.\n");

    scanf("%d", &scelta);

    switch (scelta){

        case 1:
            lista();
            break;
        case 2:
            pila();
            break;
        case 3:
            coda();
            break;
        case 4:
            priorita();
            break;

        case 5:
            return -1;
         default:
            printf("Inserisci valore corretto!");
            break;

    }


    return 0;
}
