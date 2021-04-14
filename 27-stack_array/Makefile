CFLAGS=-std=c99 -Wall
CC=gcc

expression: stack.o main.o
	$(CC) $(CFLAGS) stack.o main.o -o expression

test: stack.o test.o
	$(CC) $(CFLAGS) stack.o test.o -o test

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.h stack.c
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f expression test *.o
