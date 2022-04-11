#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dijkstra.h"
#include "bfs.h"
#include "error.h"
#include "list.h"

#ifndef TEST
#define TEST 0
#endif

pq_t init(int size){
    pq_t pq = malloc(sizeof(pq));
    pq->q = malloc(sizeof(pq->q)* size);
    pq->pos = malloc(sizeof(pq->pos)* size);
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
        ;
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
            pq->pos[pq->q[smallest]->val] = i;
            pq->pos[pq->q[i]->val] = smallest;
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
        printf("%d\n", pq->q[i]->val);
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
    return pq->n == 0;
}

hn_t getMin(pq_t pq){
    if (isEmpty(pq)){
        return NULL;
    }
    hn_t root = malloc(sizeof(root));
    hn_t last = malloc(sizeof(last));
    root = pq->q[0];
    last = pq->q[pq->n - 1];
    pq->q[0] = last;
    pq->n -= 1;
    heapify(pq, 0);
    return root;
}

void decreseKey(pq_t pq, int val, double weigth){
    int pos = pq->pos[val];
    pq->q[pos]->weigth = weigth;
    while(pos && pq->q[pos]->weigth < pq->q[(pos-1)/2]->weigth){
        pq->pos[pq->q[pos]->val] = (pos - 1)/2;
        pq->pos[pq->q[(pos-1)/2]->val] = pos;
        swap(&pq->q[pos], &pq->q[(pos-1)/2]);
        pos = (pos - 1)/2;
    }
}

int isInPQ(pq_t pq, int val){
    if(pq->pos[val] < pq->n){
        return 1;
    }
    return 0;
}

void dijkstra(int src, graph_t graph, int tryb){
    int size = graph->nc * graph->nr;
    double *dist = malloc(sizeof(*dist)*size);
    int *prew = malloc(sizeof(*prew)* size); //talbica poprzednikówa
    pq_t pq = init(size);
    for(int i = 0; i<size; i++){
        dist[i] = DBL_MAX;
        add(pq, i, dist[i]);
        pq->pos[i] = i;
        prew[i] = -1;
    }   

    add(pq, src, dist[src]);
    pq->pos[src] = src;
    dist[src] = 0;
    decreseKey(pq, src, dist[src]);
    pq->n = size;
    while(!isEmpty(pq)){
        hn_t hn = getMin(pq);
        int u = hn->val;
        list_t pCrawl = malloc(sizeof *pCrawl);
        pCrawl = graph->al[u]->next;
        while(pCrawl != NULL){
            int v = pCrawl->node;
            if(pCrawl->w<0){
                fprintf(stderr,"INPUT_FORMAT_ERROR\n\n");
                exit(INPUT_FORMAT_ERROR);
            }
            if(isInPQ(pq,v) && dist[u] != DBL_MAX && pCrawl->w + dist[u] < dist[v]){
                dist[v] = dist[u] + pCrawl->w;
                decreseKey(pq, v, dist[v]);
                prew[v] = u;
            }
            pCrawl = pCrawl->next;
        }
    }
    if(tryb == 1){
        for(int j= 0; j<size; j++){
            if(j == src){
                    fprintf(stdout,"Węzeł: %d Węzeł źródłowy  Długość drogi: %lf\n",j, dist[j]);
                    continue;
                }
            printf("Węzeł: %d droga: ",j);
            int k = j;
            while(prew[prew[k]] != -1){
                
                printf("%d <- ", prew[k]);
                k = prew[k];
            }
            fprintf(stdout,"%d  Długość drogi: %lf\n",src, dist[j]);
        }
    }
    else if(tryb == 0){
        ;
    }
    else if(tryb == 2){
        for(int j = 0; j<size; j++){
            printf("Węzeł: %d, Długość drogi: %lf\n", j, dist[j]);
        }
    }
    if (!TEST)
        freeGraph(graph);
}

