#include <stdio.h>
#include <stdlib.h>
#include "wGraphAM.h"
#include "wgPQ.h"

/*
	Kruskal Algorithm is used to calculate the Minimum Spanning Tree like Prim Algorithm
	But it implements in a completely different way, it directly operates edges and add 
	edges to the initial empty MST(using a graph to representation:interesting)

	detail:
	every time I choose a minimum weighted edge, I will add it to my MST graph if it does not
	build cycle, which means the endpoints of the new edge do not have an edges in MST before adding.
	When I get V - 1 edges in my MST graph, I should stop

	As Kruskal Algorithm focuses on edges, if the number of edges is very big then the efficiency of 
	Kruskal Algorithm should not good. It is better for sparse graphs.While Prim Algorithm foucuses on
	vertices, it is better for dense graphs.

	complexity:
	O(Elog(V))
*/
Graph KruskalAlgorithm(Graph g, int nV, int nE);
int isPath(Graph g, int curv, int goal, int numV, int *order, int *visited);

Graph KruskalAlgorithm(Graph g, int nV, int nE)
{
	Graph MST = newGraph(nV);	// MST contains all vertices of the original graph
	PQ p = createPQ(nE + 1);
	// initialize the PQ with all the edges
	for (Vertex v1 = 0; v1 < nV; v1++)
	{
		for (Vertex v2 = 0; v2 < nV; v2++)
		{
			Edge e = getEdge(v1, v2, g);// get edge from graph(but not real edge)
			if (isEdge(e, g)){
				insertPQ(e, p);
			}
		}
	}
	int n = 0;	// counts the number of edges
	Weight cost = 0.0;
	while (!isEmptyPQ(p) && n < nV - 1)
	{
		Edge e = delMinPQ(p);	// delete an edge, smallest first
		int *visited, order = 0;
		if (isPath(MST, e.v, e.w, nV, &order, visited) == 0){//check cycle
			insertEdge(e, MST);
			cost += e.x;	// total cost should plus the new join edge
			n++;
		}
		free(visited);
	}
	return MST;
}

/*
	this is an easy DFS to make sure if there is a path between vertex A to vertex B
	we just return the result: found or not found. I define a found variable to pass on
	from calls to calls.
*/
int isPath(Graph g, int curv, int goal, int numV, int *order, int *visited)
{
	// starting at 'curv', do a recursive DFS looking for vertex 'goal'
	// if there is no oath from curv to goal then there should be no cycle
	// else if we add new edge there will be cycle
	int found = 0;
	visited[curv] = *order;
	*order = *order + 1;
	if (curv == goal){
		found = 1;	// this means we found a path between the two endpoints
	}else{
		for (Vertex w = 0; w < numV && !found; w++)
		{			// go deep through my neighbors to find the goal vertex
			if (isEdge(newEdge(curv, w, 0.0), g) && visited[w] == UNVISITED){
				found = isPath(g, w, goal, numV, order, visited);
			}
		}
	}
	return found;
}

int main(void)
{
	Graph g = newGraph(5);
	Edge e = newEdge(0, 1, 1.1);
	insertEdge(e, g);
	e = newEdge(0, 2, 2.0);
	insertEdge(e, g);
	e = newEdge(0, 3, 1.5);
	insertEdge(e, g);
	e = newEdge(1, 3, 1.2);
	insertEdge(e, g);
	e = newEdge(2, 3, 0.8);
	insertEdge(e, g);
	KruskalAlgorithm(g, 5, 5);
}