#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "edge.h"

void save(edge_t **edges, char *filename, int c, int w){
    FILE *fp;
    if ((fp=fopen(filename, "w"))==NULL) {
        printf ("Nie mogę otworzyć pliku do zapisu!\n");
        exit(1);
    }
    fprintf(fp,"%d %d\n", c, w );
    edge_t *pom;
    pom = edges[0];
    printf("%d\n", &pom);
    for(int i = 0; i < c*w; i++){
        printf("%d\n", &pom);
        while(i == pom->snode){
            fprintf(fp, "%d : %f ", pom->fnode, pom->w);
            pom++;
        }
        fprintf(fp,"\n");
        pom++;
    }// z jakiegoś powodu nie działa przesuwanie wskaźnika
 }

