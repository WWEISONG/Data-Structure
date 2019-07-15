#include <stdio.h>
#include <stdlib.h>

/*
	the time complexity is O(n) since we need 
	to handle all the input numbers one by one
	and once time.it's linear complexity.
*/
int main()
{
	int *tar, r = 0, temp = 0, length = 0, i;
	printf("Enter an integer: ");
	r = scanf("%d", &temp);					// read first number
	if ( r ){
		tar = malloc(sizeof(int));
		if ( tar == NULL ){                  // if you use malloc remember to check
			fprintf(stderr, "no memory\n");
			exit(1);
		}
	}
	*tar = temp;
	length++;
	while ( 1 )
	{
		printf("Enter an integer: ");
		r = scanf("%d", &temp);
		if ( r ){
			length++;
			tar = realloc(tar, sizeof(int) * length);
			*(tar + length - 1) = temp;
		}else{
			break;
		}
	}
	*(tar + length) = '\0';

	for ( i = 0; i < length - 1; i++ )
	{
		printf("%d->", *(tar + i));
	}
	printf("%d\n", *(tar + i));

	free(tar);                   // remember to free pointer
	tar = NULL;

	return EXIT_SUCCESS;
}