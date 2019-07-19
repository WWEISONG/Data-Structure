#include <stdio.h>
#include <stdlib.h>
#include "GraphAL.h"

int main(void)
{
	GraphAL g = NULL;
	g = newGraph(10);
	Edge e1 = NULL, e2 = NULL;
	e1 = newEdge(1, 2);
	e2 = newEdge(3, 4);
	insertEdge(g, e1);
	insertEdge(g, e2);
	removeEdge(g, e1);
	showGraph(g);
	freeGraph(g);
	return EXIT_SUCCESS;
}
