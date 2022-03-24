CC=gcc

readtest: mainreadtest.c files.c list.c
	$(CC) -o readtest mainreadtest.c files.c list.c
