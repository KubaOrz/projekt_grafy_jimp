#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include "edge.h"

void save(edge_t *edges, char *filename, int c, int w); //czy to void? w sumie to co ma to przyjmować, tablice może ale nic nie zwraca to na pewno
edge_t read(char *filename);

#endif