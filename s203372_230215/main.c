#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct graph{
    int v;
    int e;
    char **name;
    int **adj;
}*G;

struct Lista{
        char name[21];
        struct Lista *next;
    }*lista;

int max = 0, *bestsol;

void listinsert(struct Lista *lista, char *str);
int listlength(struct Lista *lista);
char *listgetname(struct Lista *lista, int i);
int getname(G grafo, char* str);

void path(G grafo, int x, int y, int k, int p, int *mark, int *sol, int totweight, int pos);
void stampasol(int *sol, G grafo, int n);
int num(G grafo, int *mark);
int sum(G grafo, int *mark);

int main(int argc, char* argv[])
{
    int i = 0, j, k, x, y = 0, w = 1, flag, p;
    FILE *f;
    char temp1[21], temp2[21];
    G grafo;

    if((f=fopen(argv[1], "r"))==NULL) return -1;
    lista = malloc(sizeof(struct Lista));
    lista->next = NULL;

    //PRIMA LETTURA FILE E INSERIMENTO IN LISTA
    while(!feof(f)){

        i++;
        fscanf(f, "%s", temp1);
        listinsert(lista, temp1);
        fscanf(f, "%*d");
        fscanf(f, "%s", temp1);
        listinsert(lista, temp1);
    }
    //ALLOCAZIONI DELLA STRUTTURA GRAFO
    grafo = malloc(sizeof(struct graph));
    grafo->v = listlength(lista);
    grafo->e = i;
    grafo->adj = malloc(grafo->v*sizeof(int*));
    grafo->name = malloc(grafo->v*sizeof(char*));
    for(i=0; i<grafo->v; i++){
        grafo->name[i] = malloc(21*sizeof(char));
        grafo->adj[i] = malloc(grafo->v*sizeof(int));
    }
    //INIZIALIZZAZIONE MATRICE ADIACENZE
    for(i=0; i<grafo->v; i++)
        for(j=0; j<grafo->v; j++)
            grafo->adj[i][j] = 0;
    //CARICAMENTO NOMI VERTICI DALLA LISTA
    for(i=0; i<grafo->v; i++)
        grafo->name[i] = listgetname(lista, i);

    rewind(f);
    //SECONDA LETTURA FILE PER CARICAMENTO ADIACENZE
    while(!feof(f)){
        fscanf(f, "%s%d%s", temp1, &i, temp2);
        grafo->adj[getname(grafo, temp1)][getname(grafo, temp2)] = i;
    }
    fclose(f);


    if((f=fopen(argv[2], "r"))==NULL) return -1;

    char **path1, **path2, **commons;
    //ALLOCAZIONE CAMMINI E CARICAMENTO DI ESSI DAL SECONDO FILE
    fscanf(f, "%d", &i);
    i++;
    path1 = malloc(i*sizeof(char*));
    for(j=0; j<i; j++){
        path1[j] = malloc(21*sizeof(char));
        fscanf(f, "%s", path1[j]);
    }

    fscanf(f, "%d", &k);
    k++;
    path2 = malloc(k*sizeof(char*));
    for(j=0; j<k; j++){
        path2[j] = malloc(21*sizeof(char));
        fscanf(f, "%s", path2[j]);
    }
    //ALLOCAZIONE VETTORE PER VERTICI IN COMUNE
    commons = malloc(i*sizeof(char*));
    for(j=0; j<i; j++)
        commons[j] = malloc(21*sizeof(char));

    printf("I vertici in comune sono: ");
    //RICERCA E CARICAMENTO VERTICI IN COMUNE
    for(j=0; j<i; j++){
        for(x=0; x<k; x++){
            if(strcmp(path1[j], path2[x])==0){
                strcpy(commons[y++], path1[j]);
                printf("%s ", path1[j]);
            }
        }
    }
    fclose(f);
    //SPEZZETTAMENTO CAMMINI IN SOTTOCAMMINI
    //Leggendo un cammino per volta per ogni vertice si controlla l'eventuale intersezione
    //la quale mediante un flag genera successivamente un a capo e un incremento del numero dei sottocammini
    printf("\nSottocammino 1.%d: ", w);
    for(j=0; j<i-1; j++){
        flag = 0;
        printf("%s ", path1[j]);
        for(x=0; x<y; x++)
            if(strcmp(path1[j+1], commons[x])==0)
                flag = 1;
        if(flag)
        {
            w++;
            printf("\nSottocammino 1.%d: ", w);
        }
    }
    printf("%s ", path1[j]);
    w = 1;

    printf("\nSottocammino 2.%d: ", w);
    for(j=0; j<k-1; j++){
        flag = 0;
        printf("%s ", path2[j]);
        for(x=0; x<y; x++)
            if(strcmp(path2[j+1], commons[x])==0)
                flag = 1;
        if(flag)
        {
            w++;
            printf("\nSottocammino 2.%d: ", w);
        }
    }
    printf("%s ", path2[j]);
    //SCAN DEI DATI RICHIESTI ALLO SVILUPPO DELL'ULTIMO PUNTO
    printf("\nInserisci coppia di vertici: ");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("Inserisci numero vertici riattraversati: ");
    scanf("%d", &k);
    printf("Inserisci numero riattraversamenti: ");
    scanf("%d", &p);
    //INIZIALIZZAZIONE VARIABILI UTILI ALLA FUNZIONE RICORSIVA PATH PER LO SVILUPPO DELL'ULTIMO PUNTO
    int pos = 1, totweight = 0, mark[grafo->v], *sol;
    sol = malloc((grafo->v+p)*sizeof(int));
    bestsol = malloc((grafo->v+p)*sizeof(int));
    for(w=0; w<grafo->v; mark[w] = 0, w++);
    for(w=0; w<grafo->v+p; sol[w]=-1, w++);
    //CARICAMENTO E MARCAMENTO VERTICE DI PARTENZA
    sol[0] = x;
    mark[x]++;
    //FUNZIONE RICORSIVA
    path(grafo, x, y, k, p, mark, sol, totweight, pos);

    stampasol(bestsol, grafo, grafo->v +p);


    return 0;
}
//INSERISCE NOME VERTICE IN LISTA SE NON GIA' PRESENTE
void listinsert(struct Lista *lista, char *str){

    int flag =0;
    struct Lista *t;
    for(t= lista; t->next!=NULL; t = t->next )
        if(strcmp(t->name, str)==0)
            flag = 1;
    if(!flag){
        strcpy(t->name, str);
        t->next = malloc(sizeof(struct Lista));
        t = t->next;
        t->next = NULL;

    }
    return;
}
//RESTITUISCE LUNGHEZZA LISTA
int listlength(struct Lista *lista){

    int num=0;
    struct Lista *t;
    for(t= lista; t->next!=NULL; t = t->next )
        num++;

return num;
}
//RESTITUISCE NOME IN POSIZIONE RICHIESTA
char *listgetname(struct Lista *lista, int i){

    struct Lista *t;
    for(t = lista; i>0; i--, t= t->next);
    return t->name;
}
//RESTITUISCE INDICE DI UN VERTICE CERCATO PER NOME
int getname(G grafo, char* str){

    int i;
    for(i=0; i<grafo->v; i++)
        if(strcmp(str, grafo->name[i])==0)
            return i;
    return -1;
}
//FUNZIONE RICORSIVA CHE DETERMINA IL CAMMINO MASSIMO E LO SALVA IN BESTSOL
//La funzione viene richiamata sotto opportune condizioni:
//  -la somma degli attraversamenti per ogni vertice -1 (vedere funzione sum)  deve essere minore di p;
//  -il numero dei vertici con mark>1 (vedere funzione num) deve essere minore di k;
//La funzione salva la soluzione in best sol solo se x==y e il peso corrente è maggiore del massimo.
void path(G grafo, int x, int y, int k, int p, int *mark, int *sol, int totweight, int pos){

    int i,j;
    if(totweight>max && x == y){
        max = totweight;
        for(j=0; j<pos; j++) bestsol[j] = sol[j];
        for(;j<grafo->v+p;j++) bestsol[j] = -1;
        return;
    }
    for(i=0; i<grafo->v; i++){
        if(grafo->adj[x][i]!=0){
            mark[i]++;
            if(sum(grafo, mark)<=p){
                if(num(grafo, mark)<=k){
                    sol[pos] = i;
                    path(grafo, i, y, k, p, mark, sol, totweight + grafo->adj[x][i], pos+1);
                }

            }
            mark[i]--;
        }
    }

    return;
}
//STAMPA VETTORE BESTSOL
void stampasol(int *sol, G grafo, int n){

    int i;
    for(i=0; i<n; i++)
        if(sol[i]!=-1)
            printf("%s ", grafo->name[sol[i]]);

    return;
}
//RESTITUISCE IL NUMERO DI VERTICI CON PIU' DI UN ATTRAVERSAMENTO
int num(G grafo, int *mark){

    int i, somma =0;
    for(i=0; i<grafo->v; i++)
        if(mark[i]>1)
            somma++;

return somma;
}
//RESTITUISCE IL NUMERO DI RIATTRAVERSAMENTI
int sum(G grafo, int *mark){

    int i, somma=0;
    for(i=0; i<grafo->v; i++)
        if(mark[i]>1)
            somma += mark[i] -1;

return somma;
}
