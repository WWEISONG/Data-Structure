#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int array[30], temp = 0, i = 0, flag = 0;
	scanf("%d", &temp);
	array[0] = temp;
	while ( getchar() != '\n')
	{
		scanf("%d", &temp);
		for ( i = 0; array[i] != '\0'; i++ )
		{
			if ( array[i] == temp ){
				flag = 1;
			}
		}

		if ( !flag ){
			array[i] = temp;
		}
	}

	for ( i = 0; array[i] != '\0'; i++ )
	{
		printf("%d ", array[i]);
	}
	
	putchar('\n');

	return EXIT_SUCCESS;
}