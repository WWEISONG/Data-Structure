#ifndef GRAPHAL_H_
#define GRAPHAL_H_

// GraphAL.h:ADT interface for undirected/unweighted graphs
typedef int Vertex;
typedef struct edge *Edge;   	       // use a struct to describe edge
typedef struct graphal *GraphAL;       // use a struct to describe grpah

GraphAL newGraph(int);		       // build a new graph
void freeGraph(GraphAL);               // free the graph mallocs
void showGraph(GraphAL);               // show the graph

Edge newEdge(Vertex, Vertex);  	       // create a new edge
void insertEdge(GraphAL, Edge);	       // insert a new edge to the graph
void removeEdge(GraphAL, Edge);        // remove an edge from the graph
void showEdge(Edge);                   // print an edge
int isEdge(GraphAL, Edge);   	       // make sure if specific edge is in graph
int validV(GraphAL, Vertex);           // make sure if vertex in graph or not
int removeV(GraphAL, Vertex, Vertex);  // remove later vertex from the former list
#endif
