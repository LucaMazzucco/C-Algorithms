#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct coda{
        char codice[11];
        struct coda *succ;
    } *lista, *inizio, *cont;
    int scelta, i=0, j=0;
    inizio = (lista = malloc(sizeof(struct coda*)));
 while (1){
    printf("\n1 - Aggiungi persona in coda;\n2 - Togli persona in testa;\n3 - Stampa lista attesa;\n4 - Chiudi.\nScegli un'opzione: ");
    scanf("%d", &scelta);

    switch (scelta){
        case 1:
            printf("\nInserisci codice nuovo cliente: ");
            scanf("%s", lista->codice);
            lista = (lista->succ = malloc(sizeof(struct coda*)));
            i++;
            break;
        case 2:
            if (i>0){
                free(inizio);
                inizio = inizio->succ;
                i--;
                printf("\nPersona in testa tolta con successo\n");
            }
            else
                printf("\nNessuna persona da togliere dalla lista!");
            break;
        case 3:
            printf("\nLista attesa: \n");
            cont = inizio;
            for (j=0; j<i; j++){
                printf("%d - %s\n", j, cont->codice);
                cont = cont->succ;
            }
            break;
        case 4:
            return -1;
            break;
        default:
            printf("\nInserisci valore corretto!\n");
            break;
    }
 }
    return 0;
}
