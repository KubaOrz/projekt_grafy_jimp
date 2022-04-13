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
    int *results = calloc(size, sizeof *results);
    queue_t head = NULL;

    results[start] = 1; // 0 to biały, 1 to szary, a 2 to czarny
    head = pushQ(head, start);
    while(head != NULL) {
        u = first(head);
        head = pop(head);
        list_t it = graph -> al[u];
        while (it != NULL) {
            if (results[it -> node] == 0) {
                results[it -> node] = 1;
                head = pushQ(head, it -> node);
            }
            it = it -> next;
        }
        results[u] = 2;
    }
    if (!TEST)
        freeGraph(graph);

    for (int i = 0; i < size; i++) {
        if (results[i] != 2) {
            if (!TEST)
                free(results);
            return 0;
        }
    }
    if (!TEST)
        free(results);
    return 1;
}

queue_t pushQ(queue_t head, int node) {
    queue_t new = malloc(sizeof *new);
    new -> node = node;
    new -> next = NULL;
    if (head == NULL) 
        return new;
    queue_t iter = head;
    while (iter->next != NULL)
        iter = iter -> next;
    iter->next= new;
    return head;
}

int first(queue_t head) {
    return head -> node;
}

queue_t pop(queue_t head) {
    queue_t prev = head;
    head = head -> next;
    free(prev);
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
