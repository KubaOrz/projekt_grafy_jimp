#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int node;
    double w;
    struct list *next;
}*list_t;

void push(list_t head, int node, double w);
void printlist(list_t head);

#endif