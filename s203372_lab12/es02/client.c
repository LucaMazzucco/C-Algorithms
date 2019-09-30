#include <stdio.h>
#include <stdlib.h>
#include "client.h"

struct client{
    char *name;
    int priority;
};

int client_get_priority(CLIENT cl){

    return cl->priority;
}

char *client_get_name(CLIENT cl){

    return cl->name;
}

CLIENT client_init(CLIENT cl){

    cl = malloc(sizeof(struct client));
    return cl;
}

void client_insert(CLIENT cl, char *name, int priority){

    cl->priority = priority;
    cl->name = name;

    return;
}
