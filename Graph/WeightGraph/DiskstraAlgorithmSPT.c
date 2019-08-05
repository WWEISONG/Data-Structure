#include <stdio.h>
#include <stdlib.h>
#include "wGraphAM.h"
#define NONE -1

/*
	Dijkstra Algorithm is used to find all the least-cost routes from source to all
	other vertex. We need to record the path from the source to destination and least
	cost for the path. The core idea of Dijkstra Algorithm is greedy, which every time
	will choose the optimal case. Generally, greedy is locally optimal, but in this 
	algorithm we make it globally..

	The finally result we can get is a SHORTEST PATH TREE from source vertex to all other
	vertices: single-source(all other)
*/
void DijkstraAlgorithm(Graph g, int nV, int nE, Vertex source);

void DijkstraAlgorithm(Graph g, int nV, int nE, Vertex source)
{
	int *visited, *parent;
	float *pathCost;
	// malloc memory for visited and initialize it
	// just for understand Algorithm we assume will get memory
	visited = malloc(sizeof(int) * nV);
	for (int i = 0; i < nV; i++)
	{
		visited[i] = 0;
	}
	parent = malloc(sizeof(int) * nV);
	for (int i = 0; i < nV; i++)
	{
		parent[i] = NONE;
	}
	pathCost = malloc(sizeof(float) * nV);
	for (int i = 0; i < nV; i++)
	{
		pathCost[i] = MAXWEIGHT;// initially the cost should be INFINITY
	}
	pathCost[source] = 0;	// for the source vertex I just initialize its pathcost to 0:not collect

	// there should be nV loops since we have nV vertex
	for (int step = 1; step <= nV; step++)
	{
		Vertex minw = NONE;
		for (Vertex w = 0; w < nV; w++){	// find minimum least cost and unvisited vertex
			if ((visited[w] == 0) && (minw == NONE || pathCost[minw] > pathCost[w])){
				minw = w;
			}
		}
		// until now, we should find the least cost and unvisited vertex
		visited[minw] = VISITED;
		// then we should check all its neighbors and update the cost if necessary
		for (Vertex w = 0; w < nV; w++)
		{
			Weight minCost = getWeight(g, minw, w);	// current vertex need to use the weight
			if (visited[w] != VISITED && 			// case when we need to update
				minCost != NOWEIGHT	&&	// this means two vertices connected
				pathCost[minw] + minCost < pathCost[w]){
				pathCost[w] = pathCost[minw] + minCost;
				parent[w] = minw;	// update the path alone the route
			}
		}
	}
	for (int i = 0; i < nV; i++)
	{
		printf("%.1f-->", pathCost[i]);
	}
	putchar('\n');
	free(visited);
	free(parent);
	free(pathCost);
}

int main(void)
{
	Graph g = newGraph(5);
	Edge e;
	e = newEdge(0, 1, 3.0);
	insertEdge(e, g);
	e = newEdge(0, 2, 4.0);
	insertEdge(e, g);
	e = newEdge(1, 3, 1.0);
	insertEdge(e, g);
	e = newEdge(1, 4, 2.0);
	insertEdge(e, g);
	DijkstraAlgorithm(g, 5, 4, 0);
}