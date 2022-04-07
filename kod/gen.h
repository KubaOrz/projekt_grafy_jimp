#ifndef GEN_H
#define GEN_H

typedef struct ifEdge {
    double value;
    int exists;
} ifEdge_t;

enum density {
    ALL = -1,
    HIGH,
    MEDIUM,
    LOW
};

void generate (char *filename, int rows, int cols, double from, double to, int density);

#endif