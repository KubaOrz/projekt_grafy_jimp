#include <stdio.h>
#include <ctype.h>
#include "error.h"

int isNum(char *s) {
    int i = s[0] == '-' ? 1 : 0;
    while(s[i] != '\0') {
        if (!isdigit(s[i]))
            return 0;
        i++;
    }
    return 1;
}

void printHelp() {
    printf("Wywołanie: ./graf ścieżka do pliku [flagi i argumenty opcjonalne]\n\n");
    printf("Spis flag i argumentów:\n");
    printf("\t%-44s\t%s\n", "-g [ilość wierszy] [ilość kolumn]", "Wygeneruj graf o podanych wymiarach i wagach z przediału (0, 1)");
    printf("\t%-44s\t%s\n", "-g [ilość wierszy] [ilość kolumn] -w [a] [b]", "Wygeneruj graf o podanych wymiarach i wagach z przediału (a, b)");
    printf("\t%-44s\t%s\n", "-d [numer wierzchołka]", "Przeszukaj graf za pomocą algorytmu dijkstry rozpoczynajc od podanego wierzchołka");
    printf("\t%-44s\t%s\n", "-d [numer wierzchołka] -p", "Jak wyżej, wyświetla dodatkowo przebiego ścieżek");
    printf("\t%-44s\t%s\n", "-h", "Wyświetl pomoc");
    printf("\nBez dodatkowych flag i argumentów zostanie sprawdzona spójność grafu\n");
}