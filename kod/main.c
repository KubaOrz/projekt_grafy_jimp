#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "files.h"
#include "gen.h"
#include "error.h"
#include "bfs.h"
#include "pq.h"

#define FILE_LEN 30

int main(int argc, char **argv){  
    if (argc == 3 || argc == 6 || argc == 7 || argc > 8) {
       fprintf(stderr, "ARG_ERROR\n");
       exit(ARG_ERROR);
    }
    
    const char *flags[4] = {"-d", "-g", "-w", "-h"};

    if (argc == 1 || (argc == 2 && strcmp(argv[1], flags[3]) == 0)) {
        printHelp();
        return 0;
    }

    char filename[FILE_LEN];
    strcpy(filename, argv[1]);

    if (argc == 2) {
        // Odpalamy read i BFS
        printf("Odpalam BFS\n");
        graph_t graph = read(filename);
        if (bfs(graph, 0))
            printf("Graf jest spójny\n");
        else
            printf("Graf nie jest spojny\n");
        return 0;
    }

    if (argc == 4) {
        if (strcmp(argv[2], flags[0]) == 0) {
            if (!isNum(argv[3])) {
                fprintf(stderr, "AGR_ERROR\n");
                return ARG_ERROR;
            }
            
            int snode = atoi(argv[3]);
            // Tu odpalimy read i dijkstrę
            printf("Odpalam dijkstrę\n");
            graph_t graph = read(filename);
            dijkstra(snode, graph);
            return 0;
        }

        fprintf(stderr, "UNKNOWN_FLAG\n");
        return UNKNOWN_FLAG;
    }

    if (argc == 5) {
        if (strcmp(argv[2], flags[1]) == 0) {
            if (!isNum(argv[3]) || !isNum(argv[4])) {
                fprintf(stderr, "ARG_ERROR\n");
                return ARG_ERROR;
            }
            
            int rows = atoi(argv[3]);
            int cols = atoi(argv[4]);
            // Tu odpalimy generację
            generate(filename, rows, cols, 0, 1, ALL);
            return 0;
        }

        fprintf(stderr, "UNKNOWN_FLAG\n");
        return UNKNOWN_FLAG;
    }

    if (argc == 8) {
        if (strcmp(argv[2], flags[1]) == 0 && strcmp(argv[5], flags[2]) == 0) {
            if (!isNum(argv[3]) || !isNum(argv[4]) || !isNum(argv[6]) || !isNum(argv[7])) {
                fprintf(stderr, "ARG_ERROR\n");
                return ARG_ERROR;
            }
            
            int rows = atoi(argv[3]);
            int cols = atoi(argv[4]);
            int w1 = atoi(argv[6]);
            int w2 = atoi(argv[7]);
            // Tu odpalimy generację ze zmienionymi wagami
            generate(filename, rows, cols, w1, w2, ALL);
            return 0;
        }

        fprintf(stderr, "UNKNOWN_FLAG\n");
        return UNKNOWN_FLAG;
    }
}
