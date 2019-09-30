#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{
    FILE*f;
    int i, j, x, k=1;
    char s[20];
    typedef struct{
    char parola[20];
    int lung;
    int occorrenze;
    int posizione[10];
    }seq;

    seq sequenza[50];

    for(i=0; i<50; i++){
        sequenza[i].occorrenze =0;
    }

    if((f=fopen(argv[1], "r"))==NULL)
        printf("Impossibile aprire il file");
    else{
        fscanf(f, "%d", &i);
        for(j=0; j<i; j++){
            fscanf(f, "%s", sequenza[j].parola);
            sequenza[j].lung = strlen(sequenza[j].parola);
        }
    }
    fclose(f);

    if((f=fopen(argv[2], "r"))==NULL)
        printf("Impossibile aprire il file");
    else{
        while(!feof(f)){
        fscanf(f, "%s", s);
        for(j=0; j<i; j++){
            if((strncmp(s,sequenza[j].parola, sequenza[j].lung))==0){
                sequenza[j].posizione[sequenza[j].occorrenze]=k;
                sequenza[j].occorrenze++;
            }
        }
        k++;
        }
        for(j=0; j<i; j++){
            printf("%5s occorrenze 2d  posizioni", sequenza[j].parola, sequenza[j].occorrenze);
            for(x=0; x<sequenza[j].occorrenze; x++)
                printf(" %2d",sequenza[j].posizione[x]);
            printf("\n");
        }
    }
    fclose(f);

    return 0;
}
