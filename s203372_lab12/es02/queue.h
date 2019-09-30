#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct pqueue *PQ;

PQ PQUEUEinit(int maxN);
void PQinsert(PQ pq, char name[6], int priority);
void PQUEUEextractMax(PQ pq);
void Heapify(PQ pq, int i);
void PQshow(PQ pq);

#endif // QUEUE_H_INCLUDED
