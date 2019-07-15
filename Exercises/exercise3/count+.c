#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int num = 0, i = 0;
	if ( argc != 2 || !sscanf(argv[1], "%d", &num) ){
		fprintf(stderr, "Usage: ./count+ number\n");
	}else{
		for ( i = 0; i <= num; i++ )
		{
			if ( i != num ){
				printf("%d,", i);
			}else{
				printf("%d\n", i);
			}
		}
	}

	return EXIT_SUCCESS;	
}