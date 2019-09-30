#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc, char *argv[])
{

    FILE*f;
    char s;
    int i=0, j=1, x=0, maxx=0;
    typedef struct {
    int conteggio;
    int posizioni[10];
    }parola;

    parola parole[100];

    for (i=0; i<100; i++)
        parole[i].conteggio =0;

    f = fopen(argv[1], "r");
    if(f==NULL)
        printf("Impossibile aprire il file");
    else{
        while(!feof(f)){
            fscanf(f, "%c", &s);
            if(isalpha(s)!=0)
                x++ ;
            else{
            if(x>0){
            if(x>maxx)
                maxx=x;
            parole[x].posizioni[parole[x].conteggio] = j;
            parole[x].conteggio++;
            j++;
            x=0;
            }
            }
        }

    }
    printf("%10s %10s %10s\n\n", "Lunghezza", "Conteggio", "  Posizioni");
    for(i=0; i<=maxx;i++){
        if(parole[i].conteggio!=0){
        printf("%10d %10d  ", i, parole[i].conteggio);

        for(j=0; j<parole[i].conteggio; j++)
            printf(" %2d",parole[i].posizioni[j]);
        printf("\n");
        }
    }
    return 0;
}
