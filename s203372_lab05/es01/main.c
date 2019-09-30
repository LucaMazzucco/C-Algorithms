#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int conversione (int num, int bas);
int main()
{
    int base = 26, numero,n;
    printf("Inserire lunghezza parole: ");
    scanf("%d", &n);
    for (numero = 0; numero < pow(26, n)-1; numero++, printf("\n"))
        conversione(numero, base);
    return 0;
}
int conversione(int num, int bas)
{
    if (num < bas)
        printf("%c", num+97);
    else{
        conversione(num / bas, bas);
        printf("%c", (num%bas)+97);
    }
    return 0;
}
