// unorder array for priority queue
#include <stdio.h>
#include <stdlib.h>

typedef struct pqNode *PQ;

PQ createPQ(int size);           // create a pq and return
void insertPQ(PQ q, int data);	 // insert an item into pq
int delMaxPQ(PQ q);				 // delete the max value and return
void showPQ(PQ q);               // show all elements in pq
int isEmpty(PQ q);               // confirm if pq is empty or not