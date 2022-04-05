#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "list.h"

int main(int argc, char **argv){  
    char *filename = "graf.txt"; //mały zestaw testowych danyc hw pliku zapisanym zgodnie z formatem opisanyw w specyfikacji
    graph_t graph;
    graph = read(filename);
    printlist(graph->al[0]);
    printlist(graph->al[1]);
    printlist(graph->al[2]);
    printf("%d\n", graph->nc * graph->nr );
    return 0;
}