#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dijkstra.h"
#include "error.h"
#include "list.h"

pq_t init(int size){
    pq_t pq = malloc(sizeof *pq);
    pq->q = malloc(sizeof pq->q * size);
    pq->pos = malloc(sizeof pq->pos * size);
    pq->s = size;
    pq->n = 0;
    return pq;
}

void swap(hn_t *a, hn_t *b){
    hn_t tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

void heapify(pq_t pq, int i){
        int smallest = i;
    while(1){
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
            i = smallest;
        }
        else{
            return;
        }
    }
}


void add(pq_t pq, int val, double weigth){
    hn_t node = malloc(sizeof *node);
    node->val = val;
    node->weigth = weigth;
    if(pq->n == 0){
        pq->q[0] = node;
        pq->n += 1;
    }
    else{
        pq->q[pq->n] = node;
        pq->n += 1;
        heapify(pq,pq->n);
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
    hn_t root;
    hn_t last;
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

void freePQ(pq_t pq){
    /*
    for(int k = 0 ; k < pq->s ; k++){
        free(pq->q[k]);
    }*/
    
    free(pq->q);
    free(pq->pos);
    free(pq);
}


void dijkstra(int src, graph_t graph, int tryb){
    int size = graph->nc * graph->nr;
    double *dist = malloc(sizeof(*dist)*size);
    int *prew = malloc(sizeof(*prew)* size); //talbica poprzednik??wa
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
    list_t pCrawl;
    hn_t hn;
    int u; 
    while(!isEmpty(pq)){
        hn = getMin(pq);
        u = hn->val;
        pCrawl = graph->al[u];
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
    freePQ(pq);
    freeGraph(graph);
    if(tryb == 1){
        for(int j= 0; j<size; j++){
            if(j == src){
                    fprintf(stdout,"W??ze??: %d W??ze?? ??r??d??owy  D??ugo???? drogi: %lf\n",j, dist[j]);
                    continue;
            }
            printf("W??ze??: %d droga: ",j);
            int k = j;
            if(prew[k] == -1){
                    printf("Brak drogi do wiercho??ka\n");
                    continue;;
            }
            while(prew[prew[k]] != -1){
                printf("%d <- ", prew[k]);
                k = prew[k];
            }
            fprintf(stdout,"%d  D??ugo???? drogi: %lf\n",src, dist[j]);
        }
    }

    else if(tryb == 2){
        for(int j = 0; j<size; j++){
            if(j == src){
                    fprintf(stdout,"W??ze??: %d W??ze?? ??r??d??owy  D??ugo???? drogi: %lf\n",j, dist[j]);
                    continue;
            }
            if(prew[j] == -1){
                    printf("W??ze??: %d, Brak dorgi do wiercho??ka\n",j);
                    continue;;
            }
            printf("W??ze??: %d, D??ugo???? drogi: %lf\n", j, dist[j]);
        }
    }
    free(prew);
    free(dist);
    return;

        
}

