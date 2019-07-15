#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// like a ring / queue
// people are not killed should be put back of the queue
// queuing cycle

int main(int argc, char *argv[])
{
	int choose = 0;              // choose people to kill
	int number = 0;              // total number of people

	Stack S = NULL;              // create stack
	S = createStack();

 	if ( argc < 3 ){
 		fprintf(stderr, "Please input total number and choose number\n");
 	}else{
 		sscanf(argv[1], "%d", &number);       // read data from command line
 		sscanf(argv[2], "%d", &choose);
 		for ( int i = 1; i <= number; i++ )
 		{
 			qush(i, S);
 		}
 		showStack(S);

 		while ( S->top != 0 )
 		{
 			for ( int i = 0; i < choose - 1; i++ )
 			{
 				qush(pop(S), S);              // pop from the head and put on the tail
 			}
 			pop(S);
 		}

 		printf("lucky man: %d\n", pop(S));
 	}

    // becareful about array and pointer: they are different object
    // but pointer is stronger then array, it has all functions of array
    // while array is not a good choice for storing your data
    // lastly, remember add terminator for pointer and free it
/* 	printf("%p\n", S->array);
 	free(S->array);

 	printf("%p\n", S->array);
 	printf("%p\n", S);
 	free(S);
 	S = NULL;
 	printf("%p\n", S);*/

 	return EXIT_SUCCESS;
}
















