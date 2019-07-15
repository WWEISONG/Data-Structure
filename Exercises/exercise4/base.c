#include <stdio.h>
#include <stdlib.h>
#include "quack.h"

int main(int argc, char *argv[])
{
	int num = 0, base = 0, digit = 0;    // conditions for correct input
	Quack q;                             // create quack and initialize
	q = createQuack();

	if ( argc != 3 || !sscanf(argv[1], "%d", &num) || !sscanf(argv[2], "%d", &base) \
		|| !(base >= 2 && base <= 16) || num < 0 ){
		fprintf(stderr, "Usage: ./base number base\n");
	}else{
		while ( num != 0 ) 				// limition is num <= 0
		{                               
			push(num % base, q);          // push mod to quack
			num /= base;
		}
		if ( isEmpty(q) ){
			// num = 0
			printf("0");     // num = 0, then quack is empty
		}

		while ( !isEmpty(q) )         // be careful about your conditions in loop or if
		{
			digit = pop(q);
			switch(digit)
			{
				case 10: printf("a"); break;
				case 11: printf("b"); break;
				case 12: printf("c"); break;
				case 13: printf("d"); break;
				case 14: printf("e"); break;
				case 15: printf("f"); break;    // put some cases together
				case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
						printf("%d", digit); break;
				default: printf("Calculate error\n");
			}
		}

		putchar('\n');
	}

	return EXIT_SUCCESS;
}