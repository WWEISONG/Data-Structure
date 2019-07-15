#include <stdio.h>
#include <stdlib.h>
#include "heapMax.h"

int main(int argc, char *argv[])
{
	int num = 0, i = 0;
	heapMax h;
	h = initializeHeap();             // create and initialize heap

	if ( argc < 2 ){				 // if input nothing, we prompt user to input something
		fprintf(stderr, "Usage: ./a.out integers...\n");
	}else{
		for ( i = 1; i < argc; i++ ){
			if ( !sscanf(argv[i], "%d", &num) ){
				fprintf(stderr, "Usage: ./a.out integers...\n");
			}else{
				insertData(num, h);
			}
		}

		showHeap(h);
	}
}