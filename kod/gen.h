#ifndef GEN_H
#define GEN_H

typedef struct ifEdge {
    double value;
    int exists;
} ifEdge_t;

void generate (char *filename, int rows, int cols, double from, double to);

#endif