#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "list.h"
#include "error.h"


graph_t read(char *filename){
    FILE *fp;
    int c, w;
    if ((fp=fopen(filename, "r"))==NULL) {
        fprintf(stdout,"FILE_ERROR\n");
        exit(FILE_ERROR);
    }
    if(fscanf(fp, "%d %d", &w,&c) != 2){
        fprintf(stdout,"IPUT_FORMAT_ERROR\n");
        exit(INPUT_FORMAT_ERROR);
    }
    //sprawdzanie poprawności wejścia, ergo czy format danych w pliku jest zbazowany
	graph_t g = malloc( sizeof *g );
	g->nc = c;
	g->nr = w;
	g->al = malloc( w*c * sizeof *(g->al) );
    int node;
    double weight;
	char buff[8192];
    fgets( buff, 8192, fp );
    for(int i = 0; i < c*w ; i++){
				fgets( buff, 8192, fp );
				int buffPtr = 0;
                int tmp = 0;
                list_t p;
                if(sscanf( buff+buffPtr, "%d :%lf%n", &node, &weight, &tmp )==2){
                    p = initlist(node,weight);
                    buffPtr += tmp;
                }
                
				while( sscanf( buff+buffPtr, "%d :%lf%n", &node, &weight, &tmp ) == 2 ) {
                    //printf("%d :%lf\n", node, weight);
					push(p,node,weight);  // push( g->al[i], node weight );
					buffPtr += tmp;
				}
                //printf("\n");
                g->al[i] = p;
		}
    return g;
}
