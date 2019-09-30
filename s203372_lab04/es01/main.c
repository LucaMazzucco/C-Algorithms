#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
  FILE*f;
  int r, c,i,j, cont=0, **m1, simm1 =0, simm2=0;
  struct numeri{
  int ind, numero;
  }**m2;
//ALLOCAZIONE MATRICI E CARICAMENTO DATI MATRICE ESTESA
  if ((f=fopen(argv[1],"r"))==NULL)  return -1;
    fscanf(f, "%d%d", &r, &c);
    m1 = malloc(r*sizeof(int*));
    m2 = malloc(r*sizeof(struct numeri*));
    for(i=0; i<r; i++){
        m1[i] = malloc(c*sizeof(int));
        for(j=0; j<c;j++){
            fscanf(f, "%d", &m1[i][j]);
            printf("%d ", m1[i][j]);
            if (m1[i][j]!=0)
                cont++;
        }
        printf("\n");
        m2[i] = malloc(cont*sizeof(struct numeri));
        printf("sizeof %d\n",sizeof(m1[i]));
        cont = 0;
    }
    printf("\n");
    fclose(f);
    //CARICAMENTO DATI MATRICE COMPATTA E SIMMETRIA MATRICE ESTESA
    for(i=0; i<r; i++){
        for(j=0;j<c;j++){
            if (m1[i][j]!=m1[j][i])
                simm1 = 1;
            if (m1[i][j]!=0){
                m2[i][cont].ind = j;
                m2[i][cont].numero = m1[i][j];
                printf("%d %d   ",m2[i][cont].ind, m2[i][cont].numero );
                cont++;
            }
        }
    printf("\n");
    cont = 0;
    }
    //VERIFICA SIMMETRIA MATRICE COMPATTA
    for(i=0; i<r; i++){
        for(j=0;j<c ;j++)
            if(m1[i][j]!=0){
                if( m2[i][cont].numero != m2[m2[i][cont].ind][i].numero){
                    simm2 = 1;
                    cont++;
                }
            }
    cont = 0;
    }
    //ACCESSO AI DATI DELLE MATRICI IN MODO INDIPENDENTE
    printf("\n\nInserisci riga: (0 - %d): ", r-1);
    scanf("%d", &i);
    printf("\nInserisci colonna: (0 - %d): ", c-1);
    scanf("%d", &j);
    printf("Elemento ricavato da matrice originale: %d\n", m1[i][j]);
    for(cont =0; cont<c;cont++)
        if (m2[i][cont].ind == j)
            printf("Elemento ricavato da matrice compatta:  %d\n", m2[i][cont].numero);
    //DEALLOCAZIONE MEMORIA DINAMICA
    for (i=0; i<c; i++){
        free(m1[i]);
        free(m2[i]);
    }
    free(m1);
    free(m2);
    if (simm1 == 0)
        printf("La matrice originale e' simmetrica\n");
    else
        printf("La matrice originale non e' simmetrica\n");
    if (simm2 == 0)
        printf("La matrice compatta e' simmetrica\n");
    else
        printf("La matrice compatta non e' simmetrica\n");
    return 0;}
