#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

void pushQ(queue_t head, int node) {
    queue_t new = malloc(sizeof *new);
    new = head;
    while (new -> next != NULL) {
        new = new -> next;
    }
    new -> next = malloc(sizeof(queue_t));
    new -> next -> node = node;
    new -> next -> next = NULL;
}

int first(queue_t head) {
    return head -> next -> node;
}

queue_t pop(queue_t head) {
    head = head -> next;
    return head;
}

void printQueue(queue_t head){
    queue_t curent = malloc(sizeof(curent));
    curent = head;
    while(curent->next != NULL){
        printf("%d ", curent->next->node);
        curent = curent->next;
    }
    printf("\n");
}

