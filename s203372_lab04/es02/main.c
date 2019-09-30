#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char*argv[])
{
    FILE*f,*f1;
    int n,i,j,aa,mm,gg;
    struct studente{
    char *nome, *cognome, *data, *sesso;
    }*stu,temp;
//APRO FILE IN LETTURA E ALLOCO MEMORIA
    if ((f=fopen(argv[1], "r"))==NULL || argc != 2) return -1;
        fscanf(f, "%d", &n);
        stu = malloc(n*sizeof(struct studente));
        for(i=0; i<n; i++){
            stu[i].nome = malloc(35*sizeof(char));
            stu[i].cognome = malloc(35*sizeof(char));
            stu[i].data = malloc(9*sizeof(char));
            stu[i].sesso = malloc(2*sizeof(char));
//CARICO DATI NELLE STRUTTURE ALLOCATE
            fscanf(f, "%s%s%s%s", stu[i].nome, stu[i].cognome, stu[i].data, stu[i].sesso);
        }
//ORDINAMENTO PER DATA CRESCENTE
        fclose(f);
        for (i =0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                   aa = strcmp(stu[i].data+6, stu[j].data+6);
                   mm = strncmp(stu[i].data+3, stu[j].data+3,2);
                   gg = strncmp(stu[i].data, stu[j].data,2);
                if (aa >= 0 || (aa==0 && mm>=0) || (aa==0 && mm==0 && gg >=0) ){
                    temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
            }
        }
//STAMPO IN FILE SEPARATI PER SESSO I CONTENUTI ORDINATI PER DATA
        if ((f = fopen("ragazzi.txt", "w"))==NULL)      return -2;
            if ((f1= fopen("ragazze.txt", "w"))==NULL)  return -3;
                   for(i=0; i<n;i++){
                        if( (strcmp(stu[i].sesso, "M"))==0)
                            fprintf(f,"%s %s %s %s\n", stu[i].nome, stu[i].cognome,stu[i].data, stu[i].sesso);
                        else
                            fprintf(f1,"%s %s %s %s\n", stu[i].nome, stu[i].cognome,stu[i].data, stu[i].sesso);
                   }
//CHIUDO FILE
        fclose(f);
        fclose(f1);
        for (i=0; i<n; i++)
             printf("%s %s %s %s \n", stu[i].nome, stu[i].cognome, stu[i].data, stu[i].sesso);
//DEALLOCO MEMORIA
        for(i=0; i<n; i++){
            free(stu[i].nome);
            free(stu[i].cognome);
            free(stu[i].data);
            free(stu[i].sesso);
        }
        free(stu);
    return 0;
}
