CFLAGS=-std=c99 -Wall
CC=gcc

sorting: sorts.o main.o
	$(CC) $(CFLAGS) sorts.o main.o -o sorting

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

stack.o: sorts.h sorts.c
	$(CC) $(CFLAGS) -c sorts.c

clean:
	rm -f sorting *.o
