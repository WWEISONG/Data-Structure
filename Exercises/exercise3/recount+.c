#include <stdio.h>
#include <stdlib.h>

void printNumber(int num, int originNum);     // function signature

int main(int argc, char *argv[])
{
	int num = 0, i = 0;
	if ( argc != 2 || !sscanf(argv[1], "%d", &num) ){
		fprintf(stderr, "Usage: ./count+ number\n");
	}else{
		printNumber(num, num);              // take the original num for using last num
	}

	return EXIT_SUCCESS;	
}

void printNumber(int num, int originNum)
{
	if ( num == 0 ){                       // boundary condition
		printf("%d,", num);
		return;
	}else{
		// if not touch the boundary condition we recursion to next
		( num > 0 ) ? printNumber(num - 1, originNum) : printNumber(num + 1, originNum);
	}

	( num == originNum ) ? printf("%d\n", num) : printf("%d,", num);

	return;
}