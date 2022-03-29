#ifndef FIFO_H
#define FIFO_H

typedef struct queue {
    int node;
    struct queue *next;
} *queue_t;

void pushQ(queue_t head, int node);

int first(queue_t head);

queue_t pop(queue_t head);

void printQueue(queue_t head);

#endif