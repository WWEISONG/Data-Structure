// weighted graph priority queue--> min-heapified array
#ifndef WGPQ_H_
#define WGPQ_H_
#include <stdio.h>
#include <stdlib.h>
#include "wGraphAM.h"

typedef struct pqRep *PQ;

PQ createPQ(int);	// create the priority
void insertPQ(Edge, PQ);	// an Edge is inserted, not an int
Edge delMinPQ(PQ);			// 'min' weighted edge
int isEmptyPQ(PQ);			// confirm the priority queue is empty or not
#endif