#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

struct pqNode
{
	int length;         // record the length of priority queue
	int *items;  		// use an array to store data for priority queue
	int maxsize;        // record the capacity of priority queue
};

PQ createPQ(int size)
{
	PQ q;
	q = malloc(sizeof(struct pqNode));   // require memory for q;

	if (q == NULL){						 // fail to malloc memory
		fprintf(stderr, "createPQ error: no memory\n");
		exit(0);
	}else{
		q->items = malloc(sizeof(int) * size);
		if (q->items == NULL){
			fprintf(stderr, "createPQ error: no memory\n");
			exit(1);
		}
		q->length = 0;				 // initialize the length of queue
		q->maxsize = size;
		return q;
	}
}

void insertPQ(PQ q, int data)
{
	if (q == NULL){						// make sure about queue's initizlization
		fprintf(stderr, "insertPQ error: queue is not initialized\n");
		exit(1);
	}
	if (q->length == q->maxsize){
		fprintf(stderr, "insertPQ error: queue is full\n");
		exit(1);		
	}

	q->items[q->length] = data;         // store the data into the unorder array directly
	q->length++;

	return;
}

int delMaxPQ(PQ q)
{
	// the core of the priority queue:delete the max
	// time complexity is O(n)
	if (q == NULL){
		fprintf(stderr, "delMax error: queue is not initialized\n");
		exit(1);
	}	
	if (q->length == 0){				// queue is empty when delete
		fprintf(stderr, "delMax error: queue is empty\n");
		exit(1);
	}
	int *temp = q->items;              // define a new array to find the max value
	int max = 0;                        // we assump max is in 0 position initially
	for (int i = 1; i < q->length; i++)
	{
		if (temp[max] < temp[i]){		// if max < i'th position value then we assign i to max
			max = i;
		}
	}
	int retval = temp[max];
	for (int i = max; i < q->length - 1; i++)
	{								   // move all the number: no need
		q->items[i] = q->items[i+1];
	}
	q->length--;

	return retval;
}

void showPQ(PQ q)
{
	for (int i = 0; i < q->length; i++)
	{
		printf("%d ", q->items[i]);
	}

	putchar('\n');

	return;
}

int isEmpty(PQ q)
{
	int empty = 0;
	empty = q->length == 0;

	return empty;
}