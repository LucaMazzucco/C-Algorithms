#include <stdio.h>
#include <stdlib.h>

int differenza, *sol_best, flag = 0;

 struct compiti{
        char nome[11];
        int difficolta;
        int mark;
    }*comp;

struct risorse{
        char nome[21];
        int carico;
    }*ris;

void disp(int pos, int *sol, int n_compiti, int n_risorse);

int main(int argc, char *argv[])
{
/**********************
DICHIARAZIONE VARIABILI
**********************/
    FILE *f1, *f2;
    int i, n_risorse=0, n_compiti=0, *sol;

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
    sol = malloc(n_compiti*sizeof(struct compiti));
    sol_best = malloc(n_compiti*sizeof(struct compiti));

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
    for(i=0; i<n_compiti; i++){
        fscanf(f1, "%s%d", comp[i].nome, &comp[i].difficolta);
        comp[i].mark = 0;
        differenza += comp[i].difficolta;
    }

    for(i=0; i<n_risorse; i++){
        fscanf(f2, "%s", ris[i].nome);
        ris[i].carico = 0;
    }

/******************************************
SOLUZIONE APPROCIO DISPOSIZIONI DEI COMPITI
Per ogni disposizione, i compiti vengono
attribuiti in sequenza alle risorse.
Ad ogni attribuizione si compara con la
soluzione ottimale precedente.
*****************************************/


    disp(0, sol, n_compiti, n_risorse);


/************************************************************
DEALLOCAZIONE VETTORI, CHIUSURA FILES, TERMINAZIONE PROGRAMMA
************************************************************/

    free(comp);
    free(ris);
    fclose(f1);
    fclose(f2);

    return 0;
}

/***************************************************
FUNZIONE RICORSIVA PER CALCOLO DISPOSIZIONI SEMPLICI
***************************************************/

void disp(int pos, int *sol, int n_compiti, int n_risorse){


    int i,j, carico_max, carico_min;

    if(differenza == 0) return;

    if(pos == n_compiti){
        for(j=0; j<n_compiti; j++)
            ris[j%3].carico += sol[j];

        carico_min = ris[0].carico;
        carico_max = ris[0].carico;

        for(j=1; j<n_risorse; j++){
            if(ris[j].carico < carico_min){
                carico_min = ris[j].carico;
            }
            if(ris[j].carico > carico_max){
                carico_max = ris[j].carico;
            }
        }

        if(differenza > carico_max-carico_min){
            differenza = carico_max-carico_min;
            for(j=0; j<n_compiti; j++)
                sol_best[j] = sol[j];
            system("cls");
            for(i=0; i<n_risorse; i++)
                printf("%s, carico totale: %d\n", ris[i].nome, ris[i].carico);
              printf("\nDifferenza tra carichi max e min: %d\n\n", differenza);
        }

         for(j=0; j<n_risorse; j++)
            ris[j].carico = 0;

        return;
    }
    flag = 1;
    for(i=0; i<n_compiti; i++)
        if(comp[i].mark == 0){
            comp[i].mark = 1;
            sol[pos] = comp[i].difficolta;
            disp(pos+1, sol, n_compiti, n_risorse);
            comp[i].mark = 0;
        }

return;
}
