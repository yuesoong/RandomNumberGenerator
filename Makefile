CC = gcc
CFLAGS = -Wall -pedantic -pthread -std=c99 -ggdb

all: mersenne kiss linear binary

mersenne: mersenne.o
	$(CC) $(CFLAGS) -o mersenne mersenne.o

mersenne.o: mersenne.c
	$(CC) $(CFLAGS) -c mersenne.c

kiss: kiss.o
	$(CC) $(CFLAGS) -o kiss kiss.o

kiss.o: kiss.c
	$(CC) $(CFLAGS) -c kiss.c

linear: linear.o
	$(CC) $(CFLAGS) -o linear linear.o

linear.o: linear.c
	$(CC) $(CFLAGS) -c linear.c

binary: binary.o
	$(CC) $(CFLAGS) -o binary binary.o

binary.o: binary.c
	$(CC) $(CFLAGS) -c binary.c

clean:
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f mersenne
	rm -f kiss
	rm -f linear
	rm -f binary
