/* hasPath Testing module ...
   Written by Ashesh Mahidadia
*/

#include "Graph.h"
#include <stdio.h>

#define NODES 20

int hasPath(Graph g, Vertex s, Vertex d);

int main(void) {
  Graph g = newGraph(NODES);
  Vertex from, to, s, d; 
  
  int count = fscanf(stdin, "from: %d , to: %d", &from, &to);
  if(count != 2){ 
    fprintf(stdout, "Error: incorrect input!!" );
    return 1; 
  }
  fprintf(stdout, "hasPath, From: %d , To: %d \n\n", from, to );
  while(fscanf(stdin, "%d %d", &s, &d) == 2){
    insertDirectedEdge(g, s, d);   
    fprintf(stdout, "Edge inserted:  %d -> %d \n", s, d);
  }
  fprintf(stdout, "\n");
    
  int ans = hasPath(g, from, to); 
  fprintf(stdout, "\nhasPath: %d \n\n", ans);
  
  freeGraph(g);
  
  return 0;
}
