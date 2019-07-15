#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *input;
	int count = 0;
	if ( argc != 2 ){
		fprintf(stderr, "Usage: ./count_0 number\n");
	}else{
		input = argv[1];
		while( *input != '\0' )
		{
			if ( *input == '0' ){
				count++;
			}
			input++;
		}
		printf("%d\n", count);
	}

	return count;
}