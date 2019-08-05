#include <stdio.h>
#include <stdlib.h>
#include "wGraphAM.h"

/*
	Minimum Spanning Tree:
	A minimun spanning tree(MST) of a weighted graph G is a spanning tree of G
	whose edges sum to minimum weight. means consists of same set of vertices as G
	and consists of a subset of edges of G
	grapg --> spanning tree --> minimum spanning tree

	Prim's formulation
	1. initially
		partition all vertices into mst and rest sets
		where mst contains some start vertex and rest contains the rest of the vertices
	2. select a minimum crossing edge
		crossing edges are edges joining vertices in the mst and rest sets
	3. move that edge and the adjacent vertex from rest to mst
	4. repeatedly select and move until the mst set contains all vertices

	And prim algorithm are almost identical to the Dijkstra Algorithm
	Complexity is O(V^2)
*/

void DijkstraPrim(Graph g, int nV, int nE, Vertex src, char alg) {


   int *visited = mallocArray(nV);   // initialised to UNVISITED
   int *parent = mallocArray(nV);    // initialised to UNVISITED
   float *pacost = mallocFArray(nV); // floats: initialised to INFINITY

   pacost[src] = 0.0;
   for (int step = 1; step <= nV; step++) {
      Vertex minw = NONE;
      for (Vertex w = 0; w < nV; w++) {        // find minimum cost vertex
         if ((visited[w] == UNVISITED) &&
             (minw == NONE || pacost[w] < pacost[minw])) {
            minw = w;
         }
      }

      visited[minw] = VISITED;

      for (Vertex w = 0; w < nV; w++) {         // 
         Weight minCost = getWeight(g, minw, w);// if minw == w, minCost = NOWEIGHT 
         // minCost is cost of the minimum crossing edge
         if (minCost != NOWEIGHT) {
/*            if (alg == 'd') {                   // if DIJKSTRA ...
               minCost = minCost + pacost[minw];// add in the path cost 
            }*/
            if ((visited[w] != VISITED) &&
                (minCost < pacost[w])) {
                   pacost[w] = minCost;
                   parent[w] = minw;
            }
         }
      }
   }
   showArray("visited", visited, nV);
   showArray("parent", parent, nV);
   showFArray("pacost", pacost, nV);
   free(visited);
   free(parent);
   free(pacost);
   return;
}