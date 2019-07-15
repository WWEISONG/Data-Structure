#include <stdio.h>
#include <stdlib.h>

// basic operation of C
#define MIN_NUM 10000
#define MAX_NUM 25000    // because mutiply 4 should not beyond 5-digits

int calExponent(int num, int expo);

int main(int argc, char *argv[])
{
	int i = 0, j = 0, temp = 0;
	int num;
	for ( i = MIN_NUM; i <= MAX_NUM; i++ )
	{
		temp = 0;            			// thinking of initialization
		num = i;
		j = 4;                           // reverse digit
		while ( num != 0 )
		{
			temp += (num % 10) * calExponent(10, j);		// calculate reverse number
			num /= 10;
			--j;
		}

		if ( temp == 4 * i ){           // confirm reverse number == original number
			printf("%d ", i);
		}
	}

	return EXIT_SUCCESS;
}

int calExponent(int num, int expo)    
{   
	// calculate a exponent of a number

	int i = 0, result = num;

	if ( expo == 0){   // for any number when exponent is 0, return 1;
		return 1;
	}

	for ( i = 1; i < expo; i++)
	{
		result = result * num;
	}

	return result;
}