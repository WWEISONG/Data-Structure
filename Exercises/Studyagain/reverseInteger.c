#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int minus = 0;
	char *start, *end;
	if ( argc != 2 ){
		fprintf(stderr, "Usage: ./reverseInteger number\n");		
	}else{
		start = argv[1];              // use start and end pointer to record the number
		end = argv[1];
		while ( *end != '\0' )
		{
			end++;
		}

		if ( *start == '-' ){
			printf("%c", *start);
			minus = 1;
		}
		end--;
		while ( end != start )
		{
			printf("%c", *end);
			end--;
		}

		if ( !minus ){
			printf("%c\n", *end);
		}else{
			putchar('\n');
		}

	}
}