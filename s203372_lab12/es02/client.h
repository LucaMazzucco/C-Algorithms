#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

typedef struct client *CLIENT;

int client_get_priority(CLIENT cl);
char *client_get_name(CLIENT cl);
CLIENT client_init(CLIENT cl);
void client_insert(CLIENT cl, char *name, int priority);

#endif // CLIENT_H_INCLUDED
