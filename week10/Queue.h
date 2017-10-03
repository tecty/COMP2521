// Queue.h ... interface to Queue-of-BSTree-nodes ADT

#ifndef QUEUE_H
#define QUEUE_H

#include "BSTree.h"
typedef struct BSTNode *Item;
#define showItem showBSTreeNode

typedef struct QueueRep *Queue;

Queue newQueue(); // create new empty queue
void dropQueue(Queue); // free memory used by queue
void showQueue(Queue); // display as 3 > 5 > 4 > ...
void QueueJoin(Queue,Item); // add item on queue
Item QueueLeave(Queue); // remove item from queue
int QueueIsEmpty(Queue); // check for no items

#endif
