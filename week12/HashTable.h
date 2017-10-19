// HashTable.h ... interface to HashTable ADT
// Written by John Shepherd, March 2013

#ifndef HASHTAB_H
#define HASHTAB_H
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Item.h"
#include "List.h"

// Types and functions local to HashTable ADT

typedef struct HashTabRep {
	List *lists;  // either use this
	int   nslots; // # elements in array
	int   nitems; // # items stored in HashTable
} HashTabRep;

typedef struct HashTabRep *HashTable;

// create an empty HashTable
HashTable newHashTable(int);
// free memory associated with HashTable
void dropHashTable(HashTable);
// display HashTable stats
void HashTableStats(HashTable);

// insert a new value into a HashTable
void HashTableInsert(HashTable, Item);
// delete a value from a HashTable
void HashTableDelete(HashTable, Key);
// get Item from HashTable using Key
Item *HashTableSearch(HashTable, Key);

#endif
