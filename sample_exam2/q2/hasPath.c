
/* hasPath.c
   Written by Ashesh Mahidadia, October 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Graph.h"



/*
    You will submit only this one file.

    Implement the function "hasPath" below. Read the exam paper for
    detailed specification and description of your task.

    - You can add helper functions in this file, if required.

    - DO NOT modify code in the file BSTree.h .
    - DO NOT add "main" function in this file.
*/


int *visited;  // array of visited

//
// typedef struct node_t {
//     int val;
//     struct node_t *next;
// } *node;
//
// typedef struct queue_t {
//     node head;
//     node tail;
// } *queue;
//
// node init_node(int val){
//     node new = malloc(sizeof(struct node_t));
//     assert(new != NULL);
//
//     // initial the value in the node
//     new->val = val;
//     new->next = NULL;
// }
//
// queue init_queue(){
//     queue new = malloc(sizeof(struct queue_t));
//
//     // initial the value in the queue
//     new ->head = new->tail = NULL;
//     return new;
// }
//
//
// int leave_q(queue q){
//     // pop the node in the queue
//     if (q->head == NULL) {
//         /* the queue is empty */
//         return -1;
//     }
//     // else
//     int this = q->head->val;
//     queue delete = q->head;
//     // rearrange the queue's link
//     q->head = q->head-> next;
//     if (q->head == NULL) {
//         /* the last node is leaved the queue, the queue is empty now */
//         q->head = NULL;
//     }
//
//     // free the memory usage
//     free(delete);
//     // return the Vertex in the node
//     return this;
// }
//
// void join_q(queue q,int val){
//     // create a node to link
//     node this = init_node(val);
//     if (q->head == NULL) {
//         /* the queue is empty */
//         q->head = q->tail = this;
//     }
//     else{
//         // add one more at the end of the queues
//         q->tail->next = this;
//         // refresh the queue
//         q->tail = this;
//     }
// }

//
//
// int hasPath(Graph g, Vertex src, Vertex dest)
// {
//
// 	// Implement this function,
// 	// also change the return value below!
//
//     // special situation
//     if (dest == src) {
//         /* the node can reach itself ? */
//         return 1;
//     }
//     if (g == NULL) {
//         /* not provided Graph */
//         return 0;
//     }
//
//
//     // initial the array of visited
//     visited = malloc(g->nV* sizeof(int));
//     for (int i = 0; i < g->nV; i++) {
//         /* initial the array with 0 */
//         visited[i] = 0;
//     }
//
//     // search for the Graph by bfs
//     // initial the queue to store the vertices
//     queue q = init_queue();
//
//     // join the first node to search
//     join_q(q , src);
//
//     // current search v
//     int v;
//
//     while ((v = leave_q(q))>=0) {
//         /* search for all the vertices could reach by src */
//         for (int to = 0; to < g->nV; to++) {
//             /* All possible edges from v to to */
//             if (adjacent(g, v, to)) {
//                 /* here is an edge between v and to */
//                 if (to == dest) {
//                     /* the node(to) is the required node */
//                     // successful found
//                     return 1;
//                 }
//
//                 if(visited[to]){
//                     // this node is visited, not going to visit it again
//                     // skip all the action to this node(to)
//                     continue;
//                 }
//                 // else
//                 // set this node to visited, because it would be search
//                 visited[to] = 1;
//                 // join the queue, to search after
//                 join_q(q, to);
//             }
//         }
//     }
//    return 0;
// }


int doHasPath(Graph g, Vertex src, Vertex dest ) {
    /* code */
    for (int v = 0; v < g->nV; v++) {
        /* code */
        if (adjacent(g,src,v)) {
            /* src and v is neighbour */
            if (visited[v]) {
                /* code */
                continue;
            }
            visited[v] = 1;
        if (v == dest) {
            /* destination is found */
            return 1;
        }
            if(doHasPath(g, v, dest)){
                // the child is found the node
                return 1;
            }
            // else continue searing;
        }
    }
    // not found any node by searching 
    return 0;
}


int hasPath(Graph g, Vertex src, Vertex dest)
{
    // malloc of visited
    visited = malloc(g->nV * sizeof(int));
    for (size_t n = 0; n < g->nV; n++) {
        /* initial the array */
        visited[n] = 0;
    }

    // recursive to find the path
    return doHasPath(g, src, dest);
}
