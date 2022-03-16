#include <stdio.h>
#include <stdlib.h>
#include "files.h"

void save(edge_t **edges, char *filename, int c, int w){
    FILE *fp;
    if ((fp=fopen(filename, "w"))==NULL) {
        printf ("Nie mogę otworzyć pliku test.txt do zapisu!\n");
        exit(1);
    }
    fprintf(fp,"%d %d", c, w );
    for(int i = 0; i < c*w; i++){
        if(edges[i]->snode == i){
            int n = get_size(edges[i]);
            for(int j= 0; j < n; j++){
                fprintf(fp,"%d : %f ", edges[j]->fnode, edges[j]-> w);
            }
            fprintf(fp,'/n');
        }
    }
}