#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

typedef struct item *ITEM;

ITEM item_init(ITEM tab, int n);
void item_upload(FILE *f, ITEM tab, int n);
void item_print(ITEM tab, int n);
void item_search(ITEM tab, char key[11], int l, int r);
void item_quicksort(ITEM tab, int l, int r);
int item_partition(ITEM tab, int l, int r);
void item_push(ITEM tab);
int  item_search_list(ITEM tab, char key[11]);

#endif // ITEM_H_INCLUDED
