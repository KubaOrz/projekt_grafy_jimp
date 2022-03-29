#include <stdio.h>
#include <stdlib.h>
#include "pq.h"


pq_t init(int size){
    pq_t pq = malloc(sizeof(pq));
    pq->q = malloc(sizeof(pq->q)* size);
    pq->s = size;
    pq->n = 0;
    return pq;
}

void swap(hn_t *a, hn_t *b){
    hn_t tmp = malloc(sizeof(tmp));
    tmp = *b;
    *b = *a;
    *a = tmp;
}

void heapify(pq_t pq, int i){
    if(pq->n == 1){
        printf("Kopiec ma jeden element");
    }
    else{
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l<pq->n && pq->q[l]->weigth < pq->q[smallest]->weigth){
            smallest = l;
        }
        if(r<pq->n && pq->q[r]->weigth < pq->q[smallest]->weigth){
            smallest = r;
        }
        if(smallest != i){
            swap(&pq->q[i], &pq->q[smallest]);
            heapify(pq, smallest);
        }
    }
}

void add(pq_t pq, int val, double weigth){
    hn_t node = malloc(sizeof(node));
    node->val = val;
    node->weigth = weigth;
    if(pq->n == 0){
        pq->q[0] = node;
        pq->n += 1;
    }
    else{
        pq->q[pq->n] = node;
        pq->n += 1;
        for(int i = pq->n/2 -1 ; i>=0; i--){
            heapify(pq,i);
        }
    }
}

void printpq(pq_t pq){
    for(int i = 0; i<pq->n; i++){
        printf("%d %lf\n", pq->q[i]->val, pq->q[i]->weigth);
    }
}

void del(pq_t pq, int num){
    int i;
    for(i = 0; i<pq->n; i++){
        if(pq->q[i]->val == num){
            break;
        }
    }
    swap(&pq->q[i], &pq->q[pq->n -1]);
    pq->n -= 1;
    for(int j = pq->n/2 - 1; j >=0; j--){
        heapify(pq, j);
    }
}

int isEmpty(pq_t pq){
    return pq->s == 0;
}

hn_t getMin(pq_t pq){
    if (isEmpty(pq)){
        return NULL;
    }
    hn_t root = malloc(sizeof(root));
    hn_t last = malloc(sizeof(last));
    root = pq->q[0];
    last = pq->q[pq->s - 1];
    pq->q[0] = last;
    pq->s -= 1;
    heapify(pq, 0);
    return root;
}


