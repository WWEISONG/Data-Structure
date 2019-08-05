// use to determine whether a graph is Eulerian or not
// degree all even-->Eulerian else NOT
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "GraphAM.h"
#include "quack.h"

#define MAXSIZE 100

int *getInput(int *);
int isEulerian(GraphAM, int *, int);
void findEulerCycle(GraphAM g, int numV, Vertex startV);
Vertex getAdjacent(GraphAM g, int numV, Vertex v);

int *getInput(int *index)
{
	int *allEdges, num = 0;
	allEdges = malloc(sizeof(int) * MAXSIZE);
	if (allEdges == NULL){
		fprintf(stderr, "getInput: out of memory\n");
		exit(EXIT_FAILURE);
	}
	getchar();
	while (scanf("%d", &num) == 1)
	{
		allEdges[*index] = num;
		(*index)++;
	}
	return allEdges;
}

int isEulerian(GraphAM g, int *allEdges, int numData)
{
	int numVertices = allEdges[0], isCycle = 1;
	for (int i = 1; i < numData - 1; i += 2)
	{
		Edge e = newEdge(allEdges[i], allEdges[i+1]);
		insertEdge(g, e);
	}
	for (Vertex v = 0; v < numVertices && isCycle; v++)
	{
		int degree = 0;
		for (Vertex w = 0; w < numVertices; w++)
		{
			Edge e =newEdge(v, w);
			if (isEdge(g, e)){
				degree+= 1;
			}
		}
		if (degree % 2 != 0){
			isCycle = 0;
		}
	}
	return isCycle;
}

int main(void)
{
	int *allEdges, index = 0, isCycle = 0;
	allEdges = getInput(&index);
	GraphAM g = newGraph(allEdges[0]);
	isCycle = isEulerian(g, allEdges, index);
	showGraph(g);
	if (isCycle){
		findEulerCycle(g, allEdges[0], 0);
	}else{
		printf("Not Eulerian\n");
	}
}

void findEulerCycle(GraphAM g, int numV, Vertex startV)
{
	Quack s = createQuack();
	push(startV, s);
	int alVisited = 0;
	int visited[numV];
	for (int i = 0; i < numV; i++)
	{
		visited[i] = -1;
	}

	while (!alVisited)
	{
		printf("Eulerian cycle\n");
		while (!isEmpty(s))
		{
			Vertex v = pop(s);	// pop top out and then put back
			push(v, s);	// but we have get the value of the top element
			Vertex w = getAdjacent(g, numV, v);
			if (w >= 0){// if true there is an adjacent vertex
				push(w, s);
				removeEdge(g, newEdge(v, w));
			}else{	// if I have no neighbor then there is no edge across me
				int alongV = pop(s);
				printf("%d ", alongV);
				visited[alongV] = 1;
			}
		}
		putchar('\n');
		for (int i = 0; i < numV; i++)
		{
			if (visited[i] == -1){
				alVisited = 0;	// be careful about this we just find 1 and put it into
				push(i, s);		// and stop
				break;			// just one only one
			}else{
				alVisited = 1;
			}
		}
	}
}

Vertex getAdjacent(GraphAM g, int numV, Vertex v)
{
	Vertex retV = -1;// assume no adjacent vertices
	for (Vertex w = numV - 1; w >= 0 && retV == -1; w--)
	{
		if (isEdge(g, newEdge(v, w))){
			retV = w;	// found largest adjacent vertex
		}
	}
	return retV;
}