#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct item_data{
    int key;
    char name[26];
};

ITEM item_new(int key, char* name){
    ITEM item;
    item = malloc(sizeof(struct item_data));
    item->key = key;
    strcpy(item->name, name);
    return item;
}

int item_getkey(ITEM item){

    return item->key;
}

void item_visit(ITEM item)
{
    printf("%d  %s\n", item->key, item->name);
    return;
}

void item_filesave(ITEM item, FILE *f){

    fprintf(f, "%d  %s\n", item->key, item->name);
    return;

}
