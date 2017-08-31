// Queue.c ... list implementation of a queue

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

typedef struct QueueNode *Link;

struct QueueNode { 
   Item item; 
   Link next; 
};

struct QueueRep { 
   Link head; 
   Link tail;
   int  size; 
};

// private function for creating list nodes
static Link createNode(Item item)
{ 
   Link n = malloc(sizeof(struct QueueNode));
   assert(n != NULL);
   n->item = item; 
   n->next = NULL;    
   return n;                   
}

// create an initially empty Queue
Queue createQueue(void)
{
   Queue q = malloc(sizeof(struct QueueRep));
   assert(q != NULL); 
   q->head = NULL; 
   q->tail = NULL;
   q->size = 0; 
   return q;
}

// free all memory used by the Queue
void dropQueue(Queue q)
{
   Link curr;
   Link next;
   assert(q != NULL);
   curr = q->head;
   while (curr != NULL) {
      next = curr->next;
      curr = next;
   }
   free(q);
}


// add new Item to the tail of the Queue
void enterQueue (Queue q, Item it)
{ 
   assert(q != NULL);
   Link n = createNode(it);
   if (q->head == NULL) {
      q->head = n; 
   }
   q->tail = n;
}

// remove Item from head of Queue; return it
Item leaveQueue (Queue q)
{
   assert(q != NULL);
   Item it = q->head->item;
   Link delNode = q->head; 
   q->head = q->head->next;
   free(delNode);
   q->size--;  
   return it;
}

// return count of Items in Queue
int queueLength(Queue q)
{ 
   assert(q != NULL);
   return q->size; 
}

// display Queue as list of 2-digit numbers
void showQueue(Queue q)
{
   printf("H");
   Link curr;
   curr = q->head;
   while (curr != NULL) {
      printf(" %02d", curr->item);
   }
   printf(" T\n");
}
