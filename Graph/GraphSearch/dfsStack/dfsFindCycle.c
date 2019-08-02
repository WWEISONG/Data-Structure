#include <stdio.h>
#include <stdlib.h>
#include "GraphAM.h"
#include "quack.h"

/*
	this is an important part: using DFS recursion to find cycle
	the core logical is add a from vertex, which is my parent vertex
	and I as the current vertex, I will visit all my neighbors.If my
	neighbor was visited before, and it not same as my parent vertex
	this mean there is a cycle.

	Just think about, your neghbor was visited before and not is one
	of your parent nodes, then your parent nodes was visited before
	you, that means some nodes can connect with your parent, and your
	parent connect you, and you connect back to 'some nodes' mentioned
	before, so should build a cycle. You must understand this
*/ 

int dfsFindCycle(GraphAM, int, Vertex, Vertex, int *, int *);

int dfsFindCycle(GraphAM g, int numV, Vertex fromV, Vertex, int *visited, int *order)
{
	int found = 0;	// use a integer to label if we find the cycle or not
	visited[v] = *order;	// label visited order
	*order = *order + 1;	// increase the order
	for (Vertex w = 0; w < numV && !found; w++)
	{	// trverse all my neighbors
		if (isEdge(g, newEdge(v, w)) && visited[w] == -1){
			found = dfsFindCycle(g, numV, v, w, visited, order);// for w, it should from v
		}else{
			if (w != fromV){// as I mentioned before this should build cycle
				found = 1;	// now  set found to 1
			}
		}
	}
	return found;
}

/*
	expend the above question from find a cycle to find an Eulerian cycle
	first thing is: what is an Eulerian cycle graph? Generally speaking, we traverse all edges
	of the graph exactly once. second thing is: what should we do? and what can we do with DFS
	over this prolbem?

	Just think about that, every time I pop a vertex from the stack, and visit all its neighbors
	and then I remove the edge between my neighbor and I.
*/

void findEulerianCycle(GraphAM g, int numV, Vertex startV)
{
	Quack s = createQuack();
	printf("Eulerian cycle: ");

	push(startV, s);
	while (!isEmptyQuack(s))
	{	// pop and immediatly push but we can get the value
		Vertex v = pop(s);	// pop and then we find all its neighbors
		push(v, s);			// we push back to the stack
		Vertex w = getAdjacent(g, numV, v);	// get one neighbor
		if (w >= 0){	// means it still has neighbor
			push(w, s);	// push its neighbor into the stack
			removeEdge(newEdge(v, w), g);// remove edge to vertex
		}else{	// means I have no neighbor
			v = pop(s);	// I should be pop out from the stack
			printf("%d ", v);
		}
	}
	putchar('\n');
}