CFLAGS=-std=c99 -Wall

shapes: shapes.o cylinder.o circle.o
	gcc $(CFLAGS) shapes.o cylinder.o circle.o -o shapes

shapes.o: shapes.c cylinder.h circle.h
	gcc $(CFLAGS) -c shapes.c

cylinder.o: cylinder.c cylinder.h circle.h
	gcc $(CFLAGS) -c cylinder.c

circle.o: circle.c circle.h
	gcc $(CFLAGS) -c circle.c

clean:
	rm shapes.o cylinder.o circle.o shapes
