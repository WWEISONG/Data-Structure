#include <stdio.h>
#include <stdlib.h>

void partA(int n);
int partB(int num);

int main(int argc, char *argv[])
{
	int number = 0, i = 0;
	if ( argc != 2 || !sscanf(argv[1], "%d", &number)){
		fprintf(stderr, "Usage: ./collatzeFib\n");
	}else{
		partA(number);
		putchar('\n');
		for ( i = 1; i <= 4; i++ )
		{
			printf("Fib[%d] = %d: ", i, partB(i));
			partA(partB(i));
			putchar('\n');
		}
	}
}

void partA(int n)
{
	while ( n != 1 )
	{
		if ( n % 2 == 0 ){
			n /= 2;
		}else{
			n = 3 * n + 1;
		}

		printf("%d ", n);
	}

	return;
}

int partB(int num)
{
	unsigned long long int a = 1, b = 1, temp = 0;
	if ( num <= 2 ){
		return 1;
	}else{
		for ( int i = 2; i < num; i++ )
		{	
			temp = b;
			b = a + b;
			a = temp;
		}
	}

	return b;
}