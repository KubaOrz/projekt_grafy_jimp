all: main.c files.c list.c bfs.c error.c gen.c dijkstra.c
	$(CC) -o graf main.c files.c list.c bfs.c error.c gen.c dijkstra.c

test: maintest.c files.c list.c bfs.c error.c gen.c dijkstra.c
	$(CC) -o test maintest.c files.c list.c bfs.c error.c gen.c dijkstra.c -DTEST=1

debug: main.c files.c list.c bfs.c error.c gen.c dijkstra.c
	$(CC) -o debug main.c files.c list.c bfs.c error.c gen.c dijkstra.c -ggdb

clean:
	rm graf debug test readtest pqtest bfs
