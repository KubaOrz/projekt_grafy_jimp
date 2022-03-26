#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "files.h"
#include "gen.h"
#include "error.h"

void generate (char *filename, int rows, int cols, double from, double to) {
    srand(time(NULL));

    FILE *out;
    if ((out = fopen(filename, "w")) == NULL) {
        printf ("FILE_ERROR\n");
        exit(FILE_ERROR);
    }

    int edgeCount = 0, observed = 0;
    ifEdge_t *topEdges = malloc(cols * sizeof * topEdges);
    ifEdge_t leftEdge = {0, 0};

    fprintf(out, "%d %d\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            observed = cols * i + j;
            fprintf(out, "\t");
            if (i != 0 && topEdges[j].exists) {
                fprintf(out, "%d: %lf ", observed - cols, topEdges[j].value);
                edgeCount++;
            }
            if (j != 0 && leftEdge.exists) {
                fprintf(out, "%d: %lf ", observed - 1, leftEdge.value);
                edgeCount++;
            }

            if (rand() % 2 == 1) {
                leftEdge.exists = 1;
                leftEdge.value = from + (double)rand() / RAND_MAX * (to - from);
            }
            else
                leftEdge.exists = 0;

            if (rand() % 2 == 1) {
                topEdges[j].exists = 1;
                topEdges[j].value = from + (double)rand() / RAND_MAX * (to - from);
            }
            else
                topEdges[j].exists = 0;

            if (j != cols - 1 && leftEdge.exists) {
                fprintf(out, "%d: %lf ", observed + 1, leftEdge.value);
                edgeCount++;
            }
            if (i != rows - 1 && topEdges[j].exists) {
                fprintf(out, "%d: %lf ", observed + cols, topEdges[j].value);
                edgeCount++;
            }
            fprintf(out, "\n");
        }
    }
}