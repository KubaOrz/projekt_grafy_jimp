#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "list.h"


list_t *read(char *filename, int *size){
    FILE *fp;
    int c, w;
    char *line = malloc(4);
    if ((fp=fopen(filename, "r"))==NULL) {
        fprintf(stdout,"FILE_ERROR\n");
        exit(1);
    }
    fgets(line, 4, fp);
    if(sscanf(line, "%d %d", &w,&c) != 2){
        fprintf(stdout,"IMPUT_FORMAT_ERROR\n");
        exit(1);
    }
    //sprawdzanie poprawności wejścia, ergo czy format danych w pliku jest zbazowany
    *size = c*w;
    list_t *nodes = malloc(c*w*sizeof(nodes));
    int ca;
    int node;
    double weight;
    for(int i = 0; i<c*w; i++){
        int a;
        a = fscanf(fp, "%d :%lf", &node, &weight);
        if(a == -1){
            break;
        }
        if(a !=2){
            fprintf(stdout,"FILE_INPUT_ERROR\n");
            exit(1);
        }
        list_t p = malloc(sizeof(p));
        push(p, node, weight);
        while(ca = fgetc(fp)){
            if (ca == 32){
                if(fscanf(fp, "%d :%lf", &node, &weight) != 2){
                    fprintf(stdout,"FILE_INPUT_ERROR\n");
                    exit(1);
                }
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
