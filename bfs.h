#ifndef BFS_H
#define BFS_H

#include "list.h"

typedef struct color {
    int color;
    int distance;
    int parent;
} color_t;

int bfs(list_t *nodes, int start); // Zwraca 1 jeśli graf jest spójny i 0 jeśli nie jest

#endif