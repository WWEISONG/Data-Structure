#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if ( argc > 1 ){
		int sum = 0, temp = 0;
		for ( int i = 1; i < argc; i++ )               // because we do not know how many number
		{											   // will be given, using for loop 
			if ( sscanf(argv[i], "%d", &temp) ){
				sum += temp;
			}else{
				fprintf(stderr, "argument %s is non-numberic\n", argv[i]);
				return EXIT_SUCCESS;
			}
		}

		fprintf(stdout, "%d\n", sum);
	}

	return EXIT_SUCCESS;
}