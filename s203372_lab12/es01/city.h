#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

typedef struct city_table *CITY;

CITY city_init(int v);
void city_add(CITY c_tab, char name[20], char region[20], int i);
int city_getv(CITY c_tab, char name[20], int v);

#endif // CITY_H_INCLUDED
