// weight graph priority queue implementation
// the implementation is heapified array
#include <stdio.h>
#include <stdlib.h>
#include "wgPQ.h"
#include "wGraphAM.h"

struct pqRep {
	int numEdges;	// record the total number of edges
	int size;		// the max size of the array;
	struct edge *itemsEdges;	// use a struct array to store the edge struct
};

PQ createPQ(int size)
{
	PQ pq = NULL;
	if (size < 0){	// confirm the size if is valid or not
		fprintf(stderr, "createPQ: invalid size provided\n");
	}else{			// malloc for the pq
		pq = malloc(sizeof(struct pqRep));
		if (pq == NULL){//malloc failure
			fprintf(stderr, "createPQ: out of memory\n");
			exit(EXIT_FAILURE);
		}
		// malloc memory for the data array
		pq->itemsEdges = malloc(sizeof(struct edge) * size);
		if (pq->itemsEdges == NULL){
			fprintf(stderr, "createPQ: out of memory\n");
			exit(EXIT_FAILURE);
		}
		pq->numEdges = 0;	// initially there is no edge in the array
		pq->size = size;	// max size of the array
	}
	return pq;
}

void insertPQ(Edge e, PQ pq)
{
	if (pq == NULL){
		fprintf(stderr, "insertPQ: pq not be initialized\n");
	}else{
		// two steps
		// 1. insert into the last position
		// 2. fix up-->compare with parent and up
		pq->numEdges++;	// be careful the first position(index 0) in the array does not store data
		pq->itemsEdges[pq->numEdges] = e;// put the new data at the last position
		int child = pq->numEdges, finishUp = 0;
		while (child > 1 && !finishUp)
		{	// this step is the phase of fix up
			if (pq->itemsEdges[child].x < pq->itemsEdges[child / 2].x){
				struct edge tempEdge = pq->itemsEdges[child / 2];
				pq->itemsEdges[child / 2] = pq->itemsEdges[child];
				pq->itemsEdges[child] = tempEdge;
			}else{// at this point we finish our fix up
				finishUp = 1;
			}
		}
	}
}

Edge delMinPQ(PQ pq)
{
	// delete the top element from the min heap-->minimum edge
	if (pq == NULL){
		fprintf(stderr, "delMinPQ: pq is not initialized\n");
		exit(EXIT_FAILURE);
	}
	if (pq->numEdges == 0){
		fprintf(stderr, "delMinPQ: pq is empty\n");
		exit(EXIT_FAILURE);
	}
	Edge e = pq->itemsEdges[1];	// delete the top minimum edge of the heap
	pq->itemsEdges[1] = pq->itemsEdges[pq->numEdges];	// take last one to the top
	pq->numEdges--;	// the number of element in heap should minus 1
	int parent = 1, finishDown = 0, child = 2;	// current parent -->fix down
	for (parent = 1; 2 * parent <= pq->numEdges && !finishDown; parent = child)
	{
		child = 2 * parent;	// my left child in the heap
		if (child != pq->numEdges && 	// this means have both of children
			pq->itemsEdges[child].x > pq->itemsEdges[child+1].x){
			child++;	// we find the smaller one
		}
		if (pq->itemsEdges[parent].x > pq->itemsEdges[child].x){
			// exchange parent with this smaller child
			Edge tempEdge = pq->itemsEdges[parent];
			pq->itemsEdges[parent] = pq->itemsEdges[child];
			pq->itemsEdges[child] = tempEdge;
		}else{
			finishDown = 1;	// if no more exchange then we finish
		}
	}
	return e;
}

int isEmptyPQ(PQ pq)
{
	int empty = 0;
	empty = pq->numEdges == 0;
	return empty;
}