#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(list_t head, int node, double w){
    list_t new = malloc(sizeof *new);
    new->node = node;
    new->next = NULL;
    new->w = w;
    if(head == NULL){
        head = new;
        return;
    }
    list_t curent = head;
    while(curent->next != NULL){
        curent = curent->next;
    }
    curent->next = new;
}


void printlist(list_t head){
    list_t curent = head;
    while(curent->next != NULL){
        printf("%d: %f ", curent->next->node, curent->next->w);
        curent = curent->next;
    }
    printf("\n");
}

void freeGraph(graph_t graph) {
    for (int i = 0; i < graph -> nc * graph -> nr; i++) {
        list_t current = graph -> al[i];
        list_t next = NULL;
        while (current != NULL) {
            next = current -> next;
            free(current);
            current = next;
        }
    }
    free(graph -> al);
    free(graph);
}