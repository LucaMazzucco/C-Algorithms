#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
/**********************
DICHIARAZIONE VARIABILI
**********************/
    FILE *f1, *f2;
    int i, j, n_risorse=0, n_compiti=0, carico_min, carico_max, carico_min_index, differenza;

    struct compiti{
        char nome[11];
        int difficolta;
    }*comp;

    struct risorse{
        char nome[21];
        int carico;
    }*ris;
/***********************************
CONTROLLO PARAMETRI LINEA DI COMANDO
***********************************/
    if(argc != 3) return -1;
    if((f1 = fopen(argv[1], "r")) == NULL) return -1;
    if((f2 = fopen(argv[2], "r")) == NULL) return -1;

/*******************************
ALLOCAZIONE VETTORI DI STRUTTURE
*******************************/
    while(!feof(f1)){
        fscanf(f1, "%*s%*d");
        n_compiti++;
    }
    comp = malloc(n_compiti*sizeof(struct compiti));

    while(!feof(f2)){
        fscanf(f2, "%*s");
        n_risorse++;
    }
    ris = malloc(n_risorse*sizeof(struct risorse));

    rewind(f1);
    rewind(f2);

/*********************
ACQUISIZIONE DATI FILE
*********************/
    for(i=0; i<n_compiti; i++)
        fscanf(f1, "%s%d", comp[i].nome, &comp[i].difficolta);

    for(i=0; i<n_risorse; i++){
        fscanf(f2, "%s", ris[i].nome);
        ris[i].carico = 0;
    }

/************************
SOLUZIONE APPROCIO GREEDY
Attribuisco il compito
corrente alla risorsa
con meno carico.
************************/

    for(i=0; i<n_compiti; i++){

        carico_min = ris[0].carico;
        carico_min_index = 0;
        for(j=1; j<n_risorse; j++)
            if(ris[j].carico < carico_min){
                carico_min = ris[j].carico;
                carico_min_index = j;
            }
        ris[carico_min_index].carico += comp[i].difficolta;
    }
    for(i=0; i<n_risorse; i++)
        printf("%s, carico totale: %d\n", ris[i].nome, ris[i].carico);

        carico_min = ris[0].carico;
        carico_max = ris[0].carico;
        carico_min_index = 0;
        for(j=1; j<n_risorse; j++){
            if(ris[j].carico < carico_min){
                carico_min = ris[j].carico;
            }
            if(ris[j].carico > carico_max){
                carico_max = ris[j].carico;
            }
        }

    differenza = carico_max-carico_min;
    printf("\nDifferenza tra carichi max e min: %d", differenza);

/************************************************************
DEALLOCAZIONE VETTORI, CHIUSURA FILES, TERMINAZIONE PROGRAMMA
************************************************************/

    free(comp);
    free(ris);
    fclose(f1);
    fclose(f2);

    return 0;
}
