#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

typedef struct table *TABLE;

TABLE table_init(FILE*f, TABLE tab);
void  table_upload(FILE*f, TABLE tab);
void  table_print(TABLE tab);
void  table_search(TABLE tab);
void  table_quicksort(TABLE tab);
TABLE table_push(TABLE tab);
void  table_pop();
void  table_free(TABLE tab);

#endif // TABLE_H_INCLUDED
