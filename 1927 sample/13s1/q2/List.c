// List.c ... implementation of simple List ADT

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "List.h"

typedef struct Node *Link;

typedef struct Node {
	int  value;
	Link next;
} Node;

typedef struct ListRep {
	int  nnodes;
	Link first;
	Link last;
} ListRep;

// newList ... make new empty List
List newList()
{
	List new = malloc(sizeof(ListRep));
	assert(new != NULL);
	new->nnodes = 0;
	new->first = NULL;
	new->last = NULL;
	return new;
}

// ListShow ... display List as <a, b, c, d, ...z>
void ListShow(List L)
{
	assert(L != NULL);
	printf("[");
	Link curr = L->first;
	while (curr != NULL) {
		printf("%d",curr->value);
		if (curr->next != NULL) printf(", ");
		curr = curr->next;
	}
	printf("]\n");
}

// ListLength ... number of nodes in List
int ListLength(List L)
{
	assert(L != NULL);
	return (L->nnodes);
}

// ListAppend ... append a new value to List
void ListAppend(List L, int value)
{
	assert(L != NULL);
	Link new = malloc(sizeof(Node));
	assert(new != NULL);
	new->value = value;
	new->next = NULL;
	L->nnodes++;
	if (L->first == NULL)
		L->first = L->last = new;
	else {
		L->last->next = new;
		L->last = new;
	}
}


// ListReverse ... reverse a List
void ListReverse(List L)
{
    if (L == NULL || L->first == L -> last) {
        /* the list is not exist or only have one or less node */
        return;
    }
    // for record the tmp pointer of nodes
    Link this_node, prev_node, tmp;
    prev_node = L->first; this_node = prev_node->next;
    prev_node ->next = NULL;
    while (this_node != NULL) {
        /* read throught the end of the link list */
        // the node's next will be delete
        tmp = this_node->next;
        // link back
        this_node->next = prev_node;
        prev_node = this_node;
        // restore the next node
        this_node = tmp;
    }

    // reverse the first and last
    this_node = L->first;
    L->first = L ->last;
    L->last  = this_node;

}
