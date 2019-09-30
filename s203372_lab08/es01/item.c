#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct item{
    char key[11];
    char name[31];
    char surname[31];
    char date[9];
}Item;

ITEM item_init(ITEM tab, int n){

    tab = malloc(n*sizeof(struct item));
return tab;
}

void item_upload(FILE *f, ITEM tab, int n){

    int i;
    for(i=0; i<n; i++){
        fscanf(f, "%s", tab[i].key);
        fscanf(f, "%s", tab[i].name);
        fscanf(f, "%s", tab[i].surname);
        fscanf(f, "%s", tab[i].date);

    }

    return;
}

void item_print(ITEM tab, int n){

    int i;
    for(i=0; i<n; i++){
        printf("\n");
        printf("%s\n", tab[i].key);
        printf("%s\n", tab[i].name);
        printf("%s\n", tab[i].surname);
        printf("%s\n", tab[i].date);
    }
    return;
}

void item_search(ITEM tab, char key[11], int l, int r){

    int q = (l+r)/2;
    if (strcmp(key, tab[q].key) == 0){
        printf("Elemento trovato in posizione %d", q);
        return;
    }
    else{
        if ( strcmp(tab[q].key, key) < 0)
            item_search(tab, key, q+1, r);
        else
            item_search(tab, key, l, q-1);
    }
    printf("Elemento non trovato");

    return;
}

void item_quicksort(ITEM tab, int l, int r)
{
    int q;
    if (r<=l)
        return;
    q = item_partition(tab, l, r);
    item_quicksort(tab, l, q-1);
    item_quicksort(tab, q+1, r);

    return;
}

int item_partition(ITEM tab, int l, int r){

    int i = l-1, j = r;
    struct item temp;
    struct item x = tab[r];
    for ( ; ; ) {
        while(strcmp(tab[++i].key, x.key) < 0);
        while(strcmp(tab[--j].key, x.key) > 0);
        if (j == l)
            break;
        if (i >= j)
            break;
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
    temp = tab[i];
    tab[i] = tab[r];
    tab[r] = temp;
return i;
}

void item_push(ITEM tab){

   printf("\nInserisci codice alfanumerico: ");
   scanf("%s", tab->key);
   printf("\nInserisci nome: ");
   scanf("%s", tab->name);
   printf("\nInserisci cognome: ");
   scanf("%s", tab->surname);
   printf("\nInserisci data di nascita: ");
   scanf("%s", tab->date);


   return;
}

int  item_search_list(ITEM tab, char key[11]){

    if (strcmp(tab->key, key) != 0)
        return 0;
    else
        return 1;
}
