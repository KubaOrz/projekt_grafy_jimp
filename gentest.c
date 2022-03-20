#include <stdio.h>
#include <stdlib.h>

#include "gen.h"
#include "edge.h"
#include "files.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Niepoprawna ilość argumentów\n");
        return 1;
    }
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);

    edge_t *edges = malloc((arg1 * arg2 * 4) * sizeof * edges);
    int edgeCount = generate(edges, arg1, arg2, 0, 1);

    for (int i = 0; i < edgeCount; i++) {
        printf("%d --> %d: %lf\n", edges[i].snode, edges[i].fnode, edges[i].w);
    }
    return 0;
}
