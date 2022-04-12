#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "bfs.h"

#ifndef TEST
#define TEST 0
#endif

int bfs(graph_t graph, int start) {
    int u, v;
    int size = graph -> nc * graph -> nr;
    color_t *results = malloc(size * sizeof *results);
    queue_t head = malloc(sizeof *head);

    for (int i = 0; i < size; i++) {
        results[i].color = 0;
    }
    results[start].color = 1; // 0 to biały, 1 to szary, a 2 to czarny
    pushQ(head, start);
    while(head -> next != NULL) {
        u = first(head);
        pop(head);
        list_t it = graph -> al[u];
        while (it != NULL) {
            if (results[it -> node].color == 0) {
                results[it -> node].color = 1;
                pushQ(head, it -> node);
            }
            it = it -> next;
        }
        results[u].color = 2;
        head = head -> next;
    }

    if (!TEST)
        freeGraph(graph);

    for (int i = 0; i < size; i++) {
        if (results[i].color != 2) {
            if (!TEST)
                free(results);
            return 0;
        }
    }
    if (!TEST)
        free(results);
    return 1;
}

void pushQ(queue_t head, int node) {
    queue_t new = head;
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

queue_t pop(queue_t head) { // Jak to zwolnić??? :(
    //queue_t prev = head;
    head = head -> next;
    //free(prev);
    return head;
}

void printQueue(queue_t head){
    queue_t curent = head;
    while(curent->next != NULL){
        printf("%d ", curent->next->node);
        curent = curent->next;
    }
    printf("\n");
}