#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct Client{
        char id[26];
        char name[26];
        char surname[26];
        char category[26];
        int totaccess;
        float totkb;
        float totsec;
    };

    struct category{
        char name[26];
        int *clients;
        int nc;
        float totcatkb;
        float totcatsec;
    }*cat;

    FILE *f;
    int i,j, n_clienti=0, sec, id, max_id=0, traffic;
    char id_string[26];

CLIENT hashtable_init(int argc, char* argv[], CLIENT client){

    f = fopen(argv[1], "r");

    while(!feof(f)){
        fscanf(f, "%s", id_string);
        id = atoi(id_string);
        if(id>max_id) max_id = id;
        fscanf(f, "%*s%*s%*s");
        n_clienti++;
    }
    rewind(f);

    client = malloc(n_clienti*sizeof(struct Client));

    return client;
}

void hashtable_uploaddata(int argc, char* argv[], CLIENT client){

    cat = malloc(5*sizeof(struct category));
    for(i=0; i<5; i++){
        cat[i].clients = malloc(n_clienti*sizeof(int));
        cat[i].nc = 0;
        cat[i].totcatkb = 0;
        cat[i].totcatsec = 0;
    }

    strcpy(cat[0].name, "Base");
    strcpy(cat[1].name, "Bronze");
    strcpy(cat[2].name, "Silver");
    strcpy(cat[3].name, "Gold");
    strcpy(cat[4].name, "Premium");

    for(i=0; i<n_clienti; i++){
        fscanf(f, "%s", id_string);
        id = atoi(id_string);
        strcpy(client[id].id, id_string);
        fscanf(f, "%s%s%s", client[id].name, client[id].surname, client[id].category);
        client[id].totaccess = 0;
        client[id].totkb = 0;
        client[id].totsec = 0;
        if(strcmp(client[id].category, "Base")==0)
            cat[0].clients[cat[0].nc++] = id;
        if(strcmp(client[id].category, "Bronze")==0)
            cat[1].clients[cat[1].nc++] = id;
        if(strcmp(client[id].category, "Silver")==0)
            cat[2].clients[cat[2].nc++] = id;
        if(strcmp(client[id].category, "Gold")==0)
            cat[3].clients[cat[3].nc++] = id;
        if(strcmp(client[id].category, "Premium")==0)
            cat[4].clients[cat[4].nc++] = id;

    }

    fclose(f);

    f = fopen(argv[2], "w");
    for(i=0; i<50; i++)
    {
        sec = rand()%60;
        fprintf(f, "%s   %d  %d\n", client[rand()%n_clienti].id, sec*2, sec);
    }
    fclose(f);

    f = fopen(argv[2], "r");

    while(!feof(f)){
        fscanf(f, "%s", id_string);
        id = atoi(id_string);
        fscanf(f, "%d%d", &traffic, &sec);
        client[id].totaccess++;
        client[id].totkb += traffic;
        client[id].totsec += sec;
        if(strcmp(client[id].category, "Base")==0) {
            cat[0].totcatkb += traffic;
            cat[0].totcatsec += sec;
        }
        if(strcmp(client[id].category, "Bronze")==0) {
            cat[1].totcatkb += traffic;
            cat[1].totcatsec += sec;
        }
        if(strcmp(client[id].category, "Silver")==0) {
            cat[2].totcatkb += traffic;
            cat[2].totcatsec += sec;
        }
        if(strcmp(client[id].category, "Gold")==0) {
            cat[3].totcatkb += traffic;
            cat[3].totcatsec += sec;
        }
        if(strcmp(client[id].category, "Premium")==0) {
            cat[4].totcatkb += traffic;
            cat[4].totcatsec += sec;
        }
    }
    fclose(f);
    return;
}
void hashtable_filesave(int argc, char* argv[], CLIENT client){

    f = fopen(argv[3], "w");
    for(i=0; i<5; i++)
        fprintf(f, "%s  %.0f  %.0f\n", cat[i].name, cat[i].totcatkb, cat[i].totcatsec);

    fclose(f);

    f = fopen(argv[4], "w");
    for(i=0; i<5; i++){
        fprintf(f, "\n%s\n", cat[i].name);
        for(j=0; j<cat[i].nc; j++)
            fprintf(f, "     %s  %s  %s\n", client[cat[i].clients[j]].id, client[cat[i].clients[j]].name, client[cat[i].clients[j]].surname);
    }
    fclose(f);
    f = fopen(argv[5], "w");
    for(i=0; i<max_id+1; i++)
        fprintf(f, "%s  %s  %s  %s  %d  %.0f  %.0f\n", client[i].id, client[i].name, client[i].surname, client[i].category, client[i].totaccess, client[i].totkb, client[i].totsec);

    fclose(f);

    return;
}
