// Tutaj możliwe są tylko krawędzie między sąsiadami w macierzy, a szansa na wygenerowanie połączenia to 50%
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vEdge {
    double value;
    int exists;
} vEdge;

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Niepoprawna ilość argumentów");
        return 1;
    }
    int rows = atoi(argv[2]);
    int cols = atoi(argv[3]);
    FILE *out = fopen(argv[1], "w");

    srand(time(NULL));

    int edgeCount = 0;
    vEdge *topEdges = malloc(cols * sizeof * topEdges);
    vEdge leftEdge = {0, 0};

    fprintf(out, "%d %d\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(out, "\t");
            
            if (i != 0 && topEdges[j].exists) 
                fprintf(out, "%d: %lf  ", edgeCount - cols, topEdges[j].value);
            if (j != 0 && leftEdge.exists) {
                fprintf(out, "%d: %lf  ", edgeCount - 1, leftEdge.value);
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

            if (j != cols - 1 && leftEdge.exists)
                fprintf(out, "%d: %lf  ", edgeCount + 1, leftEdge.value);
            if (i != rows - 1 && topEdges[j].exists)
                fprintf(out, "%d: %lf  ", edgeCount + cols, topEdges[j].value);

            edgeCount++;
            fprintf(out, "\n");
        }
    }
    return 0;
}