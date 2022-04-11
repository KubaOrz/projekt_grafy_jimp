#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "bfs.h"
#include "files.h"
#include "dijkstra.h"

void testDijsktra(char *path){
    clock_t p = clock();
    graph_t graph = read(path);
    int size = graph->nc*graph->nr;
    clock_t start = clock();
    dijkstra(1, graph, 0);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Plik o rozmiarze: %d, został wczytany w czasie: %lf\n",size, (double)(start-p)/CLOCKS_PER_SEC);
    printf("Czas działania algorytmu Disjkstry: %lf, dla: %d węzłów\n\n", time, size);
}


int main(int argc, char ** argv) {
    /*
    //test BfS 1
    assert(bfs(read("../testy/g1.txt"), 0) == 0);
    printf("Test BFS 1 OK\n\n");

    //test BFS 2
    assert(bfs(read("../testy/g2.txt"), 0) == 0);
    printf("Test BFS 2 OK\n\n");

    //test BFS 3
    assert(bfs(read("../testy/g3.txt"), 0));
    printf("Test BFS 3 OK\n\n");

    //test BFS 4
    assert(bfs(read("../testy/g4.txt"), 0));
    printf("Test BFS 4 OK\n\n");
    */
    //test czasu Dijkstry 1
    testDijsktra("../testy/100w");

    //test czasu Dijkstry 2
    testDijsktra("../testy/10000w");

    //test czasu Dijkstry 3
    testDijsktra("../testy/10000w2");
    
    //test czasu Dijkstry 4
    testDijsktra("../testy/100000w");

    //test czasu Dijkstry 5
    testDijsktra("../testy/10000w3");
    
    
    return 0;
}
