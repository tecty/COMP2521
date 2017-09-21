// crawl.c ... build a graph of part of the web
// Written by John Shepherd, September 2015
// Uses the cURL library and functions by Vincent Sanders <vince@kyllikki.org>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <curl/curl.h>
//#include "stack.h"
#include "queue.h"
#include "set.h"
#include "graph.h"
#include "html.h"
#include "url_file.h"

#define BUFSIZE 1024

// urls for visited pages
int  visited;
// count for the visited pages 
int page_count = 0;


void setFirstURL(char *, char *);
void normalise(char *, char *, char *, char *, int);
int isHtml(char *url);
int main(int argc, char **argv)
{
	URL_FILE *handle;
	char buffer[BUFSIZE];
	char baseURL[BUFSIZE];
	char firstURL[BUFSIZE];
	char *next;
	int  maxURLs;

	if (argc > 2) {
		strcpy(baseURL,argv[1]);
		setFirstURL(baseURL,firstURL);
		maxURLs = atoi(argv[2]);
		if (maxURLs < 40) maxURLs = 40;
	}
	else {
		fprintf(stderr, "Usage: %s BaseURL MaxURLs\n",argv[0]);
		exit(1);
	}
		
	// You need to modify the code below to implement:
	//
	// add firstURL to the ToDo list
	// initialise Graph to hold up to maxURLs
	// initialise set of Seen URLs
	// while (ToDo list not empty and Graph not filled) {
	//    grab Next URL from ToDo list
	//    if (not allowed) continue
	//    foreach line in the opened URL {
	//       foreach URL on that line {
	//          if (Graph not filled or both URLs in Graph)
	//             add an edge from Next to this URL
	//          if (this URL not Seen already) {
	//             add it to the Seen set
	//             add it to the ToDo list
	//          }
	//       }
    //    }
	//    close the opened URL
	//    sleep(1)
	// }
	
	// initial the graph
	Graph page_graph = newGraph(maxURLs);
	


	
	// initial the page queue to maintain
	Queue page_q = newQueue();
	// input the first page to queue to visit
	enterQueue(page_q, firstURL);
	// set the firstURL as a visited vertex
	addVertex(firstURL,page_graph->vertex, page_graph->nV);
	
	
	
	// loop till all the page have been touch
	while(!emptyQueue(page_q)&& page_graph->nV <= maxURLs){
	    // get the page should visit into next;
	    next = leaveQueue(page_q);
	    
	    
	
	    // try to open all the link in the queue
	    if (!(handle = url_fopen(next, "r"))) {
		    fprintf(stderr,"Couldn't open %s\n", next);
		    exit(1);
	    }
	    
	    printf("opening %s \n",next);
	    while(!url_feof(handle)) {
		    url_fgets(buffer,sizeof(buffer),handle);

            
		    int pos = 0;
		    char result[BUFSIZE];
		    memset(result,0,BUFSIZE);
           
   	    
		    while ((pos = GetNextURL(buffer, next, result, pos)) > 0) {
                
                if (!strstr(result,"unsw.edu.au")){
                    //this link doesn't belong to the unsw
                    continue;
                }
                
   
                // check whether the result page is visited
                // and check whether it is a html page
                if (vertexID(result,
                    page_graph->vertex,page_graph->nV )<0
                    && NormalizeURL(result)
                    ){
                    // this page is not visited 
                    // the the page to be scan 
                    enterQueue(page_q, result);
                    // print this addr out show that it's not visited 
                    printf("Found: '%s'\n",result);
                }
                    
                 
                
                // add the edge in to graph 
                addEdge(page_graph, next, result);
                
                
                

			    
			    memset(result,0,BUFSIZE);
		    }
	    }
        // ending part
	    url_fclose(handle);
        // free the space used in next string, to prevent memleak
        free(next);
	    
	    sleep(1);
	    
	    
	
	}
	
	
	showGraph(page_graph,2);
	return 0;
}

// check where a page is a html page
int isHtml(char *url){
    int len = strlen(url);
    if (url[len-5] == '.' &&
        url[len-4] == 'h' &&
        url[len-3] == 't' &&
        url[len-2] == 'm' &&
        url[len-1] == 'l' 
    )
    return 1;
    if (url[len-4] == '.' &&
        url[len-3] == 'h' &&
        url[len-2] == 't' &&
        url[len-1] == 'm' 
    )
    return 1;
    // else:
    return 0;

}

// setFirstURL(Base,First)
// - sets a "normalised" version of Base as First
// - modifies Base to a "normalised" version of itself
void setFirstURL(char *base, char *first)
{
	char *c;
	if ((c = strstr(base, "/index.html")) != NULL) {
		strcpy(first,base);
		*c = '\0';
	}
	else if (base[strlen(base)-1] == '/') {
		strcpy(first,base);
		strcat(first,"index.html");
		base[strlen(base)-1] = '\0';
	}
	else {
		strcpy(first,base);
		strcat(first,"/index.html");
	}
}


// vertexID(Str,Names,N)
// - searches for Str in array of Names[N]
// - returns index of Str if found, -1 if not
static int vertexID(char *str, char **names, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (strcmp(str,names[i]) ==0) return i;
	return -1;
}
