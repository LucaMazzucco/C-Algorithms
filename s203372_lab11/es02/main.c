#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(int argc, char* argv[])
{

    CLIENT client = NULL;

    client = hashtable_init(argc, argv, client);
    hashtable_uploaddata(argc, argv, client);
    hashtable_filesave(argc, argv, client);

    printf("Dati telefonici analizzati con successo.\nRisultati caricati sui file.\n");

   return 0;
}
