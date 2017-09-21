// Graph.c ... implementation of Graph ADT
// Written by John Shepherd, May 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Graph.h"
#include "Queue.h"

// graph representation (adjacency matrix)
typedef struct GraphRep {
	int    nV;    // #vertices
	int    nE;    // #edges
	int  **edges; // matrix of weights (0 == no edge)
} GraphRep;

// check validity of Vertex
int validV(Graph g, Vertex v)
{
	return (g != NULL && v >= 0 && v < g->nV);
}

// make an edge
Edge mkEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	Edge new = {v,w}; // struct assignment
	return new;
}

// insert an Edge
// - sets (v,w) and (w,v)
void insertEdge(Graph g, Vertex v, Vertex w, int wt)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	if (g->edges[v][w] == 0) {
		g->edges[v][w] = wt;
		g->edges[w][v] = wt;
		g->nE++;
	}
}

// remove an Edge
// - unsets (v,w) and (w,v)
void removeEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	if (g->edges[v][w] != 0) {
		g->edges[v][w] = 0;
		g->edges[w][v] = 0;
		g->nE--;
	}
}

// create an empty graph
Graph newGraph(int nV)
{
	assert(nV > 0);
	int v, w;
	Graph new = malloc(sizeof(GraphRep));
	assert(new != 0);
	new->nV = nV; new->nE = 0;
	new->edges = malloc(nV*sizeof(int *));
	assert(new->edges != 0);
	for (v = 0; v < nV; v++) {
		new->edges[v] = malloc(nV*sizeof(int));
		assert(new->edges[v] != 0);
		for (w = 0; w < nV; w++)
			new->edges[v][w] = 0;
	}
	return new;
}

// free memory associated with graph
void dropGraph(Graph g)
{
	assert(g != NULL);
	// not needed for this lab
}

// display graph, using names for vertices
void showGraph(Graph g, char **names)
{
	assert(g != NULL);
	printf("#vertices=%d, #edges=%d\n\n",g->nV,g->nE);
	int v, w;
	for (v = 0; v < g->nV; v++) {
		printf("%d %s\n",v,names[v]);
		for (w = 0; w < g->nV; w++) {
			if (g->edges[v][w]) {
				printf("\t%s (%d)\n",names[w],g->edges[v][w]);
			}
		}
		printf("\n");
	}
}

// clear all the information in the Queue
void cleanQueue(Queue q){
    while (!QueueIsEmpty(q)) {
        /* leave all the information in the queue */
        QueueLeave(q);
    }
}


// handy function to manipulate the route
Queue dupQueue(Queue dest, Queue src){
    // duplicate the content in the src to dest


}

// a method to store the path, by using the bfs, the max path would be sorte
// is 30, prevent some overhead, seted 35
// using the queue structure to record the path
Queue route[35];
// index currently occupied route
int route_occupy[35]={0};

int findEmptyRoute(){
    int i =0;
    for (i = 0; i < 35; i++) {
        /* serch in route_occupy array */
        if (route_occupy[i]==0) {
            /* this route is empty */
            return i;
        }
    }
    // couldn't found a empty route
    // kill the programme
    fprintf(stderr, "coudln't find a empty route to store\n" );
    for ( i = 0; i < 35; i++) {
        /* print all the current path state */
        showQueue(route[i]);
    }
    // end the programme
    exit(1);
}


// find a path between two vertices using breadth-first traversal
// only allow edges whose weight is less than "max"
int findPath(Graph g, Vertex src, Vertex dest, int max, int *path)
{
    // have to have these variables
    assert(g != NULL);
    // record the path for visited palces
    int visited[30];

    // create a queue to do BFS
    Queue route_q = newQueue();





    // handy vars for loop
    int i, j ,k;
    // initial all the path
    for (i = 0; i <30; i++){
        route[i] = newQueue();
    }


    // i don't want to confuse my self by Vertex and Item
    int this_place;

    // try to find a path by BFS
    while(QueueIsEmpty(route_q)){
        path_id = QueueLeave(route_q);

        route[path_id]



    }

    // free the memory of Queue
    dropQueue(place_q);
    // couldn't find a path
	return 0; // never find a path ... you need to fix this
}
