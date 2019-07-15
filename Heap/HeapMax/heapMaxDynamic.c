#include <stdio.h>
#include <stdlib.h>
#include "heapMax.h"
#define CURSOR -999

struct heap
{
	int size; // record size of heap
	int *heapData;  // pointer of real data
};

heapMax initializeHeap()
{
	heapMax h;
	h = malloc(sizeof(struct heap));
	if ( h == NULL ){
		fprintf(stderr, "initializeHeap error: no memory\n");
		exit(1);
	}else{
		h->size = 0;
		h->heapData = malloc(sizeof(int));             // data type is int
		if ( h->heapData == NULL ){	
			fprintf(stderr, "initializeHeap error: no memory\n");
			exit(1);
		}
		*(h->heapData) = CURSOR;                       // flag data

		return h;
	}
}

void insertData(int data, heapMax h)
{
	int child = 0, temp = 0;
	if ( h == NULL ){
		fprintf(stderr, "insertData error: heap no initialize\n");
	}else{
		h->size++;
		h->heapData = realloc(h->heapData, sizeof(int) * (h->size + 1));     // alloc for the new data
		*(h->heapData + h->size) = data;
		child = h->size;
		while ( child > 1 && *(h->heapData + child / 2) < *(h->heapData + child) )
		{
			temp = *(h->heapData + child);					// swap child with parent
			*(h->heapData + child) = *(h->heapData + child / 2);
			*(h->heapData + child / 2) = temp;
			child /= 2;
		}
	}

	return;	
}

int deleteMax(heapMax h)
{
	int retval = 0, parent = 1, child = 2, finish = 0, temp = 0;
	if ( h == NULL ){
		fprintf(stderr, "deleteMax error: heap no initialize\n");
	}else{
		retval = *(h->heapData + 1);            // delete the root data
		*(h->heapData + 1) = *(h->heapData + h->size); // take the last to the root(delete)
		parent = 1;
		for ( parent = 1; 2 * parent <= h->size && !finish; parent = child )
		{
			child = 2 * parent;
			if ( child != h->size && *(h->heapData + child + 1) > *(h->heapData + child)){
				child++;
			}
			if ( *(h->heapData + parent) < *(h->heapData + child) ){  // exchange data: parent with child
				temp = *(h->heapData + child);
				*(h->heapData + child) = *(h->heapData + parent);
				*(h->heapData + parent) = temp;
			}else{
				finish = 1;
			}
		}
	}

	return retval;
}

void showHeap(heapMax h)
{
	// origin array data distribution
	printf("original array: ");
	for ( int i = 0; i <= h->size; i++)
	{
		printf("%d ", *(h->heapData + i));
	}
	putchar('\n');
	if ( h == NULL ){
		fprintf(stderr, "showHeap error: heap need initialize\n");
	}else{
		int par = 1;    // root node
		printf("Cursor: %d\n", *(h->heapData));
		for ( par = 1; par <= h->size / 2; par++ )
		{
			printf("parent: %d  ", *(h->heapData + par));         // print the parent
			if ( 2 * par + 1 <= h->size ){					// case:2 child
				printf("two child: %d  %d\n", *(h->heapData + 2 * par), *(h->heapData + 2 * par + 1));
			}else if( 2 * par <= h->size ){					// case:1 child
				printf("one child: %d\n", *(h->heapData + 2 * par));
			}
		}
	}

	return;
}