#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "bfs.h"

int bfs(graph_t graph, int start) {
    int u, v;
    int size = graph -> nc * graph -> nr;
    color_t *results = malloc(size * sizeof *results); // musi być jakoś przekazana ilość wierzchołków
    queue_t head = malloc(sizeof *head);

    for (int i = 0; i < size; i++) {
        results[i].color = 0;
        results[i].distance = -1; // -1 czyli nieskończoność
        results[i].parent = -1; // czyli nie ma przodka
    }
    results[start].color = 1; // 0 to biały, 1 to szary, a 2 to czarny
    results[start].distance = 0;
    results[start].parent = -1;
    pushQ(head, start);
    while(head -> next != NULL) {
        u = first(head);
        pop(head);
        list_t it = graph -> al[u];
        while (it != NULL) {
            if (results[it -> node].color == 0) {
                results[it -> node].color = 1;
                results[it -> node].distance = results[u].distance + 1;
                results[it -> node].parent = u;
                pushQ(head, it -> node);
            }
            it = it -> next;
        }
        results[u].color = 2;
        head = head -> next;
    }

    freeGraph(graph);

    for (int i = 0; i < size; i++) {
        if (results[i].color != 2) {
            free(results);
            return 0;
        }
    }
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
