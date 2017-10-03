CC=gcc
CFLAGS=-Wall -Werror -g
OBJS=bst.o BSTree.o Queue.o
BINS=bst mkrand mkpref

all : $(BINS)

bst : $(OBJS)
	$(CC) -o bst $(OBJS)

bst.o : bst.c BSTree.h
BSTree.o : BSTree.c BSTree.h Queue.h
Queue.o : Queue.c Queue.h

tests : bst
	cd tests ; make

clean :
	rm -fr $(BINS) $(OBJS) core *.dSYM tests/*.observed
