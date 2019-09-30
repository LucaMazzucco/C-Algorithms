#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

typedef struct item_data *ITEM;

ITEM item_new(int key, char *name);
int item_getkey(ITEM item);
void item_visit(ITEM item);
void item_filesave(ITEM item, FILE*f);

#endif // ITEM_H_INCLUDED
