#include <stdio.h>
#include <stdlib.h>
#define LEN 4
int main()
{
	char letters[] = {'a', 'b', 'l', 'e'};  // be careful about the size of array 5
	int i, j, k, m, count = 0;
	for ( i = 0; i < LEN; i++ )
	{	
		for ( j = 0; j < LEN; j++ )
		{
			for ( k = 0; k < LEN; k++ )
			{
				for ( m = 0; m < LEN; m++ )
				{
					if ( i != j && i != k && i != m && j != k && j != m && k != m ){
						count++;
						printf("%c%c%c%c\n", letters[i],letters[j], letters[k], letters[m]);
					}
				}
			}
		}
	}
	printf("totally: %d\n", count);
	return EXIT_SUCCESS;
}