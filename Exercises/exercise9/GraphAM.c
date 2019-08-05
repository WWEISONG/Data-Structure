#include <stdio.h>
#include <stdlib.h>
#include "GraphAM.h"

// how to define the vertex?
// how to define the edges?
// how to define the graph?

struct grapham
{
	int numberVertex;                 // number of vertex
	int numberEdge;                   // number of edges
	int **edges;              	  // this is the adjacent matrix     
};

// first part: implement operations of graph
GraphAM newGraph(int numVerticess)
{
	GraphAM g = NULL;
	int numVertices = numVerticess;
	if (numVertices < 0){
		fprintf(stderr, "newGraph: invalid number of vertices\n");
	}else{
		g = malloc(sizeof(struct grapham));// malloc memory for the graph
		if (g == NULL){		// malloc failure
			fprintf(stderr, "newGraph: no memory\n");
			exit(EXIT_FAILURE);
		}
		// malloc memory for edges: including several pointers(point int)
		g->edges = malloc(sizeof(int *) * numVertices);
		if (g->edges == NULL){
			fprintf(stderr, "newGraph: no memory\n");
			exit(EXIT_FAILURE);
		}

		for(int v = 0; v < numVertices; v++)
		{							// malloc memory for every line(every vertex)
			g->edges[v] = malloc(sizeof(int) * numVertices);
			if (g->edges[v] == NULL){
				fprintf(stderr, "newGraph: no memory\n");
				exit(EXIT_FAILURE);
			}
			for (int otherV = 0; otherV < numVertices; otherV++)
			{						// initialize linked state with other vertices
				g->edges[v][otherV] = 0;
			}
		}
		g->numberEdge = 0;
		g->numberVertex = numVertices; 
	}
	return g;
}

void showGraph(GraphAM graph)
{
	if (graph == NULL){
		printf("NULL graph\n");
	}else{
		printf("Ordered Word Ladder Graph\n");
		printf("V=%d, E=%d\n", graph->numberVertex, graph->numberEdge);
		for (int v = 0; v < graph->numberVertex; v++)// visit all current vertex
		{
			int nshown = 0;							// other vertex
			for (int otherV = 0; otherV < graph->numberVertex; otherV++)
			{
				if (graph->edges[v][otherV]){		// if they have edge
					printf("<%d %d> ", v, otherV);
					nshown++;
				}
			}
			if (nshown > 0){// separate by line
				putchar('\n');
			}
		}
	}
	return;
}

GraphAM freeGraph(GraphAM g)
{
	if (g == NULL){
		fprintf(stderr, "freeGraph:NULL graph\n");
	}else{												
		for (int v = 0; v < g->numberVertex; v++)
		{
			free(g->edges[v]);	// free the mallocs for each row...
			g->edges[v] = NULL;
		}	
		free(g->edges);			// now the malloc for the edges array
		free(g);				// now the malloc for the graph
		g->edges = NULL;
	}

	return g;
}

// second part: implement operations of edges and vertex
Edge newEdge(Vertex v, Vertex w)
{
	Edge e = {v, w};	// create an edge from v to w
	return e;
}

void insertEdge(GraphAM g, Edge e)
{
	if (g == NULL){
		printf("NULL graph\n");
	}else{
		if(!validV(g, e.v) || !validV(g, e.w)){
			fprintf(stderr, "insertEdge: invalid vertices\n");
		}else{
			if (isEdge(g, e) == 0){ // if this edge is a new edge
				g->numberEdge++;// we increment the number of edge
			}
			g->edges[e.v][e.w] = 1;		// add an edge for v-w
			g->edges[e.w][e.v] = 1;		// add and edge for w-v
		}
	}
	return;
}

int isEdge(GraphAM g, Edge e)
{
	int inGraph = 0;
	if (g == NULL){
		fprintf(stderr, "isEdge: NULL graph\n");
		exit(EXIT_FAILURE);
	}else{					// corresponding position should be 1
		if(g->edges[e.v][e.w] == 1 && g->edges[e.w][e.v] == 1){
			inGraph = 1;	// means edge in graph
		}
	}

	return inGraph;
}

void showEdge(Edge e)	// print the edge
{
	printf("%d-%d\n", e.v, e.w);
	return;
}

int validV(GraphAM graph, Vertex v)
{
	int valid = 0;
	if (graph == NULL){
		fprintf(stderr, "NULL graph\n");
		exit(0);
	}else{
		valid = v >= 0 && v < graph->numberVertex;
	}

	return valid;
}

void removeEdge(GraphAM graph, Edge e)
{
	if (graph == NULL){
		printf("NULL graph\n");
	}else{
		if (!validV(graph, e.v) || !validV(graph, e.w)){
			fprintf(stderr, "removeEdge error: invalid vertices\n");
		}else{
			if (isEdge(graph, e) == 1){		// should check if edge is in graph or not
				graph->edges[e.v][e.w] = 0;	// set to 0
				graph->edges[e.w][e.v] = 0;	// set to 0
				graph->numberEdge--;		// number of edges minus 1
			}
		}
	}

	return;
}