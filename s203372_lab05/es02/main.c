#include <stdio.h>
#include <stdlib.h>

int catalan ( int n);

int main()
{

    int numero, risultato;

    printf("Quale numero di catalan vuoi calcolare?: ");
    scanf("%d", &numero);
    risultato = catalan(numero);
    printf("Il numero %d di Catalan e': %d", numero, risultato);

    return 0;
}

int catalan(int n){

    int cat = 0, i;

    if (n == 0 || n == 1)
        cat++;
    else
        for (i =0; i<=(n-1); i++)
            cat += catalan(i)*catalan(n-1-i);

    return cat;
}
