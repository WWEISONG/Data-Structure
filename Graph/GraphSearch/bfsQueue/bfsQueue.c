#include <stdio.h>
#include <stdlib.h>
#include "GraphAM.h"
#include "quack.h"

/*
	an typical application of BFS is to find the shortest path from start to goal
	that mean, I search from the start node one by one layer until I reach the goal
	Then this path should be the shortest path I have found, so I need to record 
	the parent nodes along the path and label the upper layer nodes visited

	The visited state should be labled when I add my neighbors onto the queue why??
	This is because when I visited my neighbor, if it has been labeled, then I go to
	the goal via it, this path must longer than it before visited path. (BFS visits
	nodes from top layer to bottom layer one by one)

	BFS used to find single path
*/

typedef int Vertex;
void bfsShortestPath(GraphAM, Vertex, Vertex, int);
void initializeVisted(int *, int);
void initializeParent(int *, int);
void printPath(int *, int, Vertex);

void bfsShortestPath(GraphAM g, Vertex start, Vertex goal, int numV)
{
	int *visited, *parent;	// visted used to label, parent use to record path
	int order = 0, found = 0;
	Quack q = createQuack();
	qush(start, q);
	visited = malloc(sizeof(int) * numV);	// malloc memory for visted
	parent = malloc(sizeof(int) * numV);	// malloc memory for parent
	if (visited == NULL || parent == NULL){	// malloc memory failure
		fprintf(stderr, "bfsShortestPath: no memory\n");
		exit(EXIT_FAILURE);
	}
	visited[start] = order++;	// be careful about order++, use order first
	while (!isEmpty(a) && !found)
	{
		Vertex v = pop(q);		// pop the head of queue
		for (Vertex w = 0; w < numV && !found; w++)
		{	// be careful about the order of traverse:from 0-numV
			if (isEdge(g, newEdge(v, w)) && visited[w] == -1){	// link with me and unvisited
				visited[w] = order++;	// label with visited
				parent[w] = v;			// record the along path
				qush(w, q);				// qush into the trail of queue
				if (w == goal){			// if w == goal, then we find the goal
					found = 1;			// found set to 1
				}
			}
		}
		if (found){						// print the path on the screen
			printf("Shortest path from %d to %d is \n", start, goal);
			printPath(parent, numV, goal);// use a recursion to print out
			puchar('\n');
		}else{							// find no path between start to goal
			printf("no path found\n");
		}
	}
	free(visited);	// free mallocs of visted
	free(parent);	// free mallocs of parent
	makeEmpty(q);	// make empty of quack
	return;
}

void initializeVisted(int *visited, int numV)
{
	for (int i = 0; i < numV; i++)
	{
		*(visited + i) = -1;
	}
	return;
}

void initializeParent(int *parent, int)
{
	for (int i = 0; i < numV; i++)
	{
		*(parent + i) = -1;
	}
	return;
}

void printPath(int *parent, int numV, Vertex v)
{
	if (parent[v] != -1){	// the limited condition
		if (0 <= v && v < numV){	// the number of vertex should in the range
			printPath(parent, numV, parent[v]);// go deep
			printf("-->");// back from the call
		}
	}
	printf("%d\n", v);	// print the vertex along the path
	return;
}