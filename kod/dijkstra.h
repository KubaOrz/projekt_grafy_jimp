#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "files.h"

typedef struct heapNode{ //elementy stosu
    double weigth; //waga połączenia
    int val; //numer wierzchołka docelowego
}*hn_t;

typedef struct pq{
    hn_t *q; //lista
    int n; //licza węzłow w liście (obecnie)
    int s; //rozmiar
    int *pos; 
}*pq_t;

pq_t init(int s);
void swap(hn_t *a, hn_t *b);
void heapify(pq_t pq, int i);
void add(pq_t pq, int val, double weigth);
void printpq(pq_t pq);
void del(pq_t pq, int num);
int isEmpty(pq_t pq);
hn_t getMin(pq_t pq);
void decreseKey(pq_t pq, int val, double weigth); //ciekawe czy da się zrobić żeby bez tego działało
int isInPQ(pq_t pq, int val);//ciekawe czy da się zrobić żeby bez tego działało
void freePQ(pq_t pq);
void dijkstra(int src, graph_t graph, int tryb);


#endif