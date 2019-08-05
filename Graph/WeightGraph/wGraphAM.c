// wGraphAM.c: an adjacency matrix implementation of a weighted graph
#include <stdio.h>
#include <stdlib.h>
#include "wGraphAM.h"

struct graphRep {
	int nV;	// number of vertices
	int nE;	// number of edges
	Weight **edges;	// matrix of weights 
};

Graph newGraph(int numVertices)
{
	Graph g = NULL;	// define the graph
	if (numVertices < 0){// number of vertices is invalid
		fprintf(stderr, "newGraph: invalid number of vertices\n");
	}else{
		g = malloc(sizeof(struct graphRep));
		if (g == NULL){
			fprintf(stderr, "newGraph: out of memory\n");
			exit(EXIT_FAILURE);
		}
		g->edges = malloc(sizeof(Weight *) * numVertices);	// number of vertex
		if (g->edges == NULL){
			fprintf(stderr, "newGraph: out of memory\n");
			exit(EXIT_FAILURE);
		}
		for (int v = 0; v < numVertices; v++)
		{	// malloc memory for every vertex
			g->edges[v] = malloc(sizeof(Weight) * numVertices);
			if (g->edges[v] == NULL){
				fprintf(stderr, "newGraph: out of memory\n");
				exit(EXIT_FAILURE);
			}
			// after malloc you should initiaize the connection state
			for (int j = 0; j < numVertices; j++)
			{
				g->edges[v][j] = NOWEIGHT;
			}
		}
		g->nV = numVertices;	// initial number of vertices
		g->nE = 0;	// initial number of edges
	}
	return g;
}

void freeGraph(Graph g)
{
	if (g != NULL){
		for (int i = 0; i < g->nV; i++)
		{
			free(g->edges[i]);	// free mallocs for vertex pointers
		}
		free(g->edges);			// free mallocs for pointer itself occupy
		free(g);				// free graph
	}
	return;
}

void insertEdge(Edge e, Graph g)
{	// insert an edge into a graph: weight
	if (g == NULL){	// graph not initialised before
		fprintf(stderr, "insertEdge: graph not initialised\n");
	}else{
		if (!validV(g, e.v) || !validV(g, e.w)){// vertex should be valid
			fprintf(stderr, "insertEdge: invalid vertex\n");
		}else{
			if (!isEdge(e, g)){	// increment nE only if it is new
				g->nE++;
			}
			g->edges[e.v][e.w] = e.x;
			g->edges[e.w][e.v] = e.x;
		}
	}
	return;
}

int isEdge(Edge e, Graph g)
{
	int isInGraph = 0;
	if (g != NULL){	// graph should be not null
		if (g->edges[e.v][e.w] != NOWEIGHT){
			isInGraph = 1;	// find edge from the graph
		}
	}
	return isInGraph;
}

int validV(Graph g, Vertex v){	// checks if v is in graph
	return (v >= 0 && v <= g->nV);
}
Edge newEdge(Vertex v, Vertex w, Weight x) { // create an edge from v to w
	Edge e = {v, w, x};
	return e; 
}

Weight getWeight(Graph g, Vertex v1, Vertex v2){	// get weight: NOWEIGHT if not existing
	Edge e = {v1, v2};
	Weight retval = 0.0;	// be careful about the data type
	if (g == NULL){
		fprintf(stderr, "getWeight: graph not initialised\n");
	}else{
		retval = g->edges[e.v][e.w];
	}
	return retval;
}

Edge getEdge(Vertex v, Vertex w, Graph g)
{
	Edge e = {0, 0, 0.0};
	if (validV(g, v) && validV(g, w)){
		e.v = v;
		e.w = w;
		e.x = g->edges[v][w];
	}
	return e;
}

void showGraph(Graph g) { // print a graph
	if (g == NULL) {
		printf("NULL graph\n");
	}
	else {
		printf("V=%d, E=%d\n", g->nV, g->nE); 
		int i;
		for (i = 0; i < g->nV; i++) { 
			int nshown = 0; 
			int j;
			for (j = 0; j < g->nV; j++) { 
				if (g->edges[i][j] != NOWEIGHT) { 
					printf("%d %d:%.2f ", i, j, g->edges[i][j]);
					nshown++;
				}
			}
			if (nshown > 0) {
				printf("\n");
			}
		}
	}
	return;
}