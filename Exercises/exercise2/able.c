#include <stdio.h>
#include <stdlib.h>

#define LEN 4

int main(int argc, char *argv[])
{
	char able[] = { 'a', 'b', 'l', 'e'};
	for ( int i = 0; i < LEN; i++ )
	{
		for ( int j = 0; j < LEN; j++ )
		{
			for ( int k = 0; k < LEN; k++ )
			{
				for ( int l = 0; l < LEN; l++ )
				{
					if ( i != j && i != k && i != l && j != k && j != l && k != l )
					{
						printf("%c %c %c %c\n", able[i], able[j], able[k], able[l]);
					}
				}
			}
		}
	}

	return EXIT_SUCCESS;
}