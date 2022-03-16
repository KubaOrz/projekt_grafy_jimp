#include <stdio.h>
#include <stdlib.h>
#include "edge.h"

int get_size(edge_t *tab){
    return sizeof(*tab)/ sizeof(tab[0]);
}