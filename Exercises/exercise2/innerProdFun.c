#include <stdio.h>
#include <stdlib.h>

float innerProduct(float a[], float b[], int n);

int main(int argc, char *argv[])
{
	float a[3]= { 2.1, 3.5, 4.6 };           // define array
	float b[3] ={ 1.1, 2.1, 3.1 };           // define array
	int n = 3;
	float result = innerProduct(a, b, n);

	printf("%.3f\n", result);

	return EXIT_SUCCESS;
}

float innerProduct(float a[], float b[], int n)
{
	float result = 0;               	// define a float as result
	for ( n = n - 1; n >= 0; n-- )      // calculate from bottom to top
	{
		result += a[n] * b[n];         
	}

	return result;
}






















