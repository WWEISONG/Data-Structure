#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int number = 0;
	unsigned long long int a = 1, b = 1, temp = 0;
	if ( argc != 2 || !sscanf(argv[1], "%d", &number) || number <= 0){
		fprintf(stderr, "Usage: ./fib number\n");
	}else{
		if ( number <= 2){
			printf("1\n");
			return EXIT_SUCCESS;
		}

		for ( int i = 2; i < number; i++ )
		{
			temp = b;
			b = a + b;
			a = temp;
		}
		printf("%lld\n", b);
	}

	return EXIT_SUCCESS;
}