#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "heapMax.h"

int main(int argc, char *argv[])
{
	int i = 1;
	char temp;
	heapMax h;
	h = initializeHeap();                 // remember to initialize heap
	if ( argc < 2 ){
		fprintf(stderr, "Usage: ./cHeap alphaNum alphaNum...\n");
		exit(1);
	}else{
		for ( i = 1; i < argc; i++ )
		{			
			if ( sscanf(argv[i], "%c", &temp) && isalnum(temp) \
				&& strlen(argv[i]) == 1 ){      // this is positive condition
				insertData(temp, h); 
			}
		}

		if ( !isEmpty(h) ){
			showHeap(h);
		}
	}

	return EXIT_SUCCESS;	
}