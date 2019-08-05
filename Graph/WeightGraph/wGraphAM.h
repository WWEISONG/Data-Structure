// wGraph.h: an interface for weighted graph ADT
#ifndef WGRAPH_H_
#define WGRAPH_H_
#include <math.h>

typedef float Weight;	// define a WEIGHT
typedef int Vertex;		// define a VERTEX
#define NOWEIGHT -1.0	// NOWEIGHT means there is no edge
#define VISITED 1
#define UNVISITED -1
#define MAXWEIGHT INFINITY

typedef struct edge{
	Vertex v;		
	Vertex w;
	Weight x;	// add Weight field to the Edge struct
} Edge;

typedef struct graphRep *Graph;	// define a GRAPH

Graph newGraph(int);
void freeGraph(Graph);
void showGraph(Graph);

void insertEdge(Edge, Graph);
void removeEdge(Edge, Graph);
void showEdge(Edge);
int isEdge(Edge, Graph);
Edge newEdge(Vertex, Vertex, Weight);
Edge getEdge(Vertex, Vertex, Graph);
int cmpEdge(Edge, Edge);
int validV(Graph, Vertex);

Weight getWeight(Graph, Vertex, Vertex);
#endif