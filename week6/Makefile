# COMP1927 Week 04 Lab

CC=gcc
CFLAGS=-Wall -Werror -gdwarf-2
LDFLAGS=

all: sorter testQ

sorter : sorter.c

testQ : testQ.o Queue.o

Queue.o : Queue.c Queue.h

clean:
	rm -f testQ sorter *.o
