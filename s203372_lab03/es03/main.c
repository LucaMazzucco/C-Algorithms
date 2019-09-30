#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int i,j,k, scelta, comp, r;
    char **stringa, *temp;

    stringa = malloc(100*sizeof(char*));
    for(i=0; i<100;i++)
        stringa[i] = malloc(25*sizeof(char));
    i =0;
    while(1){
    printf("1 - Inserisci nuova stringa\n");
    printf("2 - Elimina stringa con ricerca dicotomica\n");
    printf("3 - Stampa tutte le stringhe\n");
    printf("4 - Esci\n");
    printf("Scegliere una funzione: ");
    scanf("%d", &scelta);

    switch (scelta){
        case 1:
            printf("\nScrivi stringa: ");
            scanf("%s", stringa[i]);
            i++;
            break;
        case 2:
            for(j=0;j<i-1;j++)
                for(k=j+1;k<i;k++)
                    if ((strcmp(stringa[j], stringa[k]))>=0){
                        temp = stringa[j];
                        stringa[j]=stringa[k];
                        stringa[k]=temp;}

            printf("\nInserisci stringa da eliminare: ");
            scanf("%s", temp);

            j=0;
            k=i-1;
            while(1){
            r = floor((j+k)/2);
            printf("%d\n", r);
            comp = strcmp(stringa[r], temp);
            if (comp==0){
                printf("Stringa eliminata con successo");
                strcpy(stringa[r],stringa[i-1]);
                i--;
                break;}
            else{
                if(j==k){
                    printf("Stringa non trovata");
                    break;}
                if(comp<0)
                    j = r + 1;
                else
                    k = r - 1;
            }
            }

            break;
        case 3:
            for(j=0;j<i;j++)
                printf("%s\n", stringa[j]);
            break;
        case 4:
            return 0;

    }
    }

    return 0;
}
