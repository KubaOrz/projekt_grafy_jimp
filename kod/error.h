#ifndef ERROR_H
#define ERROR_H

enum error{
    UNKNOWN_FLAG = 1,
    ARG_ERROR,
    FILE_ERROR,
    INPUT_FORMAT_ERROR,
    FILE_NAME_REP
};

enum density {
    ALL = -1,
    HIGH,
    MEDIUM,
    LOW
};

int isNum(char *s);

void printHelp();

#endif