#ifndef PQ_H
#define PQ_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "files.h"

typedef struct heapNode{
    double weigth;
    int val;
}*hn_t;

typedef struct pq{
    hn_t *q; //lista
    int n; //licza węzłow w liście (obecnie)
    int s; //rozmiar
}*pq_t;

pq_t init(int s);
void swap(hn_t *a, hn_t *b);
void heapify(pq_t pq, int i);
void add(pq_t pq, int val, double weigth);
void printpq(pq_t pq);
void del(pq_t pq, int num);
int isEmpty(pq_t pq);
hn_t getMin(pq_t pq);



#endif