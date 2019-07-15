#include <stdio.h>
#include <stdlib.h>
#define MIN 10000
#define MAX 24999

int main()
{	
	int num = 0, mod = 0, j = 0, i = 0;
	for ( i = MIN; i <= MAX; i++ )
	{
		num = 0;
		j = i;
		while ( j != 0 )
		{
			mod = j % 10;
			num = num * 10 + mod;                    // be careful about cumulation or inductive!!!
			j /= 10;
		}
		
		( num == 4 * i ) ? printf("%d\n", i) : num;
	}

	return EXIT_SUCCESS;
}