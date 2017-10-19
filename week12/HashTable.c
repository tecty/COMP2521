// HashTable.c ... implementation of HashTable ADT
// Written by John Shepherd, May 2013


#include "HashTable.h"


// convert key into index (from Sedgewick)
unsigned int hash(Key k, int tableSize)
{
    unsigned int h = 0;
	unsigned int h2 = 0;
	// int a = 31415, b = 27183;
	// for (; *k != '\0'; k++) {
	// 	a = a*b % (tableSize-1);
	// 	h = (a*h + *k) % tableSize;
	// }
	// return (h % tableSize);
    for (; *k != '\0'; k++) {
        h = h*29 +( *k-'a');
        h2 = (h2<<3) +( *k-'a');

    }
    return (h2+h) % tableSize;
}


// Interface functions for HashTable ADT

// create an empty HashTable
HashTable newHashTable(int N)
{
	HashTabRep *new = malloc(sizeof(HashTabRep));
	assert(new != NULL);
	new->lists = malloc(N*sizeof(List));
	assert(new->lists != NULL);
	int i;
	for (i = 0; i < N; i++)
		new->lists[i] = newList();
	new->nslots = N; new->nitems = 0;
	return new;
}

// free memory associated with HashTable
void dropHashTable(HashTable ht)
{
	assert(ht != NULL);
	int i;
    for (i = 0; i < ht->nslots; i++)
		dropList(ht->lists[i]);
	free(ht);
}

// display HashTable stats
void HashTableStats(HashTable ht)
{
	assert(ht != NULL);
	printf("Hash Table Stats:\n");
	printf("Number of slots = %d\n",ht->nslots);
	printf("Number of items = %d\n",ht->nitems);
	printf("Chain length distribution\n");
	printf("%8s %8s\n","Length","#Chains");
    // a very long table to count the length distribution
    int len_count[100]= {0};
    // record the maxlenth of list in the slot
    int max_len = 0;

    for (int i = 0; i < ht->nslots; i++) {
        /* for every slot in the table */
        int this_len = ListLength(ht->lists[i]);
        len_count[this_len] ++;
        if (this_len > max_len) {
            /* refresh the maxlenth */
            max_len = this_len;
        }
    }

    // base on the maxlenth to print the statistic
    for (int i = 0; i < max_len+1; i++) {
        /* for every valid record in the len_count */
        if (len_count[i] != 0) {
            /* check whether this slot have things to print */
            printf("%8d %8d\n",i,len_count[i]);
        }
    }


}

// insert a new value into a HashTable
void HashTableInsert(HashTable ht, Item it)
{
	assert(ht != NULL);
	int i = hash(key(it), ht->nslots);
	if (ListSearch(ht->lists[i], key(it)) == NULL) {
		ListInsert(ht->lists[i], it);
		ht->nitems++;
	}
}

// delete a value from a HashTable
void HashTableDelete(HashTable ht, Key k)
{
	assert(ht != NULL);
	int h = hash(k, ht->nslots);
	ListDelete(ht->lists[h], k);
}

// get Item from HashTable using Key
Item *HashTableSearch(HashTable ht, Key k)
{
	assert(ht != NULL);
	int i = hash(k, ht->nslots);
	return ListSearch(ht->lists[i], k);
}
