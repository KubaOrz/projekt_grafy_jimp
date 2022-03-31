#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "list.h"
#include "error.h" // żeby się dało zwrócić odpowiedni kod błędu


list_t *read(char *filename, int *c, int *w){ // trzeba przekazać wskaźniki żeby bfs miał do tego jakiś dostęp
    FILE *fp;
    char *line = malloc(10); // zmieniłem tutaj 4 na 10 bo nie działało dla większych grafów
    if ((fp=fopen(filename, "r"))==NULL) {
        fprintf(stdout,"FILE_ERROR\n");
        exit(FILE_ERROR);
    }
    fgets(line, 10, fp);
    if(sscanf(line, "%d %d", w, c) != 2){
        fprintf(stdout,"INPUT_FORMAT_ERROR\n");
        exit(INPUT_FORMAT_ERROR);
    }
    list_t *nodes = malloc(*c**w*sizeof(nodes));
    int ca;
    int node;
    double weight;
    for(int i = 0; i<*c**w; i++){
        fscanf(fp, "%d :%lf", &node, &weight);
        list_t p = malloc(sizeof(p));
        push(p, node, weight);
        while(ca = fgetc(fp)){
            if (ca == 32){
                fscanf(fp, "%d :%lf", &node, &weight);
                push(p, node, weight);
            }
            if(ca == 10 || ca == EOF){
                break;
            }
        }
        nodes[i] = p;
    }
    return nodes;
}
