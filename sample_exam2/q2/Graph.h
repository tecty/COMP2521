/*  Graph ADT interface ... 
*/

#include <stdbool.h>

typedef struct GraphRep *Graph;
typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges
} GraphRep;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
   Vertex v;
   Vertex w;
} Edge;

Graph newGraph(int);

/* 
   Inserts a directed edge from 's' to 'd'
   void insertDirectedEdge(Graph g, Vertex s, Vertex d) 
*/
void insertDirectedEdge(Graph, Vertex, Vertex);


/* 
   Returns true if there is an edge from 's' to 'd', false otherwise
   bool  adjacent(Graph g, Vertex s, Vertex d);
*/
bool  adjacent(Graph, Vertex, Vertex);


void  showGraph(Graph);
void  freeGraph(Graph);
