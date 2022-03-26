#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "files.h"
#include "gen.h"
#include "error.h"

#define FILE_LEN 30

int main(int argc, char **argv){  
    if (argc == 1 || argc == 3 || argc == 6 || argc == 7 || argc > 8) {
       fprintf(stderr, "ARG_ERROR\n");
       exit(ARG_ERROR);
    }
    char filename[FILE_LEN];
    strcpy(filename, argv[1]);
    const char *flags[3] = {"-d", "-g", "-w"};

    if (argc == 2) {
        // Odpalamy read i BFS
        printf("Odpalam BFS\n");
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
            generate(filename, rows, cols, 0, 1);
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
            generate(filename, rows, cols, w1, w2);
            return 0;
        }

        fprintf(stderr, "UNKNOWN_FLAG\n");
        return UNKNOWN_FLAG;
    }
}