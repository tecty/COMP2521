// DLList.h - Interface to doubly-linked list ADT
// Written by John Shepherd, March 2013
// Last modified, August 2014

#ifndef DLLIST_H
#define DLLIST_H

#include <stdio.h>
#include "DLList.h"

// External view of DLList
// Implementation given in DLList.c
// Implements a DLList of strings (i.e. items are strings)

typedef struct DLListRep *DLList;

// create a new empty DLList
DLList newDLList();

// free up all space associated with list
void freeDLList(DLList);

// create an DLList by reading items from a file
// assume that the file is open for reading
DLList getDLList(FILE *);

// display list to file, one item per line
// assumes that the file is open for writing
void putDLList(FILE *, DLList);

// check sanity of a DLList (for testing)
int validDLList(DLList);

// return item at current position
char *DLListCurrent(DLList);

// move current position (+ve forward, -ve backward)
// return 1 if reach end of list during move
int DLListMove(DLList, int);

// move to specified position in list
// i'th node, assuming first node has i==1
int DLListMoveTo(DLList, int);

// insert an item before current item
// new item becomes current item
void DLListBefore(DLList, char *);

// insert an item after current item
// new item becomes current item
void DLListAfter(DLList, char *);

// delete current item
// new item becomes item following current
// if current was last, current becomes new last
// if current was only item, current becomes null
void DLListDelete(DLList);

// return number of elements in a list
int DLListLength(DLList);

// is the list empty?
int DLListIsEmpty(DLList);

#endif
