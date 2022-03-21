#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "edge.h"
#include "files.h"
#include "gen.h"

int generate (edge_t *edges, int rows, int cols, double from, double to) {
    srand(time(NULL));

    int edgeCount = 0, observed = 0;
    ifEdge_t *topEdges = malloc(cols * sizeof * topEdges);
    ifEdge_t leftEdge = {0, 0};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            observed = cols * i + j;
            
            if (i != 0 && topEdges[j].exists) {
                edges[edgeCount].snode = observed;
                edges[edgeCount].fnode = observed - cols;
                edges[edgeCount].w = topEdges[j].value;
                //printf("%d --> %d: %lf\n", edges[edgeCount].snode, edges[edgeCount].fnode, edges[edgeCount].w);
                edgeCount++;
            }
            if (j != 0 && leftEdge.exists) {
                edges[edgeCount].snode = observed;
                edges[edgeCount].fnode = observed - 1;
                edges[edgeCount].w = leftEdge.value;
                //printf("%d --> %d: %lf\n", edges[edgeCount].snode, edges[edgeCount].fnode, edges[edgeCount].w);
                edgeCount++;
            }

            if (rand() % 2 == 1) {
                leftEdge.exists = 1;
                leftEdge.value = (double)rand() / RAND_MAX;
            }
            else
                leftEdge.exists = 0;

            if (rand() % 2 == 1) {
                topEdges[j].exists = 1;
                topEdges[j].value = (double)rand() / RAND_MAX;
            }
            else
                topEdges[j].exists = 0;

            if (j != cols - 1 && leftEdge.exists) {
                edges[edgeCount].snode = observed;
                edges[edgeCount].fnode = observed + 1;
                edges[edgeCount].w = leftEdge.value;
                //printf("%d --> %d: %lf\n", edges[edgeCount].snode, edges[edgeCount].fnode, edges[edgeCount].w);
                edgeCount++;
            }
            if (i != rows - 1 && topEdges[j].exists) {
                edges[edgeCount].snode = observed;
                edges[edgeCount].fnode = observed + cols;
                edges[edgeCount].w = topEdges[j].value;
                //printf("%d --> %d: %lf\n", edges[edgeCount].snode, edges[edgeCount].fnode, edges[edgeCount].w);
                edgeCount++;
            }
        }
    }
    return edgeCount;
}