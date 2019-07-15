#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *target, *start;
	int flag = 0;
	if ( argc != 2 ){
		fprintf(stderr, "Usage: ./reverseInteger integer\n");
	}else{
		target = argv[1];
		start = argv[1];
		while ( *target != '\0' )
		{
			target++;
		}
		target--;
		if ( *start == '-' ){
			printf("%c", *start);
			flag = 1;
		}
		while ( target != start )
		{
			printf("%c", *target);
			target--;
		}
		if ( !flag ){
			printf("%c\n", *target);
		}else{
			putchar('\n');
		}
	}

	return EXIT_SUCCESS;
}