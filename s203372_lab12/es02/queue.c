#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "client.h"

struct pqueue {
    CLIENT *cl;
    int heapsize;
};

PQ PQUEUEinit( int maxN ) {
    PQ pq;
    int i;
    pq = malloc(sizeof(struct pqueue));
    pq->cl = (CLIENT *)malloc(maxN*sizeof(CLIENT));
    pq->heapsize = 0;
    for(i=0; i<maxN; i++)
        pq->cl[i] = client_init(pq->cl[i]);
    return pq;
}

void PQinsert (PQ pq,char name[6], int priority)
{
    int i;
    i = pq->heapsize++;
    while (i>=1 && client_get_priority(pq->cl[(i-1)/2]) < priority)
    {
    pq->cl[i] = pq->cl[(i-1)/2];
    i = (i-1)/2;
    }
    client_insert(pq->cl[i], name, priority);
    return;
}

void PQUEUEextractMax(PQ pq)
{
    CLIENT cl;
    cl = pq->cl[pq->heapsize-1];
    pq->cl[pq->heapsize-1] = pq->cl[0];
    pq->cl[0] = cl;

    pq->heapsize--;
    Heapify(pq, 0);
    return;
}

void Heapify(PQ pq, int i) {
    int l, r, largest;
    CLIENT cl;
    l = 2*i+1;
    r = 2*i+2;
    if (l < pq->heapsize && client_get_priority(pq->cl[l]) > client_get_priority(pq->cl[i]))
        largest = l;
    else
        largest = i;
    if (r<pq->heapsize && client_get_priority(pq->cl[r]) > client_get_priority(pq->cl[largest]))
        largest = r;

    if (largest != i) {
    cl = pq->cl[largest];
    pq->cl[largest] = pq->cl[i];
    pq->cl[i] = cl;

    Heapify(pq, largest);
    }
    return;
}

void PQshow(PQ pq){
    int i;
    printf("Lista clienti in coda:\n");
    for(i=0; i<pq->heapsize; i++)
        printf("Cliente: %s - Priorita': %d\n", client_get_name(pq->cl[i]), client_get_priority(pq->cl[i]));

    return;
}
