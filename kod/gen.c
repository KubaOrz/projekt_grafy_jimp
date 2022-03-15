// Napisałem tak jak zrozumiałem ale imo w takim przypadku ta siatka traci jakikolwiek sens
// Jeżeli każdy wierzchołek może mieć połączenie z każdym innnym to nie da się stworzyć takiej siatki
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Niepoprawna ilość argumentów");
        return 1;
    }
    int rows = atoi(argv[2]);
    int cols = atoi(argv[3]);
    FILE *out = fopen(argv[1], "w");
    srand(time(NULL));
    int edgeCount = cols * rows;
    int howMany;
    fprintf(out, "%d %d\n", rows, cols);
    for (int i = 0; i < edgeCount; i++ ) {
        fprintf(out, "\t");
        // Tu losuję ilość połączeń, jaka będzie wychodzić z danego wierzchołka
        howMany = rand() % 6;
        for (int j = 0; j < howMany; j++) {
            // Tu losuję numer wierzchołka, z którym ma istnieć połączenie i wagę tego połączenia
            fprintf(out, "%d :%lf\t", rand() % (edgeCount + 1), (double)rand() / RAND_MAX);
        }
        if (howMany == 0)
            fprintf(out, "NONE"); // Jeśli może nie być połączeń to trzeba to jakoś zaznaczyć
        fprintf(out, "\n");
    }
    return 0;
}