#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if ( argc != 2 ){
		fprintf(stdout, "Usage:Please input a number ./count+ number\n");
	}else{
		int num = 0;
		if ( sscanf(argv[1], "%d", &num) ){
			for ( int i = 0; i <= num; i++ )
			{
				if ( i == num ){
					printf("%d\n", num);
				}else{
					printf("%d,", i);
				}
			}
		}else{
			fprintf(stdout, "%s is non-numeric\n", argv[1]);
		}
	}

	return EXIT_SUCCESS;
}







