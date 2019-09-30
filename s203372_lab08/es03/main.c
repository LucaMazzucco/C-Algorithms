//INSERIRE IN LINEA DI COMANDO: 6 7_3_6_ _6_8_9 9_9_8_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void disp(int *num[], int pos,int val[],int sol[],int mark[],int n, int k);

int main(int argc, char *argv[])
{
    int *num[3], mark[9] = {0}, i, j,n;
    int *val  = malloc(9 * sizeof(int));
    int *sol  = malloc(9 * sizeof(int));
    if (argc != 5) return -1;

    n = atoi(argv[1]);

    for(j=0; j<3; j++){
        num[j] = malloc(n*sizeof(int));
        for(i=0; i<n; i++)
            num[j][i] = argv[j+2][i]-48;
    }
    for(i=0; i<9; i++)
        val[i] = i;

    disp(num, 0, val, sol, mark, 9, 9);
    return 0;
}

void disp(int *num[], int pos,int val[],int sol[],int mark[],int n, int k){
    int i,m=0, somma1=0, somma2=0, somma3=0;
    if (pos >= k){

       for(i=0; i<6; i++){
           somma1 += (num[0][i]==47? sol[m++]+1:num[0][i])*pow(10,6-i);
           somma2 += (num[1][i]==47? sol[m++]+1:num[1][i])*pow(10,6-i);
           somma3 += (num[2][i]==47? sol[m++]+1:num[2][i])*pow(10,6-i);
       }
       if(somma1+somma2 == somma3){
            printf("\nLa soluzione e':\n\n");
            printf("  %d +\n", somma1/10);
            printf("  %d =\n  --------\n", somma2/10);
            printf("  %d\n", somma3/10);
       }
    return;
    }
    for (i=0; i<n; i++){
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            disp(num, pos+1, val, sol, mark, n, k);
            mark[i] = 0;
        }
    }
    return;
}
