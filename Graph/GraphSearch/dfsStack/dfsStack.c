// dfsquack.c:traverse a graph using DFS and a stack implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GraphAM.h"
#include "quack.h"
#define WHITESPACE 100
void dfs(GraphAM g, Vertex startPonit, int numberVertex);
int readNumV(void);
int readGraph(int numV, GraphAM g);

/*
	about time complexity:
	number of pushes and pops, they should be same
	for a single node, the times it is pushed into quack is equal to it's degrees
	--> all times of push is euqal to 2 * E (for all vertices)
	--> the time complexity is O(E), linear with number of edges 
	--> E = V * (V - 1) / 2
	--> the time complexity is O(V * (V - 1)) ~ quadratic with number of vertex
*/

void dfs(GraphAM g, Vertex startPonit, int numberVertex)
{
	// first part we need to bulid an array to label if we
	// visit the vertex or not
	int *visited;
	visited = malloc(sizeof(int) * numberVertex);
	if (visited == NULL){
		fprintf(stderr, "dfs error: no memory\n");
	}else{
		for (int i = 0; i < numberVertex; i++)
		{							// initialize the visit state for every vertex
			visited[i] = -1;		// -1 indicates not visit before
		}
		// second part we implement DFS:should understand what's DFS
		// data structure is Stack:pop a vertex(unvisited) then push its all linked vertex
		Quack s = createQuack();	// bulid a stack data structure for DFS
		push(startPonit, s);		// initialization phase: push the first vertex into the stack
		int order = 0;				// just want to observe visit order of vertex practial should set 1
		while(!isEmptyQuack(s))
		{
			int curVertex = pop(s);				// pop one vertex from the stack
			if (visited[curVertex] == -1){		// say did not visit before
				visited[curVertex] = order++;	// now we label we have visited this vertex
				Vertex linkedVertex = 0;		// push all lined vertex into the stack
				Edge e;
				for(linkedVertex = 0; linkedVertex < numberVertex; linkedVertex++)
				{
					e = newEdge(curVertex, linkedVertex);
					if(isEdge(g, e) && visited[w] == -1){// and my neoghbors still not be visited
						push(linkedVertex, s);	// if edge in the graph then we consider there is connection
					}
				}
			}
		}
	}
	free(visited);
	return;
}

int main(void)
{
	return EXIT_SUCCESS;
}