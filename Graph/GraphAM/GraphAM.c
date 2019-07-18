#include <stdio.h>
#include <stdlib.h>
#include "GraphAM.h"

// how to define the vertex?
// how to define the edges?
// how to define the graph?

struct edge                       // use two vertices to define edge
{
	Vertex v;					  // vertex v
	Vertex w;					  // vertex w 
};

struct grapham
{
	int numberVertex;                 // number of vertex
	int numberEdge;                   // number of edges
	int **edges;              		  // this is the adjacent matrix     
};

// first part: implement operations of graph
GraphAM newGraph(int numVertices)
{
	GraphAM graph = NULL;
	if (numVertices < 0){
		fprintf(stderr, "newGraph error: invalid number of vertices\n");
	}else{
		graph = malloc(sizeof(struct grapham));   // malloc memory for the graph
		if (graph == NULL){						  // malloc failure
			fprintf(stderr, "newGraph error: no memory\n");
			exit(1);
		}
												 // malloc memory for edges: including several pointers(point int)
		graph->edges = malloc(sizeof(int *) * numVertices);
		if (graph->edges == NULL){
			fprintf(stderr, "newGraph error: no memory\n");
			exit(1);
		}

		for(int v = 0; v < numVertices; v++)
		{										// malloc memory for every line(every vertex)
			graph->edges[v] = malloc(sizeof(int) * numVertices);
			if (graph->edges[v] == NULL){
				fprintf(stderr, "newGraph error: no memory\n");
				exit(1);
			}
			for (int otherV = 0; otherV < numVertices; otherV++)
			{									// initialize linked state with other vertices
				graph->edges[v][otherV] = 0;
			}
		}
		graph->numberEdge = 0;
		graph->numberVertex = numVertices; 
	}

	return graph;
}

void showGraph(GraphAM graph)
{
	if (graph == NULL){
		printf("NULL graph\n");
	}else{
		printf("number Vertex: %d, number Edges: %d\n", graph->numberVertex, graph->numberEdge);
		for (int v = 0; v < graph->numberVertex; v++)						// current vertex
		{
			int nshown = 0;
			for (int otherV = 0; otherV < graph->numberVertex; otherV++)	// other vertex
			{
				if (graph->edges[v][otherV]){								// if they have edge
					printf("%d-%d ", v, otherV);
					nshown++;
				}
			}
			if (nshown > 0){												// separate by line
				putchar('\n');
			}
		}
	}
	return;
}

void freeGraph(GraphAM graph)
{
	if (graph == NULL){
		printf("NULL graph\n");
	}else{												
		for (int v = 0; v < graph->numberVertex; v++)		// free every vertex
		{
			free(graph->edges[v]);
			graph->edges[v] = NULL;
		}	
		free(graph->edges);								    // free edges
		graph->edges = NULL;
		free(graph);										// free this graph
		graph = NULL;
	}

	return;
}

// second part: implement operations of edges and vertex
Edge newEdge(Vertex v, Vertex w)
{
	Edge e = NULL;
	e = malloc(sizeof(struct edge));					// malloc memory for new edge
	if (e == NULL){				
		fprintf(stderr, "newEdge error: no memory\n");	// out of memory
		exit(1);
	}
	e->v = v;										    // assign v
	e->w = w;											// assign w

	return e;
}

void insertEdge(GraphAM graph, Edge e)
{
	if (graph == NULL){
		printf("NULL graph\n");
	}else{
		if (e == NULL){
			printf("NULL  edge\n");
		}else{
			if(!validV(graph, e->v) || !validV(graph, e->w)){
				fprintf(stderr, "insertEdge: invalid vertices\n");
			}else{
				if (isEdge(graph, e) == 0){					// if this edge is a new edge
					graph->numberEdge++;					// we increment the number of edge
				}
				graph->edges[e->v][e->w] = 1;
				graph->edges[e->w][e->v] = 1;
			}
		}
	}
	return;
}

void removeEdge(GraphAM graph, Edge e)
{
	if (graph == NULL){
		printf("NULL graph\n");
	}else{
		if (e == NULL){
			printf("NULL edge\n");
		}else{
			if (!validV(graph, e->v) || !validV(graph, e->w)){
				fprintf(stderr, "removeEdge error: invalid vertices\n");
			}else{
				if (isEdge(graph, e) == 1){					// should check if edge is in graph or not
					graph->edges[e->v][e->w] = 0;			// set to 0
					graph->edges[e->w][e->v] = 0;			// set to 0
					graph->numberEdge--;					// number of edges minus 1
				}
			}
		}
	}

	return;
}

int isEdge(GraphAM graph, Edge e)
{
	int inGraph = 0;
	if (graph == NULL){
		printf("NULL graph\n");
		exit(1);
	}else{													// corresponding position should be 1
		if(graph->edges[e->v][e->w] == 1 && graph->edges[e->w][e->v] == 1){
			inGraph = 1;									// means edge in graph
		}
	}

	return inGraph;
}

void showEdge(Edge e)			// print the edge
{
	printf("%d-%d\n", e->v, e->w);
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