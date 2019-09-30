#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "city.h"

struct city_table{
    char name[20];
    char region[20];
};

CITY city_init(int v){

    CITY c_tab;
    c_tab = malloc(v*sizeof(struct city_table));
    return c_tab;
}

void city_add(CITY c_tab, char name[20], char region[20], int i){

    strcpy(c_tab[i].name, name);
    strcpy(c_tab[i].region, region);

    return;
}

int city_getv(CITY c_tab, char name[20], int v){

    int i;
    for(i=0; i<v; i++){
        if(strcmp(name, c_tab[i].name) == 0) return i;
    }
    return -1;

}
