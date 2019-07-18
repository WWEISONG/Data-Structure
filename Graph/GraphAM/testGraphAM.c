#include <stdio.h>
#include <stdlib.h>
#include "GraphAM.h"

int main(void)
{
	GraphAM graph = NULL;
	graph = newGraph(10);
	Edge e1 = NULL;
	e1= newEdge(3, 5);
	Edge e2 = NULL;
	e2 = newEdge(6, 7);
	insertEdge(graph, e1);
	insertEdge(graph, e2);
	showGraph(graph);
	removeEdge(graph, e1);
	showGraph(graph);
	freeGraph(graph);

	return EXIT_SUCCESS;
}