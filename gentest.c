#include <stdio.h>
#include <stdlib.h>

#include "gen.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Niepoprawna ilość argumentów\n");
        return 1;
    }
    FILE *out = fopen(argv[1], "w");
    int arg1 = atoi(argv[2]);
    int arg2 = atoi(argv[3]);

    generate(out, arg1, arg2, 0, 1);
    return 0;
}
