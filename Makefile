CC=gcc

readtest: mainreadtest.c files.c list.c
	$(CC) -o readtest mainreadtest.c files.c list.c
pqtest: pqmain.c pq.c
	$(CC) -o pqtest pqmain.c pq.c