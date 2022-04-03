#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "pq.h"

int main(int argc, char *argv){
    pq_t pq;
    pq = init(6);
    add(pq, 4, 0);
    add(pq, 3, DBL_MAX);
    add(pq, 18, DBL_MAX);
    add(pq, 14, DBL_MAX);
    add(pq, 8, DBL_MAX);
    add(pq,7, DBL_MAX);
    printpq(pq);    
}