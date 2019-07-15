#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *tar, temp;
	int length = 0, flag = 0, i, j;
	if ( argc != 2 ){
		fprintf(stderr, "Usage: ./sort number\n");
	}else{
		tar = argv[1];
		while ( *tar != '\0' )
		{
			length++;
			tar++;
		}
		tar = argv[1];
		for ( i = 0; i < length; i++ )
		{
			for ( j = i; j < length - 1; j++ )
			{
				if ( *(tar + j) > *(tar + j + 1) ){
					temp = *(tar + j + 1);
					*(tar + j + 1) = *(tar + j);
					*(tar + j) = temp;
					flag = 1;
				}
			}
			if ( flag ){
				flag = 0;
				for ( ; j > i; j-- )
				{
					if ( *(tar + j) < *(tar + j - 1) ){
						temp = *(tar + j - 1);
						*(tar + j - 1) = *(tar + j);
						*(tar + j) = temp;
						flag = 1;
					}
				}
			}

			if ( !flag ){
				break;
			}
		}
		printf("%s\n", tar);
	}
	return EXIT_SUCCESS;
}