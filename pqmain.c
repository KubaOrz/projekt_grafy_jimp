#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

int main(int argc, char *argv){
    pq_t pq;
    pq = init(6);
    add(pq, 4, 3.5);
    add(pq, 3, 4.2);
    add(pq, 18, 8.1);
    add(pq, 14, 12.3);
    add(pq, 8, 0.103);
    add(pq,7, 4.6);
    printpq(pq);    
}