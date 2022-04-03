#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "list.h"

int main(int argc, char **argv){  
    char *filename = "abc"; //mały zestaw testowych danyc hw pliku zapisanym zgodnie z formatem opisanyw w specyfikacji
    list_t *graph;
    int size;
    graph = read(filename, &size);
    printlist(graph[0]);
    printlist(graph[1]);
    printlist(graph[2]);
    printf("%d\n", size);
    return 0;
}