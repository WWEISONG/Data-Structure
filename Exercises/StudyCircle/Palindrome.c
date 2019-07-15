#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *start, *end;
	if ( argc != 2 ){
		fprintf(stderr, "Usage: ./palindrome number\n");
	}else{
		start = argv[1];
		end = argv[1];

		while ( *end != '\0' )
		{
			end++;
		}

		end--;

		while( start <= end )           // Thanks Albeter start and endss
		{
			if ( *start != *end ){
				printf("False\n");
				return EXIT_SUCCESS;
			}

			start++;
			end--;
		}
	}

	printf("True\n");
	return EXIT_SUCCESS;
}