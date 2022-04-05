#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(list_t head, int node, double w){
    list_t curent = malloc(sizeof(curent));
    curent = head;
    while(curent->next != NULL){
        curent = curent->next;
    }
    curent->next = malloc(sizeof(list_t));
    curent->next->node = node;
    curent->next->w = w;
    curent->next->next = NULL;
}


void printlist(list_t head){
    list_t curent = malloc(sizeof(curent));
    curent = head;
    while(curent->next != NULL){
        printf("%d: %f ", curent->next->node, curent->next->w);
        curent = curent->next;
    }
    printf("\n");
}

