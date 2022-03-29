#ifndef ERROR_H
#define ERROR_H

enum error{
    UNKNOWN_FLAG = 1,
    ARG_ERROR,
    FILE_ERROR,
    INPUT_FORMAT_ERROR,
    FILE_NAME_REP
};

int isNum(char *s);

#endif