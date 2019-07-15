#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *str;
	int length = 0;
	if ( argc != 2 ){
		fprintf(stdout, "Usage: ./countLength string\n");
	}else{
		str = argv[1];
		while ( *(str + length) != '\0' )
		{
			++length;
		}
		printf("The length of string you input is: %d\n", length);
	}

	return EXIT_SUCCESS;
}