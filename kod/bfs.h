#ifndef BFS_H
#define BFS_H

#include "list.h"

typedef struct color {
    int color;
    int distance;
    int parent;
} color_t;

typedef struct queue {
    int node;
    struct queue *next;
} *queue_t;

queue_t pushQ(queue_t head, int node);

int first(queue_t head);

queue_t pop(queue_t head);

void printQueue(queue_t head);

int bfs(graph_t graph, int start); // Zwraca 1 jeśli graf jest spójny i 0 jeśli nie jest

#endif