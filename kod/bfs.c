#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"
#include "list.h"
#include "bfs.h"

int bfs(list_t *nodes, int start, int size) {
    int u, v;
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
        list_t it = nodes[u];
        while (it -> next != NULL) {
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

    for (int i = 0; i < size; i++) {
        if (results[i].color != 2)
            return 0;
    }
    return 1;
}
