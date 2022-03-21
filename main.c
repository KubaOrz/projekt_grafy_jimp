#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "edge.h"

int main(int argc, char **argv){  
    printf("Hello World!\n");
    int i =1;
    edge_t *ania = malloc(sizeof(ania));
    edge_t *ma = malloc(sizeof(ma));
    edge_t *kota = malloc(sizeof(kota));
    ania->snode = 0;
    ania->fnode = 2;
    ania->w = 2;
    ma->snode = 0;
    ma->fnode = 2;
    ma->w = 0.5;
    kota->snode = 2;
    kota->fnode = 3;
    kota->w = 0.13;
    edge_t **edges = malloc(sizeof(edges)*3);
    edges[0] = ania;
    edges[1] = ma;
    edges[2] = kota;
    printf("%d, %d, %d\n", &ania, &ma, &kota);
    save(edges,"abc",1,3);
    return 0;
}