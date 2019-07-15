#include <stdio.h>
#include <stdlib.h>
#include "heapMax.h"
#define CAPACITY 50
#define CURSOR -999

struct heap
{
	int size;                // current size of heap
	int array[CAPACITY];     // use array to store data
};

heapMax initializeHeap()
{
	heapMax H;
	H = malloc(sizeof(struct heap));

	if ( H == NULL ){
		fprintf(stderr, "initializeHeap error: no memory\n");
		exit(1);
	}else{
		H->size = 0;           // initialize size
		H->array[0] = CURSOR; // set a cursor point

		return H;
	}
}
/*
	two step:
	1 insert last position
	2 fix up: compare current child with parent, up up up

	time complexity: O(n) since we will fix up from
	bottom to the root(height of tree) one by one
*/
void insertData(int data, heapMax h)
{
	int child = 0, finish = 0, temp = 0;
	if ( h == NULL ){
		fprintf(stderr, "insertData error: heap need initialize\n");
	}else{
		h->size++;
		h->array[h->size] = data;     // insert data into last position, logically we think child
		child = h->size;
		while ( child > 1 && !finish )
		{
			if ( h->array[child] > h->array[child / 2] ){  // child > parent
				temp = h->array[child / 2];                // swap child with parent
				h->array[child / 2] = h->array[child];
				h->array[child] = temp;
			}else{
				finish = 1;                      // finish: h->array[child] < h->array[child / 2]
			}

			child /= 2;         // fix up
		}
	}

	return;
}
/*
	we delete the root, then move the last to the root
	and compare down with it's child: down down

	time complexity: O(log(n))
*/
int deleteMax(heapMax h)
{	
	int retval = 0, parent = 1, temp = 0, child = 0, finish = 0;
	if ( h == NULL ){
		fprintf(stderr, "deleteMax error: heap no initialize\n");
	}else{
		retval = h->array[1];             // take the root value to return
		h->array[1] = h->array[h->size];  // move last position value to the root as parent
		h->size--;                        // size should minus 1
		for ( parent = 1; 2*parent <= h->size && !finish; parent = child )
		{
			child = 2 * parent;          // the index of child should be 2 times of parent
			if ( child != h->size && h->array[child] < h->array[child+1] ){
				child++;
			}
			if ( h->array[parent] < h->array[child] ){    // should exchange parent and child
				temp = h->array[child];             
				h->array[child] = h->array[parent];
				h->array[parent] = temp;
			}else{
				finish = 1;                         // if no exchange, then we finish
			}
		}
	}

	return retval;
}
/*
	important to understand we directly handle a array
	this operation like go-and-back: go from start of array
	to end of array, back from current data to the root/parent

	time complexity nlog(n)
*/
int *convertToHeap(int h[], int size)
{
	int child = 0, temp = 0, i = 0;
	i = 2;                 // from bottom to root
	while ( i <= size )    // first loop: euqal to inserting from 2-n
	{
		child = i;
		while ( child > 1 && h[child] > h[child / 2] ){ // second loop: now we insert a data into the last
			temp = h[child / 2];           // swap child with parent
			h[child / 2] = h[child];
			h[child] = temp;
			child /= 2;                      // go to left child -- different from lecture
		}
		i++;
	}

	return h;
}
// help to see what happened to my heap
void showHeap(heapMax h)
{
	// origin array data distribution
	printf("original array: ");
	for ( int i = 1; i <= h->size; i++)
	{
		printf("%d ", h->array[i]);
	}
	putchar('\n');
	if ( h == NULL ){
		fprintf(stderr, "showHeap error: heap need initialize\n");
	}else{
		int par = 1;    // root node
		for ( par = 1; par <= h->size / 2; par++ )
		{
			printf("parent: %d  ", h->array[par]);         // print the parent
			if ( 2 * par + 1 <= h->size ){					// case:2 child
				printf("two child: %d  %d\n", h->array[2*par], h->array[2*par + 1]);
			}else if( 2 * par <= h->size ){					// case:1 child
				printf("one child: %d\n", h->array[2*par]);
			}
		}
	}

	return;
}