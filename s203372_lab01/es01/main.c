#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    FILE*f;
    int x, y, i,j, p,q,k=0;
    int matrice[20][20];
    float media=0, somma=0;
    f = fopen(argv[1], "r");
    if (f == NULL)
        printf("Impossibile aprire il file");
    else{
        for(x=0; x<20; x++){
            for(y=0; y<20; y++){
                matrice[x][y] = 0;
            }
        }
        fscanf(f, "%d%d", &x,&y);
        while(!feof(f)){
            for(i=1; i<=x; i++){
                for(j=1; j<=y; j++){
                     fscanf(f, "%d", &matrice[i][j]);
                }
            }
        }
    }
    fclose(f);
    f = fopen(argv[2], "w");
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            for (p=i-1;p<=i+1;p++){
                for(q=j-1;q<=j+1;q++)
                {
                    somma += matrice[p][q];
                    if (p>0&&p<=x&&q>0&&q<=y)
                        k++;
                }
            }
            somma -= matrice[i][j];
            media = somma/(k-1);
            fprintf(f,"%5.2f ", media);
            somma =0;
            k = 0;
        }
        fprintf(f,"\n");
    }
    fclose(f);
    return 0;
}
