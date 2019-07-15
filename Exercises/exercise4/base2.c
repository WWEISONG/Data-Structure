#include <stdio.h>
#include <stdlib.h>
#include "quack.h"
// input a number from command line
// then convert it to binary
// the time complexity is O(log(n)), since every time we
// get the 1/2 of num.
int main(int argc, char *argv[])
{
	int num = 0;
	Quack q;                          // create a quack
	q = createQuack();                // initialize the quack
	// argc is 1 default: name of mainfile
	if ( argc != 2 || !sscanf(argv[1], "%d", &num) || num < 0 ){
		fprintf(stderr, "Usage: ./base2 number\n");
	}else{
		while ( num != 0 )
		{                            // put mod into quack
			push(num % 2, q);
			num /= 2;
		}

		while ( !isEmpty(q) )
		{                            // printf all the binary number
			printf("%d", pop(q));
		}

		putchar('\n');
	}

	return EXIT_SUCCESS;
}