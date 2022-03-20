#ifndef GEN_H
#define GEN_H

#include "files.h"
#include "edge.h"

typedef struct ifEdge {
    double value;
    int exists;
} ifEdge_t;

int generate (edge_t *edges, int rows, int cols, double from, double to);

#endif