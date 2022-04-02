CC=gcc

test: main.c files.c list.c bfs.c error.c fifo.c gen.c
	$(CC) -o test main.c files.c list.c bfs.c error.c fifo.c gen.c

debug: main.c files.c list.c bfs.c error.c fifo.c gen.c
	$(CC) -o debug main.c files.c list.c bfs.c error.c fifo.c gen.c -ggdb

readtest: mainreadtest.c files.c list.c
	$(CC) -o readtest mainreadtest.c files.c list.c
	
pqtest: pqmain.c pq.c bfs.c fifo.c list.c
	$(CC) -o pqtest pqmain.c pq.c bfs.c fifo.c list.c
