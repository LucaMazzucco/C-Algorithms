#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#include "item.h"

struct table{
    ITEM person;
    TABLE next;
};

struct table_data{
    int size;
    int max;
    TABLE head;
} data;

int scelta;

TABLE table_init(FILE*f, TABLE tab){
start:
    printf("\n     Seleziona scelta:");
    printf("\n     1 - Carica da file");
    printf("\n     2 - Carica manualmente");
    printf("\n     Scelta: ");
    scanf("%d", &scelta);

    switch (scelta){
        case 1:
            fscanf(f, "%d", &(data.max));
            tab = malloc(sizeof(struct table));
            tab->person = item_init(tab->person, data.max);
            break;
        case 2:
            tab = malloc(sizeof(struct table));
            tab->person = item_init(tab->person, 1);
            tab->next = data.head;
            data.head = tab;
            data.size = 1;
            break;
        default:
            printf("\nValore inserito non corretto!\n");
            goto start;

    }
return tab;
}


void  table_upload(FILE*f, TABLE tab){
    switch(scelta){
        case 1:
            item_upload(f, tab->person, data.max);
            break;
        case 2:
            printf("Caricamento da file non disponibile per lista!\n");
            break;
    }
    return;
}

void  table_print(TABLE tab){
    TABLE t = data.head;
    int i;
    switch(scelta){
        case 1:
            item_print(tab->person, data.max);
            break;
        case 2:
            for (i=0; i<data.size-1; i++, t = t->next)
                item_print(t->person, 1);
            break;
    }
    return;
}

void  table_search(TABLE tab){

    char key[11];
    int i,q=0;
    TABLE t = data.head;
    printf("Inserire il codice alfanumerico: ");
    scanf("%s", key);

    switch(scelta){
        case 1:
            item_search(tab->person, key, 0, data.max);
            break;
        case 2:
            for(i=0; i<data.size&&q==0; i++, t = t->next){
                q = item_search_list(t->person, key);
            }
            if(q == 0)
                printf("Elemento non trovato!\n");
            else
                printf("Item trovato in posizione %d", i);
            break;
    return;
    }
}

void  table_quicksort(TABLE tab){

    switch(scelta){
        case 1:
            item_quicksort(tab->person, 0, data.max-1);
            break;
        case 2:
            printf("Non implementato per l'opzione lista!\n");
            break;
    }
    return;
}

TABLE  table_push(TABLE tab){

    item_push(tab->person);
    tab->next = malloc(sizeof(struct table));
    tab = tab->next;
    tab->person = item_init(tab->person, 1);
    tab->next = data.head;
    data.size++;

return tab;
}

void  table_pop(){

    int i,q=0;
    char key[11];
    TABLE t = data.head;
    printf("Inserisci codice alfanumerico dell'item da eliminare: ");
    scanf("%s", key);
    for(i=0; i<data.size&&q==0; i++, t = t->next){
        q = item_search_list(t->person, key);
    }

    if(q == 0){
        printf("Elemento non trovato!\n");
        return;
    }
    else
        printf("Item trovato in posizione %d\n", i);

    if(t == data.head)
        data.head = t->next;
    for(i=0; i<data.size-2; i++)
        t = t->next;

    t->next = t->next->next;

    data.size--;

    return;
}

void  table_free(TABLE tab){

    int i;
    TABLE t1 = data.head, t2 = data.head;
    switch(scelta){
        case 1:
            free(tab->person);
            free(tab);
            break;
        case 2:
            for(i=0; i<=data.size; i++){
                t2 = t1;
                t1 = t1->next;
                free(t2->person);
                free(t2);
            }

            break;
    }
    return;
}
