#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bfs.h"
#include "files.h"

int main(int argc, char ** argv) {

    //test BfS 1
    assert(bfs(read("dane/g1.txt"), 0) == 0);
    printf("Test BFS 1 OK\n\n");

    //test BFS 2
    assert(bfs(read("dane/g2.txt"), 0) == 0);
    printf("Test BFS 2 OK\n\n");

    //test BFS 3
    assert(bfs(read("dane/g3.txt"), 0));
    printf("Test BFS 3 OK\n\n");

    //test BFS 4
    assert(bfs(read("dane/g4.txt"), 0));
    printf("Test BFS 4 OK\n\n");

    //Trzeba dodać testy dijkstry
    return 0;
}
