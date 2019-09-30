#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
   FILE*f1,*f2;
   int **matr1, **matr2,**matr3, x1, y1, x2, y2,i,j,k, somma=0;
   if((f1=fopen(argv[1], "r"))==NULL){
        printf("Impossibile aprire il file matrice1.txt");
        return -1;}
   else{
        if((f2=fopen(argv[2], "r"))==NULL){
            printf("Impossibile aprire il file matrice2.txt");
            return -2;}
        else{
            fscanf(f1, "%d%d", &x1, &y1);
            fscanf(f2, "%d%d", &x2, &y2);
            if (y1 != x2)
                printf("Prodotto righe per colonne non realizzabile");
            else{
                matr1 = malloc(x1*sizeof(int*));
                for (i=0;i<x1;i++){
                    matr1[i] = malloc(y1*sizeof(int));
                }
                matr2 = malloc(x2*sizeof(int*));
                for (i=0;i<x2;i++){
                    matr2[i] = malloc(y2*sizeof(int));
                }

                for (i=0;i<x1;i++){
                    for (j=0;j<y1;j++){
                        fscanf(f1, "%d", &matr1[i][j]);
                    }
                }
                fclose(f1);
                for (i=0;i<x2;i++){
                    for (j=0;j<y2;j++){
                        fscanf(f2, "%d", &matr2[i][j]);
                    }
                }
                fclose(f2);
            if((f1=fopen("matricerisultato.txt", "w"))==NULL){
                printf("Impossibile aprire nuovo file in scrittura");
                return -3;
            }
            else{
                matr3 = malloc(x1*sizeof(int*));
                for (i=0;i<x1;i++){
                    matr3[i] = malloc(y2*sizeof(int));
                }
                fprintf(f1, "%d %d\n", x1, y2);
                for (i=0;i<x1;i++){
                    for (j=0;j<y2;j++){
                        for (k=0; k<y1; k++){
                            somma += matr1[i][k]*matr2[k][j];
                        }
                        fprintf(f1, "%d ", somma);
                        matr3[i][j] = somma;
                        somma =0;
                    }
                    fprintf(f1,"\n");
                }
            }
            fclose(f1);
                for (i=0;i<x1;i++){
                    free(matr1[i]);
                }
                free(matr1);
                for (i=0;i<x2;i++){
                    free(matr2[i]);
                }
                free(matr2);
                for (i=0;i<x1;i++){
                    free(matr3[i]);
                }
                free(matr3);
            }
        }
   }
    return 0;
}
