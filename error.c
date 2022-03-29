#include <stdio.h>
#include <ctype.h>
#include "error.h"

int isNum(char *s) {
    int i = 0;
    while(s[i] != '\0') {
        if (!isdigit(s[i]))
            return 0;
        i++;
    }
    return 1;
}