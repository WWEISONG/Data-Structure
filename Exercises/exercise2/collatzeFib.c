#include <stdio.h>
#include <stdlib.h>

void partA(unsigned int n);
int partB(unsigned int num);

int main(int argc, char *argv[])
{
	for ( int i = 1; i < 5; i++ )
	{
		printf("Fib[%d] = %d: ", i, partB(i));
		partA(partB(i));
	}

	return EXIT_SUCCESS;
}

void partA(unsigned int n)
{
	while ( n != 1 )
	{
		int parity = n % 2;      // record the parity of n

		switch(parity)           // implement 2 cases
		{
			case 0: n = n / 2;
				break;
			case 1: n = 3 * n + 1;
				break;
			default: fprintf(stderr, "error of calculating\n");
		}

		printf("%d ", n);        // print n
	}

	putchar('\n');

	return;
}

int partB(unsigned int num)
{
	// calculate Fib number of no.num
	int a = 1, b = 1;
	for ( int i = 2; i < num; i++ )
	{
		int temp = b;
		b = a + b;
		a = temp;
	}

	return b;
}
















