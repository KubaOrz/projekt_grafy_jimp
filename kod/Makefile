CC=gcc

all: main.c files.c list.c bfs.c error.c fifo.c gen.c pq.c
	$(CC) -o graf main.c files.c list.c bfs.c error.c fifo.c gen.c pq.c

test: maintest.c files.c list.c bfs.c error.c fifo.c gen.c pq.c
	$(CC) -o test maintest.c files.c list.c bfs.c error.c fifo.c gen.c pq.c

debug: main.c files.c list.c bfs.c error.c fifo.c gen.c pq.c
	$(CC) -o debug main.c files.c list.c bfs.c error.c fifo.c gen.c pq.c -ggdb

readtest: mainreadtest.c files.c list.c
	$(CC) -o readtest mainreadtest.c files.c list.c
	
pqtest: pqmain.c pq.c bfs.c fifo.c list.c
	$(CC) -o pqtest pqmain.c pq.c bfs.c fifo.c list.c

bfs: main.c files.c list.c bfs.c error.c fifo.c gen.c
	$(CC) -o bfs main.c files.c list.c bfs.c error.c fifo.c gen.c

clean:
	rm graf debug test readtest pqtest bfs
