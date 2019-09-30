#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define base 26
/*int main(int argc, char *argv[]){
   int q,w,e,r;
   FILE *f;
   if (( f=fopen(argv[1], "w")) == NULL) return -1;
   for (q = 97; q <= 122; q++)
        for (w = 97; w <= 122; w++)
            for (e = 97; e <= 122; e++)
                for (r = 97; r <= 122; r++)
                    if ((q != 97 && q!= 101 && q!=105 && q!=111 && q!=117) && (w == 97 || w== 101 || w==105 || w==111 || w==117) && (e != 97 && e!= 101 && e!=105 && e!=111 && e!=117) && (r == 97 || r== 101 || r==105 || r==111 || r==117))
                        fprintf(f, "%c%c%c%c\n", q,w,e,r);
    return 0;}
*/

int conversione (int num, int *v, int i);
int main(int argc, char*argv[])
{
    FILE *f;
    if (( f=fopen(argv[1], "w")) == NULL) return -1;
    int numero,n, j, *v, flag = 0,i=0;
    printf("Inserire lunghezza parole: ");
    scanf("%d", &n);
    v = malloc(n*sizeof(int));

    for (j=0;j<n;v[j]=0,j++);
    for (numero = 0; numero < pow(base, n); numero++){
        for(j=n-1; j>0&&pow(base, j)>numero; v[n-j-1] =  97, j--);
        conversione(numero, v, n-1);
        flag = 0;
        for (j = 0; j<n; j++)
            if (j%2!=0 && (v[j] != 97 && v[j]!= 101 && v[j]!=105 && v[j]!=111 && v[j]!=117) || j%2==0 && (v[j] == 97 || v[j]== 101 || v[j]==105 || v[j]==111 || v[j]==117))
                flag = 1;
            if ( flag == 0){
                i++;
                for (j = 0; j<n; j++)
                    fprintf(f, "%c", v[j]);
            fprintf(f,"\n");
            }
    }
    fclose(f);
    printf("%d",i);
    return 0;
}
int conversione(int num, int *v, int i)
{
    if (num < base)
        v[i] = num+97;
    else{
        conversione(num / base, v, i-1);
        v[i] = num%base+97;
    }
    return 0;
}
