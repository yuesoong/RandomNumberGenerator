CC = gcc
CFLAGS = -Wall -pedantic -pthread -std=c99 -ggdb

all: mersenne

mersenne: mersenne.o
	$(CC) $(CFLAGS) -o mersenne mersenne.o

mersenne.o: mersenne.c
	$(CC) $(CFLAGS) -c mersenne.c

clean:
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f all
