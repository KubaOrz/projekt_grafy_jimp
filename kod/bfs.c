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
    queue_t head=NULL; /*= malloc(sizeof *head);

    head -> node = start;
    head -> next = NULL;*/

    for (int i = 0; i < size; i++) {
        results[i].color = 0;
    }
    results[start].color = 1; // 0 to biały, 1 to szary, a 2 to czarny
    head = pushQ(head, start);
    while(head != NULL) {
        u = first(head);
        head = pop(head);
        list_t it = graph -> al[u];
        while (it != NULL) {
            if (results[it -> node].color == 0) {
                results[it -> node].color = 1;
                head = pushQ(head, it -> node);
            }
            it = it -> next;
        }
        results[u].color = 2;
    }

    if (!TEST)
        freeGraph(graph);

    for (int i = 0; i < size; i++) {
        if (results[i].color != 2) {
            if (!TEST)
                free(results);
                //free(head);
            return 0;
        }
    }
    if (!TEST)
        free(results);
        //free(head);
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
    /*queue_t new = head;
    while (head != NULL) {
        head = head -> next;
    }
    head = malloc(sizeof(queue_t));
    head -> node = node;
    head -> next = NULL;
    return new;*/
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
